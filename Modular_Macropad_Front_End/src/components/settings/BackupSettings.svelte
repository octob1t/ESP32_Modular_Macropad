<!-- src/components/settings/BackupSettings.svelte -->
<script>
let autoBackup = true;
let backupInterval = 'weekly';
let lastBackup = new Date(2024, 1, 15).toLocaleDateString();

function exportSettings() {
  // Implementation for exporting settings
  console.log('Exporting settings...');
}

function importSettings() {
  // Implementation for importing settings
  console.log('Importing settings...');
}
</script>

<div class="space-y-6">
  <div>
    <h3 class="text-lg font-medium text-gray-900 mb-4">Backup & Restore</h3>

    <div class="space-y-4">
      <!-- Auto Backup Toggle -->
      <div class="flex items-center justify-between">
        <span class="text-sm font-medium text-gray-700">Auto Backup</span>
        <button
          class="relative inline-flex h-6 w-11 items-center rounded-full transition-colors"
          class:bg-blue-600={autoBackup}
          class:bg-gray-200={!autoBackup}
          on:click={() => autoBackup = !autoBackup}
        >
          <span
            class="inline-block h-4 w-4 rounded-full bg-white transition-transform translate-x-1"
            class:translate-x-6={autoBackup}
          />
        </button>
      </div>

      <!-- Backup Interval -->
      {#if autoBackup}
        <div>
          <label class="block text-sm font-medium text-gray-700 mb-2">
            Backup Interval
          </label>
          <select
            bind:value={backupInterval}
            class="w-full p-2 border rounded-md bg-white"
          >
            <option value="daily">Daily</option>
            <option value="weekly">Weekly</option>
            <option value="monthly">Monthly</option>
          </select>
        </div>
      {/if}

      <!-- Last Backup Info -->
      <div class="text-sm text-gray-600">
        Last backup: {lastBackup}
      </div>

      <!-- Manual Backup/Restore Buttons -->
      <div class="flex space-x-4 pt-4">
        <button
          class="px-4 py-2 bg-blue-500 text-white rounded hover:bg-blue-600"
          on:click={exportSettings}
        >
          Export Settings
        </button>
        <button
          class="px-4 py-2 bg-gray-500 text-white rounded hover:bg-gray-600"
          on:click={importSettings}
        >
          Import Settings
        </button>
      </div>
    </div>
  </div>
</div>