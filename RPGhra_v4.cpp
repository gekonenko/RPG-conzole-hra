#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <cmath>


using namespace std;

int mHP;
int HP = 1;
int mmana = 0;
int mana;
int dodge ;
float attack;
float magic_attack;
int gold;
int enemyhp[1] = {50};
int sword_multiplier = 1;
int win = 0;
int trida = 1;
int health_pots = 0;
string name;
int stopka;
int volba;
int pocet_voleb = 3;
int opak;
int hit_For_dodge;
int enemy_dmg []={1};
int enemy_crit []={1};
int enemy_hp []={1};
int enemy_number;

void cstats()
{
    cout << "______________________\n";
    cout << "vase current staty:\nHP:" << mHP << "\nuroven fyzickeho utoku: " << attack << "\nuroven magickeho utoku: " << magic_attack << "\nmana: " << mmana << "\ndodge: " << dodge << "%\n";
    cout << "______________________\n";
}

void select_volba()
{
    cout<< "9)ukazat staty\n";
    volba = 0;
    cout<< "vyerte volbu: ";
    cin >> volba;

    if (volba == 9)
    {
        cstats();
    }

    if (volba <= 0 or (volba > pocet_voleb and volba != 9))
    {
        cout << "neplatna volba, zadejte znovu: ";
    }
}

void shop()
{
    cout << "\n\n\n______________________\n";
    pocet_voleb = 8;
    cout << "nachazite se v obchode:\n";
    cout << "vase zlato: " << gold;
    cout << "\nvyberte si polozku kterou chcete koupit:\n";
    cout << R"(1) mec lvl 1 - 50 gold
2) mec lvl 2 - 100 gold
3) mec lvl 3 - 200 gold
4) dagger lvl 1 - 65 gold
5) dagger lvl 2 - 160 gold
6) spell book lvl 1 - 55 gold
7) spell book lvl 2 - 170 gold
8) vratit se na namesti
)";
    select_volba();
}

void broke_boi()
{
    cout << "\n______________________\n";
    cout << "nemate dostatek zlata\n";

}

void incoming_attack(){
hit_For_dodge = rand() % 100 + 1;
if (hit_For_dodge < dodge){
    cout<<"attack dognut\n";
}else {
        HP=HP-enemy_dmg[enemy_number];
    }
}


int main()
{
    srand(time(0));              // aby bylo generovani nahodneho cisla fr random
    SetConsoleCP(CP_UTF8);       // output asci tabullky
    SetConsoleOutputCP(CP_UTF8); // nevim asci tabulka

    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "Toto je turn-based textove RPG erpegia\n";
    cout << "zadejte jmeno hrace: ";
    cin >> name;

    cout << "zadejte tridu: 1-fighter, 2-mage, 3-thief: ";
    do
    {
        cin >> trida;
        if (trida <= 0 or trida > 3)
        {
            cout << "neplatna trida, zadejte znovu: ";
        }
    } while (trida <= 0 or trida > 3);

    cout << "______________________\n";

    if (trida == 1)
    { // fighter;
        mHP = 40;
        mmana = 10;
        dodge = 10;
        attack = 50;
        magic_attack = 10;
        cout << "vase trida je: fighter\n";
    }
    if (trida == 2)
    { // mage;
        mHP = 25;
        mmana = 40;
        dodge = 5;
        attack = 15;
        magic_attack = 45;
        cout << "vase trida je: Mage\n";
    }
    if (trida == 3)
    { // zlodej;
        mHP = 20;
        mmana = 25;
        dodge = 35;
        attack = 30;
        magic_attack = 30;
        cout << "vase trida je: zlodej\n";
    }

    cout << "vase base staty:\nHP:" << mHP << "\nuroven fyzickeho utoku: " << attack << "\nuroven magickeho utoku: " << magic_attack << "\nmana: " << mmana << "\ndodge : " << dodge << "%\n";

    // dodge - %chance na dognutí attacku;
    cout << "______________________\n";

    if (name == "loser")
    {
        HP = 0;
        win = 0;
    }
    else if (name == "winner")
    {
        HP = 1;
        win = 1;
    }
    else if (name == "cheater")
    {
        HP = 1;
        win = 1;
    }

    pocet_voleb = 3;

    do{
        opak=0;
        do
        {
            cout << "vyberte si co chete delat dale\n1)jit do obchodu\n2)vydat se na cestu\n3)udelat side quest\n";
            select_volba();
            cout << "vase volba: " << volba;
            
                




    } while ((volba == 9) or (volba <= 0) or (volba > pocet_voleb and volba != 9));

    switch (volba)
    {
    case 1:
        volba = 0;
        shop();

        pocet_voleb = 8;
        select_volba;
        

        switch (volba)//jakoby po vyberu veci v shopu
            {
                
                
                case 1:
                if(gold>=50){
                    cout<<"koupil jste mec lvl 1";
                    gold-=50;
                    attack = ceil(attack*1.3); //ceil je od cmath a zaokrouhluje nahoru 
                } else if(gold<50){
                    broke_boi();
                }   
                break;
                
                
                case 2:
                if(gold>=100){
                    cout<<"koupil jste mec lvl 2";
                    gold-=100;
                    attack = ceil(attack*1.6);
                } else if(gold<100){
                    broke_boi();
                }
                break;
                
                
                case 3:
                if(gold>=200){
                    cout<<"koupil jste mec lvl 3";
                    gold-=200;
                    attack = ceil(attack*2);
                } else if(gold<200){
                    broke_boi();
                }
                break;
                
                
                case 4:
                if(gold>=65){
                    cout<<"koupil jste dagger lvl 1";
                    gold-=65;
                    attack = ceil(attack*1.2);
                    magic_attack = ceil(magic_attack*1.2);
                } else if(gold<65){
                    broke_boi();
                }
                break;
                
                
                case 5:
                if(gold>=160){
                    cout<<"koupil jste dagger lvl 2";
                    gold-=160;
                    attack = ceil(attack*1.5);
                    magic_attack = ceil(magic_attack*1.5);
                } else if(gold<160){
                    broke_boi();
                }
                break;
                
                
                case 6:
                if(gold>=55){
                    cout<<"koupil jste spell book lvl 1";
                    gold-=55;
                    magic_attack = ceil(magic_attack*1.3);
                } else if(gold<55){
                    broke_boi();
                }
                break;
                
                
                case 7:
                if(gold>=170){
                    cout<<"koupil jste spell book lvl 2";
                    gold-=170;
                    magic_attack = ceil(magic_attack*1.7);
                } else if(gold<170){
                    broke_boi();
                }
                break;
                
                
                case 8:
                cout<<"vracite se na namesti...";
                
                opak = 1;   
                break;





        break;
            }
    
            case 2:
        cout << "vase volba je: "<<volba;
        break;

    case 3:
        
        
        cout<<R"(
zravím tě dobrodruhu, slyšel jsem že hledáš práci, mám pro tebe úkol.
potřebuju aby si porazil zlého a nevrlého bezdomovce v naší vesnici, jehož jméno je Bob, je to nebezpečný protivník, 
ale pokud ho porazíš, odměním tě zlatem a skušenostmi. Co ty na to?
        
                
1) přijmout úkol
2) odmítnout úkol
)" ;//ten bezdak bude mit high crit chance
    
        pocet_voleb = 2;
        do {
            select_volba();
        } while (volba <= 0 or (volba > pocet_voleb and volba != 9))   ;
        
        if(volba == 2){
        opak = 1;
        cout<< "ukol odmítnut";
        }
    break;
    
    
    
    }

}while (opak == 1);
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    if (HP <= 0)
    { // R"( znamená raw string
        cout << R"(
 ██████   █████  ███    ███ ███████      ██████  ██    ██ ███████ ██████
██       ██   ██ ████  ████ ██          ██    ██ ██    ██ ██      ██   ██
██   ███ ███████ ██ ████ ██ █████       ██    ██ ██    ██ █████   ██████
██    ██ ██   ██ ██  ██  ██ ██          ██    ██  ██  ██  ██      ██   ██
 ██████  ██   ██ ██      ██ ███████      ██████    ████   ███████ ██   ██
)" << "\n";
    }
    else if (win == 1)
    {
        cout << R"(
 ██████   █████  ███    ███ ███████      ██     ██  ██████  ███    ██
██       ██   ██ ████  ████ ██           ██     ██ ██    ██ ████   ██
██   ███ ███████ ██ ████ ██ █████        ██  █  ██ ██    ██ ██ ██  ██
██    ██ ██   ██ ██  ██  ██ ██           ██ ███ ██ ██    ██ ██  ██ ██
 ██████  ██   ██ ██      ██ ███████       ███ ███   ██████  ██   ████
)" << "\n";
    }
    cin >> stopka;

    system("taskkill /F /IM nazev_tveho_programu.exe /T >nul 2>&1"); // ukonci ten process
    return 2;
    





}  