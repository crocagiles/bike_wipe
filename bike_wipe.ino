/*

*/


#include <Adafruit_NeoPixel.h>

#define PIN      6
#define N_LEDS 150

Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);
int n[ 127 ];

void setup() {
  strip.begin();
  Serial.begin(9600);
  // led : percent

  //Left Downtube through left chainstay
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


  //Right Downtube through right chainstay
  n[ 98 ] = 0;
  n[ 97 ] = 1;
  n[ 96 ] = 2;
  n[ 95 ] = 3;
  n[ 94 ] = 4;
  n[ 93 ] = 5;
  n[ 92 ] = 6;
  n[ 91 ] = 7;
  n[ 90 ] = 8;
  n[ 89 ] = 9;
  n[ 88 ] = 10;
  n[ 87 ] = 11;
  n[ 86 ] = 12;
  n[ 85 ] = 13;
  n[ 84 ] = 14;
  n[ 83 ] = 15;
  n[ 82 ] = 16;
  n[ 81 ] = 17;
  n[ 80 ] = 18;
  n[ 79 ] = 19;
  n[ 78 ] = 20;
  n[ 77 ] = 21;
  n[ 76 ] = 22;
  n[ 75 ] = 23;
  n[ 74 ] = 24;
  n[ 73 ] = 25;

  //Left top tube
  n[ 127 ] = 0;
  n[ 126 ] = 1;
  n[ 125 ] = 2;
  n[ 124 ] = 3;
  n[ 123 ] = 4;
  n[ 122 ] = 5;
  n[ 121 ] = 6;
  n[ 120 ] = 7;
  n[ 119 ] = 8;
  n[ 118 ] = 9;
  n[ 117 ] = 10;
  n[ 116 ] = 11;
  n[ 115 ] = 12;
  n[ 114 ] = 13;
  n[ 113 ] = 14;

  //Right Top tube
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


  //left seat stay 15 -> 27

  n[ 37 ] = 15;
  n[ 36 ] = 16;
  n[ 35 ] = 17;
  n[ 34 ] = 18;
  n[ 33 ] = 19;
  n[ 32 ] = 20;
  n[ 31 ] = 21;
  n[ 30 ] = 22;
  n[ 29 ] = 23;
  n[ 28 ] = 24;
  n[ 27 ] = 25;
  n[ 26 ] = 26;
  n[ 25 ] = 27;


  //right seat tube + left seat tube
  n[ 39 ] = 15;
  n[ 40 ] = 15;
  n[ 41 ] = 15;
  n[ 42 ] = 15;
  n[ 43 ] = 15;
  n[ 44 ] = 15;
  n[ 45 ] = 15;
  n[ 46 ] = 15;
  n[ 47 ] = 15;
  n[ 48 ] = 15;
  n[ 49 ] = 15;
  n[ 50 ] = 15;
  n[ 51 ] = 15;
  n[ 52 ] = 15;
  n[ 53 ] = 15;
  n[ 54 ] = 15;
  n[ 55 ] = 15;
  n[ 56 ] = 15;
  n[ 57 ] = 15;
  n[ 58 ] = 15;

  //right chain stay
  n[ 59 ] = 16;
  n[ 60 ] = 17;
  n[ 61 ] = 18;
  n[ 62 ] = 19;
  n[ 63 ] = 20;
  n[ 64 ] = 21;
  n[ 65 ] = 22;
  n[ 66 ] = 23;
  n[ 67 ] = 24;
  n[ 68 ] = 25;
  n[ 68 ] = 25;



}



void loop() {
  // chase(strip.Color(255, 0, 0)); // Red
  // chase(strip.Color(0, 255, 0)); // Green
  // chase(strip.Color(0, 0, 255)); // Blue
  // section_one(strip.Color(255, 0, 0));

  for (uint16_t i = 0; i < 26; i++) {
    display(i);
    delay(25);
  }

  // test_pix(27);

}

static void test_pix(uint8_t pxLoc) {
  for (uint16_t i = 0; i < 150; i++) {
    strip.setPixelColor(i, strip.Color(0, 0, 0) );
  }
  strip.show();
  delay(50);
  strip.setPixelColor(pxLoc, strip.Color(255, 0, 0) );
  strip.show();
  delay(250);

}

static void display(uint8_t litPerc) {

  // Serial.println(strip.getPixelColor(1));

  for (int i = 0; i < 127; i++) {
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


