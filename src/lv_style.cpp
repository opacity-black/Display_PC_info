#include "GUI/lv_style.h"
#include "Arduino.h"

//白底黑字，无透明度，黑框
lv_style_t style_simple_white;
//黑底白字，无透明度，白框
lv_style_t style_simple_black;
//大字体
lv_style_t Big_text;
//
lv_style_t no_pad;

/*
 * 创建样式
 */

void createLvStyle()
{
    lv_style_init(&style_simple_white);
    lv_style_set_bg_color(&style_simple_white, lv_color_white());
    lv_style_set_bg_opa(&style_simple_white, LV_OPA_70);
    lv_style_set_text_color(&style_simple_white, lv_color_black());
    lv_style_set_border_width(&style_simple_white, 1);
    lv_style_set_border_color(&style_simple_white, lv_color_black());


    lv_style_init(&style_simple_black);
    lv_style_set_bg_color(&style_simple_black, lv_color_black());
    lv_style_set_text_color(&style_simple_black, lv_color_white());
    lv_style_set_border_width(&style_simple_white, 1);
    lv_style_set_border_color(&style_simple_black, lv_color_white());

    lv_style_init(&Big_text);
    lv_style_set_text_font(&Big_text, &lv_font_montserrat_28);  /*Set a larger font*/
    
    lv_style_init(&no_pad);
    lv_style_set_pad_all(&no_pad, 0);
}