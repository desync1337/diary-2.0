#include <iostream>
#include <Windows.h>
#include <list>

using namespace std;

#define ANSI_COLOR_INVERSE "\033[7m"
#define ANSI_COLOR_RESET "\033[0m"

string menutype = "mainmenu";
list<string> mainoptionlist = {"Read Notes","Write Notes","quit"};

int choosenindex = 0;
int optioncount;

void draw(string menu) {

    if (menu == "mainmenu")
    {
        optioncount = mainoptionlist.size();
        system("cls");

        cout << "WELCOME TO DIARY 2.0" << endl;
        cout << "############################################//////////////////.....................\n" << endl;
        for (int i = 0; i < optioncount; i++) {

            list<string>::iterator it = mainoptionlist.begin();
            advance(it, i);

            if(i == choosenindex)
            {
                cout << ANSI_COLOR_INVERSE << i + 1 << "." << *it << ANSI_COLOR_RESET << std::endl;
            }
            else {
                cout << i + 1 << "." << *it << std::endl;
            }

        }
    }
    if (menu == "exit")
    {
        system("cls");
        cout << "GOODBYE \(^w^)" << endl;
        cout << ".................. . . . . . . .   .   .    .     .   \n" << endl;
    }
}

void switchmenu(string menu) {

    if (menu == "quit")
    {
        draw("exit");
        exit(1337);
    }

}


int main() {
    std::setlocale(LC_ALL, "ru_RU");        //
    SetConsoleTitleA("made in china");      //изменяем титульник консоли и
    draw("mainmenu");                       //       рендерим главное меню

    int timer = 50000;//таймер 
    bool inputallowed = true;

    while (1)
    {
        //check for input
        if (inputallowed == false) {  //            замедляем считывание нажатий тк я не знаю как считывать нажатие 1 раз.
            timer -= 1;               //            каждый раз когда мы нажимаем кнопку мы запрещаем очередной ввод
        }                             
                                      //            таймер считает до 50 тысяч и разрешает ввод (пиздец много ему считать)

        if (timer == 0) {
            inputallowed = true;
            timer = 50000;
       }

        // if i press key DOWN ###################
        if (GetKeyState(VK_DOWN) & 0x8000 && inputallowed == true)
        {
            inputallowed = false;
            if ((choosenindex + 2) > optioncount)
            {
                choosenindex = 0;
            }
            else {
                choosenindex += 1;
            }

            draw(menutype);
        }
        // if i press key UP ######################
        if (GetKeyState(VK_UP) & 0x8000 && inputallowed == true)
        {
            inputallowed = false;
            if ((choosenindex - 1) < 0)
            {
                choosenindex = optioncount;
            }
            choosenindex -= 1;
            draw(menutype);
        }
        if (GetKeyState(VK_RETURN) & 0x8000 && inputallowed == true)
        {
            inputallowed = false;

            list<string>::iterator it = mainoptionlist.begin();
            advance(it, choosenindex);

            switchmenu(*it);

        }
    }
}

