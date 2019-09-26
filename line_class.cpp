#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

// Please replace this Point class with your version from Part B
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

private:
    int x,y;
};


class Line {
    // implement cout for Line classes objects
    friend ostream & operator<<( ostream &output, const Line &L ){
        output << "Point 1: " << L.P1 << endl << "Point 2: " << L.P2;
        return output;
    }

    // implement cin for Line classes objects
    friend istream & operator>>( istream &input, Line &L ){
        input >> L.P1 >> L.P2;
        return input;
    }

public:
    // Add your functions/methods here //
    Line(){
        setX1(0);
        setX2(x2);
        setY1(y1);
        setY2(y2);


    }
    Line(int x1, int y1, int x2, int y2, Point P1, Point P2){
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
        cout << "Slope: "<< Slope()<<endl;
        cout << "Y intercept: "<<Yint()<<endl;
    }
    double getSlope(){
        return Slope();
    }

private:

    Point P1, P2;
    int x1,x2,y1,y2;
    double Slope(){
        double slope = 0;
        double xdiff;
        double ydiff;
        xdiff = P2.getX() - P1.getX();
        ydiff = P2.getY() - P1.getY();

        if(ydiff == 0){
            cout << "the line is vertical"<<endl;
        }
        else if(xdiff == 0){
            cout << "Line is vertical"<<endl;
        }
        else{
           slope = ydiff / xdiff;
        }

        return slope;
    }
    double Yint(){
        double yI = 0;
        yI = y1 - (Slope() * x1);
        return yI;
    }

};

int main(){
    Line L1;
    Line L2;
    // Line L2(5,6,7,8);
    cout << "L1: should have all zeros for values" << endl;
    cout << L1 << endl;

    cout << "Enter Two Points For Line: ";
    cin >> L1;
    cout << L1 << endl;
    L1.Display();
    cout << "Enter Two points For Line: "<<endl;
    cin >> L2;
    cout << L2 << endl;
    L2.Display();
    if(L1.getSlope() == L2.getSlope()){
        cout << "Lines are Parralel"<<endl;

    }
    else{
        cout << "Lines are not parralel"<<endl;
    }


    return 0;
}
