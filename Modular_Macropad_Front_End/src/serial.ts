// serial.ts
import { writable } from 'svelte/store';

declare global {
    interface SerialPort {
        open(options: { baudRate: number }): Promise<void>;
        readable: ReadableStream;
        writable: WritableStream;
        close(): Promise<void>;
    }
    
    interface Navigator {
        serial: {
            requestPort(): Promise<SerialPort>;
        };
    }
}

export interface ModuleInfo {
    type: number;
    typeName: string;
    hasDisplay: boolean;
    numButtons: number;
    numLEDs: number;
    numRotaryEncoders: number;
    numSliders: number;
    numAS5600Encoders: number;
    moduleVersion: string;
    uniqueId: string;
}

export interface KeyConfig {
    name: string;
    color: number;
    macro: string;
}

export interface MacropadConfig {
    keys: KeyConfig[];
    encoder: {
        mode: number;
        function: string;
    };
}

interface SerialStore {
    port: SerialPort | null;
    reader: ReadableStreamDefaultReader | null;
    writer: WritableStreamDefaultWriter | null;
    connected: boolean;
    moduleInfo: ModuleInfo | null;
    config: MacropadConfig | null;
}

function createSerialStore() {
    const { subscribe, set, update } = writable<SerialStore>({
        port: null,
        reader: null,
        writer: null,
        connected: false,
        moduleInfo: null,
        config: null
    });

    let textDecoder = new TextDecoder();
    let textEncoder = new TextEncoder();

    return {
        subscribe,
        
        async connect() {
            try {
                const port = await navigator.serial.requestPort();
                await port.open({ baudRate: 115200 });
                
                const reader = port.readable.getReader();
                const writer = port.writable.getWriter();
                
                update(store => ({
                    ...store,
                    port,
                    reader,
                    writer,
                    connected: true
                }));

                // Perform handshake
                await this.handshake();
                
                // Start reading loop
                this.startReading();
                
                // Get module information
                await this.getModuleInfo();
                
                // Get initial config
                await this.getConfig();
                
            } catch (error) {
                console.error('Connection failed:', error);
                this.disconnect();
            }
        },

        async handshake() {
            update(store => {
                if (!store.writer) return store;
                
                // Send handshake query
                store.writer.write(textEncoder.encode("?\n"));
                return store;
            });

            // Wait for response in reading loop
            return new Promise((resolve) => {
                const timeout = setTimeout(() => {
                    console.error('Handshake timeout');
                    resolve(false);
                }, 1000);

                const unsubscribe = subscribe(store => {
                    if (store.connected) {
                        clearTimeout(timeout);
                        unsubscribe();
                        resolve(true);
                    }
                });
            });
        },
        
        async disconnect() {
            update(store => {
                if (store.reader) store.reader.releaseLock();
                if (store.writer) store.writer.releaseLock();
                if (store.port) store.port.close();
                return {
                    port: null,
                    reader: null,
                    writer: null,
                    connected: false,
                    moduleInfo: null,
                    config: null
                };
            });
        },
        
        async startReading() {
            update(store => {
                if (!store.reader) return store;
                
                // Read loop
                const readLoop = async () => {
                    try {
                        while (store.connected) {
                            const { value, done } = await store.reader!.read();
                            if (done) break;
                            
                            // Parse the received data
                            const data = textDecoder.decode(value);
                            const messages = data.split('\n').filter(msg => msg.trim());
                            
                            for (const msg of messages) {
                                try {
                                    const response = JSON.parse(msg);
                                    
                                    // Handle different response types
                                    if (response.event === 'keyPress') {
                                        // Handle key press event
                                    } else if (response.event === 'encoder') {
                                        // Handle encoder event
                                    } else if (response.type !== undefined) {
                                        // Module info response
                                        update(s => ({ ...s, moduleInfo: response }));
                                    }
                                } catch (e) {
                                    console.error('Failed to parse message:', msg);
                                }
                            }
                        }
                    } catch (error) {
                        console.error('Read error:', error);
                        this.disconnect();
                    }
                };
                
                readLoop();
                return store;
            });
        },
        
        async getModuleInfo() {
            update(store => {
                if (!store.writer) return store;
                
                const command = JSON.stringify({ cmd: 'getModuleInfo' }) + '\n';
                store.writer.write(textEncoder.encode(command));
                return store;
            });
        },
        
        async getConfig() {
            update(store => {
                if (!store.writer) return store;
                
                const command = JSON.stringify({ cmd: 'getConfig' }) + '\n';
                store.writer.write(textEncoder.encode(command));
                return store;
            });
        },
        
        async setConfig(config: MacropadConfig) {
            update(store => {
                if (!store.writer) return store;
                
                const command = JSON.stringify({
                    cmd: 'setConfig',
                    config
                }) + '\n';
                
                store.writer.write(textEncoder.encode(command));
                return {
                    ...store,
                    config
                };
            });
        }
    };
}

export const serialStore = createSerialStore();