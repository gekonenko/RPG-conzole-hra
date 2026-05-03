#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

    int mHP;
    int HP = 1;
    int mmana = 0;
    int mana;
	int dodge = 0;
    int poloha = 0;
    int win = 0;
    int turn = 0;
    int trida = 1;
    string name;
    int stopka;

void turnstart() {
    turn++;
    cout << "______________________" << "\n";
    cout<<"zajdete stopku";
    cin >>stopka;


    cout << HP;
    cout << win;
}

int main() {
    
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

    


    
    if (trida == 1) { //fighter;
        mHP = 40;
        mmana = 10;
        dodge = 10;
        cout << "vase trida je: fighter\n";
        

    }
    if (trida == 2) { //mage;
        mHP = 25;
        mmana = 40;
        dodge = 5;
		cout << "vase trida je: Mage\n";
        
    }
    if (trida == 3) {//zlodej;
        mHP = 20;
        mmana = 25;
        dodge = 35;
        cout << "vase trida je: zlodej\n";
		
    }
    cout << "______________________\n";
    cout << "vase base staty:\nHP:" << mHP << "\nmana: " << mmana << "\ndodge : " << dodge <<"%\n";

 //dodge - chance na dognutí attacku;





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
        turnstart();    

    } while (HP < 0 and win==0);

    cout<<"\n\n\n\n______________________\n";
    if (HP <= 0) {
        cout << " #####   #####  ###    ### #######\n##       ##   ## ####  #### ##     \n##   ### ####### ## #### ## #####  \n##    ## ##   ## ##  ##  ## ##     \n ######  ##   ## ##      ## #######\n\n ######  ##    ## ####### ######   \n##    ## ##    ## ##      ##   ##  \n##    ## ##    ## #####   ######   \n##    ##  ##  ##  ##      ##   ##  \n ######    ####   ####### ##   ##";
    }
    else if (win == 1) {
        cout << "######   #####  ###    ### #######\n##       ##   ## ####  #### ##     \n##   ### ####### ## #### ## #####  \n##    ## ##   ## ##  ##  ## ##     \n ######  ##   ## ##      ## #######\n\n##      ##  ######  ###    ##\n##      ## ##    ## ####   ##\n##   #  ## ##    ## ## ##  ##\n##  ### ## ##    ## ##  ## ##\n ###   ###  ######  ##   ####\n";
    }











}
