#ifndef _H_LVGL_BASIC
#define _H_LVGL_BASIC

#include "lvgl.h"


const uint16_t screenHeight = 240;
const uint16_t screenWidth  = 320;
//初始化lvgl
void my_init_lvgl();
//屏幕刷新函数
void my_disp_flush(lv_disp_drv_t * disp, const lv_area_t * area, lv_color_t * color_p);
//创建自定义的lvgl样式
void createLvStyle();

#endif