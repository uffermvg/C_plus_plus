#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cmath>

using namespace std;

// this file uses classes to find calculations for a circle
class Point {
public:
    Point(){
        setX(0);
        setY(0);
    }
    Point(double in_x, double in_y){
        setX(in_x);
        setY(in_y);
    }
    double getX(){
        return x;
    }
    double getY(){
        return y;
    }
    void setX(double in_x){
        x = in_x;
    }
    void setY(double in_y){
        y = in_y;
    }

    // cout implementation for Point class
    friend ostream & operator<<( ostream &output, const Point &P ){
        output << "x: " << P.x << " y: " << P.y;
        return output;
    }

    // cin implementation for Point class
    friend istream & operator>>( istream &input, Point &P ){
        input >> P.x >> P.y;
        return input;
    }
    bool operator==(Point &rhs) {
        return (rhs.x == x && rhs.y == y);
    }



private:
    int x,y;
};


class Circle {
    // implement cout for Line classes objects
    friend ostream & operator<<( ostream &output, const Circle &L ){
        output << "Point 1: " << L.P1 << endl << "Point 2: " << L.P2;
        return output;
    }

    // implement cin for Line classes objects
    friend istream & operator>>( istream &input, Circle &L ){
        input >> L.P1 >> L.P2;
        return input;
    }

public:
    
    Circle(){
        setX1(0);
        setX2(x2);
        setY1(y1);
        setY2(y2);


    }
    Circle(int x1, int y1, int x2, int y2, Point P1, Point P2){
        setX1(x1);
        setX2(x2);
        setY1(y1);
        setY2(y2);
        setP1(0);
        setP2(0);

    }
    Point getP1(){
        return P1;
    }
    Point getP2(){
        return P2;
    }
    void setX1(int x){
        x1 = x;
    }
    void setY1(int y){
        y1 = y;
    }
    void setX2(int x){
        x2 = x;
    }
    void setY2(int y){
        y2 = y;
    }
    void setP1(Point in_P1(int x1, int y1)){
        P1 = in_P1(x1,y1);
    }
    void setP2(Point in_P2(int x2, int y2)){
        P2 = in_P2(x2,y2);
    }

    void Display(){
        cout << "The radius of the circle: "<<radius()<<endl;
        cout << "The diameter of the circle: "<<diameter()<<endl;
        cout << "The area of the circle: "<<area()<<endl;
        cout << "The circumference of the circle: "<<circumfrence()<<endl;
    }

    double getrad(){
        return radius();
    }


    bool operator==(Circle C2){
        if(radius() == C2.radius() && (P1 == C2.P1)){
            return true;
        }
        else {
            return false;
        }
    }

private:

    Point P1, P2;
    int x1,x2,y1,y2;
    bool equal(){
        if (P1 == P2){
            cout << "Points are equal"<<endl;
            return true;
        }
        else {
            cout << "Points are not equal"<<endl;
            return false;
        }
    }

    double radius(){
        double r;
        r = sqrt(pow((P2.getX() - P1.getX()),2)+ pow((P2.getY() - P1.getY()),2));
        return r;
    }

    double diameter(){
        double d;
        d = radius()*2;
        return d;
    }

    double area(){
        double a;
        a = M_PI * pow(radius(),2);
        return a;
    }

    double circumfrence(){
        double c;
        c = diameter() * M_PI;
        return c;
    }


};


int main(){
    Circle C1;
    Circle C2;
    // Line L2(5,6,7,8);
    cout << "C1: should have all zeros for values" << endl;
    cout << C1 << endl;

    cout << "Enter Two Points For Circle 1: ";
    cin >> C1;
    cout << C1 << endl;
    C1.Display();
    cout << "Enter Two points For Circle 2: "<<endl;
    cin >> C2;
    cout << C2 << endl;
    C2.Display();
    if(C2 == C1){
        cout << "Circles are the same"<<endl;
    }
    else{
        cout << "Circles are not the same"<<endl;
    }



    return 0;
}
