#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

#define ERROR_STYLESHEET "QLabel { color: red }"
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int width = this->size().width();
    int height = this->size().height();
    int arr[] = {width, height};
    draw(arr);

    connect(m_input, SIGNAL (textChanged(/* QString */)), this, SLOT(handleTextEdit()));
    //connect(m_fileInput, SIGNAL (textChanged(QString)), this, SLOT(handleFileInputEdit(QString)));
    connect(m_button1, SIGNAL (pressed()), this, SLOT (handleButton1()));
    connect(m_button2, SIGNAL (pressed()), this, SLOT (handleButton2()));
    connect(m_buttonBig, SIGNAL (pressed()), this, SLOT (handleButton2()));
}
void MainWindow::draw(int arr[]){
    int width = arr[0];
    int height = arr[1];
    m_button1 = new QPushButton("Append to text", this);
    m_button2 = new QPushButton("Replace with text", this);
    m_buttonBig = new QPushButton("Add text", this);
    m_button1->setGeometry(QRect(QPoint(width/2 - 175, height/2 - 47.5),
                                 QSize(145, 30)));
    m_button2->setGeometry(QRect(QPoint(width/2 - 175, height/2 - 12.5),
                                 QSize(145, 30)));
    m_buttonBig->setGeometry(QRect(QPoint(width/2 - 175, height/2 - 47.5),
                                   QSize(145, 70)));
    m_buttonBig->hide();
    text_label = new QLabel(this);
    text_label->setText("");
    text_label->setAlignment(Qt::AlignBottom | Qt::AlignRight);
    text_label->setGeometry(QRect(QPoint(width/2 + 150, height/2 - 12.5), QSize(200, 200)));
    text_label->setWordWrap(true);
    m_input = new QTextEdit(this);
    m_input->setPlaceholderText("Type here");
    m_input->setFocus();
    m_input->setGeometry(QRect(QPoint(width/2 - 30, height/2 - 50), QSize(150, 70)));
    QLineEdit *m_fileInput = new QLineEdit(this);
    m_fileInput->setPlaceholderText("File save");
    m_fileInput->setFocus();
    m_fileInput->setGeometry(QRect(QPoint(width/2 - 175, height/2 + 25), QSize(350, 30)));
    connect(m_fileInput, SIGNAL (textChanged(QString)), this, SLOT(handleFileInputEdit(QString)));
}
void MainWindow::handleButton(bool condition)
{

    if(!inputText.isEmpty()){
        cout<<inputText.toStdString()<<endl;
        text_label->setText(inputText);
        if (isError == true){
            text_label->setStyleSheet("QLabel { color: black; }");
        }
        if (!fileText.isEmpty()){
            //file.open("/home/zixuan/qtProjects/project/exampleFile.txt", inputText.toStdString());
            file.open(fileText.toStdString(), condition, inputText.toStdString());
        } else {
            cerr<<"Please specify a file (line 63: mainwindow.cpp) \n cerr<<\"Please specify a file (line 63: mainwindow.cpp) \\n \"<<endl;"<<endl;
            text_label->setText("Please specify file");
            text_label->setStyleSheet(ERROR_STYLESHEET);
            isError = true;
        }
    } else {
        cerr<<"Error: text empty (line 69: mainwindow.cpp) \n cerr<<\"Error: text empty (line 69: mainwindow.cpp) \\n \"<<endl;"<<endl;
        text_label->setText("Text is empty");
        text_label->setStyleSheet(ERROR_STYLESHEET);
        isError = true;
    }
    m_input->setText("");
}

MainWindow::~MainWindow()
{
    delete ui;
    //delete m_button1;
}

