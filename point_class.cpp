#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

// Please complete this Point class.
// The cin/cout operators have been overloaded for you
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

int main(){
    Point P1;
    Point P2(7,6);
    cout << "Point P1 should have 0,0 as values" << endl;
    cout << P1 << endl;
    cout << "Point P2 should have 7,6 as values" << endl;
    cout << P2 << endl;

    cout << "Enter x and y points: ie 3 4 ";
    cin >> P1;
    cout << P1 << endl;

    return 0;
}
