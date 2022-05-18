from struct import pack
import serial
import json
import psutil
import time
from GPUtil import GPUtil

# 设置开机自启动：https://www.cnblogs.com/Gaohx/p/14870900.html

# 隐藏窗口
# import win32api, win32gui
# ct = win32api.GetConsoleTitle()
# hd = win32gui.FindWindow(0,ct)
# win32gui.ShowWindow(hd,0)

# 工作过程
# 等待连接 -> PC:json+"\n\r" -> 运行出错（拔出） -> 等待连接 -> ...

class Serial_obj:
    def __init__(self, port:str, interval_s=0.5) -> None:
        self.port = port
        self.working = False
        self.interval = interval_s      #数据发送间隔
        self.ser = serial.Serial(self.port, 115200, timeout=0.5)


    def waitConnect(self):
        print("等待连接",end=".")
        while 1:
            try:
                if not self.ser.is_open:
                    self.ser.open()
                # while 1:#检测开头词
                #     if self.ser.readline()==b"Hello\r\n":
                #         break
                #     # time.sleep(0.2)
                #     print(end=".")
                self.working = True
                break
            except serial.serialutil.SerialException:
                print(end=".")
                self.working = False
                time.sleep(0.5)
        print("")
        self.Send()


    def Send(self):
        print("已侦测到设备，数据正在发送中...")
        try:
            sent=0
            recv=0
            while self.working:
                sent_before = psutil.net_io_counters().bytes_sent  # 已发送的流量
                recv_before = psutil.net_io_counters().bytes_recv  # 已接收的流量
                packet = {
                    "T" : time.ctime(),
                    "CPU" : psutil.cpu_percent(),
                    "RAM" : psutil.virtual_memory().percent,
                    "GPU" : int(GPUtil.getGPUs()[0].memoryUtil*100),
                    "time": str(time.ctime()),
                    "Text": "up: "+ str(round(sent/self.interval,1))+
                            "KB/s\ndown: "+ str(round(recv/self.interval,1))+
                            "KB/s\n"
                }
                res = json.dumps(packet)+"\n\r"
                self.ser.write(res.encode())
                time.sleep(self.interval)

                sent_now = psutil.net_io_counters().bytes_sent
                recv_now = psutil.net_io_counters().bytes_recv
                sent = (sent_now - sent_before)/1024  # 算出差值
                recv = (recv_now - recv_before)/1024

        except serial.serialutil.SerialException:
            print("设备断开")
            self.ser.is_open = False
            self.working=False
            self.waitConnect()



if __name__=="__main__":
    s = Serial_obj("com5")
    s.waitConnect()
    # try:
    #     s = Serial_obj("com5")
    #     s.listen()
    # except:
    #     print("结束")
    #     s.End()