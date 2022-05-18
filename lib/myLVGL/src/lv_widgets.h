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
    STATEBAR_WIFI_ON,
    STATEBAR_WIFI_OFF,

    STATEBAR_SERIAL_CON,
    STATEBAR_SERIAL_DCON,

    STATEBAR_SERIAL_ON,
    STATEBAR_SERIAL_OFF,
};
//状态栏
class StateBar
{
    private:
        lv_obj_t * panel;
        lv_obj_t * time_lbl;
        lv_obj_t * state_lbl;
        //状态列表，默认全部关闭
        int slist[3] = {STATEBAR_WIFI_OFF,STATEBAR_SERIAL_DCON,STATEBAR_SERIAL_OFF};
    public:
        StateBar();
        ~StateBar();

        //所有需要创建object的语句都要在lvgl初始化完成之后，该函数也是
        void init();


        /*
         * [brief]  更新通知栏状态
         * 
         * [note]   该函数不涉及显示！只改变存储状态的数组，可在任何时刻调用
         * 
         * [in]     state - 新状态
         */
        void updateState(int state);


        /*
         * [brief]  更新通知栏显示
         * 
         * [note]   在init()之前不可以调用setState!!!
         */
        void setState();
        

        /*
         * [brief]  设置时间
         * 
         * [note]   还没写完。。。
         */
        void setTime(const char * t);

        /*
         * [brief]  验证通知栏状态
         * 
         * [note]   该函数不涉及显示，可随时调用
         * 
         * [in]     state - 欲验证的状态
         * 
         * [out]    真，state有效，否则无效
         */
        bool getState(int state);
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