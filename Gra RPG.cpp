// Dołączamy Biblioteki 
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <ctime>

const int EnemyDmg = 35;

const std::string describses[10] = {
    "Przechodzisz przez podziemna rzeke. Na brzegach znajduje sie pelno elfickich kości. Pomimo braku oznak zycia, wyczuwasz obecnosc niespotykanego bytu",
    "Znajdujesz się w pradawnej grocie , niegdyś zamieszkałej przez starożytnego smoka Antraha",
    "Wchodzisz do sali obrad wielkiego władcy , zdrajcy który udał się dawno na południe",
    "Przechodzisz przez korytarz , który wydaje się nie mieć końca , ze szczelin pomiędzy ścianami przedziera się woda",
    "Przemieszczając się coraz dalej w głąb lochów stajesz się coraz słabszy z wycieńczenia ",
    "Wchodzisz do sali Faraona , dopada cię klątwa , przez którą twój stan psychiczny się pogarsza ",
    "Dalej przemieszczasz się po lochach , zauważasz jednak jeszcze niższe piętro , zmierzasz w jego stronę",
    "Przechodząc przez wrota , dostrzegł cię pradawny smok Hellcat , doskonale włada ogniem i temperaturą ciała wrogów. Spadl na niego stalaktyt , ktory go zabil , miales szczescie",
    "Trafiasz do ruin starej elfickiej bogini ksiezyca Luny",
    "Natrafiles na pradawny grobowiec jednego z Elfickich kroli "
};

const std::string traps[3] = {
    "Wchodzisz do jednego z licznych korytarzy. Niestety miejsce na ktore stanales aktywowalo pulapke. Giniesz przeszyty przez wylatujace z murow strzaly.",
    "Wspinajac sie po stromej scianie nie udaje Ci sie dosiegnac wystajacej skaly i spadasz. Nikt nie uslyszy Twojej heroicznej historii.",
    "Ukasil Cie pajak! Zasypiasz, by nie ubdzic sie juz nigdy wiecej."
};

const std::string weapon_type[4] = {
        "topor",
        "miecz",
        "sztylet",
        "luk"
};

enum Elemental {
    FIRE,
    WATER,
    EARTH,
    WIND
};

struct Item
{
    std::string name;
    Elemental type;
};

struct Player
{
    int HP = 100;
    std::string imie;
    std::vector<Item> eq;
};

struct Page
{
    int id;
    std::string opis;

    bool isItem;
    Item item;

    bool isHospital;
    bool isOver;
    bool isWin;

    bool isEnemy;
    Elemental enemyType;

    Page* left;
    Page* right;
    Page* up;
    Page* down;

    Page(int id, std::string opis);
    Page();
};

Page::Page(int id, std::string opis)
{
    this->id = id;
    this->opis = opis;
    this->left = NULL;
    this->right = NULL;
    this->up = NULL;
    this->down = NULL;
    this->isHospital = false;
    this->isOver = false;
    this->isWin = false;
    this->isEnemy = false;
    this->isItem = false;
}


void addLeft(Page* page, Page* left)
{
    page->left = left;
    left->right = page;
}

void addRight(Page* page, Page* right)
{
    page->right = right;
    right->left = page;
}

void addUp(Page* page, Page* up)
{
    page->up = up;
    up->down = page;
}

void addDown(Page* page, Page* down)
{
    page->down = down;
    down->up = page;
}


void initWin(Page& page)
{
    page.isWin = true;
    page.isEnemy = false;
    page.isHospital = false;
    page.isOver = false;
    page.isItem = false;
    page.opis = "Udalo ci sie skompletowac wszystkie zaginione dusze pokonujac smoki , twoje przeznaczeie sie dopelnilo , wracasz do domu ! \n";
}

void initEnemy(Page& page)
{
    page.isEnemy = true;
    page.enemyType = static_cast<Elemental>((std::rand() % 4));
    if (page.enemyType == Elemental::EARTH)
    {
        page.opis = "Wszedlesc do olbrzymiej jaskini. Wokol znajduja sie niezliczone krysztaly roznej wielkosci oraz rosliny o ktorych istnieniu nie miales pojecia.";
        page.opis += "\nNa srodku groty znajduje się olbrzymia, porosnieta porostami skala. Okazuje sie jednak ze skala oddycha, wstaje i rozprostowuje dlugie na ";
        page.opis += "\n6 dlugosci konia skrzydla. Gargantuiczny ziemny smok staje na przeciwko Ciebie. Czas szykowac sie do walki";
    }
    else if (page.enemyType == Elemental::FIRE)
    {
        page.opis = "Przeciskajac sie przez zawalone w wiekszosci kamienne wrota, trafiasz na most rozposcierajacy sie nad rzeka magmy. Zapach siarki staje sie nie do";
        page.opis += "\nwytrzymania. Pot splywa Ci po twarzy. Ostroznie wchodzisz na nadszarpniety przez czas most gdy z dolu dochodzi do Ciebie straszliwy ryk.";
        page.opis += "\nNagle spod tafli piekelnej rzeki wzbija sie w powietrze dlugi jak wieza obronna czerwony smok, pokryty od ogona po grzbiet dlugimi na 3 lokcie kolcami.";
    }
    else if (page.enemyType == Elemental::WATER)
    {
        page.opis = "Trafiasz do podziemnego jeziora. Powietrze jest cieple i wilgotne. Z pod zawieszonego na ogromnej wysokosci sufitu, przebija sie swiatlo sloneczne.";
        page.opis += "\nNareszcie chwila spokoju. Siadajac przy wodzie, w celu uzupelnienia zapasu tego zyciodajnego plynu, slyszysz lekki, ledwo wyczuwalny szelest dochodzacy";
        page.opis += "\nz drugiego konca zbiornika. Tam dostrzegasz go. Gad o sliskiej, niebieskiej skorze zbudowanej z nakladajacych sie na siebie, polyskujacych lusek.";
        page.opis += "\nWodny smok, stworzenie przypominajace polaczenie wegorza z najplugawszymi stworzeniami bytujacymi na swiecie.";
    }
    else
    {
        page.opis = "Znajdujesz sie w jednym z bylych dystrykow mieszkalnych elfow. Wysoka jaskinia ze zbudowanymi domami na bokach. Posrodku plac, bedacy niegdys";
        page.opis += "\ncentrum kultorowym zamieszkujacej tu spolecznosci. Niegdys slychac tu bylo rozmowy i zabawy, obecnie miejsce owiane jest przerazajaca cisza.";
        page.opis += "\nCo dosc niespotykane pod ziemia, wieja tutaj przerazliwe wiatry. Dochodzac do srodka placu spostrzegasz prawie niedostrzegalnego bialego gada";
        page.opis += "\no dlugim ciele przypominajacym weza, z dwiema parami cienkich skrzydel. Panujacy nad powietrzem, smok wiatru.";
    }
}

int fight(Player& player, Elemental enemyType)
{
    Elemental counter;
    switch (enemyType)
    {
    case Elemental::EARTH:
        counter = Elemental::FIRE;
        break;

    case Elemental::FIRE:
        counter = Elemental::WATER;
        break;

    case Elemental::WATER:
        counter = Elemental::WIND;
        break;

    case Elemental::WIND:
        counter = Elemental::EARTH;
        break;
    }

    for (int i = 0; i < player.eq.size(); i++)
    {
        if (player.eq[i].type == counter)
        {
            std::cout << "Uzyles " << player.eq[i].name << ", udalo Ci sie pokonac bestie bez zadnych strat! Niestety bron nie wytrzymala walki.\n";
            player.eq.erase(player.eq.begin() + (i));
            return 0;
        }
    }
    if (player.HP - EnemyDmg > 0)
    {
        std::cout << "Zwyciezyles po ciezkiej walce. Straciles " << EnemyDmg << "punktow zdrowia!\n";
    }
    else
    {
        std::cout << "Niestety, giniesz w walce " << std::endl;
    }

    return EnemyDmg;
}

void initItem(Page& page)
{
    page.isItem = true;
    unsigned int weapon = std::rand() % 4;
    std::string name = weapon_type[weapon];
    Item item;
    item.type = static_cast<Elemental>((std::rand() % 4));
    if (item.type == Elemental::EARTH)
    {
        item.name = "Zatruty " + name;
    }
    else if (item.type == Elemental::FIRE)
    {
        item.name = "Ognisty " + name;
    }
    else if (item.type == Elemental::WATER)
    {
        item.name = "Wodny " + name;
    }
    else
    {
        item.name = "Wietrzny " + name;
    }
    page.item = item;
}
void initHospital(Page& page) {
    page.isHospital = true;
    page.isEnemy = false;
    page.isItem = false;
    page.isOver = false;
    page.opis = "Natrafiles na zrodlo zycia wiecznego , dostajesz 30HP \n";
}
void initTraps(Page& page)
{
    page.isOver = true;
    int i = std::rand() % 3;
    page.opis = traps[i];
}

void showBackpack(Player player)
{
    if (player.eq.size() > 0)
    {
        std::cout << "\nPlecak:\n";
        for (int i = 0; i < player.eq.size(); i++)
        {
            std::cout << player.eq[i].name << std::endl;
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "\nNie posiadasz nic w plecaku." << std::endl;
    }

}

//Wykmin dodawanie stron 
std::vector<Page> initPages()
{
    srand(time(NULL));
    std::vector<Page> pages;

    pages.push_back(Page(0, "Wszedles w siedlisko smokow. W pomieszczeniu roznosi sie smrod siarki. Stare opuszczone elfickie ruiny, sluzace obecnie za wylegarnie zla, nigdys wspaniale dzis budza groze"));

    unsigned int opis;

    for (int i = 1; i <= 51; i++)
    {
        opis = (std::rand() % 10);// Losujemy liczbe od 0 d 9 

        pages.push_back(Page(i, describses[opis]));// dodajemy do wektora nową stronę z id i jednym z 10 opisów 
    }

    addUp(&pages[0], &pages[2]);

    for (int i = 1; i <= 46; i += 3)
    {
        addUp(&pages[i], &pages[i + 3]);
        addRight(&pages[i], &pages[i + 1]);

        addUp(&pages[i + 1], &pages[i + 4]);
        addRight(&pages[i + 1], &pages[i + 2]);

        addUp(&pages[i + 2], &pages[i + 5]);
    }

    //Traps:
    initTraps(pages[8]);

    //ItemSpawn:
    initItem(pages[2]);
    initItem(pages[6]);
    initItem(pages[33]);
    initItem(pages[41]);

    //EnemySpawn:
    initEnemy(pages[5]);
    initEnemy(pages[11]);
    initEnemy(pages[17]);
    initEnemy(pages[19]);
    initEnemy(pages[30]);
    initEnemy(pages[32]);
    initEnemy(pages[46]);
    initEnemy(pages[47]);
    initEnemy(pages[48]);

    //Źródło życia 
    initHospital(pages[16]);

    //Wygranie gry:
    initWin(pages[49]);
    initWin(pages[50]);
    initWin(pages[51]);

    return pages;
}

void newGame()
{
    srand(time(NULL)); // Liczby pseudolosowe 
    Player player;
    std::cout << "Podaj nazwe swojego bohatera: " << std::endl;
    std::cin >> player.imie;

    std::vector<Page> pages;
    std::cout << "Witaj " << player.imie << "\n\n";
    pages = initPages();
    int current = 0;
    bool isWin = false;
    while (player.HP > 0 && !isWin)
    {
        char choice;
        if (pages[current].isWin == true)
        {
            isWin = true;
        }
        std::cout << pages[current].opis << std::endl;

        if (pages[current].isOver)
        {
            player.HP = -1;
            continue;
        }
        if (pages[current].isHospital == true) {
            player.HP += 30;
            pages[current].isHospital = false;
            pages[current].opis = "W tym miejscu znajdowalo sie niegdys zdrodlo lecznicze , niestety wyschlo !";
        }

        if (pages[current].isEnemy)
        {
            int dmg = fight(player, pages[current].enemyType);
            player.HP -= dmg;
            if (player.HP < 0)
            {
                continue;
            }
            pages[current].isEnemy = false;
        }

        if (pages[current].isItem)
        {
            std::cout << "Dostrzegasz skrzynie! W srodku znajduje sie: " << pages[current].item.name << " \n";
            player.eq.push_back(pages[current].item);
            pages[current].isItem = false;
        }
        if (!isWin) {


            std::cout << std::endl;
            std::cout << "Wybierz akcje:             |*           HP:" << player.HP << std::endl;
            std::cout << "[W] Idz na polnoc          |*              " << std::endl;
            std::cout << "[S] Idz na poludnie        |*              " << std::endl;
            std::cout << "[D] Idz na wschod          |*              " << std::endl;
            std::cout << "[A] Idz na zachod          |*              " << std::endl;
            std::cout << "[E] Wyswietl wyposazenie   |*              " << std::endl;
            std::cout << std::endl;
            std::cin >> choice;
            switch (choice)
            {
            case 'w':
                if (pages[current].up != NULL)
                {
                    current = pages[current].up->id;
                }
                else
                    std::cout << "Nie mozna isc na polnoc" << std::endl;
                break;

            case 's':
                if (pages[current].down != NULL)
                {
                    current = pages[current].down->id;
                }
                else
                    std::cout << "Nie mozna isc na poludnie" << std::endl;
                break;

            case 'd':
                if (pages[current].right != NULL)
                {
                    current = pages[current].right->id;
                }
                else
                    std::cout << "Nie mozna isc na wschod" << std::endl;
                break;

            case 'a':
                if (pages[current].left != NULL)
                {
                    current = pages[current].left->id;
                }
                else
                    std::cout << "Nie mozna isc na zachod" << std::endl;
                break;

            case 'e':
                showBackpack(player);
                break;
            }
        }
    }
    if (isWin)
    {
        std::cout << "Wygrales gre!" << std::endl;
    }
    else
    {
        std::cout << "Przegrana                  __" << std::endl;
        std::cout << "------------------------- /R \\ " << std::endl;
        std::cout << "--------------------------| I|" << std::endl;
        std::cout << "--------------------------|P |" << std::endl;
        std::cout << "--------------------------~~~~" << std::endl;
    }
}

void Menu()
{
    //Zmienna służąca do poruszania się po menu 
    int choice;

    std::string error = ""; //Tworzymy zmienną przechowującą errory 

    do {
        std::cout << "\n\n";
        std::cout << "                                         (           " << std::endl;
        std::cout << "____________________________________        (        " << std::endl;
        std::cout << "|Witaj w Soul And Dragons! |///////|          )      " << std::endl;
        std::cout << "|Menu:                     |///////|         ()      " << std::endl;
        std::cout << "|                          |///////|        |--|     " << std::endl;
        std::cout << "| [1]Nowa Gra              |///////|        |  |     " << std::endl;
        std::cout << "|                          |///////|        |S |     " << std::endl;
        std::cout << "| [2]Autor                 |///////|        | A|     " << std::endl;
        std::cout << "|                          |///////|        |D |     " << std::endl;
        std::cout << "| [3]Koniec                |///////|      .-|  |-.   " << std::endl;
        std::cout << "|                          |///////|     :  |  |  :  " << std::endl;
        std::cout << "|                          |///////|     :  '--'  :  " << std::endl;
        std::cout << "|__________________________|_______|     '- .... -'  " << std::endl;
        if (error.length() > 0) // Sprawdzamy czy nie został przekazany błąd do zmiennej error 
        {
            std::cout << "~!~~ " << error << " ~~!~" << std::endl;
            error = "";
        }
        bool badChoice = false; // Sprawdza czy wszystko poszło okej 



        std::cin >> choice; // Wpisujemy wartość do choice 
        badChoice = !std::cin.good();
        if (badChoice)
        {
            std::cin.clear();// czyscimy cin
            std::cin.ignore(); // ignorujemy cin 
            choice = 0;
        }


        switch (choice) {
        case 0:
            error = "Error: prosze wpisac liczbe!";
            break;
        case 1:
            newGame();
            break;

        case 2:
            std::cout << "Kacper Machlus s24746 " << std::endl;
            break;

        case 3:
            std::cout << "Do zobaczenia !" << std::endl;
            break;

        default:
            
            error = "Error: Zly wybor";
            break;
        }
    } while (choice != 3);
}
// Wejście do funkcji menu 
int main()
{
    Menu();
}
