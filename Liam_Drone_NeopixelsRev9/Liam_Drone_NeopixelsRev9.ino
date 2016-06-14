#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
 

#define PIN            2
#define PIN1           3

#define NUMPIXELS 5
 
Adafruit_NeoPixel Rear = Adafruit_NeoPixel(NUMPIXELS, PIN1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel Front = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int pixels = 5;
int frames = 5;
int fps = 5; //For that peasant feel
byte R[] = {0,0,0,0,0,0,255,0,0,0,0,0,0,0,0,0,0,0,255,0,0,0,0,0,255,0,0,0,0,0,255,0,0,0,0,0,0,0,0,0,0,0,255,0,0,0,0,0,255,0,0,0,0,0,255,0,0,0,0,0,0,0,0,0,0,0,255,0,0,0,0,0,0,0,0};
byte F[] = {0,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,0};
int Position;
void setup() {
  Front.begin();
  Rear.begin();
  Front.show();
  Rear.show();
}
 
int pos = 0, dir = 1; // Position, direction of "eye"
int pos1 = 0, dir1 = 1;
int cframe = 0;


 uint32_t green = Front.Color(0, 255, 0);
 uint32_t red = Front.Color(255, 0, 0);
 uint32_t blue = Front.Color(0, 0, 255);
 

void loop() {
  for (int i=0; i<NUMPIXELS; i++) {
        int cpixel = i % pixels;
        int index = cframe*pixels*3 + cpixel*3;
        Rear.setPixelColor(i,R[index],R[index+1],R[index+2]);
    }
      for (int i=0; i<NUMPIXELS; i++) {
        int cpixel = i % pixels;
        int index = cframe*pixels*3 + cpixel*3;
        Front.setPixelColor(i,F[index],F[index+1],F[index+2]);
  }
   
    Rear.show();
    Front.show();
    cframe ++;
    if (cframe >= frames) cframe = 0;
    delay(1000/fps);
  
}
