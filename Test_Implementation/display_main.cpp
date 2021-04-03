#include "display.h"
int main()
{
    display obj;
    int16_t value;

    int16_t mask = 3;
    int16_t mask1 = 2040;
    int16_t mask2 = 8192;
    int16_t data_value = 0;
    int16_t mask3 = 49152;
    int16_t sof_mask = (int16_t)16384;
    int16_t mask4 = 12288;
    int16_t level1 = 32768;
    int16_t level2 = 16384;
    int data = 0;
    while (1)
    {
        cout << endl;
        value = obj.receieve();
        //cout<<"shouldnt be here "<<unsigned(value)<<endl;
        if ((value & mask) == 1)
        {
            if ((value & mask3) == mask3 || (value & mask3) == level1 || (value & mask3) == level2)
            {
                cout << endl
                     << "SOF not present";
                cout << "id1 = controller " << endl;
            }
            else
            {
                cout << "id1 = controller " << endl;
                data_value = mask1 & value;
                cout << data_value / 8 << endl;
                if ((value & mask4) == 12288)
                {
                    send("0111111111111111");
                }
            }
        }

        else if ((value & mask) == 2)
        {
            if ((value & mask3) != mask3 && (value & mask3) != 32768 && (value & mask3) != 16384)
            {
                cout << "id2 = sensor " << endl;
                data_value = mask1 & value;
                cout << data_value / 8 << endl;
                ;
            }
            else
            {
                cout << "sensor start of frame is wrong" << endl;
            }

            //if((value&mask3
        }
        else
        {
            cout << "wrong data received";
        }
    }
}
