#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
  char urun_rengi[10];
  char urun_malzemesi[10];
  char urun_skt[10];
}urun_ozellikler;
typedef struct
{
  int urun_id;
  int urun_fiyat;
  char urun_adi[20];
  urun_ozellikler urun_ozellikleri;
}urun, *urun_p;

int main() {
  urun urun;


  strcpy(urun.urun_ozellikleri.urun_malzemesi,"Demir");



  printf("%s ikinci urun : ", urun.urun_ozellikleri.urun_malzemesi);
  for(;;) {}
  return 0;
}
