#include "source.h"

class simulation:public source{
    public:
    simulation();
    simulation(int16_t simulation_FRAME);
    void send(char *data,int flags);
    
    //void process();
};
void receieve();