#include "Elf.hpp"
using AoC22::Elf;

bool Elf::operator > (const Elf& a) const {
    return total_calories > a.getTotalCalories();
};

int Elf::getTotalCalories() const {
    return total_calories;
};

void Elf::addFood(int calories) {
    food.push_back(calories);
    total_calories += calories;
}

void Elf::Reset() {
    total_calories = 0;
    food.clear();
};
