#include "source.h"

class simulation : public source
{
    int16_t ack;

public:
    simulation();
    simulation(int16_t obj_DATA, int obj_ack);

    simulation(int16_t obj_SOF, int16_t obj_DATA, int obj_ack);
    simulation operator=(int16_t data);
    int16_t con_frame_id();

    con_status send();
    con_status receieve_ack();

   
};
con_status receieve();

