// /*
//  * 基本接口
//  */
// #include <HTTPClient.h>
// #include <ArduinoJson.h>
// #include "WebApi.h"

// // HTTPClient httpc;
// // DynamicJsonDocument doc(2048);

// webApi::webApi(HTTPClient * httpc, DynamicJsonDocument * doc)
// {
//     this->url = "https://bird.ioliu.cn/weather?city=%E5%8D%97%E6%98%8C";
//     this->httpc = httpc;
//     this->doc = doc;
// }

// void webApi::getWeather()
// {
//     httpc.begin(this->url);
//     if(httpc.GET()==HTTP_CODE_OK)
//     {
//         httpc.setUserAgent("Mozilla/5.0 (Windows NT 11.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/99.0.4844.82 Safari/537.36");
//         deserializeJson(doc, httpc.getString());
//         JsonObject obj = doc.as<JsonObject>();

//         this->updateTime = obj[F("basic")][F("update")][F("loc")];
//     }
//     httpc.end();
// }