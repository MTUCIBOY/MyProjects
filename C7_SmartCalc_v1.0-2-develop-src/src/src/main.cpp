#include <QtWidgets>

#include "Calculator.h"
#include "Credit.h"
#include "Deposit.h"

int main(int argc, char** argv) {
  QApplication app(argc, argv);
  setlocale(LC_ALL, "C");

  QTabWidget tab;

  tab.addTab(new Calc(&app), "Smart calculator");
  tab.addTab(new DepositCalc(&app), "Deposit calculator");
  tab.addTab(new CreditCalc(&app), "Credit calculator");

  tab.show();

  return app.exec();
}
