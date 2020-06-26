#ifndef OPENFILE_H
#define OPENFILE_H

#include <iostream>
#include <QFileInfo>
using namespace std;
class OpenFile
{
public:
    OpenFile();
    void open(string filePath, bool type, string addText);
    bool ifFileExists(string filePath);
private:
    //bool fileExists{true};
};

#endif // OPENFILE_H
