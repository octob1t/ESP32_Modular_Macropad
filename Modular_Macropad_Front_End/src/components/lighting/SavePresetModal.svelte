
<!-- src/components/lighting/SavePresetModal.svelte -->
<script>
export let show = false;
export let onSave = () => {};
export let onClose = () => {};

let presetName = '';
let includeSelection = true;

function handleSubmit() {
  onSave({
    name: presetName,
    includeSelection
  });
  presetName = '';
  show = false;
}
</script>

{#if show}
  <div class="fixed inset-0 bg-black bg-opacity-50 flex items-center justify-center">
    <div class="bg-white rounded-lg p-6 w-full max-w-md">
      <h2 class="text-xl font-semibold mb-4">Save Preset</h2>
      
      <form on:submit|preventDefault={handleSubmit} class="space-y-4">
        <div>
          <label class="block text-sm font-medium text-gray-700 mb-2">
            Preset Name
          </label>
          <input
            type="text"
            bind:value={presetName}
            placeholder="Enter preset name"
            class="w-full p-2 border rounded-md"
            required
          />
        </div>

        <div class="flex items-center">
          <input
            type="checkbox"
            id="includeSelection"
            bind:checked={includeSelection}
            class="mr-2"
          />
          <label for="includeSelection" class="text-sm text-gray-700">
            Include selected LEDs
          </label>
        </div>

        <div class="flex justify-end space-x-4 pt-4">
          <button
            type="button"
            class="px-4 py-2 text-gray-600 hover:text-gray-800"
            on:click={onClose}
          >
            Cancel
          </button>
          <button
            type="submit"
            class="px-4 py-2 bg-blue-500 text-white rounded hover:bg-blue-600"
            disabled={!presetName}
          >
            Save Preset
          </button>
        </div>
      </form>
    </div>
  </div>
{/if}