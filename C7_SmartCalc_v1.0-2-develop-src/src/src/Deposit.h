#pragma once
#include <QtWidgets>

extern "C" {
int bank_deposit(double amount, double term, double percent, int capitalization,
                 double* amount_end, double* income);

int bank_credit(double amount, double term, double percent, double* month_pay,
                double* overpay, double* total);
}

class DepositCalc : public QWidget {
  Q_OBJECT
 private:
  QApplication* p_app = nullptr;
  QSlider* slider = new QSlider(Qt::Horizontal);

  QLabel* amount_lbl = new QLabel("Amount:");
  QLabel* term_lbl = new QLabel("term:");
  QLabel* percent_lbl = new QLabel("percent:");
  QLabel* capital_lbl = new QLabel();
  QLabel* deposit_lbl = new QLabel("deposit income:");
  QLabel* amount_end_lbl = new QLabel("amount at the end of term:");

  QPushButton* btn_quit = new QPushButton("quit");
  QPushButton* btn_calc = new QPushButton("calculate");

  QDoubleSpinBox* display = new QDoubleSpinBox;
  QCheckBox* capital_box = new QCheckBox("capitalization");
  QDoubleSpinBox* display_income = new QDoubleSpinBox;
  QDoubleSpinBox* display_amount_end = new QDoubleSpinBox;

  QDoubleSpinBox* spin_term = new QDoubleSpinBox;
  QDoubleSpinBox* spin_percent = new QDoubleSpinBox;

  QGridLayout* calc_layout = new QGridLayout(this);

 public:
  DepositCalc(QApplication* app);
  ~DepositCalc(){};

  void buttonConnect();

 public slots:
  void sliderConvert(int);
  void displayConvert(double);
  void calc_parameters();

 signals:
  void sliderChanged(double);
};
