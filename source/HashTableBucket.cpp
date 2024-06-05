#include <iostream>
#include "../headers/HashTableBucket.hpp"

using namespace std;

int HashTableBucket::hash(const string &key) { //funkcja haszuj¹ca
    int hash = 0;
    for (char c : key) {
        hash = (hash * 31 + c) % tableSize;
    }
    return hash;
}

void HashTableBucket::rehash() { //powiêkszanie tablicy dwukrotnie
    int oldSize = tableSize;
    tableSize *= 2;
    Bucket* oldTable = table;
    table = new Bucket[tableSize];
    numElements = 0;

    for (int i = 0; i < oldSize; ++i) {
        for (int j = 0; j < oldTable[i].nodes.getSize(); ++j) {
            DynamicArray::HashNode* node = oldTable[i].nodes.get(j);
            if (node != nullptr) {
                insert(node->key, node->value);
            }
        }
    }
    delete[] oldTable;
}

HashTableBucket::HashTableBucket(int size) {
    tableSize = size;
    table = new Bucket[tableSize];
    numElements = 0;
}

HashTableBucket::~HashTableBucket() {
    delete[] table;
}

void HashTableBucket::insert(const string &key, int value) { //funkcja dodaj¹ca wartoœæ o podanym kluczu
    if ((double)numElements / tableSize > 2) { //wspolczynnik zajetosci
        rehash();
    }

    int index = hash(key);

    int val = table[index].nodes.search(key);
    if (val != -1) {
        for (int i = 0; i < table[index].nodes.getSize(); ++i) {
            DynamicArray::HashNode* node = table[index].nodes.get(i);
            if (node->key == key) {
                node->value = value;
                return;
            }
        }
    } else {
        table[index].nodes.add(key, value);
        ++numElements;
    }
}

int HashTableBucket::search(const string &key) { //przeszukiwanie tablicy po kluczu
    int index = hash(key);
    return table[index].nodes.search(key);
}

bool HashTableBucket::remove(const string &key) { //usuwanie wartoœci o kluczu
    int index = hash(key);
    if (table[index].nodes.remove(key)) {
        return true;
    }
    return false;
}

void HashTableBucket::printTable() const { //wypisuje ca³¹ tablicê
    for (int i = 0; i < tableSize; ++i) {
        cout << "Index " << i << ": ";
        for (int j = 0; j < table[i].nodes.getSize(); ++j) {
            DynamicArray::HashNode* node = table[i].nodes.get(j);
            if (node != nullptr) {
                cout << "[Key = " << node->key << ", Value = " << node->value << "] ";
            }
        }
        cout << endl;
    }
}
