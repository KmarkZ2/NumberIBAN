
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include <QRegularExpressionValidator>
#include <QRegularExpressionMatch>


class Validator
{
public:
    virtual bool isValid(QString somestring)=0;
};

class PasswordValidator : public Validator
{
    QString str = "[A-Za-z]{2}[0-9]{2}[0-9]{6}[0-9]{19}";
    QRegularExpression reg=QRegularExpression(str);
public:

    virtual bool isValid(QString somestring)
    {
        QRegularExpressionMatch regmatch1 = reg.match(somestring);
        bool ismatch1 = regmatch1.hasMatch() ;
        bool ismatch = ismatch1;
        if  (ismatch==true && somestring.size() == 29)
            return true;
        else
            return false;
    }
};


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
    void on_lineEdit_returnPressed();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
