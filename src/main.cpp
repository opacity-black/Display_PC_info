//提前引入
#include <Wire.h>
//我的接口
#include "MyApi.h"
#include "myLVGL.h"
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
  // note:不知道为什么wifi在lvgl初始化后打开，屏幕就会白屏，希望有懂得大佬指导
  // 如果你也出现了这个问题，不妨试试让wifi移到lvgl初始化之前打开
  // lv_start(20, "WiFi initial ...");
  // sBar.updateState(STATEBAR_WIFI_ON);
  // if (initWifi() != WIFI_OK)
  // {
  //   lv_start(45, "WiFi failed, open AP...");
  //   sBar.updateState(STATEBAR_WIFI_OFF);
  // }


  //获取网络时间
  if(WiFi.status()==WL_CONNECTED)
  {
    lv_start(70, "Get time ...");
    setClock();
  }


  //加载界面
  lv_start(LV_START_END);
  lv_menu();
}

void loop()
{
  lv_timer_handler();
  delay(5);
}
