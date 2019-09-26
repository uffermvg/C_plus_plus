#include <iostream>
#include <vector>



using namespace std;


int Random(){
    int N;
    srand(16);
    N = rand() % (15);
    return N;
}

int Ymovement(int uy, char User){
    if (User == 'w'){
       uy = uy + 1;
    }
    else if (User == 's'){
        uy = uy -1;
    }
    return uy;

}
int Xmovement(int ux, char User){
    if(User == 'a'){
        ux = ux - 1;
    }
    else if (User == 'd'){
        ux = ux + 1;
    }
    return ux;
}



int main()
{
    char quit = 'o';
    char A [14][14],direction;
    char Elon = '$';
    char yugo = '@';
    char Pinto = '*';
    char Roadster = '#';
    char User = '&';
    int yx = Random();
    int yy = Random();
    int p = Random();
    int r = Random();
    int ex = Random();
    int ey = Random();
    int uy = Random();
    int ux = Random();
    int count = 0;
    int win = 0;
    int lose = 0;

    for(int i = 0; i < 14; i++){
        for (int j =0; j< 14; j++){
            A[i][j]= '_';
        }
    }
    //cout << ey << endl << ex << endl<< uy<<endl << ux<< Random()<<endl;
    A[ex][ey] = Elon;
    while(quit != 'x'){
        if(A[ex][ey] != Elon){
            A[ex][ey] = Elon;
            break;
        }
        if(A[yx][yy] != Elon){
            A[yx][yy] = yugo;
            break;
        }
        else{
            yx = Random();
            yy = Random();
        }

    }
    while(quit != 'x'){
        if(A[p][p] != Elon && A[p][p] != yugo){
            A[p][p] = Pinto;
            break;
        }
        else{
            p = Random();
        }
    }
    while(quit != 'x'){
        if(A[r][r] != Elon && A[r][r] != yugo && A[r][r] != Pinto){
            A[r][r] = Roadster;
            break;
        }
        else{
        r = Random();
        }
    }
    while(quit != 'x'){
        if(A[ux][uy] != Elon && A[ux][uy] != yugo && A[ux][uy] != Pinto&& A[ux][uy] != Roadster){
            A[ux][uy] = User;
            break;
        }
        else{
        ux = Random();
        uy = Random();
        }
    }

    cout << "Welcome to the game"<<endl<<"Elon Musk is asleep some where in this room you must avoid waking him"<<endl;

    while (direction != 'x' || direction != 'X')
    {
        count = count + 1;

        cout << "Use w,a,s,d to navigate the room."<<endl<<"Press x to quit the game" << endl;
        for (int j = 1; j > -2; j--){
            for(int i = -1; i < 2; i++){
                cout << A[ux + i][uy + j];
            }
            cout << endl;
        }
        cin >> direction;
        if (direction == 'x' || direction == 'X'){
            break;
        }

        else if (direction == 'w' || direction == 's'){
            A[ux][uy] = '_';
            uy = Ymovement(uy, direction);
            A[ux][uy] = User;
            if((direction == 'w' && r > uy) || (direction == 's' && r < uy)){
                 cout << "You are getting warmer"<<endl;
            }
             else{
                  cout << "You are getting colder"<<endl;
            }
            }
            if (direction == 'a'||direction == 'd'){
                A[ux][uy] = '_';
                ux = Xmovement(ux, direction);
                if (A[ux][uy] == Elon||A[ux][uy]==yugo||A[ux][uy]==Pinto){
                    lose = lose +1;
                    cout << "You have been caught and sent into space to become starman"<<endl;
                    cout << "The End"<< endl<<"You have been caught by Elon Musk and have become Starman"<<endl;
                    cout << "Would you like to play again?" << endl << "If not please press x to quit the game, otherwsie press y"<<endl;

                    if(direction == 'x' || direction == 'X'){
                        break;
                    }
                }
                else if(A[ux][uy] == Roadster){
                    win = win +1;
                    cout << "It took you  "<<count<<" turns to find the roadster"<<endl;
                    cout << "You have found the roadster and escaped"<<endl;
                    break;
                }
                else{
                    A[ux][uy]= User;
                }
                if((direction == 'a' && r > uy) || (direction == 'd' && r < uy)){
                    cout << "You are getting warmer"<<endl;
                }
                else{
                  cout << "You are getting colder"<<endl;
                }
                if(count >= 3){
                    A[ex][ey] = '_';
                    ex = Random();
                    ey = Random();
                    A[ex][ey]=Elon;
               }
            }

       }

    cout << "You became Starman "<< lose<< " times"<<endl << "You found the roadster "<< win << " times"<<endl;
return 0;
}
