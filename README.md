[TOC]

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


# 简介
主要是基于Arduino移植LVGL到ESP32，做了一个显示实时信息的界面
有空把各种传感器驱动代码做一下

电脑上要在插入设备前运行test/SerialServer.py才会有显示