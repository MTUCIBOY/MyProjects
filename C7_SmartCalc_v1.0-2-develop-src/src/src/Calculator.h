#pragma once
#include <QtWidgets>

#include "qcustomplot.h"

extern "C" {
int calc_main(char* str, double* result, double x);
}

class Calc : public QWidget {
  Q_OBJECT
 private:
  QString* expr_str = new QString("");
  QApplication* p_app = nullptr;
  char* calc_str = new char[256];
  bool hasX = false;

  QLabel* lbl = new QLabel("its label");
  QLineEdit* display = new QLineEdit("its_display");

  QSignalMapper* calc_mapper = new QSignalMapper(this);

  QPushButton* btn_0 = new QPushButton("0");
  QPushButton* btn_1 = new QPushButton("1");
  QPushButton* btn_2 = new QPushButton("2");
  QPushButton* btn_3 = new QPushButton("3");
  QPushButton* btn_4 = new QPushButton("4");
  QPushButton* btn_5 = new QPushButton("5");
  QPushButton* btn_6 = new QPushButton("6");
  QPushButton* btn_7 = new QPushButton("7");
  QPushButton* btn_8 = new QPushButton("8");
  QPushButton* btn_9 = new QPushButton("9");

  QPushButton* btn_clear = new QPushButton("C");
  QPushButton* btn_equal = new QPushButton("=");
  QPushButton* btn_dot = new QPushButton(".");
  QPushButton* btn_l_brack = new QPushButton("(");
  QPushButton* btn_r_brack = new QPushButton(")");
  QPushButton* btn_x = new QPushButton("x");

  QPushButton* btn_sin = new QPushButton("sin");
  QPushButton* btn_cos = new QPushButton("cos");
  QPushButton* btn_tan = new QPushButton("tan");

  QPushButton* btn_acos = new QPushButton("acos");
  QPushButton* btn_asin = new QPushButton("asin");
  QPushButton* btn_atan = new QPushButton("atan");

  QPushButton* btn_ln = new QPushButton("ln");
  QPushButton* btn_log = new QPushButton("log");
  QPushButton* btn_sqrt = new QPushButton("sqrt");
  QPushButton* btn_plot = new QPushButton("plot");

  QPushButton* btn_plus = new QPushButton("+");
  QPushButton* btn_minus = new QPushButton("-");
  QPushButton* btn_mult = new QPushButton("*");
  QPushButton* btn_div = new QPushButton("/");
  QPushButton* btn_pow = new QPushButton("^");
  QPushButton* btn_mod = new QPushButton("mod");

  QPushButton* btn_quit = new QPushButton("quit");
  QCustomPlot* custom_plot = new QCustomPlot();

  QLabel* boxLabel_Xmax = new QLabel("X max:");
  QLabel* boxLabel_Xmin = new QLabel("X min:");

  QLabel* boxLabel_Ymax = new QLabel("Y max:");
  QLabel* boxLabel_Ymin = new QLabel("Y min:");

  QDoubleSpinBox* spinBoxSetX = new QDoubleSpinBox;
  QDoubleSpinBox* spinBoxXmax = new QDoubleSpinBox;
  QDoubleSpinBox* spinBoxXmin = new QDoubleSpinBox;

  QDoubleSpinBox* spinBoxYmax = new QDoubleSpinBox;
  QDoubleSpinBox* spinBoxYmin = new QDoubleSpinBox;

  QVector<double>* plot_x = nullptr;
  QVector<double>* plot_y = nullptr;

  QGridLayout* button_layout = new QGridLayout(this);

 public:
  Calc(QApplication* app);
  ~Calc(){};

  void buttonConnect();
  bool calculate(double* result);

 public slots:
  void getButtonClicked(const QString&);
  void clearStr();
  void equalProcessing();
  void setX();
  void setPlot();
 signals:
  void sendExp(const QString&);
};
