#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int rolldie(){
    int die;
    srand(time(NULL));
    die = rand() % 7;
    if(die ==0)
        die = 1;

    return die;
}
int first(){
    int guess;
    int die= 0;
    int win = 0;
    int lose = 0;

    char input = 'y';
    cout << "Please input a value from 1 - 6"<< endl;
    cin >> guess;
    die = rolldie();
    while (input != 'X'){
        if (guess == die){
          win = win + 1;
          cout << "Wins: "<<win<<endl<<"Losses: "<<lose<<endl;
        }
        else {
            lose = lose + 1;
            cout << "Wins: "<<win<<endl<<"Losses: "<<lose<<endl;
        }
        die = rolldie();
        cout << "Please input a value from 1 - 6"<< endl;
        cin >> guess;
        cout << "Would you like to stop? If so please type X, if not type y."<<endl;
        cin >> input;
    }
    cout << "Wins: "<<win<<endl<<"Losses: "<<lose<<endl;

    return 0;
}
bool playOnegame(int guess){
    int die= 0;
    cout << "Please input a value from (1 - 6): ";
    cin >> guess;
    die = rolldie();

    if (guess == die){

        return true;
    }
    else {

        return false;
    }
}
bool threeRolls(int guess){
    int count = 1;
    bool win;
    while (count <=3){
        if(playOnegame(guess) == true){
            cout << "Roll #"<<count<<" is "<<rolldie()<<endl <<"**win**"<<endl;
            win = true;
            cout <<"**You Win**"<<endl;
            break;

        }
        else {
            cout << "Roll #"<<count<<" is "<<rolldie()<<endl;
            win = false;

        }
        count = count +1;
    }
    if(win == false)
        cout <<"**You Lose**"<<endl;
    return win;

}
double wagerGame(int guess){
    double money = 100.00;
    double wager = 1;
    int win = 0;
    int lose = 0;
    int count = 0;
    int per;
    while (wager != 0 && money >0){
        cout << "Account Balance: "<<money<<endl<<"Enter a wager (0 to exit): "<<endl;
        cin >> wager;
        if (wager == 0)
            break;
        if(wager > money || wager < 0){
            cout << "The wager is invalid, please make another wager: "<<endl;
            cin >> wager;
        }
        else {
            if(threeRolls(guess) == true){

                money = money + wager;
                win = win +1;
            }
            else{

                money = money - wager;
                lose = lose + 1;
            }
            count = count +1;
        }
    }
    per =(win / count) * 100;
    if(money < 0){
        cout << "Game over, you are out of money!"<<endl;
    }

    cout << "Your final balance was: $"<<money<<endl;
    cout << "You won "<<win<<" out of "<< count <<" for a winning percentage of "<<per<<"%"<<endl;


    return money;

}



int main()
{

    int guess;
    wagerGame(guess);
    //playOnegame(guess);
    return 0;
}
