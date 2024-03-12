#ifndef ROKET_H
#define ROKET_H

typedef union{
    float           sayi;
    unsigned char   array[4];
}FLOAT32_UINT8_DONUSTURUCU;

unsigned char olusturulacak_paket[78];

unsigned char check_sum_hesapla();
void paket_olustur();


#endif