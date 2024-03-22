#ifndef NUMBER_H
#define NUMBER_H
#include <string>
#include <cmath>
#include <iostream>
#include <sstream>

// операторы + , -, *, /, pow, sqrt
// get/set Number(std::stirng)


template <class T>
class Number {
private:
    T m_number;
public:
    Number(const T &number) {
        m_number = number;
    }

    Number() = delete;

    Number& operator=(const Number &other) {
        //проверка на самоприсваивание
        if (this == &other) {
            return *this;
        }
        m_number = other.m_number;
        return *this;
    }

    Number operator+(const Number &other) {
        return Number(m_number + other.m_number);
    }

    Number operator-(const Number &other) {
        return Number(m_number - other.m_number);
    }

    Number operator*(const Number &other) {
        return Number(m_number * other.m_number);
    }

    Number operator/(const Number &other) {
        return Number(m_number / other.m_number);
    }

    Number pow(const double power) {
        return Number(m_number.pow(power));
    }

    Number sqrt(const double power) {
        return Number(m_number.sqrt(power));
    }

    std::string GetNumber() {
        return m_number.GetNumber();
    }
};

class PNumber {
private:
    int m_accuracy{0};
    double m_number{0};

public:
    inline PNumber(unsigned accuracy, double number);
    inline void SetNumber(const std::string &str);

    inline PNumber& operator=(const PNumber &other);


    inline PNumber operator+(const PNumber &other);

    inline PNumber operator-(const PNumber &other);

    inline PNumber operator*(const PNumber &other);

    inline PNumber operator/(const PNumber &other);

//    PNumber& pow(const PNumber &other);

    inline PNumber pow(const double power);

    inline PNumber sqrt();

    inline std::string GetNumber();
};

class FractionNumber{

private:
    int m_numenator{0};
    int m_denumenator{0};

    inline FractionNumber ToCommonDivisor(const FractionNumber &other);
    inline FractionNumber ReduceNumenators();

public:
    FractionNumber() {}
    inline FractionNumber(const int numenator, const int denumenator);
    inline void SetNumber(const std::string &str);
    inline std::string GetNumber();

    inline FractionNumber& operator=(const FractionNumber &other);


    inline FractionNumber operator+(const FractionNumber &other);

    inline FractionNumber operator-(const FractionNumber &other);

    inline FractionNumber operator*(const FractionNumber &other);

    inline FractionNumber operator/(const FractionNumber &other);

//    PNumber& pow(const PNumber &other);

    inline FractionNumber pow(const double power);

    inline FractionNumber sqrt();

    inline void print();
};

class ComplexNumber{
private:
    double m_r{0};
    double m_im{0};
public:
    ComplexNumber(const double r, const double im);
    void SetNumber(const std::string &str);
    std::string GetNumber();

    inline ComplexNumber& operator=(const ComplexNumber &other);


    inline ComplexNumber operator+(const ComplexNumber &other);

    inline ComplexNumber operator-(const ComplexNumber &other);

    inline ComplexNumber operator*(const ComplexNumber &other);

    inline ComplexNumber operator/(const ComplexNumber &other);

//    PNumber& pow(const PNumber &other);

    inline ComplexNumber pow(const double power);

    // returns argument of complex number
    inline double arg();

    inline ComplexNumber FormulaMuavra(const double power);
    inline ComplexNumber FormulaMuavra(const ComplexNumber& power);
    inline ComplexNumber sqrt();

};
inline int NOD(int n1, int n2);
inline int NOK(int n1, int n2);

#endif // NUMBER_H
#include "fraction.inl"
