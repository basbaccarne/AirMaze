# AirMaze
This ball game is a puzzle game made out of tubes, fans, small balls and distance sensors. You need to get the ball through the maze by walking around the structure.   

![idea](/img/idea.jpg)


## Description
- Barrier posts are set-up in a circular patterns of about 1m diameter
- Each barrier post is equiped with distance sensor, oriented outward
- In the middle of the circle, a patterns of tubes is installed
- These tubes are filles with small styrofoam balls in different colors
- Underneath built-in at difference places in the tubes, air vents are installed that trigger when people come close to the distance sensors
- This creates a mesmerizing puzzle

## Materials
- Tubes, 3 meters / 40 mm outer diameter, 2mm thickness, transparent acryl ([€10/m](https://www.kunststofforte.nl/product/transparante-acrylaat-buizen-xt/)) > €30 (*ordered*)
- 6 x Arduino Unos ([6 x €25](https://www.kiwi-electronics.com/nl/arduino-uno-rev3-atmega328-729?search=arduino))
- 6 x small fans (brushless DC, 5V, 0.5A) ([6 x €10](https://www.mouser.be/ProductDetail/Delta-Electronics/EFB0405VHD-F00?qs=%2FW4LtXOBxKsYebwOUVkrBw%3D%3D)) > €60 (*ordered*)
- 6 x HC-SR04 Ultrasonic distance sensor ([6 x €5,5](https://www.kiwi-electronics.com/nl/ultrasoon-sensor-hc-sr04-2592?search=HC-SR04%20Ultrasonic%20distance%20sensor))
- Duct tape (*bring it*)
- 6 x neopixel strip ([6 x €7](https://www.kiwi-electronics.com/nl/neopixel-stick-8x-5050-rgb-led-met-geintegreerde-drivers-7316))
- 6 x LN298N motor driver ([6 x €4](https://www.kiwi-electronics.com/nl/dual-h-bridge-dc-stepper-motor-driver-l298n-4117?search=LN298N))
- 6 x DC to Terminal connector ([6 x €2](https://www.kiwi-electronics.com/nl/terminal-block-naar-2-1mm-dc-barrel-jack-female-747?search=Terminal%20connector))
- 6 x 5V adapter ([6 x €10](https://www.kiwi-electronics.com/nl/voedingsadapter-5v-2-4a-12w-5-5x2-1mm-dc-plug-3595?search=5v%20adapter))
  - **Issue: the LN298N has a voltage drop of about 1.5-2V > these adapters are not strong enough**
  - Needed to buy an [alternative variable DC adapter 3 - 12V](https://www.allekabels.nl/ac-dc-adapter/7207/4332190/universele-acdc-adapter.html)
- Paint (*bring it*)
- Base plate (*to do*)
- Fine saw (*bring it*)

## Sensor set-up  
#### Components of a single 'measure & blow' unit:
- Arduino Uno
- 7V power source
- Strong PC fan 5V
- HC-SR04 Ultrasonic distance sensor
- LN298N motor driver
- Neopixel Stick
- Case

The Arduino detects the distance and maps this to a PWM signal that drives the motor and a pulsating LED strip.  The closer something is, the harder the fan blows and the faster the led moves.    
#### Connections
- Connect the **power**
  - 7V Vcc (Terminal connector) to Vin (Arduino) & 12V in (LN298N)
  - GND (Terminal connector) to GND (Arduino) & GND (LN298N)
- Connect the **fan**
  - Vcc (fan) to Out1 (LN298N)
  - GND (fan) to Out2 (LN298N)
- Connect the **distance sensor** to the Arduino
  - Vcc (sensor) to 5V (Arduino)
  - Gnd (sensor)  to GND (Arduino)
  - Trigg (sensor) to digital 2 (Arduino)
  - Echo (sensor) to digital 3 (Arduino)
- Connect the **motor driver** to the Arduino
  - Remove the ENa Jumper 
  - digital 9 (Arduino) to ENa
  - digital 8 (Arduino) to IN1
- Connect the **led strip** to the Arduino
  - Connect Connect Din (Neopixel) to Digital 6 (Arduino)
  - Connect 5VDC (Neopixel) to 5V (Arduino)
  - Connect GND (Neopixel) to GND (Arduino)   
#### Code
- Upload [this script](distance_mapping.ino) to the Arduino
#### Case
- The base component are mounted on a [laser cutted base](https://www.instructables.com/5-Design-of-Laser-Cut-Cases-for-5-Popular-Platform/)

## Air flow set-up
Components
- 'measure & blow' units
- Tubes
- [Fan connections](https://a360.co/3UqDi5y)
  - Fan connections are inserted on the inside of the tubes to be able to acces the mounting holes
- Tube connection pieces
- Ground plate
- Paint
- Styrofoam Balls

## Final installation
- Central piece on a pedestal
- Mount fans & LED strips
- Mount motion sensors
- Connect components and power (single switch power distribution plug)
- Test and adjust sensitivity

## Initial idea   
An immersive circular installation where lightweight fabric panels sway and dance in response to visitors’ movements, creating a mesmerizing play of colors and gentle breezes
Inspired by
- [Morning Mist](https://www.designlabexperience.com/projects/morning-mist-fans-installation)
- [Daniel Wurtzel's Air Series](https://www.danielwurtzel.com/)
- [Hans Haakcke's Blue Sail](https://arth207-spring.tumblr.com/post/50658432895)
