<script setup lang="ts">
import { useStreamersStore } from './stores/streamers';
import Player from './WebRTSPPlayer.vue'

const streamers = useStreamersStore()
</script>

<template>
  <Card class="card" v-for="streamer of streamers.streamers" :key="streamer.id">
    <template #header>
      <div class="card-header-container">
        <Player :uri="streamer.id"/>
      </div>
    </template>
    <template #title>
      <span
        class="title"
        :class="{ 'disabled-title': !streamer.enabled }"
        :title="streamer.sourceUrl"
      >
        {{ streamer.sourceUrl }}
      </span>
    </template>
    <template #subtitle>
      {{ streamer.description }}
    </template>
  </Card>
</template>

<style scoped>
  .card {
    width: var(--card-width);
    overflow: hidden;
  }

  .card-header-container {
    position: relative;
    background-color: var(--p-surface-300);
    height: calc(var(--card-width) / var(--preview-aspect-ratio));
  }

  .title {
    display: inline-block;
    width: 100%;
    overflow: hidden;
    text-overflow:ellipsis;
  }

  .disabled-title {
    text-decoration: line-through;
  }
</style>
