#ifndef GRAPHWINDOW_H
#define GRAPHWINDOW_H

#include <QWidget>
#include <QString>
#include "../controller/controller.h"


namespace Ui {
class GraphWindow;
}

class GraphWindow : public QWidget
{
    Q_OBJECT

public:
    explicit GraphWindow(QWidget *parent = nullptr);
    ~GraphWindow();
    void SetController(s21::Controller *source);
    void Plot();
    void SetFunc(QString source);

private slots:



    void on_plotGraph_clicked();

private:
    Ui::GraphWindow *ui;
    s21::Controller *_controller;
};


#endif // GRAPHWINDOW_H
