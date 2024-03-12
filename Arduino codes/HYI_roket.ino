#include "roket.h"


void setup() {
  Serial.begin(9600); // Seri portu başlat
}

void loop() {
  paket_olustur();
  Serial.write(olusturulacak_paket,78);

  delay(2000);
}
