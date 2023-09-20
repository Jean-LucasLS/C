int main(){

  struct time{
    int *pHour;
    int *pMin ;
    int *pSec ;
  };

  struct time today;

  int hour = 200;
  int min  = 300;
  int sec  = 400;

  today.pHour = &hour;
  today.pMin  = &min ;
  today.pSec  = &sec ;

  printf("Hour -> %i | Min -> %i | Min -> %i", *today.pHour, *today.pMin, *today.pSec);

  return;
}