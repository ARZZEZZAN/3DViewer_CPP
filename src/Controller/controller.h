#ifndef CPP4_3DVIEWER_V2_0_2_SRC_CONTROLLER_CONTROLLER_H_
#define CPP4_3DVIEWER_V2_0_2_SRC_CONTROLLER_CONTROLLER_H_
#include "../Model/Facade/facade.h"
namespace s21 {
class Controller {
 public:
  // Parser
  void Parse(const std::string& fileName);

  // Affine
  void Move(double move, int coordinate);
  void Transform(double angle, int coordinate);
  void Scale(double scale, int coordinate);

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
#endif  // CPP4_3DVIEWER_V2_0_2_SRC_CONTROLLER_CONTROLLER_H_
