#ifndef CPP4_3DVIEWER_V2_0_3_SRC_CONTROLLER_CONTROLLER_H_
#define CPP4_3DVIEWER_V2_0_3_SRC_CONTROLLER_CONTROLLER_H_
#include "../Model/Facade/facade.h"
namespace s21 {
class Controller {
 public:
  // Parser
  void Parse(const std::string& fileName);

  // Affine
  void Move(double move, Operation role);
  void Transform(double angle, Operation role);
  void Scale(double scale, Operation role);

  // Figure
  void Remove();

  std::vector<double> getVertexes() const;
  std::vector<int> getFacets() const;
  int getCountVertexes() const;
  int getCountEdges() const;
  int getCountPolygons() const;
  double getMaxCoordinate() const;

 private:
  Facade facade_;
};
}  // namespace s21
#endif  // CPP4_3DVIEWER_V2_0_3_SRC_CONTROLLER_CONTROLLER_H_
