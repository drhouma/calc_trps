#ifndef FRACTION_H
#define FRACTION_H
#include "number.h"


inline FractionNumber::FractionNumber(const int numenator, const int denumenator) :
    m_numenator(numenator), m_denumenator(denumenator) {
    if (denumenator == 0) {
        // throw error
        // or nan
    }
}

inline FractionNumber& FractionNumber::operator=(const FractionNumber &other) {
    //проверка на самоприсваивание
    if (this == &other) {
        return *this;
    }
    m_denumenator = other.m_denumenator;
    m_numenator = other.m_numenator;
    return *this;
}

inline FractionNumber FractionNumber::operator+(const FractionNumber &other) {
    FractionNumber tmp = ToCommonDivisor(other);
    auto res = FractionNumber(m_numenator + tmp.m_numenator, m_denumenator).ReduceNumenators();
    this->ReduceNumenators();
    return res;
};

FractionNumber FractionNumber::operator-(const FractionNumber &other) {
    FractionNumber tmp = ToCommonDivisor(other);
    return FractionNumber(m_numenator - tmp.m_numenator, m_denumenator).ReduceNumenators();
};

FractionNumber FractionNumber::operator*(const FractionNumber &other) {
    return FractionNumber(m_numenator * other.m_numenator, m_denumenator * other.m_denumenator).ReduceNumenators();
};

FractionNumber FractionNumber::operator/(const FractionNumber &other) {
    return FractionNumber(m_numenator * other.m_denumenator, m_denumenator * other.m_numenator).ReduceNumenators();
}

//    PNumber& pow(const PNumber &other);

FractionNumber FractionNumber::pow(const double power) {
    return FractionNumber(std::pow(m_numenator, power), std::pow(m_denumenator, power));
};

FractionNumber FractionNumber::sqrt() {
    return FractionNumber(std::ceil(std::sqrt(m_numenator)), std::ceil(std::sqrt(m_denumenator)));
}

FractionNumber FractionNumber::ToCommonDivisor(const FractionNumber& other) {
    if (other.m_denumenator == m_denumenator) {
        return other;
    }
    FractionNumber help(other.m_numenator, other.m_denumenator);
    int help2 = other.m_denumenator;
    help.m_denumenator *= m_denumenator;
    help.m_numenator *= m_denumenator;
    m_numenator *= help2;
    m_denumenator *= help2;
    return help;
}

// Наибольший общий делитель
inline int NOD(int n1, int n2)
{
  int div;
  if (n1 == n2)  return n1;
  int d = n1 - n2;
  if (d < 0) {
    d = -d;
    div = NOD(n1, d);
  }
  else
    div = NOD(n2, d);
  return div;
}

// Наименьшее общее кратное
inline int NOK(int n1, int n2)
{
  return n1*n2 / NOD(n1, n2);
}

FractionNumber FractionNumber::ReduceNumenators() {
     int n = 0;
     while (n != 1) {
         n = NOD(m_numenator, m_denumenator);
         if (n == 0) {
             exit(0);// return error
         }
         if (n == 1) {
             return *this;
         }
         m_numenator /= n;
         m_denumenator /= n;
     }
    return *this;
}


inline void FractionNumber::print() {
    std::cout << m_numenator << '/' << m_denumenator << '\n';
}

void FractionNumber::SetNumber(const std::string& str) {
    // str must be in this format:
    // numen(str-integer) denumen(str-integer)
    int res = sscanf(str.c_str(), "%i %i", &m_numenator, &m_denumenator);
    if (res == 0 || res == 1) {
        // error
    }
}

#endif
