#ifndef CPP4_3DVIEWER_V2_0_2_SRC_VIEW_MAINWINDOW_H_
#define CPP4_3DVIEWER_V2_0_2_SRC_VIEW_MAINWINDOW_H_

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
class Command;   // TODO delete
class Strategy;  // TODO delete

QT_END_NAMESPACE
enum Strategies { kRotateStrgy, kMoveStrgy, kScaleStrgy };
enum Operation {
  kRotValueX,
  kRotSliderX,
  kRotValueY,
  kRotSliderY,
  kRotValueZ,
  kRotSliderZ,
  kMovePlusX,
  kMoveMinusX,
  kMovePlusY,
  kMoveMinusY,
  kMovePlusZ,
  kMoveMinusZ,
  kScalePlusX,
  kScaleMinusX,
  kScalePlusY,
  kScaleMinusY,
  kScalePlusZ,
  kScaleMinusZ,
};

class Invoker {  // TODO delete
 public:
  void Execute(Command *command, Operation operation);
};

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

  Ui::MainWindow *getUi();
  s21::Controller &getController();

  void SaveSettings();
  void LoadSettings();

  void CommandActionEvent(Command *command, Operation operation);

  int getValue() const;  // TODO Check mb delete

  double getRotValueX() const;
  double getRotValueY() const;
  double getRotValueZ() const;

  double getBgrClrR() const;
  double getBgrClrG() const;
  double getBgrClrB() const;

  double getEdgClrR() const;
  double getEdgClrG() const;
  double getEdgClrB() const;

  void setRotValueX(double rotValueX);
  void setRotValueY(double rotValueY);
  void setRotValueZ(double rotValueZ);

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
  void on_horizontalScrollBar_rot_y_sliderReleased();
  void on_horizontalScrollBar_rot_y_valueChanged(int value);
  void on_horizontalScrollBar_rot_z_valueChanged(int value);
  void on_horizontalScrollBar_rot_z_sliderReleased();
  void on_verticalScrollBar_valueChanged(int value);
  void on_verticalScrollBar_sliderReleased();

 private:
  QString file_;
  int value_;
  float xRot_, yRot_, zRot_;
  float lastPosX_, lastPosY_;
  double rotValueX_, rotValueY_, rotValueZ_, qvalue_;
  double bgrClrR_, bgrClrG_, bgrClrB_;
  double edgClrR_, edgClrG_, edgClrB_;
  double vertClrR_, vertClrG_, vertClrB_;

  void SetColor(double value, void (MainWindow::*setFunc)(double),
                QSpinBox *spinBox);

  QPoint mPos_;
  QImage image_;

  s21::Invoker invoker_;
  std::vector<Strategy *> strategies_;
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

#endif  // CPP4_3DVIEWER_V2_0_2_SRC_VIEW_MAINWINDOW_H_
