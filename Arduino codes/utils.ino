#include "roket.h"

unsigned char check_sum_hesapla(){
    int check_sum = 0;
    
    for(int i = 4; i < 75; i++){
        //Serial.println(olusturulacak_paket[i]);//for debug!
        check_sum += olusturulacak_paket[i];
    }
    
    return (unsigned char) (check_sum % 256); 
}

void paket_olustur(){
    olusturulacak_paket[0] = 0xFF; // Sabit
    olusturulacak_paket[1] = 0xFF; // Sabit
    olusturulacak_paket[2] = 0x54; // Sabit
    olusturulacak_paket[3] = 0x52; // Sabit
    
    olusturulacak_paket[4] = 0;   // Takim ID = 0
    olusturulacak_paket[5] = 0; // Sayac degeri = 0
     
    FLOAT32_UINT8_DONUSTURUCU irtifa_float32_uint8_donusturucu;
    irtifa_float32_uint8_donusturucu.sayi = 20.2; // Irtifa degerinin atamasini yapiyoruz.
	olusturulacak_paket[6] = irtifa_float32_uint8_donusturucu.array[0];
    olusturulacak_paket[7] = irtifa_float32_uint8_donusturucu.array[1];
    olusturulacak_paket[8] = irtifa_float32_uint8_donusturucu.array[2];
    olusturulacak_paket[9] = irtifa_float32_uint8_donusturucu.array[3];
    
    FLOAT32_UINT8_DONUSTURUCU roket_gps_irtifa_float32_uint8_donusturucu;
    roket_gps_irtifa_float32_uint8_donusturucu.sayi = 1461.55; // Roket GPS Irtifa degerinin atamasini yapiyoruz.
	olusturulacak_paket[10] = roket_gps_irtifa_float32_uint8_donusturucu.array[0]; 
    olusturulacak_paket[11] = roket_gps_irtifa_float32_uint8_donusturucu.array[1];
    olusturulacak_paket[12] = roket_gps_irtifa_float32_uint8_donusturucu.array[2];
    olusturulacak_paket[13] = roket_gps_irtifa_float32_uint8_donusturucu.array[3];
    
    FLOAT32_UINT8_DONUSTURUCU roket_enlem_float32_uint8_donusturucu;
    roket_enlem_float32_uint8_donusturucu.sayi = 39.925019; // Roket enlem degerinin atamasini yapiyoruz.
	olusturulacak_paket[14] = roket_enlem_float32_uint8_donusturucu.array[0]; 
    olusturulacak_paket[15] = roket_enlem_float32_uint8_donusturucu.array[1];
    olusturulacak_paket[16] = roket_enlem_float32_uint8_donusturucu.array[2];
    olusturulacak_paket[17] = roket_enlem_float32_uint8_donusturucu.array[3];
    
    FLOAT32_UINT8_DONUSTURUCU roket_boylam_irtifa_float32_uint8_donusturucu;
    roket_boylam_irtifa_float32_uint8_donusturucu.sayi = 32.836954; // Roket boylam degerinin atamasini yapiyoruz.
	olusturulacak_paket[18] = roket_boylam_irtifa_float32_uint8_donusturucu.array[0]; 
    olusturulacak_paket[19] = roket_boylam_irtifa_float32_uint8_donusturucu.array[1];
    olusturulacak_paket[20] = roket_boylam_irtifa_float32_uint8_donusturucu.array[2];
    olusturulacak_paket[21] = roket_boylam_irtifa_float32_uint8_donusturucu.array[3];
    
    FLOAT32_UINT8_DONUSTURUCU gorev_yuku_gps_irtifa_float32_uint8_donusturucu;
    gorev_yuku_gps_irtifa_float32_uint8_donusturucu.sayi = 1361.61; // Gorev yuku GPS irtifa degerinin atamasini yapiyoruz.
	olusturulacak_paket[22] = gorev_yuku_gps_irtifa_float32_uint8_donusturucu.array[0]; 
    olusturulacak_paket[23] = gorev_yuku_gps_irtifa_float32_uint8_donusturucu.array[1];
    olusturulacak_paket[24] = gorev_yuku_gps_irtifa_float32_uint8_donusturucu.array[2];
    olusturulacak_paket[25] = gorev_yuku_gps_irtifa_float32_uint8_donusturucu.array[3];
    
    FLOAT32_UINT8_DONUSTURUCU gorev_yuku_enlem_float32_uint8_donusturucu;
    gorev_yuku_enlem_float32_uint8_donusturucu.sayi = 41.104593; // Gorev yuku enlem degerinin atamasini yapiyoruz.
	olusturulacak_paket[26] = gorev_yuku_enlem_float32_uint8_donusturucu.array[0]; 
    olusturulacak_paket[27] = gorev_yuku_enlem_float32_uint8_donusturucu.array[1];
    olusturulacak_paket[28] = gorev_yuku_enlem_float32_uint8_donusturucu.array[2];
    olusturulacak_paket[29] = gorev_yuku_enlem_float32_uint8_donusturucu.array[3];
    
    FLOAT32_UINT8_DONUSTURUCU gorev_yuku_boylam_irtifa_float32_uint8_donusturucu;
    gorev_yuku_boylam_irtifa_float32_uint8_donusturucu.sayi = 29.024411; // Gorev yuku boylam degerinin atamasini yapiyoruz.
	olusturulacak_paket[30] = gorev_yuku_boylam_irtifa_float32_uint8_donusturucu.array[0]; 
    olusturulacak_paket[31] = gorev_yuku_boylam_irtifa_float32_uint8_donusturucu.array[1];
    olusturulacak_paket[32] = gorev_yuku_boylam_irtifa_float32_uint8_donusturucu.array[2];
    olusturulacak_paket[33] = gorev_yuku_boylam_irtifa_float32_uint8_donusturucu.array[3];
    
    FLOAT32_UINT8_DONUSTURUCU kademe_gps_irtifa_float32_uint8_donusturucu;
    kademe_gps_irtifa_float32_uint8_donusturucu.sayi = 1666.61; // Kademe GPS Irtifa degerinin atamasini yapiyoruz.
	olusturulacak_paket[34] = kademe_gps_irtifa_float32_uint8_donusturucu.array[0]; 
    olusturulacak_paket[35] = kademe_gps_irtifa_float32_uint8_donusturucu.array[1];
    olusturulacak_paket[36] = kademe_gps_irtifa_float32_uint8_donusturucu.array[2];
    olusturulacak_paket[37] = kademe_gps_irtifa_float32_uint8_donusturucu.array[3];
    
    FLOAT32_UINT8_DONUSTURUCU kademe_enlem_float32_uint8_donusturucu;
    kademe_enlem_float32_uint8_donusturucu.sayi = 41.091485; // Kademe enlem degerinin atamasini yapiyoruz.
	olusturulacak_paket[38] = kademe_enlem_float32_uint8_donusturucu.array[0]; 
    olusturulacak_paket[39] = kademe_enlem_float32_uint8_donusturucu.array[1];
    olusturulacak_paket[40] = kademe_enlem_float32_uint8_donusturucu.array[2];
    olusturulacak_paket[41] = kademe_enlem_float32_uint8_donusturucu.array[3];
    
    FLOAT32_UINT8_DONUSTURUCU kademe_boylam_irtifa_float32_uint8_donusturucu;
    kademe_boylam_irtifa_float32_uint8_donusturucu.sayi = 29.061412; // Kademe boylam degerinin atamasini yapiyoruz.
	olusturulacak_paket[42] = kademe_boylam_irtifa_float32_uint8_donusturucu.array[0]; 
    olusturulacak_paket[43] = kademe_boylam_irtifa_float32_uint8_donusturucu.array[1];
    olusturulacak_paket[44] = kademe_boylam_irtifa_float32_uint8_donusturucu.array[2];
    olusturulacak_paket[45] = kademe_boylam_irtifa_float32_uint8_donusturucu.array[3];
    
    FLOAT32_UINT8_DONUSTURUCU jiroskop_x_float32_uint8_donusturucu;
    jiroskop_x_float32_uint8_donusturucu.sayi = 1.51; // Jiroskop X degerinin atamasini yapiyoruz.
	olusturulacak_paket[46] = jiroskop_x_float32_uint8_donusturucu.array[0]; 
    olusturulacak_paket[47] = jiroskop_x_float32_uint8_donusturucu.array[1];
    olusturulacak_paket[48] = jiroskop_x_float32_uint8_donusturucu.array[2];
    olusturulacak_paket[49] = jiroskop_x_float32_uint8_donusturucu.array[3];
    
    FLOAT32_UINT8_DONUSTURUCU jiroskop_y_float32_uint8_donusturucu;
    jiroskop_y_float32_uint8_donusturucu.sayi = 0.49; // Jiroskop Y degerinin atamasini yapiyoruz.
	olusturulacak_paket[50] = jiroskop_y_float32_uint8_donusturucu.array[0]; 
    olusturulacak_paket[51] = jiroskop_y_float32_uint8_donusturucu.array[1];
    olusturulacak_paket[52] = jiroskop_y_float32_uint8_donusturucu.array[2];
    olusturulacak_paket[53] = jiroskop_y_float32_uint8_donusturucu.array[3];
    
    FLOAT32_UINT8_DONUSTURUCU jiroskop_z_float32_uint8_donusturucu;
    jiroskop_z_float32_uint8_donusturucu.sayi = 0.61; // Jiroskop Z degerinin atamasini yapiyoruz.
	olusturulacak_paket[54] = jiroskop_z_float32_uint8_donusturucu.array[0]; 
    olusturulacak_paket[55] = jiroskop_z_float32_uint8_donusturucu.array[1];
    olusturulacak_paket[56] = jiroskop_z_float32_uint8_donusturucu.array[2];
    olusturulacak_paket[57] = jiroskop_z_float32_uint8_donusturucu.array[3];
    
    FLOAT32_UINT8_DONUSTURUCU ivme_x_float32_uint8_donusturucu;
    ivme_x_float32_uint8_donusturucu.sayi = 0.0411; // Ivme X degerinin atamasini yapiyoruz.
	olusturulacak_paket[58] = ivme_x_float32_uint8_donusturucu.array[0]; 
    olusturulacak_paket[59] = ivme_x_float32_uint8_donusturucu.array[1];
    olusturulacak_paket[60] = ivme_x_float32_uint8_donusturucu.array[2];
    olusturulacak_paket[61] = ivme_x_float32_uint8_donusturucu.array[3];
    
    FLOAT32_UINT8_DONUSTURUCU ivme_y_float32_uint8_donusturucu;
    ivme_y_float32_uint8_donusturucu.sayi = 0.0140; // Ivme Y degerinin atamasini yapiyoruz.
	olusturulacak_paket[62] = ivme_y_float32_uint8_donusturucu.array[0]; 
    olusturulacak_paket[63] = ivme_y_float32_uint8_donusturucu.array[1];
    olusturulacak_paket[64] = ivme_y_float32_uint8_donusturucu.array[2];
    olusturulacak_paket[65] = ivme_y_float32_uint8_donusturucu.array[3];
    
    FLOAT32_UINT8_DONUSTURUCU ivme_z_float32_uint8_donusturucu;
    ivme_z_float32_uint8_donusturucu.sayi = -0.9552; // Ivme Z degerinin atamasini yapiyoruz.
	olusturulacak_paket[66] = ivme_z_float32_uint8_donusturucu.array[0]; 
    olusturulacak_paket[67] = ivme_z_float32_uint8_donusturucu.array[1];
    olusturulacak_paket[68] = ivme_z_float32_uint8_donusturucu.array[2];
    olusturulacak_paket[69] = ivme_z_float32_uint8_donusturucu.array[3];
    
    FLOAT32_UINT8_DONUSTURUCU aci_float32_uint8_donusturucu;
    aci_float32_uint8_donusturucu.sayi = 5.08; // Aci degerinin atamasini yapiyoruz.
	olusturulacak_paket[70] = aci_float32_uint8_donusturucu.array[0]; 
    olusturulacak_paket[71] = aci_float32_uint8_donusturucu.array[1];
    olusturulacak_paket[72] = aci_float32_uint8_donusturucu.array[2];
    olusturulacak_paket[73] = aci_float32_uint8_donusturucu.array[3];
    
    olusturulacak_paket[74] = 1; // Durum bilgisi = Iki parasut de tetiklenmedi
     
    olusturulacak_paket[75] = check_sum_hesapla(); // Check_sum = check_sum_hesapla();
    olusturulacak_paket[76] = 0x0D; // Sabit
    olusturulacak_paket[77] = 0x0A; // Sabit
}