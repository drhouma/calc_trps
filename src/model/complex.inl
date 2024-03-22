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


inline ComplexNumber& ComplexNumber::operator=(const ComplexNumber &other) {
    if (this == &other) {
        return *this;
    }
    m_im = other.m_im;
    m_r = other.m_r;
    return *this;
}



inline ComplexNumber ComplexNumber::operator+(const ComplexNumber &other) {
    return ComplexNumber(other.m_r + m_r, other.m_im + m_im);
}

inline ComplexNumber ComplexNumber::operator-(const ComplexNumber &other) {
    return ComplexNumber(other.m_r - m_r, other.m_im - m_im);
}

inline ComplexNumber ComplexNumber::operator*(const ComplexNumber &other) {
    return ComplexNumber((other.m_r * m_r) + (other.m_im * m_im), (other.m_im * m_r) + (other.m_r * m_im));
}

inline ComplexNumber ComplexNumber::operator/(const ComplexNumber &other) {
    double real_part = (m_r * other.m_r + m_im * other.m_im) / (other.m_r * other.m_r + other.m_im * other.m_im);
    double imagine_part = (m_im * other.m_r - m_r * other.m_im) / (other.m_r * other.m_r + other.m_im * other.m_im);
    return ComplexNumber(real_part, imagine_part);
}

//    PNumber& pow(const PNumber &other);

inline ComplexNumber ComplexNumber::pow(const double power) {
    return FormulaMuavra(power);
}

inline double ComplexNumber::arg() {
    if (m_r > 0) {
        return std::atan(m_im / m_r);
    } else if (m_r < 0 && m_im >= 0) {
        return M_PI/2 + std::atan(m_im / m_r);
    } else if (m_r < 0 && m_im < 0) {
        return -M_PI/2 + std::atan(m_im / m_r);
    } else if (m_r == 0 && m_im > 0) {
        return M_PI/2;
    }
    return -M_PI/2;
}


inline ComplexNumber ComplexNumber::FormulaMuavra(const double power) {
    if (power > 0) {
        double modz = std::sqrt(std::pow(m_r + m_im, 2));
        double real_part = std::pow(modz, power) * cos(arg() * power);
        double im_part = std::pow(modz, power) * sin(arg() * power);
        return ComplexNumber(real_part, im_part);
    } else if (power < 0) {
        double modz = std::sqrt(std::pow(m_r + m_im, 2));
        double real_part = std::pow(modz, power) * cos(arg() / -power);
        double im_part = std::pow(modz, power) * sin(arg() / -power);
        return ComplexNumber(real_part, im_part);
    }
    return ComplexNumber(1, 0);
}

inline ComplexNumber ComplexNumber::sqrt() {
    return FormulaMuavra(-2);
}

inline std::string ComplexNumber::GetNumber() {
    return std::to_string(m_im) + " + " + std::to_string(m_r);
}
