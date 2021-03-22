#include "sensor.h"
sensor::sensor()
{}
sensor::sensor(int16_t sensor_FRAME):source(sensor_FRAME)
{}
void sensor::send(char *data,int flags)
{
char *ID="010";
char *SOF="00";
char *recieve_back="100";
char *n_recieve_back="000";
int j=0,k=0,l=0;
char *array=new char[16];
for(int i=0;i<16;i++)
{
  if(i<3)
  {
    array[15-i]=ID[2-i];
  }
  else if(i==3 || i<11)
  {
    array[15-i]=data[7-j];
    j++;
  }
    else if(i==11 || i<14)
  {
    array[15-i]=n_recieve_back[k];
    k++;
  }
      else if(i==14 || i<16)
  {
    array[15-i]=SOF[l];
    l++;
  }
  else
  {
    //array[16]='\0';
  }
}

    send_message(array);
    delete [] array;
    array=NULL;
    if(flags==1)
    {
       //receieve();
     }

//processing
//constructor call filled with data

}
void receieve()
{
int8_t buf=0;
buf=receieve_message();
cout<<endl<<"Receiver sensor "<<unsigned(buf);
}


