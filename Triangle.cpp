#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cmath>

using namespace std;


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


class Triangle {
    // implement cout for Line classes objects
    friend ostream & operator<<( ostream &output, const Triangle &T ){
        output << "Point 1: " << T.P1 << endl << "Point 2: " <<T.P2<<endl<<"Point 3: "<<T.P3<<endl;
        return output;
    }

    // implement cin for Line classes objects
    friend istream & operator>>( istream &input, Triangle &T ){
        input >> T.P1 >> T.P2>>T.P3;
        return input;
    }

public:
   
    Triangle(){
        setX1(x1);
        setX2(x2);
        setY1(y1);
        setY2(y2);
        setX3(x3);
        setY3(y3);


    }
    Triangle(int x1, int y1, int x2, int y2, int x3, int y3, Point P1, Point P2, Point P3){
        setX1(x1);
        setX2(x2);
        setY1(y1);
        setY2(y2);
        setX3(x3);
        setY3(y3);
        setP1(0);
        setP2(0);
        setP3(0);

    }
    Point getP1(){
        return P1;
    }
    Point getP2(){
        return P2;
    }
    Point getP3(){
        return P3;
    }
    void setX3(int x){
        x3 = x;
    }
    void setY3(int y){
        y3 = y;
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
    void setP3(Point in_P3(int x3, int y3)){
        P3 = in_P3(x3,y3);
    }
    void Display(){
        cout << "The area of the triangle: "<<area()<<endl;
        cout << "The perimeter of the triangle: "<<perimeter()<<endl;
    }



    bool operator==(Triangle T2){
        if((P1 == T2.P1) && P2 == T2.P2 && P3 == T2.P3){
            return true;
        }
        else {
            return false;
        }
    }
    bool colinear(){
        if (!(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2))){
            cout << "Triangle cannot be formed"<<endl;
            return true;
        }
        else {
            cout << "Triangle can be formed"<<endl;
            return false;
        }
    }
    bool equaladeral(){
        if(L1() == L2() && L1() == L3()){
            cout << "The triangle is equaladeral"<<endl;
            return true;
        }
        else{
            cout << "The triangle is not equaladeral"<<endl;
            return false;
        }
    }

private:

    Point P1, P2, P3;
    int x1,x2,y1,y2,x3,y3;

    double L1(){
        double l1;
        l1 = sqrt(pow((P2.getX() - P1.getX()),2)+ pow((P2.getY() - P1.getY()),2));
        return l1;
    }
    double L2(){
        double l2;
        l2 = sqrt(pow((P3.getX() - P2.getX()),2)+ pow((P3.getY() - P2.getY()),2));
        return l2;
    }
    double L3(){
        double l3;
        l3 = sqrt(pow((P3.getX() - P1.getX()),2)+ pow((P3.getY() - P1.getY()),2));
        return l3;
    }
    double height(){
        double h;
        h = sqrt(pow(L1(),2) - pow(((1/2) * L2()),2));
        return h;
    }

    double area(){
        double a;
        a = .5 * L2() * height();
        return a;
    }
    double perimeter(){
        double p;
        p = L1() + L2() + L3();
        return p;
    }



};


int main(){
    Triangle T1;
    Triangle T2;


    cout << "Enter Three Points For Triangle 1: ";
    cin >> T1;
    cout << T1 << endl;
    if(T1.colinear()){
        cout << "Triangle cannot be made"<<endl;
    }
    else{
        T1.equaladeral();
        T1.Display();
    }
    cout << "Enter Three points For Triangle 2: "<<endl;
    cin >> T2;
    cout << T2 << endl;
    if(T2.colinear()){
        cout << "Triangle cannot be made"<<endl;
    }
    else{
        T2.equaladeral();
        T2.Display();
    }
    if(!(T1.colinear() && T2.colinear())){
        if(T2 == T1){
            cout << "Triangles are the same"<<endl;
        }
        else{
            cout << "Triangles are not the same"<<endl;
        }
    }

    return 0;
}
