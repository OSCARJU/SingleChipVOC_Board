#include <EEPROM.h>
#include <Nextion.h>  // Include the nextion library (the official one) https://github.com/itead/ITEADLIB_Arduino_Nextion
                      // Make sure you edit the NexConfig.h file on the library folder to set the correct Serial port for the display.
                      // By default it's set to Serial1, which most arduino boards don't have.
                      // Change "#define nexSerial Serial1" to "#define nexSerial Serial" if you are using arduino uno, nano, etc.
int start = 0;
int CurrentPage = 0;  // Create a variable to store which page is currently loaded
//Voltage Variable
int     SensorPin = A0; // port number of analogic input

int   Voltage;        // Voltage Value
float   percent;        // Percent from 0~100 % of voltage.
//trigger
int TriggerPin  = A1;

int VoltageR;
//TIMER Relay transition D8_D9
int  timerC2=0;       
//Initiation of timers
boolean tim1  = false;
boolean tim2  = false;
boolean tim3  = false;
boolean tim4  = false;
boolean tim5  = false;
boolean tim6  = false;
boolean tims  = false;
boolean timf  = false;
boolean timp  = false;

boolean timPage0  = false;

//Time Variables
unsigned long tNow       = 0;
unsigned long tNow1      = 0;
unsigned long tNow2      = 0;
unsigned long tNow3      = 0;
unsigned long tNow4      = 0;
unsigned long tNow5      = 0; 
unsigned long tNows      = 0;
unsigned long tNowf      = 0;
unsigned long tNowp      = 0;
unsigned long tNowPage4     = 0;

//Time Variables
unsigned long tNowt1      = 0;
unsigned long tNowt2      = 0;
unsigned long tNowt3      = 0;
unsigned long tNowt4      = 0;
unsigned long tNowt5      = 0;
unsigned long tNowts      = 0;
unsigned long tNowtf      = 0;
unsigned long tNowtp      = 0;
unsigned long tNowtPage4      = 0;
unsigned long tNextion      = 0;

//Status Alert
boolean flag1 = false;
boolean flag2 = false;
boolean flag3 = false;
boolean flag4 = false;
boolean flag5 = false;
boolean flagf = false;
boolean flags = false;

boolean flag86 = false; 
boolean flagp = false;
boolean flagp1 = false;
boolean flagp2 = false;
boolean flagp3 = false;
boolean flagEND = false;

boolean flagPage5 = false;

//Digital Output Relay
int D1  = 12;
int D2  = 11;
int D3  = 10;
int D4  = 9;
int D5  = 8;
int D6  = 7;
int D7  = 6;
int D8  = 5;
int D9  = 4;
int D10 = 3;

///////////////////////////
int r1 = 0 ;
int r2 = 0 ;
int r3 = 0 ;
int r4 = 0 ;
int r5 = 0 ;
int r6 = 0 ;
int r7 = 0 ;
int r8 = 0 ;
int r9 = 0 ;
int r10 = 0 ;

/////////Page 1
NexButton b13 = NexButton(1, 9, "b3");  // Button added Timer 1 - 
NexButton b14 = NexButton(1, 10, "b4");  // Button added Timer 1 +
NexButton b15 = NexButton(1, 11, "b5");  // Button added Timer 2 - 
NexButton b16 = NexButton(1, 12, "b6");  // Button added Timer 2 +
NexButton b17 = NexButton(1, 13, "b7");  // Button added Timer 3 - 
NexButton b18 = NexButton(1, 14, "b8");  // Button added Timer 3 +
NexButton b19 = NexButton(1, 15, "b9");  // Button added Timer 4 - 
NexButton b110 = NexButton(1, 16, "b10");  // Button added Timer 4 +
NexButton b111 = NexButton(1, 17, "b11");  // Button added Timer 5 -
NexButton b112 = NexButton(1, 18, "b12");  // Button added Timer 5 + 
NexButton b113 = NexButton(1, 19, "b13");  // Button added Timer 6 -
NexButton b114 = NexButton(1, 20, "b14");  // Button added Timer 6 + 
//NexButton b12 = NexButton(1, 3, "b2");  // Button added save 

///////////Page 2
NexButton b23 = NexButton(2, 6, "b3");  // Button added Release  - 
NexButton b24 = NexButton(2, 7, "b4");  // Button added Release  +
NexButton b25 = NexButton(2, 8, "b5");  // Button added Compensate  - 
NexButton b26 = NexButton(2, 9, "b6");  // Button added Compensate  +
NexButton b27 = NexButton(2, 10, "b7");  // Button added Lower limit  - 
NexButton b28 = NexButton(2, 11, "b8");  // Button added Lower limit +
NexButton b29 = NexButton(2, 14, "b9");  // Button added Lower limit  - 
NexButton b210 = NexButton(2, 15, "b10");  // Button added Lower limit +
NexButton b22 = NexButton(2, 12, "b2");  // Button added Save
//NexButton b20 = NexButton(2, 1, "b0");  // Button added start

///////////Page 3

NexButton b33 = NexButton(3, 33, "b3");  // Button added start


///////////////////////
NexPage page0 = NexPage(0, 0, "page0");  // Page added as a touch event
NexPage page1 = NexPage(1, 0, "page1");  // Page added as a touch event
NexPage page2 = NexPage(2, 0, "page2");  // Page added as a touch event
NexPage page3 = NexPage(3, 0, "page3");  // Page added as a touch event
NexPage page4 = NexPage(4, 0, "page4");  // Page added as a touch event
NexPage page5 = NexPage(5, 0, "page5");  // Page added as a touch event


/////////////////////page 5
NexButton b53 = NexButton(5, 5, "b3");  // Button turn on D1
NexButton b54 = NexButton(5, 6, "b4");  // Button turn off D1 
NexButton b55 = NexButton(5, 7, "b5");  // Button turn on D2
NexButton b56 = NexButton(5, 8, "b6");  // Button turn off D2 
NexButton b57 = NexButton(5, 9, "b7");  // Button turn on D3
NexButton b58 = NexButton(5, 10, "b8");  // Button turn off D3 
NexButton b59 = NexButton(5, 11, "b9");  // Button turn on D4
NexButton b510 = NexButton(5, 12, "b10");  // Button turn off D4 
NexButton b511 = NexButton(5, 13, "b11");  // Button turn on D5
NexButton b512 = NexButton(5, 14, "b12");  // Button turn off D5
NexButton b513 = NexButton(5, 15, "b13");  // Button turn on D6
NexButton b514 = NexButton(5, 16, "b14");  // Button turn off D6 
NexButton b515 = NexButton(5, 17, "b15");  // Button turn on D7 
NexButton b516 = NexButton(5, 18, "b16");  // Button turn off D7 
NexButton b517 = NexButton(5, 19, "b17");  // Button turn on D8
NexButton b518 = NexButton(5, 20, "b18");  // Button turn off D8 
NexButton b519 = NexButton(5, 21, "b19");  // Button turn on D9
NexButton b520 = NexButton(5, 22, "b20");  // Button turn off D9 
NexButton b521 = NexButton(5, 23, "b21");  // Button turn on D10 
NexButton b522 = NexButton(5, 24, "b22");  // Button turn off D10
NexButton b523 = NexButton(5, 28, "b23");  // Button turn off D9 
NexButton b524 = NexButton(5, 29, "b24");  // Button turn on D10 
//NexButton b525 = NexButton(5, 31, "b25");  // Button turn off D10



// End of declaring objects

char buffer[100] = {0};  // This is needed only if you are going to receive a text from the display. You can remove it otherwise.
                         // Further on this sketch I do receive text so that's why I created this buffer.

// Declare touch event objects to the touch event list: 
// You just need to add the names of the objects that send a touch event.
// Format: &<object name>,

NexTouch *nex_listen_list[] = 
{
  ///////page1
    &b13, 
    &b14,
    &b15,  
    &b16,  
    &b17, 
    &b18, 
    &b19, 
    &b110, 
    &b111, 
    &b112, 
    &b113, 
    &b114,  
    //&b12 ,

///////////Page 2
    &b23 ,
    &b24, 
    &b25, 
    &b26, 
     &b27,
    &b28,
     &b29,
    &b210, 
    &b22,  
    //&b20, 

 ////////////////////page 3
      &b33,

///////////Page 4


    /////////////////////////////////////////
    &page0, 
    &page1, 
    &page2, 
    &page3, 
    &page4, 
    &page5, 
      ////////// page 5
      &b53,
      &b54,
      &b55,
      &b56,
      &b57,
      &b58,
      &b59,
      &b510,
      &b511,
      &b512,
      &b513,
      &b514,
      &b515,
      &b516,
      &b517,
      &b518,
      &b519,
      &b520,
      &b521,
      &b522,
      &b523,
      &b524,
      //&b525,
      

    /////
  NULL  // String terminated
};  // End of touch event list
////////////////////////// Touch events:
// Each of the following sections are going to run everytime the touch event happens:
// Is going to run the code inside each section only ones for each touch event.

////////////////////////Memory
//Memory Variables
struct MYDATA{
    int initialized;
    int M_T1;
    int M_T2;
    int M_T3;
    int M_T4;
    int M_T5;
    int M_T6;
    int M_R;
    int M_C;
    int M_L;
    int M_Sensor;
    int M_Cal;
    
};
union MEMORY{
   MYDATA d;
   byte b[sizeof(MYDATA)];
}
memory;
////////////////////////////////
/////////////////////////////Void memory
void readConfiguration()
{
    for( int i=0 ; i < sizeof(memory.d) ; i++  )
        memory.b[i] = EEPROM.read(i);

    if( !memory.d.initialized )
    {
        memory.d.initialized = true;
        memory.d.M_T1     = 0;
        memory.d.M_T2     = 0;
        memory.d.M_T3     = 0;
        memory.d.M_T4     = 0;
        memory.d.M_T5     = 0;
        memory.d.M_T6     = 0;
        memory.d.M_Sensor     = 0;
        memory.d.M_R     = 0;
        memory.d.M_C     = 0;
        memory.d.M_L     = 0;  
        memory.d.M_Cal   =0;
        
    } 
}

void writeConfiguration()
{
    for( int i=0 ; i<sizeof(memory.d) ; i++  )
        EEPROM.write( i, memory.b[i] );
}
/////////////////////////////////////
void b53PushCallback(void *ptr)  // Press event for D1
{
   // Turn ON internal LED
    digitalWrite(D1, HIGH);
  
}  // End of press event

void b54PushCallback(void *ptr)  // Release event for D1
{
   // Turn OFF internal LED
  
  digitalWrite(D1, LOW);
}  // End of release event

void b55PushCallback(void *ptr)  // Press event for D2
{
   // Turn ON internal LED
    digitalWrite(D2, HIGH);
  
}  // End of press event

void b56PushCallback(void *ptr)  // Release event for D2
{
   // Turn OFF internal LED
  
  digitalWrite(D2, LOW);
}  // End of release event

void b57PushCallback(void *ptr)  // Press event for D3
{
   // Turn ON internal LED
    digitalWrite(D3, HIGH);
  
}  // End of press event

void b58PushCallback(void *ptr)  // Release event for D3
{
   // Turn OFF internal LED
  
  digitalWrite(D3, LOW);
}  // End of release event

void b59PushCallback(void *ptr)  // Press event for D4
{
   // Turn ON internal LED
    digitalWrite(D4, HIGH);
  
}  // End of press event

void b510PushCallback(void *ptr)  // Release event for D4
{
   // Turn OFF internal LED
  
  digitalWrite(D4, LOW);
}  // End of release event

void b511PushCallback(void *ptr)  // Press event for D5
{
   // Turn ON internal LED
    digitalWrite(D5, HIGH);
  
}  // End of press event

void b512PushCallback(void *ptr)  // Release event for D5
{
   // Turn OFF internal LED
  
  digitalWrite(D5, LOW);
}  // End of release event

void b513PushCallback(void *ptr)  // Press event for D6
{
   // Turn ON internal LED
    digitalWrite(D6, HIGH);
  
}  // End of press event

void b514PushCallback(void *ptr)  // Release event for D6
{
   // Turn OFF internal LED
  
  digitalWrite(D6, LOW);
}  // End of release event

void b515PushCallback(void *ptr)  // Press event for D7
{
   // Turn ON internal LED
    digitalWrite(D7, HIGH);
  
}  // End of press event

void b516PushCallback(void *ptr)  // Release event for D7
{
   // Turn OFF internal LED
  
  digitalWrite(D7, LOW);
}  // End of release event

void b517PushCallback(void *ptr)  // Press event for D8
{
   // Turn ON internal LED
    digitalWrite(D8, HIGH);
  
}  // End of press event

void b518PushCallback(void *ptr)  // Release event for D8
{
   // Turn OFF internal LED
  
  digitalWrite(D8, LOW);
}  // End of release event

void b519PushCallback(void *ptr)  // Press event for D9
{
   // Turn ON internal LED
    digitalWrite(D9, HIGH);
  
}  // End of press event

void b520PushCallback(void *ptr)  // Release event for D9
{
   // Turn OFF internal LED
  
  digitalWrite(D9, LOW);
}  // End of release event

void b521PushCallback(void *ptr)  // Press event for D10
{
   // Turn ON internal LED
    digitalWrite(D10, HIGH);
  
}  // End of press event

void b522PushCallback(void *ptr)  // Release event for D10
{
   // Turn OFF internal LED
  
  digitalWrite(D10, LOW);
}  // End of release event


///////////////////////////////////////

/////////////////////////////////////

void b13PushCallback(void *ptr)  // Press event for button b0
{
  memory.d.M_T1  = memory.d.M_T1  - 1;  // Subtract 1 to the current value of the counter

/*  Serial.print("n0.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
  Serial.print(counter1);  // This is the value you want to send to that object and atribute mentioned before.
  Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  Serial.write(0xff);
  Serial.write(0xff);*/
}  // End of press event
void b14PushCallback(void *ptr)  // Press event for button b4
{
  memory.d.M_T1  = memory.d.M_T1  + 1;  // Add 1 to the current value of the counter

/*  Serial.print("n0.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
  Serial.print(counter1);  // This is the value you want to send to that object and atribute mentioned before.
  Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  Serial.write(0xff);
  Serial.write(0xff);*/
}  // End of press event


void b15PushCallback(void *ptr)  // Press event for button b0
{
  memory.d.M_T2  = memory.d.M_T2 - 1;  // Subtract 1 to the current value of the counter

/*  Serial.print("n1.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
  Serial.print(counter2);  // This is the value you want to send to that object and atribute mentioned before.
  Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  Serial.write(0xff);
  Serial.write(0xff);*/
}  // End of press event
void b16PushCallback(void *ptr)  // Press event for button b4
{
  memory.d.M_T2 = memory.d.M_T2 + 1;  // Add 1 to the current value of the counter

/*  Serial.print("n1.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
  Serial.print(counter2);  // This is the value you want to send to that object and atribute mentioned before.
  Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  Serial.write(0xff);
  Serial.write(0xff);*/
}  // End of press event

void b17PushCallback(void *ptr)  // Press event for button b0
{
  memory.d.M_T3 = memory.d.M_T3 - 1;  // Subtract 1 to the current value of the counter

/*  Serial.print("n2.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
  Serial.print(counter3);  // This is the value you want to send to that object and atribute mentioned before.
  Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  Serial.write(0xff);
  Serial.write(0xff);*/
}  // End of press event
void b18PushCallback(void *ptr)  // Press event for button b4
{
  memory.d.M_T3 = memory.d.M_T3 + 1;  // Add 1 to the current value of the counter

/*  Serial.print("n2.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
  Serial.print(counter3);  // This is the value you want to send to that object and atribute mentioned before.
  Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  Serial.write(0xff);
  Serial.write(0xff);*/
}  // End of press event

void b19PushCallback(void *ptr)  // Press event for button b0
{
  memory.d.M_T4 = memory.d.M_T4 - 1;  // Subtract 1 to the current value of the counter

/*  Serial.print("n3.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
  Serial.print(counter4);  // This is the value you want to send to that object and atribute mentioned before.
  Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  Serial.write(0xff);
  Serial.write(0xff);*/
}  // End of press event
void b110PushCallback(void *ptr)  // Press event for button b4
{
  memory.d.M_T4 = memory.d.M_T4 + 1;  // Add 1 to the current value of the counter

 /* Serial.print("n3.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
  Serial.print(counter4);  // This is the value you want to send to that object and atribute mentioned before.
  Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  Serial.write(0xff);
  Serial.write(0xff);*/
}  // End of press event

void b111PushCallback(void *ptr)  // Press event for button b0
{
  memory.d.M_T5 = memory.d.M_T5 - 1;  // Subtract 1 to the current value of the counter

/*  Serial.print("n4.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
  Serial.print(counter5);  // This is the value you want to send to that object and atribute mentioned before.
  Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  Serial.write(0xff);
  Serial.write(0xff);*/
}  // End of press event
void b112PushCallback(void *ptr)  // Press event for button b4
{
  memory.d.M_T5 = memory.d.M_T5 + 1;  // Add 1 to the current value of the counter

/*  Serial.print("n4.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
  Serial.print(counter5);  // This is the value you want to send to that object and atribute mentioned before.
  Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  Serial.write(0xff);
  Serial.write(0xff);*/
}  // End of press event

void b113PushCallback(void *ptr)  // Press event for button b0
{
  memory.d.M_T6 = memory.d.M_T6 - 1;  // Subtract 1 to the current value of the counter

/*  Serial.print("n5.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
  Serial.print(counter6);  // This is the value you want to send to that object and atribute mentioned before.
  Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  Serial.write(0xff);
  Serial.write(0xff);*/
}  // End of press event
void b114PushCallback(void *ptr)  // Press event for button b4
{
  memory.d.M_T6 = memory.d.M_T6 + 1;  // Add 1 to the current value of the counter

/*  Serial.print("n5.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
  Serial.print(counter6);  // This is the value you want to send to that object and atribute mentioned before.
  Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  Serial.write(0xff);
  Serial.write(0xff);*/
}  // End of press event



void b23PushCallback(void *ptr)  // Press event for button b0
{
  memory.d.M_R = memory.d.M_R - 1;  // Subtract 1 to the current value of the counter

/*  Serial.print("n20.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
  Serial.print(counter7);  // This is the value you want to send to that object and atribute mentioned before.
  Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  Serial.write(0xff);
  Serial.write(0xff);*/
}  // End of press event
void b24PushCallback(void *ptr)  // Press event for button b4
{
  memory.d.M_R = memory.d.M_R + 1;  // Add 1 to the current value of the counter

 /* Serial.print("n20.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
  Serial.print(counter7);  // This is the value you want to send to that object and atribute mentioned before.
  Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  Serial.write(0xff);
  Serial.write(0xff);*/
}  // End of press event

void b25PushCallback(void *ptr)  // Press event for button b0
{
  memory.d.M_C = memory.d.M_C - 1;  // Subtract 1 to the current value of the counter

 /* Serial.print("n21.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
  Serial.print(counter8);  // This is the value you want to send to that object and atribute mentioned before.
  Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  Serial.write(0xff);
  Serial.write(0xff);*/
}  // End of press event
void b26PushCallback(void *ptr)  // Press event for button b4
{
  memory.d.M_C = memory.d.M_C + 1;  // Add 1 to the current value of the counter

  /*Serial.print("n21.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
  Serial.print(counter8);  // This is the value you want to send to that object and atribute mentioned before.
  Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  Serial.write(0xff);
  Serial.write(0xff);*/
}  // End of press event

void b27PushCallback(void *ptr)  // Press event for button b0
{
  memory.d.M_L = memory.d.M_L - 1;  // Subtract 1 to the current value of the counter

 /*Serial.print("n22.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
  Serial.print(counter9);  // This is the value you want to send to that object and atribute mentioned before.
  Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  Serial.write(0xff);
  Serial.write(0xff);*/
}  // End of press event
void b28PushCallback(void *ptr)  // Press event for button b4
{
  memory.d.M_L = memory.d.M_L + 1;  // Add 1 to the current value of the counter

  /*Serial.print("n22.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
  Serial.print(counter9);  // This is the value you want to send to that object and atribute mentioned before.
  Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  Serial.write(0xff);
  Serial.write(0xff);*/
}  // End of press event


void b29PushCallback(void *ptr)  // Press event for button b0
{
  memory.d.M_Sensor = memory.d.M_Sensor - 1;  // Subtract 1 to the current value of the counter

 /*Serial.print("n22.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
  Serial.print(counter9);  // This is the value you want to send to that object and atribute mentioned before.
  Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  Serial.write(0xff);
  Serial.write(0xff);*/
}  // End of press event
void b210PushCallback(void *ptr)  // Press event for button b4
{
  memory.d.M_Sensor = memory.d.M_Sensor + 1;  // Add 1 to the current value of the counter

  /*Serial.print("n22.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
  Serial.print(counter9);  // This is the value you want to send to that object and atribute mentioned before.
  Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  Serial.write(0xff);
  Serial.write(0xff);*/
}  // End of press event

void b33PushCallback(void *ptr)  // Press event for button start
{
 //digitalWrite(13, HIGH);
  start = 1;
 
  /*Serial.print("n22.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
  Serial.print(counter9);  // This is the value you want to send to that object and atribute mentioned before.
  Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  Serial.write(0xff);
  Serial.write(0xff);*/
}  // End of press event



////////////////////////////////////calibration
void b523PushCallback(void *ptr)  // Press event for button b0
{
  memory.d.M_Cal  = memory.d.M_Cal  - 1;  // Subtract 1 to the current value of the counter

/*  Serial.print("n0.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
  Serial.print(counter1);  // This is the value you want to send to that object and atribute mentioned before.
  Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  Serial.write(0xff);
  Serial.write(0xff);*/
}  // End of press event
void b524PushCallback(void *ptr)  // Press event for button b4
{
  memory.d.M_Cal  = memory.d.M_Cal  + 1;  // Add 1 to the current value of the counter

/*  Serial.print("n0.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
  Serial.print(counter1);  // This is the value you want to send to that object and atribute mentioned before.
  Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  Serial.write(0xff);
  Serial.write(0xff);*/
}  // End of press event
////////////////////////////////////////////////


///////////MEMORY
/*void b12PushCallback(void *ptr)  // Press event for button b0
{
 writeConfiguration();
 //readConfiguration();
// digitalWrite(13, HIGH);


} */ // End of press event
void b22PushCallback(void *ptr)  // Press event for button b4
{
  writeConfiguration();
  //readConfiguration();
//  digitalWrite(13, LOW);

}  // End of press event

/*void b525PushCallback(void *ptr)  // Press event for button b4
{
  writeConfiguration();
  //readConfiguration();
//  digitalWrite(13, LOW);

} */ // End of press event



// Page change event:
void page0PushCallback(void *ptr)  // If page 0 is loaded on the display, the following is going to execute:
{
  CurrentPage = 0;  // Set variable as 0 so from now on arduino knows page 0 is loaded on the display
}  // End of press event


// Page change event:
void page1PushCallback(void *ptr)  // If page 1 is loaded on the display, the following is going to execute:
{
  CurrentPage = 1;  // Set variable as 1 so from now on arduino knows page 1 is loaded on the display
}  // End of press event


// Page change event:
void page2PushCallback(void *ptr)  // If page 2 is loaded on the display, the following is going to execute:
{
  CurrentPage = 2;  // Set variable as 2 so from now on arduino knows page 2 is loaded on the display
}  // End of press event

// Page change event:
void page3PushCallback(void *ptr)  // If page 1 is loaded on the display, the following is going to execute:
{
  CurrentPage = 3;  // Set variable as 1 so from now on arduino knows page 1 is loaded on the display
}  // End of press event

// Page change event:
void page4PushCallback(void *ptr)  // If page 1 is loaded on the display, the following is going to execute:
{
  CurrentPage = 4;  // Set variable as 1 so from now on arduino knows page 1 is loaded on the display
}  // End of press event

void page5PushCallback(void *ptr)  // If page 1 is loaded on the display, the following is going to execute:
{
  CurrentPage = 5;  // Set variable as 1 so from now on arduino knows page 1 is loaded on the display
}  // End of press event






void setup() {  // Put your setup code here, to run once:
   readConfiguration();
 /* Serial.begin(9600);  // Start Serial comunication at baud=9600
 
  // I am going to change the Serial baud to a faster rate.
  // The reason is that the slider have a glitch when we try to read it's value.
  // One way to solve it was to increase the speed of the Serial port.
  delay(500);  // This dalay is just in case the nextion display didn't start yet, to be sure it will receive the following command.
  Serial.print("baud=115200");  // Set new baud rate of nextion to 115200, but it's temporal. Next time nextion is power on,
                                // it will retore to default baud of 9600.
                                // To take effect, make sure to reboot the arduino (reseting arduino is not enough).
                                // If you want to change the default baud, send the command as "bauds=115200", instead of "baud=115200".
                                // If you change the default baud, everytime the nextion is power ON is going to have that baud rate, and
                                // would not be necessery to set the baud on the setup anymore.
  Serial.write(0xff);  // We always have to send this three lines after each command sent to nextion.
  Serial.write(0xff);
  Serial.write(0xff);
  Serial.end();  // End the Serial comunication of baud=9600*/
  Serial.begin(9600);  // Start Serial comunication at baud=115200
  readConfiguration();
  // Register the event callback functions of each touch event:
  // You need to register press events and release events seperatly.
  // Format for press events: <object name>.attachPush(<object name>PushCallback);
  // Format for release events: <object name>.attachPop(<object name>PopCallback);

  
 // b12.attachPush(b12PushCallback);  // Button press
  b13.attachPush(b13PushCallback);  // Button press
  b14.attachPush(b14PushCallback);  // Button press
  b15.attachPush(b15PushCallback);  // Button press
  b16.attachPush(b16PushCallback);  // Button press
  b17.attachPush(b17PushCallback);  // Button press
  b18.attachPush(b18PushCallback);  // Button press
  b19.attachPush(b19PushCallback);  // Button press
  b110.attachPush(b110PushCallback);  // Button press
  b111.attachPush(b111PushCallback);  // Button press
  b112.attachPush(b112PushCallback);  // Button press
  b113.attachPush(b113PushCallback);  // Button press
  b114.attachPush(b114PushCallback);  // Button press

  b22.attachPush(b22PushCallback);  // Button press
  b23.attachPush(b23PushCallback);  // Button press
  b24.attachPush(b24PushCallback);  // Button press
  b25.attachPush(b25PushCallback);  // Button press
  b26.attachPush(b26PushCallback);  // Button press
  b27.attachPush(b27PushCallback);  // Button press
  b28.attachPush(b28PushCallback);  // Button press
  b29.attachPush(b29PushCallback);  // Button press
  b210.attachPush(b210PushCallback);  // Button press

  ///////////////page 3
  b33.attachPush(b33PushCallback);  // Button press
    
  page0.attachPush(page0PushCallback);  // Page press event
  page1.attachPush(page1PushCallback);  // Page press event
  page2.attachPush(page2PushCallback);  // Page press event
  page3.attachPush(page3PushCallback);  // Page press event
  page4.attachPush(page4PushCallback);  // Page press event
  page5.attachPush(page5PushCallback);  // Page press event
  ////////////////////page 5
  b53.attachPush(b53PushCallback);  // Button press ON
  b54.attachPush(b54PushCallback);  // Button press off
  b55.attachPush(b55PushCallback);  // Button press ON
  b56.attachPush(b56PushCallback);  // Button press off
  b57.attachPush(b57PushCallback);  // Button press ON
  b58.attachPush(b58PushCallback);  // Button press off
  b59.attachPush(b59PushCallback);  // Button press ON
  b510.attachPush(b510PushCallback);  // Button press off
  b511.attachPush(b511PushCallback);  // Button press ON
  b512.attachPush(b512PushCallback);  // Button press off
  b513.attachPush(b513PushCallback);  // Button press ON
  b514.attachPush(b514PushCallback);  // Button press off
  b515.attachPush(b515PushCallback);  // Button press ON
  b516.attachPush(b516PushCallback);  // Button press off
  b517.attachPush(b517PushCallback);  // Button press ON
  b518.attachPush(b518PushCallback);  // Button press off
  b519.attachPush(b519PushCallback);  // Button press ON
  b520.attachPush(b520PushCallback);  // Button press off
  b521.attachPush(b521PushCallback);  // Button press ON
  b522.attachPush(b522PushCallback);  // Button press off
  b523.attachPush(b523PushCallback);  // calibration +
  b524.attachPush(b524PushCallback);  // calibration -
//  b525.attachPush(b525PushCallback);  // save

  
  
  // End of registering the event callback functions

  //pinMode(13, OUTPUT);

  ////////////////////////Oscar 
   pinMode(D1, OUTPUT);
   pinMode(D2, OUTPUT); 
   pinMode(D3, OUTPUT);
   pinMode(D4, OUTPUT); 
   pinMode(D5, OUTPUT);
   pinMode(D6, OUTPUT); 
   pinMode(D7, OUTPUT);
    pinMode(D8, OUTPUT); 
    pinMode(D9, OUTPUT); 
    pinMode(D10, OUTPUT);
    pinMode(13, OUTPUT);


}  // End of setup




void loop() {  // Put your main code here, to run repeatedly:

void(* resetFunc) (void) = 0; //declare reset function @ address 0

  delay(30);  // This is the only delay on this loop.
              // I put this delay because without it, the timer on the display would stop running.
              // The timer I am talking about is the one called tm0 on page 0 (of my example nextion project).
              // Aparently we shouldn't send data to the display too often.
/////////////////////////OSCAR VOID FUNCTION

      //Read voltageIn
    
      VoltageR = map(analogRead(TriggerPin), 0, 1024, 0, 500);
      
         
        if (flagPage5 == false)
        { 
         if (VoltageR >= 200)
         {
          
           //digitalWrite( 13, HIGH ) ;
               delay (150);
               Serial.print("page ");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
               Serial.print(3);  // Since we are sending text, and not a number, we need to send double quote before and after the actual text.
               Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
               Serial.write(0xff);
               Serial.write(0xff);
                digitalWrite( 13, LOW ) ;
                delay (150);
                start = 1;   
         }
        }
         
       
        
        
           //Read Sensor Voltage 1~5 volts
         
           // map it to the range of the analog out:
            Voltage = map(analogRead(SensorPin), 0, 1024, 0, 500);
            Voltage = Voltage + memory.d.M_Cal;
            // /// data correction0.75  0.35~0.75
           // percent = (((Voltage-96)/(500-96))*100)-(0.75); calibration sensor
            percent= (map(Voltage, 100, 500, 0, 10000))/100; //////two decimal factors
            int percentt= (map(Voltage, 100, 500, 0, 10000));
          // percent = (((Voltage-100)/(500-100))*100);
       ///////// percent = (((Voltage-96)/(500-96))*100)-(0.95); before used
        //Sensor value

        ///////////////////


            //int percentint2 = percent*100;
            int percentint = percentt/100;
            int percentint3 = (percentt-percentint*100); 

           int percent2 = map(percentt, 0, 10000, 0, 255);

           
              
  


 
  if(CurrentPage == 0){  // If the display is on page 0, do the following:
  
     nexLoop(nex_listen_list);  // Check for any touch event
    // Send a text to the object called t1:
    Serial.print("t0.txt=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
    Serial.print("\"");  // Since we are sending text, and not a number, we need to send double quote before and after the actual text.
    Serial.print("Online");  // This is the text you want to send to that object and atribute mentioned before.
    Serial.print("\"");  // Since we are sending text, and not a number, we need to send double quote before and after the actual text.
    Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
    Serial.write(0xff);
    Serial.write(0xff);

    

        

   
    
  }

if(CurrentPage == 1){
 nexLoop(nex_listen_list);



  
  
   Serial.print("n0.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
   //memory.d.M_T1;
   Serial.print(memory.d.M_T1);  // This is the text you want to send to that object and atribute mentioned before.
   Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
   Serial.write(0xff);
   Serial.write(0xff);
   
  Serial.print("n1.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
  // memory.d.M_T2
   Serial.print(memory.d.M_T2);  // This is the text you want to send to that object and atribute mentioned before.
   Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
   Serial.write(0xff);
   Serial.write(0xff);
   
   Serial.print("n2.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
  // memory.d.M_T3
   Serial.print(memory.d.M_T3);  // This is the text you want to send to that object and atribute mentioned before.
   Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
   Serial.write(0xff);
   Serial.write(0xff);
   
   Serial.print("n3.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
  // memory.d.M_T4
   Serial.print(memory.d.M_T4);  // This is the text you want to send to that object and atribute mentioned before.
   Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
   Serial.write(0xff);
   Serial.write(0xff);
   
   Serial.print("n4.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
  // memory.d.M_T5
   Serial.print(memory.d.M_T5);  // This is the text you want to send to that object and atribute mentioned before.
   Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
   Serial.write(0xff);
   Serial.write(0xff);
   
  Serial.print("n5.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
  // memory.d.M_T6
   Serial.print(memory.d.M_T6);  // This is the text you want to send to that object and atribute mentioned before.
   Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
   Serial.write(0xff);
   Serial.write(0xff);
  
}

if(CurrentPage == 2){
  
   nexLoop(nex_listen_list);
    // Send a text to the object called t1:
   
   
  
  Serial.print("n0.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
  // memory.d.M_R
   Serial.print(memory.d.M_R);  // This is the text you want to send to that object and atribute mentioned before.
   Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
   Serial.write(0xff);
   Serial.write(0xff);
   
  Serial.print("n1.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
  // memory.d.M_C
   Serial.print(memory.d.M_C);  // This is the text you want to send to that object and atribute mentioned before.
   Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
   Serial.write(0xff);
   Serial.write(0xff);
   
 Serial.print("n2.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
  // memory.d.M_L
   Serial.print(memory.d.M_L);  // This is the text you want to send to that object and atribute mentioned before.
   Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
   Serial.write(0xff);
   Serial.write(0xff);

  Serial.print("n3.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
  // memory.d.M_Sensor
   Serial.print(memory.d.M_Sensor);  // This is the text you want to send to that object and atribute mentioned before.
   Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
   Serial.write(0xff);
   Serial.write(0xff);
   
}

if(CurrentPage == 3)
{
  nexLoop(nex_listen_list);
 


    

    Serial.print("n30.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
  // VoltageR
   Serial.print(VoltageR);  // This is the text you want to send to that object and atribute mentioned before.
   Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
   Serial.write(0xff);
   Serial.write(0xff);

   Serial.print("n31.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
  // timer
   Serial.print(tNowf);  // This is the text you want to send to that object and atribute mentioned before.
   Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
   Serial.write(0xff);
   Serial.write(0xff);

    Serial.print("n32.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
  // timer
   Serial.print(tNextion);  // This is the text you want to send to that object and atribute mentioned before.
   Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
   Serial.write(0xff);
   Serial.write(0xff);

    Serial.print("n33.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
  // SENSOR
   Serial.print(percentint);  // This is the text you want to send to that object and atribute mentioned before.
   Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
   Serial.write(0xff);
   Serial.write(0xff);
    Serial.print("n34.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
  // SENSOR
   Serial.print(percentint3);  // This is the text you want to send to that object and atribute mentioned before.
   Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
   Serial.write(0xff);
   Serial.write(0xff);


  Serial.print("r0.val=");Serial.print(r1);Serial.write(0xff);Serial.write(0xff);Serial.write(0xff);
  Serial.print("r1.val=");Serial.print(r2);Serial.write(0xff);Serial.write(0xff);Serial.write(0xff);
  Serial.print("r2.val=");Serial.print(r3);Serial.write(0xff);Serial.write(0xff);Serial.write(0xff);
  Serial.print("r3.val=");Serial.print(r4);Serial.write(0xff);Serial.write(0xff);Serial.write(0xff);
  Serial.print("r4.val=");Serial.print(r5);Serial.write(0xff);Serial.write(0xff);Serial.write(0xff);
  Serial.print("r5.val=");Serial.print(r6);Serial.write(0xff);Serial.write(0xff);Serial.write(0xff);
  Serial.print("r6.val=");Serial.print(r7);Serial.write(0xff);Serial.write(0xff);Serial.write(0xff);
  Serial.print("r7.val=");Serial.print(r8);Serial.write(0xff);Serial.write(0xff);Serial.write(0xff);
  Serial.print("r8.val=");Serial.print(r9);Serial.write(0xff);Serial.write(0xff);Serial.write(0xff);
  Serial.print("r9.val=");Serial.print(r10);Serial.write(0xff);Serial.write(0xff);Serial.write(0xff);


  

    
//////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////


    
}

if(CurrentPage == 4)
{
nexLoop(nex_listen_list);

    Serial.print("n40.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
  // timer
   Serial.print(tNowf);  // This is the text you want to send to that object and atribute mentioned before.
   Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
   Serial.write(0xff);
   Serial.write(0xff);
   Serial.print("n41.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
  // SENSOR
   Serial.print(percentint);  // This is the text you want to send to that object and atribute mentioned before.
   Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
   Serial.write(0xff);
   Serial.write(0xff);
    Serial.print("n42.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
  // SENSOR
   Serial.print(percentint3);  // This is the text you want to send to that object and atribute mentioned before.
   Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
   Serial.write(0xff);
   Serial.write(0xff);
  // Send a new value to the waveform. In this case we are sending the variable1 value that goes from 0 to 240:
    delay (1000);

 
    
    Serial.print("add 4,0,");  // This sends data to the waveform. There are 3 numbers you have to put with a comma
                               // between them: [objectID],[Channel],[Value]
                               // In this case 2 is the ID of the waveform; 0 is the channel number; and last value is
                               // going to be send in the next line:
    Serial.print(percent2);  // This is the value we are going to send for the waveform and channel mentioned previously.
                              // Range is from 0 to 255. Going over 255 will show the graphic line going to 0 and continue from there.
                              // Each number it's a pixel. This means you can't do waveforms over 255 pixels high. Over that is unusable.
    Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
    Serial.write(0xff);
    Serial.write(0xff);

    
}

if(CurrentPage == 5)
{
  digitalWrite(13, LOW);
  flagPage5 = true;
  nexLoop(nex_listen_list);
     Serial.print("n50.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
    Serial.print(Voltage);  // This is the text you want to send to that object and atribute mentioned before.
    Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
    Serial.write(0xff);
    Serial.write(0xff);
      
   Serial.print("n51.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
    Serial.print(VoltageR);  // This is the text you want to send to that object and atribute mentioned before.
    Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
    Serial.write(0xff);
    Serial.write(0xff);

   Serial.print("n52.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
    Serial.print(memory.d.M_Cal);  // This is the text you want to send to that object and atribute mentioned before.
    Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
    Serial.write(0xff);
    Serial.write(0xff);
    
 
}
else
{
  flagPage5 = false;
  digitalWrite(13, HIGH);
}


 //////////////////////////////////////////////
if( start== 1)
        {
          //percent = percent/100;
   
        //TIMER 1 first loop  3 MINUTES
            if (tims==false)
            {
              tNowts=millis();
              tims=true;
            }
            tNows=(millis()-tNowts)/1000;  
        //TIMER 2 second loop  3 MINUTES
            if (timf==false)
            {
              tNowtf=millis();
              timf=true;
            }
            tNowf=(millis()-tNowtf)/1000;  

        //  Condition 1
        // if (tNows>=180)// memory.d.M_T1 instead of use 180 
            if (tNows>=memory.d.M_T1)
            {
              flags=true;
            }
            if (flags==true)
            {
              digitalWrite( D5, HIGH ) ;  
              digitalWrite( D6, HIGH ) ; 
              digitalWrite( D7, HIGH ) ;   
              r5=1;
              r6=1;
              r7=1;
                     
            }

        //Condition 2 
        //if (tNowf<360) //memory.d.M_T2 instead of use 360
            
        //if (tNowf>=360)
            if (tNowf>=memory.d.M_T2)
            {
              flagf=true;
            }
            if (flagf==true)
            {
               delay (250);
               Serial.print("page ");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
               Serial.print(0);  // Since we are sending text, and not a number, we need to send double quote before and after the actual text.
               Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
               Serial.write(0xff);
               Serial.write(0xff);
               // digitalWrite( 13, HIGH ) ;
              delay (250);
              digitalWrite( D10, LOW ) ;
              digitalWrite( D1, LOW ) ;  
              digitalWrite( D2, LOW ) ; 
              delay(200);
              digitalWrite( D5, LOW ) ; 
              digitalWrite( D6, LOW ) ;  
              delay(200);
              digitalWrite( D7, LOW ) ;  
              digitalWrite( D8, LOW ) ; 
              delay(200);
              digitalWrite( D9, LOW ) ; 
              digitalWrite( D10, LOW ) ;
              tims=false;
              timf=false;
            
              r1=0;
              r2=0;
              r3=0;
              r4=0;
              r5=0;
              r6=0;
              r7=0;
              r8=0;
              r9=0;
              r10=0;

               //Reset
              delay(250);
              //resetFunc();  //call reset
             
              start=0;
            delay(250);
              resetFunc();  //caLL RESET
            
               
            }

         
           ///////////////Purge
         
                          if (flagp == false)
                            {  
                              if (timp==false)
                                {
                                  tNowtp=millis();
                                  timp=true;
                                }
                              tNowp=(millis()-tNowtp)/1000;

                              
                              tNextion = tNowp;
                             
                              r1=1;
                              r2=1;
                                if (tNowp==2)// purge f
                                {
                                  flagp1  =true;//First Purge
                                }
                                if (tNowp==(memory.d.M_T6+1))//purge h
                                {
                                  flagp2   =true;//second purge   
                                }
                                if (tNowp>=(memory.d.M_T6+memory.d.M_T6+1))//purge l
                                {
                                
                                  flagp3   =true;//third purge
                                  flagp=true;
                                  digitalWrite( D4, LOW ) ;  
                                  delay(100);
                                  digitalWrite( D6, LOW ) ;
                                  r4=0;
                                  r6=0; 
                                }

                                
                                if (flagp1==false)//purge 2 second
                                {
                                   digitalWrite( D1, HIGH ) ;  
                                   digitalWrite( D2, HIGH ) ; 
                                   digitalWrite( D6, HIGH ) ;   
                                  
                                     r1=1;
                                     r2=1;
                                     r6=1;
                                }
                                if (flagp1==true && flagp2==false  )//purge h
                                {
                                   digitalWrite( D1, HIGH ) ;  
                                   digitalWrite( D2, HIGH ) ; 
                                   digitalWrite( D3, HIGH ) ; 
                                   digitalWrite( D6, HIGH ) ;   
                                  
                                    r1=1;
                                    r2=1;
                                    r3=1;
                                    r6=1;
                                }
                                 if (flagp1==true && flagp2==true && flagp3==false  )//purge l
                                 {
                                    digitalWrite( D1, HIGH ) ;  
                                    digitalWrite( D2, HIGH ) ; 
                                    digitalWrite( D3, LOW ) ; 
                                    digitalWrite( D4, HIGH ) ; 
                                    digitalWrite( D6, HIGH ) ;   
                                 
                                   r1=1;
                                   r2=1;
                                   r3=0;
                                   r4=1;
                                   r6=1;
                                 }
                                
                            }
                            else
                            {
          
          //First information
           // if (percent<(memory.d.M_Sensor-4)&&flag2==false)
            if (percent<(memory.d.M_Sensor-memory.d.M_L)&&flag2==false)
            {
              flag1=true;
            }
            if (flag1==true && flagf==false)
            {
               digitalWrite( D1, HIGH ) ;  
               digitalWrite( D2, HIGH ) ;  
               digitalWrite( D8, HIGH ) ;  
               digitalWrite( D9, HIGH ) ;  
               digitalWrite( D10, HIGH ) ; 
              
                                   r1=1;
                                   r2=1;
                                   r8=1;
                                   r9=1;
                                   r10=1;
            }
            
          //Second information
            if (percent>=(memory.d.M_Sensor-memory.d.M_L) && flagf==false)
            {
              flag2=true;
              flag1=false;
            }
            if (flag2==true&&flagf==false)
            {
              if (tim1==false)
                {
                    tNowt1=millis();
                    tim1=true;
                 }
              tNow1=(millis()-tNowt1)/1000;

              //Waiting to check the sensor
              if (tNow1<=memory.d.M_T3)//5sec memory.d.M_T3
                  {
                    digitalWrite( D8, LOW ) ; 
                    r8=0; 
                    digitalWrite( D10, HIGH ) ;  
                    r10=1;

                 
                   tNextion=tNow1;
                   
                    timerC2=5;
                  
                    if (percent>=(memory.d.M_Sensor-10) && timerC2==5 )
                      {
                        digitalWrite( D9, LOW ) ;  
                        r9=0; 
                      }
                  }
                  
              if (tNow1>memory.d.M_T3) // suggested 5 sec
                  {
                    if (tim2==false)
                      {
                        tNowt2=millis();
                        tim2=true;
                      }
                    tNow2=(millis()-tNowt2)/1000;  
                    if (tNow2<=memory.d.M_T3)//5sec
                      {
                        digitalWrite( D8, LOW ) ;  
                        r8=0;
                        digitalWrite( D10, HIGH ) ;  
                        r10=1;
                      
                       tNextion=tNow2;
                       
                        timerC2=5;
                      
                        timerC2=5;
                        if (percent>=(memory.d.M_Sensor-10) && timerC2==5 )
                          {
                            digitalWrite( D9, LOW ) ;  
                            r9=0;
                          }     
                      }
                      
                      //Conditions after 5 seconds
                    if (tNow2>memory.d.M_T3) //5sec
                      {
                          //Set New less 86%
                         if((percent<=(memory.d.M_Sensor-memory.d.M_L)) && flag3==false && flag4==false && flag5==false )
                         {
                          flag86=true;
                         }                        
                          //Set Point < Set Point-2                 <88
                        if((percent>(memory.d.M_Sensor-memory.d.M_L)) && (percent<=(memory.d.M_Sensor-memory.d.M_C)) && flag4==false && flag5==false && flag86==false)
                          {
                            flag3=true;
                          }
                          //Set Point-2 < Set Point < Set Point+2   88 < Set Point < 92
                        if((percent>(memory.d.M_Sensor-memory.d.M_C))&&(percent<(memory.d.M_Sensor+memory.d.M_R)) && flag3==false && flag5==false && flag86==false)
                          {
                            flag4=true;
                          }
                          //Set Point > Set Point+2                 92>
                        if((percent>=(memory.d.M_Sensor+memory.d.M_R)) && flag3==false && flag4==false && flag86==false)
                          {
                            flag5=true;
                          }

                        //set data less than 86 %
                          if (flag86==true)
                          { 
                            if (tim3==false)
                               {
                                  tNowt3=millis();
                                  tim3=true;
                                }
                            tNow3=(millis()-tNowt3)/1000;
                            digitalWrite( D8, HIGH ) ; 
                            r8=1;
                            delay(200);                   
                            digitalWrite( D9, HIGH ) ; 
                            r9=1;
                            
                         
                           tNextion=tNow3;
                         
                              //if (tNow3>=memory.d.M_T4)// 5 sec
                              if (percent>(memory.d.M_Sensor-memory.d.M_L))// 5 sec /// Set less 86%
                               {
                              
                                 tim2  = false; //Restart timers
                                 tim3  = false;
                                 flag86 = false;
                               }
                            }

                        
                        //Set Point < Set Point-2 D8 on 1 second D8 off 1 second 
                        //Set Point < Set Point-2 D9 on 1 second D9 off 1 second 
                        if (flag3==true)
                          { 
                            if (tim3==false)
                               {
                                  tNowt3=millis();
                                  tim3=true;
                                }
                            tNow3=(millis()-tNowt3)/1000;
                            if (tNow3 <= (memory.d.M_T4/100))
                                {
                                  digitalWrite( D8, HIGH ) ; 
                                  r8=1;
                                 
                                }
                            else 
                                {
                                  digitalWrite( D8, LOW ) ;  
                                  r8=0;
                                }
                            if (tNow3>=((memory.d.M_T4/100)+1)&&tNow3<=((memory.d.M_T4/100)+2))
                                {
                                  digitalWrite( D9, HIGH ) ; 
                                  r9=1;
                                 
                                 }
                              else 
                                  {
                                    digitalWrite( D9, LOW ) ;  
                                    r9=0;
                                  }
                           
                              tNextion=tNow3;
                            
                             // if (tNow3>=memory.d.M_T4)// 5 sec BEFORE
                              if (tNow3>=5)
                               {
                                 tim2  = false; //Restart timers
                                 tim3  = false;
                                 flag3 = false;
                               }
                            }

                        //Set Point-2 < Set Point < Set Point+2   88 < Set Point < 92
                        if (flag4==true)
                            {
                              if (tim4==false)
                                  {
                                    tNowt4=millis();
                                    tim4=true;
                                   }
                              tNow4=(millis()-tNowt4)/1000;
                              digitalWrite( D8, LOW ) ;  
                              r8=0;
                              digitalWrite( D9, LOW ) ; 
                              r9=0;
                            
                              tNextion=tNow4;
                                 
                             r1=1;
                             r2=1;
                             r10=1;    
                                if (tNow4>=memory.d.M_T3)/// 5sec
                                   {
                                     tim2=false; //Restart timers
                                     tim4=false;
                                     flag4=false;
                                    }
                            }

                         //Set Point > Set Point+2                 92>    
                        if (flag5==true)
                            {  
                              if (tim5==false)
                                {
                                  tNowt5=millis();
                                  tim5=true;
                                }
                              tNow5=(millis()-tNowt5)/1000;
                              
                              digitalWrite( D10, LOW ) ; 
                              r10=0;
                           
                            tNextion=tNow5;
                            
                              if (tNow5==(memory.d.M_T5/100))//0.35 or 0.50
                                {
                                  tim2=false;//Restart timers
                                  tim5=false;
                                  flag5=false;
                                }
                            }
                     }
               }
          }
                            } ///////////////////
        }
/////////////////////////////////////////////





  nexLoop(nex_listen_list);  // Check for any touch event










}  // End of loop


