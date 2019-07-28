#include <NewPing.h>
#include <NewTone.h>


#define TRIGGER_PIN  6  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     7  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 1000 // Maximum distance we want to ping for (in centimeters).

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
boolean triggered = false; 


#define ALARM 3
float sinVal;
int toneVal;
int higherTone;
unsigned int distance;

boolean isPlaying = false;
char notes[] = "EEEEEDCAAEDDAAG DDECBBAAAEDCAAEDDAAG DDECAA";
int e = 200;
int duration[] = {e*3, e, e, e, e*2, e*2, e*2, e, e, e, e*2, e*2, e, e, e, e*2, e*4, e, e, e*2, e*2, e, e, e, e, e*2, e*2, e*2, e, e, e, e*2, e*2, e, e, e, e*2, e*4, e, e, e*2, e*2, e, 0};
int C = 523, A = 440, G = 392, E = 659, D = 587;

void setup(){

Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.  


}
void loop(){
//      delay(29); // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
//      unsigned int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
//      distance = uS / US_ROUNDTRIP_CM;
//      if(distance==0) {
//      //  Serial.println("Nothing is detected");
//      } else {
//      Serial.print(distance);
//      Serial.println("cm");
//      Serial.print(toneVal);
//      Serial.println("IDK what this is");
//      }
//      if(distance<200&&distance>0) {
//        alarm();
//      } else {
//        noNewTone(ALARM);
//      }
  if (!isPlaying) {
    alarm();
  }
//   if(distance<200&&distance>0) {
//       alarm();
//    } else {
//       noNewTone(ALARM);
//     }
}

void alarm(){

//   for (int x=0; x<180; x++) {
//    // convert degrees to radians then obtain sin value
//    //sinVal = (sin(x*(3.1412/180)));
//    // generate a frequency from the sin value
//    //toneVal = 2000+(int(sinVal*500));
//    toneVal = 200*distance;
//    NewTone(ALARM, toneVal);
//   }
  isPlaying = true;
//  toneVal = 523;
//  delay(1000);
//  toneVal= 440;
  char note;
  for (int i = 0; i < 44; i = i + 1) {
    note = notes[i];
    switch (note) {
      case 'C':
        toneVal = 523;
        break;
      case 'A':
        toneVal = 440;
        break;
       case 'G':
        toneVal = 392;
        break;
       case 'E':
        toneVal = 659;
        break;
       case 'D':
        toneVal = 587;
        break;
       case 'B':
        toneVal = 494;
        break;
       default:
        toneVal = 0; //idk why
        break;
    }
    NewTone(ALARM, toneVal);
    delay(duration[i]);
    noNewTone(ALARM);
    delay(100);
  }
  delay(1000);
  isPlaying = false;
}
