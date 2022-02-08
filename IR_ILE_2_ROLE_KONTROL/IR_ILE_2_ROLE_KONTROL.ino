//IR kumanda İle Lamba Kontrolü
#include <IRremote.h>
int role1 = 8;
int role2 = 9;
int kumandaPin = 2;
IRrecv kumanda(kumandaPin);
decode_results sonuclar;

void setup()
{
  kumanda.enableIRIn();
  Serial.begin(9600);
   pinMode(role1,OUTPUT);
   pinMode(role2,OUTPUT);
}

void loop()
{
  if(kumanda.decode(&sonuclar))
  {
    Serial.print("Tuş kodu: ");
    Serial.println(sonuclar.value, DEC); //HEX,DEC,BIN
    kumanda.resume();
  }

  delay(100);
  if(sonuclar.value == 2993){
    digitalWrite(role1,HIGH);
    }
   if(sonuclar.value == 946){
    digitalWrite(role1,LOW);
    }
   if(sonuclar.value == 2962){
    digitalWrite(role2,HIGH);
    }
   if(sonuclar.value == 942){
    digitalWrite(role2,LOW);
   }
   if(sonuclar.value == 2954){
    digitalWrite(role2,HIGH);
    digitalWrite(role1,HIGH);
   }
   if(sonuclar.value == 941){
    digitalWrite(role2,LOW);
    digitalWrite(role1,LOW);
   }
    if(sonuclar.value == 2961){
    digitalWrite(role2,HIGH);
    digitalWrite(role1,HIGH);
   }
   if(sonuclar.value == 913){
    digitalWrite(role2,LOW);
    digitalWrite(role1,LOW);
   }
}
//byFat1h
