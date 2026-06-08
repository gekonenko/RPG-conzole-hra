#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <cmath>
#include <chrono>

using namespace std;

int mHP;
float HP = 1;
int mmana = 0;
float mana;
int dodge;
float attack;
float magic_attack;
float gold;
int gold_multiplier = 1;
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
int hit_for_crit;
int rand_for_gold;
// Indexy v polích odpovídají těmto nepřátelům:
// 0: Bob (Sidequest ve vesnici)
// 1: Divoký ruličkář z Rumunska (Les)
// 2-3: Roman a Radek (Ústí nad Labem - skupina 2)
// 4: Bezdomovec v Ústí (Sidequest 2)
// 5-7: 3 žebrající holubi (Cesta - skupina 3)
// 8: Divoký cyklozmrd (Miniboss 1)
// 9-10: 2 zlobiví zajíci (Cesta - skupina 2)
// 11: Zlobivý krakonoš (Miniboss 2)
// 12-14: Ruličkáři v Berlíně (Berlín - skupina 3)
// 15-16: Policajti (Finální souboj - skupina 2)
int enemy_dmg[] =               {  4,  3,  4,  4,  5,  3,  3,  3, 12,  7,  7, 18, 10, 10, 10, 14, 14};
int enemy_crit[] =              { 35, 10,  5,  5, 15, 10, 10, 10, 15, 10, 10, 20, 10, 10, 10, 15, 15};
int enemy_hp[] =                { 80, 100, 100, 150, 55, 30, 30, 30, 200, 70, 65, 500, 90, 90, 90, 200, 200};
int enemy_xp[] =                { 10, 10, 15, 15, 10,  7,  7,  7, 20, 15, 15, 30, 15, 15, 15, 25, 25};
int enemy_gold[] =              { 25, 20, 25, 25, 30,  5,  5,  5, 60, 20, 20, 80, 40, 40, 40, 100, 100};
int enemy_gold_dorpchance[] =   {100, 90, 85, 85, 100, 30, 30, 30, 100, 40, 40, 100, 90, 90, 90, 100, 100};
int cil;
int zbyvaji_nepratele;
int enemy_number;

int number_of_enemies;
int target;
int cislo_nepritele;
int boss;
int opak2;
int cooldown;
int xp;
int level = 1;
int dmg;
int sidequest_done = 0;
int x;//mam for loop a v nem funkci, to je jako t i v foru



int boss_hp;
int random_cislo;
int random_cislo2;
int boss_max_hp;
int boss_atk;
float boss_def;
int boss_crit;
int boss_regen;


int last_effect;
int effect_multiplier;
int player_consecutive_hits;


int stolen_stat_type;
int stolen_duration;
float original_stat;


float player_base_atk;
float player_base_magic;


float base_dmg;
int final_dmg;
float incoming_dmg;

void cstats()
{
    cout << "\n______________________\n";
    cout << "vase current staty:\nHP:" << mHP << "\nuroven fyzickeho utoku: " << attack << "\nuroven magickeho utoku: " << magic_attack << "\nmana: " << mmana << "\ndodge: " << dodge << "%\n";
    cout << "\n______________________\n";
}


void ccstats()
{
    cout << "\n______________________\n";
    cout << "\nvase current staty: " << "Hp:" << HP << ", Mana:" << mana;
    cout << "\n______________________\n";
}

void level_up()

{
    if (xp >= 20)
    {
        level++;
        xp = 0;
        mHP = mHP + 5;
        mmana = mmana + 5;
        attack = attack + 5;
        magic_attack = magic_attack + 5;
        cout << "postoupil jste na level " << level << "!\n";
        
    }
}

void select_volba()
{
    do
    {

        volba = 0;
        cout << "vyerte volbu: ";
        cin >> volba;

        if (volba <= 0 or volba > pocet_voleb)
        {
            cout << "neplatna volba, zadejte znovu: \n";
        }
    } while (volba <= 0 or volba > pocet_voleb);
}

void broke_boi()
{
    cout << "\n______________________\n";
    cout << "nemate dostatek zlata\n";
    opak = 1;
}

void shop()
{

    cout << "\n\n\n______________________\n";
    pocet_voleb = 9;
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
8) armour - 20 gold; 
9)vratit se na namesti
)";
    
    select_volba();

    opak = 0;
    switch (volba) // jakoby po vyberu veci v shopu
    {

    case 1:
        if (gold >= 50)
        {
            cout << "koupil jste mec lvl 1";
            gold -= 50;
            attack = ceil(attack * 1.3); // ceil je od cmath a zaokrouhluje nahoru
            opak = 1;
        }
        else if (gold < 50)
        {
            broke_boi();
        }
        break;

    case 2:
        if (gold >= 100)
        {
            cout << "koupil jste mec lvl 2";
            opak = 1;
            gold -= 100;
            attack = ceil(attack * 1.6);
        }
        else if (gold < 100)
        {
            broke_boi();
        }
        break;

    case 3:
        if (gold >= 200)
        {
            cout << "koupil jste mec lvl 3";
            opak = 1;
            gold -= 200;
            attack = ceil(attack * 2);
        }
        else if (gold < 200)
        {
            broke_boi();
        }
        break;

    case 4:
        if (gold >= 65)
        {
            cout << "koupil jste dagger lvl 1";
            gold -= 65;
            attack = ceil(attack * 1.2);
            magic_attack = ceil(magic_attack * 1.2);
            opak = 1;
        }
        else if (gold < 65)
        {
            broke_boi();
        }
        break;

    case 5:
        if (gold >= 160)
        {
            cout << "koupil jste dagger lvl 2";
            gold -= 160;
            attack = ceil(attack * 1.5);
            magic_attack = ceil(magic_attack * 1.5);
            opak = 1;
        }
        else if (gold < 160)
        {
            broke_boi();
        }
        break;

    case 6:
        if (gold >= 55)
        {
            cout << "koupil jste spell book lvl 1";
            gold -= 55;
            magic_attack = ceil(magic_attack * 1.3);
            opak = 1;
        }
        else if (gold < 55)
        {
            broke_boi();
        }
        break;

    case 7:
        if (gold >= 170)
        {
            cout << "koupil jste spell book lvl 2";
            gold -= 170;
            magic_attack = ceil(magic_attack * 1.7);
            opak = 1;
        }
        else if (gold < 170)
        {
            broke_boi();
        }
        break;

    case 8:
        cout<<"koupil jste si armour";
        HP=HP+5;
        opak=1;
        gold=gold-20;

        break;
    case 9:
       cout << "vracite se na namesti...\n";
        opak2 = 1;
    }
cstats();
}

void enemy_hit()
{

    hit_For_dodge = rand() % 100 + 1;
    hit_for_crit = rand() % 100 + 1;
    cout << "nepritel utoci...\n";
    system("timeout /t 1 >nul"); // pauza mezi utokem nepritele a vypisem damage
    
    if (hit_For_dodge < dodge)
    {
        cout << "attack dognut\n";
    }
    else
    {
        
        

        


        if (hit_for_crit <= enemy_crit[enemy_number])
        {
            if (trida == 1)
            {
                HP = HP - enemy_dmg[enemy_number+x] * 2 * 0.7;
                cout << "nepritel "<< 1+x<<" udeřil kriticky a ubral vam: " << enemy_dmg[enemy_number+x] * 2 * 0.7 << "HP\n";
            }
            else
            {
                HP = HP - enemy_dmg[enemy_number+x] * 2;
                cout << "nepritel "<< 1+x<<"udeřil kriticky a ubral vam: " << enemy_dmg[enemy_number+x] * 2 << "HP\n";
            }
        }
        else
        {

            if (trida == 1)
            {
                HP = HP - enemy_dmg[enemy_number+x] * 0.7;
                cout << "nepritel "<< 1+x<<" udeřil a ubral vam: " << enemy_dmg[enemy_number+x] * 0.7 << "HP\n";
            }
            else
            {
                HP = HP - enemy_dmg[enemy_number+x];
                cout << "nepritel "<< 1+x<<" udeřil a ubral vam: " << enemy_dmg[enemy_number+x] << "HP\n";
            }
        }
    }
}


void incoming_gold()
{
    for (int i= 0;i<number_of_enemies;i++){
    rand_for_gold = rand() % 100 + 1;

    if (enemy_gold_dorpchance[enemy_number+i] >= rand_for_gold)
    {
        gold = gold + (enemy_gold[enemy_number+i] * gold_multiplier);
        cout << "z nepritele jste ziskali: " << enemy_gold[enemy_number+i] * gold_multiplier << " zlata\n";
    }
    else
    {
        cout << "z nepritele nedroplo zadne ztlato :( \n";
    }
    cout << "vase aktualni zlato: " << gold << "\n\n";
    xp = xp + enemy_xp[enemy_number+i];
    cout << "ziskali jste: " << enemy_xp[enemy_number+i] << "Xp\n";
    if (xp>=20){
    cout << "vase aktualni zkušenosti: " << xp-20 << "\n";
    }else{
        cout << "vase aktualni zkušenosti: " << xp << "\n";
    }
    if(xp<20){
    cout << "zbyvajici xp od dalsiho levelu: " << 20 - xp << "\n";
    }
    cout<<"\n_______________\n";
level_up();
}
}

void fight()
{
    zbyvaji_nepratele=number_of_enemies;
    mana=mmana;
    cooldown = 0;


    opak=0;

    for (int i=0;i<number_of_enemies;i++){
        cout << "\nnepritel "<< i+1<<" ma " << enemy_hp[enemy_number+i] << " HP\n";
        }

    do
    {
        if(boss==0){
        
    do {
        ccstats();
         
        if (cooldown > 0)
        {
            cout << "charge attack je na cooldownu\n";
            cooldown--;
        }
        
        switch (trida)
        { // attacko moznosti pro kazdou tridu
        case 1:
            cout << "zadejte: \n1) pro fyzicky utok\n2) pro heavy utok\n3) pro magicky utok\n";

            break;
        case 2:
            cout << "zadejte: \n1) pro magicky utok\n2) pro silny magicky utok\n3) pro fyzicky utok\n";

            break;
        case 3:

            cout << "zadejte: \n1)pro fyzicky utok\n2) pro magicky utok\n3) pro lecivou schopnost\n";

            break;
        }
        
       
       
       
       
       
       
      
        
        pocet_voleb = 3;
        do
        {
            select_volba();
            if (volba == 2 and cooldown > 0)
            {
                cout << "charge attack je na cooldownu, zadejte znovu\n";
            }
        } while (volba == 2 and cooldown > 0); 
        cout << "\n\n\n";

        if(opak!=1){
        
        if(number_of_enemies>1){
        cout<<"\nvyberte na jakeho nepritele chcete zautocit: ";
        }
        switch (number_of_enemies){
        
            case 1: break;
            case 2:    cout<<"\n1) nepritel 1\n2) nepritel 2\n"; break;
            case 3:    cout<<"\n1) nepritel 1\n2) nepritel 2\n3) nepritel 3\n"; break;
        }
        
        if(number_of_enemies>1){
        do{
            
            cin >> target;
            if (target<=0 or target>number_of_enemies){
                cout<<"neplatna volba, zadejte znovu";
            }
        }while(target<=0 or target>number_of_enemies);
        
        cout<<"zautocili jste na neppritele: "<<target<<"\n";
    }else{
        target=1;
    }
    }
    
    opak=0;
    switch (volba)//attack na nepritele
        {

        case 1:
            switch (trida)
            {
            case 1:
                cout << "fyzicky utok\n";
                dmg = enemy_hp[enemy_number-1+target] - attack;
                enemy_hp[enemy_number-1+target] = enemy_hp[enemy_number-1+target] - attack;
                break;
            case 2:
                if (mana>10){
                cout << "magicky utok\n";
                dmg = enemy_hp[enemy_number-1+target] - attack * 1.2;
                enemy_hp[enemy_number-1+target] = enemy_hp[enemy_number-1+target] - (magic_attack * 1.2);
                mana = mana - 13;
                }else{
                    cout<<"nemate dost many";
                    opak=1;
                }
                break;
            case 3:
                cout << "fyzicky utok\n";
                dmg = enemy_hp[enemy_number-1+target] - attack;
                enemy_hp[enemy_number-1+target] = enemy_hp[enemy_number-1+target] - attack;
                break;
            }
            break;

        case 2:
            switch (trida)
            {
            case 1:
                cout << "heavy utok\n";
                dmg = enemy_hp[enemy_number-1+target] - attack;
                enemy_hp[enemy_number-1+target] = enemy_hp[enemy_number-1+target] - attack * 1.4;
                break;
            case 2:
            if(mana>20){    
            cout << "silny magicky utok\n";
                dmg = enemy_hp[enemy_number-1+target] - attack * 1.2;
                enemy_hp[enemy_number-1+target] = enemy_hp[enemy_number-1+target] - (magic_attack * 1.4 * 1.2);
                mana = mana - 20;
                }else{
                    cout<<"nemate dost many";
                    opak=1;
                }
                break;
            case 3:
            if (mana>25){    
                cout << "magicky utok\n";
                dmg = enemy_hp[enemy_number-1+target] - attack;
                enemy_hp[enemy_number-1+target] = enemy_hp[enemy_number-1+target] - magic_attack * 1.4;
                mana = mana - 25;
                }else{
                    cout<<"nemate dost many";
                    opak=1;
                }
                break;
            }
            cooldown = 3;

            break;
        case 3:
            switch (trida)
            {
            case 1:
            if(mana>10){    
                cout << "magicky utok\n";
                dmg = enemy_hp[enemy_number-1+target] - attack;
                enemy_hp[enemy_number-1+target] = enemy_hp[enemy_number-1+target] - magic_attack;
                mana = mana - 10;
                }else{
                    cout<<"nemate dost many";
                    opak=1;
                }
                break;
            case 2:
                cout << "fyzicky utok\n";
                dmg = enemy_hp[enemy_number-1+target] - attack * 1.2;
                enemy_hp[enemy_number-1+target] = enemy_hp[enemy_number-1+target] - (attack * 1.2);
                break;
            case 3:
           if(mana>10){     
            cout << "lecivou schopnost\n";
                dmg = 0;
                HP = HP + 15;
                mana = mana - 10;
                if (HP > mHP)
                {
                    HP = mHP;
                }
                }else{
                    cout<<"nemate dost many";
                    opak=1;
                }
                
                break;
            }
            break;
        }    
    }while(opak==1);

     
       
       
       
       for (int i=0;i<number_of_enemies;i++){
        
        if(enemy_hp[enemy_number+i]>0){
        cout << "\nnepritel "<< i+1<<" ma " << enemy_hp[enemy_number+i] << " HP\n";
        }else {
            cout << "\nnepritel "<< i+1<<" ma " << 0 << " HP\n";
        }
    
        }
     boss==0;  
    }
       
        mana = mana + 10;
        
         
        
        
        cout << "\n______________________\n";
        
        for (int i=0;i<number_of_enemies;i++){
        
        x=i;//pro tu funkci enemy_hit
        
            if (enemy_hp[enemy_number+i] > 0)
        {
            enemy_hit();
        }
        }
       

        zbyvaji_nepratele=number_of_enemies;
        
        for(int i=0;i<number_of_enemies;i++){
        if(enemy_hp[enemy_number+i]<=0){
            zbyvaji_nepratele--;
               
        }
        }
        



    } while (HP > 0 and zbyvaji_nepratele>0);

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
    else
    {
        cout << "nepritel byl zabit\n";
        incoming_gold();
        
        cstats();
    }
}

void vesnice()
{
    cout << "nachazite se ve vesnici\n";
    cout<<sidequest_done;
    pocet_voleb = 3;
    do
    {
        cout<<sidequest_done;
        volba = 0;
        opak = 0;
        opak2 = 0;
        do
        {
            HP = mHP;
            cout << "\n______________________\n";
            if(sidequest_done==4){
            cout << "Nachazite se ve vesnici vyberte si co chete delat dale\n1)jit do obchodu\n2)vydat se na cestu\n";
            }else{
                cout << "Nachazite se ve vesnici vyberte si co chete delat dale\n1)jit do obchodu\n2)vydat se na cestu\n3)udelat side quest\n";
            }
            pocet_voleb = 3;
            select_volba();

            cout << "vase volba: " << volba;
            cout << "\n______________________\n";

            switch (volba)
            {
            case 1:
                do
                {

                    shop();

                } while (opak == 1);

                break;

            case 2:
                opak2 = 0;
                opak = 0;
                break;

            case 3:

                if (sidequest_done == 1)
                {
                    cout << "uz jste tento side quest dokoncil\n";
                    opak = 2;
                
                
                
                
                
                
                
                
                }
                else if (sidequest_done == 0)
                {
                    do
                    {

                        cout << R"(
zravím tě dobrodruhu, slyšel jsem že hledáš práci, mám pro tebe úkol.
potřebuju aby si porazil zlého a nevrlého bezdomovce v naší vesnici, jehož jméno je Bob, je to nebezpečný protivník,
ale pokud ho porazíš, odměním tě zlatem a skušenostmi. Co ty na to?


1) přijmout úkol
2) odmítnout úkol
)"; // ten bezdak bude mit high crit chance

                        pocet_voleb = 2;
                        select_volba();

                        if (volba == 2)
                        {
                            opak = 1;
                            cout << "ukol odmítnut";
                            opak = 2;
                        }
                        else if (volba == 1)
                        {
                            cout << "ukol přijat,jdete k bezdomovci do jeho doupěte...";

                            cout << "dorazili jste do doupěte divokého bezdáka, bob na vas hazi exkremnety a utoci na vas";
                            enemy_number = 0;
                            number_of_enemies=1;
                            fight();
                            opak = 2;
                            sidequest_done = 1;
                            

                            system("pause");
                        }

                    } while (opak2 == 1); //

                    break;
                
                
                
                
                
                }else if(sidequest_done==2){
                    cout<<"nacházíš se v centru ústí nad labem. nějaký podivný individuál ti povídá že ti dá 20 zlata pokud zabiješ bezdomovce co mu lootí jeho bezdomovecky doupě. ";
                    
                    pocet_voleb = 2;
                    cout<<"1) přijmout úkol\n2) odmítnout úkol";    
                    select_volba();

                        
                        
                        if (volba == 2)
                        {
                            opak = 1;
                            cout << "ukol odmítnut";
                            opak = 2;
                        }
                        else if (volba == 1)
                        {
                            cout << "ukol přijat,jdete k bezdomovci";

                            cout << "blud na vas zacal kricen nesmysly a nadavat vam";
                            enemy_number = 4;
                            number_of_enemies=1;
                            fight();
                            opak = 2;
                            sidequest_done = 3;
                            

                            system("pause");
                        }



                }else if(sidequest_done==3){
                    cout << "uz jste tento side quest v usti dokoncil\n";
                    opak = 2;

                }            }
        } while (opak == 2);
    } while (opak2 == 1);
}

int main()
{

    srand(time(0));              // aby bylo generovani nahodneho cisla fr random
    SetConsoleCP(CP_UTF8);       // output asci tabullky
    SetConsoleOutputCP(CP_UTF8); // nevim asci tabulka

    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "Toto je turn-based textove RPG erpegia\n";
    cout<<R"(
Pravidla:
hrac bude zadavat pouze cisl, pokud zadate neco jineho nez cislo(krome vyberu jmena) budete muset restartovat hru.
kazdych par souboju se ocitnete ve vesnici
    )";
    cout << "zadejte jmeno hrace: ";
    cin >> name;
    number_of_enemies = 1;

    cout << "vyberte si tridu: 1-fighter, 2-mage, 3-thief: ";
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
    {
        // fighter; - tank
        mHP = 40;
        mmana = 10;
        dodge = 10;
        attack = 20;
        magic_attack = 10;
        cout << "vase trida je: fighter\n";
        cout << "______________________\n";
        cout << "vase scpeicalni schopnost : vynasobi incoming damage 0.7x\n";
    }
    else if (trida == 2)
    {
        // mage; - glass canon
        mHP = 25;
        mmana = 50;
        dodge = 25;
        attack = 15;
        magic_attack = 55;
        cout << "vase trida je: Mage\n";
        cout << "vase scpeicalni schopnost : vynasobi damage 1.2x (pri vyberu tahu se ukazuje poskozeni pred vynasobenim)\n";
    }
    else if (trida == 3)
    {
        // zlodej; - charge attack reliant, heal sustain
        mHP = 25;
        mmana = 30;
        dodge = 35;
        attack = 20;
        magic_attack = 45;
        gold_multiplier = 1.3;
        cout << "vase trida je: zlodej\n";
        cout << "vase scpeicalni schopnost : vynasobi prijem zlata 1.3x\n";
    }

    if (name == "cheater")
    {
        attack = 999;
        magic_attack = 999;
    }

    cout << "vase base staty:\nHP:" << mHP << "\nuroven fyzickeho utoku: " << attack << "\nuroven magickeho utoku: " << magic_attack << "\nmana: " << mmana << "\ndodge : " << dodge << "%\n";
    HP = mHP;
    mana = mmana;
    xp = 0;

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

    vesnice();
    cout << "\nvydal jsi se na cestu do vesnice Ústí nad labem...\n";
    system("timeout /t 3 >nul"); // pauza mezi cestou a bojem

    cout << "\nprocházíte lesem a najednou potkate divokeho rulickare z rumonska a snazi se vas okrast o vase zlato\n";
    enemy_number = 1;//cislo na kterym list enemaku zacina
    number_of_enemies=1;//kolik je tam enemaku
    fight();
    cout << "\n______________________\n";
   
        system("timeout /t 1 >nul");
        cout << "\n po porazeni nepritele pokracujete v ceste...\n";
        system("timeout /t 1 >nul");
    
    cout << "\n______________________\n";
    cout << "kdyz jste dorazil na okraj města zautočil na vás Roman a Radek. Tyto vzdělaní individuálové vaří doma na sídlišti\n a snaží se vám vnutit podezrelou mouku\n";
    cout << "\n______________________\n";
    system("pause");
    number_of_enemies = 2;
    enemy_number = 2;
    fight();
    sidequest_done=2;
    vesnice();

    cout<<"\nvydal jste se na cestu do mostu\n";
    cout<<"cestou z ústí jste potkal 3 žebrající holuby kteří na vás začali agresivně útočit a mlátit vás protože ste jim nedal cheba\n";
    number_of_enemies=3;
    enemy_number=5;
        fight();
    
    cout<<"po porazeni zebrajicich holubu jste se vydal uz doopravdy na cestu do mostu\n";
    system("timeout /t 1 >nul");
    cout<<"cestou po silnici si objevil divokého cilkozmrda ktery naschval blokoval silnici a snazil se te nasvat \n";
    number_of_enemies=1;
    enemy_number=8;
    
    fight();//minibos 1;

    system("timeout /t 1 >nul");
    cout<<"po odstranšeni cyklozmrda ze silnice pokracujete v ceste\n";
    cout<<" potkavatze 2 zlobive zajice. zajici na vas utoci a kopou vas\n";
    number_of_enemies=2;
    enemy_number=9;
    fight();
    sidequest_done=4;
    vesnice();

    cout<<"po vyrazeni z mostu sjte se vydali do berlina\n";
    system("timeout /t 1 >nul");
    cout<<"cestou do berlina jste potkali zlobiveho krakonose\n";
    enemy_number=11;
   
    number_of_enemies=1;
    fight();//miniboss 2;

    cout<<"po zabiti krakonose pokracujes do nemecka\n";
    system("timeout /t 1 >nul");
    cout<<"kdyz si dorazil od nemecka skvely mistr kebabu ti dal kebab a zvýšil tvoje max životy o 5\nW kebabar ♡";
    mHP=mHP+5;

    cout<<"dorazil jsi do centra berlina";
    sidequest_done=4;
    vesnice();
    cout<<"v cenrtru berlina se vas snazi okrast rulickari\n";
    enemy_number=12;
    number_of_enemies=3;
    fight();

    cout<<"rulickari se nastvali a zavolali na vas policajty ted s nimi musite bojovat\n";
    enemy_number=15;
    number_of_enemies=2;
    
    cout<<"po dobrodrustvi v berlise se vydavate spatky do prahy";
    

    cout<<"co si to provedl ty si zabil krakonoše, říka krakonosova sojka\n";
    cout<<"cestou do prahy prochazis do vesnice\n";
    vesnice();
    cout<<"vysel jis z veynice...";
    system("timeout /t 1 >nul");    
    cout<<"\nto si ondeses";

    cout<<"final bossfight;";
    //final boss
cout << "\n______________________\n";
    cout << "Konecne jsi dorazil zpatky... Ale cesta je zablokovana!\n";
    cout << "Pred tebou stoji obrovska zmutovana Kukacka!\n";
    cout << "Kukacka na tebe zlověstně zírá. Zacinaji se dit divne veci s tvymi staty...\n";
    cout << "______________________\n";

    system("timeout /t 2 >nul");

    // final boss setup (Kukacka)
    
    do {
        
        cout << "\n--- Tah Kukacky --- \n";
        random_cislo = rand() % 4 + 1; 
        
        if (random_cislo == last_effect) {
            effect_multiplier *= 2;
        } else {
            effect_multiplier = 1;
            last_effect = random_cislo;
        }

        switch(random_cislo) {
            case 1:
                boss_atk += (5 * effect_multiplier);
                cout << "Kukacka agresivne mava kridly Jeji utok se zvysil na " << boss_atk << "!\n";
                break;
            case 2:
                boss_def -= (0.15 * effect_multiplier);
                if (boss_def < 0.2) boss_def = 0.2; // cap na 80% redukci
                cout << "Kukacka si zpevnila peri Bude tezsi ji zranit.\n";
                break;
            case 3:
                boss_regen += (10 * effect_multiplier);
                cout << "Kukacka zacala zobat zazracna seminka Ziskava regeneraci " << boss_regen << " HP za kolo.\n";
                break;
            case 4:
                boss_crit += (10 * effect_multiplier);
                if (boss_crit > 80) boss_crit = 80;
                cout << "Kukacka miri na tvoje slaba mista Sance na kriticky zasah se zvysila na " << boss_crit << "%!\n";
                break;
        }

        
        random_cislo2 = rand() % 100 + 1;
        if (random_cislo2 <= 10) {
            cout << "\n kukacka pouzila zmateni \n";
            cout << "Tvoje nabrany zbrane a kouzla ztraceji silu Bonusy k utoku byly resetovany.\n";
            attack = player_base_atk * 0.7; // docasny debuff 
            magic_attack = player_base_magic * 0.7;
        }

       
        ccstats();
        cout << "\nKukacka ma " << boss_hp << " / " << boss_max_hp << " HP\n";
        
        if (cooldown > 0) {
            cout << "charge attack je na cooldownu (" << cooldown << " kol)\n";
            cooldown--;
        }

        switch (trida) {
            case 1: cout << "zadejte: \n1) pro fyzicky utok\n2) pro heavy utok\n3) pro magicky utok\n"; break;
            case 2: cout << "zadejte: \n1) pro magicky utok\n2) pro silny magicky utok\n3) pro fyzicky utok\n"; break;
            case 3: cout << "zadejte: \n1) pro fyzicky utok\n2) pro magicky utok\n3) pro lecivou schopnost\n"; break;
        }

        pocet_voleb = 3;
        do {
            select_volba();
            if (volba == 2 and cooldown > 0) {
                cout << "charge attack je na cooldownu, zadejte znovu\n";
            }
        } while (volba == 2 and cooldown > 0); 
        
        float base_dmg = 0;
        
        
        switch (volba) {
            case 1:
                if (trida == 1 or trida == 3) { cout << "fyzicky utok\n"; base_dmg = attack; }
                else if (trida == 2) { 
                    if (mana >= 10) { cout << "magicky utok\n"; base_dmg = magic_attack * 1.2; mana -= 13; }
                    else { cout << "nemate dost many Utok selhal.\n"; }
                }
                break;
            case 2:
                cooldown = 3;
                if (trida == 1) { cout << "heavy utok\n"; base_dmg = attack * 1.4; }
                else if (trida == 2) { 
                    if (mana >= 20) { cout << "silny magicky utok\n"; base_dmg = magic_attack * 1.4 * 1.2; mana -= 20; }
                    else { cout << "nemate dost many\n"; cooldown = 0; }
                }
                else if (trida == 3) {
                    if (mana >= 25) { cout << "silny magicky utok\n"; base_dmg = magic_attack * 1.4; mana -= 25; }
                    else { cout << "nemate dost many\n"; cooldown = 0; }
                }
                break;
            case 3:
                if (trida == 1) { 
                    if (mana >= 10) { cout << "magicky utok\n"; base_dmg = magic_attack; mana -= 10; }
                    else { cout << "nemate dost many\n"; }
                }
                else if (trida == 2) { cout << "slabsi fyzicky utok\n"; base_dmg = attack * 1.2; }
                else if (trida == 3) {
                    if (mana >= 10) { 
                        cout << "leciva schopnost\n"; 
                        HP += 15; 
                        mana -= 10; 
                        if (HP > mHP) HP = mHP; 
                    }
                    else { cout << "nemate dost many!\n"; }
                }
                break;
        }

        
        int final_dmg = ceil(base_dmg * boss_def);
        if (final_dmg > 0) {
            boss_hp -= final_dmg;
            cout << "Udelil jsi Kukacce " << final_dmg << " poskozeni\n";
            player_consecutive_hits++;
        } else if (volba != 3 or trida != 3) { // Pokud se hrac zrovna nehealoval
            player_consecutive_hits = 0;
        }

        
        if (player_consecutive_hits >= 3 and stolen_duration == 0) {
            cout << "\nkukacka se anstvala \n";
            cout << "Zasahls ji 3x po sobe Kukacka ti krade jeden z tvych statu\n";
            stolen_stat_type = rand() % 3 + 1;
            stolen_duration = 2; 
            
            if (stolen_stat_type == 1) {
                original_stat = attack;
                attack /= 2; // sebere pulku utoku
                boss_atk += 15;
                cout << "Kukacka ti sezobla svaly Tvuj fyzicky utok je polovicni a ona je ted silnejsi.\n";
            } else if (stolen_stat_type == 2) {
                original_stat = magic_attack;
                magic_attack /= 2;
                boss_regen += 15;
                cout << "Kukacka nasala tvoji magii Tvuj magicky utok klesl a ona se lepe regeneruje.\n";
            } else {
                original_stat = dodge;
                dodge = 0;
                boss_crit += 20;
                cout << "Kukacka ti ukradla obratnost Nemuzes uhnout a ona ma vetsi sanci na crit\n";
            }
            player_consecutive_hits = 0; 
        }

        
        if (stolen_duration > 0) {
            stolen_duration--;
            if (stolen_duration == 0) {
                cout << "\nUkradeny stat se ti vratil zpatky\n";
                if (stolen_stat_type == 1) attack = original_stat;
                else if (stolen_stat_type == 2) magic_attack = original_stat;
                else if (stolen_stat_type == 3) dodge = original_stat;
            }
        }

        // Boss se regeneruje
        if (boss_hp > 0 and boss_hp < boss_max_hp and boss_regen > 0) {
            boss_hp += boss_regen;
            if (boss_hp > boss_max_hp) boss_hp = boss_max_hp;{
            cout << "Kukacka si obnovila " << boss_regen << " HP Ma ted " << boss_hp << " HP.\n";
            }
        }

        mana += 10;

        // Fáze 5: Útok Kukacky
        if (boss_hp > 0) {
            cout << "\nKukacka utoci\n";
            system("timeout /t 1 >nul");
            hit_For_dodge = rand() % 100 + 1;
            hit_for_crit = rand() % 100 + 1;

            if (hit_For_dodge <= dodge) {
                cout << "dodgnul jsi utok\n";
            } else {
                float incoming_dmg = boss_atk;
                if (hit_for_crit <= boss_crit) {
                    incoming_dmg *= 2;
                    cout << "kriticky zasah ";
                }
                
                if (trida == 1) incoming_dmg *= 0.7; // Fighterova pasivka

                HP -= incoming_dmg;
                cout << "Kukacka  udelila " << incoming_dmg << " HP dmg\n";
            }
        }

    } while (HP > 0 and boss_hp > 0);

    if (HP > 0) {
        win = 1;
        cout << "\nkukacka zemrela\n";
    } else {
        win = 0;
    }

    if (win == 1) {
        cout << R"(
  ██████   █████  ███    ███ ███████        ██     ██  ██████  ███    ██
 ██       ██   ██ ████  ████ ██             ██     ██ ██    ██ ████   ██
 ██   ███ ███████ ██ ████ ██ █████          ██  █  ██ ██    ██ ██ ██  ██
 ██    ██ ██   ██ ██  ██  ██ ██             ██ ███ ██ ██    ██ ██  ██ ██
  ██████  ██   ██ ██      ██ ███████         ███ ███   ██████  ██   ████
)" << "\n";
    } else {
        cout << R"(
  ██████   █████  ███    ███ ███████      ██████  ██    ██ ███████ ██████
 ██       ██   ██ ████  ████ ██          ██    ██ ██    ██ ██      ██   ██
 ██   ███ ███████ ██ ████ ██ █████       ██    ██ ██    ██ █████   ██████
 ██    ██ ██   ██ ██  ██  ██ ██          ██    ██  ██  ██  ██      ██   ██
  ██████  ██   ██ ██      ██ ███████      ██████    ████   ███████ ██   ██
)" << "\n";
    }

    system("pause");
    return 0;
}
    


    
    
    

    


 