#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    cout << "input velocity: ";
    double velocity;
    cin >> velocity;

    double gravity = 9.8;
    double height = 0;
    int time = 0;
    double maxHeight = 0;
    int maxTime = 0;

    cout << "Time   Height"<<endl;

    while (height >= 0){
        height = (velocity * time) - (0.5 * gravity * pow(time,2));
        if(height < 0){
            height = 0;
            cout << time << "      "<< height << endl;
            break;
        }

        cout << time << "      "<< height << endl;
        if(maxHeight < height){
            maxHeight = height;
            maxTime = time;
        }
        if(height >= 0)
            time = time + 1;
        else {
            time = time;

        }
    }
    if(velocity ==0)
        time =0;
    cout << "Total time: "<< time<<"-seconds"<<endl;
    cout << "Maximum height: "<< maxHeight << " @ "<< maxTime<<"-seconds"<<endl;

    return 0;
}
