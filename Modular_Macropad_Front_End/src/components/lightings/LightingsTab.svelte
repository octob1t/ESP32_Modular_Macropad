<!--  components/keys/LightingsTab.svelte  -->

<script>
  import LightingsDisplay from "./LightingsDisplay.svelte";
  import LightingsEditor from "./LightingsEditor.svelte";

  let selectedLED = null;
</script>

<div class="lightings-tab-container">
  <LightingsDisplay bind:selectedLED />
  <LightingsEditor {selectedLED} />
</div>

<style>
  .lightings-tab-container {
    display: flex;
    flex-direction: column;
    height: 100vh;
  }
</style>