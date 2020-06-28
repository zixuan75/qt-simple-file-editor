#include "openfile.h"

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
