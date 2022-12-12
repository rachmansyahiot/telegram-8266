#include "CTBot.h"
CTBot myBot;
 
String ssid  = "ARMhome"; 
String pass  = "rahasia"; 
String token = "5640932958:AAE5xxr2dwB6GTNtvEEvNYVn4-rezaxMyv0";
 
const int lampu1 = 4;   //D2                     
const int lampu2 = 5;   //D1

void setup() {
  // initialize the Serial
  Serial.begin(115200);
  Serial.println("Starting TelegramBot...");
 
  // connect the ESP8266 to the desired access point
  myBot.wifiConnect(ssid, pass);
 
  // set the telegram bot token
  myBot.setTelegramToken(token);
 
  // check if all things are ok
  if (myBot.testConnection())
    Serial.println("\ntestConnection OK");
  else
    Serial.println("\ntestConnection NOK");
 
  // set the pin connected to the LED to act as output pin
  pinMode(lampu1, OUTPUT);
  pinMode(lampu2, OUTPUT);
  digitalWrite(lampu1, HIGH); 
  digitalWrite(lampu2, HIGH); 
 
}
 
void loop() {
     
  // a variable to store telegram message data
  TBMessage msg;
 
  // if there is an incoming message...
  if (myBot.getNewMessage(msg)) {
    if (msg.text.equalsIgnoreCase("1 On")) {                   
      digitalWrite(lampu1, LOW);                              
      myBot.sendMessage(msg.sender.id, "Lampu 1 ON"); 
    }
    else if (msg.text.equalsIgnoreCase("1 Off")) {              
      digitalWrite(lampu1, HIGH);                              
      myBot.sendMessage(msg.sender.id, "Lampu 1 OFF"); 
    }
    else if (msg.text.equalsIgnoreCase("2 On")) {              
      digitalWrite(lampu2, LOW);                              
      myBot.sendMessage(msg.sender.id, "Lampu 2 ON"); 
    }
    else if (msg.text.equalsIgnoreCase("2 Off")) {              
      digitalWrite(lampu2, HIGH);                              
      myBot.sendMessage(msg.sender.id, "Lampu 2 OFF"); 
    }
    else {                                                    
      // generate the message for the sender
      String reply;
      reply = (String)"Selamat datang";
      myBot.sendMessage(msg.sender.id, reply);             
    }
   
  }
  // wait 500 milliseconds
  delay(500);
}
