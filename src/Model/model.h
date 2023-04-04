#ifndef CPP4_3DVIEWER_V2_0_2_SRC_MODEL_MODEL_H_
#define CPP4_3DVIEWER_V2_0_2_SRC_MODEL_MODEL_H_
#include "Affine/affine.h"
namespace s21 {
class Model {
 public:
  Model() {}
  ~Model() {}
  Parser& getParser() { return parser_; }
  Affine& getAffine() { return affine_; }

 private:
  Parser parser_;
  Affine affine_;
};
}  // namespace s21
#endif  // CPP4_3DVIEWER_V2_0_2_SRC_MODEL_MODEL_H_
