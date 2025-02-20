<script>
  // Function to handle key click events
  function handleKeyClick(keyId) {
    console.log(`Key ${keyId} clicked`);
    // You can add additional functionality here, such as updating state or calling a callback
  }
</script>

<style>
  .macropad {
    display: grid;
    grid-template-columns: repeat(5, 1fr); /* 5 columns */
    grid-template-rows: repeat(5, 1fr); /* 5 rows */
    gap: 8px; /* Space between keys */
    padding: 16px; /* Padding around the grid */
    border: 2px solid #4A90E2; /* Outer border color */
    border-radius: 12px; /* Rounded corners */
    background-color: #FFFFFF; /* Background color of the macropad */
    box-shadow: 0 4px 10px rgba(0, 0, 0, 0.1); /* Subtle shadow for depth */
    width: 400px; /* Width for square shape */
    height: 400px; /* Height for square shape */
  }

  .key {
    background-color: #F3F4F6; /* Key background color */
    border: 1px solid #D1D5DB; /* Key border color */
    border-radius: 8px; /* Rounded corners for keys */
    display: flex;
    align-items: center;
    justify-content: center;
    font-size: 1.5em; /* Font size for key labels */
    transition: background-color 0.2s ease; /* Smooth background transition */
    height: 100%; /* Make keys fill the grid cell */
    width: 100%; /* Make keys fill the grid cell */
  }

  .key:hover {
    background-color: #E5E7EB; /* Darker background on hover */
  }

  .display {
    grid-column: 1 / 4; /* Span columns 1 to 3 */
    grid-row: 1 / 3; /* Span rows 1 to 2 */
    background-color: #E0E7FF; /* Display background color */
    border: 1px solid #A5B4FC; /* Display border color */
    border-radius: 8px; /* Rounded corners for display */
    display: flex;
    align-items: center;
    justify-content: center;
    font-size: 2em; /* Font size for display text */
    height: 100%; /* Make display fill the grid cell */
    width: 100%; /* Make display fill the grid cell */
  }
</style>

<div class="macropad">
  <div class="display" aria-label="Display Area">
    Display Area <!-- Replace with actual display content -->
  </div>
  
  {#each Array(19) as _, index}
    <button type="button" class="key" on:click={() => handleKeyClick(`k${index + 1}`)} aria-label={`Key ${index + 1}`}>
      {`Key ${index + 1}`} <!-- You can replace this with actual key labels -->
    </button>
  {/each}
</div>
