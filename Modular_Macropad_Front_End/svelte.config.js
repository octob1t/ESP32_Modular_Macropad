import { vitePreprocess } from '@sveltejs/vite-plugin-svelte';

export default {
  kit: {
    alias: {
      $lib: 'src/lib'
    }
  },
  preprocess: vitePreprocess(),
};
