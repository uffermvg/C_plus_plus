#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <sstream>
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
        output << "The triangle can be formed: " << T.colinear() << endl << "Area of triangle: " <<T.a<<endl<<"Perimeter of triangle: "<<T.p<<endl<<"The triangles are equalateral: "<<T.e<<endl;
        return output;
    }

    // implement cin for Line classes objects
    friend istream & operator>>( istream &input, Triangle &T ){
        input >> T.P1 >> T.P2>>T.P3;
        return input;
    }

public:
    // Add your functions/methods here //
    Triangle(){
        setX1(x1);
        setX2(x2);
        setY1(y1);
        setY2(y2);
        setX3(x3);
        setY3(y3);
        colinear();


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
        colinear();

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
        if ((x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2))){
            c = 1;
            return c;
        }
        else {
            c = 0;
            return c;
        }
    }
    bool equaladeral(){
        if(L1() == L2() && L1() == L3()){
            e = 1;
            return e;
        }
        else{
            e = 0;
            return e;
        }
    }

private:

    Point P1, P2, P3;
    int x1,x2,y1,y2,x3,y3;
    bool c,e;
   int a,p;


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
        a = .5 * L2() * height();
        return a;
    }
    double perimeter(){
        p = L1() + L2() + L3();
        return p;
    }



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
    // Add your functions/methods here //
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
class Quad {
    // implement cout for Line classes objects
    friend ostream & operator<<( ostream &output, const Quad &Q ){
        output << "Point 1: " << Q.P1 << endl << "Point 2: " <<Q.P2<<endl<<"Point 3: "<<Q.P3<<endl<<"Point 4: "<<Q.P4<<endl;
        return output;
    }

    // implement cin for Line classes objects
    friend istream & operator>>( istream &input, Quad &Q ){
        input >> Q.P1 >> Q.P2>>Q.P3>>Q.P4;
        return input;
    }

public:
    // Add your functions/methods here //
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
            return true;
        }
        else {
            cout << "Quaderlateral can be formed"<<endl;
            return false;
        }
    }


private:

    Point P1, P2, P3, P4;
    int x1,x2,y1,y2,x3,y3,x4,y4;


    double area(){
        double a;
        a = .5 * abs((x1*y2)+(x2*y3)+(x3*y4)+(x4*y1)-(x2*y1) - (x3*y2)-(x4*y3)-(x1*y4));
        return a;
    }




};


vector<double> breakupstring(string str){
    vector<double> numdata;
    stringstream ss;     //requires sstream library included
    ss << str;

    while(!ss.eof()){
        double temp;
        ss >> temp;
        numdata.push_back(temp);
    }

    return numdata;
}


int main(){

    string s1;
    vector<double> numbers;
    ifstream myfile ("example.txt");

    if (myfile.is_open())
    {
      while ( getline (myfile,'/n') )
      {
        s1 << getline(myfile) << '\n';
      }
      myfile.close();
    }
    numbers = breakupstring(s1);

    for(int i = 0; i < numbers.size(); i++){
        cout << numbers.at(i) << endl;
    }
    if(numbers.size() == 4){
        Circle C;

        cin >> C;
        C.Display();

    }
    else if(numbers.size() == 6){
        Triangle T;
        T.Display();
    }
    else if(numbers.size() == 8){
        Quad Q;
        Q.Display();
    }
    else{
        cout << "No shape can be made"<<endl;
    }
    return 0;
}

