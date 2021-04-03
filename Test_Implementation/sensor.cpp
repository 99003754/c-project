#include "sensor.h"
//sensor::sensor()

sensor::sensor(int16_t sensor_FRAME, int x, int y) : source(sensor_FRAME, x, y)
{
}

int sensor::send()
{

  int decimal_number = FRAME;
  //cout<<"frame is "<<FRAME;
  char *array = new char[16];
  int sum = 0;
  for (int index = 0; index < 16; index++)
  {
    sum = decimal_number % 2;
    if (sum == 1)
    {
      array[15 - index] = '1';
      //cout<< array[15-index];
    }
    else
    {
      array[15 - index] = '0';
      // cout<< array[15-index];
    }
    array[14] = '1';
    array[15] = '0';
    decimal_number /= 2;
  }
  cout << endl;
  send_message1(array);
  delete[] array;
  array = NULL;
  return 1;

  //sensor new_obj(answer);
}

int16_t processing(char *array_processing)
{
  int index;
  int sums = 0;
  int n_c = 15;
  for (index = 0; index < 16; index++)
  {

    if (array_processing[index] == 48)
    {
      sums += 0;
    }
    else
    {
      sums += 1 * pow(2, n_c);
    }
    n_c--;
  }
  int16_t answer = sums;
  return answer;
}
