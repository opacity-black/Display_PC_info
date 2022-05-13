#ifndef _H_MY_WIFI
#define _H_MY_WIFI

#include <WiFi.h>
#include "esp_wifi.h"
// const char* ssid = "RUNOOB";
// const char* password = "123456789";
#define SSID_PHONE "jiechuwang"
#define PASSWORD_PHONE "12345678"

#define AP_SSID "ESP32-CAM"
#define AP_PASSWORD "12345678"

//校时服务器
#define NTP1 "ntp1.aliyun.com"
#define NTP2 "ntp2.aliyun.com"
#define NTP3 "ntp3.aliyun.com"

#define WIFI_OK true
#define AP_OK false

/*
 * [brief]  连接wifi
 * 
 * [in]     ssid - wifi名称
 * [in]     password - wifi密码
 * [in]     timeout_ms - 连接的超时时间，默认20s
 * 
 * [out]    连接结果 true - 连接成功
 */
bool connectWifi(const char *ssid, const char *password, int timeout_ms = 20000);

/*
 * [brief]  创建热点
 * 
 * [note]   热点和wifi不要同时开
 * 
 * [in]     apssid - 热点名称
 * [in]     appwd - 热点密码
 */
inline void createAP(const char *apssid = AP_SSID, const char *appwd = AP_PASSWORD) { WiFi.softAP((WiFi.softAPIP().toString() + "_" + (String)apssid).c_str(), appwd); };


/*
 * [brief]  网络初始化
 * 
 * [note]   默认连接手机热点，失败就自己创建热点esp32-cam，密码12345678
 * 
 * [in]     ssid - wifi名称
 * [in]     password - wifi密码
 */
bool initWifi(const char *ssid = SSID_PHONE, const char *password = PASSWORD_PHONE);



/*
 * [brief]  自动设置时间
 * 
 * [note]   开机第一次调用时会获取网络时间，以后调用则读取本地时间
 */
void setClock();

//网络初始化后会设置本地IP
extern String LocalIP;

#endif