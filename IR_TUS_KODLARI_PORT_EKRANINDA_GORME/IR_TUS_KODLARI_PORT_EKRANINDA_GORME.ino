#include <IRremote.h>

int kumandaPin = 2;
IRrecv kumanda(kumandaPin);
decode_results sonuclar;

void setup()
{
  kumanda.enableIRIn();
  Serial.begin(9600);
}
 
void loop()
{
  if(kumanda.decode(&sonuclar))
  {
    Serial.print("Tuş kodu: ");
    Serial.println(sonuclar.value, HEX); //HEX,DEC,BIN
    kumanda.resume();
  }

  delay(100);
}
