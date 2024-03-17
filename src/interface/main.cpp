#include <QApplication>

#include "../controller/controller.h"
#include "mainwindow.h"

int main(int argc, char *argv[]) {
  s21::Model myModel;
  s21::Controller controller(&myModel);
  QApplication a(argc, argv);
  MainWindow w;
  w.SetController(&controller);
  w.show();
  return a.exec();
}
