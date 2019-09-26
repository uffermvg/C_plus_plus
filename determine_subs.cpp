#include <iostream>

using namespace std;

string determineSubstance(double bp){
    string substance;
    if (bp >= 95 && bp <= 105){
        substance = "Water";
    }
    else if (bp >= 339.15 && bp <= 374.85){
        substance = "Mercury";
    }
    else if (bp >= 2193 - (2193 * .05) && bp <= 2193 + (2193 * .05)){
        substance = "Silver";
    }


    else if (bp >= 1187 - (1187 * .05) && bp <= 1187 + (1187 * .05)){
        substance = "Copper";
    }
    else if (bp >= 2660 - (2660 * .05) && bp <= 2660 + (2660*.05)){
        substance = "Gold";
    }
    else {
        substance = "Unknown";
    }
    return substance;
}

int main() {  //NO NEED TO CHANGE THIS
    double bp = 100;
    cout << "Substance function returns: " << determineSubstance(bp)
         << " for a temperature of " << bp << " Should be Water" << endl;
    bp = 350;
    cout << "Substance function returns: " << determineSubstance(bp)
         << " for a temperature of " << bp << " Should be Mecury" << endl;
    bp = 2100;
    cout << "Substance function returns: " << determineSubstance(bp)
         << " for a temperature of " << bp << " Should be Silver" << endl;
    bp = 1100;
    cout << "Substance function returns: " << determineSubstance(bp)
         << " for a temperature of " << bp << " Should be Unknown" << endl;
    bp = 1150;
    cout << "Substance function returns: " << determineSubstance(bp)
         << " for a temperature of " << bp << " Should be Copper" << endl;
    bp = 2600;
    cout << "Substance function returns: " << determineSubstance(bp)
         << " for a temperature of " << bp << " Should be Gold" << endl;
    bp = 11000;
    cout << "Substance function returns: " << determineSubstance(bp)
         << " for a temperature of " << bp << " Should be Known" << endl;
    return 0;
}
