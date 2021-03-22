#include "simulation.h"
int main()
{
    char array_controller[8];
    int i;
    int flag;

    simulation s;
    while(1)
    {
    cout<<"enter 8 bits"<<endl;
    for(i=0;i<8;i++)
    {
        cin>>array_controller[i];
    }
    cout<<"receieve data back -1"<<endl;
    cin>>flag;

    s.send(array_controller,flag);
    //sleep(10);
    }
    
    
}
