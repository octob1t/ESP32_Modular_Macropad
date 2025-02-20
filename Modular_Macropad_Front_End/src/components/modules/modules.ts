// src/modules.ts

export const modules = [
  {
    name: 'Main Module',
    type: 'keys',
    buttons: [
      { id: 'Display', type: 'button', leds: [] },
      { id: 'K1', type: 'button', leds: ['LED1'] },
      { id: 'K2', type: 'dial', leds: ['LED2'] }, // Rotary encoder (dial)
      { id: 'K3', type: 'button', leds: ['LED3'] },
      { id: 'K4', type: 'button', leds: ['LED4'] },
      { id: 'K5', type: 'button', leds: ['LED5'] },
      { id: 'K6', type: 'button', leds: ['LED6'] },
    ]
  },
  {
    name: 'Dial Module',
    type: 'keys',
    buttons: [
      { id: 'Dial1', type: 'largeDial', leds: ['LED7', 'LED8', 'LED9', 'LED10', 'LED11', 'LED12', 'LED13', 'LED14'] },
      { id: 'Dial2', type: 'dial', leds: [] },
      { id: 'Dial3', type: 'dial', leds: [] },
    ]
  },
  {
    name: 'Slider Module',
    type: 'keys',
    buttons: [
      { id: 'Slider1', type: 'slider', leds: ['LED15'] },
      { id: 'Slider2', type: 'slider', leds: [] },
      { id: 'Slider3', type: 'slider', leds: [] },
      { id: 'Slider4', type: 'slider', leds: [] },
      { id: 'Slider5', type: 'slider', leds: [] },
    ]
  },
  {
    name: 'Mini Main Module',
    type: 'keys',
    buttons: [
      { id: 'K1', type: 'button', leds: [] },
      { id: 'K2', type: 'button', leds: [] },
      { id: 'K3', type: 'button', leds: [] },
      { id: 'K4', type: 'button', leds: [] },
      { id: 'K5', type: 'button', leds: [] },
      { id: 'K6', type: 'button', leds: [] },
    ]
  },
  {
    name: 'Mini Dial Module',
    type: 'keys',
    buttons: [
      { id: 'Dial1', type: 'dial', leds: [] },
      { id: 'Dial2', type: 'dial', leds: [] },
      { id: 'Dial3', type: 'dial', leds: [] },
      { id: 'Dial4', type: 'dial', leds: [] },
      { id: 'Dial5', type: 'dial', leds: [] },
      { id: 'Dial6', type: 'dial', leds: [] },
    ]
  },
  {
    name: 'Mini Slider Module',
    type: 'keys',
    buttons: [
      { id: 'Slider1', type: 'slider', leds: [] },
      { id: 'Slider2', type: 'slider', leds: [] },
    ]
  },
];
