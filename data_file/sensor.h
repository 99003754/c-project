#include "source.h"
#include <cstdlib>
#include <ctime>

class sensor:public source{
    public:
    sensor();
    sensor(int16_t FRAME);
    void send(char *data,int flags);
    
    
    //void process();
};
void receieve();