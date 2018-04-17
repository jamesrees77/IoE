
#include <SPI.h>
#include <Ethernet.h>
#include <PubNub.h>


byte mac[] = {0x00, 0x0E, 0xEF, 0x00, 0x00, 0x45};

char pubkey[] = "pub-c-f1bdab1f-6f75-45fc-8766-3eae32fb8e97";
char subkey[] = "sub-c-85c498f4-3667-11e8-8741-e2a40c21c595";
char channel[] = "jChannel";

const int FLEX_PIN = A0; // Pin connected to voltage divider output
const int FLEX_PIN_1 = A1;
const int FLEX_PIN_2 = A2;
const int FLEX_PIN_3 = A3;
const int FLEX_PIN_4 = A4;// pin a1 



// Measure the voltage at 5V and the actual resistance

const float VCC = 4.98; // Measured voltage of Ardunio 5V line
const float R_DIV = 47500.0; // Measured resistance of 3.3k resistor


// accurately calculate bend degree.
const float STRAIGHT_RESISTANCE = 37300.0; // resistance when straight
const float BEND_RESISTANCE = 90000.0; // resistance at 90 deg

void setup() 
{
  Serial.begin(9600);
  pinMode(FLEX_PIN, INPUT);
  pinMode(FLEX_PIN_1, INPUT); 
  pinMode(FLEX_PIN_2, INPUT); 
  pinMode(FLEX_PIN_3, INPUT); 
  pinMode(FLEX_PIN_4, INPUT); 

   while(!Ethernet.begin(mac)) {
    Serial.println("Ethernet setup error!");
    delay(1000);
  }
  Serial.println("Ethernet set up");
  PubNub.begin(pubkey,subkey);
  Serial.println("Pubnub set up");
}

void loop() 
{

   Ethernet.maintain();
  EthernetClient *client;
//

//  
  // Read the ADC, and calculate voltage and resistance from it
  int flexADC = analogRead(FLEX_PIN);

  
  float flexV = flexADC * VCC / 1023.0;
  float flexR = R_DIV * (VCC / flexV - 1.0);
//  Serial.println("Resistance: " + String(flexR) + " ohms");

  // Use the calculated resistance to estimate the sensor's
  // bend angle:
  float angle = map(flexR, STRAIGHT_RESISTANCE, BEND_RESISTANCE,
                   0, 90.0);
  Serial.println("Bend1: " + String(angle) + " degrees");
  Serial.println();
//
//if(angle > 10000) {
//    Serial.println("A");
// }


 //finger 2------------------------------------------------------------------ 
  // Read the ADC, and calculate voltage and resistance from it
  int flexFinger2 = analogRead(FLEX_PIN_1);
  
  flexV = flexFinger2 * VCC / 1023.0;
  flexR = R_DIV * (VCC / flexV - 1.0);
//  Serial.println("Resistance: " + String(flexR) + " ohms");

  // Use the calculated resistance to estimate the sensor's
  // bend angle:
 float angle2 = map(flexR, STRAIGHT_RESISTANCE, BEND_RESISTANCE,
                   0, 90.0);
  Serial.println("Bend2: " + String(angle2) + " degrees");
  Serial.println();

 
//finger 3 ------------------------------------------------------------------
  // Read the ADC, and calculate voltage and resistance from it
  int flexFinger3 = analogRead(FLEX_PIN_2);
  
  flexV = flexFinger3 * VCC / 1023.0;
  flexR = R_DIV * (VCC / flexV - 1.0);
//  Serial.println("Resistance: " + String(flexR) + " ohms");

  // Use the calculated resistance to estimate the sensor's
  // bend angle:
 float angle3 = map(flexR, STRAIGHT_RESISTANCE, BEND_RESISTANCE,
                   0, 90.0);
  Serial.println("Bend3: " + String(angle3) + " degrees");
  Serial.println();

 
 //finger 4 ------------------------------------------------------------------
  // Read the ADC, and calculate voltage and resistance from it
  int flexFinger4 = analogRead(FLEX_PIN_3);
  
  flexV = flexFinger4 * VCC / 1023.0;
  flexR = R_DIV * (VCC / flexV - 1.0);
//  Serial.println("Resistance: " + String(flexR) + " ohms");

  // Use the calculated resistance to estimate the sensor's
  // bend angle:
 float angle4 = map(flexR, STRAIGHT_RESISTANCE, BEND_RESISTANCE,
                   0, 90.0);
  Serial.println("Bend4: " + String(angle4) + " degrees");
  Serial.println();
  



//finger 5 ------------------------------------------------------------------
  // Read the ADC, and calculate voltage and resistance from it
  int flexFinger5 = analogRead(FLEX_PIN_4);
  
  flexV = flexFinger5 * VCC / 1023.0;
  flexR = R_DIV * (VCC / flexV - 1.0);
//  Serial.println("Resistance: " + String(flexR) + " ohms");

  // Use the calculated resistance to estimate the sensor's
  // bend angle:
 float angle5 = map(flexR, STRAIGHT_RESISTANCE, BEND_RESISTANCE,
                   0, 90.0);
  Serial.println("Bend5: " + String(angle5) + " degrees");
  Serial.println();

  bool letterFound = true;

  char msg[64] = "{\"Letter\":[";

//  LETTTERS --------------------------------------------------------------------
  if(angle >=6000 && angle2 >=6000 && angle3 >=5000 && angle4 >=8000) {
    Serial.println("A");
    
     sprintf(msg + strlen(msg), "%s", "\"A\"");
    
 }
 else if (angle5 >= 8000 && angle + angle2 + angle3 + angle4 < 15000) {
     Serial.println("B");
     sprintf(msg + strlen(msg), "%s", "\"B\"");
   
     
 }
  else if (angle4 >= 5000 && angle4 <= 10000 && angle + angle2 + angle3 + angle5 <=12000) {
     Serial.println("C");
     sprintf(msg + strlen(msg), "%s", "\"C\"");
 }
    else if (angle4 <= 5000 && angle >=6000 && angle2 >=6000 && angle3 >=3000 && angle5 >=6000) {
     Serial.println("D");
     sprintf(msg + strlen(msg), "%s", "\"D\"");
 }
     else if (angle4 <= 5000 && angle5 <= 8000 && angle >= 8000 && angle2 >= 7000 && angle3 >= 5000 ) {
     Serial.println("L");
     sprintf(msg + strlen(msg), "%s", "\"L\"");
 }
     else if (angle <= 5000 && angle2 >= 4000 && angle3 >= 5000 && angle4 >= 8000 && angle5 >=5000) {
     Serial.println("I");
    
     sprintf(msg + strlen(msg), "%s", "\"I\"");
     
 }
      else if (angle <= 8000 && angle5 <= 8000 && angle2 >= 5000 && angle3 >= 5000 && angle4 >= 5000) {
     Serial.println("Y");
     sprintf(msg + strlen(msg), "%s", "\"Y\"");
      }
// else {
//
//  letterFound = false;
// }


//  if(letterFound) {
    strcat (msg, "]}");
    
    Serial.println(msg);
  
    
     client = PubNub.publish(channel, msg);
  
    if(!client) {
      Serial.println("publishing error");
    } else {
  //    Serial.println("published");
      client->stop();
    }
      


  delay(1000);
  
}
