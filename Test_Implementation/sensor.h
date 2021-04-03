#include "source.h"
#include <cstdlib>
#include <ctime>

class sensor : public source
{
public:
    //sensor();
    sensor(int16_t sensor_FRAME, int x, int y);
    int send();

    //void process();
};
int16_t processing(char *array_processing);
//void send_mssg();
//void random_number_generator();
//void message_generator();
