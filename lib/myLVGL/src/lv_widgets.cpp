// lvgl组件库
#include <Arduino.h>
#include "lv_style.h"
#include "lv_widgets.h"

/*
 * 自定义按钮
 */
Button::Button(lv_coord_t w, lv_coord_t h, lv_obj_t *parent)
{
    this->btn = lv_btn_create(parent);
    lv_obj_add_style(this->btn, &style_simple_white, LV_STATE_DEFAULT);
    lv_obj_add_style(this->btn, &style_simple_black, LV_STATE_PRESSED);
    lv_obj_set_size(this->btn, w, h);
    lv_obj_center(this->btn);


    this->label = lv_label_create(this->btn);
    lv_label_set_text(this->label, "NULL");
    lv_obj_center(this->label);
    // lv_obj_align(this->label, LV_ALIGN_CENTER, 0, 0);
}

Button::~Button()
{
    lv_obj_del(this->label);
    lv_obj_del(this->btn);
}

void Button::setLabel(const char *text)
{
    lv_label_set_text(this->label, text);
}


void Button::setPos(lv_coord_t x, lv_coord_t y)
{
    lv_obj_set_pos(this->btn, x, y);
}


/*
 * 自定义面板
 */
Panel::Panel(lv_coord_t w, lv_coord_t h, lv_coord_t x, lv_coord_t y, lv_obj_t *parent)
{
    this->panel = lv_obj_create(parent);
    lv_obj_set_size(this->panel, w, h);
    // lv_obj_set_scroll_snap_x(this->panel, LV_SCROLL_SNAP_CENTER);
    // lv_obj_set_flex_flow(this->panel, LV_FLEX_FLOW_ROW);
    lv_obj_add_style(this->panel, &style_simple_black, LV_STATE_DEFAULT);
    lv_obj_set_pos(this->panel,x,y);
    // lv_obj_align(this->panel, LV_ALIGN_CENTER, 0, 0);
}


Bar::Bar(lv_coord_t w, lv_coord_t h, const char * text, lv_obj_t *parent)
{
    this->bar = lv_bar_create(parent);
    lv_obj_set_size(this->bar, w, h);
    lv_obj_center(this->bar);
    if(text!=NULL)
    {
        this->label = lv_label_create(this->bar);
        lv_label_set_text(this->label,text);
        lv_obj_center(this->label);
    }
}
Bar::~Bar()
{
    if(this->label!=NULL)
        lv_obj_del_async(this->label);
    lv_obj_del_async(this->bar);
}


Special_Arc::Special_Arc(lv_coord_t w, lv_coord_t h, const char * text, lv_obj_t *parent)
{
    /*Create an Arc*/
    this->arc = lv_arc_create(parent);
    lv_obj_set_size(this->arc, w, h);
    lv_arc_set_rotation(this->arc, 135);
    lv_arc_set_bg_angles(this->arc, 0, 270);
    lv_arc_set_value(this->arc, 0);
    lv_obj_center(this->arc);

    this->label = lv_label_create(this->arc);
    lv_label_set_text(this->label, text);
    lv_obj_align(this->label, LV_ALIGN_BOTTOM_MID, 0, 0);
    
    this->num = lv_label_create(this->arc);
    lv_label_set_text(this->num, "0%");
    lv_obj_add_style(this->num, &Big_text, LV_STATE_DEFAULT);
    lv_obj_center(this->num);
}

Special_Arc::~Special_Arc()
{
    lv_obj_del(this->arc);
}

void Special_Arc::setValue(int val)
{
    lv_arc_set_value(this->arc, val);
    lv_label_set_text_fmt(this->num, "%d%%", val);
}


StateBar::StateBar()
{

}

void StateBar::init()
{
    this->panel = lv_obj_create(lv_scr_act());
    lv_obj_set_pos(this->panel,0,0);
    lv_obj_set_style_pad_all(this->panel, 0, LV_STATE_DEFAULT);
    lv_obj_set_size(this->panel, lv_pct(100), lv_pct(8));
    lv_obj_set_style_min_height(this->panel,24,LV_STATE_DEFAULT);

    this->time_lbl = lv_label_create(this->panel);
    lv_label_set_text(time_lbl,"time");
    lv_obj_align(time_lbl, LV_ALIGN_RIGHT_MID, 0, 0);

    this->state_lbl = lv_label_create(this->panel);
    lv_label_set_text(state_lbl,"state");
    lv_obj_align(state_lbl, LV_ALIGN_LEFT_MID, 0, 0);
}

StateBar::~StateBar()
{
    lv_obj_del(this->time_lbl);
    lv_obj_del(this->state_lbl);
    lv_obj_del(this->panel);
}

void StateBar::setState()
{
    String state;
    for(int i=0; i<sizeof(this->slist)/sizeof(int); i++)
    {
        switch (this->slist[i])
        {
        case STATEBAR_WIFI_ON:
            state+=LV_SYMBOL_WIFI;
            break;
        case STATEBAR_SERIAL_CON:
            state+=LV_SYMBOL_OK;
            break;
        case STATEBAR_SERIAL_ON:
            state+=LV_SYMBOL_USB;
            break;
        }
    }
    lv_label_set_text(this->state_lbl, state.c_str());
}

void StateBar::setTime(const char * t)
{
    lv_label_set_text(this->time_lbl, t);
}

void StateBar::updateState(int state)
{
    this->slist[state/2]=state;
}


bool StateBar::getState(int state)
{
    return (this->slist[state/2]==state) ? true:false;
}



DisplayPanelO::DisplayPanelO() { }
void DisplayPanelO::init(lv_coord_t w, lv_coord_t h, lv_coord_t x, lv_coord_t y, const char* text, lv_obj_t *parent)
{
    this->panel = lv_obj_create(parent);
    lv_obj_set_size(this->panel, w, h);
    lv_obj_set_pos(this->panel,x,y);
    lv_obj_set_style_pad_all(panel, 2, LV_STATE_DEFAULT);
    lv_obj_add_style(this->panel, &style_simple_black, LV_STATE_DEFAULT);

    /*Create an Arc*/
    this->arc = lv_arc_create(this->panel);
    lv_obj_set_size(this->arc, lv_pct(95), lv_pct(95));
    lv_arc_set_rotation(this->arc, 135);
    lv_arc_set_bg_angles(this->arc, 0, 270);
    lv_arc_set_value(this->arc, 0);
    lv_obj_center(this->arc);

    this->label = lv_label_create(this->arc);
    lv_label_set_text(this->label, text);
    lv_obj_align(this->label, LV_ALIGN_BOTTOM_MID, 0, 0);
    
    this->num = lv_label_create(this->arc);
    lv_label_set_text(this->num, "0%");
    lv_obj_add_style(this->num, &Big_text, LV_STATE_DEFAULT);
    lv_obj_center(this->num);
}
DisplayPanelO::~DisplayPanelO() 
{
    lv_obj_del(this->num);
    lv_obj_del(this->label);
    lv_obj_del(this->arc);
    lv_obj_del(this->panel);
}
void DisplayPanelO::setvalue(int val)
{
    lv_arc_set_value(this->arc, val);
    lv_label_set_text_fmt(this->num, "%d%%", val);
}



DisplayPanelS::DisplayPanelS(){}
void DisplayPanelS::init(lv_coord_t w, lv_coord_t h, lv_coord_t x, lv_coord_t y, lv_obj_t *parent)
{
    this->panel = lv_obj_create(parent);
    lv_obj_set_size(this->panel, w, h);
    lv_obj_add_style(this->panel, &style_simple_black, LV_STATE_DEFAULT);
    lv_obj_set_pos(this->panel,x,y);
    lv_obj_set_style_pad_all(this->panel, 2, LV_STATE_DEFAULT);
    
    this->lbl = lv_label_create(this->panel);
    lv_obj_align(this->lbl,LV_ALIGN_TOP_LEFT,0,0);
}
DisplayPanelS::~DisplayPanelS()
{
    lv_obj_del(this->panel);
    lv_obj_del(this->lbl);
}
void DisplayPanelS::print(const char * text)
{
    lv_label_set_text(this->lbl, text);
}