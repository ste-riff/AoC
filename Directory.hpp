#pragma once
#include <list>
using std::list;

namespace AoC22 {
    class Directory {
    private:
        string name;
        int total_size = 0;
        map<string, int> files;
    public:
        Directory* parent = nullptr;
        list<Directory> children = {};
        Directory(string dir_name) : name(dir_name) {}
        ~Directory() {}

        string getName();
        int getSize();
        void updateSize(int);
        void addFile(string, int);
        int getFilesSize();
        map<string, int> getFiles();
    };

    void executeCommand(Directory*&, string);
    void createDirectory(Directory*&, string);
    void createFile(Directory*&, string);
    void updateParentDirectorySize(Directory*&, int);
    void calculateTotalSize(int&, Directory*&);
    void findDirToDelete(Directory*&, int&, int);
}