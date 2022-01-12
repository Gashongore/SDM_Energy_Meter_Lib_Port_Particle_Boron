/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/Users/gashongore/Desktop/Port_Particle/SDM630_Particle/src/SDM630_Particle.ino"
/*
 * Project SDM630_Particle
 * Description:
 * Author: Prince GASHONGORE
 * Date: 2022/01/13
 */

void setup();
void loop();
#line 8 "/Users/gashongore/Desktop/Port_Particle/SDM630_Particle/src/SDM630_Particle.ino"
#define READSDMEVERY  2000                           //read sdm every 2000ms
#define NBREG   5 

#include "SDM630_Boron.h"
 
SDM sdm(SDM_UART_BAUD,DERE_PIN, SERIAL_8N1); // 
// setup() runs once, when the device is first turned on.
void setup() {

 Serial.begin(9600);
  // Put initialization like pinMode and begin functions here.
sdm.begin(); 
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // The core of your code will likely live here.


  char bufout[10];
  sprintf(bufout, "%c[1;0H", 27);
  Serial.print(bufout);

  Serial.print("Voltage:   ");
  Serial.print(sdm.readVal(SDM_PHASE_1_VOLTAGE), 2);                            //display voltage
  Serial.println("V");

  Serial.print("Current:   ");
  Serial.print(sdm.readVal(SDM_PHASE_1_CURRENT), 2);                            //display current
  Serial.println("A");

  Serial.print("Power:     ");
  Serial.print(sdm.readVal(SDM_PHASE_1_POWER), 2);                              //display power
  Serial.println("W");

  Serial.print("Frequency: ");
  Serial.print(sdm.readVal(SDM_FREQUENCY), 2);                                  //display frequency
  Serial.println("Hz");

  delay(1000);                                                                  //wait a while before next loop

}