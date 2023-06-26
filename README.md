# AdafruitOLED
How to connect (and program) an Adafruit OLED 128x64 display to the Playground Express board

## Connecting

Using the STEMMA QT connector (the small one, on the back side of the display),you need to connect only 4 cables to the board using coco clips or soldering its, as in the following images.

**Be sure to put the wire colors in the same order!!**

![](/images/938-08.jpg)

![](/images/2023-06-25%20at%2022.49.44.jpeg)

## Programming 

### Setup Arduino IDE to use Adafruit boards

See detailed instructions at this page:
https://learn.adafruit.com/adafruit-circuit-playground-express/set-up-arduino-ide

If you have any problem with the procedure, you can try using the old fashioned procedure: https://learn.adafruit.com/adafruit-arduino-ide-setup/arduino-1-dot-6-x-ide 
It looks a little obsolete, but works OK with new Arduino versions too. 


### Install Arduino Libraries
Using these OLEDs with Arduino sketches requires that two libraries be installed: Adafruit_SSD1306, which handles the low-level communication with the hardware, and Adafruit_GFX, which builds atop this to add graphics and high level text functions.

1. Open up the Arduino library manager:
![](/images/adafruit_products_library_manager_menu.png)

2. Search for the Adafruit SSD1306 library and install it:
![](/images/adafruit_products_ssd1306.png)

3. Search for the Adafruit GFX library and install it
![](/images/adafruit_products_gfx.png)

4. After installing the Adafruit_SSD1306 and Adafruit_GFX libraries, close and restart the Arduino IDE.

### Download the code
Download [the code](/code/PlayGroundOLEDText.ino) in a folder **with the same name that the file** (PlayGroundOLEDText) in your Arduino programs folder or just copy & paste it to your own new Arduino sketch and save it.

### Using the code

This code was made to display text on a small OLED screen. It can be set as static, scrolling to the left or scrolling up.

You can set the following program parameters in the USER SETTING AREA of the program, without need of modify the main code area:

 - The text to show in the screen
 - The font size to use 
 - The space between lines
 - The default scroll mode
 - The speed of vertical and horizontal scrolling

Also, you can use the slide switch en the board to choose between two modes:

  - Moving it to the left, turns the red LED on and set the scroll mode to "multiple", meaning that you can alternate scroll modes by pressing the left button on the board 
- Moving it to the right, turns the red LED off and fix the last scroll mode selected.
Be aware that booting the board the scroll mode will be returned to the default mode, as it has been establishedd in the USER SETTING AREA.

[![](https://markdown-videos.deta/youtube/{RBi8kSpZZxw})](https://youtu.be/{RBi8kSpZZxw})

Enjoy it !!




