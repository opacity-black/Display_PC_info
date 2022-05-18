#include "myLVGL.h"
#include "Arduino.h"
#include "ArduinoJson.h"

StateBar sBar;
DisplayPanelO gpu;
DisplayPanelO ram;
DisplayPanelO cpu;
DisplayPanelS noteInfo;


static void set_value(void *bar, int32_t v)
{
    lv_bar_set_value((lv_obj_t *)bar, v, LV_ANIM_OFF);
}


void lv_start(int value, const char *text)
{
    static Bar m_bar(200, 20);
    static lv_obj_t *lb = lv_label_create(lv_scr_act());
    if (value == LV_START_END)
    {
        m_bar.~Bar();
        lv_obj_del(lb);
        lv_timer_handler();
        return;
    }
    lv_bar_set_value(m_bar.bar, value, LV_ANIM_OFF);

    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_var(&a, m_bar.bar);
    lv_anim_set_values(&a, lv_bar_get_value(m_bar.bar), value);
    lv_anim_set_exec_cb(&a, set_value);
    lv_anim_set_time(&a, 2000);
    lv_anim_set_playback_time(&a, 2000);
    lv_anim_set_repeat_count(&a, LV_ANIM_REPEAT_INFINITE);
    lv_anim_start(&a);

    lv_label_set_text(lb, text);
    lv_obj_center(lb);

    lv_timer_handler(); /* let the GUI do its work */
}


void lv_menu(void)
{

    //初始化通知栏
    sBar.init();
    sBar.setState();

    /*初始化信息板*/
    gpu.init(lv_pct(28), lv_pct(40), lv_pct(5), lv_pct(13), "GPU");
    cpu.init(lv_pct(28), lv_pct(40), lv_pct(36), lv_pct(13), "CPU");
    ram.init(lv_pct(28), lv_pct(40), lv_pct(67), lv_pct(13), "RAM");
    noteInfo.init(lv_pct(90), lv_pct(40), lv_pct(5), lv_pct(56));
    noteInfo.print("Waitting...");

    //加载定时器
    lv_timer_t *t = lv_timer_create(updateinfo, 500, NULL);
}

//要求是label对象【弃用】
void showTime(lv_timer_t *timer)
{
    struct tm timeinfo;
    getLocalTime(&timeinfo, 60);
    lv_obj_t *obj = (lv_obj_t *)(timer->user_data);
    lv_label_set_text(obj, asctime(&timeinfo));
}

DynamicJsonDocument doc(1024);
void updateinfo(lv_timer_t *timer)
{
    static int i=0;
    String res = Serial.readStringUntil('\n');
    if(res.length()>5){
        i=0;
        deserializeJson(doc, res);
        JsonObject obj = doc.as<JsonObject>();
        sBar.setTime(obj[F("time")]);
        gpu.setvalue( obj[F("GPU")] );
        cpu.setvalue( obj[F("CPU")] );
        ram.setvalue( obj[F("RAM")] );
        noteInfo.print( (const char *)obj[F("Text")] );
        if(!sBar.getState(STATEBAR_SERIAL_CON))
            sBar.updateState(STATEBAR_SERIAL_CON);
            sBar.setState();
    }else{
        i++;
        if(i>4)
        {
            i=0;
            sBar.updateState(STATEBAR_SERIAL_DCON);
            sBar.setState();
        }
    }
}