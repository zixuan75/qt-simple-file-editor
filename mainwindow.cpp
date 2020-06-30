#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

#define ERROR_STYLESHEET "QLabel { color: red }"
#define NORMAL_STYLESHEET "QLabel { color: blue }"
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
}
void MainWindow::draw(int arr[]){
    int width = arr[0];
    int height = arr[1];
    // Draw buttons
    m_button1 = new QPushButton("Append to text", this);
    m_button2 = new QPushButton("Replace with text", this);
    m_buttonBig = new QPushButton("Add text", this);
    m_button1->setGeometry(QRect(QPoint(width/2 - 175, height/2 - 50),
                                 QSize(145, 35)));
    m_button2->setGeometry(QRect(QPoint(width/2 - 175, height/2 - 15),
                                 QSize(145, 35)));
    m_buttonBig->setGeometry(QRect(QPoint(width/2 - 175, height/2 - 50),
                                   QSize(145, 70)));
    m_buttonBig->hide();
    // Labels
    text_label = new QLabel(this);
    text_label->setText("");
    text_label->setAlignment(Qt::AlignBottom | Qt::AlignRight);
    text_label->setStyleSheet(NORMAL_STYLESHEET);
    text_label->setGeometry(QRect(QPoint(width/2 + 150, height/2 - 12.5), QSize(200, 200)));
    text_label->setWordWrap(true);
    // Inputs
    m_input = new QTextEdit(this);
    m_input->setPlaceholderText("Type here");
    m_input->setFocus();
    m_input->setGeometry(QRect(QPoint(width/2 - 30, height/2 - 50), QSize(150, 70)));
    QLineEdit *m_fileInput = new QLineEdit(this);
    m_fileInput->setPlaceholderText("File save");
    m_fileInput->setFocus();
    m_fileInput->setGeometry(QRect(QPoint(width/2 - 175, height/2 + 25), QSize(295, 30)));

    // Before and after
    m_text = new QTextEdit(this);
    m_text->setFocus();
    m_text->setGeometry(QRect(QPoint(width/2 - 175, height - 225), QSize(295, 225)));
    m_text->setReadOnly(true);
    connect(m_input, SIGNAL (textChanged(/* QString */)), this, SLOT(handleTextEdit()));
    connect(m_fileInput, SIGNAL (textChanged(QString)), this, SLOT(handleFileInputEdit(QString)));
    connect(m_button1, SIGNAL (pressed()), this, SLOT (handleButton1()));
    connect(m_button2, SIGNAL (pressed()), this, SLOT (handleButton2()));
    connect(m_buttonBig, SIGNAL (pressed()), this, SLOT (handleButton()));

}
void MainWindow::handleButton(bool condition)
{
    if(!inputText.isEmpty()){
        cout<<inputText.toStdString()<<endl;
        text_label->setText(inputText);
        if (isError == true){
            text_label->setStyleSheet(NORMAL_STYLESHEET);
        }
        if (!fileText.isEmpty()){
            file.open(fileText.toStdString(), condition, inputText.toStdString());
            m_text->setText(QString::fromStdString(file.read(fileText.toStdString())));
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

