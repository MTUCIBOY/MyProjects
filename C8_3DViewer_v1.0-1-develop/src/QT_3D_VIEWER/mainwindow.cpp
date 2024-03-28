#include "mainwindow.h"

#include "glwidget.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  pressed = false;
  leftButton = false;
  ui->setupUi(this);
  ui->infoLabel->setText(
      "name: Standart cube\nPoints count: " +
      QString::number(ui->openGLWidget->getVerticesCount()) +
      "\tFacets count: " + QString::number(ui->openGLWidget->getFacetsCount()));
}

MainWindow::~MainWindow() {
  delete gif;
  delete ui;
}

void MainWindow::on_Button_left_clicked() {
  // MovePoints(&_p, -0.1, 0, 0);
  ui->openGLWidget->moveModel(-0.1, 0, 0);
}

void MainWindow::on_Button_up_clicked() {
  // MovePoints(&_p, 0, 0.1, 0);
  ui->openGLWidget->moveModel(0, 0.1, 0);
}

void MainWindow::on_Button_down_clicked() {
  // MovePoints(&_p, 0, -0.1, 0);
  ui->openGLWidget->moveModel(0, -0.1, 0);
}

void MainWindow::on_Button_right_clicked() {
  // MovePoints(&_p, 0.1, 0, 0);
  ui->openGLWidget->moveModel(0.1, 0, 0);
}

void MainWindow::on_Button_in_clicked() {
  // MovePoints(&_p, 0, 0, 0.1);
  ui->openGLWidget->moveModel(0, 0, 0.1);
}

void MainWindow::on_Button_out_clicked() {
  // MovePoints(&_p, 0, 0, -0.1);
  ui->openGLWidget->moveModel(0, 0, -0.1);
}

void MainWindow::on_Button_zoomIn_clicked() {
  // zoom(&_p, 0.1);
  ui->openGLWidget->zoomModel(0.1);
}

void MainWindow::on_Button_zoomOut_clicked() {
  // zoom(&_p, -0.1);
  ui->openGLWidget->zoomModel(-0.1);
}

void MainWindow::on_Button_filename_clicked() {
  QString filePath =
      QFileDialog::getOpenFileName(this, "Выберите файл", QDir::currentPath());
  ui->openGLWidget->loadModel(filePath);
  ui->infoLabel->setText(
      "name: " + filePath.section('/', -1) + "\nPoints count: " +
      QString::number(ui->openGLWidget->getVerticesCount()) +
      "\tFacets count: " + QString::number(ui->openGLWidget->getFacetsCount()));
  // GL
}

void MainWindow::on_Button_turnMinusOX_clicked() {
  ui->openGLWidget->turnModel(-15, 0, 0);
}

void MainWindow::on_Button_turnMinusOY_clicked() {
  ui->openGLWidget->turnModel(0, -15, 0);
}

void MainWindow::on_Button_turnMinusOZ_clicked() {
  ui->openGLWidget->turnModel(0, 0, -15);
}

void MainWindow::on_Button_turnPlusOX_clicked() {
  // turn(&_p, 15, 0, 0);
  ui->openGLWidget->turnModel(15, 0, 0);
}

void MainWindow::on_Button_turnPlusOY_clicked() {
  // turn(&_p, 0, 15, 0);
  ui->openGLWidget->turnModel(0, 15, 0);
}

void MainWindow::on_Button_turnPlusOZ_clicked() {
  // turn(&_p, 0, 0, 15);
  ui->openGLWidget->turnModel(0, 0, 15);
}

void MainWindow::on_Button_settings_Flustrum_clicked() {
  ui->openGLWidget->changeViewMode(Flustrum);
}

void MainWindow::on_Button_settings_Normal_clicked() {
  ui->openGLWidget->changeViewMode(Normal);
}

void MainWindow::on_Button_settings_StippleLines_clicked() {
  ui->openGLWidget->changeFacetMode(Stipple);
}

void MainWindow::on_Button_settings_SolidLines_clicked() {
  ui->openGLWidget->changeFacetMode(Solid);
}

void MainWindow::on_Button_settings_FacetsColor_clicked() {
  QColor newcolor = QColorDialog::getColor(ui->openGLWidget->FacetColor, this,
                                           tr("Select facets color"));
  if (newcolor.isValid()) {
    ui->openGLWidget->setFacetColor(newcolor);
  }
}

void MainWindow::on_Button_settings_FacetsThickness_clicked() {
  double th =
      QInputDialog::getDouble(this, "Thickness", "Set thickness",
                              ui->openGLWidget->getFacetsThickness(), 0, 20);
  ui->openGLWidget->setFacetThickness(th);
}

void MainWindow::on_Button_settings_Dots_SquareMode_clicked() {
  ui->openGLWidget->setDotsViewMode(Square);
}

void MainWindow::on_Button_settings_Dots_Circlemode_clicked() {
  ui->openGLWidget->setDotsViewMode(Circle);
}

void MainWindow::on_Button_settings_Dots_VoidMode_clicked() {
  ui->openGLWidget->setDotsViewMode(Void);
}

void MainWindow::on_Button_settings_DotsSize_clicked() {
  float size = QInputDialog::getInt(this, "Dots size", "Set dots size",
                                    ui->openGLWidget->getPointsSize(), 1, 100);
  ui->openGLWidget->setDotsSize(size);
}

void MainWindow::on_Button_settings_DotsColor_clicked() {
  QColor newcolor = QColorDialog::getColor(ui->openGLWidget->DotsColor, this,
                                           tr("Select dots color"));
  if (newcolor.isValid()) {
    ui->openGLWidget->setDotsColor(newcolor);
  }
}

void MainWindow::on_Button_settings_BGColor_clicked() {
  QColor newcolor = QColorDialog::getColor(ui->openGLWidget->DotsColor, this,
                                           tr("Select dots color"));
  if (newcolor.isValid()) {
    ui->openGLWidget->setBGColor(newcolor);
  }
}

void MainWindow::on_Button_MakeScreenshot_clicked() {
  QImage screen = ui->openGLWidget->grabFramebuffer();
  QString filter = "JPEG Files (*.jpg, *.jpeg);;BMP Files (*.bmp)";
  QString fileName =
      QFileDialog::getSaveFileName(this, tr("Save screenshot"), "", filter);

  if (!fileName.isEmpty()) {
    QFileInfo info(fileName);
    QString ext = info.suffix().toLower();
    if (ext.isEmpty() || !(ext == "bmp" || ext == "jpg" || ext == "jpeg"))
      fileName += ".jpeg";
    screen.save(fileName);
  }
}

void MainWindow::on_Button_MakeGif_clicked() {
  ui->Button_MakeGif->setDisabled(true);
  screenTimer = new QTimer(this);
  screenCount = 0;
  gif = new QGifImage;
  connect(screenTimer, &QTimer::timeout, this, &MainWindow::stopRecord);
  screenTimer->start(10);
}

void MainWindow::stopRecord() {
  screenCount++;
  screenFrame =
      ui->openGLWidget->grabFramebuffer().scaled(640, 480, Qt::KeepAspectRatio);
  ui->openGLWidget->turnModel(0, 15, 0);
  gif->addFrame(screenFrame, 100);
  if (screenCount >= 30) {
    screenTimer->stop();
    QString filename =
        QFileDialog::getSaveFileName(this, NULL, NULL, "GIF (*.gif)");
    if (!filename.isEmpty()) {
      QFileInfo info(filename);
      QString ext = info.suffix().toLower();
      if (ext.isEmpty() || !(ext == "gif")) {
        qDebug() << "Was here, all shoul be cool " << ext;
        filename += ".gif";
      } else {
        qDebug() << "Was here, shit happends " << ext;
      }
      gif->save(filename);
      ui->Button_MakeGif->setEnabled(true);
    }
  }
}

void MainWindow::on_Button_settings_Reset_clicked() {
  ui->openGLWidget->resetSettings();
}
