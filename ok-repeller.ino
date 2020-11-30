#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

int speaker = 11; // Digital Pin 11
int frequency = 90000; // 90KHz (adjust it between 20KHz to 170KHz)
int frequency1 = 20000; // 20KHz (adjust it between 20KHz to 170KHz)
int frequency2 = 37000; // 37KHz (adjust it between 20KHz to 170KHz)
int frequency3 = 60000; // 60KHz (adjust it between 20KHz to 170KHz)

#define setbit(data,b) (data|=(1<<b)) //set the b bit of data to 1
#define clrbit(data,b) (data&=~(1<<b)) //set the b bit of data to 0
uint8_t code8421 = 0;
const uint8_t code8Pin = 5;
const uint8_t code4Pin = 4;
const uint8_t code2Pin = 3;
const uint8_t code1Pin = 2;

Adafruit_SSD1306 display(-1);

void setup()   
{                
  // initialize with the I2C addr 0x3C
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  

  // Clear the buffer.
  display.clearDisplay();

  // Display Text
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,15);
  display.println("E-REPELLER");
  display.setCursor(0,30);
  display.println("-gada888-");
  display.display();
  delay(2000);
  display.clearDisplay();
  
Serial.begin(115200);
Serial.println("8421 Encoder Starts up!");
pinMode(code8Pin, INPUT);
pinMode(code4Pin, INPUT);
pinMode(code2Pin, INPUT);
pinMode(code1Pin, INPUT);
}

void loop() 
{
 if (digitalRead(code8Pin) == HIGH){
setbit(code8421, 3);
tone(speaker, frequency);
// Display Text
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,15);
  display.println("Frequency");
  display.display();
  delay(2000);
  display.clearDisplay();
}

if (digitalRead(code4Pin) == HIGH){
setbit(code8421, 2);
tone(speaker, frequency1);
// Display Text
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,15);
  display.println("Frequency1");
  display.display();
  delay(2000);
  display.clearDisplay();
}

if (digitalRead(code2Pin) == HIGH){
setbit(code8421, 1);
tone(speaker, frequency2);
// Display Text
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,15);
  display.println("Frequency2");
  display.display();
  delay(2000);
  display.clearDisplay();
}

if (digitalRead(code1Pin) == HIGH){
setbit(code8421, 0);
tone(speaker, frequency3);
// Display Text
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,15);
  display.println("Frequency3");
  display.display();
  delay(2000);
  display.clearDisplay();
}

//Output the code in hexadecimal
Serial.print("Now code8421 is: ");
Serial.println(code8421, HEX);
delay(1000);
   } 
