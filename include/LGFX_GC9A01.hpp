#pragma once

#define LGFX_USE_V1
#include <LovyanGFX.hpp>

class LGFX_GC9A01 : public lgfx::LGFX_Device
{
    lgfx::Panel_GC9A01      _panel_instance;
    lgfx::Bus_SPI           _bus_instance;
    lgfx::Light_PWM         _light_instance;
  public:
    LGFX_GC9A01(void)
    {
      {
        auto cfg = _bus_instance.config();
        cfg.spi_host   = 1;
        cfg.spi_mode   = 0;
        cfg.freq_write = 10000000;
        cfg.pin_sclk   = 10;
        cfg.pin_miso   = -1;
        cfg.pin_mosi   = 11;
        cfg.pin_dc     = 8;
        _bus_instance.config(cfg);
        _panel_instance.setBus(&_bus_instance);
      }

      {
        auto cfg = _panel_instance.config();
        cfg.pin_cs           =    9;
        cfg.pin_rst          =    12;
        cfg.panel_width      =   240;
        cfg.panel_height     =   240;
        cfg.offset_x         =     0;
        cfg.offset_y         =     0;
        cfg.invert           =  true;  // パネルの明暗が反転してしまう場合 trueに設定

        _panel_instance.config(cfg);
      }
      {
        auto cfg = _light_instance.config();
        cfg.pin_bl      = 22;
        _light_instance.config(cfg);
        _panel_instance.setLight(&_light_instance);
      }

      setPanel(&_panel_instance); // 使用するパネルをセットします。
    }
};