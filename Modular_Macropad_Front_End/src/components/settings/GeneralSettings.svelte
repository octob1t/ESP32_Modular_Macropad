<!-- src/components/settings/GeneralSettings.svelte -->
<script>
let usbMode = 'auto';
let autoSleep = 15;
let brightness = 100;
let hapticFeedback = true;
let soundEffects = true;
</script>

<div class="space-y-6">
  <div>
    <h3 class="text-lg font-medium text-gray-900 mb-4">General Settings</h3>
    
    <div class="space-y-4">
      <!-- USB Mode -->
      <div>
        <label class="block text-sm font-medium text-gray-700 mb-2">
          USB Mode
        </label>
        <select
          bind:value={usbMode}
          class="w-full p-2 border rounded-md bg-white"
        >
          <option value="auto">Automatic</option>
          <option value="gaming">Gaming Mode</option>
          <option value="standard">Standard Mode</option>
        </select>
      </div>

      <!-- Auto Sleep -->
      <div>
        <label class="block text-sm font-medium text-gray-700 mb-2">
          Auto Sleep (minutes)
        </label>
        <input
          type="number"
          bind:value={autoSleep}
          min="1"
          max="60"
          class="w-full p-2 border rounded-md"
        />
      </div>

      <!-- Default Brightness -->
      <div>
        <label class="block text-sm font-medium text-gray-700 mb-2">
          Default Brightness
        </label>
        <input
          type="range"
          bind:value={brightness}
          min="0"
          max="100"
          class="w-full"
        />
        <div class="text-sm text-gray-500 mt-1">{brightness}%</div>
      </div>

      <!-- Toggles -->
      <div class="space-y-3">
        <div class="flex items-center justify-between">
          <span class="text-sm font-medium text-gray-700">Haptic Feedback</span>
          <button
            class="relative inline-flex h-6 w-11 items-center rounded-full transition-colors"
            class:bg-blue-600={hapticFeedback}
            class:bg-gray-200={!hapticFeedback}
            on:click={() => hapticFeedback = !hapticFeedback}
          >
            <span
              class="inline-block h-4 w-4 rounded-full bg-white transition-transform translate-x-1"
              class:translate-x-6={hapticFeedback}
            />
          </button>
        </div>

        <div class="flex items-center justify-between">
          <span class="text-sm font-medium text-gray-700">Sound Effects</span>
          <button
            class="relative inline-flex h-6 w-11 items-center rounded-full transition-colors"
            class:bg-blue-600={soundEffects}
            class:bg-gray-200={!soundEffects}
            on:click={() => soundEffects = !soundEffects}
          >
            <span
              class="inline-block h-4 w-4 rounded-full bg-white transition-transform translate-x-1"
              class:translate-x-6={soundEffects}
            />
          </button>
        </div>
      </div>
    </div>
  </div>
</div>