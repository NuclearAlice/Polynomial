/******************************************************
** File            :   Temp.h
** Date            :   2022/6/14
** This File contains class Temp
******************************************************/

#pragma once
#include <iostream>
using namespace std;

/* Class Temp declaration:*/
class Term
{
public:
    /* Setter functions : take a number as parameter and put its value into coefficient and power*/
    void setCoefficient(float);
    void setPower(int);

    /* Getter inline functions : return the value of coefficient and power*/
    float getCoefficient() const { return coefficient; }
    int getPower() const { return power; }

    /* Operator overloadings*/

    Term operator+(const Term &) const;                 // Temp  + Temp
    Term operator+(const float &f) const;               // Temp  + float
    friend Term operator+(const float &, const Term &); // float + Term

    Term operator-(const Term &) const;                 // Term   - Term
    Term operator-(const float &f) const;               // Term   - float
    friend Term operator-(const float &, const Term &); // float  - Temp

    Term operator*(const Term &) const;                 // Term   * Term
    Term operator*(const float &f) const;               // Term   * float
    friend Term operator*(const float &, const Term &); // float  * Temp

    Term operator/(const Term &) const;                 // Term   / Term
    Term operator/(const float &f) const;               // Term   / float
    friend Term operator*(const float &, const Term &); // float  / Temp

    Term &operator+=(const Term &); // Term += Term

    Term &operator-=(const Term &); // Term -= Term

    Term &operator*=(const Term &); // Term *= Term

    Term &operator/=(const Term &); // Term /= Term

    Term &operator=(const Term &); // Term  = Term

    bool operator>(const Term &) const;                 // Term   > Term
    bool operator>(const float &f) const;               // Term   > float
    friend bool operator>(const float &, const Term &); // float  > Temp

    bool operator<(const Term &) const;                 // Term   < Term
    bool operator<(const float &f) const;               // Term   > float
    friend bool operator<(const float &, const Term &); // float  > Temp

    bool operator>=(const Term &) const;                 // Term  >= Term
    bool operator>=(const float &f) const;               // Term  >= float
    friend bool operator>=(const float &, const Term &); // float >= Temp

    bool operator<=(const Term &) const;                 // Term  <= Term
    bool operator<=(const float &f) const;               // Term  <= float
    friend bool operator>=(const float &, const Term &); // float <= Temp

    bool operator==(const Term &) const;                 // Term  == Term
    bool operator==(const float &f) const;               // Term  == float
    friend bool operator==(const float &, const Term &); // float == Temp

    bool operator!=(const Term &) const;                 // Term  != Term
    bool operator!=(const float &f) const;               // Term  != float
    friend bool operator!=(const float &, const Term &); // float != Temp

    Term operator~() const; // Derivative of Term

    Term &operator++();   // ++Term
    Term operator++(int); // Term++

    Term &operator--();   //--Term
    Term operator--(int); // Term--

    float operator()(float); // The value of Term per a number

    friend ostream &operator<<(ostream &, const Term &); // Output Term
    friend istream &operator>>(istream &, Term &);       // Input Term

private:
    float coefficient; //[12]x^2
    int power;         // 12x^[2]
};

void divideStringIntoTerm(string inputTerm, Term &t);