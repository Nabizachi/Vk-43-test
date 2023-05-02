#include <Arduino.h>
#include <BH1750.h>
#include <Wire.h>
#include <IRremote.hpp>
#include <OneWire.h>
#include <DS18B20.h>

#define SW1 35
#define SW2 34
#define SW3 39

#define LEDS 33

#define Stepper_MA 26
#define Stepper_MB 27
#define Stepper_MC 14
#define Stepper_MD 12

#define Cold_temp_Relay 13
#define HOT_temp_Relay 4

#define SDA 21
#define SCL 22

#define IR_SENSOR_PIN 5

#define ONE_WIRE_BUS 25

OneWire oneWire(ONE_WIRE_BUS);
DS18B20 sensor(&oneWire);

BH1750 lightMeter(0x23);

void setup()
{
  Serial.begin(115200);

  IrReceiver.begin(IR_SENSOR_PIN, ENABLE_LED_FEEDBACK); // Start the receiver

  pinMode(SW1, INPUT);
  pinMode(SW2, INPUT);
  pinMode(SW3, INPUT);
  pinMode(LEDS, OUTPUT);
  pinMode(Stepper_MA, OUTPUT);
  pinMode(Stepper_MB, OUTPUT);
  pinMode(Stepper_MC, OUTPUT);
  pinMode(Stepper_MD, OUTPUT);
  pinMode(Cold_temp_Relay, OUTPUT);
  pinMode(HOT_temp_Relay, OUTPUT);

  Wire.begin(SDA, SCL);
  if (lightMeter.begin(BH1750::CONTINUOUS_HIGH_RES_MODE))
  {
    Serial.println(F("BH1750 Advanced begin"));
  }
  else
  {
    Serial.println(F("Error initialising BH1750"));
  }

  Serial.println(__FILE__);

  sensor.begin();
}

void loop()
{

  // ***--- STEPPER ---*** //

  /*
  digitalWrite(Stepper_MA, 1);
  digitalWrite(Stepper_MB, 0);
  digitalWrite(Stepper_MC, 0);
  digitalWrite(Stepper_MD, 1);
  delay(5);

  digitalWrite(Stepper_MA, 1);
  digitalWrite(Stepper_MB, 1);
  digitalWrite(Stepper_MC, 0);
  digitalWrite(Stepper_MD, 0);
  delay(5);

  digitalWrite(Stepper_MA, 0);
  digitalWrite(Stepper_MB, 1);
  digitalWrite(Stepper_MC, 1);
  digitalWrite(Stepper_MD, 0);
  delay(5);

  digitalWrite(Stepper_MA, 0);
  digitalWrite(Stepper_MB, 0);
  digitalWrite(Stepper_MC, 1);
  digitalWrite(Stepper_MD, 1);
  delay(5);
  */

  // ***--- COLD/HOT_Relay ---*** //

  /*
  digitalWrite(Cold_temp_Relay, 1);
  digitalWrite(HOT_temp_Relay, 1);
  delay(1000);
  digitalWrite(Cold_temp_Relay, 0);
  digitalWrite(HOT_temp_Relay, 0);
  delay(1000);
  */

  // ***--- SENSOR BUTTONS ---*** //

  Serial.print("SW1 =  ");
  Serial.println(digitalRead(SW1));
  Serial.print("SW2 =  ");
  Serial.println(digitalRead(SW2));
  Serial.print("SW3 =  ");
  Serial.println(digitalRead(SW3));
  delay(1000);

  // ***--- LEDS ---*** //

  /*
  for (int i = 0; i < 256; i++)
  {
    analogWrite(LEDS, i);
    delay(5);
  }
  */

  // ***--- LIGHT SENSOR ---*** //

  /*
  if (lightMeter.measurementReady())
  {
    float lux = lightMeter.readLightLevel();
    Serial.print("Light: ");
    Serial.print(lux);
    Serial.println(" lx");
  }
  delay(1000);
  */

  // ***--- IR SENSOR ---*** //

  /*
  if (IrReceiver.decode())
  {
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX); // Print "old" raw data
    IrReceiver.printIRResultShort(&Serial); // Print complete received data in one line
    IrReceiver.printIRSendUsage(&Serial);   // Print the statement required to send this data
    IrReceiver.resume();                    // Enable receiving of the next value
  }
  */

  // ***--- DS18B20 ---*** //

  // sensor.requestTemperatures();
  // Serial.println(sensor.getTempC());
  // delay(1000);
}
