#ifndef CALCULATORS_H
#define CALCULATORS_H

#include <QMainWindow>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stack>
#include <vector>

using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui { class calculators; }
QT_END_NAMESPACE

class calculators : public QMainWindow
{
    Q_OBJECT


public:
    calculators(QWidget *parent = nullptr);
    ~calculators();

private:
    Ui::calculators *ui;
bool waitingForOperand;


public slots:
    //void NumPressed();
    //void MathButtonPressed();
    void EqualButtonPressed();
void Add();
void Subtract();
void Multiply();
void Divide ();
void Exponent();
    void C();
    void CE();
void addbrackets();
void T1();
    void T2();
 void T3();
 void Button1();
void Button2();
void Button3();
void Button4();
void Button5();
void Button6();
void Button7();
void Button8();
void Button9();
void Button0();

 void point();

private:
    double m_firstNum;
    double m_secondNum;
    double m_result;
    QString m_mainDisplay = "";
    QString m_subDisplay = "";
    const int DIGIT_LIMIT = 16;
    enum OPERATOR {
        initial,
        add,
        subtract,
        multiply,
        divide,
        exponent,
        equals
    };
    OPERATOR operatorPressed = initial;
    void numClicked(QString num);

};



#endif // CALCULATORS_H
