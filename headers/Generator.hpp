#ifndef GENERATOR_HPP
#define GENERATOR_HPP

#include <cstdint>
#include <random>

uint32_t generateSeed(); //funkcja generuj¹ca seed

class Uint32Generator { //klasa generatora liczb uint32_t
public:
    Uint32Generator(uint32_t seed);
    uint32_t generate();
private:
    std::mt19937 generator;
};

void fillArray(uint32_t* array, size_t size, Uint32Generator& generator); //funkcja wype³niaj¹ca tablicê losowymi liczbami uint32_t

#endif // GENERATOR_HPP

