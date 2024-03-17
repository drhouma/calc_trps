#pragma once

#include <cmath>
#include <stack>
#include <string>

#define ERROR true
#define OK false
namespace s21 {

class Model {
 private:
  std::string _input;

 public:
  void PutStringInInput(std::string const source);

  std::string GetStringInput();

  void ClearStringInput();

  void PrintUnary(std::string source);

  bool BracketsEquality();

  const std::string &GetInputString();

  bool CheckMultyplyPoints();
  bool ValidateInput();
};


bool ValidateInput() {
    return true;
}

// calculating class
class PolishNotation {
 private:
  std::string _pn;

 public:
  PolishNotation(std::string const &source);

  bool IsNumber(std::string::iterator iter);
  void ConvertToPolish();

  void CheckNumber(std::string::iterator &left, std::string &res);
  void CheckX(std::string::iterator &left, std::string &res);
  void CheckOper(std::string::iterator &left, std::string &res,
                 std::stack<char> &opers);
  void CheckFunc(std::string::iterator &left, std::stack<char> &opers);
  void CheckBracket(std::string::iterator &left, std::string &res,
                    std::stack<char> &opers);
  std::string GetString();

  double calculate(double x);

};
}
