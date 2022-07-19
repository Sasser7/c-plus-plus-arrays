#ifndef ROZMIAR_TABLICY_DO_ZAD1
#define ROZMIAR_TABLICY_DO_ZAD1 50
#endif
#if ROZMIAR_TABLICY_DO_ZAD1 < 10 && ROZMIAR_TABLICY_DO_ZAD1 > 99
#error "niewlasciwy rozmiar tablicy"
#else
#define TABLICA_OK_LOG() std::cout << "rozmiar tablicy OK" << std::endl
#endif

#include <random>
#include <locale.h>
#include <iostream>

typedef int i_32;
using namespace std;

random_device silnik_losu;
mt19937 randomizer(silnik_losu());
uniform_int_distribution<i_32>zakres(1, 100);

// Zadanie 1
i_32* tab = new i_32[ROZMIAR_TABLICY_DO_ZAD1];

struct Zadania_Preview {
public:
    void Wylosuj() {
        this->prop1 = tab;
        for (i_32 i = 0; i < ROZMIAR_TABLICY_DO_ZAD1; i++)
        {
            prop1[i] = zakres(silnik_losu);
        }
    }

    virtual void zad3() {
        cout << "Zadanie 3" << endl;
    };
    virtual void zad4() {
        cout << "Zadanie 4" << endl;
    };
    virtual void zad5_6() {
        cout << "Zadanie 5 i 6" << endl;
    };
    virtual void zad7() {
        cout << "Zadanie 7" << endl;
    };
    virtual void zad8() {
        cout << "Zadanie 8" << endl;
    };
    virtual void zad9() {
        cout << "Zadanie 9" << endl;
    };

protected:
    i_32* prop1 = NULL;
};

class Zadania : public Zadania_Preview {
public:
    Zadania(){
        Wylosuj();
        for (i_32 i = 0; i < ROZMIAR_TABLICY_DO_ZAD1; i++)
        {
            // Zadanie 2
            cout << prop1[i] << endl;
        }
    }

    virtual void zad3() {
        system("cls");

        // Zadanie 3
#define PODANY_INDEX_ZAD2 2
        i_32 suma = NULL;

        prop1[PODANY_INDEX_ZAD2] = 207;
        prop1[((PODANY_INDEX_ZAD2 << PODANY_INDEX_ZAD2))] = -5;

        for (i_32 i = 0; i < ROZMIAR_TABLICY_DO_ZAD1; i++)
        {
            cout << prop1[i] << endl;
        }
    }

    virtual void zad4() {
        system("cls");

        i_32 suma = NULL;
        // Zadanie 4
        for (i_32 i = 0; i < ROZMIAR_TABLICY_DO_ZAD1; i++) {
            cout << prop1[i] << endl;
            suma += prop1[i];
        }

        if (suma != NULL)
            cout << "Suma wszystkich elementow tablicy wynosi: " << suma << endl;
        else
            throw (suma);
    }

    virtual void zad5_6() {
        system("cls");

        // Zadania 5 i 6
        Wylosuj();
        for (i_32 i = 0; i < ROZMIAR_TABLICY_DO_ZAD1; i++)
        {
            prop1[i] -= 50;
            if (prop1[i] < 0)
                cout << prop1[i] << endl;
        }
    }

    virtual void zad7() {
        system("cls");

        // Zadanie 7
        bool czy_jest_wiecej_niz_1 = false;
        for (i_32 i = 0; i < ROZMIAR_TABLICY_DO_ZAD1; i++)
        {
            if (prop1[i] % 2 == 0 && prop1[i] % 5 == 0)
            {
                czy_jest_wiecej_niz_1 = true;
                cout << prop1[i] << endl;
            }
        }
        switch (czy_jest_wiecej_niz_1)
        {
        case true:
            cout << "liczb podzielnych przez 2 i 5 jest wiecej niz 1!" << endl;
            break;
        default:
            cout << "Przykro mi, ale nie ma ani jednej liczby podzielnej przez 2 i 5" << endl;
            break;
        }
    }

    virtual void zad8() {
        system("cls");

        // Zadanie 8
         Wylosuj();
        i_32 najmniejsza_liczba = INT_MAX;
        i_32 najwieksza_liczba = NULL;
        for (i_32 i = 0; i < ROZMIAR_TABLICY_DO_ZAD1; i++)
        {
            if (prop1[i] > najwieksza_liczba)
                najwieksza_liczba = prop1[i];

            else if (prop1[i] < najmniejsza_liczba)
                najmniejsza_liczba = prop1[i];
        }

        cout << "Najmniejsza liczba to: " << najmniejsza_liczba << endl;
        cout << "Najwieksza liczba to: " << najwieksza_liczba << endl;
    }

    void Wykonaj(){

    }

    ~Zadania(){
        cout << "Zakonczono!" << endl;
    }

    struct Zadanie_dotatkowe {
    public:
        // Zadanie 9
        void Wykonaj() {
            system("cls");

            i_32 ilosc = 0;
            for (i_32 i = 0; i < ROZMIAR_TABLICY_DO_ZAD1; i++)
            {
                short s_p = 0;
                for (i_32 j = 2; j <= 10; j++)
                {
                    if (prop2[i] % j != 0)
                    {
                        s_p++;
                    }
                    if (s_p == 9)
                    {
                        cout << prop2[i] << endl;
                        ilosc++;
                    }
                }
            }
            cout << "liczb pierwszych jest: " << ilosc << endl;
        }
    private:
        i_32* prop2 = tab;
    };
private:
    
};

i_32 main(){
    setlocale(LC_ALL, "");

    Zadania zad;

    TABLICA_OK_LOG();
    Zadania_Preview* polmorf_zad_wsk = &zad;

    short wybor = 0;
    cout << "Ostrzezenie!\nZadania 1 i 2 sa wykonane kolejno w deklaracji stalej dla preprocesora, inicjalizacji tablicy i w metodzie losu wywolywanej w konstruktorze obiektu klasy Zadania" << endl << endl;
    cout << "Zadania 5 i 6 sa zawarte w jednej metodzie" << endl << endl;
    cout << "Podaj nr zadania: " << endl;
    cin >> wybor;
    system("cls");
    switch (wybor)
    {
    case 3:
        polmorf_zad_wsk->zad3();
        break;
    case 4:
        polmorf_zad_wsk->zad4();
        break;
    case 5:
        polmorf_zad_wsk->zad5_6();
        cout << "Zadania 5 i 6 sa zawarte w jednej metodzie" << endl;
        break;
    case 6:
        polmorf_zad_wsk->zad5_6();
        cout << "Zadania 5 i 6 sa zawarte w jednej metodzie" << endl;
        break;
    case 7:
        polmorf_zad_wsk->zad7();
        break;
    case 8:
        polmorf_zad_wsk->zad8();
        break;
    case 9:
        (new Zadania::Zadanie_dotatkowe)->Wykonaj();
        break;
    default:
        cout << "Zadania 1 i 2 sa wykonane kolejno w deklaracji stalej dla preprocesora, \ninicjalizacji tablicy i w metodzie losu wywolywanej w konstruktorze obiektu klasy Zadania" << endl;
        cout << "Nie ma takiego zadania" << endl;
        break;
    }
}