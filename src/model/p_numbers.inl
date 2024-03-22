#ifndef P_NUMBER_INL
#define P_NUMBER_INL
#include "number.h"

inline PNumber::PNumber(unsigned accuracy, double number) :
    m_accuracy(accuracy), m_number(number){
    // cut number to given accuracy
}


inline void PNumber::SetNumber(const std::string& str) {
    // str must be in this format:
    // accuracy (str-integer) number (str-float)
    int res = sscanf(str.c_str(), "%i %lf", &m_accuracy, &m_number);
    if (res == 0 || res == 1) {
        // error
    }
}



inline PNumber& PNumber::operator=(const PNumber &other) {
    if (this == &other) {
        return *this;
    }
    m_number = other.m_number;
    return *this;
}


inline PNumber PNumber::operator+(const PNumber &other) {
    return PNumber(std::min(m_accuracy, other.m_accuracy), m_number + other.m_number);
}

inline PNumber PNumber::operator-(const PNumber &other) {
    return PNumber(std::min(m_accuracy, other.m_accuracy), m_number + other.m_number);
}

inline PNumber PNumber::operator*(const PNumber &other) {
    return PNumber(std::min(m_accuracy, other.m_accuracy), m_number + other.m_number);
}

inline PNumber PNumber::operator/(const PNumber &other) {
    return PNumber(std::min(m_accuracy, other.m_accuracy), m_number + other.m_number);
}

//    PNumber& PNumber::pow(const PNumber &other);

inline PNumber PNumber::pow(const double power) {
    return PNumber(m_accuracy, std::pow(m_number, power));
}

inline PNumber PNumber::sqrt() {
    return PNumber(m_accuracy, std::sqrt(m_number));
}

inline std::string PNumber::GetNumber() {
    return std::to_string(m_number);
}

#endif
