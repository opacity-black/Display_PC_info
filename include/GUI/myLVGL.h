#include "lv_basic.h"
#include "lv_widgets.h"
// #include "lv_style.h"

#define LV_START_END 100

extern StateBar sBar;
extern DisplayPanelS noteInfo;
extern DisplayPanelO ram;
extern DisplayPanelO gpu;
extern DisplayPanelO cpu;

/*
 * lvgl定时任务
 */
void showTime(lv_timer_t *timer);
void updateinfo(lv_timer_t *timer);

/*
 * [brief]  程序启动时显示进度条
 * 
 * [note]   最后一次调用必为"lv_start(LV_START_END);"，结束进度条
 * 
 * [in]     value - 加载百分比
 * [in]     text - 需要在进度条上显示的文字
 */
void lv_start(int value, const char *text = NULL);

/*
 * 加载主界面
 */
void lv_menu();
