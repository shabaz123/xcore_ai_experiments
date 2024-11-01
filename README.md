# xcore.ai Experiments

This repo contains a collection of material related to xcore.ai devices.

## Connecting up the [xcore.ai](https://www.xmos.com/xcore-ai) Evaluation Kit ([XK-EVK-XU316](https://www.xmos.com/xk-evk-xu316))

You'll need two USB cables; one provides the debugger connection, and the other provides 5V power, and access to the USB connection for data. A USB hub in a Y-shaped splitter cable form-factor is shown in the photo, for reducing the number of connections to the PC to a single connection if desired.

<img width="100%" align="left" src="assets\xmos-board-usb-cables-annotated.jpg">

.

## first_example
This folder contains a simple C program that pulses the LEDs on the xcore.ai evaluation board (XK-EVK-XU316) at precisely 100 kHz. It demonstrates how to use a clock to control the port counter for GPIO output.

<img width="100%" align="left" src="assets\xmos-board-oscilloscope-connections.jpg">

The README file in the project folder shows how to build and run the project. Alternatively, [use VS Code](https://www.xmos.com/documentation/XM-014363-PC/html/tools-guide/vscode-guide/index.html) to build and run the project. 

When run, you should see a precise 100 kHz output, with jitter solely dependent on the clock oscillator hardware (and PLL). For lower jitter, a better clock oscillator could be used, connected as a source for the port counter; this would require the example code to be modified.

<img width="100%" align="left" src="assets\100khz-out.png">


