#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

const int TRIG_PIN    = 9;
const int ECHO_PIN    = 8;
const int BUZZER_PIN  = 3;
const int BUILTIN_LED = 13; 

unsigned long lastBeepTime = 0;
bool buzzerState = false;

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(BUILTIN_LED, OUTPUT);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
}

void loop() {
  
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  float distance = duration * 0.0343 / 2;

  display.clearDisplay();

  if (distance > 30.0 || distance <= 0) {
    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(BUILTIN_LED, LOW);

    display.setTextColor(SSD1306_WHITE);
    
    
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.println(F("RADAR DISTANCE:"));

   
    display.setTextSize(2);
    display.setCursor(0, 14);
    display.print(distance, 1);
    display.println(F(" cm"));

    
    display.drawRect(0, 34, 120, 10, SSD1306_WHITE);
    int barWidth = map((int)constrain(distance, 0, 50), 0, 50, 0, 116);
    display.fillRect(2, 36, barWidth, 6, SSD1306_WHITE);

    
    display.setTextSize(1);
    display.setCursor(0, 50);
    display.println(F("STATUS: SAFE"));
  } 

  else if (distance > 10.0 && distance <= 30.0) {
    digitalWrite(BUILTIN_LED, HIGH);

    
    int beepInterval = map((int)distance, 10, 30, 100, 400); 
    if (millis() - lastBeepTime >= beepInterval) {
      lastBeepTime = millis();
      buzzerState = !buzzerState;
      digitalWrite(BUZZER_PIN, buzzerState ? HIGH : LOW);
    }

    display.setTextColor(SSD1306_WHITE);

   
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.println(F("RADAR DISTANCE:"));

    
    display.setTextSize(2);
    display.setCursor(0, 14);
    display.print(distance, 1);
    display.println(F(" cm"));

    
    display.drawRect(0, 34, 120, 10, SSD1306_WHITE);
    int barWidth = map((int)constrain(distance, 0, 50), 0, 50, 0, 116);
    display.fillRect(2, 36, barWidth, 6, SSD1306_WHITE);

    
    display.setTextSize(1);
    display.setCursor(0, 50);
    display.println(F("STATUS: WARNING!"));
  } 

  
  else {
    digitalWrite(BUZZER_PIN, HIGH);  
    digitalWrite(BUILTIN_LED, HIGH); 

   
    display.fillScreen(SSD1306_WHITE);
    
    
    display.setTextColor(SSD1306_BLACK);

    display.setTextSize(1);
    display.setCursor(0, 2);
    display.println(F("CRITICAL STOP!!"));

    
    display.setTextSize(2);
    display.setCursor(0, 18);
    display.print(distance, 1);
    display.println(F(" cm"));

    
    display.drawRect(0, 38, 120, 10, SSD1306_BLACK);
    int barWidth = map((int)constrain(distance, 0, 50), 0, 50, 0, 116);
    display.fillRect(2, 40, barWidth, 6, SSD1306_BLACK);

    display.setTextSize(1);
    display.setCursor(0, 52);
    display.println(F("TOO CLOSE!"));
  }

  display.display();
  delay(50);
}