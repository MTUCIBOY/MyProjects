#include "Calculator.h"

Calc::Calc(QApplication* app) {
  p_app = app;

  btn_clear->setStyleSheet("background-color: red");
  btn_equal->setStyleSheet("background-color: orange");

  btn_plus->setStyleSheet("background-color: lightblue");
  btn_minus->setStyleSheet("background-color: lightblue");
  btn_mult->setStyleSheet("background-color: lightblue");
  btn_div->setStyleSheet("background-color: lightblue");
  btn_pow->setStyleSheet("background-color: lightblue");
  btn_mod->setStyleSheet("background-color: lightblue");
  btn_l_brack->setStyleSheet("background-color: lightblue");
  btn_r_brack->setStyleSheet("background-color: lightblue");
  btn_dot->setStyleSheet("background-color: lightblue");

  btn_sin->setStyleSheet("background-color: blue");
  btn_cos->setStyleSheet("background-color: blue");
  btn_tan->setStyleSheet("background-color: blue");
  btn_acos->setStyleSheet("background-color: blue");
  btn_asin->setStyleSheet("background-color: blue");
  btn_atan->setStyleSheet("background-color: blue");
  btn_ln->setStyleSheet("background-color: blue");
  btn_log->setStyleSheet("background-color: blue");
  btn_sqrt->setStyleSheet("background-color: blue");
  btn_quit->setStyleSheet("background-color: lightgreen");

  btn_x->setStyleSheet("background-color: purple");
  btn_plot->setStyleSheet("background-color: purple");
  spinBoxSetX->setStyleSheet("background-color: purple");

  display->setStyleSheet("font: 18px");
  display->setMaxLength(255);
  display->setFixedHeight(30);
  display->setAlignment(Qt::AlignRight);

  button_layout->setRowMinimumHeight(0, 35);
  button_layout->addWidget(display, 0, 0, 1, 5);

  button_layout->addWidget(btn_plus, 1, 0);
  button_layout->addWidget(btn_minus, 1, 1);
  button_layout->addWidget(btn_mult, 1, 2);
  button_layout->addWidget(btn_div, 1, 3);
  button_layout->addWidget(btn_clear, 1, 4);

  button_layout->addWidget(btn_tan, 2, 0);
  button_layout->addWidget(btn_sin, 2, 1);
  button_layout->addWidget(btn_cos, 2, 2);
  button_layout->addWidget(btn_sqrt, 2, 3);
  button_layout->addWidget(btn_ln, 2, 4);

  button_layout->addWidget(btn_asin, 3, 0);
  button_layout->addWidget(btn_acos, 3, 1);
  button_layout->addWidget(btn_atan, 3, 2);
  button_layout->addWidget(btn_log, 3, 3);
  button_layout->addWidget(btn_x, 3, 4);

  button_layout->addWidget(btn_1, 4, 0);
  button_layout->addWidget(btn_2, 4, 1);
  button_layout->addWidget(btn_3, 4, 2);
  button_layout->addWidget(btn_pow, 4, 3);
  button_layout->addWidget(spinBoxSetX, 4, 4);

  button_layout->addWidget(btn_4, 5, 0);
  button_layout->addWidget(btn_5, 5, 1);
  button_layout->addWidget(btn_6, 5, 2);
  button_layout->addWidget(btn_mod, 5, 3);
  button_layout->addWidget(btn_plot, 5, 4);

  button_layout->addWidget(btn_7, 6, 0);
  button_layout->addWidget(btn_8, 6, 1);
  button_layout->addWidget(btn_9, 6, 2);
  button_layout->addWidget(btn_r_brack, 6, 3);
  button_layout->addWidget(btn_equal, 6, 4);

  button_layout->addWidget(btn_0, 7, 0, 1, 2);
  button_layout->addWidget(btn_dot, 7, 2);
  button_layout->addWidget(btn_l_brack, 7, 3);
  button_layout->addWidget(btn_quit, 7, 4);

  button_layout->addWidget(boxLabel_Xmax, 8, 0);
  button_layout->addWidget(boxLabel_Xmin, 8, 1);

  button_layout->addWidget(boxLabel_Ymax, 8, 2);
  button_layout->addWidget(boxLabel_Ymin, 8, 3);

  button_layout->addWidget(spinBoxXmax, 9, 0);
  button_layout->addWidget(spinBoxXmin, 9, 1);

  button_layout->addWidget(spinBoxYmax, 9, 2);
  button_layout->addWidget(spinBoxYmin, 9, 3);

  spinBoxSetX->setRange(-1000000, 1000000);

  spinBoxXmax->setRange(-1000000, 1000000);
  spinBoxXmin->setRange(-1000000, 1000000);

  spinBoxYmax->setRange(-1000000, 1000000);
  spinBoxYmin->setRange(-1000000, 1000000);

  spinBoxXmax->setValue(10);
  spinBoxXmin->setValue(-10);

  spinBoxYmax->setValue(10);
  spinBoxYmin->setValue(-10);

  button_layout->setRowMinimumHeight(10, 400);
  button_layout->addWidget(custom_plot, 10, 0, 1, 5);

  this->setLayout(button_layout);
  buttonConnect();
}

void Calc::buttonConnect() {
  connect(btn_quit, SIGNAL(clicked()), p_app, SLOT(quit()));

  connect(calc_mapper, SIGNAL(mappedString(const QString&)), this,
          SLOT(getButtonClicked(const QString&)));

  connect(this, SIGNAL(sendExp(const QString&)), display,
          SLOT(setText(const QString&)));

  connect(btn_0, SIGNAL(clicked()), calc_mapper, SLOT(map()));
  calc_mapper->setMapping(btn_0, "0");

  connect(btn_1, SIGNAL(clicked()), calc_mapper, SLOT(map()));
  calc_mapper->setMapping(btn_1, "1");

  connect(btn_2, SIGNAL(clicked()), calc_mapper, SLOT(map()));
  calc_mapper->setMapping(btn_2, "2");

  connect(btn_3, SIGNAL(clicked()), calc_mapper, SLOT(map()));
  calc_mapper->setMapping(btn_3, "3");

  connect(btn_4, SIGNAL(clicked()), calc_mapper, SLOT(map()));
  calc_mapper->setMapping(btn_4, "4");

  connect(btn_5, SIGNAL(clicked()), calc_mapper, SLOT(map()));
  calc_mapper->setMapping(btn_5, "5");

  connect(btn_6, SIGNAL(clicked()), calc_mapper, SLOT(map()));
  calc_mapper->setMapping(btn_6, "6");

  connect(btn_7, SIGNAL(clicked()), calc_mapper, SLOT(map()));
  calc_mapper->setMapping(btn_7, "7");

  connect(btn_8, SIGNAL(clicked()), calc_mapper, SLOT(map()));
  calc_mapper->setMapping(btn_8, "8");

  connect(btn_9, SIGNAL(clicked()), calc_mapper, SLOT(map()));
  calc_mapper->setMapping(btn_9, "9");

  connect(btn_sqrt, SIGNAL(clicked()), calc_mapper, SLOT(map()));
  calc_mapper->setMapping(btn_sqrt, "sqrt(");

  connect(btn_sin, SIGNAL(clicked()), calc_mapper, SLOT(map()));
  calc_mapper->setMapping(btn_sin, "sin(");

  connect(btn_cos, SIGNAL(clicked()), calc_mapper, SLOT(map()));
  calc_mapper->setMapping(btn_cos, "cos(");

  connect(btn_tan, SIGNAL(clicked()), calc_mapper, SLOT(map()));
  calc_mapper->setMapping(btn_tan, "tan(");

  connect(btn_log, SIGNAL(clicked()), calc_mapper, SLOT(map()));
  calc_mapper->setMapping(btn_log, "log(");

  connect(btn_ln, SIGNAL(clicked()), calc_mapper, SLOT(map()));
  calc_mapper->setMapping(btn_ln, "ln(");

  connect(btn_plus, SIGNAL(clicked()), calc_mapper, SLOT(map()));
  calc_mapper->setMapping(btn_plus, "+");

  connect(btn_minus, SIGNAL(clicked()), calc_mapper, SLOT(map()));
  calc_mapper->setMapping(btn_minus, "-");

  connect(btn_mult, SIGNAL(clicked()), calc_mapper, SLOT(map()));
  calc_mapper->setMapping(btn_mult, "*");

  connect(btn_div, SIGNAL(clicked()), calc_mapper, SLOT(map()));
  calc_mapper->setMapping(btn_div, "/");

  connect(btn_asin, SIGNAL(clicked()), calc_mapper, SLOT(map()));
  calc_mapper->setMapping(btn_asin, "asin(");

  connect(btn_acos, SIGNAL(clicked()), calc_mapper, SLOT(map()));
  calc_mapper->setMapping(btn_acos, "acos(");

  connect(btn_atan, SIGNAL(clicked()), calc_mapper, SLOT(map()));
  calc_mapper->setMapping(btn_atan, "atan(");

  connect(btn_l_brack, SIGNAL(clicked()), calc_mapper, SLOT(map()));
  calc_mapper->setMapping(btn_l_brack, "(");

  connect(btn_r_brack, SIGNAL(clicked()), calc_mapper, SLOT(map()));
  calc_mapper->setMapping(btn_r_brack, ")");

  connect(btn_dot, SIGNAL(clicked()), calc_mapper, SLOT(map()));
  calc_mapper->setMapping(btn_dot, ".");

  connect(btn_mod, SIGNAL(clicked()), calc_mapper, SLOT(map()));
  calc_mapper->setMapping(btn_mod, "%");

  connect(btn_pow, SIGNAL(clicked()), calc_mapper, SLOT(map()));
  calc_mapper->setMapping(btn_pow, "^");

  connect(btn_x, SIGNAL(clicked()), calc_mapper, SLOT(map()));
  calc_mapper->setMapping(btn_x, "x");

  connect(btn_x, SIGNAL(clicked()), this, SLOT(setX()));
  connect(btn_plot, SIGNAL(clicked()), this, SLOT(setPlot()));

  connect(btn_clear, SIGNAL(clicked()), display, SLOT(clear()));
  connect(btn_clear, SIGNAL(clicked()), this, SLOT(clearStr()));
  connect(btn_equal, SIGNAL(clicked()), this, SLOT(equalProcessing()));
}
