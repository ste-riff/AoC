#include <iostream>
using std::cout;
using std::endl;
#include<map>
using std::map;
#include <string>
using std::string;
#include <tuple>
using std::get;
#include <utility>
using std::pair;
#include "Directory.hpp"
using AoC22::Directory;

string Directory::getName() { return name; };

int Directory::getSize() { return total_size; };

void Directory::updateSize(int size) { total_size += size; };

void Directory::addFile(string filename, int file_size) {
    files.insert({ filename, file_size });
    total_size += file_size;
};

int Directory::getFilesSize() {
    int total_file_size = 0;

    for (auto it : files) {
        total_file_size += get<1>(it);
    }

    return total_file_size;
};

map<string, int> Directory::getFiles() { return files; };

void AoC22::executeCommand(Directory*& current_dir_ptr, string line) {
    if (line.substr(2, 2).compare("cd") == 0) {
        // extract dirname from line
        string dirname = line.substr(5, string::npos);
        // check whether it's a proper directory name or ..
        if (dirname.compare("..") == 0) {
            // move up a level
            current_dir_ptr = current_dir_ptr->parent;
        }
        else if (dirname.compare("/") == 0) {
            // root folder is a special case, do nothing
        }
        else {
            // create lambda to find right directory
            auto findDir = [dirname](Directory dir) {return dir.getName().compare(dirname) == 0; };
            // find subdir with specified name and return iterator
            list<Directory>::iterator it = find_if(current_dir_ptr->children.begin(), current_dir_ptr->children.end(), findDir);
            // point current_dir to found folder
            current_dir_ptr = &(*it);
        }
    }
    else if (line.substr(2, 2).compare("ls") == 0) {
        // do nothing
    }
    else
        cout << "Command not recognized" << endl;
};

void AoC22::createDirectory(Directory*& current_dir_ptr, string line) {
    // extract dirname from line
    string dirname = line.substr(4, string::npos);

    // check whether there already is such directory created
    // create lambda to find  directory
    auto findDir = [dirname](Directory dir) {return dir.getName().compare(dirname) == 0; };
    // find subdir with specified name and return iterator
    list<Directory>::iterator it = find_if(current_dir_ptr->children.begin(), current_dir_ptr->children.end(), findDir);

    if (it == current_dir_ptr->children.end()) {
        // no such directory found, create it
        Directory dir(dirname);
        dir.parent = current_dir_ptr;
        current_dir_ptr->children.push_back(dir);
    }
    else {
        // do nothing
    }
};

void AoC22::createFile(Directory*& current_dir_ptr, string line) {
    // extract filename and filesize from line
    size_t space = line.find(" ");
    string filename = line.substr(space, string::npos);
    int filesize = stoi(line.substr(0, space));

    // check whether there is already such file created
    // create lambda to find file
    auto files = current_dir_ptr->getFiles();
    auto findFile = [filename](pair<string, int> file) {return filename.compare(get<0>(file)) == 0; };
    // find subdir with specified name and return iterator
    map<string, int>::iterator it = find_if(files.begin(), files.end(), findFile);

    if (it == files.end()) {
        // no such file was found, add it
        current_dir_ptr->addFile(filename, filesize);
        // update the size of the containing tree of directories, until current_dir_ptr->parent == nullptr
        // maybe use a copy to current_dir_ptr to not loose the current pointed directory
        Directory* parentDir = current_dir_ptr->parent;
        updateParentDirectorySize(parentDir, filesize);
    }
    else {
        // do nothing
    }

};

void AoC22::updateParentDirectorySize(Directory*& parent_dir_ptr, int filesize) {
    if (parent_dir_ptr != nullptr) {
        parent_dir_ptr->updateSize(filesize);
        updateParentDirectorySize(parent_dir_ptr->parent, filesize);
    }
};

void AoC22::calculateTotalSize(int& total_size_sum, Directory*& current_dir_ptr) {
    if (current_dir_ptr->getSize() <= 100'000)
        total_size_sum += current_dir_ptr->getSize();

    if (!current_dir_ptr->children.empty()) {
        Directory* ptr;
        for (auto it : current_dir_ptr->children) {
            ptr = &it;
            calculateTotalSize(total_size_sum, ptr);
        }
    }
};

void AoC22::findDirToDelete(Directory*& current_dir_ptr, int& size_to_delete, int space_to_free) {

    if (current_dir_ptr->getSize() >= space_to_free &&
        current_dir_ptr->getSize() < size_to_delete) {
        size_to_delete = current_dir_ptr->getSize();
    }
    Directory* ptr = nullptr;
    for (auto it : current_dir_ptr->children) {
        ptr = &it;
        findDirToDelete(ptr, size_to_delete, space_to_free);
    }
};

