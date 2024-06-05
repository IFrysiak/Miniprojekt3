#include "../headers/Generator.hpp"
#include <random>

//funkcja generuj�ca seed
uint32_t generateSeed() {
    std::random_device rd;
    return rd();
}

//konstruktor klasy Uint32Generator
Uint32Generator::Uint32Generator(uint32_t seed) : generator(seed) {}

//metoda generuj�ca losow� liczb� uint32_t
uint32_t Uint32Generator::generate() {
    std::uniform_int_distribution<uint32_t> distribution(0, UINT32_MAX);
    return distribution(generator);
}

//funkcja wype�niaj�ca tablic� losowymi liczbami uint32_t
void fillArray(uint32_t* array, size_t size, Uint32Generator& generator) {
    for (size_t i = 0; i < size; ++i) {
        array[i] = generator.generate();
    }
}
