#pragma once
#include <QtWidgets>

extern "C" {

int bank_credit(double amount, double term, double percent, double* month_pay,
                double* overpay, double* total);
}

class CreditCalc : public QWidget {
  Q_OBJECT
 private:
  QApplication* p_app = nullptr;
  QSlider* slider = new QSlider(Qt::Horizontal);

  QLabel* amount_lbl = new QLabel("Amount:");
  QLabel* term_lbl = new QLabel("term:");
  QLabel* percent_lbl = new QLabel("percent:");
  QLabel* month_lbl = new QLabel("month pay:");
  QLabel* overpay_lbl = new QLabel("overpay:");
  QLabel* total_lbl = new QLabel("total pay:");

  QPushButton* btn_quit = new QPushButton("quit");
  QPushButton* btn_calc = new QPushButton("calculate");

  QDoubleSpinBox* display = new QDoubleSpinBox;
  QDoubleSpinBox* display_month_pay = new QDoubleSpinBox;
  QDoubleSpinBox* display_overpay = new QDoubleSpinBox;
  QDoubleSpinBox* display_total_pay = new QDoubleSpinBox;

  QDoubleSpinBox* spin_amount = new QDoubleSpinBox;
  QDoubleSpinBox* spin_term = new QDoubleSpinBox;
  QDoubleSpinBox* spin_percent = new QDoubleSpinBox;

  QGridLayout* calc_layout = new QGridLayout(this);

 public:
  CreditCalc(QApplication* app);
  ~CreditCalc(){};

  void buttonConnect();

 public slots:
  void sliderConvert(int);
  void displayConvert(double);
  void calc_parameters();

 signals:
  void sliderChanged(double);
};
