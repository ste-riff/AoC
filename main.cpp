#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// Functions declaration
void day1();
void day2();
void day3();

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
    // day2();
    day3();

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

    int total_score_first = 0;
    int total_score_second = 0;
    
    while(getline(input_file, line, '\n')) {
        stringstream round(line);
        getline(round, player1, ' ');
        getline(round, player2, ' ');
        
        switch(player1[0]) {
            case 'A':
                if(player2[0] == 'X') {
                    // 1st: player2 played Rock, 1 point
                    total_score_first++;
                    // 1st: result is a draw, 3 points
                    total_score_first += 3;

                    // 2nd: player2 needs to loose, plays Scissors, 3 points
                    total_score_second += 3;
                    // 2nd: result is a loss, 0 points
                } else if(player2[0] == 'Y') {
                    // 1st: player2 played Paper, 2 points
                    total_score_first += 2;
                    // 1st: result is a win, 6 points
                    total_score_first += 6;

                    // 2nd: player2 needs to draw, plays Rock, 1 point
                    total_score_second++;
                    // 2nd: result is a draw, 3 points
                    total_score_second += 3;
                } else if(player2[0] == 'Z') {
                    // 1st: player2 played Scissors, 3 points
                    total_score_first += 3;
                    // 1st: result is a loss, 0 points

                    // 2nd: player2 needs to win, plays Paper, 2 points
                    total_score_second += 2;
                    // 2nd: result is a win, 6 points
                    total_score_second += 6;
                }
                break;
            case 'B':
                if(player2[0] == 'X') {
                    // 1st: player2 played Rock, 1 point
                    total_score_first++;
                    // 1st: result is a loss, 0 points

                    // 2nd: player2 needs to loose, plays Rock, 1 point
                    total_score_second ++;
                    // 2nd: result is a loss, 0 points
                } else if(player2[0] == 'Y') {
                    // 1st: player2 played Paper, 2 points
                    total_score_first += 2;
                    // 1st: result is a draw, 3 points
                    total_score_first += 3;

                    // 2nd: player2 needs to draw, plays Paper, 2 points
                    total_score_second += 2;
                    // 2nd: result is a draw, 3 points
                    total_score_second += 3;
                } else if(player2[0] == 'Z') {
                    // 1st: player2 played Scissors, 3 points
                    total_score_first += 3;
                    // 1st: result is a win, 6 points
                    total_score_first += 6;
                    
                    // 2nd: player2 needs to win, plays Scissors, 3 points
                    total_score_second += 3;
                    // 2nd: result is a win, 6 points
                    total_score_second += 6;
                }
                break;
            case 'C':
                if(player2[0] == 'X') {
                    // 1st: player2 played Rock, 1 point
                    total_score_first++;
                    // 1st: result is a win, 6 points
                    total_score_first += 6;

                    // 2nd: player2 needs to loose, plays Paper, 2 points
                    total_score_second += 2;
                    // 2nd: result is a loss, 0 points
                } else if(player2[0] == 'Y') {
                    // 1st: player2 played Paper, 2 points
                    total_score_first += 2;
                    // 1st: result is a loss, 0 points

                    // 2nd: player2 needs to draw, plays Scissors, 3 points
                    total_score_second += 3;
                    // 2nd: result is a draw, 3 points
                    total_score_second += 3;
                } else if(player2[0] == 'Z') {
                    // 1st: player2 played Scissors, 3 points
                    total_score_first += 3;
                    // 1st: result is a draw, 3 points
                    total_score_first += 3;

                    // 2nd: player2 needs to win, plays Rock, 1 point
                    total_score_second++;
                    // 2nd: result is a win, 6 points
                    total_score_second += 6;
                }
                break;
            default:
                cout << "ERROR: invalid input" << endl;
                break;
        } 
    }

    cout << "Total score in first attempt: " << total_score_first << " points." << endl;
    cout << "Total score in second attempt: " << total_score_second << " points." << endl;
}

void day3() {
    cout << "### Day 3 ###" << endl;
    
    const string filename = "C:/Users/H780521/Documents/AoC/Inputs/Day3.txt";
    ifstream input_file(filename);
    string line, rucksack1, rucksack2;
    size_t index;
    int total_elf_prority = 0, group_counter = 0, total_group_priority = 0;
    unordered_map<char, int> inventory;
    char map_key = 'a';
    string group[3];
    map<char, int> group_items;
    
    // initialize hash map inventory
    // Insert lowercase letters with corresponding values
    for (int value = 1; value <= 26; ++value) {
        inventory[map_key] = value;
        ++map_key;
    }

    // Insert uppercase letters with corresponding values
    map_key = 'A';
    for (int value = 27; value <= 52; ++value) {
        inventory[map_key] = value;
        ++map_key;
    }

    while(getline(input_file, line, '\n')) {
        // split each line in two substrings, equally long
        rucksack1 = line.substr(0, (line.size() / 2));
        rucksack2 = line.substr((line.size() / 2), (line.size() / 2));

        if(rucksack1.size() != rucksack2.size()) {
            cout << "Error in string splitting, not same length!!" << endl;
            return;
        }
        index = rucksack1.find_first_of(rucksack2);
        total_elf_prority += inventory[rucksack1.at(index)];

        // start by removing duplicates inside the same string, 
        // save found chars in group_items map.
        // when one char is found 3 times (once each string), that's the common char for all strings

        // remove duplicates in input string
        std::sort(line.begin(), line.end());
        line.erase(std::unique(line.begin(), line.end()), line.end());
        group[group_counter] = line;
        cout << "New string: " << line << endl;

        if(group_counter == 2) {
            for(char c_key: group[0]) {
                group_items.insert({c_key, 1});
            }
            for(char c_key: group[1]) {
                if(group_items.find(c_key) == group_items.end()) {
                    group_items.insert({c_key, 1});
                } else {
                    group_items.erase(c_key);
                    group_items.insert({c_key, 2});
                }
            }
            for(char c_key: group[2]) {
                if(group_items.find(c_key) == group_items.end()) {
                    group_items.insert({c_key, 1});
                } else {
                    if(group_items[c_key] == 2) {
                        total_group_priority += inventory[c_key];
                        group_items.clear();
                        break;
                    }
                }
            }
            group_counter = 0;
        } else {
            group_counter++;
        }
    }
    
    cout << "Total priority count: " << total_elf_prority << endl;
    cout << "Total group priority: " << total_group_priority << endl;
}