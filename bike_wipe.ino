/*

*/


#include <Adafruit_NeoPixel.h>

#define PIN      6
#define N_LEDS 128

Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);
int n[ 127 ];
int clocky = 0;

void setup() {
  strip.begin();
  Serial.begin(9600);
  // led : percent

// 1.) Left Downtube
n[ 0 ] = 0;
n[ 1 ] = 1;
n[ 2 ] = 2;
n[ 3 ] = 3;
n[ 4 ] = 4;
n[ 5 ] = 5;
n[ 6 ] = 6;
n[ 7 ] = 7;
n[ 8 ] = 8;
n[ 9 ] = 9;
n[ 10 ] = 10;
n[ 11 ] = 11;
n[ 12 ] = 12;
n[ 13 ] = 13;
n[ 14 ] = 14;
n[ 15 ] = 15;
// 2.) Left Chain Stay
n[ 16 ] = 16;
n[ 17 ] = 17;
n[ 18 ] = 18;
n[ 19 ] = 19;
n[ 20 ] = 20;
n[ 21 ] = 21;
n[ 22 ] = 22;
n[ 23 ] = 23;
n[ 24 ] = 24;
n[ 25 ] = 25;
// 3.) Left Seat Stay
n[ 26 ] = 27;
n[ 27 ] = 26;
n[ 28 ] = 25;
n[ 29 ] = 24;
n[ 30 ] = 23;
n[ 31 ] = 22;
n[ 32 ] = 21;
n[ 33 ] = 20;
n[ 34 ] = 19;
n[ 35 ] = 18;
n[ 36 ] = 17;
n[ 37 ] = 16;
n[ 38 ] = 15;
// 4.) Left Seat Tube
n[ 39 ] = 10;
n[ 40 ] = 11;
n[ 41 ] = 12;
n[ 42 ] = 13;
n[ 43 ] = 14;
n[ 44 ] = 14;
n[ 45 ] = 13;
n[ 46 ] = 12;
n[ 47 ] = 11;
n[ 48 ] = 10;
// 5.) Right Seat Tube
n[ 49 ] = 10;
n[ 50 ] = 11;
n[ 51 ] = 12;
n[ 52 ] = 13;
n[ 53 ] = 14;
n[ 54 ] = 14;
n[ 55 ] = 13;
n[ 56 ] = 12;
n[ 57 ] = 11;
n[ 58 ] = 10;
// 6.) Right Seat Stay
n[ 59 ] = 15;
n[ 60 ] = 16;
n[ 61 ] = 17;
n[ 62 ] = 18;
n[ 63 ] = 19;
n[ 64 ] = 20;
n[ 65 ] = 21;
n[ 66 ] = 22;
n[ 67 ] = 23;
n[ 68 ] = 24;
n[ 69 ] = 25;
n[ 70 ] = 26;
n[ 71 ] = 27;
// 7.) Right Chain Stay
n[ 72 ] = 25;
n[ 73 ] = 24;
n[ 74 ] = 23;
n[ 75 ] = 22;
n[ 76 ] = 21;
n[ 77 ] = 20;
n[ 78 ] = 19;
n[ 79 ] = 18;
n[ 80 ] = 17;
n[ 81 ] = 16;
// 8.) Right Down Tube
n[ 82 ] = 15;
n[ 83 ] = 14;
n[ 84 ] = 13;
n[ 85 ] = 12;
n[ 86 ] = 11;
n[ 87 ] = 10;
n[ 88 ] = 9;
n[ 89 ] = 8;
n[ 90 ] = 7;
n[ 91 ] = 6;
n[ 92 ] = 5;
n[ 93 ] = 4;
n[ 94 ] = 3;
n[ 95 ] = 2;
n[ 96 ] = 1;
n[ 97 ] = 0;
// 9.) Right Top Tube
n[ 98 ] = 0;
n[ 99 ] = 1;
n[ 100 ] = 2;
n[ 101 ] = 3;
n[ 102 ] = 4;
n[ 103 ] = 5;
n[ 104 ] = 6;
n[ 105 ] = 7;
n[ 106 ] = 8;
n[ 107 ] = 9;
n[ 108 ] = 10;
n[ 109 ] = 11;
n[ 110 ] = 12;
n[ 111 ] = 13;
n[ 112 ] = 14;
// 10.) Left Top Tube
n[ 113 ] = 14;
n[ 114 ] = 13;
n[ 115 ] = 12;
n[ 116 ] = 11;
n[ 117 ] = 10;
n[ 118 ] = 9;
n[ 119 ] = 8;
n[ 120 ] = 7;
n[ 121 ] = 6;
n[ 122 ] = 5;
n[ 123 ] = 4;
n[ 124 ] = 3;
n[ 125 ] = 2;
n[ 126 ] = 1;
n[ 127 ] = 0;



}



void loop() {
  
  clocky++;
  // chase(strip.Color(255, 0, 0)); // Red
  // chase(strip.Color(0, 255, 0)); // Green
  // chase(strip.Color(0, 0, 255)); // Blue
  // section_one(strip.Color(255, 0, 0));

  for (uint16_t i = 0; i < 29; i++) {
    display(i);
    delay(25);
    
  }

  // test_pix(27);

}

static void test_pix(uint8_t pxLoc) {
  for (uint16_t i = 0; i < 128; i++) {
    strip.setPixelColor(i, strip.Color(0, 0, 0) );
  }
  strip.show();
  delay(50);
  strip.setPixelColor(pxLoc, strip.Color(255, 0, 0) );
  strip.show();
  delay(250);

}

static void push_sine() {
  int clocky = 0;
  for (uint16_t x = 0; x < 29; x++) { // iterates of x positions on bike
    clocky++;
    for (uint16_t i = 0; i < 128; i++) { // iterates over each of the LEDs
      if (x != 0) { //propagate from previous pixel if we are not on x position 0
        int prev_x = x - 1;
        // TODO pull pixel value from a pixel index (0-127) instead of x axis index (0-27)
        if (n[i] == x) {
          int prev_color = strip.getPixelColor(prev_x); // TODO get color from index of i instead of x
          // TODO set color
        }
      }
      if (x == 0) {
        if (n[i] == 0) { //if x position is 0, aka LED position is on the headset. 
          float val = sin(clocky); 
          // TODO map to 0: 255
          strip.setPixelColor(i, strip.Color(val, 0, 0) ); // sets pixels at x position 0 to sin
        }
      }
    }
  strip.show();
  }
}


static void display(uint8_t litPerc) {

  // Serial.println(strip.getPixelColor(1));

  for (int i = 0; i < 128; i++) {
    int led = i;
    int perc = n[i];

    if (perc == litPerc) {
      strip.setPixelColor(led, strip.Color(0, 0, 255) );
    }
    else if (perc < litPerc && perc >= litPerc - 50) {
      int t = perc - litPerc;
      int tm = map(t, 0, 50, 0, 255);
      strip.setPixelColor(led, strip.Color(0, 0, tm) );
    }
    else {
      strip.setPixelColor(led, strip.Color(0, 0, 0));
    }
  }
  strip.show();
}

static void chase(uint32_t c) {
  for (uint16_t i = 0; i < strip.numPixels() + 4; i++) {
    strip.setPixelColor(i, c);   // Draw new pixel
    strip.setPixelColor(i - 4, 0); // Erase pixel a few steps back
    strip.show();
    delay(25);
  }
}

static void section_one(uint32_t c) {
  for (uint16_t i = 0; i < 21; i++) {
    strip.setPixelColor(i, c);   // Draw new pixel
    strip.setPixelColor(i - 1, 0); // Erase pixel a few steps back

    strip.setPixelColor(i + 19, c); // Draw new pixel
    strip.setPixelColor(i + 18, 0); //Erase pixel a few steps back

    strip.show();
    delay(25);
  }


}


