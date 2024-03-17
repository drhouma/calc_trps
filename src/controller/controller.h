#pragma once
#include "../model/model.h"
#include <string>
#include <QLabel>
#include <vector>

namespace s21 {

class Controller {
private:
    Model *_model;

public:
    Controller();
    Controller(Model *model);

    void SetModel(Model* model) {
        _model = model;
    }

    void UpdateInputString(std::string source);

    void UpdateLabel(QLabel *label);

    void ClearInput();

    std::string CalculateResult( double x);

    QVector<double> GetData(double xMin, double xMax, QVector<double> &xValues, int NumberOfPoints);

    void SetUnarySign(QLabel *label);

    bool CheckInput();

//    bool CheckInput();




};
}
