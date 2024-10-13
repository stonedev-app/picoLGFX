#include <Arduino.h>

#if defined(SSD1306)
#include "LGFX_SSD1306.hpp"
static LGFX_SSD1306 lcd;
#elif defined(GC9A01)
#include "LGFX_GC9A01.hpp"
static LGFX_GC9A01 lcd;
#elif defined(ST7789)
#include "LGFX_ST7789.hpp"
static LGFX_ST7789 lcd;
#endif

void setup() {
  lcd.init();
  lcd.setFont(&fonts::lgfxJapanGothicP_20);
  lcd.println("あいうえおかきくけこ");
}

void loop() {
  // put your main code here, to run repeatedly:
}