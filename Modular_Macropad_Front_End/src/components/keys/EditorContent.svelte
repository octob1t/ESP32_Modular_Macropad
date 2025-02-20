<!-- components/keys/EditorContent.svelte -->
<script>
  import BasicSettings from "./BasicSettings.svelte";
  import ExtendedSettings from "./ExtendedSettings.svelte";
  import MacrosSettings from "./MacrosSettings.svelte";

  export let activeTab;
  export let selectedKey;
  export let assignKey;
  export let assignMacro;
</script>

<div class="editor-content">
  {#if activeTab === "Basic"}
    <BasicSettings {selectedKey} {assignKey} />
  {:else if activeTab === "Extended"}
    <ExtendedSettings {selectedKey} {assignKey} />
  {:else if activeTab === "Macros"}
    <MacrosSettings {selectedKey} {assignMacro} />
  {/if}
</div>

<style>
  .editor-content {
    padding: 16px;
    background-color: #FFFFFF;
  }
</style>
