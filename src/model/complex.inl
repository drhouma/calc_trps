#include "number.h"


ComplexNumber::ComplexNumber(const double r, const double im) :
    m_r(r), m_im(im) {

}


void ComplexNumber::SetNumber(const std::string& str) {
    // str must be in this format:
    // real part(str-float) imagine part(str-float)
    int res = sscanf(str.c_str(), "%lf %lf", &m_r, &m_im);
    if (res == 0 || res == 1) {
        // error
    }
}
