<!-- src/components/lighting/LightingTab.svelte -->
<script>
  import MacropadLighting from './MacropadLighting.svelte';
  import LightingControls from './LightingControls.svelte';
  
  let selectedLeds = new Set();
  let brightness = 100;
  let speed = 50;
  let selectedColor = '#ff0000';
</script>

<div class="flex flex-col h-full">
  <!-- Top Section - Macropad LED Display -->
  <div class="flex-1 p-6">
    <MacropadLighting bind:selectedLeds />
  </div>

  <!-- Bottom Section - Controls -->
  <div class="h-64 bg-white shadow-lg border-t">
    <LightingControls
      bind:selectedLeds
      bind:brightness
      bind:speed
      bind:selectedColor
    />
  </div>
</div>