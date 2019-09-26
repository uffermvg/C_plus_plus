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


class Quad {
    // implement cout for Line classes objects
    friend ostream & operator<<( ostream &output, const Quad &Q ){
        output << "Area: " << Q.a << endl << "Is the Quadalateral colinear: " <<Q.c<<endl;
        return output;
    }

    // implement cin for Line classes objects
    friend istream & operator>>( istream &input, Quad &Q ){
        input >> Q.P1 >> Q.P2>>Q.P3>>Q.P4;
        return input;
    }

public:
    
    Quad(){
        setX1(x1);
        setX2(x2);
        setY1(y1);
        setY2(y2);
        setX3(x3);
        setY3(y3);
        setX4(x4);
        setY4(y4);


    }
    Quad(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
        setX1(x1);
        setX2(x2);
        setY1(y1);
        setY2(y2);
        setX3(x3);
        setY3(y3);
        setX4(x4);
        setY4(y4);
        setP1(0);
        setP2(0);
        setP3(0);
        setP4(0);
        area();

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
    Point getP4(){
        return P4;
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
    void setX4(int x){
        x4 = x;
    }
    void setY4(int y){
        y4 = y;
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
    void setP4(Point in_P4(int x4, int y4)){
        P4 = in_P4(x4,y4);
    }

    void Display(){
        cout << "The area of the quadralateral: "<<area()<<endl;
    }



    bool operator==(Quad T2){
        if((P1 == T2.P1) && P2 == T2.P2 && P3 == T2.P3){
            return true;
        }
        else {
            return false;
        }
    }
    bool colinear(){
        if ((x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2) == 0 ||x2*(y3-y4)+x3*(y4-y2)+x4*(y2-y3) == 0||x1*(y3-y4)+x3*(y4-y1)+x4*(y3-y1) == 0|| x1*(y2-y4)+x2*(y4-y1)+x4*(y1-y2) == 0)){
            cout << "Quadrilateral cannot be formed"<<endl;
            c = true;
            return c;
        }
        else {
            cout << "Quaderlateral can be formed"<<endl;
            c = false;
            return c;
        }
    }
    double area(){
        a = .5 * abs((x1*y2)+(x2*y3)+(x3*y4)+(x4*y1)-(x2*y1) - (x3*y2)-(x4*y3)-(x1*y4));
        return a;
    }


private:

    Point P1, P2, P3, P4;
    int x1,x2,y1,y2,x3,y3,x4,y4;
    double a;
    bool c;




};


int main(){
    Quad Q1;
    Quad Q2;


    cout << "Enter four Points For Quadralateral 1: ";
    cin >> Q1;
    //cout << Q1 << endl;
    if(Q1.colinear()){
        cout << "Quaderlateral cannont be formed"<<endl;
    }
    else{

        Q1.Display();
    }
    cout << "Enter four points For Quadralateral 2: "<<endl;
    cin >> Q2;
    //cout << Q2 << endl;
    if(Q2.colinear()){
        cout << "Quaderlateral cannont be formed"<<endl;
    }
    else{

        Q2.Display();
    }


    return 0;
}
