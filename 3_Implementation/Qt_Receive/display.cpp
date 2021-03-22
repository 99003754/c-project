#include"display.h"
int16_t display::receieve()
{
    int16_t buf=0;
    buf =receieve_message();
    cout<<buf;
    int16_t mask=0000000000000011U;
    int16_t mask1=0x40;
    if((buf&mask)==0)
    {
      cout<<"id1"<<endl;

        send("01000000");


    }


    if((buf&mask)==id2)
    {
       cout<<"id1"<<endl;
       // if((buf&mask)==0x80)
       // {
       // send("10000000");
        //}
    }
    return buf;

}
void send(char *data)
{
send_message(data);
}
/*int main()
{
    display obj;
    //display obj1;
   int16_ obj.receieve();

}
*/
