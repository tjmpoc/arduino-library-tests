#include <adc2.h>
#include <debugprint.h>

void setup() {
int val;
  Serial.begin(115200);
  Serial.println("adc22-test01");
  debugPrint_AnalogToDigitalConverter();

  delay(1000);
  Serial.println("synchronous V_1_1");
  adc2::readSynchronous( adc2::V_1_1 );
  debugPrint_AnalogToDigitalConverter();

  delay(1000);
  Serial.println("autotrigger temperature");
  adc2::startAutotrigger( adc2::Temperature_sensor );
  debugPrint_AnalogToDigitalConverter();

  delay(1000);
  Serial.println("reread");
  adc2::reread();
  debugPrint_AnalogToDigitalConverter();

  delay(1000);
  Serial.println("reset");
  adc2::reset();
  debugPrint_AnalogToDigitalConverter();
}

void loop() {
}
