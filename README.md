# Zephyr-Whispers, the ball game
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
- 6 x Arduino Unos ([6 x €25](https://www.kiwi-electronics.com/nl/arduino-uno-rev3-atmega328-729?search=arduino)) > €150 (*ordered*)
- 6 x small fans (brushless DC, 5V, 0.5A) ([6 x €10](https://www.mouser.be/ProductDetail/Delta-Electronics/EFB0405VHD-F00?qs=%2FW4LtXOBxKsYebwOUVkrBw%3D%3D)) > €60 (*ordered*)
- 6 x HC-SR04 Ultrasonic distance sensor ([6 x €5,5](https://www.kiwi-electronics.com/nl/ultrasoon-sensor-hc-sr04-2592?search=HC-SR04%20Ultrasonic%20distance%20sensor)) > €33 (*ordered*)
- Duct tape (*bring it*)
- 6 x neopixel strip ([6 x €7](https://www.kiwi-electronics.com/nl/neopixel-stick-8x-5050-rgb-led-met-geintegreerde-drivers-7316)) > €42 (*ordered*)
- 6 x LN298N motor driver ([6 x €4](https://www.kiwi-electronics.com/nl/dual-h-bridge-dc-stepper-motor-driver-l298n-4117?search=LN298N)) > €24 (*ordered*)
- 6 x DC to Terminal connector ([6 x €2](https://www.kiwi-electronics.com/nl/terminal-block-naar-2-1mm-dc-barrel-jack-female-747?search=Terminal%20connector)) > €12 (*ordered*)
- 6 x 5V adapter ([6 x €10](https://www.kiwi-electronics.com/nl/voedingsadapter-5v-2-4a-12w-5-5x2-1mm-dc-plug-3595?search=5v%20adapter)) > €60 (*ordered*)
- Paint (*bring it*)
- Base plate (*to do*)
- Saw (*bring it*)

## Sensor set-up  
Components of a signle unit:
- HC-SR04 Ultrasonic distance sensor
- Arduino Uno & wires
- LN298N motor driver
- Fan
- Power supply
- Casing

The Arduino detects the distance and maps this to a PWM signal that drives the motor.  The closer something is, the harder the fan blows
- Connect the distance sensor to the Arduino (Vcc > 5V, Gnd > GND, Trigg > digital 2, Echo > digital 3)
- Optional: connect the led strip to the Arduino
- Connect the motor driver to the Arduino (digital 9)
- Connect the fan to the motor driver
- Upload [this script](distance_mapping.ino) to the Arduino
- Print the case
- Mount the Arduino in the case
- Connect the power to the motor driver
- Test if the sensitivity is right
  
## Air flow set-up
Components
- Sensor boxes
- Tubes
- Fan connections
- Tube connection pieces
- Ground plate
- Paint
- Styrofoam Balls

## Initial idea   
An immersive circular installation where lightweight fabric panels sway and dance in response to visitors’ movements, creating a mesmerizing play of colors and gentle breezes
Inspired by
- [Morning Mist](https://www.designlabexperience.com/projects/morning-mist-fans-installation)
- [Daniel Wurtzel's Air Series](https://www.danielwurtzel.com/)
- [Hans Haakcke's Blue Sail](https://arth207-spring.tumblr.com/post/50658432895)
