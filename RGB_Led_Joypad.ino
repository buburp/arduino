const int pinClick = 4, pinMovX = 0, pinMovY = 1;  // Pin del joypad (4, A0, A1)
const int pinRGB[3] = {6,5,3};
int colore[3], i, posX, posY;
float lumen;

void setup() {
  pinMode(pinClick, INPUT);
  for (i=0; i<3; i++) pinMode(pinRGB[i], OUTPUT);
}

void loop() {
  if (digitalRead(pinClick) == HIGH) for (i=0; i<3; i++) colore[i] = 255;
  else {
    posX = analogRead(pinMovX);
    lumen = analogRead(pinMovY) / 1023.;
    if (posX < 512) for (i=0; i<3; i++) {
      colore[0] = (255 - posX / 2) * lumen;
      colore[1] = (posX / 2) * lumen;
      colore[2] = 0;
    }
    else {
      colore[0] = 0;
      colore[1] = (511 - posX / 2) * lumen;
      colore[2] = (posX / 2 - 256) * lumen;
    }
  }
  for (i=0; i<3; i++) analogWrite(pinRGB[i], colore[i]);
}


