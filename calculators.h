#ifndef CALCULATORS_H
#define CALCULATORS_H

#include <QMainWindow>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stack>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui { class calculators; }
QT_END_NAMESPACE

class calculators : public QMainWindow
{
    Q_OBJECT

public:
    calculators(QWidget *parent = nullptr);
    ~calculators();

public:
    Ui::calculators *ui;
bool waitingForOperand;

  public slots:
    void setText();
    void equalButtonPressed();
    void decimal();
    void theme1();
    void theme2();
    void theme3();

private:
    double m_firstNum;
    double m_secondNum;
    double m_result;
    QString mainDisplay = "";
    QString subDisplay = "";
};
#endif // CALCULATORS_H
