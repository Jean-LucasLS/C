#include <stdio.h>

int main(void){

  struct time{
    int hour;
    int min;
    int sec;
  };
  
  struct time now, *later;
  later = &now;

/*(*later).hour = 20; // First needs to declare the pointer value '(*later)', then informs '.hour'
  (*later).min  = 50;
  (*later).sec  = 30; */
  later -> hour = 20;
  later -> min  = 50;
  later -> sec  = 30;

  int sum = 100;

  struct time before;

  before.hour = sum + later -> sec;
  before.min  = now.hour + later -> min;
  before.sec  = later -> min + later -> sec;


  printf("%i:%i:%i\n", now.hour, now.min, now.sec);
  printf("%i:%i:%i", before.hour, before.min, before.sec);

  return;
}