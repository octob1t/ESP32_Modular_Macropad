<!-- src/components/lighting/LightingPreset.svelte -->
<script>
export let name = '';
export let effect = '';
export let color = '#ff0000';
export let brightness = 100;
export let speed = 50;

function applyPreset() {
  // Implementation for applying the preset
  console.log('Applying preset:', { name, effect, color, brightness, speed });
}

function deletePreset() {
  // Implementation for deleting the preset
  console.log('Deleting preset:', name);
}
</script>

<div class="border rounded-lg p-4 hover:bg-gray-50">
  <div class="flex items-center justify-between mb-2">
    <h3 class="font-medium">{name}</h3>
    <div class="flex space-x-2">
      <button
        class="p-1 text-gray-600 hover:text-blue-600"
        on:click={applyPreset}
        title="Apply Preset"
      >
        <svg xmlns="http://www.w3.org/2000/svg" class="h-5 w-5" viewBox="0 0 20 20" fill="currentColor">
          <path fill-rule="evenodd" d="M16.707 5.293a1 1 0 010 1.414l-8 8a1 1 0 01-1.414 0l-4-4a1 1 0 011.414-1.414L8 12.586l7.293-7.293a1 1 0 011.414 0z" clip-rule="evenodd"/>
        </svg>
      </button>
      <button
        class="p-1 text-gray-600 hover:text-red-600"
        on:click={deletePreset}
        title="Delete Preset"
      >
        <svg xmlns="http://www.w3.org/2000/svg" class="h-5 w-5" viewBox="0 0 20 20" fill="currentColor">
          <path fill-rule="evenodd" d="M9 2a1 1 0 00-.894.553L7.382 4H4a1 1 0 000 2v10a2 2 0 002 2h8a2 2 0 002-2V6a1 1 0 100-2h-3.382l-.724-1.447A1 1 0 0011 2H9zM7 8a1 1 0 012 0v6a1 1 0 11-2 0V8zm5-1a1 1 0 00-1 1v6a1 1 0 102 0V8a1 1 0 00-1-1z" clip-rule="evenodd"/>
        </svg>
      </button>
    </div>
  </div>
  
  <div class="grid grid-cols-2 gap-2 text-sm text-gray-600">
    <div>Effect: {effect}</div>
    <div class="flex items-center">
      Color: 
      <div
        class="w-4 h-4 rounded-full ml-1"
        style="background-color: {color}"
      />
    </div>
    <div>Brightness: {brightness}%</div>
    {#if speed !== null}
      <div>Speed: {speed}%</div>
    {/if}
  </div>
</div>
