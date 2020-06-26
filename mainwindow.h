#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <openfile.h>
#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>
#include <QLabel>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void handleButton(bool condition);
    void handleButton1()
    {
        handleButton(false);
    }
    void handleButton2()
    {
        handleButton(true);
    }
    void handleTextEdit()
    {
        inputText = m_input->toPlainText();
    }
    void draw(int arr[]);
    void handleFileInputEdit(const QString &text)
    {
        fileText = text;
        if (!file.ifFileExists(fileText.toStdString()) && !bigButtonShow){
            m_button1->hide();
            m_button2->hide();
            m_buttonBig->show();
            bigButtonShow = true;
        }
        if (file.ifFileExists(fileText.toStdString()) && bigButtonShow){
            bigButtonShow = false;
            m_button1->show();
            m_button2->show();
            m_buttonBig->hide();
        }
    }
private:
   QLabel *text_label;
   Ui::MainWindow *ui;
   OpenFile file;
   QString inputText, fileText;
   QTextEdit *m_input;
   QPushButton *m_button1, *m_button2, *m_buttonBig;
   bool isError{false}, bigButtonShow{false};
};
#endif // MAINWINDOW_H
