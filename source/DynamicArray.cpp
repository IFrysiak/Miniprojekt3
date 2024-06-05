#include "../headers/DynamicArray.hpp"
#include <iostream>

DynamicArray::DynamicArray() { //implementacja tablicy dynamicznej potrzebnej do tablicy mieszajacej z adresowaniem zamknietym
    capacity = 2;
    size = 0;
    array = new HashNode*[capacity];
}

DynamicArray::~DynamicArray() {
    for (int i = 0; i < size; ++i) {
        delete array[i];
    }
    delete[] array;
}

void DynamicArray::resize() { //zwiekszenie wielkosci tablicy
    capacity *= 2;
    HashNode** newArray = new HashNode*[capacity];
    for (int i = 0; i < size; ++i) {
        newArray[i] = array[i];
    }
    delete[] array;
    array = newArray;
}

void DynamicArray::add(const std::string &key, int value) { //dodanie wartosci po kluczu
    if (size == capacity) {
        resize();
    }
    array[size++] = new HashNode(key, value);
}

bool DynamicArray::remove(const std::string &key) { //usuniecie wartosci powiazanej z kluczem
    for (int i = 0; i < size; ++i) {
        if (array[i]->key == key) {
            delete array[i];
            array[i] = array[size - 1];
            size--;
            return true;
        }
    }
    return false;
}

int DynamicArray::search(const std::string &key) const { //szukanie wartosci powiazanej z kluczem
    for (int i = 0; i < size; ++i) {
        if (array[i]->key == key) {
            return array[i]->value;
        }
    }
    return -1;
}

int DynamicArray::getSize() const { //zwraca wielkosc tablicy
    return size;
}

DynamicArray::HashNode* DynamicArray::get(int index) const {
    if (index >= 0 && index < size) {
        return array[index];
    }
    return nullptr;
}
