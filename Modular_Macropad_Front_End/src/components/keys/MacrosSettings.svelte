<!--  components/keys/MacrosSettings.svelte  -->

<script>
  export let selectedKey;
  export let assignMacro = {};

  let macroText = "";

  $: macroText = selectedKey ? assignMacro[selectedKey] || "" : "";

  function saveMacro() {
    if (selectedKey) {
      assignMacro[selectedKey] = macroText;
    }
  }
</script>

<div class="macros-container">
  {#if selectedKey}
    <h3>Macro for {selectedKey}</h3>
    <textarea bind:value={macroText} placeholder="Enter DuckyScript commands..." />
    <button on:click={saveMacro}>Save Macro</button>
  {:else}
    <p>Select a key to assign a macro.</p>
  {/if}
</div>

<style>
  .macros-container {
    display: flex;
    flex-direction: column;
    gap: 10px;
    padding: 16px;
    background-color: #222;
    border-radius: 8px;
    color: white;
  }

  textarea {
    width: 100%;
    height: 100px;
    padding: 10px;
    border-radius: 5px;
    border: 1px solid #444;
    background-color: #333;
    color: white;
    font-family: monospace;
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
