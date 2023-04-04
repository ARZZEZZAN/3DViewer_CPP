#ifndef CPP4_3DVIEWER_V2_0_2_SRC_VIEW_STRATEGY_ACTIONS_STRATEGY_ACTIONS_H_
#define CPP4_3DVIEWER_V2_0_2_SRC_VIEW_STRATEGY_ACTIONS_STRATEGY_ACTIONS_H_

#include "mainwindow.h"

namespace s21 {
class Strategy {
 public:
  Strategy() {}
  virtual ~Strategy() = default;
  virtual void Execute(Operation role) = 0;

 protected:
  MainWindow* mainWindow_;
  s21::Controller* controller_;
  Ui::MainWindow* ui_;
};

class RotateStrategy : public Strategy {
 public:
  RotateStrategy(MainWindow* mainWindow);
  void Execute(Operation role) override;

 private:
  void RotateXValue();
  void RotateXSlider();
  void RotateYValue();
  void RotateYSlider();
  void RotateZValue();
  void RotateZSlider();
};

class MoveStrategy : public Strategy {
 public:
  MoveStrategy(MainWindow* mainWindow);
  void Execute(Operation role) override;

 private:
  void MoveXPlus();
  void MoveXMinus();
  void MoveYPlus();
  void MoveYMinus();
  void MoveZPlus();
  void MoveZMinus();
};

class ColorStrategy : public Strategy {
 public:
  ColorStrategy(MainWindow* mainWindow);
  void Execute(Operation role) override;

 private:
  void BgrClrR();
  void BgrClrG();
  void BgrClrB();
  void EdgClrR();
  void EdgClrG();
  void EdgClrB();
  void VerClrR();
  void VerClrG();
  void VerClrB();
};

class ScaleStrategy : public Strategy {
 public:
  ScaleStrategy(MainWindow* mainWindow);
  void Execute(Operation role) override;

 private:
  void ScalePlusX();
  void ScaleMinusX();
  void ScalePlusY();
  void ScaleMinusY();
  void ScalePlusZ();
  void ScaleMinusZ();
};
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_2_SRC_VIEW_STRATEGY_ACTIONS_STRATEGY_ACTIONS_H_
