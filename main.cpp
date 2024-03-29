#include <algorithm>
using std::find_if;
using std::sort;
#include <fstream>
using std::ifstream;
#include <functional>
using std::greater;
#include <iostream>
using std::cout;
using std::endl;
#include <deque>
using std::deque;
#include <list>
using std::list;
#include <map>
using std::map;
#include <sstream>
using std::stringstream;
#include <stack>
using std::stack;
#include <stdexcept>
using std::out_of_range;
#include <string>
using std::string;
using std::stoi;
#include<tuple>
using std::get;
#include <unordered_map>
using std::unordered_map;
#include <utility>
using std::pair;
#include <vector>
using std::vector;

#include "Directory.hpp"
using AoC22::Directory;
using AoC22::executeCommand;
using AoC22::createDirectory;
using AoC22::findDirToDelete;
#include "Elf.hpp"
using AoC22::Elf;

// Functions declaration
void day1();
void day2();
void day3();
void day4();
void day5();
void day6();
void day7();
void day8();

/************** MAIN *************/

int main() {
    cout << "AoC 2023" << endl;

    // day1();
    // day2();
    // day3();
    // day4();
    // day5();
    // day6();
    // day7();
    day8();

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
    sort(tribe.begin(), tribe.end(), greater<Elf>());

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
        sort(line.begin(), line.end());
        line.erase(unique(line.begin(), line.end()), line.end());
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
    vector<deque<char>> crate_stacks; // Using deque instead of stack since each stack is filled from the top (inverse order)

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
                        deque<char> generic_stack;
                        crate_stacks.push_back(generic_stack);

                        // DEBUG cout << "Stack #" << stack_id << " created." << endl;
                    }

                    if (!line.find('[')) {
                        crate_stacks.at(stack_id).push_back(line[line.find('[') + 1]);
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
            if (!line.find("move")) {
                // For each "move" line, extract the number of pops (crates_to_move) and the stacks (stack_from and stack_to)
                // To do so, split each line using the blank space as separator
                int begin = 0, end;
                int crates_to_move = 0, stack_from, stack_to;

                end = line.find_first_of(" ");
                line = line.erase(begin, end + 1); // remove "move "
                end = line.find_first_of(" ");
                crates_to_move = stoi(line.substr(begin, end)); // store crates_to_move
                // DEBUG cout << "crates_to_move: " << crates_to_move << endl;
                line = line.erase(begin, end + 6); // remove "<crates_to_move> from "
                end = line.find_first_of(" ");
                stack_from = stoi(line.substr(begin, end)); // store stack_from
                line = line.erase(begin, end + 4); // remove "<stack_from> to "
                end = line.find_first_of(" ");
                stack_to = stoi(line.substr(begin, end)); // store stack_to

                // DEBUG cout << "Move " << crates_to_move << " from " << stack_from << " to " << stack_to << endl;

                // Move crates with CrateMover9000 (Part1)
                /*for (int i = 0; i < crates_to_move; i++) {
                    crate_stacks[stack_to - 1].push_front(crate_stacks[stack_from - 1].front());
                    crate_stacks[stack_from - 1].pop_front();
                }*/

                // Move crates with CrateMover9001 (Part2)
                stack<char> temp_stack;
                
                // use a stack to "pop" elements in the right order from the queue
                for (int i = 0; i < crates_to_move; i++) {
                    temp_stack.push(crate_stacks[stack_from - 1].front());
                    crate_stacks[stack_from - 1].pop_front();
                }
                for (int i = 0; i < crates_to_move; i++) {
                    crate_stacks[stack_to - 1].push_front(temp_stack.top());
                    temp_stack.pop();
                }
            }
        }
    }

    for (int i = 0; i < crate_stacks.size(); i++)
        cout << crate_stacks[i].front();
    cout << endl;
}

void day6() {
    cout << "### Day 6 ###" << endl;

    const string filename = "C:/Users/StefanoSavarino/Documents/code/AoC/Inputs/Day6.txt";
    ifstream input_file(filename);
    string line;
    
    if (input_file.fail()) {
        cout << "Unable to open the file: " << filename << endl;
    }
    else {
        char c;
        int package_length = 4, message_length = 14;
        deque<char> sequence_package (package_length, ' ');
        deque<char> sequence_message (message_length, ' ');
        int char_id_package = 0, char_id_message = 0;
        bool repetition_package = false, repetition_message = false, package_found = false, message_found = false;

        while (input_file.get(c)) {
            // Looking for start of package
            if (!package_found) {
                char_id_package++; // increment counter

                sequence_package.pop_front(); // remove the oldest char
                sequence_package.push_back(c); // insert last read character

                repetition_package = false;

                for (int i = 0; i < package_length; i++) {
                    for (int j = 0; j < package_length; j++) {
                        if (i == j)
                            break;
                        if (sequence_package[i] == sequence_package[j]) {
                            repetition_package = true;
                            break;
                        }
                        else {
                            repetition_package = false;
                        }
                    }
                    if (repetition_package)
                        break;
                }

                if (!repetition_package) {
                    cout << "Package marker detected: ";
                    for (char c : sequence_package)
                        cout << c;
                    cout << " at position " << char_id_package << endl;
                    package_found = true;
                }
            }
            
            // Looking for start of message
            if (!message_found) {
                char_id_message++; // increment counter

                sequence_message.pop_front(); // remove the oldest char
                sequence_message.push_back(c); // insert last read character

                repetition_message = false;

                for (int i = 0; i < message_length; i++) {
                    for (int j = 0; j < message_length; j++) {
                        if (i == j)
                            break;
                        if (sequence_message[i] == sequence_message[j]) {
                            repetition_message = true;
                            break;
                        }
                        else {
                            repetition_message = false;
                        }
                    }
                    if (repetition_message)
                        break;
                }

                if (!repetition_message) {
                    cout << "Message marker detected: ";
                    for (char c : sequence_message)
                        cout << c;
                    cout << " at position " << char_id_message << endl;
                    message_found = true;
                }
            }
        }
    }}

void day7() {
    cout << "### Day 7 ###" << endl;

    const string filename = "C:/Users/StefanoSavarino/Documents/code/AoC/Inputs/Day7.txt";
    //const string filename = "C:/Users/StefanoSavarino/Documents/code/AoC/Inputs/test.txt";
    ifstream input_file(filename);
    string line;
    const int total_disk_space = 70'000'000;
    const int space_needed = 30'000'000;

    if (input_file.fail()) {
        cout << "Unable to open the file: " << filename << endl;
    }
    else {
        int total_size = 0;
        Directory* current_dir_ptr = nullptr;
        list<Directory> filesystem;
        int total_size_sum = 0;

        Directory root("/");
        filesystem.push_back(root);
        current_dir_ptr = &(*filesystem.begin());

        while (getline(input_file, line, '\n')) {
            switch (line[0]) {
            case '$':
                //cout << "Command executed: " << line << endl;
                executeCommand(current_dir_ptr, line);
                break;
            case 'd':
                //cout << "Directory listed: " << line << endl;
                createDirectory(current_dir_ptr, line);
                break;
            default:
                // cout << "File listed: " << line << endl;
                createFile(current_dir_ptr, line);
                break;
            }
        }

        // all filesystem created, now move through it and find directories with correct size
        current_dir_ptr = &(*filesystem.begin());
        calculateTotalSize(total_size_sum, current_dir_ptr);

        cout << "Total size: " << total_size_sum << endl;
        
        // calculate total available space
        int available_space = total_disk_space - filesystem.begin()->getSize();
        int space_to_free = space_needed - available_space;
        int size_to_delete = total_disk_space;

        current_dir_ptr = &(*filesystem.begin());
        findDirToDelete(current_dir_ptr, size_to_delete, space_to_free);

        cout << "Dir to delete: size: " << size_to_delete << endl;

        cout << "Done!" << endl;

    }
}

void day8() {
    cout << "### Day 8 ###" << endl;

    const string filename = "C:/Users/StefanoSavarino/Documents/code/AoC/Inputs/Day8.txt";
    //const string filename = "C:/Users/StefanoSavarino/Documents/code/AoC/Inputs/test.txt";
    ifstream input_file(filename);
    string line;

    if (input_file.fail()) {
        cout << "Unable to open the file: " << filename << endl;
    }
    else {
        vector<vector<int>> wood, visible_trees;

        // Fill the matrix with values
        while (getline(input_file, line, '\n')) {
            vector<int> temp, temp_visible;
            for(auto it : line) {
                temp.push_back(atoi(&it));
                temp_visible.push_back(0);
            }
            wood.push_back(temp);
            visible_trees.push_back(temp_visible);
        }

        int highest_column = -1, highest_row = -1; // initialized to -1 because 0 is a valid value
        
        // check from left to right and from top to bottom
        for (int i = 0; i < wood.size(); i++) {
            for (int j = 0; j < wood.size(); j++) {
                // checking row
                if (wood[i][j] > highest_row) {
                    visible_trees[i][j] = 1;
                    highest_row = wood[i][j];
                }

                // checking column
                if (wood[j][i] > highest_column) {
                    visible_trees[j][i] = 1;
                    highest_column = wood[j][i];
                }

            }
            highest_column = -1;
            highest_row = -1;
        }

        // check from right to left and from bottom to top
        for (int i = wood.size() - 1; i >= 0; i--) {
            for (int j = wood.size() - 1; j >= 0; j--) {
                // checking row
                if (wood[i][j] > highest_row) {
                    visible_trees[i][j] = 1;
                    highest_row = wood[i][j];
                }

                // checking column
                if (wood[j][i] > highest_column) {
                    visible_trees[j][i] = 1;
                    highest_column = wood[j][i];
                }
            }
            highest_column = -1;
            highest_row = -1;
        }

        // count number of ones in visible_trees
        int total_visible = 0;
        for (int i = 0; i < visible_trees.size(); i++) {
            for (int j = 0; j < visible_trees.size(); j++) {
                if (visible_trees[i][j] == 1)
                    total_visible++;
            }
        }

        cout << "Visible trees: " << total_visible << endl;

        // Part 2
        // create a new integer value to store the highest score found so far
        // for each tree:
        // 1. move up until you reach id 0, or until you reach a tree as high or higher than the current one
        // 2. move down until you reach id 0, or until you reach a tree as high or higher than the current one
        // 3. move left until you reach id 0, or until you reach a tree as high or higher than the current one
        // 4. move right until you reach id 0, or until you reach a tree as high or higher than the current one
        // store each score in its own variable, then multiply them.
        // If the result is higher than current, then update current, otherwise, move on.
        int d_up = 0, d_down = 0, d_right = 0, d_left = 0;
        int highest_score = 0;

        for (int i = 0; i < wood.size(); i++) {
            for (int j = 0; j < wood.size(); j++) {
                if (i == 0
                    || i == wood.size() - 1
                    || j == 0
                    || j == wood.size() - 1) {
                    // one of the multipliers is 0, we don't need to calculate the others
                }
                else {
                    // check row/column in each direction as long as:
                    // 1. the value is not on the edge and the direction is toward the edge
                    // 2. a higher, or as high, tree is found
                    int temp_i = i, temp_j = j;

                    // check up
                    while (temp_i > 0 &&
                        temp_i != wood.size() - 1 &&
                        temp_j != 0 &&
                        temp_j != wood[i].size() - 1) {
                        temp_i--;
                        if (wood[temp_i][j] >= wood[i][j]) {
                            d_up++;
                            break;
                        }
                        else {
                            d_up++;
                        }
                    }
                    temp_i = i;
                    // check down
                    while (temp_i != 0 &&
                        temp_i < wood.size() - 1 &&
                        temp_j != 0 &&
                        temp_j != wood[i].size() - 1) {
                        temp_i++;
                        if (wood[temp_i][j] >= wood[i][j]) {
                            d_down++;
                            break;
                        }
                        else {
                            d_down++;
                        }
                    }
                    temp_i = i;
                    // check left
                    while (temp_i != 0 &&
                        temp_i != wood.size() - 1 &&
                        temp_j > 0 &&
                        temp_j != wood[i].size() - 1) {
                        temp_j--;
                        if (wood[i][temp_j] >= wood[i][j]) {
                            d_left++;
                            break;
                        }
                        else {
                            d_left++;
                        }
                    }
                    temp_j = j;
                    // check right
                    while (temp_i != 0 &&
                        temp_i != wood.size() - 1 &&
                        temp_j != 0 &&
                        temp_j < wood[i].size() - 1) {
                        temp_j++;
                        if (wood[i][temp_j] >= wood[i][j]) {
                            d_right++;
                            break;
                        }
                        else {
                            d_right++;
                        }
                    }
                    temp_j = j;

                }
                int temp_score = d_up * d_down * d_right * d_left;

                if (highest_score < temp_score)
                    highest_score = temp_score;

                // reset values for next loop
                d_up = d_down = d_left = d_right = 0;
            }
        }

        cout << "Highest scenic score: " << highest_score << endl;
        cout << "Done" << endl;

    }
}