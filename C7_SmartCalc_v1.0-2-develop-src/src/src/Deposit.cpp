#include "Deposit.h"

DepositCalc::DepositCalc(QApplication* app) {
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
  calc_layout->addWidget(spin_term, 3, 1);

  calc_layout->addWidget(percent_lbl, 4, 0);
  percent_lbl->setAlignment(Qt::AlignRight);
  spin_percent->setDecimals(2);
  calc_layout->addWidget(spin_percent, 4, 1);

  calc_layout->addWidget(btn_calc, 5, 1);

  calc_layout->addWidget(capital_lbl, 6, 0);
  capital_lbl->setAlignment(Qt::AlignRight);
  calc_layout->addWidget(capital_box, 6, 1);

  display_income->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
  display_income->setReadOnly(true);
  display_income->setRange(0, 1000000);
  calc_layout->addWidget(deposit_lbl, 7, 0);
  deposit_lbl->setAlignment(Qt::AlignRight);
  calc_layout->addWidget(display_income, 7, 1);

  display_amount_end->setButtonSymbols(
      QAbstractSpinBox::ButtonSymbols::NoButtons);
  display_amount_end->setReadOnly(true);
  display_amount_end->setRange(0, 1000000);
  calc_layout->addWidget(amount_end_lbl, 8, 0);
  amount_end_lbl->setAlignment(Qt::AlignRight);
  calc_layout->addWidget(display_amount_end, 8, 1);

  calc_layout->addWidget(btn_quit, 9, 1);

  this->setLayout(calc_layout);
  buttonConnect();
};

void DepositCalc::buttonConnect() {
  connect(btn_quit, SIGNAL(clicked()), p_app, SLOT(quit()));

  connect(slider, SIGNAL(valueChanged(int)), this, SLOT(sliderConvert(int)));
  connect(this, SIGNAL(sliderChanged(double)), display, SLOT(setValue(double)));

  connect(display, SIGNAL(valueChanged(double)), this,
          SLOT(displayConvert(double)));

  connect(btn_calc, SIGNAL(clicked()), this, SLOT(calc_parameters()));
}

void DepositCalc::sliderConvert(int value) {
  emit sliderChanged(static_cast<double>(value));
}

void DepositCalc::displayConvert(double value) {
  slider->setSliderPosition(static_cast<int>(value));
}

void DepositCalc::calc_parameters() {
  double amount = display->value();
  qDebug() << "spin_amount: " << display->value();
  double term = spin_term->value();
  double percent = spin_percent->value();
  double income = 0;
  double amount_end = 0;
  int capitalization = 0;

  if (capital_box->isChecked())
    capitalization = 0;
  else
    capitalization = 1;

  qDebug() << "check box: " << capital_box->isChecked();

  qDebug() << "calc start";
  qDebug() << "amount: " << amount << "term: " << term
           << "percent: " << percent;

  bank_deposit(amount, term, percent, capitalization, &amount_end, &income);

  qDebug() << "income: " << income << "amount_end: " << amount_end;

  display_income->setValue(income);
  display_amount_end->setValue(amount_end);
}
