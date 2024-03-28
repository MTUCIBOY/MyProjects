#include "mainwindow.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pushButton_clicked() {
  int rowCount = ui->TableWidgetLoan->rowCount();
  ui->TableWidgetLoan->insertRow(rowCount);
}

void MainWindow::on_pushButton_2_clicked() {
  int currentRow = ui->TableWidgetLoan->currentRow();

  if (currentRow >= 0) ui->TableWidgetLoan->removeRow(currentRow);
}

void MainWindow::on_pushButton_3_clicked() {
  int rowCount = ui->TableWidgetRep->rowCount();
  ui->TableWidgetRep->insertRow(rowCount);
}

void MainWindow::on_pushButton_4_clicked() {
  int currentRow = ui->TableWidgetRep->currentRow();

  if (currentRow >= 0) ui->TableWidgetRep->removeRow(currentRow);
}

void MainWindow::on_pushButton_5_clicked() {
  ui->listWidget->clear();
  double amount = ui->DSum->text().toDouble();
  double procent_D = ui->Procent->text().toDouble();
  double procent_Tax = ui->Tax_procent->text().toDouble();
  int term = ui->Term->text().toDouble();
  bool capital = ui->Capital->checkState();
  int period = ui->comboBox->currentIndex();
  double S0 = 1000000 * procent_Tax / 100;
  double full_earn = 0;
  double earn = 0;
  double year_earn = 0;
  double tax = 0;
  int maxrowLoan = ui->TableWidgetLoan->rowCount();
  int maxrowRep = ui->TableWidgetRep->rowCount();
  int num_of_mount = 0;
  double LoanRep = 0;

  if (period == 0) term *= 30;

  if (amount < 1 || procent_D < 1 || procent_Tax < 1 || term < 1) return;

  if (capital) {
    // Year
    for (int i = 1; i <= term && period == 2; i++) {
      for (int k = 0; k < maxrowLoan; k++) {
        num_of_mount = ui->TableWidgetLoan->item(k, 1)->text().toInt();
        if (i == num_of_mount) {
          LoanRep = ui->TableWidgetLoan->item(k, 0)->text().toDouble();
          amount -= LoanRep;
        }
      }
      for (int k = 0; k < maxrowRep; k++) {
        num_of_mount = ui->TableWidgetRep->item(k, 1)->text().toInt();
        if (i == num_of_mount) {
          LoanRep = ui->TableWidgetRep->item(k, 0)->text().toDouble();

          amount += LoanRep;
        }
      }

      earn += deposit(amount, procent_D, 1);
      if (i % 12 == 0) {
        ui->listWidget->addItem(QString::number(earn));
        tax += taxies(earn, S0);
        earn -= taxies(earn, S0);
        full_earn += earn;
        amount += earn;
        earn = 0;
      }
    }
    if (earn != 0) {
      ui->listWidget->addItem(QString::number(earn));
      tax += taxies(earn, S0);
      earn -= taxies(earn, S0);
      full_earn += earn;
      amount += earn;
    }

    // month
    for (int i = 1; i <= term && period != 2; i++) {
      for (int k = 0; k < maxrowLoan; k++) {
        num_of_mount = ui->TableWidgetLoan->item(k, 1)->text().toInt();
        if (i == num_of_mount) {
          LoanRep = ui->TableWidgetLoan->item(k, 0)->text().toDouble();
          amount -= LoanRep;
        }
      }
      for (int k = 0; k < maxrowRep; k++) {
        num_of_mount = ui->TableWidgetRep->item(k, 1)->text().toInt();
        if (i == num_of_mount) {
          LoanRep = ui->TableWidgetRep->item(k, 0)->text().toDouble();
          amount += LoanRep;
        }
      }

      earn = deposit(amount, procent_D, period);
      ui->listWidget->addItem(QString::number(earn));
      year_earn += earn;
      if ((i % 12 == 0 && period == 1) || (i % 360 == 0 && period == 0) ||
          i == term) {
        tax += taxies(year_earn, S0);
        earn -= taxies(year_earn, S0);
        full_earn += earn;
        amount += earn;
        year_earn = 0;
        continue;
      }
      amount += earn;
      full_earn += earn;
    }
  } else {
    for (int i = 1; i <= term && period == 2; i++) {
      for (int k = 0; k < maxrowLoan; k++) {
        num_of_mount = ui->TableWidgetLoan->item(k, 1)->text().toInt();
        if (i == num_of_mount) {
          LoanRep = ui->TableWidgetLoan->item(k, 0)->text().toDouble();
          amount -= LoanRep;
        }
      }
      for (int k = 0; k < maxrowRep; k++) {
        num_of_mount = ui->TableWidgetRep->item(k, 1)->text().toInt();
        if (i == num_of_mount) {
          LoanRep = ui->TableWidgetRep->item(k, 0)->text().toDouble();
          amount += LoanRep;
        }
      }

      earn += deposit(amount, procent_D, 1);
      if (i % 12 == 0) {
        ui->listWidget->addItem(QString::number(earn));
        tax += taxies(earn, S0);
        earn -= taxies(earn, S0);
        full_earn += earn;
        earn = 0;
      }
    }
    if (period == 2) {
      if (earn != 0) {
        ui->listWidget->addItem(QString::number(earn));
        tax += taxies(earn, S0);
        earn -= taxies(earn, S0);
        full_earn += earn;
      }
      amount += full_earn;
    }

    for (int i = 1; i <= term && period != 2; i++) {
      for (int k = 0; k < maxrowLoan; k++) {
        num_of_mount = ui->TableWidgetLoan->item(k, 1)->text().toInt();
        if (i == num_of_mount) {
          LoanRep = ui->TableWidgetLoan->item(k, 0)->text().toDouble();
          amount -= LoanRep;
        }
      }
      for (int k = 0; k < maxrowRep; k++) {
        num_of_mount = ui->TableWidgetRep->item(k, 1)->text().toInt();
        if (i == num_of_mount) {
          LoanRep = ui->TableWidgetRep->item(k, 0)->text().toDouble();
          amount += LoanRep;
        }
      }

      earn = deposit(amount, procent_D, period);
      ui->listWidget->addItem(QString::number(earn));
      year_earn += earn;
      if ((i % 12 == 0 && period == 1) || (i % 360 == 0 && period == 0) ||
          i == term) {
        tax += taxies(year_earn, S0);
        earn -= taxies(year_earn, S0);
        full_earn += earn;
        amount += earn;
        year_earn = 0;
        continue;
      }
      full_earn += earn;
    }
    if (period != 2) {
      amount += full_earn;
    }
  }

  ui->Total_D->setText(QString::number(amount, 'f', 2));
  ui->SumProc->setText(QString::number(full_earn, 'f', 2));
  ui->Tax->setText(QString::number(tax));
}
