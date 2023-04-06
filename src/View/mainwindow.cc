#include "mainwindow.h"

namespace s21 {
MainWindow::MainWindow(QWidget* parent)
    : QOpenGLWidget(parent), ui_(new Ui::MainWindow) {
  value_ = 0.0;
  xRot_ = yRot_ = zRot_ = 0.0;
  lastPosX_ = lastPosY_ = 0.0;
  numberFps_ = 0;

  ui_->setupUi(this);
  settings_ = new QSettings(this);
  LoadSettings();
  gifTmr_ = new QTimer(0);
  connect(gifTmr_, SIGNAL(timeout()), this, SLOT(GifCreator()));
}

MainWindow::~MainWindow() {
  delete gifTmr_;
  controller_.Remove();
  delete ui_;
}

void MainWindow::initializeGL() {
  SetupPerspective();
  glEnable(GL_DEPTH_TEST);
}

void MainWindow::resizeGL(int w, int h) {
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
}

void MainWindow::paintGL() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  SetupPerspective();
  glRotatef(xRot_, 1, 0, 0);
  glRotatef(yRot_, 0, 1, 0);
  Draw();
}

void MainWindow::on_pushButton_select_name_clicked() {
  file_ =
      QFileDialog::getOpenFileName(this, "Select File", "", QString("*.obj"));
  if (file_ != "") {
    this->setWindowTitle(file_);
    InitFile(file_.toStdString());
    update();
  }
}

void MainWindow::InitFile(std::string path) {
  controller_.Parse(path);
  maxCoord_ = controller_.getMaxCoordinate() * 1.5;
  ui_->label_info_v->setNum(int(controller_.getCountVertexes()));
  ui_->label_info_e->setNum(int(controller_.getCountEdges()));
  ui_->label_info_p->setNum(int(controller_.getCountPolygons()));
  update();
}

void MainWindow::on_pushButton_reset_clicked() {
  controller_.Remove();
  xRot_ = 0;
  yRot_ = 0;
  InitFile(file_.toStdString());
  update();
}

void MainWindow::mousePressEvent(QMouseEvent* mo) {
  mPos_ = mo->pos();
  lastPosX_ = mPos_.x();
  lastPosY_ = mPos_.y();
}

void MainWindow::mouseMoveEvent(QMouseEvent* mo) {
  if (mo->pos().x() > lastPosX_) {
    yRot_ += 2;
  } else if (mo->pos().x() < lastPosX_) {
    yRot_ -= 2;
  }
  if (mo->pos().y() > lastPosY_) {
    xRot_ += 2;
  } else if (mo->pos().y() < lastPosY_) {
    xRot_ -= 2;
  }
  lastPosX_ = mo->pos().x();
  lastPosY_ = mo->pos().y();
  update();
}

void MainWindow::SetupPerspective() {
  GLdouble zNear = 0.001;
  GLdouble zFar = (maxCoord_ + 5) * 5;

  if (ui_->projection_type->currentIndex() == 1) {
    GLdouble fovY = 90;
    GLdouble fH = tan(fovY / 360 * M_PI) * zNear;
    GLdouble fW = fH;

    glFrustum(-fW, fW, -fH, fH, zNear, zFar);
    glTranslatef(0, 0, -maxCoord_);
  } else {
    glOrtho(-maxCoord_, maxCoord_, -maxCoord_, maxCoord_, -maxCoord_, zFar);
    glTranslated(0, 0, -3);
  }
}

void MainWindow::Draw() {
  glVertexPointer(3, GL_DOUBLE, 0, controller_.getVertexes().data());
  glEnableClientState(GL_VERTEX_ARRAY);
  glClearColor(bgrClrR_, bgrClrG_, bgrClrB_, 0.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // Draw edges
  glLineWidth(0.1);
  glColor3f(edgClrR_, edgClrG_, edgClrB_);
  if (ui_->radioButton_line->isChecked()) {
    glDisable(GL_LINE_STIPPLE);
  } else if (ui_->radioButton_stipple->isChecked()) {
    glLineStipple(10, 0x3333);
    glEnable(GL_LINE_STIPPLE);
  }
  glLineWidth(ui_->spinBox_edges_size->value());
  glDrawElements(GL_LINES, int(controller_.getFacets().size()), GL_UNSIGNED_INT,
                 controller_.getFacets().data());
  glDisableClientState(GL_VERTEX_ARRAY);

  // Draw vertexes
  glLineWidth(0.1);
  if (ui_->radioButton_norm->isChecked()) {
  } else {
    glEnableClientState(GL_VERTEX_ARRAY);
    glColor3f(vertClrR_, vertClrG_, vertClrB_);

    if (ui_->radioButton_circles->isChecked()) {
      glEnable(GL_POINT_SMOOTH);
      glDrawArrays(GL_POINTS, 0, controller_.getCountVertexes());
      glDisable(GL_POINT_SMOOTH);
    } else if (ui_->radioButton_quads->isChecked()) {
      glDrawArrays(GL_POINTS, 0, controller_.getCountVertexes());
    }

    glDisable(GL_POINT_SMOOTH);

    glPointSize(ui_->spinBox_vertexes_size->value());

    glDisableClientState(GL_VERTEX_ARRAY);
  }
  update();
}

void MainWindow::on_projection_type_activated() { update(); }

void MainWindow::on_spinBox_vertexes_size_valueChanged() { update(); }

void MainWindow::on_spinBox_edges_size_valueChanged() { update(); }

void MainWindow::on_pushButton_save_settings_clicked() { SaveSettings(); }

void MainWindow::wheelEvent(QWheelEvent* event) {
  controller_.Scale(event->angleDelta().y(), kScaleMouseAll);
  update();
}

void MainWindow::on_verticalScrollBar_valueChanged(int value) {
  qValue_ = value;
}

void MainWindow::on_verticalScrollBar_sliderReleased() {
  controller_.Scale(qValue_, kScaleScrollAll);
  ui_->verticalScrollBar->setValue(0);
  update();
}

// Color
void MainWindow::SetColor(double value, void (MainWindow::*setFunc)(double),
                          QSpinBox* spinBox) {
  (this->*setFunc)(value / 100.0);
  spinBox->setValue(value);
  update();
}
void MainWindow::on_horizontalScrollBar_bgr_R_valueChanged(int value) {
  SetColor(value, &MainWindow::setBgrClrR, ui_->spinBox_bgr_R);
}
void MainWindow::on_horizontalScrollBar_bgr_G_valueChanged(int value) {
  SetColor(value, &MainWindow::setBgrClrG, ui_->spinBox_bgr_G);
}
void MainWindow::on_horizontalScrollBar_bgr_B_valueChanged(int value) {
  SetColor(value, &MainWindow::setBgrClrB, ui_->spinBox_bgr_B);
}
void MainWindow::on_horizontalScrollBar_edges_R_valueChanged(int value) {
  SetColor(value, &MainWindow::setEdgClrR, ui_->spinBox_edges_R);
}
void MainWindow::on_horizontalScrollBar_edges_G_valueChanged(int value) {
  SetColor(value, &MainWindow::setEdgClrG, ui_->spinBox_edges_G);
}
void MainWindow::on_horizontalScrollBar_edges_B_valueChanged(int value) {
  SetColor(value, &MainWindow::setEdgClrB, ui_->spinBox_edges_B);
}
void MainWindow::on_horizontalScrollBar_vertexes_R_valueChanged(int value) {
  SetColor(value, &MainWindow::setVertClrR, ui_->spinBox_vertexes_R);
}
void MainWindow::on_horizontalScrollBar_vertexes_G_valueChanged(int value) {
  SetColor(value, &MainWindow::setVertClrG, ui_->spinBox_vertexes_G);
}
void MainWindow::on_horizontalScrollBar_vertexes_B_valueChanged(int value) {
  SetColor(value, &MainWindow::setVertClrB, ui_->spinBox_vertexes_B);
}

// Scale
void MainWindow::on_pushButton_sc_x_plus_clicked() {
  controller_.Scale(ui_->doubleSpinBox_sc_value->value(), kScalePlusX);
  update();
}
void MainWindow::on_pushButton_sc_y_plus_clicked() {
  controller_.Scale(ui_->doubleSpinBox_sc_value->value(), kScalePlusY);
  update();
}
void MainWindow::on_pushButton_sc_z_plus_clicked() {
  controller_.Scale(ui_->doubleSpinBox_sc_value->value(), kScalePlusZ);
  update();
}
void MainWindow::on_pushButton_sc_x_minus_clicked() {
  controller_.Scale(ui_->doubleSpinBox_sc_value->value(), kScaleMinusX);
  update();
}
void MainWindow::on_pushButton_sc_y_minus_clicked() {
  controller_.Scale(ui_->doubleSpinBox_sc_value->value(), kScaleMinusY);
  update();
}
void MainWindow::on_pushButton_sc_z_minus_clicked() {
  controller_.Scale(ui_->doubleSpinBox_sc_value->value(), kScaleMinusZ);
  update();
}

// Rotate
void MainWindow::on_horizontalScrollBar_rot_x_valueChanged(int value) {
  value_ = value;
}
void MainWindow::on_horizontalScrollBar_rot_x_sliderReleased() {
  controller_.Transform(value_, kRotSliderX);
  ui_->horizontalScrollBar_rot_x->setValue(0);
  update();
}
void MainWindow::on_horizontalScrollBar_rot_y_valueChanged(int value) {
  value_ = value;
}
void MainWindow::on_horizontalScrollBar_rot_y_sliderReleased() {
  controller_.Transform(value_, kRotSliderY);
  ui_->horizontalScrollBar_rot_y->setValue(0);
  update();
}
void MainWindow::on_horizontalScrollBar_rot_z_valueChanged(int value) {
  value_ = value;
}
void MainWindow::on_horizontalScrollBar_rot_z_sliderReleased() {
  controller_.Transform(value_, kRotSliderZ);
  ui_->horizontalScrollBar_rot_z->setValue(0);
  update();
}

// Move
void MainWindow::on_pushButton_mv_x_plus_clicked() {
  controller_.Move(ui_->doubleSpinBox_mv_value->value(), kMovePlusX);
  update();
}
void MainWindow::on_pushButton_mv_x_minus_clicked() {
  controller_.Move(ui_->doubleSpinBox_mv_value->value(), kMoveMinusX);
  update();
}
void MainWindow::on_pushButton_mv_y_plus_clicked() {
  controller_.Move(ui_->doubleSpinBox_mv_value->value(), kMovePlusY);
  update();
}
void MainWindow::on_pushButton_mv_y_minus_clicked() {
  controller_.Move(ui_->doubleSpinBox_mv_value->value(), kMoveMinusY);
  update();
}
void MainWindow::on_pushButton_mv_z_plus_clicked() {
  controller_.Move(ui_->doubleSpinBox_mv_value->value(), kMovePlusZ);
  update();
}
void MainWindow::on_pushButton_mv_z_minus_clicked() {
  controller_.Move(ui_->doubleSpinBox_mv_value->value(), kMoveMinusZ);
  update();
}

void MainWindow::on_pushButton_screenshot_clicked() {
  QFileDialog file_dialog_img(this);
  QString f_name = file_dialog_img.getSaveFileName(
      this, tr("Save a screenshot"), ".jpeg", tr("image (*.bmp *.jpeg)"));
  QImage img = grabFramebuffer();
  img.save(f_name);
}

void MainWindow::on_pushButton_gif_clicked() {
  gifFileName_ = QFileDialog::getSaveFileName(this, tr("Save GIF"), ".gif",
                                              tr("Gif Files (*.gif)"));
  if (gifFileName_ != "") {
    ui_->pushButton_gif->setDisabled(true);
    gifImg_ = new QGifImage;
    gifImg_->setDefaultDelay(10);
    GifTimer();
  } else {
    ShowMessage("Нет папки");
  }
}

void MainWindow::GifTimer() {
  gifTmr_->setInterval(100);
  gifTmr_->start();
}

void MainWindow::ShowMessage(QString message) {
  QMessageBox messageBox;
  messageBox.setFixedSize(500, 200);
  messageBox.information(0, "Info", message);
}

void MainWindow::GifCreator() {
  QImage image_ = grabFramebuffer();
  gifImg_->addFrame(image_);
  if (numberFps_ == 50) {
    gifTmr_->stop();
    gifImg_->save(gifFileName_);
    numberFps_ = 0;
    ShowMessage("Gif saved.");
    delete gifImg_;
    ui_->pushButton_gif->setText("Gif");
    ui_->pushButton_gif->setEnabled(true);
  }
  ++numberFps_;
  if (!ui_->pushButton_gif->isEnabled()) {
    ui_->pushButton_gif->setText(QString::number(numberFps_ / 10));
  }
}

void MainWindow::SaveSettings() {
  settings_->setValue("projection_type", ui_->projection_type->currentIndex());
  settings_->setValue("edges_type_line", ui_->radioButton_line->isChecked());
  settings_->setValue("edges_type_stipple",
                      ui_->radioButton_stipple->isChecked());

  settings_->setValue("radioButton_norm", ui_->radioButton_norm->isChecked());
  settings_->setValue("radioButton_circles",
                      ui_->radioButton_circles->isChecked());
  settings_->setValue("radioButton_quads", ui_->radioButton_quads->isChecked());

  settings_->setValue("edges_size", ui_->spinBox_edges_size->value());
  settings_->setValue("vertexes_size", ui_->spinBox_vertexes_size->value());

  settings_->setValue("horizontalScrollBar_bgr_R",
                      ui_->horizontalScrollBar_bgr_R->value());
  settings_->setValue("horizontalScrollBar_bgr_G",
                      ui_->horizontalScrollBar_bgr_G->value());
  settings_->setValue("horizontalScrollBar_bgr_B",
                      ui_->horizontalScrollBar_bgr_B->value());

  settings_->setValue("horizontalScrollBar_edges_R",
                      ui_->horizontalScrollBar_edges_R->value());
  settings_->setValue("horizontalScrollBar_edges_G",
                      ui_->horizontalScrollBar_edges_G->value());
  settings_->setValue("horizontalScrollBar_edges_B",
                      ui_->horizontalScrollBar_edges_B->value());

  settings_->setValue("horizontalScrollBar_vertexes_R",
                      ui_->horizontalScrollBar_vertexes_R->value());
  settings_->setValue("horizontalScrollBar_vertexes_G",
                      ui_->horizontalScrollBar_vertexes_G->value());
  settings_->setValue("horizontalScrollBar_vertexes_B",
                      ui_->horizontalScrollBar_vertexes_B->value());
}

void MainWindow::LoadSettings() {
  ui_->projection_type->setCurrentIndex(
      settings_->value("projection_type", "0").toInt());
  ui_->radioButton_line->setChecked(
      settings_->value("edges_type_line", true).toBool());
  ui_->radioButton_stipple->setChecked(
      settings_->value("edges_type_stipple", true).toBool());

  ui_->radioButton_norm->setChecked(
      settings_->value("radioButton_norm", true).toBool());
  ui_->radioButton_circles->setChecked(
      settings_->value("radioButton_circles", true).toBool());
  ui_->radioButton_quads->setChecked(
      settings_->value("radioButton_quads", true).toBool());

  ui_->spinBox_edges_size->setValue(
      settings_->value("edges_size", "1").toInt());
  ui_->spinBox_vertexes_size->setValue(
      settings_->value("vertexes_size", "10").toInt());

  // back color
  ui_->horizontalScrollBar_bgr_R->setValue(
      settings_->value("horizontalScrollBar_bgr_R").toInt());
  ui_->horizontalScrollBar_bgr_G->setValue(
      settings_->value("horizontalScrollBar_bgr_G").toInt());
  ui_->horizontalScrollBar_bgr_B->setValue(
      settings_->value("horizontalScrollBar_bgr_B").toInt());

  ui_->horizontalScrollBar_edges_R->setValue(
      settings_->value("horizontalScrollBar_edges_R").toInt());
  ui_->horizontalScrollBar_edges_G->setValue(
      settings_->value("horizontalScrollBar_edges_G").toInt());
  ui_->horizontalScrollBar_edges_B->setValue(
      settings_->value("horizontalScrollBar_edges_B").toInt());

  ui_->horizontalScrollBar_vertexes_R->setValue(
      settings_->value("horizontalScrollBar_vertexes_R").toInt());
  ui_->horizontalScrollBar_vertexes_G->setValue(
      settings_->value("horizontalScrollBar_vertexes_G").toInt());
  ui_->horizontalScrollBar_vertexes_B->setValue(
      settings_->value("horizontalScrollBar_vertexes_B").toInt());
}

// s21::Controller& MainWindow::getController() { return controller_; } // TODO
// delete Ui::MainWindow* MainWindow::getUi() { return ui_; } // TODO delete

int MainWindow::getValue() const { return value_; }

double MainWindow::getRotValueX() const { return rotValueX_; }
double MainWindow::getRotValueY() const { return rotValueY_; }
double MainWindow::getRotValueZ() const { return rotValueZ_; }

double MainWindow::getBgrClrR() const { return bgrClrR_; }
double MainWindow::getBgrClrG() const { return bgrClrG_; }
double MainWindow::getBgrClrB() const { return bgrClrB_; }

double MainWindow::getEdgClrR() const { return edgClrR_; }
double MainWindow::getEdgClrG() const { return edgClrG_; }
double MainWindow::getEdgClrB() const { return edgClrB_; }

void MainWindow::setRotValueX(double rotValueX) { rotValueX_ = rotValueX; }
void MainWindow::setRotValueY(double rotValueY) { rotValueY_ = rotValueY; }
void MainWindow::setRotValueZ(double rotValueZ) { rotValueZ_ = rotValueZ; }

void MainWindow::setBgrClrR(double bgrClrR) { bgrClrR_ = bgrClrR; }
void MainWindow::setBgrClrG(double bgrClrG) { bgrClrG_ = bgrClrG; }
void MainWindow::setBgrClrB(double bgrClrB) { bgrClrB_ = bgrClrB; }

void MainWindow::setEdgClrR(double edgClrR) { edgClrR_ = edgClrR; }
void MainWindow::setEdgClrG(double edgClrG) { edgClrG_ = edgClrG; }
void MainWindow::setEdgClrB(double edgClrB) { edgClrB_ = edgClrB; }

void MainWindow::setVertClrR(double vertClrR) { vertClrR_ = vertClrR; }
void MainWindow::setVertClrG(double vertClrG) { vertClrG_ = vertClrG; }
void MainWindow::setVertClrB(double vertClrB) { vertClrB_ = vertClrB; }
}  // namespace s21
