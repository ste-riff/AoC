#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Functions declaration
void day1();

// Classes
class Elf {
    private:
        int total_calories;
        vector<int> food;
    public:
        Elf() {
            total_calories = 0;
            // cout << "New elf created" << endl;
        }

        ~Elf() {
            // cout << "Elf destroyed" << endl;
        }

        bool operator > (const Elf& a) const {
            return total_calories > a.getTotalCalories();
        };

        int getTotalCalories() const {
            return total_calories;
        };

        void addFood(int calories) {
            food.push_back(calories);
            total_calories += calories;
            // cout << "Food worth " << calories << " added to elf." << endl; 
        }

        void Reset() {
            total_calories = 0;
            food.clear();
        };
};

/************** MAIN *************/

int main() {
    cout << "AoC 2023" << endl;

    day1();

   return 0;
}

// Functions bodies
void day1() {
    cout << "### Day 1 ###" << endl;
    
    const string filename = "C:/Users/H780521/Documents/AoC/Inputs/Day1.txt";
    vector<Elf> tribe;

    ifstream input_file(filename);
    string line;
    Elf elf;

    // read from file and add values to vector<Elf>
    while(getline(input_file, line, '\n')) {
        if(line.length() > 0) {
            // fill elf
            elf.addFood(stoi(line));
        } else {
            // store elf and create new
            tribe.push_back(elf);
            elf.Reset();
        }
    }
    input_file.close();

    // find elf with the most calories
    int highest_calories = 0;

    for(Elf elf : tribe) {
        if(elf.getTotalCalories() > highest_calories) {
            highest_calories = elf.getTotalCalories();
        }
    }

    cout << "Highest calories count: " << highest_calories << endl;

    // sort vector in descending order
    std::sort(tribe.begin(), tribe.end(), greater<Elf>());

    // print the 3 highest elfs
    int total_top3 = 0;
    for(int i = 0; i < 3; i++) {
        cout << "Elf #" << i << ": " << tribe[i].getTotalCalories() << " calories." << endl;
        total_top3 += tribe[i].getTotalCalories();
    }

    cout << "Sum of top3 elfs calories: " << total_top3 << " calories." << endl;

}