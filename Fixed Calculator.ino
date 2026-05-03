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
    num1 = Serial.parseInt();
    num2 = Serial.parseInt();
    
    // Clear buffer - THIS FIXES THE BUG
    while (Serial.available()) 
      Serial.read();
    
    int sum = num1 + num2;
    
    oled.clearDisplay();
    oled.setCursor(0, 0); 
    oled.print("Num1: "); 
    oled.print(num1);
    oled.setCursor(0, 20); 
    oled.print("Num2: "); 
    oled.print(num2);
    oled.setCursor(0, 40); 
    oled.print("Sum: ");  
    oled.print(sum);
    oled.display();
    
    Serial.print("Sum: "); 
    Serial.println(sum);
    Serial.println("Enter two numbers:");
  }
}
