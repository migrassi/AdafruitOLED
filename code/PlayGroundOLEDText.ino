/*PlayGroundOLEDText.ino
  Created: 2023/06/21
  Last modified: 2023/06/26
  Version: 1.2
  Author: Miguel Grassi
  Contact: migrassi@gmail.com
  Description: Display text on OLED screen. It can be set as static, scrolling
  to the left or scrolling up. 

  You can set the following program parameters in the USER SETTING AREA below, without need of  
  modify the main code area:
    - The text to show in the screen
    - The font size to use 
    - The space between lines
    - The default scroll mode
    - The speed of vertical and horizontal scrolling
    
  Use the slide switch to choose between two modes:
    - Moving it to the left, turns the red LED on and set the scroll mode to "multiple",
      meaning that you can alternate scroll modes by pressing the left button on the board 
    - Moving it to the right, turns the red LED off and fix the last scroll mode selected.
      Be aware that booting the board the scroll mode will be returned to the default mode,
      which originally can be established in the USER SETTING AREA.
      See this short video: https://www.youtube.com/shorts/RBi8kSpZZxw

-------------------------------------------------------------------------------------------
  Attribution-NonCommercial-ShareAlike 2.0 Generic
  (CC BY-NC-SA 2.0) Miguel Grassi - https://github.com/migrassi/AdafruitOLED
*/
#include <Adafruit_CircuitPlayground.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET -1        // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3D  // See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
int x, minX, y, minY;
#define SCROLL_NONE 0 // Scroll modes 
#define SCROLL_LEFT 1
#define SCROLL_UP 2

//-------------------------------------------------------------------------------------------
// -------------------------- USER SETTING AREA ---------------------------------------------

// Replace the lines below with your own text lines
char* matriz[8] = { "Texto de la linea 001",
                    "Texto de la linea 002",
                    "Texto de la linea 003",
                    "Texto de la linea 004",
                    "Texto de la linea 005",
                    "Texto de la linea 006",
                    "Texto de la linea 007",
                    "Texto de la linea 008"
                  };

// Set space between lines, in pixels; 0=superpose
#define LEADING 8 //

// Set Font size 1 to 10
int fontsize = 1;

// Set default scroll mode as SCROLL_NONE, SCROLL_LEFT or SCROLL_UP
int scroll = SCROLL_UP;

//Set Horizontal and Vertical scroll speeds [try 1 to 6] 
int XSpeed=1; 
int YSpeed=1;

//--------------------------- END OF USER SETTING AREA -----------------------------------
//----------------------------------------------------------------------------------------

Adafruit_SSD1306 display(128, 64, &Wire, OLED_RESET);
void setup() {
  Serial.begin(9600);
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;  // Don't proceed, loop forever
  }

  // Initialize the circuit playground
  //CircuitPlayground.begin(); // IT DOESN'T WORKS WITH THE SCREEN CONNECTED!!!!
  
  pinMode(7, INPUT_PULLUP); // Switch
  pinMode(CPLAY_LEFTBUTTON, INPUT_PULLDOWN); // Left button
  pinMode(CPLAY_REDLED, OUTPUT); // red Led

  // Clear the buffer
  display.clearDisplay();
  display.display();
  display.setTextSize(fontsize);           
  display.setTextColor(SSD1306_WHITE);  // Draw white text
  display.setTextWrap(false);
  x = display.width();
  y =  display.height();
  //minX = -12 * strlen(message);  // 12 = 6 pixels/character * text size 2
  minX =  -6 * fontsize * strlen(matriz[0]); // Set matriz[X] as the longer line that you have defined above
  minY = -10 * 8 * fontsize;// Cantidad de lineas
}

void loop() {
  Serial.println(digitalRead(24));
  showText();
  if ( digitalRead(7)) { // If switch is on, enable scroll switching
    if (digitalRead(CPLAY_LEFTBUTTON)) { // Check if button is pressed
      delay(50); //debouncing
      if (digitalRead(CPLAY_LEFTBUTTON)) { // Change scroll mode
        scroll++;
        if (scroll > 2) scroll = 0;
      }
    }
  }
  digitalWrite(CPLAY_REDLED, digitalRead(7));  // Red LED on
}

void showText() { // Show the text in matriz
  display.clearDisplay();
  for (int i = 0; i < 8; i++) {
    display.setCursor(x, i * LEADING * fontsize + y);
    display.print(matriz[i]);
  }
  display.display();
  if (scroll == SCROLL_LEFT) {
    y = 0;
    x = x - XSpeed; // scroll speed, increment the substracted value to accelerate [1 to 8]
    if (x < minX) x = display.width();
  }
  else if (scroll == SCROLL_UP) {
    x = 0;
    y = y - YSpeed; // scroll speed, increment the substracted value to accelerate [1 to 8]
    if (y < minY) y = display.height();
  }
  else {
    x = 0;
    y = 0;
  }
}
