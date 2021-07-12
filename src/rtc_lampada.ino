/*
AUTOR : NATHALIA NASCIMENTO
DATA: 24/01/2019
DESCRIÇÃO: CODIGO PARA ACIONAMENTO DE UMA LAMPADA A PARTIR DO INPUT DE UM SENSOR DE PRESENÇA
*/


//This my commit
//corrected
#include <RTClib.h>

#define rele 5
int sensor = 7;

RTC_DS1307 rtc;


void setup() {
  Serial.begin(9600);
  pinMode(rele,OUTPUT);
  pinMode(sensor,INPUT);

 if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1){
      Serial.print(" .");
    }
  }
rtc.adjust(DateTime(F(__DATE__), F(__TIME__))); 

  if (! rtc.isrunning()){
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__))); 
   } 
digitalWrite(rele,HIGH);
delay(1000);
}

void loop() {
  DateTime now = rtc.now();
  int Leitura_sensor = digitalRead(sensor);
  Serial.print(now.hour(),DEC);
  Serial.print(":");
  Serial.print(now.minute(),DEC);
  Serial.print(":");
  Serial.print(now.second(),DEC);
  Serial.println();
 if(now.hour()>=20 && now.hour()<5){        //RELE ATIVADO A PARTIR DE 20H ATE AS 5H
      Serial.println("RELE ON");
      if(Leitura_sensor == HIGH){
        digitalWrite(rele,LOW);
      }else{
        digitalWrite(rele,HIGH);
    }
 }else{
  digitalWrite(rele,HIGH);
  }
}


/*if(now.hour()== 18 && now.minute()==0 && now.second()==0){
  if(Leitura_sensor == HIGH){
    digitalWrite(rele,HIGH);
  }else{
    digitalWrite(rele,LOW);
    }
  }else if (now.hour()== 5 && now.minute()==0 && now.second()==0){
    Serial.println("SLEEP MODE");
  }
}*/
