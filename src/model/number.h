#ifndef NUMBER_H
#define NUMBER_H
#include <string>

class Number
{
public:
    Number() = delete;
    virtual void SetNumber() = 0;
    virtual std::string GetNumber() = 0;
};


class PNumbers : public Number {
public:
    void SetNumber() override;
    std::string GetNumber() override;
};

class FractionNumbers : public Number {
public:
    void SetNumber() override;
    std::string GetNumber() override;
};

class ComplexNumbers : public Number {
public:
    void SetNumber() override;
    std::string GetNumber() override;
};

#endif // NUMBER_H
