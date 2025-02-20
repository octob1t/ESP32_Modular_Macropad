<!--  components/keys/LightingsDisplay.svelte  -->

<script>
  export let selectedLED;

  function handleLEDClick(ledId) {
    selectedLED = ledId;
  }
</script>

<div class="lightings-display-container">
  {#each Array(19) as _, index}
    <button
      type="button"
      class="led {selectedLED === `led${index + 1}` ? 'selected' : ''}"
      on:click={() => handleLEDClick(`led${index + 1}`)}
      aria-label={`LED ${index + 1}`}
    >
      {`LED ${index + 1}`}
    </button>
  {/each}
</div>

<style>
  .lightings-display-container {
    display: grid;
    grid-template-columns: repeat(5, 1fr);
    grid-template-rows: repeat(5, 1fr);
    gap: 8px;
    padding: 16px;
    border: 2px solid #4A90E2;
    border-radius: 12px;
    background-color: #FFFFFF;
    box-shadow: 0 4px 10px rgba(0, 0, 0, 0.1);
    width: 400px;
    height: 400px;
  }

  .led {
    background-color: #F3F4F6;
    border: 2px solid #D1D5DB;
    border-radius: 8px;
    display: flex;
    align-items: center;
    justify-content: center;
    font-size: 1.2em;
    height: 100%;
    width: 100%;
    cursor: pointer;
  }

  .led:hover {
    background-color: #E5E7EB;
  }

  .selected {
    border: 2px solid orange !important;
  }
</style>
