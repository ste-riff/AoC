#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// Functions declaration
void day1();
void day2();
void day3();
void day4();
void day5();

// Classes
class Elf {
    private:
        int total_calories;
        vector<int> food;
    public:
        Elf() {
            total_calories = 0;
        }

        ~Elf() {
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
    // day3();
    // day4();
    day5();

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

void day4() {
    cout << "### Day 4 ###" << endl;
    
    const string filename = "C:/Users/H780521/Documents/AoC/Inputs/Day4.txt";
    ifstream input_file(filename);
    string line, section1, section2, begin, end;
    int begin1 = 0, end1 = 0, begin2 = 0, end2 = 0, contained_pairs = 0, overlapping_pairs = 0;

    while(getline(input_file, line, '\n')){
        stringstream pair(line);
        getline(pair, section1, ',');
        getline(pair, section2, ',');

        stringstream section1ss(section1);
        getline(section1ss, begin, '-');
        begin1 = stoi(begin);
        getline(section1ss, end, '-');
        end1 = stoi(end);

        stringstream section2ss(section2);
        getline(section2ss, begin, '-');
        begin2 = stoi(begin);
        getline(section2ss, end, '-');
        end2 = stoi(end);

        // search for completely contained pairs
        if(begin1 < begin2) {
            if(end1 >= end2) {
                // section2 is contained in section1
                contained_pairs++;
            }
        } else if (begin1 > begin2) {
            if(end1 <= end2) {
                // section1 is contained in section2
                contained_pairs++;
            }
        } else if (begin1 == begin2) {
            if(end1 <= end2) {
                // section1 is contained in section2
                contained_pairs++;
            } else if (end1 > end2) {
                // section2 is contained in section1
                contained_pairs++;
            }
        }

        // search for overlapping pairs
        if(begin1 <= begin2 && begin2 <= end1) {
            overlapping_pairs++;
        } else if (begin2 <= begin1 && begin1 <= end2) {
            overlapping_pairs++;
        }
    }

    cout << "There are " << contained_pairs << " contained pairs." << endl;
    cout << "There are " << overlapping_pairs << " overlapping pairs." << endl;
}

void day5() {
    cout << "### Day 5 ###" << endl;

    const string filename = "C:/Users/StefanoSavarino/Documents/code/AoC/Inputs/Day5.txt";
    ifstream input_file(filename);
    string line;
    vector<queue<char>> crate_stacks; // Using queue instead of stack since each stack is filled from the top (inverse order)

    if (input_file.fail()) {
        cout << "Unable to open the file: " << filename << endl;
    }
    else {
        int stack_id = 0;
        size_t pos = 0;

        while (getline(input_file, line, '\n')) {
            stack_id = 0; // Reset stack_id to loop from the beginning again
            
            // First part of the input file, processing the stacks
            if (!line.find('[')) { // if the line contains a square bracket, then it contains crates to register
                
                // While pos is less than the end of the string, keep on looping 4 char at a time. 
                // If they contain brackets, they contain a crate, otherwise the stack is empty
                while (pos < line.length()) {
                    // While reading the first line, create all stacks.
                    try {
                        crate_stacks.at(stack_id);
                    }
                    catch (const out_of_range& oor) {
                        // DEBUG cout << "Stack not yet created, creating it now..." << endl;
                        queue<char> generic_stack;
                        crate_stacks.push_back(generic_stack);

                        // DEBUG cout << "Stack #" << stack_id << " created." << endl;
                    }

                    if (!line.find('[')) {
                        crate_stacks.at(stack_id).push(line[line.find('[') + 1]);
                        // DEBUG cout << "Value " << line[line.find('[') + 1] << " pushed in stack " << stack_id << endl;
                    }

                    // DEBUG cout << "Substring: " << line.substr(pos, 4) << endl;
                    line.erase(0, 4);
                    stack_id++;
                }
            }

            // Remove line with ids and with empty spaces
            if (line[0] == ' ') {
                // do nothing
            }

            // Process all moves
            if (!line.fine("move")) {

            }
        }
    }
}