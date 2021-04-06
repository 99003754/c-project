extern "C"
{
#include "sender.h"
}
#include "iostream"
#include <math.h>
using namespace std;
/**
 * @brief 
 * 
 */
typedef enum{
    success,
    OUT_OF_RANGE,
    ACK_REC,
    ACK_NOT_REQ,
    sent
}con_status;
class source
{
protected:
    int16_t FRAME;
    int16_t DATA;
    int16_t SOF;
    int16_t ID;

public:
    source() : FRAME(0)
    {
    }
    source(int16_t obj_frame, int a, int b) : FRAME(obj_frame)
    {
    }

    source(int16_t obj_DATA) : DATA(obj_DATA)
    {
    }
    source(int16_t obj_SOF, int16_t obj_DATA) : SOF(obj_SOF), DATA(obj_DATA)
    {
    }

    virtual con_status send() = 0;
};
