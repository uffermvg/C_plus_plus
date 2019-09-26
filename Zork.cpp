/*
 * Project Title:
 * - Zork
 * Description:
 * This program is a Zork game where your goal is to find a trasure chest in a house. You can do this by using items you find along the way
 *
 * Developers:
 * - Veronica Ufferman
 *
 *
 * Special Instructions: // optional
 * *To beat this game perfectly input:
 * (go e
 * take bat
 * break window
 * take flashlight
 * take key
 * open door
 * use key
 * take lockpick
 * go s
 * take crowbar
 * moverug
 * open door
 * use flashlight
 * open chest
 * unlock chest)
 *
 * Developer comments: // Not optional
 * Developer 1:
 * I learned what Zork is and that I am capable of creating a text based game and was able to have doing it.
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool unlock(vector<string> input){
    if(input.at(0) == "use" && input.at(1) == "key"){
        return true;
    }
    else{
        return false;
    }
}
vector<string> pockets(vector<string> inventory, string item){
    inventory.push_back(item);
    return inventory;
}
vector<string> user(vector<string> input){
    cin >> input.at(0)>>input.at(1);
    return input;
}
bool doYouHaveIt(vector<string> inventory, string item){
    int test = 0;
    for(int i = 0; i < inventory.size(); i++){
        if(inventory.at(i) == item){
            test = 1;
            break;
        }
    }
    if(test == 1){
        return true;
    }
    else{
        return false;
    }
}
bool direction(vector<string> input){
    if(input.at(0)=="go"){
        return true;
    }
    else{
        return false;
    }
}
void start(){
    cout <<"Welcome to Zork!" <<endl<<"Legend has it that there is a chest full of treasure hidden somewhere in a house nearby"<<endl;
    cout<<"As a amature treasure humter yourself you have decided to take it upon yourself to find this fabled treasure,"<<endl;
    cout <<"but be careful for there are deadly goblins who come out in the dark"<<endl;
    cout<<"Instructions: "<<endl;
    cout<<"movement- first type go then, north(n), south(s), east(e), west(w), up(u), down(d)"<<endl;
    cout<<"Actions- go, break, open, take, move, use"<<endl;
    cout<<"Type quit game to quit the game"<<endl;
    cout << "There is a small house to your north, surrounding the house on all side is a dense forrest"<<endl;
}
bool forrest(vector<string> input){
    cout <<"You have chosen to walk into an endless forrest, it is pitch dark and you are unable to see your own hand" <<endl;
    cout<<"If you dont turn back now you will be eaten by goblins"<<endl;
    input = user(input);

    if (input.at(1) != "n"){
        cout << "You have been eaten by goblins and have died"<<endl;
        return true;
    }
    else{
        return false;
    }
}

void house(vector<string> input,int &location, vector<string> &inventory){
    string item = "baseballbat";
    cout << "You walk up the front of the house and arrive at a door that appears to have been boarded shut, "<<endl;
    cout<<"there appears to be a window on the east side of the house"<<endl;
    input = user(input);
    if(input.at(0) == "quit"){
        location = 6;
    }
    else if (direction(input) == true){
        if(input.at(1) == "n"){
           cout << "You cannot go that way"<<endl;
        }
        else if(input.at(1) == "s"){
            if(forrest(input) == true)
               location = 1;
        }
        else if (input.at(1) == "e"){
            cout << "You are now on the east side of the house. \n you see a baseball bat lying in the grass and a closed window"<<endl;
            input = user(input);
            if(input.at(0) == "take"){
                if(input.at(1) == "baseball" || input.at(1) == "bat"){
                    inventory = pockets(inventory, item);
                    cout << "You have taken the baseball bat"<<endl;
                    input = user(input);
                    if(input.at(0) == "break" && input.at(1) == "window"){
                        if(doYouHaveIt(inventory, item)){
                            cout <<"You have broken the window and in doing so fall through the window"<<endl;
                            location = 2;
                        }

                    }
                }
              }
         }
                    else if(direction(input) == true){
                        if(input.at(1) == "w"){
                            cout << "There is a boarded up window, the back of the house is to your east"<<endl;
                            input = user(input);
                            if(direction(input) && input.at(1) == "e"){
                                cout << "You stand at the back of the house it is empty there isnt even a door"<<endl;
                                input = user(input);
                                if(direction(input) && input.at(1) == "e"){
                                    cout << "You are now on the east side of the house. \n you see a baseball bat lying in the grass and a closed window"<<endl;
                                 while(location == 0 && input.at(0) != "go"){
                                    input = user(input);
                                    if(input.at(0) == "take"){
                                        if(input.at(1) == "baseball" || input.at(1) == "bat"){
                                            inventory = pockets(inventory, item);
                                            cout << "You have taken the baseball bat"<<endl;
                                            input = user(input);
                                            if(input.at(0) == "break" && input.at(1) == "window"){
                                                if(doYouHaveIt(inventory, item)){
                                                    cout <<"You have broken the window and in doing so fall through the window"<<endl;
                                                    location = 2;
                                                }

                                            }

                                        }
                                    }
                                    else if(direction(input)){
                                        forrest(input);
                                    }
                                    else{
                                        cout << "You cannot do that"<<endl;
                                    }
                                }

                            }
                        }
                            }

                }
    }

        if(input.at(0) == "take"){
            cout << "You cannot take that"<<endl;

        }
    }


void livingroom(vector<string> input, int &location, vector<string> &inventory){
    cout << "You fall through the window into a small living room \n looking around you see a flashlight, and a small brass key"<<endl;
    cout <<"To your west there is an open door, to you south a closed door and the broken window is to the north of you"<<endl;
    string item1 = "flashlight";
    string item2 = "key";
    while(input.at(0) != "quit" && location == 2){
        input = user(input);
        if(input.at(0) == "take"){
                if (input.at(1) == "flashlight" || input.at(1) == "key"){
                    cout << "You have successfully taken the item"<<endl;
                    if(input.at(1) == "flashlight"){
                        inventory = pockets(inventory,item1 );
                    }
                    else {
                        inventory = pockets(inventory, item2);
                    }
                }
                else{
                    cout << "You cannot take that"<<endl;
                }
        }
        else if(input.at(0) == "open" && input.at(1) == "door"){
            cout << "The door is locked what can you use to open it?"<<endl;
            input = user(input);
            if(input.at(0) == "use" && input.at(1) == "key"){
                if(doYouHaveIt(inventory,item2)){
                    location = 5;
                }
                else{
                    cout << "The door appears to be locked"<<endl;
                }
            }
        }
        else if(direction(input)){
            if(input.at(1) == "n"){
                cout << "You try to climb back out of the window by the glass is too sharp and the window is too high"<<endl;
            }
            else if (input.at(1) == "s"){
                if(unlock(input) == true){
                    location = 4;
                }
                else{
                    cout << "The door is locked"<<endl;
                }
            }
            else if (input.at(1) == "w"){
                location = 3;
            }
            else {
                cout << "You can not go that way"<<endl;
            }
        }
        else {
            cout << "You cannot do that"<<endl;
        }


    }

}

void kitchen(vector<string> input, int &location, vector<string> &inventory){
    cout << "You enter a small kitchen, looking around you see a cabinet a thick rug and a crowbar sitting on the table"<<endl;
    cout <<"The door you came in is behind you to the east"<<endl;
    string item = "crowbar";
    while(input.at(0) != "quit" && location == 3){
        input = user(input);
        if(direction(input)){
            if(input.at(1) == "e"){
                location = 2;
            }
            else{
                cout << "You cannot go that way"<<endl;
            }
        }
        else if(input.at(0) == "take"){
            if(input.at(1) == "crowbar"){
                cout << "You take the crowbar"<<endl;
                inventory = pockets(inventory, item);
            }
            else{
                cout << "You cannot take that"<<endl;
            }
        }
        else if(input.at(0) == "move"){
            if(input.at(1) == "rug"){
                cout << "You move the rug and see a trap door"<<endl;
                input = user(input);
                if(input.at(0) == "open" && input.at(1) == "door"){
                    cout << "The trap door appears to be stuck shut is there anything you can use to open it?"<<endl;
                    input = user(input);
                    if(input.at(0) == "use" && input.at(1) == "crowbar"){
                        if(doYouHaveIt(inventory,item)){
                            location = 4;
                        }
                        else{
                            cout << "You don't have that item"<<endl;
                        }
                    }

                }
            }
        }
        else{
            cout << "You cannot do that"<<endl;
        }
     }

}
void cellar(vector<string> input, int &location, vector<string> &inventory){
    string item = "flahslight";
    string item2 = "lockpick";
    inventory = pockets(inventory, item);
     if(doYouHaveIt(inventory, item) == false){
             cout << "It is too dark to see, if you don't leave or find a light the goblins will find you"<<endl;
             input = user(input);
             if(direction(input)){
                 if(input.at(1) != "up"){
                     cout <<"You have died the goblins have eaten you"<<endl;
                     cout << "You Have Lost"<<endl;
                     input.at(0) = "quit";
                     location = 6;
                 }
                 else{
                     location = 3;
                 }
             }
     }
     else{
         cout << "It is very dark do you have anything you could use anyhting to light it up"<<endl;
         input = user(input);

         if(input.at(0)=="use" && input.at(1) == "flashlight"){
             cout <<"You turn on the flash light and the room is flooded with light and you are now able to see"<<endl;
             cout <<"You are in a dark damp cellar it is empty except for a large chest in the corner of the room"<<endl;
             if(doYouHaveIt(inventory, item2)){
                 input = user(input);
                 if(input.at(0) == "open" && input.at(1) == "chest"){
                     cout << "The chest appears to be locked, can you think of somehting that can open it"<<endl;
                     input = user(input);
                     if(input.at(0) == "use" && input.at(1) == "lockpick"){
                        cout << "You open the chest and find it filled with coins"<<endl;
                        location = 6;
                     }
                 }
                 else if(direction(input) && input.at(1) == "up"){
                     location = 3;
                 }
                 else{
                     cout << "You cannot do that"<<endl;
                 }
             }
         }
         else if(direction(input)){
             if(input.at(1) == "up"){
                 location = 3;
             }
         }
         else{
             cout << "You cannot do anything until you can see"<<endl;
         }
     }
}
void bedroom(vector<string> input, int &location, vector<string> &inventory){
    cout << "You are in a small bedroom with a small bare bed and a dresser, there is a door to you east and one to your south"<<endl;
    cout << "On the dreeser you see what looks like a lockpick"<<endl;
    string item = "lockpick";

    while(input.at(0) != "quit" && location == 5 ){
        input = user(input);
        if(input.at(0) == "quit"){
            location = 6;
        }
        if(input.at(0) == "take"){
            if(input.at(1) == "lockpick"){
                cout << "You now have a lockpick congrats"<<endl;
                inventory = pockets(inventory,item);
            }
            else{
                cout << "You cannot take that"<<endl;
            }
        }
        else if(direction(input)){
            if(input.at(1) == "s"){
                location = 3;
            }
            else if(input.at(1) == "e"){
                location = 2;
            }
            else{
                cout << "You cannot go that way"<<endl;
            }
        }
        else{
             cout << "You cannot do that"<<endl;
            }

      }

}

int main()
{
    start();
    vector<string> input(2);
    vector<string> inventory;
    int location = 0;
    while(input.at(0) != "quit"){
        switch(location){
        case 0:
            house(input, location, inventory);
            break;
        case 1:
            if(forrest(input)){
                input.at(0) = "quit";
            }
            break;
        case 2:
            livingroom(input, location, inventory);
            break;
        case 3:
            kitchen(input, location, inventory);
            break;
        case 4:
            cellar(input, location, inventory);
            break;
        case 5:
            bedroom(input, location, inventory);
            break;
        default:
            input.at(0) = "quit";
            break;
        }

    }
    cout <<"THE END"<<endl;
    return 0;
}
