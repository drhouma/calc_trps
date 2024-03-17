#include "model.h"

#include <iostream>

namespace s21 {

void Model::PutStringInInput(std::string const source) {
  if (_input.size() <= 255) _input += source;
}

std::string Model::GetStringInput() { return _input; }

void Model::ClearStringInput() { _input = ""; }

const std::string &Model::GetInputString() { return _input; }

bool Model::CheckMultyplyPoints() {
    auto left = _input.begin(), right = _input.end();
    for (bool pointFinded = false;left != right; left++) {

        if (*left == '.') {
            if (pointFinded) return false;
            pointFinded = true;
        } else {
            pointFinded = false;
        }
    }
    return true;
}

bool Model::BracketsEquality() {
  std::string::iterator left = _input.begin(), right = _input.end();
  int numberOfLBrackets = 0, numberOfRBrackets = 0;
  while (left != right) {
    if (*left == '(') numberOfLBrackets++;
    if (*left == ')') numberOfRBrackets++;
    left++;
  }
  return numberOfLBrackets == numberOfRBrackets;
}

int GetIndex(std::string &source, std::string::iterator iter) {
  std::string::iterator r = source.begin();
  int out = 0;
  while (r != iter) {
    out++;
    r++;
  }
  return out;
}

void Model::PrintUnary(std::string source) {
  std::string haystack = " -+^";
  std::string::iterator right = source.end(), left = source.begin();
  int rBracket = 0;
  while (right != left && haystack.find(*right) == std::string::npos) {
    if (*right == ')') {
      rBracket++;
      while (rBracket != 0) {
        right--;
        if (*right == ')') rBracket++;
        if (*right == '(') rBracket--;
      }
    }
    if (*right != *left) right--;
  }
  char sign, tempSymb = 0;
  if (*right == *left && haystack.find(*right) == std::string::npos) {
    _input = '-' + source;
  } else {
    std::string temp = source.substr(0, GetIndex(source, right));
    if (*right == '+' || *right == '-') {
      if (*right == '+') sign = '-';
      if (*right == '-') sign = '+';
      tempSymb = 'N';
    }
    if (*right == ' ') {
      tempSymb = ' ';
      sign = '-';
    }
    if (*right == '^') {
      tempSymb = '^';
      sign = '-';
    }
    if (*right == 'x') {
      temp += '-';
      temp += source.substr(GetIndex(source, right));
      _input = temp;
    } else {
      if (tempSymb != 'N') temp += tempSymb;
      temp += sign;
      temp += source.substr(GetIndex(source, right) + 1);
      _input = temp;
    }
  }
}

/// calculating code

PolishNotation::PolishNotation(std::string const &source) {
  _pn = source;
  ConvertToPolish();
}

std::string PolishNotation::GetString() { return _pn; }

bool strncmpMy(std::string::iterator &iter, std::string str, int count) {
  int i = 0;
  bool res = false;
  for (; i < count && *iter != '\0' && *iter - str[i] == 0; i++, iter++) {
  }
  if (i == count) {
    res = true;
  } else {
    iter -= i;
  }
  return res;
}
bool IsFunctionRename(char symb) {
  bool res = false;
  std::string haystack = "SsCcTtLlq";
  if (haystack.find(symb) != std::string::npos) {
    res = true;
  }
  return res;
}

char IsFunction(std::string::iterator &left) {
  char out = 0;
  if (strncmpMy(left, "cos", 3)) out = 'c';
  if (strncmpMy(left, "sin", 3)) out = 's';
  if (strncmpMy(left, "acos", 4)) out = 'C';
  if (strncmpMy(left, "asin", 4)) out = 'S';
  if (strncmpMy(left, "atan", 4)) out = 'T';
  if (strncmpMy(left, "sqrt", 4)) out = 'q';
  if (strncmpMy(left, "ln", 2)) out = 'l';
  if (strncmpMy(left, "tg", 2)) out = 't';
  if (strncmpMy(left, "log", 3)) out = 'L';
  return out;
}

bool IsOperation(char symbol) {
  bool res = false;
  std::string haystack = "*/+-^%";
  if (haystack.find(symbol) != std::string::npos) {
    res = true;
  }
  return res;
}

int Prior(char symbol) {
  int out = 0;
  if (symbol == ')') out = 4;
  if (symbol == '^') out = 3;
  if (symbol == '*' || symbol == '/' || symbol == '%') out = 2;
  if (symbol == '-' || symbol == '+') out = 1;
  return out;
}

bool CheckPrior(char top, char symb) {
  bool out = false;
  if (Prior(top) >= Prior(symb)) out = true;
  if (top == '^' && symb == '^') out = false;
  if (IsFunctionRename(top)) out = true;
  if (symb == '(' || top == '(') out = false;
  return out;
}

void PolishNotation::CheckFunc(std::string::iterator &left,
                               std::stack<char> &opers) {
  char symb = IsFunction(left);
  if (symb) {
    opers.push(symb);
  }
}

void PolishNotation::CheckX(std::string::iterator &left, std::string &res) {
  if ((*left == '+' || *left == '-') && *(left + 1) == 'x') {
    res += *left;
    left++;
  }
  if (*left == 'x') res += *left;
}

void PolishNotation::CheckOper(std::string::iterator &left, std::string &res,
                               std::stack<char> &opers) {
  if (IsOperation(*left)) {
    while (!opers.empty() && CheckPrior(opers.top(), *left)) {
      char symb = opers.top();
      opers.pop();
      res += symb;
      res += ' ';
    }
    opers.push(*left);
  }
}

void PolishNotation::CheckNumber(std::string::iterator &left,
                                 std::string &res) {
  std::string haystack = "0123456789.";
  if ((*left == '+' || *left == '-') &&
      haystack.find(*(left + 1)) != std::string::npos) {
    if (*left != '+') res += *left;
    left++;
  }
  if (*left != ' ' && IsNumber(left)) {
    while (haystack.find(*left) != std::string::npos) {
      res += *left;
      left++;
    }
    res += ' ';
  }
}

void PolishNotation::CheckBracket(std::string::iterator &left, std::string &res,
                                  std::stack<char> &opers) {
  if (*left == '(') {
    opers.push(*left);
  }
  if (*left == ')') {
    while (opers.top() != '(') {
      char symb = opers.top();
      opers.pop();

      res += symb;
      res += ' ';
    }
    opers.pop();
  }
}

bool PolishNotation::IsNumber(std::string::iterator iter) {
  bool res = false, dot = false;
  int counter = 0;
  std::string numbers = "0123456789.";
  while (numbers.find(*iter) != std::string::npos) {
    if (*iter == '.') {
      if (dot == false) {
        dot = true;
        counter--;
      } else {
        counter = -10000;
      }
    }
    iter++;
    counter++;
  }
  if (counter > 0) res = true;
  return res;
}

void PolishNotation::ConvertToPolish() {
  std::string result;
  std::stack<char> operationStack;
  std::string::iterator left = _pn.begin(), right = _pn.end();
  for (; left != right; left++) {
    CheckX(left, result);
    CheckNumber(left, result);
    CheckOper(left, result, operationStack);
    CheckFunc(left, operationStack);
    CheckBracket(left, result, operationStack);
    // когда итератор выходит на конец строки уже в цикле
    if (left == right) left--;
  }
  while (!operationStack.empty()) {
    result += operationStack.top();
    result += ' ';
    operationStack.pop();
  }
  printf("%s\n", result.c_str());
  _pn = result;
}

bool IsDigit(char symbol) {
  std::string haystack = "0123456789.";
  bool res = false;
  if (haystack.find(symbol) != std::string::npos) res = true;
  return res;
}

double GetDouble(std::string::iterator &iter) {
  std::string number = "";
  while (IsDigit(*iter)) {
    number += *iter;
    iter++;
  }
  return std::stod(number);
}

bool operation(char symbol, std::stack<double> &values) {
  if (values.empty()) return ERROR;
  double num2 = values.top();
  values.pop();
  bool err = OK;
  if (values.empty()) return ERROR;
  double num1 = values.top();
  values.pop();
  if (!std::isnan(num1) && !std::isnan(num2)) {
    if (symbol == '-') {
      num1 = num1 - num2;
      values.push(num1);
    }
    if (symbol == '+') {
      num1 = num1 + num2;
      values.push(num1);
    }
    if (symbol == '*') {
      num1 = num1 * num2;
      values.push(num1);
    }
    if (symbol == '/') {
      num1 = num1 / num2;
      values.push(num1);
    }
    if (symbol == '^') {
      num1 = pow(num1, num2);
      values.push(num1);
    }
    if (symbol == '%') {
      num1 = fmod(num1, num2);
      values.push(num1);
    }
  } else {
    err = ERROR;
  }
  return err;
}

bool function(char symbol, std::stack<double> &values) {
  double res;
  if (values.empty()) return ERROR;

  if (symbol == 's') {
    res = values.top();
    values.pop();
    if (std::isnan(res)) return ERROR;
    values.push(sin(res));
  }
  if (symbol == 'S') {
    res = values.top();
    values.pop();
    if (std::isnan(res)) return ERROR;
    values.push(asin(res));
  }
  if (symbol == 'c') {
    res = values.top();
    values.pop();
    if (std::isnan(res)) return ERROR;
    values.push(cos(res));
  }
  if (symbol == 'C') {
    res = values.top();
    values.pop();
    if (std::isnan(res)) return ERROR;
    values.push(acos(res));
  }
  if (symbol == 't') {
    res = values.top();
    values.pop();
    if (std::isnan(res)) return ERROR;
    values.push(tan(res));
  }
  if (symbol == 'T') {
    res = values.top();
    values.pop();
    if (std::isnan(res)) return ERROR;
    values.push(atan(res));
  }
  if (symbol == 'l') {
    res = values.top();
    values.pop();
    if (std::isnan(res) || res < 0) return ERROR;
    values.push(log(res));
  }
  if (symbol == 'L') {
    res = values.top();
    values.pop();
    if (std::isnan(res) || res < 0) return ERROR;
    values.push(log10(res));
  }
  if (symbol == 'q') {
    res = values.top();
    values.pop();
    if (std::isnan(res) || res < 0) return ERROR;
    values.push(sqrt(res));
  }
  return OK;
}

double PolishNotation::calculate(double x) {
  std::stack<double> values;
  double res = 0;
  bool err = false;
  std::string::iterator left = _pn.begin(), right = _pn.end();
  for (; left != right && !err; left++) {
    if (*left == '-' && *(left + 1) == 'x') {
      values.push(x * -1);
      left++;
    } else if (*left == 'x') {
      values.push(x);
    } else if (*left == '-' && IsNumber(left + 1)) {
      left++;
      values.push(GetDouble(left) * -1);
    } else if (IsNumber(left)) {
      values.push(GetDouble(left));
    } else if (IsOperation(*left)) {
      err = operation(*left, values);
    } else if (IsFunctionRename(*left)) {
      err = function(*left, values);
    }
  }
  if (!values.empty() && !err) {
    res = values.top();
  } else {
    res = nan("1");
  }
  return res;
}

bool Model::ValidateInput() {
    return true;
}




}

