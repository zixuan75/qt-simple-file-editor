#include "openfile.h"
#include <fstream>
//#include <filesystem>
using namespace std;
OpenFile::OpenFile(){}
void OpenFile::open(string filePath, bool type, string addText)
{
    ofstream file;
    bool fileExists = ifFileExists(filePath);
    if (type == false){
        file.open(filePath, ios_base::app);
        if (fileExists){
            file << "\n" + addText;
        } else {
            file << addText;
        }
    } else {
        file.open(filePath);
        file << addText;
    }
    file.close();
}
bool OpenFile::ifFileExists(string filePath)
{
    ifstream iFile(filePath);
    iFile.seekg(0, ios::end);

    QFileInfo fileInfo(QString::fromStdString(filePath));
    if (!iFile.good() || fileInfo.isDir()){
        return false;
    }
    return true;
}
