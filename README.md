# myArduino
My trails on Arduino here.
### temp_humi_CloudeData.ino是esp8266+DHT11温湿度计接入小爱同学的温湿度计示例程序，可以支持云存储，在点灯科技app端查看历史数据.
### 20200227 jidianqi_Light.ino 是利用继电器结合esp8266WIFI+小爱同学实现语音控制开关等的示例程序，未完成在点灯科技app界面实现更改开关的状态（刷新）。
### 20200228 jidianqi_Light.ino程序已完成手机控制端与开关状态的同步（即按下开关后，开关下自动更变为“已开启”或“已关闭”），但有时候使用小爱同学语音控制还不能百分百保证与手机端开光状态的同步。

### 20200303 jidianqi_Light.ino 程序在正常烧入芯片上电工作时，实际出现的问题时，继电器迅速吸合并断开，现象是灯泡迅速点亮然后熄灭。经查找资料后得到的解答见：[关于ESP8266上电时IO口抖动的问题](https://blog.csdn.net/qq_39161804/article/details/104638443)
