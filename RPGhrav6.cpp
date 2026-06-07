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
int enemy_dmg[] = {3,3,2,4};
int enemy_crit[] = {60, 20, 60, 70};
int enemy_hp[] = {100, 150, 100, 200};
int enemy_xp[] = {10, 10, 15, 15};
int enemy_gold[] = {20, 60, 15, 20};
int enemy_gold_dorpchance[] = {100, 100, 65, 65};

bool zbyvaji_nepratele = false;
int enemy_number;
int enemy_number2;
int enemy_number3;
int number_of_enemies;
int opak2;
int cooldown;
int xp;
int level = 1;
int dmg;
int dmg2;
int dmg3;
int sidequest_done = 0;

void cstats()
{
    cout << "\n______________________\n";
    cout << "vase current staty:\nHP:" << mHP << "\nuroven fyzickeho utoku: " << attack << "\nuroven magickeho utoku: " << magic_attack << "\nmana: " << mmana << "\ndodge: " << dodge << "%\n";
}

void ccstats()
{
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
        cstats();
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
    pocet_voleb = 8;
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
        }
        else if (gold < 170)
        {
            broke_boi();
        }
        break;

    case 8:
        cout << "vracite se na namesti...\n";
        opak2 = 1;

        break;
    case 9:
        cstats();
        opak = 1;
        break;
    }
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
                HP = HP - enemy_dmg[enemy_number] * 2 * 0.7;
                cout << "nepritel udeřil kriticky a ubral vam: " << enemy_dmg[enemy_number] * 2 * 0.7 << "HP\n";
            }
            else
            {
                HP = HP - enemy_dmg[enemy_number] * 2;
                cout << "nepritel udeřil kriticky a ubral vam: " << enemy_dmg[enemy_number] * 2 << "HP\n";
            }
        }
        else
        {

            if (trida == 1)
            {
                HP = HP - enemy_dmg[enemy_number] * 0.7;
                cout << "nepritel udeřil a ubral vam: " << enemy_dmg[enemy_number] * 0.7 << "HP\n";
            }
            else
            {
                HP = HP - enemy_dmg[enemy_number];
                cout << "nepritel udeřil a ubral vam: " << enemy_dmg[enemy_number] << "HP\n";
            }
        }
    }
}

void fight()
{
    cooldown = 0;

    cout << "souboj s nepritelem: " << enemy_number << "\n";
    do
    {

        switch (number_of_enemies)
        {
        case 1:
            cout << "zivoty nepritele: " << enemy_hp[enemy_number] << "\n";
            break;

        case 2:
            cout << "zivoty nepritele: " << enemy_hp[enemy_number] << "\n";
            cout << "zivoty nepritele2: " << enemy_hp[enemy_number2] << "\n";
            break;

        case 3:
            cout << "zivoty nepritele: " << enemy_hp[enemy_number] << "\n";
            cout << "zivoty nepritele2: " << enemy_hp[enemy_number2] << "\n";
            cout << "zivoty nepritele63: " << enemy_hp[enemy_number3] << "\n";
            break;
        }

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
        cout << "\n\n\n\n\n";

        cout << "pouzili jste: ";
        switch (volba)
        {

        case 1:
            if (trida == 1)
            {
                cout << "fyzicky utok\n";
                dmg = enemy_hp[enemy_number] - attack;
                enemy_hp[enemy_number] = enemy_hp[enemy_number] - attack;
            }
            else if (trida == 2)
            {
                cout << "magicky utok\n";
                dmg = enemy_hp[enemy_number] - attack * 1.2;
                enemy_hp[enemy_number] = enemy_hp[enemy_number] - (magic_attack * 1.2);
                mana = mana - 10;
            }
            else if (trida == 3)
            {
                cout << "fyzicky utok\n";
                dmg = enemy_hp[enemy_number] - attack;
                enemy_hp[enemy_number] = enemy_hp[enemy_number] - attack;
            }
            break;

        case 2:
            if (trida == 1)
            {
                cout << "heavy utok\n";
                dmg = enemy_hp[enemy_number] - attack;
                enemy_hp[enemy_number] = enemy_hp[enemy_number] - attack * 1.4;
            }
            else if (trida == 2)
            {
                cout << "silny magicky utok\n";
                dmg = enemy_hp[enemy_number] - attack * 1.2;
                enemy_hp[enemy_number] = enemy_hp[enemy_number] - (magic_attack * 1.4 * 1.2);
                mana = mana - 20;
            }
            else if (trida == 3)
            {
                cout << "magicky utok\n";
                dmg = enemy_hp[enemy_number] - attack;
                enemy_hp[enemy_number] = enemy_hp[enemy_number] - magic_attack * 1.4;
                mana = mana - 25;
            }
            cooldown = 3;

            break;
        case 3:
            if (trida == 1)
            {
                cout << "magicky utok\n";
                dmg = enemy_hp[enemy_number] - attack;
                enemy_hp[enemy_number] = enemy_hp[enemy_number] - magic_attack;
                mana = mana - 10;
            }
            else if (trida == 2)
            {
                cout << "fyzicky utok\n";
                dmg = enemy_hp[enemy_number] - attack * 1.2;
                enemy_hp[enemy_number] = enemy_hp[enemy_number] - (attack * 1.2);
            }
            else if (trida == 3)
            {
                cout << "lecivou schopnost\n";
                dmg = 0;
                HP = HP + 15;
                mana = mana - 15;
                if (HP > mHP)
                {
                    HP = mHP;
                }
            }
            break;
        }

        mana = mana + 10;
        // cout<<"nepritelovi jste udelili "<<dmg<<" damage\n";
        if (enemy_hp[enemy_number] < 0)
        {
            enemy_hp[enemy_number] = 0;
        }
        if (enemy_hp[enemy_number2] < 0)
        {
            enemy_hp[enemy_number2] = 0;
        }
        if (enemy_hp[enemy_number3] < 0)
        {
            enemy_hp[enemy_number3] = 0;
        }

        cout << "nepritelovi zbylo " << enemy_hp[enemy_number] << " HP\n";
        cout << "\n______________________\n";
        if (enemy_hp[enemy_number] > 0)
        {
            enemy_hit();
        }

        //(enemy_hp[enemy_number]>0 or enemy_hp[enemy_number2]>0 or enemy_hp[enemy_number3]>0 )

        zbyvaji_nepratele = false;

        switch (number_of_enemies)//checkuej jestli zije nejakej enemak
        {
        case 1:
            if (enemy_hp[enemy_number] > 0)
            {
                zbyvaji_nepratele = true;
            }
            break;

        case 2:
            if (enemy_hp[enemy_number] > 0 || enemy_hp[enemy_number2] > 0)
            {
                zbyvaji_nepratele = true;
            }
            break;

        case 3:
            if (enemy_hp[enemy_number] > 0 || enemy_hp[enemy_number2] > 0 || enemy_hp[enemy_number3] > 0)
            {
                zbyvaji_nepratele = true;
            }
            break;
        }

    } while (HP > 0 and zbyvaji_nepratele == true);

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

        level_up();
        cout << "nepritel byl zabit\n";
    }
}

void incoming_gold()
{

    rand_for_gold = rand() % 100 + 1;

    if (enemy_gold_dorpchance[enemy_number] >= rand_for_gold)
    {
        gold = gold + (enemy_gold[enemy_number] * gold_multiplier);
        cout << "z nepritele jste ziskali: " << enemy_gold[enemy_number] * gold_multiplier << " zlata\n";
    }
    else
    {
        cout << "z nepritele nedroplo zadne ztlato :( \n";
    }
    cout << "vase aktualni zlato: " << gold << "\n";
    xp = xp + enemy_xp[enemy_number];
    cout << "ziskali jste: " << enemy_xp[enemy_number] << "Xp\n";
    cout << "vase aktualni zkušenosti: " << xp << "\n";
    cout << "zbyvajici xp od dalsiho levelu: " << 20 - xp << "\n";
}

void vesnice()
{
    cout << "nachazite se ve vesnici\n";

    pocet_voleb = 3;
    do
    {
        volba = 0;
        opak = 0;
        opak2 = 0;
        do
        {
            HP = mHP;
            cout << "\n______________________\n";
            cout << "Nachazite se ve vesnici vyberte si co chete delat dale\n1)jit do obchodu\n2)vydat se na cestu\n3)udelat side quest\n";
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
                            fight();
                            opak = 2;
                            sidequest_done = 1;
                            incoming_gold();

                            system("pause");
                        }

                    } while (opak2 == 1); //

                    break;
                }
            }
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
        mmana = 40;
        dodge = 5;
        attack = 15;
        magic_attack = 45;
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
    enemy_number = 1;
    fight();

    for (int i = 0; i <= 5; i++)
    {
        system("timeout /t 1 >nul");
        cout << "po porazeni nepritele pokracujete v ceste...\n";
    }

    cout << "kdyz jste dorazil na okraj města zautočil na vás honza a radek. Tyto vzdělaní individuálové vaří doma na sídlišti\n a snaží se vám vnutit podezrelou mouku";
    cout << "jelikoz jsou napůl člověkl a napůl něco jiného healují se každé kolo 10 HP";
    number_of_enemies = 2;
    enemy_number = 2;
    enemy_number2 = 3;
    fight();

    if (win == 1)
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
}
