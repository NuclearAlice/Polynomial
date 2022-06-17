/******************************************************
** File            :   Plynomial.h
** Date            :   2022/6/14
** This File contains class  Polynomial
******************************************************/

#pragma once
#include <iostream>
#include <vector>
#include "Temp.h"
using namespace std;

/* Class Polynomial declaration:*/
class Polynomial
{
public:
    /* Constructor functions
    one gets a vector to create object
    and the other creates the object with out any parameters
    */
    Polynomial(vector<Term>);
    Polynomial();

    /* This function returns polynomial vector size
    useful when size is needed outside of class
    but our vector is private
    */
    int getSize() const { return polynomial.size(); }

    /* show degree of polynomial*/
    int degPoly();

    /*sorts Term of a polynomial
    from biggest power to the least
    it also has other useful advantegers
    */
    Polynomial &sortPoly();

    /* Operator overloadings*/

    Polynomial operator+(const Polynomial &) const;                 // Polynomial + Polynomial
    Polynomial operator+(const Term &) const;                       // Polynomial + Term
    friend Polynomial operator+(const Term &, const Polynomial &);  // Term       + Polynomial
    Polynomial operator+(const float &) const;                      // Polynomial + float
    friend Polynomial operator+(const float &, const Polynomial &); // float      + Polynomial

    Polynomial operator-(const Polynomial &) const;                 // Polynomial - Polynomial
    Polynomial operator-(const Term &) const;                       // Polynomial - Term
    friend Polynomial operator-(const Term &, const Polynomial &);  // Term       - Polynomial
    Polynomial operator-(const float &) const;                      // Polynomial - float
    friend Polynomial operator-(const float &, const Polynomial &); // float      - Polynomial

    Polynomial operator*(const Polynomial &) const;                 // Polynomial * Polynomial
    Polynomial operator*(const Term &) const;                       // Polynomial * Term
    friend Polynomial operator*(const Term &, const Polynomial &);  // Term       * Polynomial
    Polynomial operator*(const float &) const;                      // Polynomial * float
    friend Polynomial operator*(const float &, const Polynomial &); // float      * Polynomial

    Polynomial &operator+=(const Polynomial &); // Polynomial += Polynomial

    Polynomial &operator-=(const Polynomial &); // Polynomial -= Polynomial

    Polynomial &operator*=(const Polynomial &); // Polynomial *= Polynomial

    Polynomial &operator=(const Polynomial &); // Polynomial = Polynomial

    bool operator>(const Polynomial &) const;                 // Polynomial > Polynomial
    bool operator>(const Term &) const;                       // Polynomial > Term
    friend bool operator>(const Term &, const Polynomial &);  // Term       > Polynomial
    bool operator>(const float &) const;                      // Polynomial > float
    friend bool operator>(const float &, const Polynomial &); // float      > Polynomial

    bool operator<(const Polynomial &) const;                 // Polynomial < Polynomial
    bool operator<(const Term &) const;                       // Polynomial < Term
    friend bool operator<(const Term &, const Polynomial &);  // Term       < Polynomial
    bool operator<(const float &) const;                      // Polynomial < float
    friend bool operator<(const float &, const Polynomial &); // float      < Polynomial

    bool operator>=(const Polynomial &) const;                 // Polynomial >= Polynomial
    bool operator>=(const Term &) const;                       // Polynomial >= Term
    friend bool operator>=(const Term &, const Polynomial &);  // Term       >= Polynomial
    bool operator>=(const float &) const;                      // Polynomial >= float
    friend bool operator>=(const float &, const Polynomial &); // float      >= Polynomial

    bool operator<=(const Polynomial &) const;                 // Polynomial <= Polynomial
    bool operator<=(const Term &) const;                       // Polynomial <= Term
    friend bool operator<=(const Term &, const Polynomial &);  // Term       <= Polynomial
    bool operator<=(const float &) const;                      // Polynomial <= float
    friend bool operator<=(const float &, const Polynomial &); // float      <= Polynomial

    bool operator==(const Polynomial &) const;                 // Polynomial == Polynomial
    bool operator==(const Term &) const;                       // Polynomial == Term
    friend bool operator==(const Term &, const Polynomial &);  // Term       == Polynomial
    bool operator==(const float &) const;                      // Polynomial == float
    friend bool operator==(const float &, const Polynomial &); // float      == Polynomial

    bool operator!=(const Polynomial &) const;                 // Polynomial != Polynomial
    bool operator!=(const Term &) const;                       // Polynomial != Term
    friend bool operator!=(const Term &, const Polynomial &);  // Term       != Polynomial
    bool operator!=(const float &) const;                      // Polynomial != float
    friend bool operator!=(const float &, const Polynomial &); // float      != Polynomial

    Polynomial operator~() const; // Derivative of Polynomial

    Polynomial &operator++();   // ++Polynomial
    Polynomial operator++(int); // Polynomial++

    Polynomial &operator--();   //--Polynomial
    Polynomial operator--(int); // Polynomial--

    float operator()(float); // The value of Polynomial per a number

    Term operator[](const int &) const; // Wanted Term by given index
    Term &operator[](const int &);      // Wanted Term by given index

    friend ostream &operator<<(ostream &, const Polynomial &); // Output
    friend istream &operator>>(istream &, Polynomial &);       // Input

    int s; // Useful in reading binary file

private:
    vector<Term> polynomial; // vector of Term
};