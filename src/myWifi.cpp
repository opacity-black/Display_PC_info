#include "web/myWifi.h"
#include "GUI/myLVGL.h"

String LocalIP = "";

bool initWifi(const char *ssid, const char *password)
{

  Serial.println("ssid: " + (String)ssid);
  Serial.println("password: " + (String)password);

  if (connectWifi(ssid, password))
  {
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.print("IP:");
    Serial.print(WiFi.localIP());
    LocalIP += WiFi.localIP().toString();
    return WIFI_OK;
  }
  else
  {
    Serial.println("");
    Serial.println("WiFi disconnected");
    Serial.print("IP");
    Serial.print(WiFi.softAPIP());
    createAP();
    LocalIP += WiFi.localIP().toString();
    return AP_OK;
  }
}


void setClock()
{
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo, 2000))
  { //如果获取失败，就联网获取时间
    configTime(8 * 3600, 0, NTP1, NTP2, NTP3);
    return;
  }
  Serial.println(&timeinfo, "%F %T %A"); // 格式化输出:2021-10-24 23:00:44 Sunday
  Serial.print(asctime(&timeinfo));      //默认打印格式：Mon Oct 25 11:13:29 2021
}


// void sleep_ms(int t)
// {
//   long int StartTime = millis();
//   while((StartTime + t) > millis());
// }
bool connectWifi(const char *ssid, const char *password, int timeout_ms)
{

  WiFi.begin(ssid, password);
  delay(200);

  long int StartTime = millis();
  while (WiFi.status() != WL_CONNECTED)
  {
    if ((StartTime + timeout_ms) < millis())
      return false;
    delay(200);
  }
  return true;
}