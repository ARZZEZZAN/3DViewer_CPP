#ifndef CPP4_3DVIEWER_V2_0_2_SRC_MODEL_AFFINE_AFFINE_H_
#define CPP4_3DVIEWER_V2_0_2_SRC_MODEL_AFFINE_AFFINE_H_

#include "../Parser/parser.h"

typedef enum coordinate_t { kX = 0, kY, kZ, kAll } coordinate_t;

namespace s21 {
class Affine {
 public:
  Affine();
  ~Affine();
  void Move(Parser *p, double move, int coordinate);
  void Transform(Parser *p, double angle, int coordinate);
  void Scaling(Parser *p, double scale, int coordinate);
};
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_2_SRC_MODEL_AFFINE_AFFINE_H_
