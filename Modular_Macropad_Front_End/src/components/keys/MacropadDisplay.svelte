<!--  components/keys/MacropadDisplay.svelte  -->

<script>
  export let selectedKey; // Receive selectedKey as a prop

  function handleKeyClick(keyId) {
    selectedKey = keyId; // Update the selected key
  }
</script>

<div class="container">
  <div class="macropad-container">
    <button
      type="button"
      class="display {selectedKey === 'display' ? 'selected' : ''}"
      on:click={() => handleKeyClick('display')}
      aria-label="Display"
    >
      Display
    </button>
    
    {#each Array(19) as _, index}
      <button
        type="button"
        class="key {selectedKey === `k${index + 1}` ? 'selected' : ''}"
        on:click={() => handleKeyClick(`k${index + 1}`)}
        aria-label={`Key ${index + 1}`}
      >
        {`Key ${index + 1}`}
      </button>
    {/each}
  </div>
</div>

<style>
  .container {
    display: flex;
    flex-direction: column;
    align-items: center;
    padding: 16px;
  }

  .macropad-container {
    display: grid;
    grid-template-columns: repeat(5, 1fr);
    grid-template-rows: repeat(5, 1fr);
    gap: 8px;
    padding: 16px;
    border: 2px solid #4A90E2;
    border-radius: 12px;
    background-color: #FFFFFF;
    box-shadow: 0 4px 10px rgba(0, 0, 0, 0.1);
    width: 200px;
    height: 200px;
  }

  .key, .display {
    background-color: #F3F4F6;
    border: 2px solid #D1D5DB;
    border-radius: 8px;
    display: flex;
    align-items: center;
    justify-content: center;
    font-size: .65em;
    height: 100%;
    width: 100%;
    cursor: pointer;
  }

  .key:hover, .display:hover {
    background-color: #E5E7EB;
  }

  .selected {
    border: 2px solid orange !important;
  }

  .display {
    grid-column: 1 / 4;
    grid-row: 1 / 3;
    background-color: #E0E7FF;
  }
</style>