#ifndef HASHTABLE_OPEN_HPP
#define HASHTABLE_OPEN_HPP

#include <iostream>
#include <chrono>
#include <string>

class HashTableOpen {
private:
    struct HashNode {
        std::string key; //klucz
        int value; //wartosc
        bool isOccupied; //true gdy kubelek jest zajety, false gdy jest pusty

        HashNode() : key(""), value(0), isOccupied(false) {} //wartosci poczatkowe kubelkow
    };

    HashNode* table;
    int tableSize;
    int numElements;

    int hash(const std::string &key); //funkcja hasujaca
    void rehash(); //funkcja powiekszajaca tablice

public:
    HashTableOpen(int size = 100);
    ~HashTableOpen();
    void insert(const std::string &key, int value); //funkcja dodajaca wartosc o podanym kluczu
    int search(const std::string &key); //przeszukiwanie tablicy po kluczu
    int remove(const std::string &key); //usuwanie wartosci o kluczu
    void printTable() const; //wypisuje cala tablice

};

#endif // HASHTABLE_OPEN_HPP
