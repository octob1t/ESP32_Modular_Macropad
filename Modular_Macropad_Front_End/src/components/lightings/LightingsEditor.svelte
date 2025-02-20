<!--  components/keys/LightingsEditor.svelte  -->

<script>
  export let selectedLED;
</script>

<div class="lightings-editor-container">
  {#if selectedLED}
    <h3>Lighting Settings for {selectedLED}</h3>
    <input type="color" />
    <button>Save</button>
  {:else}
    <p>Select an LED to configure lighting.</p>
  {/if}
</div>

<style>
  .lightings-editor-container {
    padding: 16px;
    background-color: #222;
    border-radius: 8px;
    color: white;
  }

  input[type="color"] {
    width: 100px;
    height: 50px;
    border: none;
    cursor: pointer;
  }

  button {
    padding: 8px 16px;
    border-radius: 5px;
    background-color: #4A90E2;
    color: white;
    border: none;
    cursor: pointer;
  }

  button:hover {
    background-color: #3B78C5;
  }
</style>