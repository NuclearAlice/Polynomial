/******************************************************
** File            :   Temp.cpp
** Date            :   2022/6/14
** This File contains class Temp methods
******************************************************/
#include <iostream>
#include <math.h>
#include "Temp.h"
using namespace std;

/* Setter funtion which takes a float parameter
   and puts its value in coefficient*/
void Term ::setCoefficient(float coefficient)
{
    this->coefficient = coefficient;
}

/* Setter funtion which takes a integer parameter
   and puts its value in power*/
void Term ::setPower(int power)
{
    this->power = power;
}

/* Overloading + operator functions
   Temp  + Temp
   Temp  + float
   float + Term
*/
Term Term::operator+(const Term &t) const
{
    if (t.power != this->power)
    {
        throw 1;
    }
    Term result;
    result.power = this->power;
    result.coefficient = t.coefficient + this->coefficient;
    return result;
}
Term Term::operator+(const float &f) const
{
    if (this->power != 0)
    {
        throw 6;
    }
    Term result;
    result.power = this->power;
    result.coefficient = f + this->coefficient;
    return result;
}
Term operator+(const float &f, const Term &t)
{
    if (t.getPower() != 0)
    {
        throw 6;
    }
    Term result;
    result.setPower(0);
    result.setCoefficient(f + t.getCoefficient());
    return result;
}

/* Overloading - operator functions
   Term   - Term
   Term   - float
   float  - Temp
*/
Term Term::operator-(const Term &t) const
{
    if (t.power != this->power)
    {
        throw 2;
    }
    Term result;
    result.power = this->power;
    result.coefficient = t.coefficient - this->coefficient;
    return result;
}
Term Term::operator-(const float &f) const
{
    if (this->power != 0)
    {
        throw 7;
    }
    Term result;
    result.power = this->power;
    result.coefficient = this->coefficient - f;
    return result;
}
Term operator-(const float &f, const Term &t)
{
    if (t.getPower() != 0)
    {
        throw 7;
    }
    Term result;
    result.setPower(0);
    result.setCoefficient(f - t.getCoefficient());
    return result;
}

/* Overloading * operator functions
   Term   * Term
   Term   * float
   float  * Temp
   */
Term Term::operator*(const Term &t) const
{
    Term result;
    result.power = this->power + t.power;
    result.coefficient = t.coefficient * this->coefficient;
    return result;
}
Term Term::operator*(const float &f) const
{
    Term result;
    result.power = this->power;
    result.coefficient = f * this->coefficient;
    return result;
}
Term operator*(const float &f, const Term &t)
{
    Term result;
    result.setPower(t.getPower());
    result.setCoefficient(f * t.getCoefficient());
    return result;
}

/* Overloading / operator functions
   Term   / Term
   Term   / float
   float  / Temp
*/
Term Term::operator/(const Term &t) const
{
    if (t.getCoefficient() == 0)
    {
        throw 8;
    }
    Term result;
    result.power = this->power - t.power;
    result.coefficient = t.coefficient / this->coefficient;
    return result;
}
Term Term::operator/(const float &f) const
{
    if (f == 0)
    {
        throw 8;
    }
    Term result;
    result.setPower(this->power);
    result.setCoefficient(this->coefficient / f);
    return result;
}
Term operator/(const float &f, const Term &t)
{
    if (t.getCoefficient() == 0)
    {
        throw 8;
    }
    Term result;
    result.setPower((-1) * t.getPower());
    result.setCoefficient(f / t.getCoefficient());
    return result;
}

/* Overloading += operator function
   Term += Term
*/
Term &Term::operator+=(const Term &t)
{
    if (t.power != this->power)
    {
        throw 1;
    }
    this->coefficient += t.coefficient;
    return *this;
}

/* Overloading -= operator function
   Term -= Term
*/
Term &Term::operator-=(const Term &t)
{
    if (t.power != this->power)
    {
        throw 2;
    }
    this->coefficient -= t.coefficient;
    return *this;
}

/* Overloading *= operator function
   Term *= Term
*/
Term &Term::operator*=(const Term &t)
{
    this->power += t.power;
    this->coefficient *= t.coefficient;
    return *this;
}

/* Overloading /= operator function
   Term /= Term
*/
Term &Term::operator/=(const Term &t)
{
    if (t.getCoefficient() == 0)
    {
        throw 8;
    }
    this->power -= t.power;
    this->coefficient /= t.coefficient;
    return *this;
}

/* Overloading = operator function
   Term = Term
*/
Term &Term::operator=(const Term &t)
{
    this->power = t.power;
    this->coefficient = t.coefficient;
    return *this;
}

/* Overloading > operator function
   Term   > Term
   Term   > float
   float  > Temp
*/
bool Term::operator>(const Term &t) const
{
    if (t.power < this->power)
    {
        return true;
    }
    else if (t.power > this->power)
    {
        return false;
    }
    return {this->coefficient > t.coefficient};
}
bool Term::operator>(const float &f) const
{
    if (0 < this->power)
    {
        return true;
    }
    else if (0 > this->power)
    {
        return false;
    }
    return {this->coefficient > f};
}
bool operator>(const float &f, const Term &t)
{
    if (0 > t.getPower())
    {
        return true;
    }
    else if (0 < t.getPower())
    {
        return false;
    }
    return {f > t.getCoefficient()};
}

/* Overloading < operator function
   Term   < Term
   Term   < float
   float  < Temp
*/
bool Term::operator<(const Term &t) const
{
    if (t.power > this->power)
    {
        return true;
    }
    else if (t.power < this->power)
    {
        return false;
    }
    return {this->coefficient < t.coefficient};
}
bool Term::operator<(const float &f) const
{
    if (0 > this->power)
    {
        return true;
    }
    else if (0 < this->power)
    {
        return false;
    }
    return {this->coefficient < f};
}
bool operator<(const float &f, const Term &t)
{
    if (0 < t.getPower())
    {
        return true;
    }
    else if (0 > t.getPower())
    {
        return false;
    }
    return {f > t.getCoefficient()};
}

/* Overloading >= operator function
   Term   >= Term
   Term   >= float
   float  >= Temp
*/
bool Term::operator>=(const Term &t) const
{
    if (t.power < this->power)
    {
        return true;
    }
    else if (t.power > this->power)
    {
        return false;
    }
    return {this->coefficient >= t.coefficient};
}
bool Term::operator>=(const float &f) const
{
    if (0 < this->power)
    {
        return true;
    }
    else if (0 > this->power)
    {
        return false;
    }
    return {this->coefficient >= f};
}
bool operator>=(const float &f, const Term &t)
{
    if (t.getPower() < 0)
    {
        return true;
    }
    else if (t.getPower() > 0)
    {
        return false;
    }
    return {f >= t.getCoefficient()};
}

/* Overloading <= operator function
   Term   <= Term
   Term   <= float
   float  <= Temp
*/
bool Term::operator<=(const Term &t) const
{
    if (t.power > this->power)
    {
        return true;
    }
    else if (t.power < this->power)
    {
        return false;
    }
    return {this->coefficient <= t.coefficient};
}
bool Term::operator<=(const float &f) const
{
    if (0 > this->power)
    {
        return true;
    }
    else if (0 < this->power)
    {
        return false;
    }
    return {this->coefficient <= f};
}
bool operator<=(const float &f, const Term &t)
{
    return {!(f > t.getCoefficient())};
}

/* Overloading == operator function
   Term   == Term
   Term   == float
   float  == Temp
*/
bool Term::operator==(const Term &t) const
{
    if (t.power == this->power)
    {
        if (t.coefficient == this->coefficient)
        {
            return true;
        }
    }
    return false;
}
bool Term::operator==(const float &f) const
{
    if (this->power != 0)
    {
        return false;
    }
    if (f == this->coefficient)
    {
        return true;
    }
    return false;
}
bool operator==(const float &f, const Term &t)
{
    if (t.getPower() != 0)
    {
        return false;
    }
    if (f == t.getCoefficient())
    {
        return true;
    }
    return false;
}

/* Overloading != operator function
   Term   != Term
   Term   != float
   float  != Temp
*/
bool Term::operator!=(const Term &t) const
{
    if (t.power == this->power)
    {
        if (t.coefficient == this->coefficient)
        {
            return false;
        }
    }
    return true;
}
bool Term::operator!=(const float &f) const
{
    return {!(*this == f)};
}
bool operator!=(const float &f, const Term &t)
{
    return {!(f == t)};
}

/* Overloading ~ operator function
   calculates Derivative of Term
*/
Term Term::operator~() const
{
    Term result;
    result.coefficient = (this->coefficient * this->power);
    result.power = this->power - 1;
    return result;
}
/* Overloading ++ operator function
   pre increment
   ++Term
*/
Term &Term::operator++()
{
    if (this->power != 0)
    {
        throw 3;
    }
    ++this->coefficient;
    return *this;
}

/* Overloading ++ operator function
   post increment
   Term++
*/
Term Term::operator++(int)
{
    if (this->power != 0)
    {
        throw 3;
    }
    Term copy(*this);
    (this->coefficient)++;
    return copy;
}

/* Overloading -- operator function
   pre deccrement
   --Term
*/
Term &Term::operator--()
{
    if (this->power != 0)
    {
        throw 4;
    }
    --this->coefficient;
    return *this;
}

/* Overloading -- operator function
   post deccrement
   Term--
*/
Term Term::operator--(int)
{
    if (this->power != 0)
    {
        throw 4;
    }
    Term copy(*this);
    (this->coefficient)--;
    return copy;
}

/* Overloading () operator function
   takes a float number as parameter
   and calculate the value of Term per that number
*/
float Term::operator()(float num)
{
    float result;
    result = pow(num, this->power);
    result *= this->coefficient;
    return result;
}

/* This function is to turn a string into term
   both the string and Term are given as parameter
   it divides the string and puts it into the given Term
*/
void divideStringIntoTerm(string inputTerm, Term &t)
{
    char ch = 'x';      // Charecter used to see where our x is placed in string
    int count = 0;      // This is for counting how many x has been entered in string
    int whereXIsPlaced; // The index which shows where our x is placed
    string tmpPower;    // A Temporary string for finding the value of Term 's power

    /*In this loop we find where our x is placed
    and also how many x is there in entered string*/
    for (int i = 0; i < inputTerm.size(); i++)
    {
        if (inputTerm[i] == ch)
        {
            whereXIsPlaced = i;
            count++;
        }
    }

    /*
    If our Term has more than one x
    then its invalid
    so there is only one or no x
    otherwise throw an exception and stop more false proceses */
    if (!(count == 0 || count == 1))
    {
        throw 5;
    }

    /*
    If there was no x in string
    then we just look for coefficient
    */
    else if (count == 0)
    {
        t.setCoefficient(stof(inputTerm));
        t.setPower(0);
    }

    /*
    If there is an x
    then we should continue other possibilitis
    */
    else if (count == 1)
    {
        /*
        If our x is set on the first character of string
        then we set one to our coefficient
        */
        if (whereXIsPlaced == 0)
        {
            t.setCoefficient(1);
        }

        /*
        If our x is placed on the second index
        then we check for a sign
        if find a sign then set the right coefficient
        othewise just set the coefficient
        by looking every number that is before x
        */
        else if ((whereXIsPlaced == 1) && (inputTerm[0] == '-'))
        {
            t.setCoefficient(-1);
        }
        else if ((whereXIsPlaced == 1) && (inputTerm[0] == '+'))
        {
            t.setCoefficient(1);
        }
        else
        {
            t.setCoefficient(stof(inputTerm));
        }

        /*
        Now that coefficient is set
        we look for power
        if there is the '^' character after x
        we look for power
        or else we just set one for power
        */
        if (inputTerm[whereXIsPlaced + 1] == '^')
        {
            /*
            Now that there is '^' after x
            we put the characters after '^' into tmpPower
            so that we can turn it to number and set it for power
            */
            for (int i = whereXIsPlaced + 2; i < inputTerm.size(); i++)
            {
                tmpPower.push_back(inputTerm[i]);
            }
            t.setPower(stoi(tmpPower));
        }
        else
        {
            t.setPower(1);
        }
    }
}

/* Overloading >> operator function
   this function takes a Term as parameter
   basically gets a Term from input
*/
istream &operator>>(istream &in, Term &t)
{
    string inputTerm; // The taken string

    /* Takes an string from input*/
    getline(in, inputTerm);

    /* Turn the string into the Term which was given as parameter*/
    divideStringIntoTerm(inputTerm, t);
    return in;
}

/* Overloading << operator function
   this function takes a Term as parameter
   and prints it on output
*/
ostream &operator<<(ostream &out, const Term &t)
{
    /*For Term that do not start with a sign or are not zero:*/
    if (!(t.coefficient == 1 || t.coefficient == -1 || t.coefficient == 0))
    {
        out << t.coefficient;
        if (!(t.power == 0 || t.power == 1))
        {
            out << "x^" << t.power;
        }
        else if (t.power == 1)
        {
            out << 'x';
        }
    }

    /*For Term that coefficent is 1 and we do not want to see 1 on output*/
    else if (t.coefficient == 1)
    {
        if (!(t.power == 0 || t.power == 1))
        {
            out << "x^" << t.power;
        }
        else if (t.power == 1)
        {
            out << 'x';
        }
        else if (t.power == 0)
        {
            out << '1';
        }
    }

    /*For Term that coefficent is -1 and we just want to see sign '-' and not -1 on output*/
    else if (t.coefficient == -1)
    {
        if (!(t.power == 0 || t.power == 1))
        {
            out << "-x^" << t.power;
        }
        else if (t.power == 1)
        {
            out << "-x";
        }
        else if (t.power == 0)
        {
            out << "-1";
        }
    }

    /*For Term that coefficient is 0 we just print 0 and nothing else
    We got function that take care of terms with z coefficien value
    but this help any other confusion or any chance to print possible values*/
    else if (t.coefficient == 0)
    {
        out << '0';
    }

    return out;
}