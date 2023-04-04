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
  std::vector<size_t> getFacets() const;
  size_t getCountVertexes() const;
  size_t getCountEdges() const;
  size_t getCountPolygons() const;
  double getMaxCoordinate() const;

  void setVertexes(std::vector<double>& vertexes);
  void setFacets(std::vector<size_t>& facets);
  void setCountVertexes(size_t countVertexes);
  void setCountEdges(size_t countEdges);
  void setCountPolygons(size_t countPolygons);
  void setMaxCoordinate(double maxCoordinate);

 private:
  Facade facade_;
};
}  // namespace s21
#endif  // CPP4_3DVIEWER_V2_0_2_SRC_CONTROLLER_CONTROLLER_H_
