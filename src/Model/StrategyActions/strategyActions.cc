
#include "strategyActions.h"  // TODO rename strategyActions -> strategy

namespace s21 {
// class RotateStrategy
RotateStrategy::RotateStrategy(Figure& figure, Affine& affine)
    : figure_(figure), affine_(affine) {}

void RotateStrategy::Execute(Operation role, double value) {
  value_ = value / 36.0;
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
      break;
  }
}

void RotateStrategy::RotateXSlider() { affine_.Transform(figure_, value_, kX); }
void RotateStrategy::RotateYSlider() { affine_.Transform(figure_, value_, kY); }
void RotateStrategy::RotateZSlider() { affine_.Transform(figure_, value_, kZ); }

// class MoveStrategy
MoveStrategy::MoveStrategy(Figure& figure, Affine& affine)
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
ScaleStrategy::ScaleStrategy(Figure& figure, Affine& affine)
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
    case kScaleMouseAll:
      ScaleMouseAll();
      break;
    case kScaleScrollAll:
      ScaleScrollAll();
      break;
    default:
      break;
  }
}

void ScaleStrategy::ScalePlusX() { affine_.Scale(figure_, 1 + value_, kX); }
void ScaleStrategy::ScaleMinusX() { affine_.Scale(figure_, 1 - value_, kX); }

void ScaleStrategy::ScalePlusY() { affine_.Scale(figure_, 1 + value_, kY); }
void ScaleStrategy::ScaleMinusY() { affine_.Scale(figure_, 1 - value_, kY); }

void ScaleStrategy::ScalePlusZ() { affine_.Scale(figure_, 1 + value_, kZ); }
void ScaleStrategy::ScaleMinusZ() { affine_.Scale(figure_, 1 - value_, kZ); }

void ScaleStrategy::ScaleMouseAll() {
  double value = 1 + value_ / 940.0;
  affine_.Scale(figure_, value, kAll);
}

void ScaleStrategy::ScaleScrollAll() {
  double value = 1 + value_ * -1 / 2500.0;
  affine_.Scale(figure_, value, kAll);
}

}  // namespace s21
