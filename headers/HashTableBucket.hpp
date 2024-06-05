#ifndef HASHTABLE_BUCKET_HPP
#define HASHTABLE_BUCKET_HPP

#include <iostream>
#include <string>
#include "../headers/DynamicArray.hpp"

class HashTableBucket { //tablica mieszajaca z adresowaniem zamknietym
private:
    struct Bucket {
        DynamicArray nodes; //dynamiczna tablica w�z��w
    };

    Bucket* table;
    int tableSize;  //wielkosc tablicy
    int numElements; //liczba elementow

    int hash(const std::string &key); //funkcja haszuj�ca
    void rehash(); //funkcja powi�kszaj�ca tablic�

public:
    HashTableBucket(int size = 100);
    ~HashTableBucket();
    void insert(const std::string &key, int value); //funkcja dodaj�ca warto�� o podanym kluczu
    int search(const std::string &key); //przeszukiwanie tablicy po kluczu
    bool remove(const std::string &key); //usuwanie warto�ci o kluczu
    void printTable() const; //wypisuje ca�� tablic�
};

#endif // HASHTABLE_BUCKET_HPP
