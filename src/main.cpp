#include <Arduino.h>
#define LGFX_USE_V1
#include "LGFX_SSD1306.hpp"
// #include "LGFX_GC9A01.hpp"

static LGFX_SSD1306 lcd;
// static LGFX_GC9A01 lcd;

void setup() {
  lcd.init();
  lcd.setFont(&fonts::lgfxJapanGothicP_20);
  lcd.println("あいうえおかきくけこ");
}

void loop() {
  // put your main code here, to run repeatedly:
}