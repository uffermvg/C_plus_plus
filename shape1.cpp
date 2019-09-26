#include <iostream>

using namespace std;

class Cube {
public:
    Cube(){
        setS(0);

    }

    Cube(double in_s){
        setS(in_s);

    }

    double getS(){
        return S;
    }


    void setS(double in_s){
        S = in_s;
    }


    void display(){
        cout << "Cube Parameters: " << endl;
        cout << "Side Length: " << getS() << endl;
        cout << "Volume: " << getVolume() << endl;
        cout << "Surface Area: " << getSArea() << endl << endl;
    }

private:
    double getVolume(){
        return S*S*S;
    }

    double getSArea(){
        return (S*S)*6;
    }

    double S;


};

int main(){

    Cube c1;
    c1.display();

    Cube c2(2);
    c2.display();

    c2.setS(3);
    c2.display();

    return 0;
}
