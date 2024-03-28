

#include "glwidget.h"

glwidget::glwidget(QWidget *parent) : QOpenGLWidget(parent) {
  settings = new QSettings(ORGNAME, APPNAME, parent);
  /*    viewMode = Normal;
      facetsMode = Stipple;
      facetsThickness = 1.0;

      dotsViewMode = Circle;
      dotsSize = 10.0; */

  loadCube();
}

void glwidget::initializeGL() {
  initializeOpenGLFunctions();
  loadSettings();
  glEnable(GL_DEPTH_TEST);
}

void glwidget::paintGL() {
  glClearColor(BackgroundColor.redF(), BackgroundColor.greenF(),
               BackgroundColor.blueF(), 1);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glEnableClientState(GL_VERTEX_ARRAY);
  glLoadIdentity();

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  // glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
  glTranslatef(0, 0, 0);

  glScalef(5.0 / 10, 5.0 / 10, 5.0 / 10);
  if (viewMode == Flustrum) {
    glFrustum(-1, 1, -1, 1, 1, 1000);
  } else {
    glOrtho(-1, 1, -1, 1, -1, 1000);
  }

  /* QMatrix4x4 modelView;
   modelView.lookAt(QVector3D(2, 2, 2), QVector3D(1, 1, 1), QVector3D(-1, -1,
   -1)); glMatrixMode(GL_MODELVIEW); glLoadMatrixf(modelView.constData());
*/
  glMatrixMode(GL_PROJECTION);

  loadPoints();
  loadFacets();
}

void glwidget::loadPoints() {
  if (dotsViewMode == Void) return;
  if (dotsViewMode == Circle) {
    glEnable(GL_POINT_SMOOTH);
    glDisable(GL_QUADS);
  } else {
    glEnable(GL_QUADS);
    glDisable(GL_POINT_SMOOTH);
  }
  glVertexPointer(3, GL_DOUBLE, 0, _p->coordinates);
  glColor3f(DotsColor.redF(), DotsColor.greenF(), DotsColor.blueF());
  glPointSize(dotsSize);
  glDrawArrays(GL_POINTS, 0, _p->quantity);
}
void glwidget::loadFacets() {
  if (facetsMode == Stipple) {
    glLineStipple(1, 0x00FF);
    glEnable(GL_LINE_STIPPLE);
  } else {
    glDisable(GL_LINE_STIPPLE);
  }
  glLineWidth(facetsThickness);
  glColor3f(FacetColor.redF(), FacetColor.greenF(), FacetColor.blueF());
  glDrawElements(GL_LINES, _f->quantity, GL_UNSIGNED_INT, _f->facet_matrix);
}

glwidget::~glwidget() {
  makeClean();
  saveSettings();
  delete settings;
}

void glwidget::moveModel(double x, double y, double z) {
  MovePoints(_p, x, y, z);
  update();
}

void glwidget::turnModel(double x, double y, double z) {
  turn(_p, x, y, z);
  update();
}

void glwidget::zoomModel(double z) {
  zoom(_p, z);
  update();
}

int glwidget::getVerticesCount() { return _p->quantity; }

int glwidget::getFacetsCount() { return _f->quantity; }

void glwidget::loadModel(QString filename) {
  makeClean();
  parser(filename.toLocal8Bit().data(), &_p, &_f);
  CenterAndScaleCoords(_p);
  update();
}

void glwidget::changeViewMode(int viewMode) {
  if (viewMode == Flustrum && viewMode != this->viewMode) {
    moveModel(0, 0, -2);
  } else if (viewMode == Normal && viewMode != this->viewMode) {
    moveModel(0, 0, 2);
  } else {
    return;
  }
  this->viewMode = viewMode;
  update();
}

void glwidget::changeFacetMode(int lineMode) {
  if (lineMode != this->facetsMode) {
    this->facetsMode = lineMode;
    update();
  }
}

void glwidget::setFacetColor(QColor color) {
  FacetColor = color;
  update();
}

void glwidget::setFacetThickness(double thickness) {
  facetsThickness = thickness;
  update();
}

void glwidget::setDotsViewMode(int mode) {
  dotsViewMode = mode;
  update();
}

double glwidget::getFacetsThickness() { return facetsThickness; }
double glwidget::getPointsSize() { return dotsSize; }

void glwidget::setDotsSize(double size) {
  dotsSize = size;
  update();
}

void glwidget::setDotsColor(QColor color) {
  DotsColor = color;
  update();
}

void glwidget::setBGColor(QColor color) {
  BackgroundColor = color;
  update();
}

void glwidget::loadCube() {
  _p = (Points *)malloc(sizeof(Points));
  _p->quantity = 8;
  _p->coordinates = (dot *)malloc(sizeof(dot) * _p->quantity);
  _p->coordinates[0] = {0, 0, 0};
  _p->coordinates[1] = {0, 0, 1};
  _p->coordinates[2] = {0, 1, 0};
  _p->coordinates[3] = {0, 1, 1};
  _p->coordinates[4] = {1, 0, 0};
  _p->coordinates[5] = {1, 0, 1};
  _p->coordinates[6] = {1, 1, 0};
  _p->coordinates[7] = {1, 1, 1};
  //

  CenterAndScaleCoords(_p);
  _f = (Facets *)malloc(sizeof(Facets));
  _f->quantity = 24;
  _f->facet_matrix = (int *)malloc(sizeof(int) * _f->quantity);
  _f->facet_matrix[0] = 0;
  _f->facet_matrix[1] = 1;
  _f->facet_matrix[2] = 1;
  _f->facet_matrix[3] = 3;
  _f->facet_matrix[4] = 3;
  _f->facet_matrix[5] = 2;
  _f->facet_matrix[6] = 2;
  _f->facet_matrix[7] = 0;
  _f->facet_matrix[8] = 4;
  _f->facet_matrix[9] = 5;
  _f->facet_matrix[10] = 5;
  _f->facet_matrix[11] = 7;
  _f->facet_matrix[12] = 7;
  _f->facet_matrix[13] = 6;
  _f->facet_matrix[14] = 6;
  _f->facet_matrix[15] = 4;
  _f->facet_matrix[16] = 0;
  _f->facet_matrix[17] = 4;
  _f->facet_matrix[18] = 1;
  _f->facet_matrix[19] = 5;
  _f->facet_matrix[20] = 2;
  _f->facet_matrix[21] = 6;
  _f->facet_matrix[22] = 3;
  _f->facet_matrix[23] = 7;
}

void glwidget::saveSettings() {
  settings->setValue("ViewMode", viewMode);
  settings->setValue("BGColor", BackgroundColor);

  settings->setValue("FacetsMode", facetsMode);
  settings->setValue("FacetsThickness", facetsThickness);
  settings->setValue("FacetsColor", FacetColor);

  settings->setValue("DotsViewMode", dotsViewMode);
  settings->setValue("DotsSize", dotsSize);
  settings->setValue("DotsColor", DotsColor);
}

void glwidget::loadSettings() {
  int tviewMode = settings->value("ViewMode", Normal).toInt();
  if (tviewMode == Flustrum)
    changeViewMode(tviewMode);
  else
    viewMode = tviewMode;
  BackgroundColor =
      settings->value("BGColor", QColorConstants::Black).value<QColor>();

  facetsMode = settings->value("FacetsMode", Stipple).toInt();
  facetsThickness = settings->value("FacetsThickness", 1).toInt();
  FacetColor =
      settings->value("FacetsColor", QColorConstants::Blue).value<QColor>();

  dotsViewMode = settings->value("DotsViewMode", Circle).toInt();
  dotsSize = settings->value("DotsSize", 1).toInt();
  DotsColor =
      settings->value("DotsColor", QColorConstants::Green).value<QColor>();
}

void glwidget::resetSettings() {
  changeViewMode(Normal);
  BackgroundColor = QColorConstants::Black;

  facetsMode = Stipple;
  facetsThickness = 1;
  FacetColor = QColorConstants::Blue;

  dotsViewMode = Circle;
  dotsSize = 1;
  DotsColor = QColorConstants::Green;
  update();
}

void glwidget::makeClean() { clean_points_and_facets(&_p, &_f); }
