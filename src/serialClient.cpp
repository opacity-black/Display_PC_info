#include "serialClient.h"

serialClient::serialClient(int timeout_ms)
{
    Serial.begin(115200);
    Serial.setDebugOutput(true);
    Serial.setTimeout(timeout_ms);
    Serial.println("Hello");
    this->is_connected = false;
}

serialClient::~serialClient()
{
}


bool serialClient::connect(int t)
{
    while(t--){
        Serial.print("Start$");
        static char buf[2];
        Serial.readBytesUntil(*"OK", &buf[2], 2);
        if (!strcmp(buf, "OK"))
        {
            this->is_connected=true;
            return true;
        }
    }
    return false;
}
