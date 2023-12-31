#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

/* Put your SSID & Password */
const char* ssid = "NodeMCU";  // Enter SSID here
const char* password = "12345678";  //Enter Password here

/* Put IP Address details */
IPAddress local_ip(192,168,2,1);
IPAddress gateway(192,168,2,1);
IPAddress subnet(255,255,255,0);

ESP8266WebServer server(80);

uint8_t LEDpin = D2;
bool DoorStatus = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(LEDpin, OUTPUT);

  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  delay(100);
  
  server.on("/", handle_OnConnect);
  server.on("/dooron", handle_ledon);
  server.on("/dooroff", handle_ledoff);
  server.onNotFound(handle_NotFound);

  server.begin();
  Serial.println("HTTP server started");
}
void loop() {
  server.handleClient();
  // if(DoorStatus)
  // digitalWrite(LEDpin, HIGH);
  // else
  // digitalWrite(LEDpin, LOW);
  if(DoorStatus){
    Serial.println("open");
    delay(1000);
  }
  else{
    Serial.println("closed");
    delay(1000);
  }
  
}

void handle_OnConnect() {
  DoorStatus = LOW;
  server.send(200, "text/html", SendHTML(false)); 
}

void handle_ledon() {
  DoorStatus = HIGH;
  server.send(200, "text/html", SendHTML(true)); 
}

void handle_ledoff() {
  DoorStatus = LOW;
  server.send(200, "text/html", SendHTML(false)); 
}

void handle_NotFound(){
  server.send(404, "text/plain", "Not found");
}

String SendHTML(uint8_t led){
  String ptr = "<!DOCTYPE html>\n";
  ptr +="<html>\n";
  ptr +="<head>\n";
  ptr +="<title>Door Control</title>\n";
  ptr +="</head>\n";
  ptr +="<body>\n";
  ptr +="<h1>Door</h1>\n";
  ptr +="<p>Click to switch Door on and off.</p>\n";
  ptr +="<form method=\"get\">\n";
  if(led)
  ptr +="<input type=\"button\" value=\"Door OFF\" onclick=\"window.location.href='/dooroff'\">\n";
  else
  ptr +="<input type=\"button\" value=\"Door ON\" onclick=\"window.location.href='/dooron'\">\n";
  ptr +="</form>\n";
  ptr +="</body>\n";
  ptr +="</html>\n";
  return ptr;
}

int openDoor(){
  int i = 11;
  return i;
}
int closeDoor(){
  int i = 00;
  return i;
}