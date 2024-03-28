#include "mainwindow.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pushButton_clicked() {
  ui->listWidget->clear();
  double amount = ui->amountLine->text().toDouble();
  double procent = ui->procentLine->text().toDouble();
  int term = ui->termLine->text().toDouble();
  double rmt = RMT_A(amount, procent, term);

  if (amount < 1 || procent < 1 || term < 1) return;

  ui->OP->setText(QString::number(Overpayment(rmt, amount, term)));
  ui->TP->setText(QString::number(Total_Payment(rmt, term)));
  ui->RMT_A->setText(QString::number(rmt));

  for (int i = 1; i <= term; i++) {
    ui->listWidget->addItem(QString::number(RMT_D(amount, procent, term, i)));
  }
}
