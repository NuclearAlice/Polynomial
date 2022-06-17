/******************************************************
** File            :   Plynomial.cpp
** Date            :   2022/6/14
** This File contains class Polynomial methods
******************************************************/
#include <iostream>
#include "Temp.h"
#include "Polynomial.h"
#include <sstream>
using namespace std;

/*
 Constructor functions
 one gets a vector to create object
 and the other creates the object with out any parameters
*/
Polynomial::Polynomial(vector<Term> p)
{
    this->polynomial = p;
}
Polynomial::Polynomial() {}

/* Overloading [] operator functions
   gets a number as parameter
   which is index of wanted Term
*/
Term Polynomial::operator[](const int &index) const
{
    Term result;
    result = this->polynomial[index];
    return result;
}

/* Overloading [] operator functions
   gets a number as parameter
   which is index of wanted Term
*/
Term &Polynomial::operator[](const int &index)
{
    return this->polynomial[index];
}

/* sorts Term of a polynomial
   from biggest power to the least
   also delete zero Terms
    */
Polynomial &Polynomial::sortPoly()
{
    /*If there is Term with same power
    the result of Term will be kept
    and delete extra Term*/
    auto it = this->polynomial.begin();
    while (it != this->polynomial.end())
    {
        auto it2 = it + 1;
        while (it2 != this->polynomial.end())
        {
            if ((*it).getPower() == (*it2).getPower())
            {
                (*it).setCoefficient(((*it).getCoefficient()) + ((*it2).getCoefficient()));
                it2 = this->polynomial.erase(it2);
            }
            else
            {
                ++it2;
            }
        }
        ++it;
    }
    /*If there is a Term with zero coefficient
    it should be deleted so it does not get memory
    also size of terms is important
    so this will avoid possible errors*/
    it = this->polynomial.begin();
    while (it != this->polynomial.end())
    {
        if ((*it).getCoefficient() == 0)
        {
            it = this->polynomial.erase(it);
        }
        else
        {
            ++it;
        }
    }
    /*Now for the sorting part
    it sorts Term from which has the biggest power to the least
    it is important to sort it
    cause as an example degree of Polymonial will always belong to the first Term*/
    for (int i = 0; i < this->polynomial.size(); i++)
    {
        for (int j = i + 1; j < this->polynomial.size(); j++)
        {
            if (this->polynomial[i] < this->polynomial[j])
            {
                swap(this->polynomial[i], this->polynomial[j]);
            }
        }
    }
    return *this;
}

/* Overloading + operator functions
   Polynomial  + Polynomial
   Polynomial  + Term
   Term        + Polynomial
   Polynomial  + float
   float       + Polynomial
*/
Polynomial Polynomial::operator+(const Polynomial &p) const
{

    Term tResult;
    vector<Term> vResult;
    for (int i = 0; i < p.polynomial.size(); i++)
    {
        tResult = p.polynomial[i];
        vResult.push_back(tResult);
    }
    Polynomial result(vResult);
    result.sortPoly();
    for (int i = 0; i < this->polynomial.size(); i++)
    {

        tResult = this->polynomial[i];

        result.polynomial.push_back(tResult);
    }
    result.sortPoly();
    return result;
}
Polynomial Polynomial::operator+(const Term &t) const
{
    Term tResult;
    vector<Term> vResult;
    for (int i = 0; i < this->polynomial.size(); i++)
    {

        tResult = this->polynomial[i];
        vResult.push_back(tResult);
    }
    vResult.push_back(t);
    Polynomial result(vResult);
    result.sortPoly();
    return result;
}
Polynomial operator+(const Term &t, const Polynomial &p)
{
    Term tResult;
    vector<Term> vResult;
    for (int i = 0; i < p.polynomial.size(); i++)
    {

        tResult = p.polynomial[i];
        vResult.push_back(tResult);
    }
    vResult.push_back(t);
    Polynomial result(vResult);
    result.sortPoly();
    return result;
}
Polynomial Polynomial::operator+(const float &f) const
{
    Term tResult;
    vector<Term> vResult;
    for (int i = 0; i < this->polynomial.size(); i++)
    {

        tResult = this->polynomial[i];
        vResult.push_back(tResult);
    }
    tResult.setCoefficient(f);
    tResult.setPower(0);
    vResult.push_back(tResult);
    Polynomial result(vResult);
    result.sortPoly();
    return result;
}
Polynomial operator+(const float &f, const Polynomial &p)
{
    Term tResult;
    vector<Term> vResult;
    for (int i = 0; i < p.polynomial.size(); i++)
    {

        tResult = p.polynomial[i];
        vResult.push_back(tResult);
    }
    tResult.setCoefficient(f);
    tResult.setPower(0);
    vResult.push_back(tResult);
    Polynomial result(vResult);
    result.sortPoly();
    return result;
}

/* Overloading - operator functions
   Polynomial  - Polynomial
   Polynomial  - Term
   Term        - Polynomial
   Polynomial  - float
   float       - Polynomial
*/
Polynomial Polynomial::operator-(const Polynomial &p) const
{

    Term tResult;
    vector<Term> vResult;
    for (int i = 0; i < p.polynomial.size(); i++)
    {
        tResult = p.polynomial[i];

        vResult.push_back(tResult);
    }

    for (int i = 0; i < vResult.size(); i++)
    {
        vResult[i].setCoefficient((vResult[i].getCoefficient()) * (-1));
    }
    Polynomial result(vResult);
    result.sortPoly();
    for (int i = 0; i < this->polynomial.size(); i++)
    {
        tResult = this->polynomial[i];
        result.polynomial.push_back(tResult);
    }
    result.sortPoly();
    return result;
}
Polynomial Polynomial::operator-(const Term &t) const
{
    Term tResult;
    vector<Term> vResult;
    for (int i = 0; i < this->polynomial.size(); i++)
    {

        tResult = this->polynomial[i];
        vResult.push_back(tResult);
    }
    tResult.setCoefficient((-1) * (t.getCoefficient()));
    tResult.setPower(t.getPower());
    vResult.push_back(tResult);
    Polynomial result(vResult);
    result.sortPoly();
    return result;
}
Polynomial operator-(const Term &t, const Polynomial &p)
{
    Term tResult;
    vector<Term> vResult;
    for (int i = 0; i < p.polynomial.size(); i++)
    {

        tResult.setCoefficient((-1) * (p.polynomial[i].getCoefficient()));
        tResult.setPower(p.polynomial[i].getPower());
        vResult.push_back(tResult);
    }
    vResult.push_back(t);
    Polynomial result(vResult);
    result.sortPoly();
    return result;
}
Polynomial Polynomial::operator-(const float &f) const
{
    Term tResult;
    vector<Term> vResult;
    for (int i = 0; i < this->polynomial.size(); i++)
    {

        tResult = this->polynomial[i];
        vResult.push_back(tResult);
    }
    tResult.setCoefficient((-1) * (f));
    tResult.setPower(0);
    vResult.push_back(tResult);
    Polynomial result(vResult);
    result.sortPoly();
    return result;
}
Polynomial operator-(const float &f, const Polynomial &p)
{
    Term tResult;
    vector<Term> vResult;
    for (int i = 0; i < p.polynomial.size(); i++)
    {

        tResult.setCoefficient((-1) * (p.polynomial[i].getCoefficient()));
        tResult.setPower(p.polynomial[i].getPower());
        vResult.push_back(tResult);
    }
    tResult.setCoefficient(f);
    tResult.setPower(0);
    vResult.push_back(tResult);
    Polynomial result(vResult);
    result.sortPoly();
    return result;
}

/* Overloading * operator functions
   Polynomial  * Polynomial
   Polynomial  * Term
   Term        * Polynomial
   Polynomial  * float
   float       * Polynomial
*/
Polynomial Polynomial::operator*(const Polynomial &p) const
{
    Term tResult;
    vector<Term> vResult;
    for (int i = 0; i < this->polynomial.size(); i++)
    {
        for (int j = 0; j < p.polynomial.size(); j++)
        {
            tResult = (this->polynomial[i]) * (p.polynomial[j]);
            vResult.push_back(tResult);
        }
    }
    Polynomial result(vResult);
    result.sortPoly();
    return result;
}
Polynomial Polynomial::operator*(const Term &t) const
{
    Term tResult;
    vector<Term> vResult;
    for (int i = 0; i < this->polynomial.size(); i++)
    {
        tResult = (this->polynomial[i]) * (t);
        vResult.push_back(tResult);
    }
    Polynomial result(vResult);
    result.sortPoly();
    return result;
}
Polynomial operator*(const Term &t, const Polynomial &p)
{
    Term tResult;
    vector<Term> vResult;
    for (int i = 0; i < p.polynomial.size(); i++)
    {
        tResult = (p.polynomial[i]) * (t);
        vResult.push_back(tResult);
    }
    Polynomial result(vResult);
    result.sortPoly();
    return result;
}
Polynomial Polynomial::operator*(const float &f) const
{
    Term tResult, t;
    vector<Term> vResult;
    t.setCoefficient(f);
    t.setPower(0);
    for (int i = 0; i < this->polynomial.size(); i++)
    {

        tResult = (this->polynomial[i]) * (t);
        vResult.push_back(tResult);
    }
    Polynomial result(vResult);
    result.sortPoly();
    return result;
}
Polynomial operator*(const float &f, const Polynomial &p)
{
    Term tResult, t;
    vector<Term> vResult;
    t.setCoefficient(f);
    t.setPower(0);
    for (int i = 0; i < p.polynomial.size(); i++)
    {
        tResult = (p.polynomial[i]) * (t);
        vResult.push_back(tResult);
    }

    Polynomial result(vResult);
    result.sortPoly();
    return result;
}

/* Overloading += operator function
   Polynomial  += Polynomial
*/
Polynomial &Polynomial::operator+=(const Polynomial &p)
{
    for (int i = 0; i < p.polynomial.size(); i++)
    {
        this->polynomial.push_back(p.polynomial[i]);
    }
    this->sortPoly();
    return *this;
}

/* Overloading -= operator function
   Polynomial  -= Polynomial
*/
Polynomial &Polynomial::operator-=(const Polynomial &p)
{
    Term tmp;
    for (int i = 0; i < p.polynomial.size(); i++)
    {
        tmp = p.polynomial[i];
        tmp.setCoefficient((-1) * (tmp.getCoefficient()));
        this->polynomial.push_back(tmp);
    }
    this->sortPoly();
    return *this;
}

/* Overloading *= operator function
   Polynomial  *= Polynomial
*/
Polynomial &Polynomial::operator*=(const Polynomial &p)
{
    Term tmp;
    for (int i = 0; i < p.polynomial.size(); i++)
    {
        tmp = p.polynomial[i];
        tmp.setCoefficient((-1) * (tmp.getCoefficient()));
        this->polynomial.push_back(tmp);
    }
    this->sortPoly();
    return *this;
}

/* Overloading = operator function
   Polynomial  = Polynomial
*/
Polynomial &Polynomial::operator=(const Polynomial &p)
{
    this->polynomial = p.polynomial;
    return *this;
}

/* Overloading > operator function
   Polynomial  > Polynomial
*/
bool Polynomial::operator>(const Polynomial &p) const
{
    int minSize = (this->polynomial.size() < p.polynomial.size()) ? this->polynomial.size() : p.polynomial.size();
    char ch = (this->polynomial.size() < p.polynomial.size()) ? 'p' : 't';
    for (int i = 0; i < minSize;)
    {
        if (this->polynomial[i] > p.polynomial[i])
        {
            return true;
        }
        else if (this->polynomial[i] < p.polynomial[i])
        {
            return false;
        }
        else if (this->polynomial[i] == p.polynomial[i])
        {
            i++;
        }
    }
    vector<Term> maxVector = (this->polynomial.size() > p.polynomial.size()) ? this->polynomial : p.polynomial;
    if (ch == 't')
    {
        if (maxVector[minSize] > 0)
        {
            return true;
        }

        return false;
    }
    else
    {
        if (maxVector[minSize] > 0)
        {
            return false;
        }

        return true;
    }
    return 0;
}

/* Overloading < operator functions
   Polynomial  < Polynomial
   Polynomial  < Term
   Polynomial  > Term
   Term        < Polynomial
   Term        > Polynomial
   Polynomial  < float
   Polynomial  > float
   float       < Polynomial
   float       > Polynomial
*/
bool Polynomial::operator<(const Polynomial &p) const
{
    if (*this == p)
    {
        return false;
    }
    if (*this > p)
    {
        return false;
    }
    return true;
}
bool Polynomial::operator<(const Term &t) const
{
    vector<Term> vResult;
    vResult.push_back(t);
    Polynomial p(vResult);
    if (*this < p)
    {
        return true;
    }
    return false;
}
bool Polynomial::operator>(const Term &t) const
{
    vector<Term> vResult;
    vResult.push_back(t);
    Polynomial p(vResult);
    if (*this > p)
    {
        return true;
    }
    return false;
}
bool operator<(const Term &t, const Polynomial &p)
{
    vector<Term> vResult;
    vResult.push_back(t);
    Polynomial p2(vResult);
    if (p2 < p)
    {
        return true;
    }
    return false;
}
bool operator>(const Term &t, const Polynomial &p)
{
    vector<Term> vResult;
    vResult.push_back(t);
    Polynomial p2(vResult);
    if (p2 > p)
    {
        return true;
    }
    return false;
}
bool Polynomial::operator<(const float &f) const
{
    Term t;
    t.setCoefficient(f);
    t.setPower(0);
    vector<Term> vResult;
    vResult.push_back(t);
    Polynomial p(vResult);
    if (*this < p)
    {
        return true;
    }
    return false;
}
bool Polynomial::operator>(const float &f) const
{
    Term t;
    t.setCoefficient(f);
    t.setPower(0);
    vector<Term> vResult;
    vResult.push_back(t);
    Polynomial p(vResult);
    if (*this > p)
    {
        return true;
    }
    return false;
}
bool operator<(const float &f, const Polynomial &p)
{
    Term t;
    t.setCoefficient(f);
    t.setPower(0);
    vector<Term> vResult;
    vResult.push_back(t);
    Polynomial p2(vResult);
    if (p2 < p)
    {
        return true;
    }
    return false;
}
bool operator>(const float &f, const Polynomial &p)
{
    Term t;
    t.setCoefficient(f);
    t.setPower(0);
    vector<Term> vResult;
    vResult.push_back(t);
    Polynomial p2(vResult);
    if (p2 > p)
    {
        return true;
    }
    return false;
}
/* Overloading == operator functions
   Polynomial  == Polynomial
   Polynomial  == Term
   Term        == Polynomial
   Polynomial  == float
   float       == Polynomial
*/
bool Polynomial::operator==(const Polynomial &p) const
{
    // this->sortPoly();
    // p.sortPoly();
    if (this->polynomial.size() != p.polynomial.size())
    {
        return false;
    }
    for (int i = 0; i < this->polynomial.size(); i++)
    {
        if (this->polynomial[i] != p.polynomial[i])
        {
            return false;
        }
    }
    return true;
}

bool Polynomial::operator==(const Term &t) const
{
    if (this->getSize() == 1)
    {
        if (this->polynomial[0] == t)
        {
            return true;
        }
    }
    return false;
}
bool operator==(const Term &t, const Polynomial &p)
{
    if (p == t)
    {
        return true;
    }
    return false;
}
bool Polynomial::operator==(const float &f) const
{
    Term t;
    t.setCoefficient(f);
    t.setPower(0);
    if (*this == t)
    {
        return true;
    }
    return false;
}
bool operator==(const float &f, const Polynomial &p)
{
    if (p == f)
    {
        return true;
    }
    return false;
}

/* Overloading <= operator functions
   Polynomial  <= Polynomial
   Polynomial  <= Term
   Term        <= Polynomial
   Polynomial  <= float
   float       <= Polynomial
*/
bool Polynomial::operator<=(const Polynomial &p) const
{
    return {!(*this > p)};
}
bool Polynomial::operator<=(const Term &t) const
{
    return {!(*this > t)};
}
bool operator<=(const Term &t, const Polynomial &p)
{
    return {!(t > p)};
}
bool Polynomial::operator<=(const float &f) const
{
    return {!(*this > f)};
}
bool operator<=(const float &f, const Polynomial &p)
{
    return {!(f > p)};
}

/* Overloading >= operator functions
   Polynomial  >= Polynomial
   Polynomial  >= Term
   Term        >= Polynomial
   Polynomial  >= float
   float       >= Polynomial
*/
bool Polynomial::operator>=(const Polynomial &p) const
{
    return {!(*this < p)};
}
bool Polynomial::operator>=(const Term &t) const
{
    return {!(*this < t)};
}
bool operator>=(const Term &t, const Polynomial &p)
{
    return {!(t < p)};
}
bool Polynomial::operator>=(const float &f) const
{
    return {!(*this < f)};
}
bool operator>=(const float &f, const Polynomial &p)
{
    return {!(f < p)};
}

/* Overloading != operator functions
   Polynomial  != Polynomial
   Polynomial  != Term
   Term        != Polynomial
   Polynomial  != float
   float       != Polynomial
*/
bool Polynomial::operator!=(const Polynomial &p) const
{
    return {!(*this == p)};
}

bool Polynomial::operator!=(const Term &t) const
{
    if (*this == t)
    {
        return false;
    }
    return true;
}
bool operator!=(const Term &t, const Polynomial &p)
{
    if (p == t)
    {
        return false;
    }
    return true;
}
bool Polynomial::operator!=(const float &f) const
{
    if (*this == f)
    {
        return false;
    }
    return true;
}
bool operator!=(const float &f, const Polynomial &p)
{
    if (p == f)
    {
        return false;
    }
    return true;
}

/* Overloading ~ operator function
   calculates Derivative of Polynomail
*/
Polynomial Polynomial::operator~() const
{
    vector<Term> vResult;
    for (int i = 0; i < this->polynomial.size(); i++)
    {
        vResult.push_back(~(this->polynomial[i]));
    }
    Polynomial result(vResult);
    result.sortPoly();
    return result;
}

/* Overloading ++ operator function
   pre increment
   ++Polynomial
*/
Polynomial &Polynomial::operator++()
{
    Term t;
    t.setCoefficient(1);
    t.setPower(0);
    this->polynomial.push_back(t);
    this->sortPoly();
    return *this;
}

/* Overloading ++ operator function
   post increment
   Polynomial++
*/
Polynomial Polynomial::operator++(int)
{
    Term t;
    t.setCoefficient(1);
    t.setPower(0);
    Polynomial copy(*this);
    this->polynomial.push_back(t);
    this->sortPoly();
    return copy;
}

/* Overloading -- operator function
   pre deccrement
   --Polynomial
*/
Polynomial &Polynomial::operator--()
{
    Term t;
    t.setCoefficient(-1);
    t.setPower(0);
    this->polynomial.push_back(t);
    this->sortPoly();
    return *this;
}

/* Overloading -- operator function
   post deccrement
   Polynomial--
*/
Polynomial Polynomial::operator--(int)
{
    Term t;
    t.setCoefficient(-1);
    t.setPower(0);
    Polynomial copy(*this);
    this->polynomial.push_back(t);
    this->sortPoly();
    return copy;
}

/* Overloading () operator function
   takes a float number as parameter
   and calculate the value of Polynomial per that number
*/
float Polynomial::operator()(float num)
{
    float result = 0;
    for (int i = 0; i < this->polynomial.size(); i++)
    {
        result += (this->polynomial[i](num));
    }
    return result;
}

/* This function get 2 index and a string as parameters
   and re turn the string between those two index
*/
string copyStringByIndex(int firstIndex, int lastIndex, string myStr)
{
    string result; // The string which we are looking for

    /*Copty the characters between these two index to result*/
    for (int i = firstIndex; i <= lastIndex; i++)
    {
        result.push_back(myStr[i]);
    }
    return result;
}

/* This function gets a string as parameter
   and turn it to Polynomial and returns it
*/
Polynomial divideStringIntoPolynomial(string inputTerm)
{
    string tmpString;   // Temporary string we use to get parts of our string
    Term tmpTerm;       // Temporary string which hold each Term we get from string
    vector<Term> terms; // Vector of Term which we give to our result Polynomial
    int firstIndex = 0; // The first index that indicate first part of Term
    int lastIndex = 0;  // The last index that indicate last part of Term

    /*Finding the first Term by finding the next Term 's sign
    if no sign found only means there is one Term*/
    for (int i = lastIndex + 1; i < inputTerm.size(); i++)
    {
        if ((inputTerm[i] == '+' || inputTerm[i] == '-') && (inputTerm[i - 1] != '^'))
        {
            /*Where ever find the sign stop the loop*/
            lastIndex = i - 1;
            break;
        }
        else
        {
            /*Term is incompelete
            increase the last index of Term*/
            lastIndex = i;
        }
    }

    /*Now that we got first Term last index
    we give the position to our function
    to fing the string holds only this Term
    */
    tmpString = copyStringByIndex(firstIndex, lastIndex, inputTerm);

    /*Turn this founded string to Term*/
    divideStringIntoTerm(tmpString, tmpTerm);

    /*Give the first Term to vector*/
    terms.push_back(tmpTerm);

    /*Increase the last and first index
    now first index shows the sign of the next Term*/
    firstIndex = (++lastIndex);

    /*A loop to find our other Temps*/
    for (int i = lastIndex + 1; i < inputTerm.size(); i++)
    {
        if ((inputTerm[i] == '+' || inputTerm[i] == '-') && (inputTerm[i - 1] != '^'))
        {
            /*Where ever find sign put the last index to one position befor that
            thats where new Term Ends
            Then Turn this founded part to Term
            and add it to the vector that holds Terms
            put the first index on the sign founded*/
            lastIndex = i - 1;
            tmpString = copyStringByIndex(firstIndex, lastIndex, inputTerm);
            divideStringIntoTerm(tmpString, tmpTerm);
            terms.push_back(tmpTerm);
            firstIndex = (++lastIndex);
        }
    }
    /*This if clause is to see if our Term are over in the loop or there is one left?*/
    if (lastIndex != inputTerm.size())
    {
        /*this is the last Term*/
        tmpString = copyStringByIndex(firstIndex, inputTerm.size() - 1, inputTerm);
        divideStringIntoTerm(tmpString, tmpTerm);
        terms.push_back(tmpTerm);
    }

    /*Create our Polynomial with our vector and return it*/
    Polynomial p(terms);
    p.sortPoly();
    return p;
}

/*This function is to check all possible errors that we get when entering a Polynomial*/
void checkMyStringToSeeIfThereIsSomthingWrong(string t)
{
    /*String got from input can not strart with sign of power*/
    if (t[0] == '^')
    {
        throw 12;
    }

    for (int i = 0; i < t.size(); i++)
    {
        /*The only characters that are alowed are shown below
          all remain one ,
          if found in string means input is invalid*/
        if (!(t[i] == '1' || t[i] == '2' || t[i] == '3' || t[i] == '4' || t[i] == '5' || t[i] == '6' || t[i] == '7' || t[i] == '8' || t[i] == '9' || t[i] == '0' || t[i] == 'x' || t[i] == '^' || t[i] == '+' || t[i] == '-'))
        {
            throw 13;
        }

        /*All these errors are explained in their exeption function
        from there you can see why these are not allowed*/
        if (t[i] == '^' && t[i - 1] != 'x')
        {
            throw 14;
        }
        if ((t[i] == '^') && (i == t.size() - 1))
        {
            throw 17;
        }
        if (t[i] == '+' || t[i] == '-')
        {
            if ((i > 0) && (i < t.size() - 1))
            {
                if ((t[i + 1] == '+') || (t[i - 1] == '+') || (t[i + 1] == '-') || (t[i - 1] == '-'))
                    throw 15;
            }
            if (i == t.size() - 1)
            {
                throw 16;
            }
        }
    }
}

/* Overloading >> operator function
   this function takes a Polynomial as parameter
   basically gets a Polynomial from input
*/
istream &operator>>(istream &in, Polynomial &p)
{
    string inputTerm;

    getline(in, inputTerm);
    checkMyStringToSeeIfThereIsSomthingWrong(inputTerm);
    p = divideStringIntoPolynomial(inputTerm);
    return in;
}

/*Finds degree of Polynomial*/
int Polynomial::degPoly()
{
    this->sortPoly();
    if (this->getSize() == 0)
    {
        return 0;
    }
    else
    {
        return this->polynomial[0].getPower();
    }
}

/* Overloading << operator function
   this function takes a Polynomial as parameter
   and prints it on output
*/
ostream &operator<<(ostream &out, const Polynomial &p)
{
    if (p.polynomial.size() == 0)
    {
        out << '0';
    }
    for (int i = 0; i < p.polynomial.size(); i++)
    {
        if (i == 0)
        {
            out << p.polynomial[i];
        }
        else if (p.polynomial[i].getCoefficient() > 0)
        {
            out << '+' << p.polynomial[i];
        }
        else
        {
            out << p.polynomial[i];
        }
    }

    return out;
}
