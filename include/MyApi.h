// 还没写。。。占个位置
#ifndef _H_MYAPI
#define _H_MYAPI

// wifi
#include "web/myWifi.h"

#define API_WEB 0
#if API_WEB

class webApi
{
public:
    webApi(HTTPClient * httpc, DynamicJsonDocument * doc);
    ~webApi();
    void getWeather();

private:
    String url;
    char * updateTime;
    HTTPClient * httpc;
    DynamicJsonDocument * doc;
};

#endif


#define API_SENSOR 1
#if API_SENSOR

    #define API_SENSOR_CAMERA 0
    #if API_SENSOR_CAMERA
        #include "sensor/Camera.h"
    #endif

#endif




#endif