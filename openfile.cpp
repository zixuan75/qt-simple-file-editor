#include "openfile.h"

//#include <filesystem>
using namespace std;
OpenFile::OpenFile(){}
void OpenFile::open(string filePath, bool type, string addText)
{
    ofstream file;
    if (type == false){
        file.open(filePath, ios_base::app);
        file << addText;
    } else {
        file.open(filePath);
        file << addText;
    }
    file.close();
}
string OpenFile::read(string filePath)
{
    ifstream file(filePath.c_str());
    string line;
    string text;
    while(getline(file, line)){
        text += line + "\n";

    }
    //cout<<"Text:"<<text<<endl;
    return text;
}
