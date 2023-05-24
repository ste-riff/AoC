#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// Functions declaration
void day1();
void day2();

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

    // day1();
    day2();

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

void day2() {
    cout << "### Day 2 ###" << endl;
    
    const string filename = "C:/Users/H780521/Documents/AoC/Inputs/Day2.txt";
    ifstream input_file(filename);
    string line, player1, player2;

    int total_score = 0;
    
    while(getline(input_file, line, '\n')) {
        stringstream round(line);
        getline(round, player1, ' ');
        getline(round, player2, ' ');
        
        switch(player1[0]) {
            case 'A':
                if(player2[0] == 'X') {
                    // player2 played Rock, 1 point
                    total_score++;
                    // result is a draw, 3 points
                    total_score += 3;
                } else if(player2[0] == 'Y') {
                    // player2 played Paper, 2 points
                    total_score += 2;
                    // result is a win, 6 points
                    total_score += 6;
                } else if(player2[0] == 'Z') {
                    // player2 played Scissors, 3 points
                    total_score += 3;
                    // result is a loss, 0 points
                }
                break;
            case 'B':
                if(player2[0] == 'X') {
                    // player2 played Rock, 1 point
                    total_score++;
                    // result is a loss, 0 points
                } else if(player2[0] == 'Y') {
                    // player2 played Paper, 2 points
                    total_score += 2;
                    // result is a draw, 3 points
                    total_score += 3;
                } else if(player2[0] == 'Z') {
                    // player2 played Scissors, 3 points
                    total_score += 3;
                    // result is a win, 6 points
                    total_score += 6;
                }
                break;
            case 'C':
                if(player2[0] == 'X') {
                    // player2 played Rock, 1 point
                    total_score++;
                    // result is a win, 6 points
                    total_score += 6;
                } else if(player2[0] == 'Y') {
                    // player2 played Paper, 2 points
                    total_score += 2;
                    // result is a loss, 0 points
                } else if(player2[0] == 'Z') {
                    // player2 played Scissors, 3 points
                    total_score += 3;
                    // result is a draw, 3 points
                    total_score += 3;
                }
                break;
            default:
                cout << "ERROR: invalid input" << endl;
                break;
        } 
    }

    cout << "Total score: " << total_score << " points." << endl;
}