#ifndef CPP4_3DVIEWER_V2_0_3_SRC_VIEW_MAINWINDOW_H_
#define CPP4_3DVIEWER_V2_0_3_SRC_VIEW_MAINWINDOW_H_

#ifdef __APPLE__
/* Defined before OpenGL and GLUT includes to avoid deprecation messages */
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#include <GL/glut.h>
#endif

#include <qgroupbox.h>

#include <QFileDialog>
#include <QMessageBox>
#include <QMouseEvent>
#include <QOpenGLWidget>
#include <QSettings>
#include <QThread>
#include <QTimer>
#include <QWidget>
#include <QtConcurrent>

#include "../Controller/controller.h"
#include "qgifimage.h"
#include "ui_mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}

namespace s21 {

QT_END_NAMESPACE

class MainWindow : public QOpenGLWidget {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

  void InitFile(std::string stringpath);
  void Draw();
  void SetupPerspective();

  void mousePressEvent(QMouseEvent *) override;
  void mouseMoveEvent(QMouseEvent *) override;

  void initializeGL() override;
  void resizeGL(int w, int h) override;
  void paintGL() override;
  void wheelEvent(QWheelEvent *event) override;

  void SaveSettings();
  void LoadSettings();

  void setBgrClrR(double bgrClrR);
  void setBgrClrG(double bgrClrG);
  void setBgrClrB(double bgrClrB);

  void setEdgClrR(double edgClrR);
  void setEdgClrG(double edgClrG);
  void setEdgClrB(double edgClrB);

  void setVertClrR(double vertClrR);
  void setVertClrG(double vertClrG);
  void setVertClrB(double vertClrB);

 private slots:
  void GifCreator();
  void GifTimer();
  void ShowMessage(QString message);

  void on_projection_type_activated();
  void on_spinBox_vertexes_size_valueChanged();
  void on_spinBox_edges_size_valueChanged();
  void on_pushButton_select_name_clicked();
  void on_pushButton_save_settings_clicked();
  void on_pushButton_screenshot_clicked();
  void on_pushButton_gif_clicked();

  void on_horizontalScrollBar_bgr_R_valueChanged(int value);
  void on_horizontalScrollBar_bgr_G_valueChanged(int value);
  void on_horizontalScrollBar_bgr_B_valueChanged(int value);

  void on_horizontalScrollBar_edges_R_valueChanged(int value);
  void on_horizontalScrollBar_edges_G_valueChanged(int value);
  void on_horizontalScrollBar_edges_B_valueChanged(int value);

  void on_horizontalScrollBar_vertexes_R_valueChanged(int value);
  void on_horizontalScrollBar_vertexes_G_valueChanged(int value);
  void on_horizontalScrollBar_vertexes_B_valueChanged(int value);

  void on_pushButton_sc_x_plus_clicked();
  void on_pushButton_sc_y_plus_clicked();
  void on_pushButton_sc_z_plus_clicked();
  void on_pushButton_sc_x_minus_clicked();
  void on_pushButton_sc_y_minus_clicked();
  void on_pushButton_sc_z_minus_clicked();

  void on_pushButton_reset_clicked();

  void on_pushButton_mv_x_plus_clicked();
  void on_pushButton_mv_x_minus_clicked();
  void on_pushButton_mv_y_plus_clicked();
  void on_pushButton_mv_y_minus_clicked();
  void on_pushButton_mv_z_minus_clicked();
  void on_pushButton_mv_z_plus_clicked();

  void on_horizontalScrollBar_rot_x_valueChanged(int value);
  void on_horizontalScrollBar_rot_x_sliderReleased();
  void on_horizontalScrollBar_rot_y_valueChanged(int value);
  void on_horizontalScrollBar_rot_y_sliderReleased();
  void on_horizontalScrollBar_rot_z_valueChanged(int value);
  void on_horizontalScrollBar_rot_z_sliderReleased();
  void on_verticalScrollBar_valueChanged(int value);
  void on_verticalScrollBar_sliderReleased();

 private:
  QString file_;
  double value_;
  float xRot_, yRot_, zRot_;
  float lastPosX_, lastPosY_;
  double bgrClrR_, bgrClrG_, bgrClrB_;
  double edgClrR_, edgClrG_, edgClrB_;
  double vertClrR_, vertClrG_, vertClrB_;

  void SetColor(double value, void (MainWindow::*setFunc)(double),
                QSpinBox *spinBox);

  Ui::MainWindow *ui_;
  s21::Controller controller_;
  double maxCoord_;
  int numberFps_;
  QTimer *gifTmr_;
  QGifImage *gifImg_;
  QString gifFileName_;
  QSettings *settings_;
};
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_3_SRC_VIEW_MAINWINDOW_H_
