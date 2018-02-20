/**
 * @file    Fraction.h
 * @brief   Includes the definition of the "Fraction" class and
 *          some stand-alone funtions.
 *
 * @author  Tomonori Yoshino
 * @date    Saturday, Feb 17
 */
#ifndef FRACTION_H
#define FRACTION_H


#include <iostream>
#include <sstream>



class Fraction
{
public:
    Fraction (int n, int d);
    
    void        write (std::ostream& strm=std::cout) const;
    void        read (std::istream& strm=std::cin);
    Fraction    add (int i) const;
    int         get_numerator() const   { return numerator; }
    int         get_denominator() const { return denominator; }
    
    //Addition.
    Fraction    operator+ (int i)                  const;
    Fraction    operator+ (const Fraction& op2)    const;
    //Subtraction.
    Fraction    operator- (int i)                  const;
    Fraction    operator- (const Fraction& f)      const;
    //Negation.
    Fraction    operator- ()                       const;
    //Multiplication.
    Fraction    operator* (int i)                  const;
    Fraction    operator* (const Fraction& f)      const;
    //Division.
    Fraction    operator/ (int i)                  const;
    Fraction    operator/ (const Fraction& f)      const;
    //Less-than <
    bool    operator< (int i)                  const;
    bool    operator< (const Fraction& f)      const;
    //Greater-than >
    bool    operator> (int i)                  const;
    bool    operator> (const Fraction& f)      const;
    //Less-than or equal-to <=
    bool    operator<= (int i)                  const;
    bool    operator<= (const Fraction& f)      const;
    //Greater-than or equal-to >=
    bool    operator>= (int i)                  const;
    bool    operator>= (const Fraction& f)      const;
    //Equal-to ==
    bool    operator== (int i)                  const;
    bool    operator== (const Fraction& f)      const;
    //Not equal-to !=
    bool    operator!= (int i)                  const;
    bool    operator!= (const Fraction& f)      const;
    
    
    //Test
    bool test (int num, int den) const;

    
    

private:
    int numerator   = 0;
    int denominator = 1;
    void reduce();
};


Fraction operator+ (int i, const Fraction& f);
Fraction operator- (int i, const Fraction& f);
Fraction operator* (int i, const Fraction& f);
Fraction operator/ (int i, const Fraction& f);
bool operator< (int i, const Fraction& f);
bool operator> (int i, const Fraction& f);
bool operator<= (int i, const Fraction& f);
bool operator>= (int i, const Fraction& f);
bool operator== (int i, const Fraction& f);
bool operator!= (int i, const Fraction& f);
std::ostream& operator<< (std::ostream& outfile, const Fraction& f);
std::istream& operator>> (std::istream& infile, Fraction& f);

bool test_relational_operator (bool actual_result, bool expected_result);
void test_insertion_operator (const Fraction& f, std::string expected);


#endif

