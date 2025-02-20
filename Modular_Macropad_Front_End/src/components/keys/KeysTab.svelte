<!--  components/keys/KeysTab.svelte  -->

<script>
  import MacropadDisplay from "./MacropadDisplay.svelte";
  import MacropadEditor from "./MacropadEditor.svelte";

  let selectedKey = null; // Manage selected key here
</script>

<div class="container">
  <MacropadDisplay bind:selectedKey />
  <MacropadEditor {selectedKey} />
</div>

<style>
  .container {
    display: flex;
    flex-direction: column;
    height: 100vh;
  }
</style>
