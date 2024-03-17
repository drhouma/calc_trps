#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "../controller/controller.h"
#include "interface/graphwindow.h"
//#include "graphwindow.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void SetController(s21::Controller *source);

private slots:



    void on_sin_clicked();
    void on_cos_clicked();
    void on_tg_clicked();
    void on_asin_clicked();
    void on_acos_clicked();
    void on_atg_clicked();
    void on_sqrt_clicked();
    void on_ln_clicked();
    void on_log_clicked();

    void on_number_0_clicked();
    void on_number_1_clicked();
    void on_number_2_clicked();
    void on_number_3_clicked();
    void on_number_4_clicked();
    void on_number_5_clicked();
    void on_number_6_clicked();
    void on_number_7_clicked();
    void on_number_8_clicked();
    void on_number_9_clicked();
    void on_dot_clicked();
    void on_rBracket_clicked();
    void on_lBracket_clicked();
    void on_power_clicked();

    void on_multiply_clicked();
    void on_substract_clicked();
    void on_addition_clicked();
    void on_division_clicked();
    void on_mod_clicked();

    void on_clear_clicked();

    void NumberButtonClicked(QPushButton *button);

    void FuncButtonClicked(QPushButton *button);

    void OperButtonClicked(QPushButton *button);

    void on_equality_clicked();

    void on_varX_clicked();

    void on_unarySign_clicked();

//    void on_drawGraph_clicked();

private:
    s21::Controller *_controller;
    Ui::MainWindow *ui;
//    GraphWindow *_graph;
};
#endif // MAINWINDOW_H
