#ifndef LV_STYLE
#define LV_STYLE

#include "lvgl.h"

//白底黑字，无透明度，黑框
extern lv_style_t style_simple_white;
//黑底白字，无透明度，白框
extern lv_style_t style_simple_black;
//大字体
extern lv_style_t Big_text;
//取消内边距
extern lv_style_t no_pad;

void createLvStyle();

#endif