#ifndef CALCULATORS_H
#define CALCULATORS_H
#include <QMainWindow>

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
    void numText();
    void unaryoperator();
    void equalButtonPressed();
    void theme1();
    void theme2();
    void theme3();
};
#endif
