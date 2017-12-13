#include <adc2.h>

void setup() {
  Serial.begin(115200);
  Serial.println("adc22-test02");
  
  adc2::reset();  // is this necessary?  i doubt it, but make sure.  FIXME
  
  adc2::setClockPrescaler( adc2::Prescale_128 );
  adc2::setVoltageReference( adc2::Reference_1_1_v );
  adc2::startAutotrigger( adc2::ADC0 );
}

const int loopSize = 10;
void loop() {
  int sum=0;
  for ( int i=0; i<loopSize; i++)
  {
    delay(200);
    int adc = adc2::reread( );
    sum += adc;
    Serial.print(100.0* adc2volt(adc)); Serial.print("  ");
  }
  Serial.println("");
//  Serial.println( 100 * adc2volt( sum ) / loopSize );
}

float adc2volt( int adc )
{
  return ( (adc * 1.1) / 1024.0 );
}

