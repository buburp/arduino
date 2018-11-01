const int leds = 10;
int i, num=0, clonenum, ritardo = 1000, myLEDs[leds];
bool stato;
// LEDs[0 to 9]: Blu1, Red1, Gre1, Yel1, Whi1, Blu2, Red2, Gre2, Yel2, Whi2

void setup() {
  for (i=0; i<leds; i++) {
     myLEDs[i] = i + 3;   // Pins 3 to 12
    pinMode(myLEDs[i], OUTPUT);
  }
}

void loop() {
  clonenum = num;
  for (i=leds-1; i>=0; i--) {
    stato = clonenum >= pow(2,i);
    digitalWrite(myLEDs[9-i], stato);
    if (stato) clonenum -= pow(2,i);
  }
  delay(ritardo);
  num = ++num % pow(2,nled);
}