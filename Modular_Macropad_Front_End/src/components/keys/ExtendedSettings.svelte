<!-- components/keys/ExtendedSettings.svelte  -->

<script>
  export let selectedKey;
  export let assignKey;

  const extendedKeys = [
    ['Volume Up', 'Volume Down', 'Mute', 'Play/Pause', 'Stop'],
    ['Next Track', 'Previous Track', 'Brightness Up', 'Brightness Down'],
    ['Print Screen', 'Scroll Lock', 'Pause/Break'],
    ['Insert', 'Home', 'End', 'Page Up', 'Page Down'],
    ['Left Arrow', 'Right Arrow', 'Up Arrow', 'Down Arrow']
  ];
</script>

<div class="extended-container">
  {#each extendedKeys as row}
    <div class="extended-row">
      {#each row as key}
        <button 
          class="extended-key" 
          on:click={() => assignKey(selectedKey, key)}
        >
          {key}
        </button>
      {/each}
    </div>
  {/each}
</div>

<style>
  .extended-container {
    display: flex;
    flex-direction: column;
    gap: 5px;
    padding: 10px;
    background-color: #222;
    border-radius: 8px;
    width: fit-content;
  }
  
  .extended-row {
    display: flex;
    gap: 5px;
  }

  .extended-key {
    background-color: #444;
    color: white;
    padding: 10px 15px;
    border: none;
    border-radius: 5px;
    cursor: pointer;
    font-size: 1em;
    text-align: center;
    display: flex;
    justify-content: center;
    align-items: center;
  }

  .extended-key:hover {
    background-color: #666;
  }
</style>
