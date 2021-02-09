/*
使用ESP8266 进行建站 仅仅理论证明可信 实测可承受3个客户端同时访问 在20秒内全部加载完毕

本项目是娱乐为主，其目的仅仅为实验性证明

该项目包含网站中绝大部分请求内容

为增加可读性 将所有请求函数独立出来

本项目需要 wifi_link_tool库 



*/

#define FS_CONFIG
//激活文件系统模式配网
#include <wifi_link_tool.h>
//引入wifilinktool头文件
void setup() {
  Serial.begin(115200);
  //开启串口
   rstb = 0;
  //重置io
  stateled = 2;
  //指示灯io
  Hostname = "ESP_WWW";
  //设备名称 允许中文名称 不建议太长
  wxscan = true;
  //是否被小程序发现设备 开启意味该设备具有后台 true开启 false关闭
  load();

  webServer.on("/favicon.ico", favicon);
  //加载网站图标
  
  webServer.on("/wzxq", wzxq);
  webServer.on("/jui", jui);
  webServer.on("/bui", bui);
  //文字星球网页及请求部分
  webServer.on("/sj", yxsj);
  //运行时长
  webServer.on("/index/css/bootstrap.css", bootstrap);
  webServer.on("/index/css/font-awesome.min.css", font);
  webServer.on("/index/css/owl-carousel.css", owl_c);
  webServer.on("/index/css/style.css", style);
  //所有css资源
  webServer.on("/index/js/jquery-3.3.1.min.js", jquery);
  webServer.on("/index/js/modernizr.min.js", modernizr);
  webServer.on("/index/js/owl.carousel.js", owl);
  //所有javascript资源
  webServer.on("/index/zp.jpg", zp);
  webServer.on("/index/project/blblframe.jpg", blblframe);
  webServer.on("/index/project/Eastereggs.jpg", Eastereggs);
  webServer.on("/index/project/ESP_VFD_Clock.jpg", ESP_VFD_Clock);
  webServer.on("/index/project/ESP_weather_Cube.jpg", ESP_weather_Cube);
  webServer.on("/index/project/nzcd.jpg", nzcd);
  webServer.on("/index/project/rpi_mt.jpg", rpi_mt);
  webServer.on("/index/project/ROG_fan.jpg", ROG_fan);
  webServer.on("/index/project/wifi_link_tool.jpg", wifi_link_tool);
  //所有图片资源
}

// 加载资源函数部分 
void favicon() {
  digitalWrite(stateled, LOW);
  File file = SPIFFS.open("/favicon.ico", "r");
  webServer.streamFile(file, "image/vnd.microsoft.icon");
  file.close();
  digitalWrite(stateled, HIGH);
}

void wzxq() {
  digitalWrite(stateled, LOW);
  File file = SPIFFS.open("/wzxq.html", "r");
  webServer.streamFile(file, "text/html");
  file.close();
  digitalWrite(stateled, HIGH);
}
void jui() {
  digitalWrite(stateled, LOW);
  File file = SPIFFS.open("/wz.txt", "r");
  if (file) webServer.send(200, "text/plain", file.readString());
  file.close();
  digitalWrite(stateled, HIGH);
}
void bui() {
  digitalWrite(stateled, LOW);
  if (webServer.arg("get") != "")
  {
    File file = SPIFFS.open("/wz.txt", "a+");
    file.print(webServer.arg("get")+",");
    file.close();
    webServer.send(200, "text/plain", "ojbk");
  }
  digitalWrite(stateled, HIGH);
}
void yxsj() {
  digitalWrite(stateled, LOW);
  File file = SPIFFS.open("/sj.html", "r");
  webServer.streamFile(file, "text/html");
  file.close();
  digitalWrite(stateled, HIGH);
}
void bootstrap() {
  digitalWrite(stateled, LOW);
  File file = SPIFFS.open("/css/bootstrap.css", "r");
  webServer.streamFile(file, "text/css");
  file.close();
  digitalWrite(stateled, HIGH);
}
void font() {
  digitalWrite(stateled, LOW);
  File file = SPIFFS.open("/css/font-awesome.min.css", "r");
  webServer.streamFile(file, "text/css");
  file.close();
  digitalWrite(stateled, HIGH);
}
void owl_c() {
  digitalWrite(stateled, LOW);
  File file = SPIFFS.open("/css/owl-carousel.css", "r");
  webServer.streamFile(file, "text/css");
  file.close();
  digitalWrite(stateled, HIGH);
}
void style() {
  digitalWrite(stateled, LOW);
  File file = SPIFFS.open("/css/style.css", "r");
  webServer.streamFile(file, "text/css");
  file.close();
  digitalWrite(stateled, HIGH);
}
void jquery() {
  digitalWrite(stateled, LOW);
  File file = SPIFFS.open("/js/jquery-3.3.1.min.js", "r");
  webServer.streamFile(file, "application/javascript");
  file.close();
  digitalWrite(stateled, HIGH);
}
void modernizr() {
  digitalWrite(stateled, LOW);
  File file = SPIFFS.open("/modernizr.js", "r");
  webServer.streamFile(file, "application/javascript");
  file.close();
  digitalWrite(stateled, HIGH);
}
void owl() {
  digitalWrite(stateled, LOW);
  File file = SPIFFS.open("/js/owl.carousel.js", "r");
  webServer.streamFile(file, "application/javascript");
  file.close();
  digitalWrite(stateled, HIGH);
}

void zp() {
  digitalWrite(stateled, LOW);
  File file = SPIFFS.open("/zp.jpg", "r");
  webServer.streamFile(file, "aimage/jpeg");
  file.close();
  digitalWrite(stateled, HIGH);
}

void blblframe() {
  digitalWrite(stateled, LOW);
  File file = SPIFFS.open("/blblframe.jpg", "r");
  webServer.streamFile(file, "aimage/jpeg");
  file.close();
  digitalWrite(stateled, HIGH);
}
void Eastereggs() {
  digitalWrite(stateled, LOW);
  File file = SPIFFS.open("/Eastereggs.jpg", "r");
  webServer.streamFile(file, "aimage/jpeg");
  file.close();
  digitalWrite(stateled, HIGH);
}
void ESP_VFD_Clock() {
  digitalWrite(stateled, LOW);
  File file = SPIFFS.open("/ESP_VFD_Clock.jpg", "r");
  webServer.streamFile(file, "aimage/jpeg");
  file.close();
  digitalWrite(stateled, HIGH);
}
void ESP_weather_Cube() {
  digitalWrite(stateled, LOW);
  File file = SPIFFS.open("/ESP_weather_Cube.jpg", "r");
  webServer.streamFile(file, "aimage/jpeg");
  file.close();
  digitalWrite(stateled, HIGH);
}
void nzcd() {

  digitalWrite(stateled, LOW);
  File file = SPIFFS.open("/nzcd.jpg", "r");
  webServer.streamFile(file, "aimage/jpeg");
  file.close();
  digitalWrite(stateled, HIGH);
}
void ROG_fan() {
  digitalWrite(stateled, LOW);
  File file = SPIFFS.open("/ROG_fan.jpg", "r");
  webServer.streamFile(file, "aimage/jpeg");
  file.close();
  digitalWrite(stateled, HIGH);
}
void rpi_mt() {
  digitalWrite(stateled, LOW);
  File file = SPIFFS.open("/rpi_mt.jpg", "r");
  webServer.streamFile(file, "aimage/jpeg");
  file.close();
  digitalWrite(stateled, HIGH);
}
void wifi_link_tool() {
  digitalWrite(stateled, LOW);
  File file = SPIFFS.open("/wifi_link_tool.jpg", "r");
  webServer.streamFile(file, "aimage/jpeg");
  file.close();
  digitalWrite(stateled, HIGH);
}


void loop() 
{
  pant();
}
