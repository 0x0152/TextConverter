#ifndef FILESYSTEM_H
#define FILESYSTEM_H
#include <string>
#include <fstream>
#include "console.h"

using std::string;
using std::ifstream;
using std::ofstream;

class FileSystem
{
private:
    string _GetNameFile(const string file) const;
public:
    FileSystem();
    string* OpenFile(const string nameFile);
    void SaveFile(const string nameFile, const string direct, const string& text, const string exstensive);
};

#endif // FILESYSTEM_H
