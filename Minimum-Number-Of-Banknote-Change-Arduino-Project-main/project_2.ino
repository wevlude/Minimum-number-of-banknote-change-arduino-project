#include <EEPROM.h>
byte bes_tl_adedi = 0;
byte on_tl_adedi = 0;
byte yirmi_tl_adedi = 3;
byte elli_tl_adedi = 1;
byte yuz_tl_adedi = 2;
byte i;
int deger;
static int toplam = 0;
static int toplam_2 = 0;
static int toplam_3 = 0;
int sonuc = 0;
byte kopukleme_hizmet_id = 1;
byte yikama_hizmet_id = 2;
byte kurulama_hizmet_id = 3;
byte cilalama_hizmet_id = 4;
String hizmet_ad[4] = {"köpükleme", "yıkama", "kurulama", "cilalama"};
byte kopukleme_fiyat = 15;
byte yikama_fiyat = 10;
byte kurulama_fiyat = 5;
byte cilalama_fiyat = 50;
byte kopukleme_kalan_hizmet = 30;
byte yikama_kalan_hizmet = 50;
byte kurulama_kalan_hizmet = 100;
byte cilalama_kalan_hizmet = 20;
byte kopukleme_kalan_hizmet_2 = 30;

long rastgele_sayi;
void setup() {
  Serial.begin(9600);
  hizmetler();

  randomSeed(analogRead(A3));
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);
  pinMode(13, INPUT);
  pinMode(A1, OUTPUT);
  //A1 KIRMIZI A2 YEŞİL
  digitalWrite(A1, LOW);
  pinMode(A2, OUTPUT);
  digitalWrite(A2, LOW);

}
void loop() {
  para_secimi();
  hizmet_secimi(toplam_2);
  hizmetler_getir();
  resetleme();
  delay(50);
}

void hizmetler() {

  //0-4 arası adresleme TL adetlerini tutuyor.
  EEPROM.write(0, bes_tl_adedi);
  EEPROM.write(1, on_tl_adedi);
  EEPROM.write(2, yirmi_tl_adedi);
  EEPROM.write(3, elli_tl_adedi);
  EEPROM.write(4, yuz_tl_adedi);


  //5-7 arası adresleme köpükleme
  EEPROM.write(5, kopukleme_hizmet_id);
  EEPROM.write(6, kopukleme_kalan_hizmet);
  EEPROM.write(7, kopukleme_fiyat);

  //8-10 arası adresleme yıkama
  EEPROM.write(8, yikama_hizmet_id);
  EEPROM.write(9, yikama_kalan_hizmet);
  EEPROM.write(10, yikama_fiyat);

  //11-13 arası adresleme kurulama
  EEPROM.write(11, kurulama_hizmet_id);
  EEPROM.write(12, kurulama_kalan_hizmet);
  EEPROM.write(13, kurulama_fiyat);

  //14-16 arası adresleme cilalama
  EEPROM.write(14, cilalama_hizmet_id);
  EEPROM.write(15, cilalama_kalan_hizmet);
  EEPROM.write(16, cilalama_fiyat);

  Serial.println(String(EEPROM.read(0)) + "," + String(EEPROM.read(1)) + "," + String(EEPROM.read(2)) + "," + String(EEPROM.read(3)) + "," + String(EEPROM.read(4)));
  Serial.println(String(EEPROM.read(5)) + "," + hizmet_ad[0] + "," + String(EEPROM.read(6)) + "," + String(EEPROM.read(7)));
  Serial.println(String(EEPROM.read(8)) + "," + hizmet_ad[1] + "," + String(EEPROM.read(9)) + "," + String(EEPROM.read(10)));
  Serial.println(String(EEPROM.read(11)) + "," + hizmet_ad[2] + "," + String(EEPROM.read(12)) + "," + String(EEPROM.read(13)));
  Serial.println(String(EEPROM.read(14)) + "," + hizmet_ad[3] + "," + String(EEPROM.read(15)) + "," + String(EEPROM.read(16)));

}


void para_secimi() {

  if (digitalRead(2) == HIGH) { //birinci buton(beş tl)
    while (digitalRead(2) == HIGH) {

    }
    toplam += 5;
    EEPROM.write(0, (EEPROM.read(0) + 1));


  }

  if (digitalRead(3) == HIGH) { //ikinci buton(on tl)
    while (digitalRead(3) == HIGH) {


    }
    toplam += 10;
    EEPROM.write(1, (EEPROM.read(1) + 1));

  }

  if (digitalRead(4) == HIGH) { //üçüncü buton(yirmi tl)
    while (digitalRead(4) == HIGH) {

    }
    toplam += 20;
    EEPROM.write(2, (EEPROM.read(2) + 1));

  }

  if (digitalRead(5) == HIGH) { //dördüncü buton(elli tl)
    while (digitalRead(5) == HIGH) {

    }
    toplam += 50;
    EEPROM.write(3, (EEPROM.read(3) + 1));

  }

  if (digitalRead(6) == HIGH) { //beşinci buton(yüz tl)
    while (digitalRead(6) == HIGH) {

    }
    toplam += 100;
    EEPROM.write(4, (EEPROM.read(4) + 1));


  }



  if (digitalRead(7) == HIGH) { //altıncı buton(bitiş)
    while (digitalRead(7) == HIGH) {

    }
    Serial.print(toplam);
    Serial.println(" TL para attınız");
    toplam_2 = toplam_dondur(toplam);

  }
}
int toplam_dondur(int toplam) {
  return toplam;
}

void hizmet_secimi(int toplam_1) {

  if (digitalRead(8) == HIGH) { //birinci buton(köpükleme)
    while (digitalRead(8) == HIGH) {

    }
    byte kopuk_fiyati = EEPROM.read(7);
    sonuc += kopuk_fiyati;

    EEPROM.write(6, EEPROM.read(6) - 1);
    // Serial.println(EEPROM.read(6));

  }


  if (digitalRead(9) == HIGH) { //ikinci buton(yıkama)
    while (digitalRead(9) == HIGH) {

    }
    byte yikama_fiyati = EEPROM.read(10);
    sonuc += yikama_fiyati;
    EEPROM.write(9, EEPROM.read(9) - 1);

  }


  if (digitalRead(10) == HIGH) { //üçüncü buton(kurulama)
    while (digitalRead(10) == HIGH) {

    }
    byte kurulama_fiyati = EEPROM.read(13);
    sonuc += kurulama_fiyati;

    EEPROM.write(12, EEPROM.read(12) - 1);

  }


  if (digitalRead(11) == HIGH) { //dördüncü buton(cilalama)
    while (digitalRead(11) == HIGH) {

    }
    byte cilalama_fiyati = EEPROM.read(16);
    sonuc += cilalama_fiyati;

    EEPROM.write(15, EEPROM.read(15) - 1);

  }


  if (digitalRead(12) == HIGH) { //beşinci buton(bitiş)
    while (digitalRead(12) == HIGH) {

    }
    toplam_1 -= sonuc;

    Serial.println(toplam_1);
    rastgele_sayi = random(0, 5);
    if (rastgele_sayi == 2) {

      Serial.println("Para sıkışma durumu... para iadesi yapıldı... Lütfen resetleyiniz...");
      digitalWrite(A2, LOW);
      digitalWrite(A1, HIGH);
      while (digitalRead(A0) == 0) {

      }

    }
    else {

      digitalWrite(A2, HIGH);
      digitalWrite(A1, LOW);

      if (para_ustu(toplam_1) == 1) {
        Serial.println("Para üstü:");
        Serial.println(String(EEPROM.read(21)) + " adet 100 TL," + String(EEPROM.read(20)) + " adet 50 TL," + String(EEPROM.read(19)) + " adet 20 TL," + String(EEPROM.read(18)) + " adet 10 TL," + String(EEPROM.read(17)) + " adet 5 TL");
      }
      else {

        Serial.println("Para üstü verilememektedir...");
      }

    }
  }
}
void hizmetler_getir() {
  if (digitalRead(13) == HIGH) {
    while (digitalRead(13) == HIGH) {

    }
    Serial.println(String(EEPROM.read(0)) + "," + String(EEPROM.read(1)) + "," + String(EEPROM.read(2)) + "," + String(EEPROM.read(3)) + "," + String(EEPROM.read(4)));
    Serial.println(String(EEPROM.read(5)) + "," + hizmet_ad[0] + "," + String(EEPROM.read(6)) + "," + String(EEPROM.read(7)));
    Serial.println(String(EEPROM.read(8)) + "," + hizmet_ad[1] + "," + String(EEPROM.read(9)) + "," + String(EEPROM.read(10)));
    Serial.println(String(EEPROM.read(11)) + "," + hizmet_ad[2] + "," + String(EEPROM.read(12)) + "," + String(EEPROM.read(13)));
    Serial.println(String(EEPROM.read(14)) + "," + hizmet_ad[3] + "," + String(EEPROM.read(15)) + "," + String(EEPROM.read(16)));

  }

}
int  para_ustu(int toplam3) {
  int ana_para[5] = {EEPROM.read(0), EEPROM.read(1), EEPROM.read(2), EEPROM.read(3), EEPROM.read(4)};
  int kontrol = 5;
  int gecici = toplam3;

  byte para_ustu_bes = 0;
  byte para_ustu_on = 0;
  byte para_ustu_yirmi = 0;
  byte para_ustu_elli = 0;
  byte para_ustu_yuz = 0;

kontrol_noktasi:

  for (int i = 0; i <= toplam3; i++) {
    if ((toplam3 >= 100) && (kontrol > 4) && (para_ustu_yuz < ana_para[4])) {
      toplam3 = toplam3 - 100;
      para_ustu_yuz = para_ustu_yuz + 1;
    }
    else if ((toplam3 >= 50) && (kontrol > 3) && (para_ustu_elli < ana_para[3])) {
      toplam3 = toplam3 - 50;
      para_ustu_elli = para_ustu_elli + 1;
    }
    else if ((toplam3 >= 20) && (kontrol > 2) && (para_ustu_yirmi < ana_para[2])) {
      toplam3 = toplam3 - 20;
      para_ustu_yirmi = para_ustu_yirmi + 1;
    }
    else if ((toplam3 >= 10) && (kontrol > 1) && (para_ustu_on < ana_para[1])) {
      toplam3 = toplam3 - 10;
      para_ustu_on = para_ustu_on + 1;
    }
    else if ((toplam3 >= 5) && (kontrol > 0) && (para_ustu_bes < ana_para[0])) {
      toplam3 = toplam3 - 5;
      para_ustu_bes = para_ustu_bes + byte(1);
    }
    else break;
  }
  if ((toplam3 > 0) && (kontrol > 0)) {
    kontrol--;
    goto kontrol_noktasi;
  } else if ((toplam3 > 0) && (para_ustu_yuz > 0)) {
    para_ustu_yuz = 0;
    para_ustu_elli = 0;
    para_ustu_yirmi = 0;
    para_ustu_on = 0;
    para_ustu_bes = 0;
    toplam3 = gecici;
    kontrol = 4;
    goto kontrol_noktasi;
  } else if ((toplam3 > 0) && (para_ustu_elli > 0)) {
    para_ustu_yuz = 0;
    para_ustu_elli = 0;
    para_ustu_yirmi = 0;
    para_ustu_on = 0;
    para_ustu_bes = 0;
    toplam3 = gecici;
    kontrol = 3;
    goto kontrol_noktasi;
  } else if ((toplam3 > 0) && (para_ustu_yirmi > 0)) {
    para_ustu_yuz = 0;
    para_ustu_elli = 0;
    para_ustu_yirmi = 0;
    para_ustu_on = 0;
    para_ustu_bes = 0;
    toplam3 = gecici;
    kontrol = 2;
    goto kontrol_noktasi;
  } else if ((toplam3 > 0) && (para_ustu_on > 0)) {
    para_ustu_yuz = 0;
    para_ustu_elli = 0;
    para_ustu_yirmi = 0;
    para_ustu_on = 0;
    para_ustu_bes = 0;
    toplam3 = gecici;
    kontrol = 1;
    goto kontrol_noktasi;
  } else if (toplam3 > 0) {
    return 0;
  } else if (toplam3 == 0) {
    //para_ustu_bes 17
    //para_ustu_on 18
    //para_ustu_yirmi 19
    //para_ustu_elli 20
    //para_ustu_yuz 21
    EEPROM.write(17, para_ustu_bes);
    EEPROM.write(18, para_ustu_on);
    EEPROM.write(19, para_ustu_yirmi);
    EEPROM.write(20, para_ustu_elli);
    EEPROM.write(21, para_ustu_yuz);

    EEPROM.write(0, (EEPROM.read(0) - para_ustu_bes));
    EEPROM.write(1, (EEPROM.read(1) - para_ustu_on));
    EEPROM.write(2, (EEPROM.read(2) - para_ustu_yirmi));
    EEPROM.write(3, (EEPROM.read(3) - para_ustu_elli));
    EEPROM.write(4, (EEPROM.read(4) - para_ustu_yuz));

    return 1;
  }
}
void resetleme() {
  if ( analogRead(A0) == 1023 ) {
    while (digitalRead(A0) == 1023) {

    }
    Serial.println("Resetleme işlemi yapılıyor...");
    EEPROM.write(0, bes_tl_adedi);
    EEPROM.write(1, on_tl_adedi);
    EEPROM.write(2, yirmi_tl_adedi);
    EEPROM.write(3, elli_tl_adedi);
    EEPROM.write(4, yuz_tl_adedi);


    EEPROM.write(6, kopukleme_kalan_hizmet);
    EEPROM.write(9, yikama_kalan_hizmet);
    EEPROM.write(12, kurulama_kalan_hizmet);
    EEPROM.write(15, cilalama_kalan_hizmet);


    toplam_2 = 0;
    sonuc = 0;
    toplam = 0;




  }


}
