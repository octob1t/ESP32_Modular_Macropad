<!-- src/components/settings/UpdateSettings.svelte -->
<script>
let autoUpdate = true;
let currentVersion = '1.0.0';
let updateChannel = 'stable';
let lastChecked = new Date(2024, 1, 19).toLocaleDateString();
let isCheckingForUpdates = false;

async function checkForUpdates() {
  isCheckingForUpdates = true;
  // Simulate update check
  await new Promise(resolve => setTimeout(resolve, 1500));
  isCheckingForUpdates = false;
}
</script>

<div class="space-y-6">
  <div>
    <h3 class="text-lg font-medium text-gray-900 mb-4">Software Updates</h3>

    <div class="space-y-4">
      <!-- Current Version -->
      <div class="text-sm text-gray-600">
        Current Version: {currentVersion}
      </div>

      <!-- Auto Update Toggle -->
      <div class="flex items-center justify-between">
        <span class="text-sm font-medium text-gray-700">Auto Update</span>
        <button
          class="relative inline-flex h-6 w-11 items-center rounded-full transition-colors"
          class:bg-blue-600={autoUpdate}
          class:bg-gray-200={!autoUpdate}
          on:click={() => autoUpdate = !autoUpdate}
        >
          <span
            class="inline-block h-4 w-4 rounded-full bg-white transition-transform translate-x-1"
            class:translate-x-6={autoUpdate}
          />
        </button>
      </div>

      <!-- Update Channel -->
      <div>
        <label class="block text-sm font-medium text-gray-700 mb-2">
          Update Channel
        </label>
        <select
          bind:value={updateChannel}
          class="w-full p-2 border rounded-md bg-white"
        >
          <option value="stable">Stable</option>
          <option value="beta">Beta</option>
          <option value="alpha">Alpha</option>
        </select>
      </div>

      <!-- Last Checked -->
      <div class="text-sm text-gray-600">
        Last checked: {lastChecked}
      </div>

      <!-- Check for Updates Button -->
      <button
        class="px-4 py-2 bg-blue-500 text-white rounded hover:bg-blue-600 disabled:bg-blue-300"
        on:click={checkForUpdates}
        disabled={isCheckingForUpdates}
      >
        {#if isCheckingForUpdates}
          Checking for updates...
        {:else}
          Check for Updates
        {/if}
      </button>
    </div>
  </div>
</div>