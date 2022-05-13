//lvgl初始化
#include <TFT_eSPI.h>
#include "GUI/lv_basic.h"


static TFT_eSPI tft = TFT_eSPI(screenWidth, screenHeight); /* TFT instance */

static lv_disp_draw_buf_t draw_buf;

#define buf_size screenWidth*10
static lv_color_t buf[ buf_size ];

static lv_disp_drv_t disp_drv;        /*Descriptor of a display driver*/


#if LV_USE_LOG != 0
/* Serial debugging */
void my_print(const char * buf)
{
    Serial.printf(buf, strlen(buf));
}
#endif


/* Display flushing */
void my_disp_flush(lv_disp_drv_t * disp, const lv_area_t * area, lv_color_t * color_p)
{
    uint32_t w = ( area->x2 - area->x1 + 1 );
    uint32_t h = ( area->y2 - area->y1 + 1 );

    tft.startWrite();
    tft.setAddrWindow( area->x1, area->y1, w, h );
    tft.pushColors( ( uint16_t * )&color_p->full, w * h, true );
    tft.endWrite();

    lv_disp_flush_ready( disp );
}


 
void my_init_lvgl()
{
  lv_init();

#if LV_USE_LOG != 0
    lv_log_register_print_cb( my_print ); /* register print function for debugging */
#endif

  tft.begin();          /* TFT init */
  tft.setRotation( 1 );

  lv_disp_draw_buf_init( &draw_buf, buf, NULL, buf_size );

  lv_disp_drv_init(&disp_drv);          /*Basic initialization*/
  disp_drv.hor_res =  screenWidth;
  disp_drv.ver_res =  screenHeight;
  disp_drv.flush_cb = my_disp_flush;    /*Set your driver function*/
  disp_drv.draw_buf = &draw_buf;        /*Assign the buffer to the display*/
  lv_disp_drv_register(&disp_drv);      /*Finally register the driver*/

//   lv_indev_drv_init(&indev_drv);      /*Basic initialization*/
//   indev_drv.type = LV_INDEV_TYPE_BUTTON;                 /*See below.*/
//   indev_drv.read_cb = button_read;              /*See below.*/
//     /*Register the driver in LVGL and save the created input device object*/
//   lv_indev_t * my_indev = lv_indev_drv_register(&indev_drv);

//   lv_indev_set_button_points(my_indev, points_array);

  //创建样式
  createLvStyle();

}

