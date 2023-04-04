#ifndef CPP4_3DVIEWER_V2_0_2_SRC_CONTROLLER_CONTROLLER_H_
#define CPP4_3DVIEWER_V2_0_2_SRC_CONTROLLER_CONTROLLER_H_
#include "../Model/model.h"
namespace s21 {
class Controller {
 public:
  std::vector<double> &getVertexs();
  std::vector<int> &getFacets();
  double getMaxCoordinate();
  bool Parse(const std::string fileName);
  void Move(double move, int coordinate);
  void Transform(double angle, int coordinate);
  void Scaling(double scale, int coordinate);
  int CountV();
  int CountE();
  int CountP();
  void Remove();

 private:
  Affine affine_;
  Parser parser_;
};
}  // namespace s21
#endif  // CPP4_3DVIEWER_V2_0_2_SRC_CONTROLLER_CONTROLLER_H_
