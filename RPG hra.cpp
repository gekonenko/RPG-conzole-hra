#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int HP = 1;
    int mana = 0;
	int dodge = 0;
    int poloha = 0;
    int win = 0;
    int turn = 0;
    int trida;
    string name;
    int stopka;
    cout << "Toto je turn-based textove RPG erpegia\n";

    cout << "zadejte jmeno hrace: ";
    cin >> name;
    
	cout << "zadejte tridu: 1-fighter, 2-mage, 3-thief: ";
    do {
        cin >> trida;
        if (trida <= 0 or trida > 3) {
            cout << "neplatna trida, zadejte znovu: ";
		}
    } while (trida <= 0 or trida > 3);
    
    
   
    cout << "______________________\n";
    if (trida == 1) {
        HP = 40;
        mana = 10;
        int dodge = 3;
        cout << "vase trida je: fighter\n";
        cout << "vase base staty:\nHP:" << HP << "\nmana: " << mana << "\ndodge: " << dodge << "\n";

    }
    if (trida == 2) {
        HP = 25;
        mana = 40;
        int dodge = 5;
		cout << "vase trida je: Mage\n";
        cout << "vase base staty:\nHP:" << HP << "\nmana: " << mana << "\ndodge: " << dodge << "\n";
    }
    if (trida == 3) {
        HP = 20;
        mana = 25;
        int dodge = 15;
        cout << "vase trida je: zlodej\n";
		cout << "vase base staty:\nHP:"  << HP << "\nmana: " << mana << "\ndodge: " << dodge << "\n";
    }
       
           

  
    




    
    if (name == "loser") {
        HP = 0;
        win = 0;

    }else if (name == "winner") {
        HP = 1;
        win = 1;
	}else if (name== "cheater") {
        HP = 1;
        win = 1;
	}
        
    
    
    do {
        turn++;
        cout <<"______________________" << "\n";
        cin >> stopka;
        if (stopka == 0)
            HP = 0;
           

        cout << HP;
        cout << win;
       
    } while (HP > 0 and win==0);

    
    if (HP <= 0) {
        cout << " #####   #####  ###    ### #######\n##       ##   ## ####  #### ##     \n##   ### ####### ## #### ## #####  \n##    ## ##   ## ##  ##  ## ##     \n ######  ##   ## ##      ## #######\n\n ######  ##    ## ####### ######   \n##    ## ##    ## ##      ##   ##  \n##    ## ##    ## #####   ######   \n##    ##  ##  ##  ##      ##   ##  \n ######    ####   ####### ##   ##";
    }
    else if (win == 1) {
        cout << "######   #####  ###    ### #######\n##       ##   ## ####  #### ##     \n##   ### ####### ## #### ## #####  \n##    ## ##   ## ##  ##  ## ##     \n ######  ##   ## ##      ## #######\n\n##      ##  ######  ###    ##\n##      ## ##    ## ####   ##\n##   #  ## ##    ## ## ##  ##\n##  ### ## ##    ## ##  ## ##\n ###   ###  ######  ##   ####\n";
    }











}