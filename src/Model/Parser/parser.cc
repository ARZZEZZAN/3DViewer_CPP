#include "parser.h"
namespace s21 {

void Parser::Parse(const std::string& fileName, Figure& figure) {
  std::ifstream file(fileName);
  figure.Clear();
  if (file.is_open() && strcmp(&fileName[fileName.size() - 3], ".obj")) {
    std::string fileLine;
    while (std::getline(file, fileLine)) {
      if (ParseConditions(fileLine, 'v')) {
        ParseVertexes(fileLine, figure);
      } else if (ParseConditions(fileLine, 'f')) {
        ParseFacets(fileLine, figure);
      }
    }
  }
  figure.setCountEdges(ParseEdges(figure.getFacets()));
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

void Parser::ParseVertexes(std::string& fileLine, Figure& figure) {
  std::vector<double> vec = ParseLine(fileLine);
  std::vector<double> tmp = figure.getVertexes();
  for (size_t i = 0; i < 3; i++) {
    if (i < vec.size()) {
      tmp.push_back(vec.at(i));
    } else {
      tmp.push_back(0);
    }
    if (fabs(vec.at(i)) > fabs(figure.getMaxCoordinate())) {
      figure.setMaxCoordinate(fabs(vec.at(i)));
    }
  }
  if (!vec.empty()) {
    figure.setCountVertexes(figure.getCountVertexes() + 1);
  }
  figure.setVertexes(tmp);
}

void Parser::ParseFacets(std::string& fileLine, Figure& figure) {
  std::vector<double> vec = ParseLine(fileLine);
  std::vector<int> tmp = figure.getFacets();

  if (!vec.empty()) {
    tmp.push_back(vec.at(0) - 1);
    for (size_t i = 1; i < vec.size(); i++) {
      tmp.push_back(vec.at(i) - 1);
      tmp.push_back(vec.at(i) - 1);
    }
    tmp.push_back(vec.at(0) - 1);
    figure.setCountPolygons(figure.getCountPolygons() + 1);
  }
  figure.setFacets(tmp);
}

int Parser::ParseEdges(const std::vector<int>& vec) {
  std::set<Pairs> edges;
  for (size_t i = 1; i < vec.size(); i++) {
    if ((i + 1) % 2 == 0) {
      Pairs edge = std::make_pair(vec.at(i - 1), vec.at(i));
      edges.insert(edge);
      Pairs edgeMirror = std::make_pair(vec.at(i), vec.at(i - 1));
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
}  // namespace s21