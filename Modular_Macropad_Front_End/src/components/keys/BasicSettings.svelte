<!-- components/keys/BasicSettings.svelte  -->

<script>
  export let selectedKey;
  export let assignKey;

  const keyboardLayout = [
    [
      { key: 'Esc', size: 1 }, { key: '1', size: 1 }, { key: '2', size: 1 }, { key: '3', size: 1 },
      { key: '4', size: 1 }, { key: '5', size: 1 }, { key: '6', size: 1 }, { key: '7', size: 1 },
      { key: '8', size: 1 }, { key: '9', size: 1 }, { key: '0', size: 1 }, { key: '-', size: 1 },
      { key: '=', size: 1 }, { key: 'Backspace', size: 2 }
    ],
    [
      { key: 'Tab', size: 1.5 }, { key: 'Q', size: 1 }, { key: 'W', size: 1 }, { key: 'E', size: 1 },
      { key: 'R', size: 1 }, { key: 'T', size: 1 }, { key: 'Y', size: 1 }, { key: 'U', size: 1 },
      { key: 'I', size: 1 }, { key: 'O', size: 1 }, { key: 'P', size: 1 }, { key: '[', size: 1 },
      { key: ']', size: 1 }, { key: '\\', size: 1.5 }
    ],
    [
      { key: 'Caps', size: 1.75 }, { key: 'A', size: 1 }, { key: 'S', size: 1 }, { key: 'D', size: 1 },
      { key: 'F', size: 1 }, { key: 'G', size: 1 }, { key: 'H', size: 1 }, { key: 'J', size: 1 },
      { key: 'K', size: 1 }, { key: 'L', size: 1 }, { key: ';', size: 1 }, { key: "'", size: 1 },
      { key: 'Enter', size: 2.25 }
    ],
    [
      { key: 'Shift', size: 2.25 }, { key: 'Z', size: 1 }, { key: 'X', size: 1 }, { key: 'C', size: 1 },
      { key: 'V', size: 1 }, { key: 'B', size: 1 }, { key: 'N', size: 1 }, { key: 'M', size: 1 },
      { key: ',', size: 1 }, { key: '.', size: 1 }, { key: '/', size: 1 }, { key: 'Shift', size: 2.75 }
    ],
    [
      { key: 'Ctrl', size: 1.25 }, { key: 'Alt', size: 1.25 }, { key: 'Space', size: 6.25 },
      { key: 'Alt', size: 1.25 }, { key: 'Fn', size: 1.25 }, { key: 'Ctrl', size: 1.25 }
    ]
  ];
</script>

<div class="keyboard-container">
  {#each keyboardLayout as row}
    <div class="keyboard-row">
      {#each row as keyData}
        <button 
          class="keyboard-key" 
          style="flex: {keyData.size}" 
          on:click={() => assignKey(selectedKey, keyData.key)}
        >
          {keyData.key}
        </button>
      {/each}
    </div>
  {/each}
</div>

<style>
  .keyboard-container {
    display: flex;
    flex-direction: column;
    gap: 5px;
    padding: 10px;
    background-color: #222;
    border-radius: 8px;
    width: fit-content;
  }
  
  .keyboard-row {
    display: flex;
    gap: 5px;
  }

  .keyboard-key {
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

  .keyboard-key:hover {
    background-color: #666;
  }
</style>
