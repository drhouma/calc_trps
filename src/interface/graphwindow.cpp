#include "graphwindow.h"

#include <QVector>

#include "../ui_graphwindow.h"

#define NUMBER_OF_POINTS 10000

void GraphWindow::SetFunc(QString source) { ui->function->setText(source); }

GraphWindow::GraphWindow(QWidget *parent)
    : QWidget(parent), ui(new Ui::GraphWindow) {
  ui->setupUi(this);
  ui->plot->addGraph();
  //    ui->plot->xAxis->setLabel("x");
  //    ui->plot->yAxis->setLabel("y");
  ui->plot->setInteraction(QCP::iRangeDrag, true);
  ui->plot->setInteraction(QCP::iRangeZoom, true);
  ui->plot->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
  ui->plot->graph(0)->setLineStyle(QCPGraph::lsNone);
}

void GraphWindow::SetController(s21::Controller *source) {
  this->_controller = source;
}

GraphWindow::~GraphWindow() { delete ui; }

void GraphWindow::Plot() {
  double xMax = ui->XAxisMax->text().toDouble();
  double xMin = ui->XAxisMin->text().toDouble();
  std::string func = ui->function->text().toStdString();
  QVector<double> x, y;
  y = _controller->GetData(xMin, xMax, x, NUMBER_OF_POINTS);
  ui->plot->graph(0)->setData(x, y);
  ui->plot->xAxis->setRange(xMin, xMax);
  ui->plot->yAxis->setRange(xMin, xMax);
  ui->plot->replot();
}

void GraphWindow::on_plotGraph_clicked() {
    if (_controller->CheckInput())
        Plot();
    else {
        ui->function->setText("invalid function");
    }
}
