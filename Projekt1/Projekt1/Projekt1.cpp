// Projekt1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iostream>
#include "Sortowanie.h"
#include <fstream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <time.h>


using namespace std;


char wybor1;


int main()
{
    
    while (wybor1 != 'k') {
        cout << "jaka tablice chcesz sparwdzic \n";
        cout << "1. 100\n2. 10000\n3. 50000\n4. 100000\n5. 500000\n6. 1000000\nk. koniec testow\n";
        cin >> wybor1;
        srand(time(NULL));
        switch (wybor1) {
        case '1':
        {
        int rozmiar = 1000;
        menu_sortowania(rozmiar);
        }
            break;
        case '2':
        {
            int rozmiar = 10000;
            menu_sortowania(rozmiar);
        }
            break;
        case '3':
        {
            int rozmiar = 50000;
            menu_sortowania(rozmiar);
        }
            break;
        case '4':
        {
            int rozmiar = 100000;
            menu_sortowania(rozmiar);
        }
            break;
        case '5':
        {
            int rozmiar = 500000;
            menu_sortowania(rozmiar);
        }
            break;
        case '6':
        {
            int rozmiar = 1000000;
            menu_sortowania(rozmiar);
        }
            break;
        case 'k':

            break;
        default:
            break;
        }
    }
    return 0;
}

