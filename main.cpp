#include <iostream>
#include <string>
#include <chrono>
#include "../headers/HashTableOpen.hpp"
#include "../headers/Generator.hpp"
#include "../headers/HashTableBucket.hpp"
#include "../headers/DynamicArray.hpp"

using namespace std;

int give_nanoseconds_between_time_stamps(auto timestamp_start, auto timestamp_end) {
    return chrono::duration_cast<chrono::nanoseconds>(timestamp_end - timestamp_start).count();
}

int main() {

    uint32_t seed = generateSeed(); //generowanie seedu
    //wygenerowane seedy uzyte do badan: 2001817738,
    //                                   3880338161,
    //                                   2268710009,
    //                                   659727510,
    //                                   563319034
    Uint32Generator gen(seed);

    //tworzenie tablic z losowymi liczbami 10'000, 15'000, 20'000, 25'000, 30'000, 35'000, 40'000, 45'000, 50'000
    const size_t arraySize10 = 10000;
    const size_t arraySize15 = 15000;
    const size_t arraySize20 = 20000;
    const size_t arraySize25 = 25000;
    const size_t arraySize30 = 30000;
    const size_t arraySize35 = 35000;
    const size_t arraySize40 = 40000;
    const size_t arraySize45 = 45000;
    const size_t arraySize50 = 50000;
    uint32_t array10[arraySize10];
    uint32_t array15[arraySize15];
    uint32_t array20[arraySize20];
    uint32_t array25[arraySize25];
    uint32_t array30[arraySize30];
    uint32_t array35[arraySize35];
    uint32_t array40[arraySize40];
    uint32_t array45[arraySize45];
    uint32_t array50[arraySize50];
    fillArray(array10, arraySize10, gen);
    fillArray(array15, arraySize15, gen);
    fillArray(array20, arraySize20, gen);
    fillArray(array25, arraySize25, gen);
    fillArray(array30, arraySize30, gen);
    fillArray(array35, arraySize35, gen);
    fillArray(array40, arraySize40, gen);
    fillArray(array45, arraySize45, gen);
    fillArray(array50, arraySize50, gen);

    //rozmiar poczatkowy - 100
    HashTableOpen hto10(100), hto15(100), hto20(100), hto25(100), hto30(100), hto35(100), hto40(100), hto45(100), hto50(100);
    HashTableBucket htb10(100), htb15(100), htb20(100), htb25(100), htb30(100), htb35(100), htb40(100), htb45(100), htb50(100);

    //MENU
    int choice;
    cout<<"1. pomiary insert dla tablicy mieszajacej z adresowaniem otwartym"<<endl;
    cout<<"2. pomiary remove dla tablicy mieszajacej z adresowaniem otwartym"<<endl;
    cout<<"3. pomiary insert dla tablicy mieszajacej z adresowaniem zamknietym"<<endl;
    cout<<"4. pomiary remove dla tablicy mieszajacej z adresowaniem zamknietym"<<endl;
    cout<<"(Wyniki pomiarow sa w nano sekundach)"<<endl;
    cout<<"Wybierz operacje:"<<endl;
    cin>>choice;
    switch (choice){
        case 1:{
            //////////////////////
            //POMIARY INSERT HTO//
            //////////////////////

            //pomiar insert dla tabeli mieszajacej z adresowaniem otwartym hto10
            auto timestamp_start10 = chrono::high_resolution_clock::now(); //poczatek pomiaru
            for (int i=0; i<arraySize10; i++) hto10.insert(std::to_string(array10[i]),(array10[i]/2));
            auto timestamp_end10 = chrono::high_resolution_clock::now(); //koniec pomiaru
            cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_start10, timestamp_end10);

            //pomiar insert dla tabeli mieszajacej z adresowaniem otwartym hto15
            auto timestamp_start15 = chrono::high_resolution_clock::now(); //poczatek pomiaru
            for (int i=0; i<arraySize15; i++) hto15.insert(std::to_string(array15[i]),(array15[i]/2));
            auto timestamp_end15 = chrono::high_resolution_clock::now(); //koniec pomiaru
            cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_start15, timestamp_end15);

            //pomiar insert dla tabeli mieszajacej z adresowaniem otwartym hto20
            auto timestamp_start20 = chrono::high_resolution_clock::now(); //poczatek pomiaru
            for (int i=0; i<arraySize20; i++) hto20.insert(std::to_string(array20[i]),(array20[i]/2));
            auto timestamp_end20 = chrono::high_resolution_clock::now(); //koniec pomiaru
            cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_start20, timestamp_end20);

            //pomiar insert dla tabeli mieszajacej z adresowaniem otwartym hto25
            auto timestamp_start25 = chrono::high_resolution_clock::now(); //poczatek pomiaru
            for (int i=0; i<arraySize25; i++) hto25.insert(std::to_string(array25[i]),(array25[i]/2));
            auto timestamp_end25 = chrono::high_resolution_clock::now(); //koniec pomiaru
            cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_start25, timestamp_end25);

            //pomiar insert dla tabeli mieszajacej z adresowaniem otwartym hto30
            auto timestamp_start30 = chrono::high_resolution_clock::now(); //poczatek pomiaru
            for (int i=0; i<arraySize30; i++) hto30.insert(std::to_string(array30[i]),(array30[i]/2));
            auto timestamp_end30 = chrono::high_resolution_clock::now(); //koniec pomiaru
            cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_start30, timestamp_end30);

            //pomiar insert dla tabeli mieszajacej z adresowaniem otwartym hto35
            auto timestamp_start35 = chrono::high_resolution_clock::now(); //poczatek pomiaru
            for (int i=0; i<arraySize35; i++) hto35.insert(std::to_string(array35[i]),(array35[i]/2));
            auto timestamp_end35 = chrono::high_resolution_clock::now(); //koniec pomiaru
            cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_start35, timestamp_end35);

            //pomiar insert dla tabeli mieszajacej z adresowaniem otwartym hto40
            auto timestamp_start40 = chrono::high_resolution_clock::now(); //poczatek pomiaru
            for (int i=0; i<arraySize40; i++) hto40.insert(std::to_string(array40[i]),(array40[i]/2));
            auto timestamp_end40 = chrono::high_resolution_clock::now(); //koniec pomiaru
            cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_start40, timestamp_end40);

            //pomiar insert dla tabeli mieszajacej z adresowaniem otwartym hto45
            auto timestamp_start45 = chrono::high_resolution_clock::now(); //poczatek pomiaru
            for (int i=0; i<arraySize45; i++) hto45.insert(std::to_string(array45[i]),(array45[i]/2));
            auto timestamp_end45 = chrono::high_resolution_clock::now(); //koniec pomiaru
            cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_start45, timestamp_end45);

            //pomiar insert dla tabeli mieszajacej z adresowaniem otwartym hto50
            auto timestamp_start50 = chrono::high_resolution_clock::now(); //poczatek pomiaru
            for (int i=0; i<arraySize50; i++) hto50.insert(std::to_string(array50[i]),(array50[i]/2));
            auto timestamp_end50 = chrono::high_resolution_clock::now(); //koniec pomiaru
            cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_start50, timestamp_end50);
            }
            break;
        case 2:{
            //insert hto
            for (int i=0; i<arraySize10; i++) hto10.insert(std::to_string(array10[i]),(array10[i]/2));
            for (int i=0; i<arraySize15; i++) hto15.insert(std::to_string(array15[i]),(array15[i]/2));
            for (int i=0; i<arraySize20; i++) hto20.insert(std::to_string(array20[i]),(array20[i]/2));
            for (int i=0; i<arraySize25; i++) hto25.insert(std::to_string(array25[i]),(array25[i]/2));
            for (int i=0; i<arraySize30; i++) hto30.insert(std::to_string(array30[i]),(array30[i]/2));
            for (int i=0; i<arraySize35; i++) hto35.insert(std::to_string(array35[i]),(array35[i]/2));
            for (int i=0; i<arraySize40; i++) hto40.insert(std::to_string(array40[i]),(array40[i]/2));
            for (int i=0; i<arraySize45; i++) hto45.insert(std::to_string(array45[i]),(array45[i]/2));
            for (int i=0; i<arraySize50; i++) hto50.insert(std::to_string(array50[i]),(array50[i]/2));


//////////////////////
//POMIARY REMOVE HTO//
//////////////////////
            cout<<"\n"<<"5 pomiarow remove na hto10:";
    //pomiar remove dla tabeli mieszajacej z adresowaniem otwartym hto10
    auto timestamp_start10r1 = chrono::high_resolution_clock::now();
    hto10.remove(std::to_string(array10[0]));
    auto timestamp_end10r1 = chrono::high_resolution_clock::now();
    cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_start10r1, timestamp_end10r1);

    //pomiar remove dla tabeli mieszajacej z adresowaniem otwartym hto10
    auto timestamp_start10r2 = chrono::high_resolution_clock::now();
    hto10.remove(std::to_string(array10[10]));
    auto timestamp_end10r2 = chrono::high_resolution_clock::now();
    cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_start10r2, timestamp_end10r2);

    //pomiar remove dla tabeli mieszajacej z adresowaniem otwartym hto10
    auto timestamp_start10r3 = chrono::high_resolution_clock::now();
    hto10.remove(std::to_string(array10[20]));
    auto timestamp_end10r3 = chrono::high_resolution_clock::now();
    cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_start10r3, timestamp_end10r3);

    //pomiar remove dla tabeli mieszajacej z adresowaniem otwartym hto10
    auto timestamp_start10r4 = chrono::high_resolution_clock::now();
    hto10.remove(std::to_string(array10[30]));
    auto timestamp_end10r4 = chrono::high_resolution_clock::now();
    cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_start10r4, timestamp_end10r4);

    //pomiar remove dla tabeli mieszajacej z adresowaniem otwartym hto10
    auto timestamp_start10r5 = chrono::high_resolution_clock::now();
    hto10.remove(std::to_string(array10[40]));
    auto timestamp_end10r5 = chrono::high_resolution_clock::now();
    cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_start10r5, timestamp_end10r5);

    cout<<"\n"<<"5 pomiarow remove na hto15:";
    //pomiar remove dla tabeli mieszajacej z adresowaniem otwartym hto15
    auto timestamp_start15r1 = chrono::high_resolution_clock::now();
    hto15.remove(std::to_string(array15[0]));
    auto timestamp_end15r1 = chrono::high_resolution_clock::now();
    cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_start15r1, timestamp_end15r1);

    //pomiar remove dla tabeli mieszajacej z adresowaniem otwartym hto15
    auto timestamp_start15r2 = chrono::high_resolution_clock::now();
    hto15.remove(std::to_string(array15[15]));
    auto timestamp_end15r2 = chrono::high_resolution_clock::now();
    cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_start15r2, timestamp_end15r2);

    //pomiar remove dla tabeli mieszajacej z adresowaniem otwartym hto15
    auto timestamp_start15r3 = chrono::high_resolution_clock::now();
    hto15.remove(std::to_string(array15[20]));
    auto timestamp_end15r3 = chrono::high_resolution_clock::now();
    cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_start15r3, timestamp_end15r3);

    //pomiar remove dla tabeli mieszajacej z adresowaniem otwartym hto15
    auto timestamp_start15r4 = chrono::high_resolution_clock::now();
    hto15.remove(std::to_string(array15[30]));
    auto timestamp_end15r4 = chrono::high_resolution_clock::now();
    cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_start15r4, timestamp_end15r4);

    //pomiar remove dla tabeli mieszajacej z adresowaniem otwartym hto15
    auto timestamp_start15r5 = chrono::high_resolution_clock::now();
    hto15.remove(std::to_string(array15[40]));
    auto timestamp_end15r5 = chrono::high_resolution_clock::now();
    cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_start15r5, timestamp_end15r5);

    cout<<"\n"<<"5 pomiarow remove na hto20:";
    //pomiar remove dla tabeli mieszajacej z adresowaniem otwartym hto20
    auto timestamp_start20r1 = chrono::high_resolution_clock::now();
    hto20.remove(std::to_string(array20[0]));
    auto timestamp_end20r1 = chrono::high_resolution_clock::now();
    cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_start20r1, timestamp_end20r1);

    //pomiar remove dla tabeli mieszajacej z adresowaniem otwartym hto20
    auto timestamp_start20r2 = chrono::high_resolution_clock::now();
    hto20.remove(std::to_string(array20[20]));
    auto timestamp_end20r2 = chrono::high_resolution_clock::now();
    cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_start20r2, timestamp_end20r2);

    //pomiar remove dla tabeli mieszajacej z adresowaniem otwartym hto20
    auto timestamp_start20r3 = chrono::high_resolution_clock::now();
    hto20.remove(std::to_string(array20[20]));
    auto timestamp_end20r3 = chrono::high_resolution_clock::now();
    cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_start20r3, timestamp_end20r3);

    //pomiar remove dla tabeli mieszajacej z adresowaniem otwartym hto20
    auto timestamp_start20r4 = chrono::high_resolution_clock::now();
    hto20.remove(std::to_string(array20[30]));
    auto timestamp_end20r4 = chrono::high_resolution_clock::now();
    cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_start20r4, timestamp_end20r4);

    //pomiar remove dla tabeli mieszajacej z adresowaniem otwartym hto20
    auto timestamp_start20r5 = chrono::high_resolution_clock::now();
    hto20.remove(std::to_string(array20[40]));
    auto timestamp_end20r5 = chrono::high_resolution_clock::now();
    cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_start20r5, timestamp_end20r5);

    cout<<"\n"<<"5 pomiarow remove na hto25:";
    //pomiar remove dla tabeli mieszajacej z adresowaniem otwartym hto25
    auto timestamp_start25r1 = chrono::high_resolution_clock::now();
    hto25.remove(std::to_string(array25[0]));
    auto timestamp_end25r1 = chrono::high_resolution_clock::now();
    cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_start25r1, timestamp_end25r1);

    //pomiar remove dla tabeli mieszajacej z adresowaniem otwartym hto25
    auto timestamp_start25r2 = chrono::high_resolution_clock::now();
    hto25.remove(std::to_string(array25[25]));
    auto timestamp_end25r2 = chrono::high_resolution_clock::now();
    cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_start25r2, timestamp_end25r2);

    //pomiar remove dla tabeli mieszajacej z adresowaniem otwartym hto25
    auto timestamp_start25r3 = chrono::high_resolution_clock::now();
    hto25.remove(std::to_string(array25[25]));
    auto timestamp_end25r3 = chrono::high_resolution_clock::now();
    cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_start25r3, timestamp_end25r3);

    //pomiar remove dla tabeli mieszajacej z adresowaniem otwartym hto25
    auto timestamp_start25r4 = chrono::high_resolution_clock::now();
    hto25.remove(std::to_string(array25[30]));
    auto timestamp_end25r4 = chrono::high_resolution_clock::now();
    cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_start25r4, timestamp_end25r4);

    //pomiar remove dla tabeli mieszajacej z adresowaniem otwartym hto25
    auto timestamp_start25r5 = chrono::high_resolution_clock::now();
    hto25.remove(std::to_string(array25[40]));
    auto timestamp_end25r5 = chrono::high_resolution_clock::now();
    cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_start25r5, timestamp_end25r5);

    cout<<"\n"<<"5 pomiarow remove na hto30:";
    //pomiar remove dla tabeli mieszajacej z adresowaniem otwartym hto30
    auto timestamp_start30r1 = chrono::high_resolution_clock::now();
    hto30.remove(std::to_string(array30[0]));
    auto timestamp_end30r1 = chrono::high_resolution_clock::now();
    cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_start30r1, timestamp_end30r1);

    //pomiar remove dla tabeli mieszajacej z adresowaniem otwartym hto30
    auto timestamp_start30r2 = chrono::high_resolution_clock::now();
    hto30.remove(std::to_string(array30[30]));
    auto timestamp_end30r2 = chrono::high_resolution_clock::now();
    cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_start30r2, timestamp_end30r2);

    //pomiar remove dla tabeli mieszajacej z adresowaniem otwartym hto30
    auto timestamp_start30r3 = chrono::high_resolution_clock::now();
    hto30.remove(std::to_string(array30[30]));
    auto timestamp_end30r3 = chrono::high_resolution_clock::now();
    cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_start30r3, timestamp_end30r3);

    //pomiar remove dla tabeli mieszajacej z adresowaniem otwartym hto30
    auto timestamp_start30r4 = chrono::high_resolution_clock::now();
    hto30.remove(std::to_string(array30[30]));
    auto timestamp_end30r4 = chrono::high_resolution_clock::now();
    cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_start30r4, timestamp_end30r4);

    //pomiar remove dla tabeli mieszajacej z adresowaniem otwartym hto30
    auto timestamp_start30r5 = chrono::high_resolution_clock::now();
    hto30.remove(std::to_string(array30[40]));
    auto timestamp_end30r5 = chrono::high_resolution_clock::now();
    cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_start30r5, timestamp_end30r5);

    cout<<"\n"<<"5 pomiarow remove na hto35:";
    //pomiar remove dla tabeli mieszajacej z adresowaniem otwartym hto35
    auto timestamp_start35r1 = chrono::high_resolution_clock::now();
    hto35.remove(std::to_string(array35[0]));
    auto timestamp_end35r1 = chrono::high_resolution_clock::now();
    cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_start35r1, timestamp_end35r1);

    //pomiar remove dla tabeli mieszajacej z adresowaniem otwartym hto35
    auto timestamp_start35r2 = chrono::high_resolution_clock::now();
    hto35.remove(std::to_string(array35[35]));
    auto timestamp_end35r2 = chrono::high_resolution_clock::now();
    cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_start35r2, timestamp_end35r2);

    //pomiar remove dla tabeli mieszajacej z adresowaniem otwartym hto35
    auto timestamp_start35r3 = chrono::high_resolution_clock::now();
    hto35.remove(std::to_string(array35[35]));
    auto timestamp_end35r3 = chrono::high_resolution_clock::now();
    cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_start35r3, timestamp_end35r3);

    //pomiar remove dla tabeli mieszajacej z adresowaniem otwartym hto35
    auto timestamp_start35r4 = chrono::high_resolution_clock::now();
    hto35.remove(std::to_string(array35[35]));
    auto timestamp_end35r4 = chrono::high_resolution_clock::now();
    cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_start35r4, timestamp_end35r4);

    //pomiar remove dla tabeli mieszajacej z adresowaniem otwartym hto35
    auto timestamp_start35r5 = chrono::high_resolution_clock::now();
    hto35.remove(std::to_string(array35[40]));
    auto timestamp_end35r5 = chrono::high_resolution_clock::now();
    cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_start35r5, timestamp_end35r5);

    cout<<"\n"<<"5 pomiarow remove na hto40:";
    //pomiar remove dla tabeli mieszajacej z adresowaniem otwartym hto40
    auto timestamp_start40r1 = chrono::high_resolution_clock::now();
    hto40.remove(std::to_string(array40[0]));
    auto timestamp_end40r1 = chrono::high_resolution_clock::now();
    cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_start40r1, timestamp_end40r1);

    //pomiar remove dla tabeli mieszajacej z adresowaniem otwartym hto40
    auto timestamp_start40r2 = chrono::high_resolution_clock::now();
    hto40.remove(std::to_string(array40[40]));
    auto timestamp_end40r2 = chrono::high_resolution_clock::now();
    cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_start40r2, timestamp_end40r2);

    //pomiar remove dla tabeli mieszajacej z adresowaniem otwartym hto40
    auto timestamp_start40r3 = chrono::high_resolution_clock::now();
    hto40.remove(std::to_string(array40[40]));
    auto timestamp_end40r3 = chrono::high_resolution_clock::now();
    cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_start40r3, timestamp_end40r3);

    //pomiar remove dla tabeli mieszajacej z adresowaniem otwartym hto40
    auto timestamp_start40r4 = chrono::high_resolution_clock::now();
    hto40.remove(std::to_string(array40[40]));
    auto timestamp_end40r4 = chrono::high_resolution_clock::now();
    cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_start40r4, timestamp_end40r4);

    //pomiar remove dla tabeli mieszajacej z adresowaniem otwartym hto40
    auto timestamp_start40r5 = chrono::high_resolution_clock::now();
    hto40.remove(std::to_string(array40[40]));
    auto timestamp_end40r5 = chrono::high_resolution_clock::now();
    cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_start40r5, timestamp_end40r5);

    cout<<"\n"<<"5 pomiarow remove na hto45:";
    //pomiar remove dla tabeli mieszajacej z adresowaniem otwartym hto45
    auto timestamp_start45r1 = chrono::high_resolution_clock::now();
    hto45.remove(std::to_string(array45[0]));
    auto timestamp_end45r1 = chrono::high_resolution_clock::now();
    cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_start45r1, timestamp_end45r1);

    //pomiar remove dla tabeli mieszajacej z adresowaniem otwartym hto45
    auto timestamp_start45r2 = chrono::high_resolution_clock::now();
    hto45.remove(std::to_string(array45[45]));
    auto timestamp_end45r2 = chrono::high_resolution_clock::now();
    cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_start45r2, timestamp_end45r2);

    //pomiar remove dla tabeli mieszajacej z adresowaniem otwartym hto45
    auto timestamp_start45r3 = chrono::high_resolution_clock::now();
    hto45.remove(std::to_string(array45[45]));
    auto timestamp_end45r3 = chrono::high_resolution_clock::now();
    cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_start45r3, timestamp_end45r3);

    //pomiar remove dla tabeli mieszajacej z adresowaniem otwartym hto45
    auto timestamp_start45r4 = chrono::high_resolution_clock::now();
    hto45.remove(std::to_string(array45[45]));
    auto timestamp_end45r4 = chrono::high_resolution_clock::now();
    cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_start45r4, timestamp_end45r4);

    //pomiar remove dla tabeli mieszajacej z adresowaniem otwartym hto45
    auto timestamp_start45r5 = chrono::high_resolution_clock::now();
    hto45.remove(std::to_string(array45[45]));
    auto timestamp_end45r5 = chrono::high_resolution_clock::now();
    cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_start45r5, timestamp_end45r5);

    cout<<"\n"<<"5 pomiarow remove na hto50:";
    //pomiar remove dla tabeli mieszajacej z adresowaniem otwartym hto50
    auto timestamp_start50r1 = chrono::high_resolution_clock::now();
    hto50.remove(std::to_string(array50[0]));
    auto timestamp_end50r1 = chrono::high_resolution_clock::now();
    cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_start50r1, timestamp_end50r1);

    //pomiar remove dla tabeli mieszajacej z adresowaniem otwartym hto50
    auto timestamp_start50r2 = chrono::high_resolution_clock::now();
    hto50.remove(std::to_string(array50[50]));
    auto timestamp_end50r2 = chrono::high_resolution_clock::now();
    cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_start50r2, timestamp_end50r2);

    //pomiar remove dla tabeli mieszajacej z adresowaniem otwartym hto50
    auto timestamp_start50r3 = chrono::high_resolution_clock::now();
    hto50.remove(std::to_string(array50[50]));
    auto timestamp_end50r3 = chrono::high_resolution_clock::now();
    cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_start50r3, timestamp_end50r3);

    //pomiar remove dla tabeli mieszajacej z adresowaniem otwartym hto50
    auto timestamp_start50r4 = chrono::high_resolution_clock::now();
    hto50.remove(std::to_string(array50[50]));
    auto timestamp_end50r4 = chrono::high_resolution_clock::now();
    cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_start50r4, timestamp_end50r4);

    //pomiar remove dla tabeli mieszajacej z adresowaniem otwartym hto50
    auto timestamp_start50r5 = chrono::high_resolution_clock::now();
    hto50.remove(std::to_string(array50[50]));
    auto timestamp_end50r5 = chrono::high_resolution_clock::now();
    cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_start50r5, timestamp_end50r5);

            }
            break;
        case 3:{
        //////////////////////
        //POMIARY INSERT HTB//
        //////////////////////
        //pomiar insert dla tabeli mieszajacej z adresowaniem zamknietym, kubelki z tablica dynamiczna, htb10
        auto timestamp_startb10 = chrono::high_resolution_clock::now(); //poczatek pomiaru
        for (int i=0; i<arraySize10; i++) htb10.insert(std::to_string(array10[i]),(array10[i]/2));
        auto timestamp_endb10 = chrono::high_resolution_clock::now(); //koniec pomiaru
        cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_startb10, timestamp_endb10);

        //pomiar insert dla tabeli mieszajacej z adresowaniem zamknietym, kubelki z tablica dynamiczna, htb15
        auto timestamp_startb15 = chrono::high_resolution_clock::now(); //poczatek pomiaru
        for (int i=0; i<arraySize15; i++) htb15.insert(std::to_string(array15[i]),(array15[i]/2));
        auto timestamp_endb15 = chrono::high_resolution_clock::now(); //koniec pomiaru
        cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_startb15, timestamp_endb15);

        //pomiar insert dla tabeli mieszajacej z adresowaniem zamknietym, kubelki z tablica dynamiczna, htb20
        auto timestamp_startb20 = chrono::high_resolution_clock::now(); //poczatek pomiaru
        for (int i=0; i<arraySize20; i++) htb20.insert(std::to_string(array20[i]),(array20[i]/2));
        auto timestamp_endb20 = chrono::high_resolution_clock::now(); //koniec pomiaru
        cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_startb20, timestamp_endb20);

        //pomiar insert dla tabeli mieszajacej z adresowaniem zamknietym, kubelki z tablica dynamiczna, htb25
        auto timestamp_startb25 = chrono::high_resolution_clock::now(); //poczatek pomiaru
        for (int i=0; i<arraySize25; i++) htb25.insert(std::to_string(array25[i]),(array25[i]/2));
        auto timestamp_endb25 = chrono::high_resolution_clock::now(); //koniec pomiaru
        cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_startb25, timestamp_endb25);

        //pomiar insert dla tabeli mieszajacej z adresowaniem zamknietym, kubelki z tablica dynamiczna, htb30
        auto timestamp_startb30 = chrono::high_resolution_clock::now(); //poczatek pomiaru
        for (int i=0; i<arraySize30; i++) htb30.insert(std::to_string(array30[i]),(array30[i]/2));
        auto timestamp_endb30 = chrono::high_resolution_clock::now(); //koniec pomiaru
        cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_startb30, timestamp_endb30);

        //pomiar insert dla tabeli mieszajacej z adresowaniem zamknietym, kubelki z tablica dynamiczna, htb35
        auto timestamp_startb35 = chrono::high_resolution_clock::now(); //poczatek pomiaru
        for (int i=0; i<arraySize35; i++) htb35.insert(std::to_string(array35[i]),(array35[i]/2));
        auto timestamp_endb35 = chrono::high_resolution_clock::now(); //koniec pomiaru
        cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_startb35, timestamp_endb35);

        //pomiar insert dla tabeli mieszajacej z adresowaniem zamknietym, kubelki z tablica dynamiczna, htb40
        auto timestamp_startb40 = chrono::high_resolution_clock::now(); //poczatek pomiaru
        for (int i=0; i<arraySize40; i++) htb40.insert(std::to_string(array40[i]),(array40[i]/2));
        auto timestamp_endb40 = chrono::high_resolution_clock::now(); //koniec pomiaru
        cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_startb40, timestamp_endb40);

        //pomiar insert dla tabeli mieszajacej z adresowaniem zamknietym, kubelki z tablica dynamiczna, htb45
        auto timestamp_startb45 = chrono::high_resolution_clock::now(); //poczatek pomiaru
        for (int i=0; i<arraySize45; i++) htb45.insert(std::to_string(array45[i]),(array45[i]/2));
        auto timestamp_endb45 = chrono::high_resolution_clock::now(); //koniec pomiaru
        cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_startb45, timestamp_endb45);

        //pomiar insert dla tabeli mieszajacej z adresowaniem zamknietym, kubelki z tablica dynamiczna, htb50
        auto timestamp_startb50 = chrono::high_resolution_clock::now(); //poczatek pomiaru
        for (int i=0; i<arraySize50; i++) htb50.insert(std::to_string(array50[i]),(array50[i]/2));
        auto timestamp_endb50 = chrono::high_resolution_clock::now(); //koniec pomiaru
        cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_startb50, timestamp_endb50);
        }
            break;
        case 4:{
        //insert htb
        for (int i=0; i<arraySize10; i++) htb10.insert(std::to_string(array10[i]),(array10[i]/2));
        for (int i=0; i<arraySize15; i++) htb15.insert(std::to_string(array15[i]),(array15[i]/2));
        for (int i=0; i<arraySize20; i++) htb20.insert(std::to_string(array20[i]),(array20[i]/2));
        for (int i=0; i<arraySize25; i++) htb25.insert(std::to_string(array25[i]),(array25[i]/2));
        for (int i=0; i<arraySize30; i++) htb30.insert(std::to_string(array30[i]),(array30[i]/2));
        for (int i=0; i<arraySize35; i++) htb35.insert(std::to_string(array35[i]),(array35[i]/2));
        for (int i=0; i<arraySize40; i++) htb40.insert(std::to_string(array40[i]),(array40[i]/2));
        for (int i=0; i<arraySize45; i++) htb45.insert(std::to_string(array45[i]),(array45[i]/2));
        for (int i=0; i<arraySize50; i++) htb50.insert(std::to_string(array50[i]),(array50[i]/2));

        cout<<"\n"<<"5 pomiarow remove na htb10:";
        //pomiar remove dla tabeli mieszajacej z adresowaniem zamknietym, kubelki z tablica dynamiczna, htb10
        auto timestamp_startb10r1 = chrono::high_resolution_clock::now();
        htb10.remove(std::to_string(array10[0]));
        auto timestamp_endb10r1 = chrono::high_resolution_clock::now();
        cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_startb10r1, timestamp_endb10r1);

        //pomiar remove dla tabeli mieszajacej z adresowaniem zamknietym, kubelki z tablica dynamiczna, htb10
        auto timestamp_startb10r2 = chrono::high_resolution_clock::now();
        htb10.remove(std::to_string(array10[10]));
        auto timestamp_endb10r2 = chrono::high_resolution_clock::now();
        cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_startb10r2, timestamp_endb10r2);

        //pomiar remove dla tabeli mieszajacej z adresowaniem zamknietym, kubelki z tablica dynamiczna, htb10
        auto timestamp_startb10r3 = chrono::high_resolution_clock::now();
        htb10.remove(std::to_string(array10[20]));
        auto timestamp_endb10r3 = chrono::high_resolution_clock::now();
        cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_startb10r3, timestamp_endb10r3);

        //pomiar remove dla tabeli mieszajacej z adresowaniem zamknietym, kubelki z tablica dynamiczna, htb10
        auto timestamp_startb10r4 = chrono::high_resolution_clock::now();
        htb10.remove(std::to_string(array10[30]));
        auto timestamp_endb10r4 = chrono::high_resolution_clock::now();
        cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_startb10r4, timestamp_endb10r4);

        //pomiar remove dla tabeli mieszajacej z adresowaniem zamknietym, kubelki z tablica dynamiczna, htb10
        auto timestamp_startb10r5 = chrono::high_resolution_clock::now();
        htb10.remove(std::to_string(array10[40]));
        auto timestamp_endb10r5 = chrono::high_resolution_clock::now();
        cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_startb10r5, timestamp_endb10r5);

        cout<<"\n"<<"5 pomiarow remove na htb15:";
        //pomiar remove dla tabeli mieszajacej z adresowaniem zamknietym, kubelki z tablica dynamiczna, htb15
        auto timestamp_startb15r1 = chrono::high_resolution_clock::now();
        htb15.remove(std::to_string(array15[0]));
        auto timestamp_endb15r1 = chrono::high_resolution_clock::now();
        cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_startb15r1, timestamp_endb15r1);

        //pomiar remove dla tabeli mieszajacej z adresowaniem zamknietym, kubelki z tablica dynamiczna, htb15
        auto timestamp_startb15r2 = chrono::high_resolution_clock::now();
        htb15.remove(std::to_string(array15[15]));
        auto timestamp_endb15r2 = chrono::high_resolution_clock::now();
        cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_startb15r2, timestamp_endb15r2);

        //pomiar remove dla tabeli mieszajacej z adresowaniem zamknietym, kubelki z tablica dynamiczna, htb15
        auto timestamp_startb15r3 = chrono::high_resolution_clock::now();
        htb15.remove(std::to_string(array15[20]));
        auto timestamp_endb15r3 = chrono::high_resolution_clock::now();
        cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_startb15r3, timestamp_endb15r3);

        //pomiar remove dla tabeli mieszajacej z adresowaniem zamknietym, kubelki z tablica dynamiczna, htb15
        auto timestamp_startb15r4 = chrono::high_resolution_clock::now();
        htb15.remove(std::to_string(array15[30]));
        auto timestamp_endb15r4 = chrono::high_resolution_clock::now();
        cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_startb15r4, timestamp_endb15r4);

        //pomiar remove dla tabeli mieszajacej z adresowaniem zamknietym, kubelki z tablica dynamiczna, htb15
        auto timestamp_startb15r5 = chrono::high_resolution_clock::now();
        htb15.remove(std::to_string(array15[40]));
        auto timestamp_endb15r5 = chrono::high_resolution_clock::now();
        cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_startb15r5, timestamp_endb15r5);

        cout<<"\n"<<"5 pomiarow remove na htb20:";
        //pomiar remove dla tabeli mieszajacej z adresowaniem zamknietym, kubelki z tablica dynamiczna, htb20
        auto timestamp_startb20r1 = chrono::high_resolution_clock::now();
        htb20.remove(std::to_string(array20[0]));
        auto timestamp_endb20r1 = chrono::high_resolution_clock::now();
        cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_startb20r1, timestamp_endb20r1);

        //pomiar remove dla tabeli mieszajacej z adresowaniem zamknietym, kubelki z tablica dynamiczna, htb20
        auto timestamp_startb20r2 = chrono::high_resolution_clock::now();
        htb20.remove(std::to_string(array20[20]));
        auto timestamp_endb20r2 = chrono::high_resolution_clock::now();
        cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_startb20r2, timestamp_endb20r2);

        //pomiar remove dla tabeli mieszajacej z adresowaniem zamknietym, kubelki z tablica dynamiczna, htb20
        auto timestamp_startb20r3 = chrono::high_resolution_clock::now();
        htb20.remove(std::to_string(array20[20]));
        auto timestamp_endb20r3 = chrono::high_resolution_clock::now();
        cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_startb20r3, timestamp_endb20r3);

        //pomiar remove dla tabeli mieszajacej z adresowaniem zamknietym, kubelki z tablica dynamiczna, htb20
        auto timestamp_startb20r4 = chrono::high_resolution_clock::now();
        htb20.remove(std::to_string(array20[30]));
        auto timestamp_endb20r4 = chrono::high_resolution_clock::now();
        cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_startb20r4, timestamp_endb20r4);

        //pomiar remove dla tabeli mieszajacej z adresowaniem zamknietym, kubelki z tablica dynamiczna, htb20
        auto timestamp_startb20r5 = chrono::high_resolution_clock::now();
        htb20.remove(std::to_string(array20[40]));
        auto timestamp_endb20r5 = chrono::high_resolution_clock::now();
        cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_startb20r5, timestamp_endb20r5);

        cout<<"\n"<<"5 pomiarow remove na htb25:";
        //pomiar remove dla tabeli mieszajacej z adresowaniem zamknietym, kubelki z tablica dynamiczna, htb25
        auto timestamp_startb25r1 = chrono::high_resolution_clock::now();
        htb25.remove(std::to_string(array25[0]));
        auto timestamp_endb25r1 = chrono::high_resolution_clock::now();
        cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_startb25r1, timestamp_endb25r1);

        //pomiar remove dla tabeli mieszajacej z adresowaniem zamknietym, kubelki z tablica dynamiczna, htb25
        auto timestamp_startb25r2 = chrono::high_resolution_clock::now();
        htb25.remove(std::to_string(array25[25]));
        auto timestamp_endb25r2 = chrono::high_resolution_clock::now();
        cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_startb25r2, timestamp_endb25r2);

        //pomiar remove dla tabeli mieszajacej z adresowaniem zamknietym, kubelki z tablica dynamiczna, htb25
        auto timestamp_startb25r3 = chrono::high_resolution_clock::now();
        htb25.remove(std::to_string(array25[25]));
        auto timestamp_endb25r3 = chrono::high_resolution_clock::now();
        cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_startb25r3, timestamp_endb25r3);

        //pomiar remove dla tabeli mieszajacej z adresowaniem zamknietym, kubelki z tablica dynamiczna, htb25
        auto timestamp_startb25r4 = chrono::high_resolution_clock::now();
        htb25.remove(std::to_string(array25[30]));
        auto timestamp_endb25r4 = chrono::high_resolution_clock::now();
        cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_startb25r4, timestamp_endb25r4);

        //pomiar remove dla tabeli mieszajacej z adresowaniem zamknietym, kubelki z tablica dynamiczna, htb25
        auto timestamp_startb25r5 = chrono::high_resolution_clock::now();
        htb25.remove(std::to_string(array25[40]));
        auto timestamp_endb25r5 = chrono::high_resolution_clock::now();
        cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_startb25r5, timestamp_endb25r5);

        cout<<"\n"<<"5 pomiarow remove na htb30:";
        //pomiar remove dla tabeli mieszajacej z adresowaniem zamknietym, kubelki z tablica dynamiczna, htb30
        auto timestamp_startb30r1 = chrono::high_resolution_clock::now();
        htb30.remove(std::to_string(array30[0]));
        auto timestamp_endb30r1 = chrono::high_resolution_clock::now();
        cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_startb30r1, timestamp_endb30r1);

        //pomiar remove dla tabeli mieszajacej z adresowaniem zamknietym, kubelki z tablica dynamiczna, htb30
        auto timestamp_startb30r2 = chrono::high_resolution_clock::now();
        htb30.remove(std::to_string(array30[30]));
        auto timestamp_endb30r2 = chrono::high_resolution_clock::now();
        cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_startb30r2, timestamp_endb30r2);

        //pomiar remove dla tabeli mieszajacej z adresowaniem zamknietym, kubelki z tablica dynamiczna, htb30
        auto timestamp_startb30r3 = chrono::high_resolution_clock::now();
        htb30.remove(std::to_string(array30[30]));
        auto timestamp_endb30r3 = chrono::high_resolution_clock::now();
        cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_startb30r3, timestamp_endb30r3);

        //pomiar remove dla tabeli mieszajacej z adresowaniem zamknietym, kubelki z tablica dynamiczna, htb30
        auto timestamp_startb30r4 = chrono::high_resolution_clock::now();
        htb30.remove(std::to_string(array30[30]));
        auto timestamp_endb30r4 = chrono::high_resolution_clock::now();
        cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_startb30r4, timestamp_endb30r4);

        //pomiar remove dla tabeli mieszajacej z adresowaniem zamknietym, kubelki z tablica dynamiczna, htb30
        auto timestamp_startb30r5 = chrono::high_resolution_clock::now();
        htb30.remove(std::to_string(array30[40]));
        auto timestamp_endb30r5 = chrono::high_resolution_clock::now();
        cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_startb30r5, timestamp_endb30r5);

        cout<<"\n"<<"5 pomiarow remove na htb35:";
        //pomiar remove dla tabeli mieszajacej z adresowaniem zamknietym, kubelki z tablica dynamiczna, htb35
        auto timestamp_startb35r1 = chrono::high_resolution_clock::now();
        htb35.remove(std::to_string(array35[0]));
        auto timestamp_endb35r1 = chrono::high_resolution_clock::now();
        cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_startb35r1, timestamp_endb35r1);

        //pomiar remove dla tabeli mieszajacej z adresowaniem zamknietym, kubelki z tablica dynamiczna, htb35
        auto timestamp_startb35r2 = chrono::high_resolution_clock::now();
        htb35.remove(std::to_string(array35[35]));
        auto timestamp_endb35r2 = chrono::high_resolution_clock::now();
        cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_startb35r2, timestamp_endb35r2);

        //pomiar remove dla tabeli mieszajacej z adresowaniem zamknietym, kubelki z tablica dynamiczna, htb35
        auto timestamp_startb35r3 = chrono::high_resolution_clock::now();
        htb35.remove(std::to_string(array35[35]));
        auto timestamp_endb35r3 = chrono::high_resolution_clock::now();
        cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_startb35r3, timestamp_endb35r3);

        //pomiar remove dla tabeli mieszajacej z adresowaniem zamknietym, kubelki z tablica dynamiczna, htb35
        auto timestamp_startb35r4 = chrono::high_resolution_clock::now();
        htb35.remove(std::to_string(array35[35]));
        auto timestamp_endb35r4 = chrono::high_resolution_clock::now();
        cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_startb35r4, timestamp_endb35r4);

        //pomiar remove dla tabeli mieszajacej z adresowaniem zamknietym, kubelki z tablica dynamiczna, htb35
        auto timestamp_startb35r5 = chrono::high_resolution_clock::now();
        htb35.remove(std::to_string(array35[40]));
        auto timestamp_endb35r5 = chrono::high_resolution_clock::now();
        cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_startb35r5, timestamp_endb35r5);

        cout<<"\n"<<"5 pomiarow remove na htb40:";
        //pomiar remove dla tabeli mieszajacej z adresowaniem zamknietym, kubelki z tablica dynamiczna, htb40
        auto timestamp_startb40r1 = chrono::high_resolution_clock::now();
        htb40.remove(std::to_string(array40[0]));
        auto timestamp_endb40r1 = chrono::high_resolution_clock::now();
        cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_startb40r1, timestamp_endb40r1);

        //pomiar remove dla tabeli mieszajacej z adresowaniem zamknietym, kubelki z tablica dynamiczna, htb40
        auto timestamp_startb40r2 = chrono::high_resolution_clock::now();
        htb40.remove(std::to_string(array40[40]));
        auto timestamp_endb40r2 = chrono::high_resolution_clock::now();
        cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_startb40r2, timestamp_endb40r2);

        //pomiar remove dla tabeli mieszajacej z adresowaniem zamknietym, kubelki z tablica dynamiczna, htb40
        auto timestamp_startb40r3 = chrono::high_resolution_clock::now();
        htb40.remove(std::to_string(array40[40]));
        auto timestamp_endb40r3 = chrono::high_resolution_clock::now();
        cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_startb40r3, timestamp_endb40r3);

        //pomiar remove dla tabeli mieszajacej z adresowaniem zamknietym, kubelki z tablica dynamiczna, htb40
        auto timestamp_startb40r4 = chrono::high_resolution_clock::now();
        htb40.remove(std::to_string(array40[40]));
        auto timestamp_endb40r4 = chrono::high_resolution_clock::now();
        cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_startb40r4, timestamp_endb40r4);

        //pomiar remove dla tabeli mieszajacej z adresowaniem zamknietym, kubelki z tablica dynamiczna, htb40
        auto timestamp_startb40r5 = chrono::high_resolution_clock::now();
        htb40.remove(std::to_string(array40[40]));
        auto timestamp_endb40r5 = chrono::high_resolution_clock::now();
        cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_startb40r5, timestamp_endb40r5);

        cout<<"\n"<<"5 pomiarow remove na htb45:";
        //pomiar remove dla tabeli mieszajacej z adresowaniem zamknietym, kubelki z tablica dynamiczna, htb45
        auto timestamp_startb45r1 = chrono::high_resolution_clock::now();
        htb45.remove(std::to_string(array45[0]));
        auto timestamp_endb45r1 = chrono::high_resolution_clock::now();
        cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_startb45r1, timestamp_endb45r1);

        //pomiar remove dla tabeli mieszajacej z adresowaniem zamknietym, kubelki z tablica dynamiczna, htb45
        auto timestamp_startb45r2 = chrono::high_resolution_clock::now();
        htb45.remove(std::to_string(array45[45]));
        auto timestamp_endb45r2 = chrono::high_resolution_clock::now();
        cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_startb45r2, timestamp_endb45r2);

        //pomiar remove dla tabeli mieszajacej z adresowaniem zamknietym, kubelki z tablica dynamiczna, htb45
        auto timestamp_startb45r3 = chrono::high_resolution_clock::now();
        htb45.remove(std::to_string(array45[45]));
        auto timestamp_endb45r3 = chrono::high_resolution_clock::now();
        cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_startb45r3, timestamp_endb45r3);

        //pomiar remove dla tabeli mieszajacej z adresowaniem zamknietym, kubelki z tablica dynamiczna, htb45
        auto timestamp_startb45r4 = chrono::high_resolution_clock::now();
        htb45.remove(std::to_string(array45[45]));
        auto timestamp_endb45r4 = chrono::high_resolution_clock::now();
        cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_startb45r4, timestamp_endb45r4);

        //pomiar remove dla tabeli mieszajacej z adresowaniem zamknietym, kubelki z tablica dynamiczna, htb45
        auto timestamp_startb45r5 = chrono::high_resolution_clock::now();
        htb45.remove(std::to_string(array45[45]));
        auto timestamp_endb45r5 = chrono::high_resolution_clock::now();
        cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_startb45r5, timestamp_endb45r5);

        cout<<"\n"<<"5 pomiarow remove na htb50:";
        //pomiar remove dla tabeli mieszajacej z adresowaniem zamknietym, kubelki z tablica dynamiczna, htb50
        auto timestamp_startb50r1 = chrono::high_resolution_clock::now();
        htb50.remove(std::to_string(array50[0]));
        auto timestamp_endb50r1 = chrono::high_resolution_clock::now();
        cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_startb50r1, timestamp_endb50r1);

        //pomiar remove dla tabeli mieszajacej z adresowaniem zamknietym, kubelki z tablica dynamiczna, htb50
        auto timestamp_startb50r2 = chrono::high_resolution_clock::now();
        htb50.remove(std::to_string(array50[50]));
        auto timestamp_endb50r2 = chrono::high_resolution_clock::now();
        cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_startb50r2, timestamp_endb50r2);

        //pomiar remove dla tabeli mieszajacej z adresowaniem zamknietym, kubelki z tablica dynamiczna, htb50
        auto timestamp_startb50r3 = chrono::high_resolution_clock::now();
        htb50.remove(std::to_string(array50[50]));
        auto timestamp_endb50r3 = chrono::high_resolution_clock::now();
        cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_startb50r3, timestamp_endb50r3);

        //pomiar remove dla tabeli mieszajacej z adresowaniem zamknietym, kubelki z tablica dynamiczna, htb50
        auto timestamp_startb50r4 = chrono::high_resolution_clock::now();
        htb50.remove(std::to_string(array50[50]));
        auto timestamp_endb50r4 = chrono::high_resolution_clock::now();
        cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_startb50r4, timestamp_endb50r4);

        //pomiar remove dla tabeli mieszajacej z adresowaniem zamknietym, kubelki z tablica dynamiczna, htb50
        auto timestamp_startb50r5 = chrono::high_resolution_clock::now();
        htb50.remove(std::to_string(array50[50]));
        auto timestamp_endb50r5 = chrono::high_resolution_clock::now();
        cout << "\n" << give_nanoseconds_between_time_stamps(timestamp_startb50r5, timestamp_endb50r5);
        }
            break;
        default:
                std::cout << "Niepoprawny wybor opcji menu" << std::endl;
                break;
    }
    return 0;
}
