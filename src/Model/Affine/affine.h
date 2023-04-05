#ifndef CPP4_3DVIEWER_V2_0_3_SRC_MODEL_AFFINE_AFFINE_H_
#define CPP4_3DVIEWER_V2_0_3_SRC_MODEL_AFFINE_AFFINE_H_

#include <cmath>

#include "../Figure/figure.h"
typedef enum coordinate_t { kX = 0, kY, kZ, kAll } coordinate_t;

namespace s21 {
class Affine {
 public:
  void Move(Figure &figure, double move, int coordinate);
  void Transform(Figure &figure, double angle, int coordinate);
  void Scale(Figure &figure, double scale, int coordinate);
};
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_3_SRC_MODEL_AFFINE_AFFINE_H_
