extern "C"{
#include "sender.h"
}
#include "iostream"
using namespace std;
/**
 * @brief 
 * 
 */
class source{
    protected:
    int16_t FRAME;
    
    
    public:
        source():FRAME(0)
    {}
        source(int16_t obj_FRAME):FRAME(obj_FRAME)
    {}

    virtual void send(char *data,int flags)=0;
    
};
