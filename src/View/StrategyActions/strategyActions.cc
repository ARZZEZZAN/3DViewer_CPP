
#include "strategyActions.h"

namespace s21 {
// class RotateStrategy
RotateStrategy::RotateStrategy(MainWindow* mainWindow) {
  mainWindow_ = mainWindow;
  controller_ = &mainWindow_->getController();
  ui_ = mainWindow_->getUi();
}
void RotateStrategy::Execute(Operation role) {
  switch (role) {
    case kRotValueX:
      RotateXValue();
      break;
    case kRotSliderX:
      RotateXSlider();
      break;
    case kRotValueY:
      RotateYValue();
      break;
    case kRotSliderY:
      RotateYSlider();
      break;
    case kRotValueZ:
      RotateZValue();
      break;
    case kRotSliderZ:
      RotateZSlider();
      break;
    default:
      throw std::invalid_argument("Pay attention for the type of operation");
      break;
  }
}

void RotateStrategy::RotateXValue() {
  mainWindow_->setRotValueX(mainWindow_->getValue() / 36.0);
}
void RotateStrategy::RotateXSlider() {
  controller_->Transform(mainWindow_->getRotValueX(), kX);
  ui_->horizontalScrollBar_rot_x->setValue(0);
  mainWindow_->update();
}
void RotateStrategy::RotateYValue() {
  mainWindow_->setRotValueY(mainWindow_->getValue() / 36.0);
}
void RotateStrategy::RotateYSlider() {
  controller_->Transform(mainWindow_->getRotValueY(), kY);
  ui_->horizontalScrollBar_rot_y->setValue(0);
  mainWindow_->update();
}
void RotateStrategy::RotateZValue() {
  mainWindow_->setRotValueZ(mainWindow_->getValue() / 36.0);
}
void RotateStrategy::RotateZSlider() {
  controller_->Transform(mainWindow_->getRotValueZ(), kZ);
  ui_->horizontalScrollBar_rot_z->setValue(0);
  mainWindow_->update();
}

// class MoveStrategy
MoveStrategy::MoveStrategy(MainWindow* mainWindow) {
  mainWindow_ = mainWindow;
  controller_ = &mainWindow_->getController();
  ui_ = mainWindow_->getUi();
}
void MoveStrategy::Execute(Operation role) {
  switch (role) {
    case kMovePlusX:
      MoveXPlus();
      break;
    case kMoveMinusX:
      MoveXMinus();
      break;
    case kMovePlusY:
      MoveYPlus();
      break;
    case kMoveMinusY:
      MoveYMinus();
      break;
    case kMovePlusZ:
      MoveZPlus();
      break;
    case kMoveMinusZ:
      MoveZMinus();
      break;
    default:
      throw std::invalid_argument("Pay attention for the type of operation");
      break;
  }
}

void MoveStrategy::MoveXPlus() {
  controller_->Move(ui_->doubleSpinBox_mv_value->value(), 0);
  mainWindow_->update();
}
void MoveStrategy::MoveXMinus() {
  controller_->Move(ui_->doubleSpinBox_mv_value->value() * -1, 0);
  mainWindow_->update();
}
void MoveStrategy::MoveYPlus() {
  controller_->Move(ui_->doubleSpinBox_mv_value->value(), 1);
  mainWindow_->update();
}
void MoveStrategy::MoveYMinus() {
  controller_->Move(ui_->doubleSpinBox_mv_value->value() * -1, 1);
  mainWindow_->update();
}
void MoveStrategy::MoveZPlus() {
  controller_->Move(ui_->doubleSpinBox_mv_value->value(), 2);
  mainWindow_->update();
}
void MoveStrategy::MoveZMinus() {
  controller_->Move(ui_->doubleSpinBox_mv_value->value() * -1, 2);
  mainWindow_->update();
}

// class ColorStrategy
ColorStrategy::ColorStrategy(MainWindow* mainWindow) {
  mainWindow_ = mainWindow;
  controller_ = &mainWindow_->getController();
  ui_ = mainWindow_->getUi();
}
void ColorStrategy::Execute(Operation role) {
  switch (role) {
    case kBgrColorRed:
      BgrClrR();
      break;
    case kBgrColorGreen:
      BgrClrG();
      break;
    case kBgrColorBlue:
      BgrClrB();
      break;
    case kEdgColorRed:
      EdgClrR();
      break;
    case kEdgColorGreen:
      EdgClrG();
      break;
    case kEdgColorBlue:
      EdgClrB();
      break;
    case kVerColorRed:
      VerClrR();
      break;
    case kVerColorGreen:
      VerClrG();
      break;
    case kVerColorBlue:
      VerClrB();
      break;
    default:
      throw std::invalid_argument("Pay attention for the type of operation");
      break;
  }
}

void ColorStrategy::BgrClrR() {
  mainWindow_->setBgrClrR(((double)mainWindow_->getValue()) / 100.0);
  ui_->spinBox_bgr_R->setValue(mainWindow_->getValue());
  mainWindow_->update();
}
void ColorStrategy::BgrClrG() {
  mainWindow_->setBgrClrG(((double)mainWindow_->getValue()) / 100.0);
  ui_->spinBox_bgr_G->setValue(mainWindow_->getValue());
  mainWindow_->update();
}
void ColorStrategy::BgrClrB() {
  mainWindow_->setBgrClrB(((double)mainWindow_->getValue()) / 100.0);
  ui_->spinBox_bgr_B->setValue(mainWindow_->getValue());
  mainWindow_->update();
}
void ColorStrategy::EdgClrR() {
  mainWindow_->setEdgClrR(((double)mainWindow_->getValue()) / 100.0);
  ui_->spinBox_edges_R->setValue(mainWindow_->getValue());
  mainWindow_->update();
}
void ColorStrategy::EdgClrG() {
  mainWindow_->setEdgClrG(((double)mainWindow_->getValue()) / 100.0);
  ui_->spinBox_edges_G->setValue(mainWindow_->getValue());
  mainWindow_->update();
}
void ColorStrategy::EdgClrB() {
  mainWindow_->setEdgClrB(((double)mainWindow_->getValue()) / 100.0);
  ui_->spinBox_edges_B->setValue(mainWindow_->getValue());
  mainWindow_->update();
}

void ColorStrategy::VerClrR() {
  mainWindow_->setVertClrR(((double)mainWindow_->getValue()) / 100.0);
  ui_->spinBox_vertexes_R->setValue(mainWindow_->getValue());
  mainWindow_->update();
}
void ColorStrategy::VerClrG() {
  mainWindow_->setVertClrG(((double)mainWindow_->getValue()) / 100.0);
  ui_->spinBox_vertexes_G->setValue(mainWindow_->getValue());
  mainWindow_->update();
}
void ColorStrategy::VerClrB() {
  mainWindow_->setVertClrB(((double)mainWindow_->getValue()) / 100.0);
  ui_->spinBox_vertexes_B->setValue(mainWindow_->getValue());
  mainWindow_->update();
}

// class ScaleStrategy
ScaleStrategy::ScaleStrategy(MainWindow* mainWindow) {
  mainWindow_ = mainWindow;
  controller_ = &mainWindow_->getController();
  ui_ = mainWindow_->getUi();
}
void ScaleStrategy::Execute(Operation role) {
  switch (role) {
    case kScalePlusX:
      ScalePlusX();
      break;
    case kScaleMinusX:
      ScaleMinusX();
      break;
    case kScalePlusY:
      ScalePlusY();
      break;
    case kScaleMinusY:
      ScaleMinusY();
      break;
    case kScalePlusZ:
      ScalePlusZ();
      break;
    case kScaleMinusZ:
      ScaleMinusZ();
      break;
    default:
      throw std::invalid_argument("Pay attention for the type of operation");
      break;
  }
}

void ScaleStrategy::ScalePlusX() {
  double value = 1 + ui_->doubleSpinBox_sc_value->value();
  controller_->Scale(value, kX);
  mainWindow_->update();
}
void ScaleStrategy::ScaleMinusX() {
  double value = 1 - ui_->doubleSpinBox_sc_value->value();
  if (value == 0) {
    value = 0.1;
  }
  controller_->Scale(value, kX);
  mainWindow_->update();
}

void ScaleStrategy::ScalePlusY() {
  double value = 1 + ui_->doubleSpinBox_sc_value->value();
  controller_->Scale(value, kY);
  mainWindow_->update();
}
void ScaleStrategy::ScaleMinusY() {
  double value = 1 - ui_->doubleSpinBox_sc_value->value();
  if (value == 0) {
    value = 0.1;
  }
  controller_->Scale(value, kY);
  mainWindow_->update();
}

void ScaleStrategy::ScalePlusZ() {
  double value = 1 + ui_->doubleSpinBox_sc_value->value();
  controller_->Scale(value, kZ);
  mainWindow_->update();
}
void ScaleStrategy::ScaleMinusZ() {
  double value = 1 - ui_->doubleSpinBox_sc_value->value();
  if (value == 0) {
    value = 0.1;
  }
  controller_->Scale(value, kZ);
  mainWindow_->update();
}

}  // namespace s21
