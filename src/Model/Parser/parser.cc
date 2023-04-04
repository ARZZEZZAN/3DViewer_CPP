#include "parser.h"
namespace s21 {

void Parser::Parse(const std::string& fileName, s21::Figure& figure) {
  std::ifstream file(fileName);
  figure_.Clear();
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
  figure_.setCountEdges(ParseEdges(figure_.getFacets()));
  figure = std::move(figure_);
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
  std::vector<double> tmp = figure_.getVertexes();
  for (size_t i = 0; i < 3; i++) {
    if (i < vec.size()) {
      tmp.push_back(vec.at(i));
    } else {
      tmp.push_back(0);
    }
    if (vec.at(i) > figure_.getMaxCoordinate()) {
      figure_.setMaxCoordinate(vec.at(i));
    }
  }
  if (!vec.empty()) {
    figure_.setCountVertexes(figure_.getCountVertexes() + 1);
  }
  figure_.setVertexes(tmp);
}

void Parser::ParseFacets(std::string& fileLine) {
  std::vector<double> vec = ParseLine(fileLine);
  std::vector<size_t> tmp = figure_.getFacets();

  if (!vec.empty()) {
    tmp.push_back(vec.at(0) - 1);
    for (size_t i = 1; i < vec.size(); i++) {
      tmp.push_back(vec.at(i) - 1);
      tmp.push_back(vec.at(i) - 1);
    }
    tmp.push_back(vec.at(0) - 1);
    figure_.setCountPolygons(figure_.getCountPolygons() + 1);
  }
  figure_.setFacets(tmp);
}

size_t Parser::ParseEdges(const std::vector<size_t>& vec) {
  std::set<Pairs> edges;
  for (size_t i = 1; i < vec.size(); i++) {
    if ((i + 1) % 2 == 0) {
      Pairs edge = std::make_pair(vec.at(i - 1), vec.at(i));
      edges.insert(edge);
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
}  // namespace s21