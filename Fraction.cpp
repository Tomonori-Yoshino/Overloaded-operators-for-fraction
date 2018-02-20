/**
 * @file    Fraction.cpp
 * @brief   Includes the implementation of functions related to "Fraction" class
 *
 * @author  Tomonori Yoshino
 * @date    Saturday, Feb 17
 */
#include "Fraction.h"
#include "gcd.h"
#include <stdexcept>
#include <string>




/**
 * Constructor for the Fraction object.
 *
 * @param        n     going to be a numerator
 * @param        d     going to be a denominator (0 is not allowed)
 *
 */
Fraction::Fraction(int n, int d)
{
    if (d == 0)
    {
        throw std::overflow_error{"Zero denominator is not allowed."};
    }
    
    numerator = n;
    denominator = d;
    reduce();
}


/**
 * @detailed     Display the numerator and denominator in the fraction object
 *               in the form of "numerator/denominator".
 *
 * @param        strm[oout]     output stream (deefault to cout)
 *
 */
void Fraction::write(std::ostream& strm) const
{
    strm << numerator << '/' << denominator;
}


/**
 * @detailed     Extract the value from the given input stream and store it
 *               into numerator and denominator respectively.
 *               The stream is set to be false if the denominator is 0.
 *
 * @param        strm[oout]     input stream (deefault to cin)
 *
 */
void Fraction::read (std::istream& strm)
{
    char ch;                                    //for slash
    strm >> numerator >> ch >> denominator;
    if ( denominator == 0 )                     //denominator cannot be 0...
    {
        strm.setstate(std::ios::failbit);
        denominator = 1;
    }
}


/**
 * @detailed     Add the integer to Fraction object.
 *
 * @param        i     integer to be added
 *
 * @return       the fraction object
 *
 */
Fraction Fraction::add (int i) const
{
    int n = numerator + i*denominator;
    int d = denominator;
    
    return Fraction {n, d};
}



/**
 * @detailed     Overloaded addition operator. (Fraction + integer)
 *
 * @param        i     integer to be added
 *
 * @return       the fraction object
 *
 */
Fraction Fraction::operator+ (int i) const
{
    int n = numerator + i*denominator;
    int d = denominator;
    
    return Fraction {n, d};
}

/**
 * @detailed     Overloaded addition operator. (Fraction + Fraction)
 *
 * @param        op2[out]     Fraction object to be added
 *
 * @return       the fraction object
 *
 */
Fraction Fraction::operator+ (const Fraction& op2) const
{
    int n = (numerator * op2.denominator)
                                    + (op2.numerator * denominator);
    int d = denominator * op2.denominator;
    
    return Fraction {n, d};
}

/**
 * @detailed     Overloaded addition operator. (integer + Fraction)
 *
 * @param        i          integer to be added
 * @param        f[out]     Fraction object to be added
 *
 * @return       the fraction object
 *
 */
Fraction operator+ (int i, const Fraction& f)
{
    int n = f.get_numerator() + i*f.get_denominator();
    int d = f.get_denominator();
    
    return Fraction {n, d};
}



/**
 * @detailed     Overloaded subtraction operator. (Fraction - integer)
 *
 * @param        i     integer to be subtracted
 *
 * @return       the fraction object
 *
 */
Fraction Fraction::operator- (int i) const
{
    int n = numerator - i * denominator;
    int d = denominator;
    return Fraction {n, d};
}


/**
 * @detailed     Overloaded subtraction operator. (Fraction - Fraction)
 *
 * @param        f[out]     Fraction object to be subtracted
 *
 * @return       the fraction object
 *
 */
Fraction Fraction::operator- (const Fraction& f) const
{
    int n = ( numerator * f.get_denominator() )
                        - ( f.get_numerator() * denominator );
    int d = denominator * f.get_denominator();
    return Fraction {n, d};
}


/**
 * @detailed     Overloaded subtraction operator. (integer - Fraction)
 *
 * @param        i          integer to be subtracted
 * @param        f[out]     Fraction object to be subtracted
 *
 * @return       the fraction object
 *
 */
Fraction operator- (int i, const Fraction& f)
{
    int n = i * f.get_denominator() - f.get_numerator();
    int d = f.get_denominator();
    return Fraction {n, d};
}


/**
 * @detailed     Overloaded negation operator.
 *
 * @return       the fraction object
 *
 */
Fraction Fraction::operator- () const
{
    int n = - numerator;
    int d = denominator;
    return Fraction {n, d};
}


/**
 * @detailed     Overloaded multiplication operator. (Fraction * integer)
 *
 * @param        i     integer to be multiplied
 *
 * @return       the fraction object
 *
 */
Fraction Fraction::operator* (int i) const
{
    int n = i * numerator;
    int d = denominator;
    return Fraction {n, d};
}


/**
 * @detailed     Overloaded multiplication operator. (Fraction * Fraction)
 *
 * @param        f[out]     Fraction to be multiplied
 *
 * @return       the fraction object
 *
 */
Fraction Fraction::operator* (const Fraction& f) const
{
    int n = numerator * f.get_numerator();
    int d = denominator * f.get_denominator();
    return Fraction {n, d};
}


/**
 * @detailed     Overloaded multiplication operator. (integer * Fraction)
 *
 * @param        i          integer to be multiplied
 * @param        f[out]     Fraction to be multiplied
 *
 * @return       the fraction object
 *
 */
Fraction operator* (int i, const Fraction& f)
{
    int n = i * f.get_numerator();
    int d = f.get_denominator();
    return Fraction {n, d};
}



/**
 * @detailed     Overloaded division operator. (Fraction / integer)
 *
 * @param        i     integer to be divided
 *
 * @return       the fraction object
 *
 */
Fraction Fraction::operator/ (int i) const
{
    int n = numerator;
    int d = i * denominator;
    return Fraction {n, d};
}


/**
 * @detailed     Overloaded division operator. (Fraction / Fraction)
 *
 * @param        f[out]     Fraction to be divided
 *
 * @return       the fraction object
 *
 */
Fraction Fraction::operator/ (const Fraction& f) const
{
    int n = numerator * f.get_denominator();
    int d = denominator * f.get_numerator();
    return Fraction {n, d};
}


/**
 * @detailed     Overloaded division operator. (integer / Fraction)
 *
 * @param        i          integer to be divided
 * @param        f[out]     Fraction to be divided
 *
 * @return       the fraction object
 *
 */
Fraction operator/ (int i, const Fraction& f)
{
    int n = i * f.get_denominator();
    int d = f.get_numerator();
    return Fraction {n, d};
}



/**
 * @detailed     Overloaded less-than operator. (Fraction < integer)
 *
 * @param        i     integer to be compared
 *
 * @return       boolean value of comparison
 *
 */
bool Fraction::operator< (int i) const
{
    double cmp = static_cast<double>(numerator) / denominator;
    return cmp < i;
}


/**
 * @detailed     Overloaded less-than operator. (Fraction < Fraction)
 *
 * @param        f[out]     Fraction to be compared
 *
 * @return       boolean value of comparison
 *
 */
bool Fraction::operator< (const Fraction& f) const
{
    double cmp1 = static_cast<double>(numerator) / denominator;
    double cmp2 = static_cast<double>(f.get_numerator()) / f.get_denominator();
    return cmp1 < cmp2;
}


/**
 * @detailed     Overloaded less-than operator. (integer < Fraction)
 *
 * @param        i          integer to be compared
 * @param        f[out]     Fraction to be compared
 *
 * @return       boolean value of comparison
 *
 */
bool operator< (int i, const Fraction& f)
{
    double cmp = static_cast<double>(f.get_numerator()) / f.get_denominator();
    return i < cmp;
}




/**
 * @detailed     Overloaded greater-than operator. (Fraction > integer)
 *
 * @param        i     integer to be compared
 *
 * @return       boolean value of comparison
 *
 */
bool Fraction::operator> (int i) const
{
    double cmp = static_cast<double>(numerator) / denominator;
    return cmp > i;
}


/**
 * @detailed     Overloaded greater-than operator. (Fraction > Fraction)
 *
 * @param        f[out]     Fraction to be compared
 *
 * @return       boolean value of comparison
 *
 */
bool Fraction::operator> (const Fraction& f) const
{
    double cmp1 = static_cast<double>(numerator) / denominator;
    double cmp2 = static_cast<double>(f.get_numerator()) / f.get_denominator();
    return cmp1 > cmp2;
}


/**
 * @detailed     Overloaded greater-than operator. (integer > Fraction)
 *
 * @param        i     integer to be compared
 * @param        f[out]     Fraction to be compared
 *
 * @return       boolean value of comparison
 *
 */
bool operator> (int i, const Fraction& f)
{
    double cmp = static_cast<double>(f.get_numerator()) / f.get_denominator();
    return i > cmp;
}



/**
 * @detailed     Overloaded less-than or equal-to operator. (Fraction <= integer)
 *
 * @param        i     integer to be compared
 *
 * @return       boolean value of comparison
 *
 */
bool Fraction::operator<= (int i) const
{
    double cmp = static_cast<double>(numerator) / denominator;
    return cmp <= i;
}


/**
 * @detailed     Overloaded less-than or equal-to operator. (Fraction <= Fraction)
 *
 * @param        f[out]     Fraction to be compared
 *
 * @return       boolean value of comparison
 *
 */
bool Fraction::operator<= (const Fraction& f) const
{
    double cmp1 = static_cast<double>(numerator) / denominator;
    double cmp2 = static_cast<double>(f.get_numerator()) / f.get_denominator();
    return cmp1 <= cmp2;
}


/**
 * @detailed     Overloaded less-than or equal-to operator. (integer <= Fraction)
 *
 * @param        i          integer to be compared
 * @param        f[out]     Fraction to be compared
 *
 * @return       boolean value of comparison
 *
 */
bool operator<= (int i, const Fraction& f)
{
    double cmp = static_cast<double>(f.get_numerator()) / f.get_denominator();
    return i <= cmp;
}



/**
 * @detailed     Overloaded greater-than or equal-to operator. (Fraction >= integer)
 *
 * @param        i     integer to be compared
 *
 * @return       boolean value of comparison
 *
 */
bool Fraction::operator>= (int i) const
{
    double cmp = static_cast<double>(numerator) / denominator;
    return cmp >= i;
}


/**
 * @detailed     Overloaded greater-than or equal-to operator. (Fraction >= Fraction)
 *
 * @param        f[out]     Fraction to be compared
 *
 * @return       boolean value of comparison
 *
 */
bool Fraction::operator>= (const Fraction& f) const
{
    double cmp1 = static_cast<double>(numerator) / denominator;
    double cmp2 = static_cast<double>(f.get_numerator()) / f.get_denominator();
    return cmp1 >= cmp2;
}


/**
 * @detailed     Overloaded greater-than or equal-to operator. (integer >= Fraction)
 *
 * @param        i          integer to be compared
 * @param        f[out]     Fraction to be compared
 *
 * @return       boolean value of comparison
 *
 */
bool operator>= (int i, const Fraction& f)
{
    double cmp = static_cast<double>(f.get_numerator()) / f.get_denominator();
    return i >= cmp;
}




/**
 * @detailed     Overloaded equal-to operator. (Fraction == integer)
 *
 * @param        i     integer to be compared
 *
 * @return       boolean value of comparison
 *
 */
bool Fraction::operator== (int i) const
{
    double cmp = static_cast<double>(numerator) / denominator;
    return cmp == i;
}


/**
 * @detailed     Overloaded equal-to operator. (Fraction == Fraction)
 *
 * @param        f[out]     Fraction to be compared
 *
 * @return       boolean value of comparison
 *
 */
bool Fraction::operator== (const Fraction& f) const
{
    double cmp1 = static_cast<double>(numerator) / denominator;
    double cmp2 = static_cast<double>(f.get_numerator()) / f.get_denominator();
    return cmp1 == cmp2;
}


/**
 * @detailed     Overloaded equal-to operator. (integer == Fraction)
 *
 * @param        i          integer to be compared
 * @param        f[out]     Fraction to be compared
 *
 * @return       boolean value of comparison
 *
 */
bool operator== (int i, const Fraction& f)
{
    double cmp = static_cast<double>(f.get_numerator()) / f.get_denominator();
    return i == cmp;
}





/**
 * @detailed     Overloaded not equal-to operator. (Fraction != integer)
 *
 * @param        i     integer to be compared
 *
 * @return       boolean value of comparison
 *
 */
bool Fraction::operator!= (int i) const
{
    double cmp = static_cast<double>(numerator) / denominator;
    return cmp != i;
}


/**
 * @detailed     Overloaded not equal-to operator. (Fraction != Fraction)
 *
 * @param        f[out]     Fraction to be compared
 *
 * @return       boolean value of comparison
 *
 */
bool Fraction::operator!= (const Fraction& f) const
{
    double cmp1 = static_cast<double>(numerator) / denominator;
    double cmp2 = static_cast<double>(f.get_numerator()) / f.get_denominator();
    return cmp1 != cmp2;
}


/**
 * @detailed     Overloaded not equal-to operator. (integer != Fraction)
 *
 * @param        i          integer to be compared
 * @param        f[out]     Fraction to be compared
 *
 * @return       boolean value of comparison
 *
 */
bool operator!= (int i, const Fraction& f)
{
    double cmp = static_cast<double>(f.get_numerator()) / f.get_denominator();
    return i != cmp;
}



/**
 * @detailed     Reduce the fractoin to its lowest possible form by
 *               using gcd() function.
 *
 */
void Fraction::reduce()
{
    //Get the common factor.
    int divisor = gcd(numerator, denominator);
    numerator   /= divisor;
    denominator /= divisor;
}


/**
 * @detailed     Overloaded insertion operator.
 *
 * @param        outfile[out]       output stream to which values to send
 * @param        f[out]             Fraction to be compared
 *
 * @return       output stream by reference
 *
 */
std::ostream& operator<< (std::ostream& outfile, const Fraction& f)
{
    f.write(outfile);
    return outfile;
}


/**
 * @detailed     Overloaded extraction operator.
 *
 * @param        infile[out]        input stream from which values are read
 * @param        f[out]             Fraction to be compared
 *
 * @return       input stream by reference
 *
 */
std::istream& operator>> (std::istream& infile, Fraction& f)
{
    f.read(infile);
    return infile;
}



/**
* @detailed     Check if the calling object is equal to the given fraction.
*
* @param        num     expected numerator to be compared
* @param        den     expected denominator to be compared
*
* @return       true if they are same
*
*/
bool Fraction::test (int num, int den) const
{
    bool result = false;
    if ( numerator == num && denominator == den )
        result = true;
    return result;
}

/**
 * @detailed     Test for relational operators.
 *
 * @param        actual_result       actual result
 * @param        expected_result     expected reslut
 *
 * @return       true if they are same
 *
 */
bool test_relational_operator (bool actual_result, bool expected_result)
{
    return actual_result == expected_result;
}

/**
 * @detailed     Test for insertion operators.
 *
 * @param        f[out]       actual result
 * @param        expected     expected reslut
 *
 * @return       true if they are same
 *
 */
void test_insertion_operator (const Fraction& f, std::string expected)
{
    std::ostringstream oss;
    oss << f;
    if(oss.str() == expected){
        std::cout << "    Passed\n";
    }
    else{
        std::cout << "    Failed\n";
    }
    
}

