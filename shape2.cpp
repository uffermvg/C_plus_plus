#include <iostream>

using namespace std;

class Cuboid {
public:
    Cuboid(){
        setW(0);
        setL(0);
        setH(0);
    }

    Cuboid(double in_w, double in_l, double in_h){
        setW(in_w);
        setL(in_l);
        setH(in_h);
    }

    double getW(){
        return w;
    }

    double getL(){
        return l;
    }
    double getH(){
        return h;
    }

    void setW(double in_w){
        w = in_w;
    }

    void setL(double in_l){
        l = in_l;
    }
    void setH(double in_h){
        h = in_h;
    }

    void display(){
        cout << "Rectangle Parameters: " << endl;
        cout << "Width: " << getW() << endl;
        cout << "Length: " << getL() << endl;
        cout << "Height: "<< getH() << endl;
        cout << "Area: " << getArea() << endl;
        cout << "Surface Area: " << getSArea() << endl << endl;
    }

private:
    double getArea(){
        return w*l*h;
    }

    double getSArea(){
        return (2*w*l) + (2*l*h) + (2*h*w);
    }
    double h;

    double w;
    double l;

};

int main(){

    Cuboid c1;
    c1.display();

    Cuboid c2(2,4,5);
    c2.display();

    c2.setW(3);
    c2.display();

    return 0;
}
