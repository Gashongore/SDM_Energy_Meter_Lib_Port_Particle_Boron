
//REMEMBER! uncomment #define USE_HARDWARESERIAL
//in SDM_Config_User.h file if you want to use hardware uart
#include <SDM.h>                                                                //import SDM library
                                                                      //for AVR
SDM sdm(SDM_UART_BAUD, NOT_A_PIN,SDM_UART_CONFIG);                                              //config SDM on Serial1 (if available!)                                                                         //for SWSERIAL

void setup() {
  Serial.begin(9600);   /* this is another serial, avoid using the same serial     */  //initialize other serial, 
  sdm.begin();                                                                  //initialize SDM communication
}

void loop() {
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
