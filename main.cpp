#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// Functions declaration
void day1();

/************** MAIN *************/

int main() {
    cout << "AoC 2023";

    day1();

   return 0;
}

// Functions bodies
void day1() {
    cout << "### Day 1 ###" << endl;
    
    string filename;

    cout << "Type input filename: ";
    cin >> filename;

    // ifstream input_file("C:/Users/H780521/Documents/AoC/Inputs/Day1.txt");
    ifstream input_file(filename);
    string line;

    while(getline(input_file, line, '\n')) {
        cout << line << " : " << line.length() << '\n';
        if(line.length() > 0) {
            // fill elf
            
        } else {
            // store elf and create new
        }
    }
    input_file.close();
}