#pragma once
#include <vector>
using std::vector;

namespace AoC22 {
    class Elf {
    private:
        int total_calories;
        vector<int> food;
    public:
        Elf() : total_calories(0) {}
        ~Elf() {}

        bool operator > (const Elf&) const;
        int getTotalCalories() const;
        void addFood(int);
        void Reset();
    };
}