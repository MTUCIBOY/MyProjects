#include "mainwindow.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pushButton_15_clicked() {
  bool code = 0;
  QString str = ui->label->text();
  QByteArray mas = str.toUtf8();
  char *expression = mas.data();
  double result = calc(expression, &code);

  if (code)
    ui->label->setText("Error!");
  else {
    str = QString::number(result);
    ui->label->setText(str);
  }
}

void MainWindow::on_pushButton_1_clicked() {
  QString A = ui->label->text() + "1";
  ui->label->setText(A);
}

void MainWindow::on_pushButton_28_clicked() { ui->label->clear(); }

void MainWindow::on_pushButton_2_clicked() {
  QString A = ui->label->text() + "2";
  ui->label->setText(A);
}

void MainWindow::on_pushButton_3_clicked() {
  QString A = ui->label->text() + "3";
  ui->label->setText(A);
}

void MainWindow::on_pushButton_4_clicked() {
  QString A = ui->label->text() + "4";
  ui->label->setText(A);
}

void MainWindow::on_pushButton_5_clicked() {
  QString A = ui->label->text() + "5";
  ui->label->setText(A);
}

void MainWindow::on_pushButton_6_clicked() {
  QString A = ui->label->text() + "6";
  ui->label->setText(A);
}

void MainWindow::on_pushButton_7_clicked() {
  QString A = ui->label->text() + "7";
  ui->label->setText(A);
}

void MainWindow::on_pushButton_8_clicked() {
  QString A = ui->label->text() + "8";
  ui->label->setText(A);
}

void MainWindow::on_pushButton_9_clicked() {
  QString A = ui->label->text() + "9";
  ui->label->setText(A);
}

void MainWindow::on_pushButton_10_clicked() {
  QString A = ui->label->text() + " + ";
  ui->label->setText(A);
}

void MainWindow::on_pushButton_11_clicked() {
  QString A = ui->label->text() + " - ";
  ui->label->setText(A);
}

void MainWindow::on_pushButton_12_clicked() {
  QString A = ui->label->text() + " * ";
  ui->label->setText(A);
}

void MainWindow::on_pushButton_13_clicked() {
  QString A = ui->label->text() + " / ";
  ui->label->setText(A);
}

void MainWindow::on_pushButton_14_clicked() {
  QString A = ui->label->text() + " ^ ";
  ui->label->setText(A);
}

void MainWindow::on_pushButton_16_clicked() {
  QString A = ui->label->text() + " cos ";
  ui->label->setText(A);
}

void MainWindow::on_pushButton_17_clicked() {
  QString A = ui->label->text() + " sin ";
  ui->label->setText(A);
}

void MainWindow::on_pushButton_18_clicked() {
  QString A = ui->label->text() + " tan ";
  ui->label->setText(A);
}

void MainWindow::on_pushButton_19_clicked() {
  QString A = ui->label->text() + " acos ";
  ui->label->setText(A);
}

void MainWindow::on_pushButton_20_clicked() {
  QString A = ui->label->text() + " asin ";
  ui->label->setText(A);
}

void MainWindow::on_pushButton_21_clicked() {
  QString A = ui->label->text() + " atan ";
  ui->label->setText(A);
}

void MainWindow::on_pushButton_22_clicked() {
  QString A = ui->label->text() + " sqrt ";
  ui->label->setText(A);
}

void MainWindow::on_pushButton_23_clicked() {
  QString A = ui->label->text() + " ln ";
  ui->label->setText(A);
}

void MainWindow::on_pushButton_24_clicked() {
  QString A = ui->label->text() + " log ";
  ui->label->setText(A);
}

void MainWindow::on_pushButton_25_clicked() {
  QString A = ui->label->text() + "( ";
  ui->label->setText(A);
}

void MainWindow::on_pushButton_26_clicked() {
  QString A = ui->label->text() + " )";
  ui->label->setText(A);
}

void MainWindow::on_pushButton_29_clicked() {
  QString A = ui->label->text() + "0";
  ui->label->setText(A);
}

void MainWindow::on_pushButton_30_clicked() {
  QString A = ui->label->text() + ",";
  ui->label->setText(A);
}

void MainWindow::on_pushButton_31_clicked() {
  QString currentText = ui->label->text();
  if (!currentText.isEmpty()) {
    currentText.chop(1);
    ui->label->setText(currentText);
  }
}

void MainWindow::on_pushButton_33_clicked() {
  graph = new Graph;
  graph->drawGraph(ui->label->text());
  graph->setMathLabelText(ui->label->text());
  graph->show();
}

void MainWindow::on_pushButton_27_clicked() {
  QString A = ui->label->text() + "x";
  ui->label->setText(A);
}

void MainWindow::on_pushButton_32_clicked() {
  QString A = ui->label->text() + "E";
  ui->label->setText(A);
}

void MainWindow::on_pushButton_34_clicked() {
  QString A = ui->label->text() + " mod ";
  ui->label->setText(A);
}
