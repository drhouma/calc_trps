#include "controller.h"
#include <QVector>

namespace s21 {

Controller::Controller(Model *model) { _model = model; }

Controller::Controller() {}

void Controller::UpdateInputString(std::string source) {
  _model->PutStringInInput(source);
}

void Controller::UpdateLabel(QLabel *label) {
  QString qstr = QString::fromStdString(_model->GetStringInput());
  label->setText(qstr);
}

void Controller::ClearInput() { _model->ClearStringInput(); }

std::string Controller::CalculateResult(double x) {
  if (!_model->BracketsEquality() || !_model->CheckMultyplyPoints()) return "Syntax Error";
  PolishNotation pn(_model->GetInputString());
  return std::to_string(pn.calculate(x));
}

void Controller::SetUnarySign(QLabel *label) {
    _model->PrintUnary(label->text().toStdString());
    this->UpdateLabel(label);
}

bool Controller::CheckInput() {
    return _model->CheckMultyplyPoints() && _model->BracketsEquality();
}

QVector<double> Controller::GetData(double xMin, double xMax, QVector<double> &xValues, int NumberOfPoints) {
    QVector<double> y;
    if (!_model->BracketsEquality()) return y;

    PolishNotation pn(_model->GetInputString());
    double step = (xMax - xMin) / NumberOfPoints;
    double value = xMin;
    std::string func = _model->GetInputString();
    for (int i=0; i< NumberOfPoints; ++i, value+=step)
    {
      xValues.push_back(value);
      y.push_back(pn.calculate(value));
    }
    return y;
}
}



