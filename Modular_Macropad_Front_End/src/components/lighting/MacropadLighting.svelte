<!-- src/components/lighting/MacropadLighting.svelte -->
<script>
  export let selectedLeds = new Set();

  // Mock data - replace with store later
  const mainModule = {
    leds: Array.from({ length: 20 }, (_, i) => ({
      id: `led${i}`,
      color: '#ff0000'
    })),
    rotaryLed: { id: 'rotaryLed', color: '#00ff00' }
  };

  function toggleLed(ledId) {
    if (selectedLeds.has(ledId)) {
      selectedLeds.delete(ledId);
    } else {
      selectedLeds.add(ledId);
    }
    selectedLeds = selectedLeds; // Trigger reactivity
  }

  function selectAll() {
    selectedLeds = new Set([
      ...mainModule.leds.map(led => led.id),
      mainModule.rotaryLed.id
    ]);
  }

  function clearSelection() {
    selectedLeds = new Set();
  }
</script>

<div class="flex flex-col items-center">
  <div class="mb-4 space-x-4">
    <button
      class="px-4 py-2 bg-blue-500 text-white rounded hover:bg-blue-600"
      on:click={selectAll}
    >
      Select All
    </button>
    <button
      class="px-4 py-2 bg-gray-500 text-white rounded hover:bg-gray-600"
      on:click={clearSelection}
    >
      Clear Selection
    </button>
  </div>

  <div class="relative w-96 h-96 bg-white rounded-lg shadow-md p-4">
    <!-- LED grid -->
    
    <div class="grid grid-cols-5 gap-2">
      {#each mainModule.leds as led}
        <button
          class="aspect-square rounded-lg border transition-all"
          style="background-color: {led.color}"
          class:selected={selectedLeds.has(led.id)}
          on:click={() => toggleLed(led.id)}
          aria-label="LED {led.id}"
        ></button>
      {/each}
    </div>  
  </div>
</div>