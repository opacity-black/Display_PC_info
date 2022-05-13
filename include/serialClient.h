#ifndef _SERIAL_CLIENT
#define _SERIAL_CLIENT
#include <Arduino.h>

#define SERIAL_CLIENT_SIZE 30
class serialClient
{
private:
    bool is_connected;
    char temp[SERIAL_CLIENT_SIZE];
public:
    serialClient(int timeout_ms=100);
    ~serialClient();
    bool connect(int t=5);
    inline void p(const char * s){Serial.print(s);};
    inline void pl(const char * s){Serial.println(s);};
};

#endif