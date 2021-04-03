#include "simulation.h"
int main()
{
    int16_t data = 1;

    simulation obj1(128, 1);
    obj1.send();
    cout << endl;
    cout << endl;
    int choice;

    while (1)
    {
        cout << "with ack: 1 & without ack 0" << endl;
        cin >> choice;
        if (choice == 0)
        {

            cout << "enter data 0 to 255" << endl;
            cin >> data;
            data = data * 8;
            obj1 = data;
            obj1.send();
        }
        else
        {
            cout << "enter data" << endl;
            cin >> data;
            data = data * 8;
            simulation obj(data, 1);
            obj.send();
        }
    }
}
