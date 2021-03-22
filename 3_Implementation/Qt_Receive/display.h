#ifndef DISPLAY_H
#define DISPLAY_H
extern "C"{
#include "receiver.h"

}
#define id1 0x01
#define id2 0x02

#include"iostream"
using namespace std;

class display{
    uint8_t FRAME;
    public:
    int16_t receieve();



};
void send(char *data);
#endif // DISPLAY_H
