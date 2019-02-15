const electron = window.require('electron');
const basepath = electron.remote.app.getAppPath();
console.log(`[Starter/Common] basepath=${basepath}`);

// Load native Olive module

const module = window.require(`${basepath}/build/Release/nanovg_node_webgl.node`);

const cvs = document.getElementById("cvs");
const gl = cvs.getContext("webgl2");
module.initNanoVG(gl);