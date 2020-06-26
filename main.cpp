#include "mainwindow.h"

#include <QApplication>
#include <openfile.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    OpenFile file;
    //file.open("/home/zixuan/qtProjects/project/exampleFile.txt");
    return a.exec();
}
