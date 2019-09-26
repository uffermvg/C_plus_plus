// Please place your information here
//
#include <iostream>
#include <string>
#include <cctype>
#include <cstring>

using namespace std;

// This prototype is complete
class stringManip {
    public:
        stringManip();
        stringManip(string input);
        string retrieve();
        void setString(string input);
        void chop();
        void padString(int n);
        void center(int length);
        void truncate(int n);
        void removeNonAlpha();
        void convertToUpperCase();
        void convertToLowerCase();
    private:
        string tobeEdited;
};

// Not all functions are defined here

// Default Constructor
stringManip::stringManip(){


}

// Overloaded Constructor
stringManip::stringManip(string in_string){
    cin >> in_string;
    tobeEdited = in_string;
}

// retrieve function
string stringManip::retrieve(){
    string in_string;
    in_string = tobeEdited;
    return in_string;
}
void stringManip::chop(){
    int i = 0;
    while(tobeEdited.at(i) != ' '){
        tobeEdited.erase(i);
        i = i +1;
    }
    while(tobeEdited.at(i) != ' '){
        tobeEdited.erase(i);
        i = i-1;
    }
}

// padString() function
void stringManip::padString(int length){
    int diff;
    if(tobeEdited.size() < length){
        diff = length - tobeEdited.size();
        for (int i= 0; i<diff; i++){
            tobeEdited.push_back(' ');
        }
    }
}

void stringManip::center(int length){
    int num;
    int size;
    num = length - tobeEdited.size();
    size = num/2;
    for(int i =0; i < size;i++){
        tobeEdited.insert(i," ");
        tobeEdited.push_back(' ');
    }
    if(num%2){
        tobeEdited.push_back(' ');
    }

}
void stringManip::truncate(int n){
    tobeEdited.substr(0,n);
}
void stringManip::removeNonAlpha(){
    for (int i = 0; i < tobeEdited.size(); i++){
        if(!isalpha(tobeEdited.at(i)) ){
           tobeEdited.erase(i,1);
        }
    }
}
void stringManip::convertToUpperCase(){
    for(int i= 0; i < tobeEdited.size(); i++){
        toupper(tobeEdited.at(i));
    }
}
void stringManip::convertToLowerCase(){
    for(int i= 0; i < tobeEdited.size(); i++){
        tolower(tobeEdited.at(i));
    }
}

// Add test cases to main()
int main(){
    stringManip S1;
    stringManip S2("testing 123");

    // Test case for padString() You should correct some of your own.
    cout << "S2 before padString(20): <" << S2.retrieve() << ">" << endl;
    S2.padString(20);
    cout << "S2 after padString(20): <" << S2.retrieve() << ">" << endl;
    S2.chop();
    cout << "S2 after chop()): <" << S2.retrieve() << ">" << endl;
    S2.center(20);
    cout << "S2 after center(20): <" << S2.retrieve() << ">" << endl;
    S2.truncate(20);
    cout << "S2 after truncate(10): <" << S2.retrieve() << ">" << endl;
    S2.convertToUpperCase();
    S2.convertToLowerCase();
    cout << "Should be: <testing 123       >" << endl;


    return 0;
}
