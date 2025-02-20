<!-- src/components/settings/SettingsTab.svelte -->
<script>
import GeneralSettings from './GeneralSettings.svelte';
import BackupSettings from './BackupSettings.svelte';
import UpdateSettings from './UpdateSettings.svelte';

let activeTab = 'general';
</script>

<div class="flex flex-col h-full">
  <div class="border-b">
    <div class="flex space-x-4 px-4">
      {#each ['general', 'backup', 'updates'] as tab}
        <button
          class="py-2 px-4 transition-colors capitalize text-gray-600"
          class:border-b-2={activeTab === tab}
          class:border-blue-500={activeTab === tab}
          class:text-blue-600={activeTab === tab}
          on:click={() => activeTab = tab}
        >
          {tab}
        </button>
      {/each}
    </div>
  </div>

  <div class="p-6 overflow-auto">
    {#if activeTab === 'general'}
      <GeneralSettings />
    {:else if activeTab === 'backup'}
      <BackupSettings />
    {:else if activeTab === 'updates'}
      <UpdateSettings />
    {/if}
  </div>
</div>