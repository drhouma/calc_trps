#ifndef P_NUMBER_INL
#define P_NUMBER_INL
#include "number.h"

PNumber::PNumber(unsigned accuracy, double number) :
    m_accuracy(accuracy), m_number(number){
    // cut number to given accuracy
}


void PNumber::SetNumber(const std::string& str) {
    // str must be in this format:
    // accuracy (str-integer) number (str-float)
    int res = sscanf(str.c_str(), "%i %lf", &m_accuracy, &m_number);
    if (res == 0 || res == 1) {
        // error
    }
}

#endif