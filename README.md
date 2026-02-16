# I2C-OLED-Display-White

#include <Wire.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 d(128, 64, &Wire, -1);

void setup() {
  Wire.begin();
  d.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  d.clearDisplay();
  d.setTextSize(2);
  d.setTextColor(SSD1306_WHITE);
  d.setCursor(20, 25);
  d.print("Hi");
  d.display();
}

void loop() {}



[(https://wokwi.com/projects/new/arduino-nano)](https://wokwi.com/)


#define SSD1306_NO_SPLASH   // Disable Adafruit's default splash logo

#include <Wire.h>            // I2C communication library
#include <Adafruit_SSD1306.h> // OLED display library

// Create an OLED object with 128x64 resolution
Adafruit_SSD1306 d(128, 64, &Wire, -1);

void setup() {

  Wire.begin();  
  // Start I2C communication (Nano/Uno → SDA=A4, SCL=A5)

  d.begin(SSD1306_SWITCHCAPVCC, 0x3C);  
  // Initialize OLED (0x3C = I2C address)

  d.clearDisplay();  
  // Clear the screen

  d.setTextSize(2);  
  // Set text size

  d.setTextColor(SSD1306_WHITE);  
  // Set text color to white

  d.setCursor(10, 25);  
  // Set cursor position on the screen

  d.print("Hello UAP");  
  // Display text on the screen

  d.display();  
  // Actually update the screen with the text (very important)
}

void loop() {
  // Empty loop – nothing will change continuously
}















#include <Wire.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 oled(128, 64, &Wire, -1);

int num1, num2;

void setup() {
  Wire.begin();
  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  oled.clearDisplay();
  oled.setTextSize(2);
  oled.setTextColor(SSD1306_WHITE);

  Serial.begin(9600);
  Serial.println("Enter two numbers:");
}

void loop() {
  if (Serial.available() > 0) {
    num1 = Serial.parseInt();  // first number
    num2 = Serial.parseInt();  // second number

    int sum = num1 + num2;

    oled.clearDisplay();
    oled.setCursor(0, 0); oled.print("Num1: "); oled.print(num1);
    oled.setCursor(0, 20); oled.print("Num2: "); oled.print(num2);
    oled.setCursor(0, 40); oled.print("Sum: ");  oled.print(sum);
    oled.display();

    Serial.print("Sum: "); Serial.println(sum);
    Serial.println("Enter two numbers:");
  }
}
















#include <Wire.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 oled(128, 64, &Wire, -1);

int num1 = 0;
int num2 = 0;

void setup() {
  Wire.begin();
  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  oled.clearDisplay();
  oled.setTextSize(2);
  oled.setTextColor(SSD1306_WHITE);
  oled.display();

  Serial.begin(9600);
  Serial.println("Enter two numbers:");
}

void loop() {
  if (Serial.available()) {
    // read numbers only when Enter is pressed
    num1 = Serial.parseInt();
    num2 = Serial.parseInt();

    // Clear leftover characters in serial buffer
    while (Serial.available()) Serial.read();

    int sum = num1 + num2;

    oled.clearDisplay();
    oled.setCursor(0, 0); oled.print("Num1: "); oled.print(num1);
    oled.setCursor(0, 20); oled.print("Num2: "); oled.print(num2);
    oled.setCursor(0, 40); oled.print("Sum: ");  oled.print(sum);
    oled.display();

    Serial.print("Sum: "); Serial.println(sum);
    Serial.println("Enter two numbers:");
  }
}
