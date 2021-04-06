#include "display.h"
int flags;
enum_status display::receieve()
{
    int16_t value;
    value = receieve_message();

    int16_t mask = 3;
    int16_t mask1 = 2040;
    int16_t mask2 = 8192;

    int16_t mask3 = 49152;
    //int16_t sof_mask = (int16_t)16384;
    int16_t mask4 = 12288;
    int16_t level1 = 32768;
    int16_t level2 = 16384;
    // int data = 0;

    if ((value & mask) == 1)
    {
        if ((value & mask3) == mask3 || (value & mask3) == level1 || (value & mask3) == level2)
        {
            //cout<<endl<<"SOF not present";
            // cout<<"id1 = controller "<<endl;
            return SOF_NOT_PRESENT_controller;
        }
        else
        {
            cout << "id1 = controller " << endl;
            data_value = mask1 & value;
            //cout<<data_value/8<<endl;
            FRAME = value;
            flags = 0;
            
            if ((value & mask4) == 12288)
            {

                send("0111111111111111");
                flags=1;
                return success_controller_ack;
            }
            else
            {
                return success_controller;
            }
        }
    }

    else if ((value & mask) == 2)
    {
        if ((value & mask3) != mask3 && (value & mask3) != 32768 && (value & mask3) != 16384)
        {
            //cout<<"id2 = sensor "<<endl;
            data_value = mask1 & value;
            FRAME = value;
            return success_sensor;
            //cout<<data_value/8<<endl;
        }
        else
        {
            FRAME=0;

            return SOF_NOT_PRESENT_sensor;
        }
    }
    else
    {
        // cout << "wrong data received";

        return Wrong_data;
    }
}
int16_t display::frameid()
{
    return FRAME;
}
enum_status display::ack_check()
{
    if (flags == 0)
    {
        return ack_not_req;
    }
    else
    {
        flags = 0;

        return succesfully_sent;
    }
}
void send(char *data)
{
    flags = 1;
    send_message(data);
}
