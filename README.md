# AdafruitOLED
How to connect (and program) an Adafruit OLED 128x64 display to the Playground Express board

## Connecting

Using the STEMMA QT connector (the small one, on the back side of the display),you need to connect only 4 cables to the board using coco clips or soldering its:

![](/images/938-08.jpg)


## Programming

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
Download the code in a folder with the same name or just copy & paste it to your Arduino Window.





