#include "mainwindow.h"

#include <QDir>

#include "../ui_mainwindow.h"
#include "../controller/controller.h"
//#include <QPushButton>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  QString binaryPlacement = QDir::currentPath();
  this->setStyleSheet("QMainWindow {background-image: url(" + binaryPlacement +
                      "/sources/Images/background1.jpeg);}");
  ui->label->setStyleSheet("QLabel {background-image: url(" + binaryPlacement +
                           "/sources/Images/school21_logo_2.png);}");

}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::SetController(s21::Controller *source) {
  this->_controller = source;
}

void MainWindow::FuncButtonClicked(QPushButton *button) {
  QString buttonName = button->text();
  _controller->UpdateInputString(buttonName.toStdString() + '(');
  _controller->UpdateLabel(ui->InputString);
}

void MainWindow::on_sin_clicked() { this->FuncButtonClicked(ui->sin); }

void MainWindow::on_tg_clicked() { this->FuncButtonClicked(ui->tg); }

void MainWindow::on_cos_clicked() { this->FuncButtonClicked(ui->cos); }

void MainWindow::on_asin_clicked() { this->FuncButtonClicked(ui->asin); }

void MainWindow::on_acos_clicked() { this->FuncButtonClicked(ui->acos); }

void MainWindow::on_atg_clicked() { this->FuncButtonClicked(ui->atg); }

void MainWindow::on_sqrt_clicked() { this->FuncButtonClicked(ui->sqrt); }

void MainWindow::on_ln_clicked() { this->FuncButtonClicked(ui->ln); }

void MainWindow::on_log_clicked() { this->FuncButtonClicked(ui->log); }

void MainWindow::NumberButtonClicked(QPushButton *button) {
  QString buttonName = button->text();
  _controller->UpdateInputString(buttonName.toStdString());
  _controller->UpdateLabel(ui->InputString);
}

void MainWindow::on_number_0_clicked() {
  this->NumberButtonClicked(ui->number_0);
}

void MainWindow::on_number_1_clicked() {
  this->NumberButtonClicked(ui->number_1);
}

void MainWindow::on_number_2_clicked() {
  this->NumberButtonClicked(ui->number_2);
}

void MainWindow::on_number_3_clicked() {
  this->NumberButtonClicked(ui->number_3);
}

void MainWindow::on_number_4_clicked() {
  this->NumberButtonClicked(ui->number_4);
}

void MainWindow::on_number_5_clicked() {
  this->NumberButtonClicked(ui->number_5);
}

void MainWindow::on_number_6_clicked() {
  this->NumberButtonClicked(ui->number_6);
}

void MainWindow::on_number_7_clicked() {
  this->NumberButtonClicked(ui->number_7);
}

void MainWindow::on_number_8_clicked() {
  this->NumberButtonClicked(ui->number_8);
}

void MainWindow::on_number_9_clicked() {
  this->NumberButtonClicked(ui->number_9);
}

void MainWindow::on_dot_clicked() { this->NumberButtonClicked(ui->dot); }

void MainWindow::on_rBracket_clicked() {
  this->NumberButtonClicked(ui->rBracket);
}

void MainWindow::on_lBracket_clicked() {
  this->NumberButtonClicked(ui->lBracket);
}

void MainWindow::on_power_clicked() { this->NumberButtonClicked(ui->power); }

void MainWindow::OperButtonClicked(QPushButton *button) {
  QString buttonName = button->text();
  _controller->UpdateInputString(buttonName.toStdString());
  _controller->UpdateLabel(ui->InputString);
}

void MainWindow::on_multiply_clicked() {
  this->OperButtonClicked(ui->multiply);
}

void MainWindow::on_substract_clicked() {
  this->OperButtonClicked(ui->substract);
}

void MainWindow::on_division_clicked() {
  this->OperButtonClicked(ui->division);
}

void MainWindow::on_addition_clicked() {
  this->OperButtonClicked(ui->addition);
}

void MainWindow::on_mod_clicked() { this->OperButtonClicked(ui->mod); }

void MainWindow::on_clear_clicked() {
  _controller->ClearInput();
  _controller->UpdateLabel(ui->InputString);
}

void MainWindow::on_equality_clicked() {
  double x = ui->xValue->text().toDouble();
  std::string text = _controller->CalculateResult(x);
  ui->ResultString->setText(QString::fromStdString(text));
}

void MainWindow::on_varX_clicked() { this->NumberButtonClicked(ui->varX); }

void MainWindow::on_unarySign_clicked() {
  _controller->SetUnarySign(ui->InputString);
}

//void MainWindow::on_drawGraph_clicked() {
//  _graph = new GraphWindow;
//  _graph->SetController(_controller);
//  _graph->SetFunc(ui->InputString->text());
//  _graph->show();
//}


