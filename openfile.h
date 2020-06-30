#ifndef OPENFILE_H
#define OPENFILE_H
#include <fstream>
#include <iostream>
#include <QFileInfo>
using namespace std;
class OpenFile
{
public:
    OpenFile();
    void open(string filePath, bool type, string addText);
    string read(string filePath);
    bool ifFileExists(string filePath)
    {
        ifstream iFile(filePath);
        iFile.seekg(0, ios::end);

        QFileInfo fileInfo(QString::fromStdString(filePath));
        if (!iFile.good() || fileInfo.isDir()){
            return false;
        }
        return true;
    }
};

#endif // OPENFILE_H
