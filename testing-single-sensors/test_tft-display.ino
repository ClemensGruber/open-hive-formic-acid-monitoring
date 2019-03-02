/*
  Open Hive | TFT-Display for Adafruit Feather
            | with Feather Huzzah ESP32
            
  2019-02 Clemens Gruber | initial sketch

  This code is in the public domain.
*/

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

// pin definition for ESP32
#define STMPE_CS 32
#define TFT_CS   15
#define TFT_DC   33
#define SD_CS    14

// set TFT 
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);

int counter  = 1;
  
void setup() {
  // serial communication 
  Serial.begin(9600);

  // initialize TFT 
  tft.begin();
  tft.fillScreen(ILI9341_BLACK);  // clear garbage from the last run 

  // set rotation (possible values 0 = portrait format up to 3)
  tft.setRotation(1);
}


void loop(void) {
  testText();
  delay(500);
}

void testText() {
  tft.setTextColor(ILI9341_GREEN, ILI9341_BLACK);  
  tft.setTextSize(1);
  
  tft.setCursor(0, 0);
  tft.println("Open Hive | IV Steglitz        Formic Acid Monitoring");
  tft.println();


  // 1. row - labels 
  int yPixRow1 = 25; 
  int yDataRow = 14; 
  tft.setTextSize(1); 
  tft.setCursor(0, yPixRow1);
  tft.println("temp out");

  tft.setCursor(90, yPixRow1);
  tft.println("humid out");

  tft.setCursor(180, yPixRow1);
  tft.println("press out");


  // 1. row - data 
  tft.setTextSize(2); 
  
  tft.setCursor(0, yPixRow1 + yDataRow);
  tft.println("--.-");

  tft.setCursor(90, yPixRow1 + yDataRow);
  tft.println("---");

  tft.setCursor(180, yPixRow1 + yDataRow);
  tft.println("----");


  // 2. row - labels 
  int yPixRow2 = yPixRow1 + 40; 
  tft.setTextSize(1); 
  tft.setCursor(0, yPixRow2);
  tft.println("temp in");

  tft.setCursor(90, yPixRow2);
  tft.println("humid in");

  tft.setCursor(180, yPixRow2);
  tft.println("weight");


  // 2. row - data 
  tft.setTextSize(2); 
  
  tft.setCursor(0, yPixRow2 + yDataRow);
  tft.println("--.-");

  tft.setCursor(90, yPixRow2 + yDataRow);
  tft.println("---");

  tft.setCursor(180, yPixRow2 + yDataRow);
  tft.println("---.---");


  // 3. row - labels 
  int yPixRow3 = yPixRow2 + 50; 
  tft.setTextSize(1); 
  tft.setCursor(0, yPixRow3);
  tft.println("#");

  tft.setCursor(30, yPixRow3);
  tft.println("acd curr");

  tft.setCursor(100, yPixRow3);
  tft.println("minimum");

  tft.setCursor(170, yPixRow3);
  tft.println("maximum");

  tft.setCursor(240, yPixRow3);
  tft.println("average");

  // 3. row - data 
  int yDataOnlyRow = 20;
  tft.setTextSize(2); 
  
  tft.setCursor(0, yPixRow3 + yDataOnlyRow);
  tft.println("1");

  tft.setCursor(30, yPixRow3 + yDataOnlyRow);
  tft.println("----");

  tft.setCursor(100, yPixRow3 + yDataOnlyRow);
  tft.println("----");

  tft.setCursor(170, yPixRow3 + yDataOnlyRow);
  tft.println("----");

  tft.setCursor(240, yPixRow3 + yDataOnlyRow);
  tft.println("----");


  // 4. row - data only 
  tft.setTextSize(2); 
  
  tft.setCursor(0, yPixRow3 + 2*yDataOnlyRow);
  tft.println("2");

  tft.setCursor(30, yPixRow3 + 2*yDataOnlyRow);
  tft.println("----");

  tft.setCursor(100, yPixRow3 + 2*yDataOnlyRow);
  tft.println("----");

  tft.setCursor(170, yPixRow3 + 2*yDataOnlyRow);
  tft.println("----");

  tft.setCursor(240, yPixRow3 + 2*yDataOnlyRow);
  tft.println("----");

  
  // 5. row - data only 
  tft.setTextSize(2); 
  
  tft.setCursor(0, yPixRow3 + 3*yDataOnlyRow);
  tft.println("3");

  tft.setCursor(30, yPixRow3 + 3*yDataOnlyRow);
  tft.println("----");

  tft.setCursor(100, yPixRow3 + 3*yDataOnlyRow);
  tft.println("----");

  tft.setCursor(170, yPixRow3 + 3*yDataOnlyRow);
  tft.println("----");

  tft.setCursor(240, yPixRow3 + 3*yDataOnlyRow);
  tft.println("----");


  // 6. row - data only 
  tft.setTextSize(2); 
  
  tft.setCursor(0, yPixRow3 + 4*yDataOnlyRow);
  tft.println("4");

  tft.setCursor(30, yPixRow3 + 4*yDataOnlyRow);
  tft.println("----");

  tft.setCursor(100, yPixRow3 + 4*yDataOnlyRow);
  tft.println("----");

  tft.setCursor(170, yPixRow3 + 4*yDataOnlyRow);
  tft.println("----");

  tft.setCursor(240, yPixRow3 + 4*yDataOnlyRow);
  tft.println("----");


 // tft.println("xx.x xx.x xx.x xx.x xx.x");

  
  counter = 1; 
  // update data 
  do {
    tft.setCursor(0, yPixRow1 + yDataRow);
    counter = counter + 1;
    if (counter < 10) {
      tft.print(" ");
    }
    
    tft.println(counter);

    delay(1000); 
  } while (counter < 99);

}
