# MQTT Broker using Mosquitto with C

## How to use:

### 1)Download Mosquitto on your machine
#### Debian:

    sudo apt-add-repository ppa:mosquitto-dev/mosquitto-ppa
    sudo apt-get update
#### Arch:
	sudo pacman -S mosquitto

### 2)Run Mosquitto
Open a terminal and type moquitto
![](https://i.ibb.co/7gZVrV8/Screenshot-1.png)
### 2)Compile and run the mqtt_sub.c script

    gcc -o mqtt_sub mqtt_sub.c -lmosquitto
    ./mqtt_sub
![enter image description here](https://i.ibb.co/S00C2p8/sub-run.png)

### 3)Compile and run the mqtt_pub.c script
	gcc -o mqtt_pub mqtt_pub.c -lmosquitto
    ./mqtt_pub
 ![enter image description here](https://i.ibb.co/Y3mSDwj/pub-run.png)
### The broker is working...
![enter image description here](https://i.ibb.co/JxwYH2d/result.png) 
