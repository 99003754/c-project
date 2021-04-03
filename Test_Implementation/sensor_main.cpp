/*#include"sensor.h"
#include <thread>
int randomNumber;
int sum=0;

int i;
int main(){
  
  
char a[8];
  while(1)
  {
    std::thread threadObj_randomnumber(random_number_generator);
    ///std::thread threadObj_message(message_generator);
    //std::thread threadObj_sendmessage(send_mssg);
    threadObj_randomnumber.join();
    
    for(i=0;i<=8;i++)
    {
      sum=randomNumber%2;
      if(sum==1)
      {
      a[8-i]='1';
      std::cout<<a[8-i]<<endl;
      }else
      {
        a[8-i]='0';
        std::cout<<a[8-i]<<endl;
      }
      randomNumber=randomNumber/2;
    }
    sum=0;
      sensor s;
    s.send(a,0);
    //threadObj_message.join();
   // threadObj_sendmessage.join();
    


  
  
  sleep(5);
  }

    
}
void random_number_generator()
{
  std::cout<<"in thread1"<<endl;
  randomNumber =(rand() % 256);
  cout<<randomNumber;
}
/*void message_generator()
{
  std::cout<<"in thread2"<<endl;
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
}
void send_mssg()
{
  std::cout<<"in thread3"<<endl;
  sensor s;
  s.send(a,0);
}
*/

#include "sensor.h"
int main()
{

  int randomNumber;
  int16_t frame_data;

  while (1)
  {
    randomNumber = (rand() % 32768);
    frame_data = (int16_t)randomNumber;
    //cout<<"r nu"<<randomNumber<<endl;
    sensor object(frame_data, 1, 1);
    object.send();
    sleep(5);
  }
}
