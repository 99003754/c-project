#include "simulation.h"
simulation::simulation()
{}
simulation::simulation(int16_t simulation_FRAME):source(simulation_FRAME)
{}
void simulation::send(char *data,int flags)
{

char *ID="001";
char *SOF="00";
char *recieve_back="111";
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
    if(flags==0)
    {
    array[15-i]=n_recieve_back[k];
    k++;
    }
    else
    {
    array[15-i]=recieve_back[k];
    k++;
    }
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
      receieve();
    }
}



void receieve()
{
    int16_t buf=0;
    buf = receieve_message();
    cout<<endl<<"Ack recieved: "<<buf<<endl;
    //processing for display at sim or sen

}


