#include "simulation.h"
int flag1 ;

simulation::simulation() : source(0, 0)
{
  FRAME = 0;
}
simulation::simulation(int16_t obj_DATA, int obj_ack = 0) : source(obj_DATA)
{
  if (obj_ack == 1)
  {
    ack = (int16_t)12288;
  }
  else
  {
    ack = 0;
  }
  SOF = (int16_t)0;
  ID = 1;
}
simulation::simulation(int16_t obj_SOF, int16_t obj_DATA, int obj_ack) : source(obj_SOF, obj_DATA)
{
  if (obj_ack == 1)
  {
    ack = (int16_t)12288;
  }
  else
  {
    ack = 0;
  }
  ID = 1;
}
con_status simulation::send()
{
  //int16_t define_ID=2;
  //cout<<"data "<<unsigned(DATA)<<endl;

  //cout<<"ID "<<unsigned(ID)<<endl;
  //cout<<"ack "<<unsigned(ack)<<endl;
  //int16_t SOF_mask = (int16_t)49152;
  //int16_t DATA_mask = (int16_t)2040;
  //int16_t ID_mask = (int16_t)3;
 // int16_t ack_mask = (int16_t)12288;



  FRAME = (SOF) + (DATA) + (ID) + (ack);

  if(DATA>=0 && DATA<=255 )
  {
      
  }
  else
  {
    FRAME=0;
    return OUT_OF_RANGE;
  }
  int decimal_number = FRAME;
  char *array = new char[16];
  int sum = 0;
  for (int index = 0; index < 16; index++)
  {
    sum = decimal_number % 2;
    if (sum == 1)
    {
      array[15 - index] = '1';
      
    }
    else
    {
      array[15 - index] = '0';
      
    }
    decimal_number /= 2;
  }
  cout << endl;
  send_message1(array);
  delete[] array;
  array = NULL;
  if(ack==12288)
  {
    flag1=1;
  }
  //if (ack == 12288)
  //{
    //receieve();
  //}
  return sent;
}

simulation simulation::operator=(int16_t data)
{

  DATA = data;
  SOF = (int16_t)0;
  
  ack = (int16_t)0;
  ID = (int16_t)1;
 
}
con_status simulation::receieve_ack()
{
  if (flag1 == 1)
  {
    return ACK_NOT_REQ;
  }
  else
  {
    return ACK_REC;
  }
}

con_status receieve()
{
  int16_t buf = 0;
  buf = receieve_message1();
  cout << endl
       << "Ack recieved: " << buf << endl;
  flag1 = 1;
  return success;
}
int16_t simulation::con_frame_id()
{
  return FRAME;
}

