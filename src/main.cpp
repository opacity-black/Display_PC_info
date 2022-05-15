//提前引入
#include <Wire.h>
//我的接口
#include "MyApi.h"
#include "GUI/myLVGL.h"
// other
#include "soc/soc.h"
#include "soc/rtc_cntl_reg.h"


void setup()
{

  WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0); // prevent brownouts by silencing them

  my_init_lvgl();

  //串口
  lv_start(0, "Serial initial ...");
  Serial.begin(115200);
  Serial.setDebugOutput(true);
  Serial.setTimeout(100);
  Serial.println("Hello");
  sBar.updateState(STATEBAR_SERIAL_ON);

  // wifi
  lv_start(20, "WiFi initial ...");
  sBar.updateState(STATEBAR_WIFI_ON);
  if (initWifi() != WIFI_OK)
  {
    lv_start(45, "WiFi failed, open AP...");
    sBar.updateState(STATEBAR_WIFI_OFF);
  }


  //时间
  if(WiFi.status()==WL_CONNECTED)
  {
    lv_start(70, "Get time ...");
    setClock();
  }

  // ledcSetup(7, 5000, 8);
  // ledcAttachPin(4, 7); // pin4 is LED

  // startHttpServer();
  // Serial.println("HttpServer initial success...");

  //加载菜单
  lv_start(LV_START_END);
  lv_menu();
}

void loop()
{
  lv_timer_handler(); /* let the GUI do its work */
  delay(5);
}
