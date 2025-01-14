<script setup lang="ts">
import { WebRTSP } from 'webrtsp/WebRTSP.mjs'
import { useTemplateRef, onMounted } from 'vue'

const { uri } = defineProps<{ uri: string }>()

declare const WebRTSPPort: number

const protocol = window.location.protocol === 'http:' ? "ws:" : "wss:"
const url = `${protocol}//${window.location.hostname}:${WebRTSPPort}/`

const videoElement = useTemplateRef('video')
let webrtsp = null

onMounted(() => {
  webrtsp = new WebRTSP(
    videoElement.value,
    [{
      urls: ["stun:stun.l.google.com:19302"]
    }],
    { debug: true })
  webrtsp.connect(url, uri)
})
</script>

<template>
  <video ref="video" autoplay="true" muted="true"> </video>
</template>

<style scoped>
  video {
    position: absolute;

    max-width: 100%;
    max-height: 100%;
    width: 100%;
    height: 100%;

    top: 0px;
    bottom: 0px;
    left: 0px;
    right: 0px;

    margin: auto;
  }
</style>
