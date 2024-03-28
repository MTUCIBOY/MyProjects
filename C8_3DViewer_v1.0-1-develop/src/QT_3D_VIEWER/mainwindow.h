#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QColorDialog>
#include <QDebug>
#include <QFileDialog>
#include <QInputDialog>
#include <QMainWindow>
#include <QProcess>
#include <QTimer>

#include "3rdparty/gifimage/qgifimage.h"

extern "C" {
#include "../Back/main.h"
}

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

/*!\brief GUI class*/
class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  /*!\brief Left move button*/
  void on_Button_left_clicked();

  /*!\brief Up move button*/
  void on_Button_up_clicked();

  /*!\brief Down move button*/
  void on_Button_down_clicked();

  /*!\brief Right move button*/
  void on_Button_right_clicked();

  /*!\brief In move button*/
  void on_Button_in_clicked();

  /*!\brief Out move button*/
  void on_Button_out_clicked();

  /*!\brief Zoom in button*/
  void on_Button_zoomIn_clicked();

  /*!\brief Zoom out button*/
  void on_Button_zoomOut_clicked();

  /*!\brief Open file button*/
  void on_Button_filename_clicked();

  /*!\brief Rotate -OX button*/
  void on_Button_turnMinusOX_clicked();

  /*!\brief Rotate -OY button*/
  void on_Button_turnMinusOY_clicked();

  /*!\brief Rotate -OZ button*/
  void on_Button_turnMinusOZ_clicked();

  /*!\brief Rotate +OX button*/
  void on_Button_turnPlusOX_clicked();

  /*!\brief Rotate +OY button*/
  void on_Button_turnPlusOY_clicked();

  /*!\brief Rotate +OZ button*/
  void on_Button_turnPlusOZ_clicked();

  /*!\brief Change perspective button*/
  void on_Button_settings_Flustrum_clicked();

  /*!\brief Change perspective button*/
  void on_Button_settings_Normal_clicked();

  /*!\brief Change setting lines button*/
  void on_Button_settings_StippleLines_clicked();

  /*!\brief Change setting lines button*/
  void on_Button_settings_SolidLines_clicked();

  /*!\brief Change facets color button*/
  void on_Button_settings_FacetsColor_clicked();

  /*!\brief Change facets thickness button*/
  void on_Button_settings_FacetsThickness_clicked();

  /*!\brief Change dots mode button*/
  void on_Button_settings_Dots_SquareMode_clicked();

  /*!\brief Change dots mode button*/
  void on_Button_settings_Dots_Circlemode_clicked();

  /*!\brief Change dots mode button*/
  void on_Button_settings_Dots_VoidMode_clicked();

  /*!\brief Change dots size button*/
  void on_Button_settings_DotsSize_clicked();

  /*!\brief Change dots color button*/
  void on_Button_settings_DotsColor_clicked();

  /*!\brief Change background color button*/
  void on_Button_settings_BGColor_clicked();

  /*!\brief Make screenshoot button*/
  void on_Button_MakeScreenshot_clicked();

  /*!\brief Make gif button*/
  void on_Button_MakeGif_clicked();

  /*!\brief Reset button*/
  void on_Button_settings_Reset_clicked();

 private:
  Ui::MainWindow *ui;

  QTimer *screenTimer;
  int screenCount;
  QImage screenFrame;
  QGifImage *gif;

  bool pressed;
  bool leftButton;
  QPoint startPos;
  QPoint newPos;

  void stopRecord();
};
#endif  // MAINWINDOW_H
