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

private:
    Ui::calculators *ui;

private slots:
    void NumPressed();
    void MathButtonPressed();
    void EqualButtonPressed();
    void ChangeNumberSign();
    void on_C_clicked();

    void on_CE_clicked();
    void on_DOT_clicked();
private:


    double m_firstNum;
    double m_secondNum;
    double m_result;
    QString m_mainDisplay = "0";
    QString m_subDisplay = "";
};
#endif // CALCULATORS_H
