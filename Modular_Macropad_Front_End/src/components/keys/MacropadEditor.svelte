<!--  components/keys/MacropadEditor.svelte  -->

<script>
  import Tabs from "./Tabs.svelte";
  import EditorContent from "./EditorContent.svelte";

  export let selectedKey;
  let activeTab = "Basic";
</script>

<div class="editor-container">
  <Tabs bind:activeTab />
  <EditorContent {activeTab} {selectedKey} />
</div>

<style>
  .editor-container {
    display: flex;
    flex-direction: column;
    border-top: 2px solid #D1D5DB;
    padding-top: 16px;
  }
</style>

