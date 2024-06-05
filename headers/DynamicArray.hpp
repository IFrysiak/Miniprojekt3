#ifndef DYNAMICARRAY_HPP
#define DYNAMICARRAY_HPP

#include <string>

class DynamicArray { //implementacja tablicy dynamicznej potrzebnej do tablicy mieszajacej z adresowaniem zamknietym
public:
    struct HashNode {
        std::string key; //klucz
        int value; //wartosc
        HashNode(const std::string &k, int v) : key(k), value(v) {}
    };

private:
    HashNode** array;
    int capacity; //pojemnosc tablicy
    int size; //wielkosc tablicy
    void resize(); //zwiekszenie wielkosci tablicy

public:
    DynamicArray();
    ~DynamicArray();
    void add(const std::string &key, int value); //dodanie wartosci po kluczu
    bool remove(const std::string &key); //usuniecie wartosci powiazanej z kluczem
    int search(const std::string &key) const; //szukanie wartosci powiazanej z kluczem
    int getSize() const; //zwraca wielkosc tablicy
    HashNode* get(int index) const;
};

#endif // DYNAMICARRAY_HPP
