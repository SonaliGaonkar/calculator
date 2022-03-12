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



public slots:
    void NumPressed();
    void MathButtonPressed();
    void EqualButtonPressed();

    void C();
    void CE();
void addbrackets();
void T1();
    void T2();
 void T3();
private:
    double m_firstNum;
    double m_secondNum;
    double m_result;
    QString m_mainDisplay = "";
    QString m_subDisplay = "";
};



#endif // CALCULATORS_H
