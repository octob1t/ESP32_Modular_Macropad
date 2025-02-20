<!-- src/components/keys/KeysTab.svelte -->
<script>
  import MacropadDisplay from './MacropadDisplay.svelte';
  import KeyConfig from './KeyConfig.svelte';

  let selectedKey = null;
  let configTab = 'basic';
</script>

<div class="flex flex-col h-full">
  <!-- Top Section - Macropad Display -->
  <div class="flex-1 p-6">
    <MacropadDisplay bind:selectedKey />
  </div>

  <!-- Bottom Section - Configuration -->
  {#if selectedKey}
    <div class="min-h-64 bg-white shadow-lg border-t overflow-auto">
      <!-- Configuration Tabs -->
      <div class="border-b">
        <div class="flex space-x-4 px-4">
          {#each ['basic', 'extended', 'macros'] as tab}
            <button
              class="py-2 px-4 transition-colors capitalize text-gray-600"
              class:border-b-2={configTab === tab}
              class:border-blue-500={configTab === tab}
              class:text-blue-600={configTab === tab}
              on:click={() => configTab = tab}
            >
              {tab}
            </button>
          {/each}
        </div>
      </div>

      <!-- Configuration Content -->
      <KeyConfig {configTab} {selectedKey} />
    </div>
  {/if}
</div>
