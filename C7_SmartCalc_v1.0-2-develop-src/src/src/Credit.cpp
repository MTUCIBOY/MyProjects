#include "Credit.h"

CreditCalc::CreditCalc(QApplication* app) {
  p_app = app;

  calc_layout->addWidget(amount_lbl, 0, 0);
  amount_lbl->setAlignment(Qt::AlignRight);
  calc_layout->addWidget(display, 0, 1);

  display->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
  display->setRange(0.0, 1000000.0);

  slider->setRange(0, 1000000);
  slider->setMaximumWidth(350);
  calc_layout->addWidget(slider, 1, 1);

  calc_layout->addWidget(term_lbl, 3, 0);
  term_lbl->setAlignment(Qt::AlignRight);
  spin_term->setDecimals(0);
  spin_term->setMinimum(1);
  calc_layout->addWidget(spin_term, 3, 1);

  calc_layout->addWidget(percent_lbl, 4, 0);
  percent_lbl->setAlignment(Qt::AlignRight);
  spin_percent->setMinimum(1);
  spin_percent->setDecimals(1);
  calc_layout->addWidget(spin_percent, 4, 1);

  calc_layout->addWidget(btn_calc, 5, 1);

  display_month_pay->setButtonSymbols(
      QAbstractSpinBox::ButtonSymbols::NoButtons);
  display_month_pay->setReadOnly(true);
  display_month_pay->setRange(0, 1000000);
  calc_layout->addWidget(month_lbl, 6, 0);
  month_lbl->setAlignment(Qt::AlignRight);
  calc_layout->addWidget(display_month_pay, 6, 1);

  display_overpay->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
  display_overpay->setReadOnly(true);
  display_overpay->setRange(0, 1000000);
  calc_layout->addWidget(overpay_lbl, 7, 0);
  overpay_lbl->setAlignment(Qt::AlignRight);
  calc_layout->addWidget(display_overpay, 7, 1);

  display_total_pay->setButtonSymbols(
      QAbstractSpinBox::ButtonSymbols::NoButtons);
  display_total_pay->setReadOnly(true);
  display_total_pay->setRange(0, 1000000);
  calc_layout->addWidget(total_lbl, 8, 0);
  total_lbl->setAlignment(Qt::AlignRight);
  calc_layout->addWidget(display_total_pay, 8, 1);

  calc_layout->addWidget(btn_quit, 9, 1);

  this->setLayout(calc_layout);
  buttonConnect();
};

void CreditCalc::buttonConnect() {
  connect(btn_quit, SIGNAL(clicked()), p_app, SLOT(quit()));

  connect(slider, SIGNAL(valueChanged(int)), this, SLOT(sliderConvert(int)));
  connect(this, SIGNAL(sliderChanged(double)), display, SLOT(setValue(double)));

  connect(display, SIGNAL(valueChanged(double)), this,
          SLOT(displayConvert(double)));

  connect(btn_calc, SIGNAL(clicked()), this, SLOT(calc_parameters()));
}

void CreditCalc::sliderConvert(int value) {
  emit sliderChanged(static_cast<double>(value));
}

void CreditCalc::displayConvert(double value) {
  slider->setSliderPosition(static_cast<int>(value));
}

void CreditCalc::calc_parameters() {
  double amount = display->value();
  qDebug() << "spin_amount: " << display->value();
  double term = spin_term->value();
  double percent = spin_percent->value();
  double month_pay = 0;
  double overpay = 0;
  double total = 0;

  qDebug() << "calc start";
  qDebug() << "amount: " << amount << "term: " << term
           << "percent: " << percent;
  bank_credit(amount, term, percent, &month_pay, &overpay, &total);

  qDebug() << "month_pay: " << month_pay << "overpay: " << overpay
           << "total: " << total;

  display_month_pay->setValue(month_pay);
  display_overpay->setValue(overpay);
  display_total_pay->setValue(total);
}
