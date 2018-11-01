int myPin[3] = {6,5,3};
int colore[3];

void setup() {
  for (byte i=0; i<3; i++) pinMode(myPin[i], OUTPUT);
}

void loop() {
  for (byte i=0; i<3; i++) {
    colore[i] = (int)random(256);
    analogWrite(myPin[i], colore[i]);
  }
  delay(500);
}
