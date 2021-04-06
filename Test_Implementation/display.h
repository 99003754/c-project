extern "C"
{
#include "receiver.h"
}
#define id1 0x01
#define id2 0x02

#include "iostream"
using namespace std;
typedef enum
{
    SOF_NOT_PRESENT_controller,
    success_controller,
    success_controller_ack,
    success_sensor,
    SOF_NOT_PRESENT_sensor,
    Wrong_data,
    succesfully_sent,
    ack_not_req
} enum_status;
class display
{
    uint16_t FRAME;

    int16_t data_value;

public:
    //int flags;
    enum_status receieve();
    int16_t frameid();
    enum_status ack_check();
};

void send(char *data);
