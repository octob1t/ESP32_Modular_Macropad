<!-- src/components/lighting/LightingControls.svelte -->
<script>
export let selectedLeds = new Set();
export let brightness = 100;
export let speed = 50;
export let selectedColor = '#ff0000';

let selectedEffect = 'solid';
let effectOptions = [
  { id: 'solid', name: 'Solid Color' },
  { id: 'breathing', name: 'Breathing' },
  { id: 'rainbow', name: 'Rainbow Wave' },
  { id: 'reactive', name: 'Reactive' },
  { id: 'ripple', name: 'Ripple' },
  { id: 'custom', name: 'Custom Pattern' }
];

let presetColors = [
  '#ff0000', // Red
  '#00ff00', // Green
  '#0000ff', // Blue
  '#ffff00', // Yellow
  '#ff00ff', // Magenta
  '#00ffff', // Cyan
  '#ffffff', // White
  '#ff8800'  // Orange
];

function applyToSelected() {
  // Implementation for applying effects to selected LEDs
  console.log('Applying to selected:', {
    effect: selectedEffect,
    color: selectedColor,
    brightness,
    speed
  });
}

function savePreset() {
  // Implementation for saving current settings as a preset
  console.log('Saving preset');
}
</script>

<div class="p-4 space-y-6">
  <!-- Effect Selection -->
  <div>
    <label class="block text-sm font-medium text-gray-700 mb-2">
      Effect
    </label>
    <select
      bind:value={selectedEffect}
      class="w-full p-2 border rounded-md bg-white"
    >
      {#each effectOptions as option}
        <option value={option.id}>{option.name}</option>
      {/each}
    </select>
  </div>

  <!-- Color Selection -->
  <div>
    <label class="block text-sm font-medium text-gray-700 mb-2">
      Color
    </label>
    <div class="space-y-2">
      <!-- Color Input -->
      <div class="flex space-x-2">
        <input
          type="color"
          bind:value={selectedColor}
          class="w-12 h-8 rounded cursor-pointer"
        />
        <input
          type="text"
          bind:value={selectedColor}
          class="flex-1 p-1 border rounded text-sm uppercase"
        />
      </div>
      
      <!-- Preset Colors -->
      <div class="flex flex-wrap gap-2">
        {#each presetColors as color}
          <button
            class="w-8 h-8 rounded-full border-2 transition-transform hover:scale-110"
            style="background-color: {color}; border-color: {selectedColor === color ? '#4A90E2' : 'transparent'}"
            on:click={() => selectedColor = color}
          />
        {/each}
      </div>
    </div>
  </div>

  <!-- Brightness Control -->
  <div>
    <label class="block text-sm font-medium text-gray-700 mb-2">
      Brightness
    </label>
    <div class="flex items-center space-x-2">
      <input
        type="range"
        bind:value={brightness}
        min="0"
        max="100"
        class="flex-1"
      />
      <span class="text-sm text-gray-600 w-12">{brightness}%</span>
    </div>
  </div>

  <!-- Speed Control (for animated effects) -->
  {#if selectedEffect !== 'solid'}
    <div>
      <label class="block text-sm font-medium text-gray-700 mb-2">
        Speed
      </label>
      <div class="flex items-center space-x-2">
        <input
          type="range"
          bind:value={speed}
          min="0"
          max="100"
          class="flex-1"
        />
        <span class="text-sm text-gray-600 w-12">{speed}%</span>
      </div>
    </div>
  {/if}

  <!-- Action Buttons -->
  <div class="flex space-x-4 pt-2">
    <button
      class="flex-1 px-4 py-2 bg-blue-500 text-white rounded hover:bg-blue-600 disabled:bg-blue-300"
      on:click={applyToSelected}
      disabled={selectedLeds.size === 0}
    >
      Apply to Selected ({selectedLeds.size})
    </button>
    
    <button
      class="px-4 py-2 bg-gray-500 text-white rounded hover:bg-gray-600"
      on:click={savePreset}
    >
      Save Preset
    </button>
  </div>
</div>

