#define BLINKER_WIFI
#define BLINKER_MIOT_OUTLET   //小爱同学

#include <Blinker.h>

char auth[] = "2f1a33e91e8b";
char ssid[] = "CMCC-WnWH";
char pswd[] = "7awwwhza";

#define LED 0    //0对应GPIO0  2对应GPIO2
 
bool oState = false;
 
BlinkerButton Button1("btn-abc");
 
//按下按键即会执行该函数
void button1_callback(const String & state) {
  digitalWrite(LED, !digitalRead(LED));
  BLINKER_LOG("get button state: ", state);
  Button1.print(state);
  if (state == BLINKER_CMD_ON) 
  {
    Button1.text("已开启");
    Button1.print("on");
  }
  else if (state == BLINKER_CMD_OFF) 
  {
    Button1.text("已关闭");
    Button1.print("off");
  }
}
 
void miotPowerState(const String & state)
{
  BLINKER_LOG("need set power state: ", state);
 
  if (state == BLINKER_CMD_ON) {
    digitalWrite(LED, LOW);
    BlinkerMIOT.powerState("on");   
    BlinkerMIOT.print();    
    oState = true;
  } else if (state == BLINKER_CMD_OFF) {
    digitalWrite(LED, HIGH);
    BlinkerMIOT.powerState("off");  
    BlinkerMIOT.print();    
    oState = false;
  }
}
 
void miotQuery(int32_t queryCode)
{
  BLINKER_LOG("MIOT Query codes: ", queryCode);
 
  switch (queryCode)
  {
    case BLINKER_CMD_QUERY_ALL_NUMBER :
      BLINKER_LOG("MIOT Query All");
      BlinkerMIOT.powerState(oState ? "on" : "off");
      BlinkerMIOT.print();
      break;
    case BLINKER_CMD_QUERY_POWERSTATE_NUMBER :
      BLINKER_LOG("MIOT Query Power State");
      BlinkerMIOT.powerState(oState ? "on" : "off");
      BlinkerMIOT.print();
      break;
    default :
      BlinkerMIOT.powerState(oState ? "on" : "off");
      BlinkerMIOT.print();
      break;
  }
}
 
void dataRead(const String & data)
{
  BLINKER_LOG("Blinker readString: ", data);
  Blinker.vibrate();
  uint32_t BlinkerTime = millis();
  Blinker.print("millis", BlinkerTime);
}
 
void setup()
{
  Serial.begin(115200);
  BLINKER_DEBUG.stream(Serial);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);
  Blinker.begin(auth, ssid, pswd);
  Blinker.attachData(dataRead);
  Button1.attach(button1_callback);
  BlinkerMIOT.attachPowerState(miotPowerState);
  BlinkerMIOT.attachQuery(miotQuery);
}
 
void loop()
{
  Blinker.run();
}
