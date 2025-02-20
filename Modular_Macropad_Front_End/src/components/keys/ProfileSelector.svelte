<!-- components/keys/ProfileSelector.svelte -->
<script>
  let profiles = ["P1", "P2", "P3"];
  let selectedProfile = "P1";

  function addProfile() {
    if (profiles.length < 24) {
      profiles = [...profiles, `P${profiles.length + 1}`];
    }
  }

  function removeProfile(index) {
    profiles = profiles.filter((_, i) => i !== index);
  }

  function renameProfile(index) {
    const newName = prompt("Enter new profile name:", profiles[index]);
    if (newName) {
      profiles[index] = newName;
    }
  }

  function selectProfile(profile) {
    selectedProfile = profile;
  }
</script>

<div class="profile-selector">
  {#each profiles as profile, index}
    <div class="profile {selectedProfile === profile ? 'active' : ''}" on:click={() => selectProfile(profile)}>
      {profile}
      <span class="edit" on:click={(e) => { e.stopPropagation(); renameProfile(index); }}>✎</span>
      <span class="delete" on:click={(e) => { e.stopPropagation(); removeProfile(index); }}>✖</span>
    </div>
  {/each}
  {#if profiles.length < 24}
    <button class="add-profile" on:click={addProfile}>+</button>
  {/if}
</div>

<style>
  .profile-selector {
    display: flex;
    gap: 8px;
    align-items: center;
    padding: 16px;
  }

  .profile {
    padding: 8px;
    border: 1px solid #D1D5DB;
    border-radius: 4px;
    cursor: pointer;
    display: flex;
    align-items: center;
  }

  .profile.active {
    background-color: #4A90E2;
    color: white;
  }

  .edit, .delete {
    margin-left: 8px;
    cursor: pointer;
  }

  .add-profile {
    border: none;
    background-color: #4A90E2;
    color: white;
    border-radius: 4px;
    cursor: pointer;
  }
</style>
