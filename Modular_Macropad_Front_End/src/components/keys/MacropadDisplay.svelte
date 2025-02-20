<!-- src/components/keys/MacropadDisplay.svelte -->
<script>
  import { createEventDispatcher } from 'svelte';
  const dispatch = createEventDispatcher();

  export let selectedKey = null;

  // Mock data - replace with store later
  const mainModule = {
    type: 'main',
    keys: [
      { id: 'k1', row: 0, col: 3 },
      { id: 'k2', row: 0, col: 4 },
      { id: 'k3', row: 1, col: 3 },
      { id: 'k4', row: 1, col: 4 },
      ...Array.from({ length: 15 }, (_, i) => ({
        id: `k${i + 5}`,
        row: Math.floor((i + 4) / 5),
        col: (i + 4) % 5,
      })),
    ],
    rotaryEncoders: [
      { id: 'r1', position: 'top' }
    ]
  };

  const connectedModules = [
    { id: 'm1', type: 'rotary', position: 'left' },
    { id: 'm2', type: 'numpad', position: 'right' }
  ];
</script>

<div class="flex justify-center items-center">
  <div class="relative w-96 h-96 bg-white rounded-lg shadow-md p-4">
    <!-- Main module label -->
    <div class="absolute -top-8 left-1/2 transform -translate-x-1/2 text-sm text-gray-600">
      Main Module
    </div>

    <!-- Key grid -->
    <div class="grid grid-cols-5 gap-2">
      {#each mainModule.keys as key}
        <button
          class="aspect-square rounded-lg border transition-all
            {selectedKey?.id === key.id 
              ? 'bg-blue-100 border-blue-500' 
              : 'bg-gray-50 border-gray-300 hover:bg-gray-100'}"
          on:click={() => selectedKey = key}
        />
      {/each}
    </div>

    <!-- Rotary encoder -->
    <div class="absolute -top-4 left-1/2 transform -translate-x-1/2">
      <button 
        class="w-8 h-8 rounded-full bg-gray-300 hover:bg-gray-400 transition-colors"
        on:click={() => selectedKey = mainModule.rotaryEncoders[0]}
      />
    </div>

    <!-- Connected modules -->
    {#each connectedModules as module}
      <div 
        class="absolute {module.position === 'left' ? '-left-20' : '-right-20'} top-1/2 transform -translate-y-1/2"
      >
        <div class="text-sm text-gray-600 mb-2">
          {module.type === 'rotary' ? 'Rotary Module' : 'Numpad Module'}
        </div>
        {#if module.type === 'rotary'}
          <button 
            class="w-8 h-8 rounded-full bg-gray-300 hover:bg-gray-400 transition-colors"
            on:click={() => selectedKey = module}
          />
        {/if}
      </div>
    {/each}
  </div>
</div>