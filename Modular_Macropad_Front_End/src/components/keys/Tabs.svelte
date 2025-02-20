<!-- components/keys/Tabs.svelte -->
<script>
  export let activeTab; // Receive activeTab as a prop

  const tabs = ["Basic", "Extended", "Macros"];
</script>

<div class="tabs">
  {#each tabs as tab}
    <div 
      class="tab {activeTab === tab ? 'active' : ''}" 
      on:click={() => activeTab = tab}
    >
      {tab}
    </div>
  {/each}
</div>

<style>
  .tabs {
    display: flex;
    justify-content: space-around;
    padding: 16px;
    background-color: #F3F4F6;
    border-bottom: 2px solid #D1D5DB;
  }

  .tab {
    cursor: pointer;
    padding: 8px 16px;
    border-radius: 8px;
    transition: background-color 0.2s ease;
  }

  .tab:hover {
    background-color: #E5E7EB;
  }

  .tab.active {
    background-color: #4A90E2;
    color: #FFFFFF;
  }
</style>
