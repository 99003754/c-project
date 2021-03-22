#include "sensor.h"


int main(){
  sensor s;
  int randomNumber;
  int sum=0;
  char a[8];
  int i;
  while(1)
  {
    randomNumber =(rand() % 256);
    for(i=0;i<=8;i++)
    {
      sum=randomNumber%2;
      if(sum==1)
      {
      a[8-i]='1';
      }else
      {
        a[8-i]='0';
      }
      randomNumber=randomNumber/2;
    }
    sum=0;
  s.send(a,1);
  sleep(5);
  }

    
}
