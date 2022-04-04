#include <iostream>
#include <random>
#include <time.h>
#define PACZKA 100

using namespace std;


void sortowanie_quicksort(int* tablica, int lewy, int prawy)
{
    int v = tablica[(lewy + prawy) / 2];// wyznaczanie piwota
    int i, j, x;
    i = lewy;
    j = prawy;
    do
    {
        while (tablica[i] < v) i++; 
        while (tablica[j] > v) j--;
        if (i <= j)
        {
            x = tablica[i];
            tablica[i] = tablica[j];
            tablica[j] = x;
            i++;
            j--;
        }
    } while (i <= j);
    if (j > lewy) sortowanie_quicksort(tablica, lewy, j);// rekursywanie wywolujemy z lewej
    if (i < prawy) sortowanie_quicksort(tablica, i, prawy);// rekursywanie wywolujemy z prawej
}


void merge(int* tab, int lewy, int srodek, int prawy)
{
    int lSize = srodek - lewy + 1;
    int rSize = prawy - srodek;

    //Tablice pomocnicze
    int* tabL = new int[lSize];
    int* tabR = new int[rSize];

    // Kopiowanie danych do tablic pomocniczych
    for (int x = 0; x < lSize; x++)
        tabL[x] = tab[lewy + x];
    for (int y = 0; y < rSize; y++)
        tabR[y] = tab[srodek + 1 + y];

    int indexL = 0;
    int indexR = 0;
    int currIndex;

    //£¹czenie tablic R i L
    for (currIndex = lewy; indexL < lSize && indexR < rSize; currIndex++)
    {
        if (tabL[indexL] <= tabR[indexR])
            tab[currIndex] = tabL[indexL++];
        else
            tab[currIndex] = tabR[indexR++];
    }

    //Jeœli w tablicy tabL pozosta³y jeszcze jakieœ elementy
    //kopiujemy je
    while (indexL < lSize)
        tab[currIndex++] = tabL[indexL++];

    //Jeœli w tablicy tabR pozosta³y jeszcze jakieœ elementy
    //kopiujemy je
    while (indexR < rSize)
        tab[currIndex++] = tabR[indexR++];
    // Zwalnianie pamieci z niepotrzebnych tablic
    delete[] tabL;
    delete[] tabR;
}


void mergeSort(int* tab, int lewy, int prawy) {
    if (prawy > lewy) {
        int m = (lewy + prawy) / 2;
        mergeSort(tab, lewy, m);
        mergeSort(tab, m + 1, prawy);
        merge(tab, lewy, m, prawy);
    }
}


void shellSort(int *tab, int N)
{
    for (int gap = N / 2; gap > 0; gap /= 2)// tworzenie podzbiorow zaleznych od odstepu
    {
        for (int i = gap; i < N; i += 1) //porowanywanie liczb w podzbiorach
        {
            int temp = tab[i];

            int j;
            for (j = i; j >= gap && tab[j - gap] > temp; j -= gap)
                tab[j] = tab[j - gap];

            tab[j] = temp;
        }
    }
}

void mieszanie_tablicy(int* tab, int size, float procent) {
    for (int i = 0; i < size*procent; i++)
    {
        tab[i] = i;
    }
    for (int i = size * procent; i < size; i++)
    {
        tab[i] = rand() % 1000000 + size*procent;
    }
}

void menu_sortowania(int size) {
    
    
    clock_t start, start2, start3, stop, stop2, stop3;
    double czas1 = 0;
    double czas2 = 0;
    double czas3 = 0;
    char wybor2 = '0';
    while (wybor2 != 'k') {
        cout << "jak bardzo posortowana tablica ma byc? \n";
        cout << "1. wcale\n2. 25%\n3. 50%\n4. 75%\n5. 95%\n6. 99%\n7. 99,7%\n8. odwrotnie\nk koniec testow\n";
        cin >> wybor2;
        switch (wybor2) {
        case '1':
        {

            for (int i = 0; i < PACZKA; i++) {
            int* tablica = new int[size];
            int* tablica2 = new int[size];
            int* tablica3 = new int[size];

            mieszanie_tablicy(tablica, size, 0.0);

            for (int j = 0; j < size; j++)
            {
                tablica2[j] = tablica[j];
                tablica3[j] = tablica[j];
            }

            start = clock();

            sortowanie_quicksort(tablica, 0, size - 1);

            stop = clock();

            czas1 += (double)(stop - start) / CLOCKS_PER_SEC;

            start2 = clock();

            mergeSort(tablica2, 0, size - 1);

            stop2 = clock();
            czas2 += (double)(stop2 - start2) / CLOCKS_PER_SEC;

            start3 = clock();

            shellSort(tablica3, size);

            stop3 = clock();
            czas3 += (double)(stop3 - start3) / CLOCKS_PER_SEC;
           /* for (int j = 0; j < size; j++) {
               cout<< tablica2[j]<<" ";
            }
            cout << endl;*/
            delete[] tablica;
            delete[] tablica2;
            delete[] tablica3;
            }

            cout << endl << "czas œredni sortowania quicksort: " << czas1/ PACZKA << " s" << endl;
            cout << endl << "czas œredni sortowania przez scalanie: " << czas2/ PACZKA << " s" << endl;
            cout << endl << "czas œredni sortowania Shella: " << czas3/ PACZKA << " s" << endl;
            czas1 = 0;
            czas2 = 0;
            czas3 = 0;
        }
            break;
        case '2':
            for (int i = 0; i < PACZKA; i++) 
            {
                int* tablica = new int[size];
                int* tablica2 = new int[size];
                int* tablica3 = new int[size];
                mieszanie_tablicy(tablica, size, 0.25);
                
                for (int j = 0; j < size; j++)
                {
                    tablica2[j] = tablica[j];
                    tablica3[j] = tablica[j];
                }

                start = clock();

                sortowanie_quicksort(tablica, 0, size - 1);

                stop = clock();
                            
                czas1 += (double)(stop - start) / CLOCKS_PER_SEC;

                start2 = clock();

                mergeSort(tablica2, 0, size - 1);

                stop2 = clock();
                czas2 += (double)(stop2 - start2) / CLOCKS_PER_SEC;

                start3 = clock();

                shellSort(tablica3, size);

                stop3 = clock();
                czas3 += (double)(stop3 - start3) / CLOCKS_PER_SEC;

                delete[] tablica;
                delete[] tablica2;
                delete[] tablica3;

            }

            cout << endl << "czas œredni sortowania quicksort: " << czas1/PACZKA<< " s" << endl;
            cout << endl << "czas œredni sortowania przez scalanie: " << czas2/PACZKA << " s" << endl;
            cout << endl << "czas œredni sortowania Shella: " << czas3/PACZKA  << " s" << endl;
            czas1 = 0;
            czas2 = 0;
            czas3 = 0;
            break;
        case '3':
            for (int i = 0; i < PACZKA; i++) {
                int* tablica = new int[size];
                int* tablica2 = new int[size];
                int* tablica3 = new int[size];
                mieszanie_tablicy(tablica, size, 0.5);

                for (int j = 0; j < size; j++)
                {
                    tablica2[j] = tablica[j];
                    tablica3[j] = tablica[j];
                }

                start = clock();

                sortowanie_quicksort(tablica, 0, size - 1);

                stop = clock();

                czas1 += (double)(stop - start) / CLOCKS_PER_SEC;

                start2 = clock();

                mergeSort(tablica2, 0, size - 1);

                stop2 = clock();
                czas2 += (double)(stop2 - start2) / CLOCKS_PER_SEC;

                start3 = clock();

                shellSort(tablica3, size);

                stop3 = clock();
                czas3 += (double)(stop3 - start3) / CLOCKS_PER_SEC;

                delete[] tablica;
                delete[] tablica2;
                delete[] tablica3;
            }

            cout << endl << "czas sredni sortowania quicksort: " << czas1 / PACZKA << " s" << endl;
            cout << endl << "czas œredni sortowania przez scalanie: " << czas2 / PACZKA << " s" << endl;
            cout << endl << "czas œredni sortowania Shella: " << czas3 / PACZKA << " s" << endl;
            czas1 = 0;
            czas2 = 0;
            czas3 = 0;
            break;
        case '4':
            for (int i = 0; i < PACZKA; i++) {
                int* tablica = new int[size];
                int* tablica2 = new int[size];
                int* tablica3 = new int[size];
                mieszanie_tablicy(tablica, size, 0.75);

                for (int j = 0; j < size; j++)
                {
                    tablica2[j] = tablica[j];
                    tablica3[j] = tablica[j];
                }

                start = clock();

                sortowanie_quicksort(tablica, 0, size - 1);

                stop = clock();

                czas1 += (double)(stop - start) / CLOCKS_PER_SEC;

                start2 = clock();

                mergeSort(tablica2, 0, size - 1);

                stop2 = clock();
                czas2 += (double)(stop2 - start2) / CLOCKS_PER_SEC;

                start3 = clock();

                shellSort(tablica3, size);

                stop3 = clock();
                czas3 += (double)(stop3 - start3) / CLOCKS_PER_SEC;

                delete[] tablica;
                delete[] tablica2;
                delete[] tablica3;
            }

            cout << endl << "czas sredni sortowania quicksort: " << czas1 / PACZKA << " s" << endl;
            cout << endl << "czas œredni sortowania przez scalanie: " << czas2 / PACZKA << " s" << endl;
            cout << endl << "czas œredni sortowania Shella: " << czas3 / PACZKA << " s" << endl;
            czas1 = 0;
            czas2 = 0;
            czas3 = 0;
            break;
        case '5':
            for (int i = 0; i < PACZKA; i++) {
                int* tablica = new int[size];
                int* tablica2 = new int[size];
                int* tablica3 = new int[size];
                mieszanie_tablicy(tablica, size, 0.95);

                for (int j = 0; j < size; j++)
                {
                    tablica2[j] = tablica[j];
                    tablica3[j] = tablica[j];
                }

                start = clock();

                sortowanie_quicksort(tablica, 0, size - 1);

                stop = clock();

                czas1 += (double)(stop - start) / CLOCKS_PER_SEC;

                start2 = clock();

                mergeSort(tablica2, 0, size - 1);

                stop2 = clock();
                czas2 += (double)(stop2 - start2) / CLOCKS_PER_SEC;

                start3 = clock();

                shellSort(tablica3, size);

                stop3 = clock();
                czas3 += (double)(stop3 - start3) / CLOCKS_PER_SEC;

                delete[] tablica;
                delete[] tablica2;
                delete[] tablica3;
            }

            cout << endl << "czas sredni sortowania quicksort: " << czas1 / PACZKA << " s" << endl;
            cout << endl << "czas œredni sortowania przez scalanie: " << czas2 / PACZKA << " s" << endl;
            cout << endl << "czas œredni sortowania Shella: " << czas3 / PACZKA << " s" << endl;
            czas1 = 0;
            czas2 = 0;
            czas3 = 0;
            break;
        case '6':
            for (int i = 0; i < PACZKA; i++) {
                int* tablica = new int[size];
                int* tablica2 = new int[size];
                int* tablica3 = new int[size];
                mieszanie_tablicy(tablica, size, 0.99);
                
                for (int j = 0; j < size; j++)
                {
                    tablica2[j] = tablica[j];
                    tablica3[j] = tablica[j];
                }

                start = clock();

                sortowanie_quicksort(tablica, 0, size - 1);

                stop = clock();
                
                czas1 += (double)(stop - start) / CLOCKS_PER_SEC;

                start2 = clock();

                mergeSort(tablica2, 0, size - 1);

                stop2 = clock();
                czas2 += (double)(stop2 - start2) / CLOCKS_PER_SEC;

                start3 = clock();

                shellSort(tablica3, size);

                stop3 = clock();
                czas3 += (double)(stop3 - start3) / CLOCKS_PER_SEC;

                delete[] tablica;
                delete[] tablica2;
                delete[] tablica3;
            }

            cout << endl << "czas sredni sortowania quicksort: " << czas1 / PACZKA << " s" << endl;
            cout << endl << "czas œredni sortowania przez scalanie: " << czas2 / PACZKA << " s" << endl;
            cout << endl << "czas œredni sortowania Shella: " << czas3 / PACZKA << " s" << endl;
            czas1 = 0;
            czas2 = 0;
            czas3 = 0;
            break;

        case '7':
            for (int i = 0; i < PACZKA; i++) {
                int* tablica = new int[size];
                int* tablica2 = new int[size];
                int* tablica3 = new int[size];
                mieszanie_tablicy(tablica, size, 0.997);
                
                for (int j = 0; j < size; j++)
                {
                    tablica2[j] = tablica[j];
                    tablica3[j] = tablica[j];
                }

                start = clock();

                sortowanie_quicksort(tablica, 0, size - 1);

                stop = clock();

                czas1 += (double)(stop - start) / CLOCKS_PER_SEC;

                start2 = clock();

                mergeSort(tablica2, 0, size - 1);

                stop2 = clock();
                czas2 += (double)(stop2 - start2) / CLOCKS_PER_SEC;

                start3 = clock();

                shellSort(tablica3, size);

                stop3 = clock();
                czas3 += (double)(stop3 - start3) / CLOCKS_PER_SEC;

                delete[] tablica;
                delete[] tablica2;
                delete[] tablica3;
            }

            cout << endl << "czas sredni sortowania quicksort: " << czas1 / PACZKA << " s" << endl;
            cout << endl << "czas œredni sortowania przez scalanie: " << czas2 / PACZKA << " s" << endl;
            cout << endl << "czas œredni sortowania Shella: " << czas3 / PACZKA << " s" << endl;
            czas1 = 0;
            czas2 = 0;
            czas3 = 0;
            break;

        case '8': {
            
            
            for (int i = 0; i < PACZKA; i++) {
                int* tablica = new int[size];
                int* tablica2 = new int[size];
                int* tablica3 = new int[size];
                int j = 0;
                for (int k = size - 1; k >= 0; k--)
                {
                    tablica[j] = k;
                    tablica2[j] = k;
                    tablica3[j] = k;

                    j++;
                }
                
                start = clock();

                sortowanie_quicksort(tablica, 0, size - 1);

                stop = clock();

                czas1 += (double)(stop - start) / CLOCKS_PER_SEC;

                start2 = clock();

                mergeSort(tablica2, 0, size - 1);

                stop2 = clock();
                czas2 += (double)(stop2 - start2) / CLOCKS_PER_SEC;

                start3 = clock();

                shellSort(tablica3, size);

                stop3 = clock();
                czas3 += (double)(stop3 - start3) / CLOCKS_PER_SEC;

                delete[] tablica;
                delete[] tablica2;
                delete[] tablica3;
            }

            cout << endl << "czas sredni sortowania quicksort: " << czas1 / PACZKA << " s" << endl;
            cout << endl << "czas œredni sortowania przez scalanie: " << czas2 / PACZKA << " s" << endl;
            cout << endl << "czas œredni sortowania Shella: " << czas3 / PACZKA << " s" << endl;
            czas1 = 0;
            czas2 = 0;
            czas3 = 0;
        }
            break;

        case 'k':
            
            break;
        default:
            break;
        }
    }
}
