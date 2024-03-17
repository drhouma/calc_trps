#include <gtest/gtest.h>

#include <iostream>

#include "model.h"

#define EPS 0.000001

using namespace s21;

TEST(Converter_to_pn, test_easy) {
  PolishNotation pn("1 + 2 / 3 * 4 - 5.21");
  ASSERT_EQ(pn.GetString(), "1 2 3 / 4 * + 5.21 - ");
}

TEST(Converter_to_pn, test_hard) {
  PolishNotation pn(
      "1 + 2 / log(5 + 3 / (2 * 10)) * 3^2 - (55 /3 * (5 + 2)) + sin(5)");
  ASSERT_EQ(pn.GetString(),
            "1 2 5 3 2 10 * / + L / 3 2 ^ * + 55 3 / 5 2 + * - 5 s + ");
}

TEST(Calculate_test, test_easy) {
  PolishNotation pn("1 + 2 / 3 * 4 - 5.21");
  double res = pn.calculate(0);
  ASSERT_EQ(-1.543333 - res < EPS, true);
}

TEST(Calculate_test, test_hard) {
  PolishNotation pn(
      "1 + 2 / log(5 + 3 / (2 * 10)) * 3^2 - (55 /3 * (5 + 2)) + sin(5)");
  double res = pn.calculate(0);
  ASSERT_EQ(-103.004512 - res < EPS, true);
}

TEST(Calculate_test, test_cos) {
  PolishNotation pn("cos(0.5)");
  double res = pn.calculate(0);
  ASSERT_EQ(0.877582 - res < EPS, true);
}

TEST(Calculate_test, test_acos) {
  PolishNotation pn("acos(0.5)");
  double res = pn.calculate(0);
  ASSERT_EQ(1.047197 - res < EPS, true);
}

TEST(Calculate_test, test_tg) {
  PolishNotation pn("tg(0.5)");
  double res = pn.calculate(0);
  ASSERT_EQ(0.546302 - res < EPS, true);
}

TEST(Calculate_test, test_ctg) {
  PolishNotation pn("atg(0.5)");
  double res = pn.calculate(0);
  ASSERT_EQ(0.463647 - res < EPS, true);
}

TEST(Calculate_test, test_sin) {
  PolishNotation pn("sin(0.5)");
  double res = pn.calculate(0);
  ASSERT_EQ(0.479425 - res < EPS, true);
}

TEST(Calculate_test, test_asin) {
  PolishNotation pn("asin(0.5)");
  double res = pn.calculate(0);
  ASSERT_EQ(0.523598 - res < EPS, true);
}

TEST(Calculate_test, test_sqrt) {
  PolishNotation pn("sqrt(4)");
  double res = pn.calculate(0);
  ASSERT_EQ(2 - res < EPS, true);
}

TEST(Calculate_test, test_ln) {
  PolishNotation pn("ln(4)");
  double res = pn.calculate(0);
  ASSERT_EQ(1.386294 - res < EPS, true);
}

TEST(Calculate_test, test_log) {
  PolishNotation pn("log(100)");
  double res = pn.calculate(0);
  ASSERT_EQ(2 - res < EPS, true);
}

TEST(Calculate_test, test_mod) {
  PolishNotation pn("10 % 3");
  double res = pn.calculate(0);
  ASSERT_EQ(fmod(10, 3), res);
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
