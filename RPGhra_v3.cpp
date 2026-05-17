#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

    int mHP;
    int HP = 1;
    int mmana = 0;
    int mana;
	int dodge = 0;
    int attack;
    int magic_attack;
    int gold;
    int enemyhp [1]={50};
    int win = 0;
    int trida = 1;
    string name;
    int stopka;
    int volba;
    int pocet_voleb = 3;
    int opak;

    void cstats (){
        cout<<"______________________\n";
        cout << "vase current staty:\nHP:" << mHP <<"\nuroven fyzickeho utoku: "<<attack<<"\nuroven magickeho utoku: "<<magic_attack <<"\nmana: " << mmana << "\ndodge: " << dodge <<"%\n";
        cout<<"______________________\n";

    }
    void select_volba (){

        do {
        
        cin >> volba;
        
        if (volba==9){
            cstats();
            opak=1;
        }
        
        if (volba <= 0 or volba > pocet_voleb and volba!=9) {
            cout<<"neplatna volba, zadejte znovu: ";
            opak=1;
		}

    } while (opak==1 );
    
}
    void shop (){
    cout<<"______________________\n";
    pocet_voleb=8;
    cout<<"nachazite se v obchode:\n";
    cout<<"vase zlato: "<<gold;
    cout<<"\nvyberte si polozku kterou chcete koupit:\n";
    cout<<"1) mec lvl 1 - 50 gold\n2) mec lvl 2 - 100 gold\n3) mec lvl 3 - 200 gold\n4)dagger lvl 1 - 65 gold\n5)dagger lvl 2 - 160 gold\n6) spell book lvl 1 - 55 gold\n7) spell book lvl 2 - 170 gold\n8)healing potionc - 10 gold";




    }

int main() {
    SetConsoleOutputCP(CP_UTF8);    //output asci tabullky
    SetConsoleCP(CP_UTF8);          //output asci tabullky
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
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
    
    if (trida == 1) { //fighter;
        mHP = 40;
        mmana = 10;
        dodge = 10;
        attack=50;
        magic_attack=10;
        cout << "vase trida je: fighter\n";
        

    }
    if (trida == 2) { //mage;
        mHP = 25;
        mmana = 40;
        dodge = 5;
        attack = 15;
        magic_attack=45;
		cout << "vase trida je: Mage\n";
        
    }
    if (trida == 3) {//zlodej;
        mHP = 20;
        mmana = 25;
        dodge = 35;
        attack=30;
        magic_attack=30;
        cout << "vase trida je: zlodej\n";
		
    }
    
    cout << "vase base staty:\nHP:" << mHP <<"\nuroven fyzickeho utoku: "<<attack<<"\nuroven magickeho utoku: "<<magic_attack <<"\nmana: " << mmana << "\ndodge : " << dodge <<"%\n";

 //dodge - chance na dognutí attacku;
    cout<<"______________________\n";




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


   cout<<"vyberte si co chete delat dale\n1)jit do obchodu\n2)vydat se na cestu\n3)udelat side quest\n9) ukazat staty";
   select_volba();

    
    
     
    switch (volba){
        case 1:
        shop();


        break;
        
        
        case 2:
        cout<<"vase volba je 2";
        break;
        
        
        
        case 3:
        cout<<"vase volba je 3";

        break;
    }


    
    
    
    
    
    
    
    
    
    
    
    
    

    
    

if (HP <= 0) {      // R"( znamená raw string
cout << R"(                 
 ██████   █████  ███    ███ ███████      ██████  ██    ██ ███████ ██████  
██       ██   ██ ████  ████ ██          ██    ██ ██    ██ ██      ██   ██ 
██   ███ ███████ ██ ████ ██ █████       ██    ██ ██    ██ █████   ██████  
██    ██ ██   ██ ██  ██  ██ ██          ██    ██  ██  ██  ██      ██   ██ 
 ██████  ██   ██ ██      ██ ███████      ██████    ████   ███████ ██   ██ 
)" << "\n";
}
else if (win == 1) {
cout << R"(
 ██████   █████  ███    ███ ███████      ██     ██  ██████  ███    ██ 
██       ██   ██ ████  ████ ██           ██     ██ ██    ██ ████   ██ 
██   ███ ███████ ██ ████ ██ █████        ██  █  ██ ██    ██ ██ ██  ██ 
██    ██ ██   ██ ██  ██  ██ ██           ██ ███ ██ ██    ██ ██  ██ ██ 
 ██████  ██   ██ ██      ██ ███████       ███ ███   ██████  ██   ████ 
)" << "\n";
}





}
