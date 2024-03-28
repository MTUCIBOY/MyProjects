#include "graph.h"

#include "mainwindow.h"
#include "ui_graph.h"

Graph::Graph(QWidget *parent) : QWidget(parent), ui(new Ui::Graph) {
  ui->setupUi(this);
}

void Graph::drawGraph(const QString &math_function) {
  bool code;
  xBegin = -30;
  xEnd = 30;
  h = 0.1;

  ui->widget->xAxis->setRange(-30, 30);
  ui->widget->yAxis->setRange(-30, 30);

  for (X = xBegin; X < xEnd; X += h) {
    x.push_back(X);
    QString myQString = math_function;
    QByteArray byteArray = myQString.toUtf8();
    const char *myStr = byteArray.constData();

    std::string expression = myStr;
    for (size_t pos = expression.find('x'); pos != std::string::npos;
         pos = expression.find('x', pos)) {
      expression.replace(pos, 1, QString::number(X).toStdString());
    }
    for (size_t pos = expression.find('.'); pos != std::string::npos;
         pos = expression.find('.', pos)) {
      expression.replace(pos, 1, ",");
    }
    char expressionBuffer[1000];
    snprintf(expressionBuffer, sizeof(expressionBuffer), "%s",
             expression.c_str());
    y.push_back(calc(expressionBuffer, &code));
  }
  ui->widget->addGraph();
  ui->widget->graph(0)->addData(x, y);
  ui->widget->replot();
}

Graph::~Graph() { delete ui; }

void Graph::setMathLabelText(const QString &text) {
  ui->math_label->setText(text);
}

QString Graph::getMathLabelText() {
  if (ui && ui->math_label) {
    return ui->math_label->text();
  } else {
    qDebug() << "Error: UI elements not initialized correctly.";
    return QString();  // Return an empty QString as a default value
  }
}
