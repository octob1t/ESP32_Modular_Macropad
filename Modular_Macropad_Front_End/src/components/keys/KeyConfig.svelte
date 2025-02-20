<!-- src/components/keys/KeyConfig.svelte -->
<script>
  export let configTab = 'basic';
  export let selectedKey;

  const basicKeys = [
    ['Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P'],
    ['A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ';'],
    ['Z', 'X', 'C', 'V', 'B', 'N', 'M', ',', '.', '/']
  ];

  const extendedKeys = [
    'Volume Up', 'Volume Down', 'Play/Pause', 'Next', 'Previous',
    'Brightness Up', 'Brightness Down', 'Mute', 'Screenshot', 'Menu'
  ];

  let isRecording = false;
  let recordedSteps = [];
</script>

<div class="p-4">
  {#if configTab === 'basic'}
    <div class="space-y-2">
      {#each basicKeys as row}
        <div class="flex justify-center space-x-1">
          {#each row as key}
            <button 
              class="w-10 h-10 border rounded hover:bg-gray-100 flex items-center justify-center text-sm"
            >
              {key}
            </button>
          {/each}
        </div>
      {/each}
    </div>

  {:else if configTab === 'extended'}
    <div class="grid grid-cols-5 gap-2">
      {#each extendedKeys as key}
        <button 
          class="p-2 border rounded hover:bg-gray-100 text-sm text-center"
        >
          {key}
        </button>
      {/each}
    </div>

  {:else}
    <div class="space-y-4">
      <button
        class="px-4 py-2 bg-blue-500 text-white rounded hover:bg-blue-600"
        on:click={() => isRecording = !isRecording}
      >
        {isRecording ? 'Stop Recording' : 'Record Macro'}
      </button>

      {#if isRecording}
        <div class="text-sm text-gray-600">
          Recording... Press keys to record them.
        </div>
      {/if}

      <div class="border rounded p-2">
        {#if recordedSteps.length === 0}
          <div class="text-gray-500 text-sm">
            No steps recorded yet...
          </div>
        {:else}
          {#each recordedSteps as step}
            <div class="text-sm">{step}</div>
          {/each}
        {/if}
      </div>
    </div>
  {/if}
</div>