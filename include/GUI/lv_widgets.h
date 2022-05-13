#ifndef _H_LVGL_WIDGETS
#define _H_LVGL_WIDGETS

class Button
{
    public:
        Button(lv_coord_t w, lv_coord_t h, lv_obj_t *parent=lv_scr_act());
        ~Button();
        // void setLabel(String text);
        void setLabel(const char * text);
        void setEvent();
        void setPos(lv_coord_t x, lv_coord_t y);
        lv_obj_t* btn;
        lv_obj_t* label;
    private:
};

class Panel
{
    public:
        Panel(lv_coord_t w, lv_coord_t h, lv_coord_t x=0, lv_coord_t y=0, lv_obj_t *parent=lv_scr_act());
        // ~Panel();
        lv_obj_t* panel;

    private:
};


// class Switch
// {
//     public:
//         Switch(lv_coord_t w, lv_coord_t h);
//         // ~Switch();
//         lv_obj_t* sw;

//     private:
// };


class Bar
{
    public:
    Bar(lv_coord_t w, lv_coord_t h, const char * text=NULL, lv_obj_t *parent=lv_scr_act());
    ~Bar();
    lv_obj_t * bar;
    lv_obj_t * label;
};


class Special_Arc
{
    public:
    Special_Arc(lv_coord_t w, lv_coord_t h, const char * text, lv_obj_t *parent=lv_scr_act());
    ~Special_Arc();
    lv_obj_t * arc;
    lv_obj_t * label;
    lv_obj_t* num;
    //val=0-100%
    void setValue(int val);         
};


//状态
enum {
    _WIFI_S_ON,
    _WIFI_S_OFF,

    _WIFI_S_CON,
    _WIFI_S_DCON,

    _SERIAL_S_ON,
    _SERIAL_S_OFF,
};
//状态栏
class StateBar
{
    public:
        StateBar();
        ~StateBar();
        lv_obj_t * panel;
        lv_obj_t * time_lbl;
        lv_obj_t * state_lbl;
        //在lvgl初始化完成之前不可以调用init()
        void init();
        //不涉及显示，可随时调用
        void updateState(int state);
        //在init()之前不可以调用setState()
        void setState();
        //验证通知栏状态
        bool getState(int state);
    private:
        //状态列表
        int slist[3] = {_WIFI_S_OFF,_WIFI_S_DCON,_SERIAL_S_OFF};
};


//显示面板O，仪表盘
class DisplayPanelO
{
    public:
        DisplayPanelO();
        ~DisplayPanelO();
        void init(lv_coord_t w, lv_coord_t h, lv_coord_t x=0, lv_coord_t y=0, const char* text=" ", lv_obj_t *parent=lv_scr_act());
        void setvalue(int val);
    private:
        lv_obj_t * panel;
        lv_obj_t * arc;
        lv_obj_t * label;
        lv_obj_t * num;
};


//显示面板S，文字
class DisplayPanelS
{
    public:
        DisplayPanelS();
        ~DisplayPanelS();
        void init(lv_coord_t w, lv_coord_t h, lv_coord_t x=0, lv_coord_t y=0, lv_obj_t *parent=lv_scr_act());
        void print(const char * text);
    private:
        lv_obj_t * panel;
        lv_obj_t * lbl;
};

#endif