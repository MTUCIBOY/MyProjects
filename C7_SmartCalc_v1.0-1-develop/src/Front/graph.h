#ifndef GRAPH_H
#define GRAPH_H

#include <QWidget>

namespace Ui {
class Graph;
}

class Graph : public QWidget {
  Q_OBJECT

 public:
  explicit Graph(QWidget *parent = nullptr);
  void setMathLabelText(const QString &text);
  void drawGraph(const QString &math_function);
  QString getMathLabelText();
  ~Graph();

 private:
  Ui::Graph *ui;
  double xBegin, xEnd, h, X;
  int N;

  QVector<double> x, y;
};

#endif  // GRAPH_H
