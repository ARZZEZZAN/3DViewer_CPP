
#include "strategyActions.h"

namespace s21 {
// class RotateStrategy
RotateStrategy::RotateStrategy(Figure figure, Affine affine)
    : figure_(figure), affine_(affine) {}

void RotateStrategy::Execute(Operation role, double value) {
  value_ = value;
  switch (role) {
    case kRotSliderX:
      RotateXSlider();
      break;
    case kRotSliderY:
      RotateYSlider();
      break;
    case kRotSliderZ:
      RotateZSlider();
      break;
    default:
      throw std::invalid_argument(
          "Pay attention for the type of operation");  // TODO mb delete
      break;
  }
}

void RotateStrategy::RotateXSlider() { affine_.Transform(figure_, value_, kX); }
void RotateStrategy::RotateYSlider() { affine_.Transform(figure_, value_, kY); }
void RotateStrategy::RotateZSlider() { affine_.Transform(figure_, value_, kZ); }

// class MoveStrategy
MoveStrategy::MoveStrategy(Figure figure, Affine affine)
    : figure_(figure), affine_(affine) {}

void MoveStrategy::Execute(Operation role, double value) {
  value_ = value;
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
      throw std::invalid_argument(
          "Pay attention for the type of operation");  // TODO delete
      break;
  }
}

void MoveStrategy::MoveXPlus() { affine_.Move(figure_, value_, kX); }
void MoveStrategy::MoveXMinus() { affine_.Move(figure_, value_ * -1, kX); }
void MoveStrategy::MoveYPlus() { affine_.Move(figure_, value_, kY); }
void MoveStrategy::MoveYMinus() { affine_.Move(figure_, value_ * -1, kY); }
void MoveStrategy::MoveZPlus() { affine_.Move(figure_, value_, kZ); }
void MoveStrategy::MoveZMinus() { affine_.Move(figure_, value_ * -1, kZ); }

// class ScaleStrategy
ScaleStrategy::ScaleStrategy(Figure figure, Affine affine)
    : figure_(figure), affine_(affine) {}

void ScaleStrategy::Execute(Operation role, double value) {
  value_ = value;
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
    case kScaleAll:
      ScaleMinusAll();
      break;
    default:
      throw std::invalid_argument(
          "Pay attention for the type of operation");  // TODO
      break;
  }
}

void ScaleStrategy::ScalePlusX() {
  double value = 1 + value_;
  affine_.Scale(figure_, value, kX);
}
void ScaleStrategy::ScaleMinusX() {
  double value = 1 - value_;
  if (value == 0) {
    value = 0.1;
  }
  affine_.Scale(figure_, value, kX);
}

void ScaleStrategy::ScalePlusY() {
  double value = 1 + value_;
  affine_.Scale(figure_, value, kY);
}
void ScaleStrategy::ScaleMinusY() {
  double value = 1 - value_;
  if (value == 0) {
    value = 0.1;
  }
  affine_.Scale(figure_, value, kY);
}

void ScaleStrategy::ScalePlusZ() { affine_.Scale(figure_, (1 + value_), kZ); }
void ScaleStrategy::ScaleMinusZ() {
  double value = 1 - value_;
  if (value == 0) {
    value = 0.1;
  }
  affine_.Scale(figure_, value, kZ);
}
void ScaleStrategy::ScaleMinusAll() {
  double value = 1 - value_;
  if (value == 0) {
    value = 0.1;
  }
  affine_.Scale(figure_, value, kAll);
}

}  // namespace s21
