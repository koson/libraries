/*

ArdSim Library Output demonstration
LED outputs controlled with dataref depending on specific value ranges

Download ArdSim Library on the site.

  by Vlad Sychev 2015
http://arduino.svglobe.com
 */

#include <SPI.h>         
#include <Ethernet.h>
#include <ArdSim.h>         // -- include ArdSim library
//----------------// MAC-Address of Arduino Ethernet shield:
#define MAC_ADR   0xDE,0xAD,0xBE,0xEF,0xFE,0xED

//----------------------------------------------
//---- Define Arduino board type and number (optional for single Arduino MEGA board): 

#define BOARD_TYPE   MEGA, 1  //MEGA, UNO, MINI, NANO,  numbers 1..9  

  // define 4 LED connections ( first number - Arduino pin, second is dataref number

  
#define  Flaps_0  5, 6          //LED on pin #5 
#define  Flaps_1  6, 6        //LED on pin #6 
#define  Flaps_2  7, 6        //LED on pin #7 
#define  Flaps_3  8, 6           //LED on pin #8 



//---------------------
void setup()  { 
 
   ArdSimStart;  
  
AnalogIn(0, 4);     // Flaps Lever

}
//--------------------------
void loop()  { 

ArdSimScan; 

      
       // LEDs, two last numbers define dataref value range between which LED is ON
       
   LEDout(Flaps_0, 0, 0.2);    
   LEDout(Flaps_1, 0.3, 0.5);    
   LEDout(Flaps_2, 0.6, 0.9); 
   LEDout(Flaps_3, 0.9, 1);    


} 

//--- End -------------------

/* output config file out_1.cfg

For this example you should have this  dataref in the 6th line number:

===================================
1 ... 
2 ...
3 ...
4 ...
5 ...
6  2  sim/flightmodel2/controls/flap_handle_deploy_ratio
7
===================================

You should see:
1. LED on pin #5 will light up when the flaps position is 0..0.3
2. LED on pin #6 will light up when the flaps position is 0.3...0.6 
3. LED on pin #7 will light up when the flaps position is 0.6...0.9 
4. LED on pin #8 will light up when the flaps position is 0.9...1.0


*/




