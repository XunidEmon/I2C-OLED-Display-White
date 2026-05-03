# I2C OLED Display with Arduino

Complete guide for using OLED display with Arduino Nano/Uno.

##  Wiring Connection

| Arduino | OLED Display |
|---------|--------------|
| 5V      | VCC          |
| GND     | GND          |
| A4      | SDA          |
| A5      | SCL          |

##  Libraries Needed

Install from Arduino Library Manager:
- Adafruit SSD1306
- Adafruit GFX

##  How OLED Display Works

### Simple Concept:
- **print()** = Stores text in memory (invisible)
- **display()** = Shows memory on screen (visible)

Without display(), nothing appears on screen!

### Key Functions:

| Function         |      What it does       |
|------------------|-------------------------|
| `begin()`        |    Initialize display   |
| `clearDisplay()` |      Clear screen       |
| `setCursor(x,y)` |     Set text position   |
| `setTextSize(n)` | Make text n times bigger|
| `print()`        |   Store text in memory  |
| `display()`      |      Show on screen     |

### Screen Size: 128 x 64 pixels
- X-axis: 0 to 127 (left to right)
- Y-axis: 0 to 63 (top to bottom)

##  Projects

### Project 1: Basic "Hi" Display

```cpp
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
