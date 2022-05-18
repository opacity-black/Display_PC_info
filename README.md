# 简介

![超星网盘](https://p.ananas.chaoxing.com/star3/origin/8181a01e401836666e60fd54dd527ecd.png)
图片地址：https://p.ananas.chaoxing.com/star3/origin/8181a01e401836666e60fd54dd527ecd.png

主要是基于Arduino移植LVGL到ESP32，做了一个显示实时信息的界面（cpu、gpu、ram、网速什么的）
有空把各种传感器驱动代码做一下

电脑上要在插入串口前运行test/SerialServer.py，tft屏幕才会正确显示


# 开发环境
platformio + esp32-cam

lvgl版本: "8.1.0"

## 硬件
240x320 tft屏幕  ILI9341

esp32-cam

## 接线

屏幕|ESP32
---|---
CS|GND
Reset|IO14
SDI(MOSI)|IO16
SCK|IO2
LED|3V3
SDO(MISO)|悬空

