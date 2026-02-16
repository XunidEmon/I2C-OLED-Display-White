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


