#include "parser.h"

namespace s21 {
Parser::Parser() : countVertexes_(0), countPolygons_(0), maxCoordinate_(0) {}

void Parser::Parse(const std::string& fileName, Figure& figure) {
  std::ifstream file(fileName);
  Clear();
  if (file.is_open() && strcmp(&fileName[fileName.size() - 3], ".obj")) {
    std::string fileLine;
    while (std::getline(file, fileLine)) {
      if (ParseConditions(fileLine, 'v')) {
        ParseVertexes(fileLine);
      } else if (ParseConditions(fileLine, 'f')) {
        ParseFacets(fileLine);
      }
    }
  }
  setFigure(figure);
}

bool Parser::ParseConditions(std::string& fileLine, char type) {
  bool success = false;
  while (!fileLine.empty() && isspace(fileLine.at(0))) {
    fileLine.erase(fileLine.begin());
  }
  if (!fileLine.empty() && fileLine.at(0) == type) {
    fileLine.erase(fileLine.begin());
    if (!fileLine.empty() && fileLine.at(0) == ' ') {
      success = true;
    }
  }
  return success;
}

void Parser::ParseVertexes(std::string& fileLine) {
  std::vector<double> vec = ParseLine(fileLine);
  for (size_t i = 0; i < 3; i++) {
    if (i < vec.size()) {
      vertexes_.push_back(vec.at(i));
    } else {
      vertexes_.push_back(0);
    }
    double mc = fabs(vec.at(i));
    if (mc > fabs(maxCoordinate_)) {
      maxCoordinate_ = mc;
    }
  }
  if (!vec.empty()) {
    countVertexes_++;
  }
}

void Parser::ParseFacets(std::string& fileLine) {
  std::vector<double> vec = ParseLine(fileLine);
  if (!vec.empty()) {
    facets_.push_back(vec.at(0) - 1);
    for (size_t i = 1; i < vec.size(); i++) {
      facets_.push_back(vec.at(i) - 1);
      facets_.push_back(vec.at(i) - 1);
    }
    facets_.push_back(vec.at(0) - 1);
    countPolygons_++;
  }
}

int Parser::ParseEdges() {
  std::set<Pairs> edges;
  for (size_t i = 1; i < facets_.size(); i++) {
    if ((i + 1) % 2 == 0) {
      Pairs edge = std::make_pair(facets_.at(i - 1), facets_.at(i));
      edges.insert(edge);
      Pairs edgeMirror = std::make_pair(facets_.at(i), facets_.at(i - 1));
      edges.erase(edgeMirror);
    }
  }
  return edges.size();
}

std::vector<double> Parser::ParseLine(std::string& fileLine) {
  std::vector<double> res;
  while (!fileLine.empty()) {
    double num = 0;
    sscanf(fileLine.c_str(), "%lf", &num);
    res.push_back(num);

    DelSpace(fileLine);

    while (!fileLine.empty() && !isspace(fileLine.at(0))) {
      fileLine.erase(fileLine.begin());
    }
    DelSpace(fileLine);
  }
  return res;
}

void Parser::DelSpace(std::string& fileLine) {
  while (!fileLine.empty() && isspace(fileLine.at(0))) {
    fileLine.erase(fileLine.begin());
  }
}

void Parser::setFigure(Figure& figure) {
  figure.setFacets(facets_);
  figure.setVertexes(vertexes_);
  figure.setCountEdges(ParseEdges());
  figure.setCountPolygons(countPolygons_);
  figure.setCountVertexes(countVertexes_);
  figure.setMaxCoordinate(maxCoordinate_);
}

void Parser::Clear() {
  vertexes_.clear();
  facets_.clear();
  countVertexes_ = 0;
  countPolygons_ = 0;
  maxCoordinate_ = 0;
}

}  // namespace s21
