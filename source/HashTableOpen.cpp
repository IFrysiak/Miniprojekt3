#include <iostream>
#include <chrono>
#include "../headers/HashTableOpen.hpp"

using namespace std;

int HashTableOpen::hash(const string &key) { //funkcja hasujaca
    int hash = 0;
    for (char c : key) {
        hash = (hash * 31 + c) % tableSize;
    }
    return hash;
}

void HashTableOpen::rehash() { //powiekszanie tablicy dwukrotnie
    int oldSize = tableSize;
    tableSize *= 2;
    HashNode* oldTable = table;
    table = new HashNode[tableSize];
    numElements = 0;

    for (int i = 0; i < oldSize; ++i) {
        if (oldTable[i].isOccupied) {
            insert(oldTable[i].key, oldTable[i].value);
        }
    }
    delete[] oldTable;
}

HashTableOpen::HashTableOpen(int size) {
    tableSize = size;
    table = new HashNode[tableSize];
    numElements = 0;
}

HashTableOpen::~HashTableOpen() {
    delete[] table;
}

void HashTableOpen::insert(const string &key, int value) { //funkcja dodajaca wartosc o podanym kluczu
    if ((double)numElements / tableSize > 0.6) {
        rehash();
    }

    int index = hash(key);
    int original_index = index;

    while (table[index].isOccupied) {
        if (table[index].key == key) {
            table[index].value = value;
            return;
        }
        index = (index + 1) % tableSize;
        if (index == original_index) {
            cerr << "tablica jest pelna co znaczy ze nie zwiekszyla sie struktura" << endl;
            rehash();
            return;
        }
    }

    table[index].key = key;
    table[index].value = value;
    table[index].isOccupied = true;
    ++numElements;
}

int HashTableOpen::search(const string &key) { //przeszukiwanie tablicy po kluczu
    int index = hash(key);
    int original_index = index;

    while (table[index].isOccupied) {
        if (table[index].key == key) {
            return table[index].value;
        }
        index = (index + 1) % tableSize;
        if (index == original_index) {
            break;
        }
    }

    return -1; //nie znaleziono klucza
}

int HashTableOpen::remove(const string &key) { //usuwanie wartosci o kluczu
    int index = hash(key);
    int original_index = index;

    while (table[index].isOccupied) {
        if (table[index].key == key) {
            table[index].key = "";
            table[index].value = 0;
            table[index].isOccupied = false;
            return 1; //potwierdzenie znalezienia i wyczyszczenia elementu
        }
        index = (index + 1) % tableSize;
        if (index == original_index) {
            break;
        }
    }

    return -1; //nie znaleziono klucza
}

void HashTableOpen::printTable() const { //wypisuje cala tablice
    for (int i = 0; i < tableSize; ++i) {
        if (table[i].isOccupied) {
            cout << "Index " << i << ": Key = " << table[i].key << ", Value = " << table[i].value << endl;
        } else {
            cout << "Index " << i << ": Empty" << endl;
        }
    }
}
