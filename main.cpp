/**
 *******************************************************************************
 * @file    main.cpp
 * @brief   Test the overloaded operators for the "Fraction" class.
 *
 * This code tests the following overloaded operators:
 *          << insertion operator
 *          >> extraction operator
 *          + addition
 *          - subtraction
 *          * multiplication
 *           / division
 *          < and <= less-than or equal-to
 *          > and >= greater-than or equal-to
 *          == and != equal-to and not equal-to
 *
 * @remarks
 *      Course:        Computer Science 2124, Spring 2018
 *      Assignment #:  04
 *      Due Date:      Monday, Feb 19
 *      Instructor:    Dr. Jason L Causey
 *
 * @author        Tomonori Yoshino
 * @date          Saturday, Feb 17
 *******************************************************************************
 */
#include "Fraction.h"
#include "gcd.h"
#include <iostream>
#include <sstream>
using namespace::std;

int main()
{
    
    
    
    cout << endl << "\n\t~Test for overloaded operators~\t\n" << endl << endl;
    //Initialize two fraction object.
    //These are used to test overloaded operators.
    Fraction f1 {3, 5};
    cout << "f1: ";
    f1.write();
    cout << endl;
    
    Fraction f2 {1, 5};
    cout << "f2: ";
    f2.write();
    cout << endl;
    
    
     
    
    cout << "\n\t~Test for overloaded addition operators~\t\n";
    //Overloaded addition method.
    Fraction f3 = f1.operator+(2);
    cout << "f3 = f1.operator+(2): ";
    f3.write();
    cout << ( f3.test( 13, 5 ) ? "\tPassed" : "\tFailed" );
    cout << endl;
    
    Fraction f4 = f1 + 2;
    cout << "f4 = f1 + 2: ";
    f4.write();
    cout << ( f4.test( 13, 5 ) ? "\tPassed" : "\tFailed" );
    cout << endl;
    
    
    //Overloaded Operators with Object Operands
    Fraction f5 = f1 + f2;
    cout << "f5 = f1 + f2: ";
    f5.write();
    cout << ( f5.test( 4, 5 ) ? "\tPassed" : "\tFailed" );
    cout << endl;
    
    Fraction f6 = f2 + f1;
    cout << "f6 = f2 + f1: ";
    f6.write();
    cout << ( f6.test( 4, 5 ) ? "\tPassed" : "\tFailed" );
    cout << endl;
    
    //Operator Associativity and Cascading
    Fraction f7 = f1 + f2 + f3;
    cout << "f7 = f1 + f2 + f3: ";
    f7.write();
    cout << ( f7.test( 17, 5 ) ? "\tPassed" : "\tFailed" );
    cout << endl;
    
    
    //Right-Hand Object Operands in friend Functions
    Fraction f8 = 1 + f1;
    cout << "f8 = 1 + f1: ";
    f8.write();
    cout << ( f8.test( 8, 5 ) ? "\tPassed" : "\tFailed" );
    cout << endl;
     
    Fraction f9 = 0 + f1;
    cout << "f9 = 0 + f1: ";
    f9.write();
    cout << ( f9.test( 3, 5 ) ? "\tPassed" : "\tFailed" );
    cout << endl;
     
     
     
     
     
    
    cout << "\n\t~Test for overloaded subtraction operators~\t\n";
    //Overloaded subtraction method.
    f3 = f1.operator-(2);
    cout << "f3 = f1.operator-(2): ";
    f3.write();
    cout << ( f3.test( -7, 5 ) ? "\tPassed" : "\tFailed" );
    cout << endl;
    
    f4 = f1 - 2;
    cout << "f4 = f1 - 2: ";
    f4.write();
    cout << ( f4.test( -7, 5 ) ? "\tPassed" : "\tFailed" );
    cout << endl;
    
    
    //Overloaded Operators with Object Operands
    f5 = f1 - f2;
    cout << "f5 = f1 - f2: ";
    f5.write();
    cout << ( f5.test( 2, 5 ) ? "\tPassed" : "\tFailed" );
    cout << endl;
    
    f6 = f2 - f1;
    cout << "f6 = f2 - f1: ";
    f6.write();
    cout << ( f6.test( -2, 5 ) ? "\tPassed" : "\tFailed" );
    cout << endl;
    
    //Operator Associativity and Cascading
    f7 = f1 - f2 - f3;
    cout << "f7 = f1 - f2 - f3: ";
    f7.write();
    cout << ( f7.test( 9, 5 ) ? "\tPassed" : "\tFailed" );
    cout << endl;
    
    
    //Right-Hand Object Operands in friend Functions
    f8 = 1 - f1;
    cout << "f8 = 1 - f1: ";
    f8.write();
    cout << ( f8.test( 2, 5 ) ? "\tPassed" : "\tFailed" );
    cout << endl;
    
    f9 = 0 - f1;
    cout << "f9 = 0 - f1: ";
    f9.write();
    cout << ( f9.test( 3, -5 ) ? "\tPassed" : "\tFailed" );
    cout << endl;

    
    cout << "\n\t~Test for overloaded subtraction operators~\t\n";
    //Negation operator
    cout << "-f1 (Negation): ";
    f3 = -f1;
    f3.write();
    cout << ( f3.test( 3, -5 ) ? "\tPassed" : "\tFailed" );
    cout << endl;
    
    
    
    
    
    cout << "\n\t~Test for overloaded multiplication operators~\t\n";
    //Overloaded multiplication method.
    f3 = f1.operator*(2);
    cout << "f3 = f1.operator*(2): ";
    f3.write();
    cout << ( f3.test( 6, 5 ) ? "\tPassed" : "\tFailed" );
    cout << endl;
    
    f4 = f1 * 2;
    cout << "f4 = f1 * 2: ";
    f4.write();
    cout << ( f4.test( 6, 5 ) ? "\tPassed" : "\tFailed" );
    cout << endl;
    
    
    //Overloaded Operators with Object Operands
    f5 = f1 * f2;
    cout << "f5 = f1 * f2: ";
    f5.write();
    cout << ( f5.test( 3, 25 ) ? "\tPassed" : "\tFailed" );
    cout << endl;
    
    f6 = f2 * f1;
    cout << "f6 = f2 * f1: ";
    f6.write();
    cout << ( f6.test( 3, 25 ) ? "\tPassed" : "\tFailed" );
    cout << endl;
    
    //Operator Associativity and Cascading
    f7 = f1 * f2 * f3;
    cout << "f7 = f1 * f2 * f3: ";
    f7.write();
    cout << ( f7.test( 18, 125 ) ? "\tPassed" : "\tFailed" );
    cout << endl;
    
    
    //Right-Hand Object Operands in friend Functions
    f8 = 1 * f1;
    cout << "f8 = 1 * f1: ";
    f8.write();
    cout << ( f8.test( 3, 5 ) ? "\tPassed" : "\tFailed" );
    cout << endl;
    
    f9 = 0 * f1;
    cout << "f9 = 0 * f1: ";
    f9.write();
    cout << ( f9.test( 0, 1 ) ? "\tPassed" : "\tFailed" );
    cout << endl;
    
    
    
    
    
    
    
    cout << "\n\t~Test for overloaded division operators~\t\n";
    //Overloaded division method.
    f3 = f1.operator/(2);
    cout << "f3 = f1.operator/(2): ";
    f3.write();
    cout << ( f3.test( 3, 10 ) ? "\tPassed" : "\tFailed" );
    cout << endl;
    
    f4 = f1 / 2;
    cout << "f4 = f1 / 2: ";
    f4.write();
    cout << ( f4.test( 3, 10 ) ? "\tPassed" : "\tFailed" );
    cout << endl;
    
    
    //Overloaded Operators with Object Operands
    f5 = f1 / f2;
    cout << "f5 = f1 / f2: ";
    f5.write();
    cout << ( f5.test( 3, 1 ) ? "\tPassed" : "\tFailed" );
    cout << endl;
    
    f6 = f2 / f1;
    cout << "f6 = f2 / f1: ";
    f6.write();
    cout << ( f6.test( 1, 3 ) ? "\tPassed" : "\tFailed" );
    cout << endl;
    
    //Operator Associativity and Cascading
    f7 = f1 / f2 / f3;
    cout << "f7 = f1 / f2 / f3: ";
    f7.write();
    cout << ( f7.test( 10, 1 ) ? "\tPassed" : "\tFailed" );
    cout << endl;
    
    
    //Right-Hand Object Operands in friend Functions
    f8 = 1 / f1;
    cout << "f8 = 1 / f1: ";
    f8.write();
    cout << ( f8.test( 5, 3 ) ? "\tPassed" : "\tFailed" );
    cout << endl;
    
    
    f9 = 0 / f1;
    cout << "f9 = 0 / f1: ";
    f9.write();
    cout << ( f9.test( 0, 1 ) ? "\tPassed" : "\tFailed" );
    cout << endl;
    
    
    
    
    
    
    cout << "\n\t~Test for overloaded less-than operators~\t\n";
    cout << "f1 = " << f1;
    cout << endl;
    cout << "f2 = " << f2 << "\n";
    cout << endl;
    
    //Fraction < integer
    cout << "f1 < 10: ";
    cout << (f1 < 10);
    cout << ( test_relational_operator( f1<10, 0.6<10 ) ? "\tPassed" : "\tFailed" );
    cout << endl;
    
    cout << "f1 < -10: ";
    cout << (f1 < -10);
    cout << ( test_relational_operator( f1<-10, 0.6<-10 ) ? "\tPassed" : "\tFailed" );
    cout << endl;
    
    
    //integer < Fraction
    cout << "10 < f1: ";
    cout << (10 < f1);
    cout << ( test_relational_operator( 10<f1, 10<0.6 ) ? "\tPassed" : "\tFailed" );
    cout << endl;
    
    
    
    //Fraction < Fraction
    cout << "f1 < f2: ";
    cout << (f1 < f2);
    cout << ( test_relational_operator( f1<f2, 0.6<0.2 ) ? "\tPassed" : "\tFailed" );
    cout << endl;
    
    cout << "f2 < f1: ";
    cout << (f2 < f1);
    cout << ( test_relational_operator( (f2<f1), 0.2<0.6 ) ? "\tPassed" : "\tFailed" );
    cout << endl;
    
    cout << "-f1 < f2: ";
    cout << (-f1 < f2);
    cout << ( test_relational_operator( -f1<f2, -0.6<0.2 ) ? "\tPassed" : "\tFailed" );
    cout << endl;
    
    
    
    cout << "\n\t~Test for overloaded greater-than operators~\t\n";
    cout << "f1 = " << f1;
    cout << endl;
    cout << "f2 = " << f2 << "\n";
    cout << endl;
    
    //Fraction < integer
    cout << "f1 > 10: ";
    cout << (f1 > 10);
    cout << ( test_relational_operator( f1>10, 0.6>10 ) ? "\tPassed" : "\tFailed" );
    cout << endl;
    
    cout << "f1 > -10: ";
    cout << (f1 > -10);
    cout << ( test_relational_operator( f1>-10, 0.6>-10 ) ? "\tPassed" : "\tFailed" );
    cout << endl;
    
    //integer < Fraction
    cout << "10 > f1: ";
    cout << (10 > f1);
    cout << ( test_relational_operator( 10>f1, 10>0.6 ) ? "\tPassed" : "\tFailed" );
    cout << endl;
    
    
    
    //Fraction < Fraction
    cout << "f1 > f2: ";
    cout << (f1 > f2);
    cout << ( test_relational_operator( f1>f2, 0.6>0.2 ) ? "\tPassed" : "\tFailed" );
    cout << endl;
    
    cout << "f2 > f1: ";
    cout << (f2 > f1);
    cout << ( test_relational_operator( f2>f1, 0.2>0.6 ) ? "\tPassed" : "\tFailed" );
    cout << endl;


    cout << "-f1 > f2: ";
    cout << (-f1 > f2);
    cout << ( test_relational_operator( -f1>f2, -0.6>0.2 ) ? "\tPassed" : "\tFailed" );
    cout << endl;

    
    
    
    
    
    
    
    cout << "\n\t~Test for overloaded less-than or equal-to operators~\t\n";
    cout << "f1 = " << f1;
    cout << endl;
    cout << "f2 = " << f2 << "\n";
    cout << endl;
    
    //Fraction < integer
    cout << "f1 <= 10: ";
    cout << (f1 <= 10);
    cout << ( test_relational_operator( f1<=10, 0.6<=10 ) ? "\tPassed" : "\tFailed" );
    cout << endl;
    
    
    //integer < Fraction
    cout << "10 <= f1: ";
    cout << (10 <= f1);
    cout << ( test_relational_operator( 10<=f1, 10<=0.6 ) ? "\tPassed" : "\tFailed" );
    cout << endl;
    
    
    
    //Fraction < Fraction
    cout << "f1 <= f2: ";
    cout << (f1 <= f2);
    cout << ( test_relational_operator( f1<=f2, 0.6<=0.2 ) ? "\tPassed" : "\tFailed" );
    cout << endl;
    
    cout << "f2 <= f2: ";
    cout << (f2 <= f2);
    cout << ( test_relational_operator( f2<=f1, 0.2<=0.2 ) ? "\tPassed" : "\tFailed" );
    cout << endl;
    
    
    
    
    
    
    cout << "\n\t~Test for overloaded greater-than or equal-to operators~\t\n";
    cout << "f1 = " << f1;
    cout << endl;
    cout << "f2 = " << f2 << "\n";
    cout << endl;
    
    //Fraction < integer
    cout << "f1 >= 10: ";
    cout << (f1 >= 10);
    cout << ( test_relational_operator( f1>=10, 0.6>=10 ) ? "\tPassed" : "\tFailed" );
    cout << endl;
    
    
    //integer < Fraction
    cout << "10 >= f1: ";
    cout << (10 >= f1);
    cout << ( test_relational_operator( 10>=f1, 10>=0.6 ) ? "\tPassed" : "\tFailed" );
    cout << endl;
    
    
    
    //Fraction < Fraction
    cout << "f1 >= f2: ";
    cout << (f1 >= f2);
    cout << ( test_relational_operator( f1>=f2, 0.6>=0.2 ) ? "\tPassed" : "\tFailed" );
    cout << endl;
    
    cout << "f2 >= f2: ";
    cout << (f2 >= f2);
    cout << ( test_relational_operator( f2>=f2, 0.2>=0.2 ) ? "\tPassed" : "\tFailed" );
    cout << endl;
    
    
    
    
    
    
    
    cout << "\n\t~Test for overloaded equal-to operators~\t\n";
    Fraction f10 {10, 1};
    cout << "f1 = " << f1;
    cout << endl;
    cout << "f2 = " << f2;
    cout << endl;
    cout << "f10 = " << f10 << "\n";
    cout << endl;
    
    
    //Fraction == integer
    cout << "f1 == 10: ";
    cout << (f1 == 10);
    cout << ( test_relational_operator( f1==10, 0.6==10 ) ? "\tPassed" : "\tFailed" );
    cout << endl;
    cout << "f10 == 10: ";
    cout << (f10 == 10);
    cout << ( test_relational_operator( f10==10, 10==10 ) ? "\tPassed" : "\tFailed" );
    cout << endl;

    
    //integer == Fraction
    cout << "10 == f1: ";
    cout << (10 == f1);
    cout << ( test_relational_operator( 10==f1, 10==0.6 ) ? "\tPassed" : "\tFailed" );
    cout << endl;
    cout << "10 == f10: ";
    cout << (10 == f10);
    cout << ( test_relational_operator( 10==f10, 10==10 ) ? "\tPassed" : "\tFailed" );
    cout << endl;
    
    
    
    //Fraction == Fraction
    cout << "f1 == f2: ";
    cout << (f1 == f2);
    cout << ( test_relational_operator( f1==f2, 0.6==0.2 ) ? "\tPassed" : "\tFailed" );
    cout << endl;
    
    cout << "f2 == f2: ";
    cout << (f2 == f2);
    cout << ( test_relational_operator( f2==f2, 0.2==0.2 ) ? "\tPassed" : "\tFailed" );
    cout << endl;
    
    
    

    cout << "\n\t~Test for overloaded not equal-to operators~\t\n";
    cout << "f1 = " << f1;
    cout << endl;
    cout << "f2 = " << f2;
    cout << endl;
    cout << "f9 = " << f10 << "\n";
    cout << endl;
    
    
    //Fraction == integer
    cout << "f1 != 10: ";
    cout << (f1 != 10);
    cout << ( test_relational_operator( f1!=10, 0.6!=10 ) ? "\tPassed" : "\tFailed" );
    cout << endl;
    cout << "f9 != 10: ";
    cout << (f10 != 10);
    cout << ( test_relational_operator( f10!=10, 10!=10 ) ? "\tPassed" : "\tFailed" );
    cout << endl;
    
    
    //integer == Fraction
    cout << "10 != f1: ";
    cout << (10 != f1);
    cout << ( test_relational_operator( 10!=f1, 10!=0.6 ) ? "\tPassed" : "\tFailed" );
    cout << endl;
    cout << "10 != f10: ";
    cout << (10 != f10);
    cout << ( test_relational_operator( 10!=f10, 10!=10 ) ? "\tPassed" : "\tFailed" );
    cout << endl;
    
    
    
    //Fraction == Fraction
    cout << "f1 != f2: ";
    cout << (f1 != f2);
    cout << ( test_relational_operator( f1!=f2, 0.6!=0.2 ) ? "\tPassed" : "\tFailed" );
    cout << endl;
    
    cout << "f2 != f2: ";
    cout << (f2 != f2);
    cout << ( test_relational_operator( f2!=f2, 0.2!=0.2 ) ? "\tPassed" : "\tFailed" );
    cout << endl;
    
    
    

    
    
    
    cout << "\n\t~Test for overloaded extraction operators~\t\n";
    
    std::istringstream iss1, iss2, iss3, iss4, iss5, iss6, iss7, iss8, iss9;
    
    
    // put the pre-planned input into iss...
    iss1.str("3 / 8");
    iss2.str("3/8");
    iss3.str("Three/forths");
    iss4.str("3forths");
    iss5.str("3/forths");
    iss6.str("Three/4");
    iss7.str("3 forths");
    iss8.str("Three 4");
    iss9.str("3/0");
    
    
    cout << "3 / 8 is send to instream for fraction object having 3/5:                  ";
    while (iss1.good())
    {
        iss1 >> f1;
    }
    iss1.clear();
    cout << f1 << " should be 3/8";
    cout << endl;
    
    cout << "3/8 is send to instream for fraction object having 3/8:                    ";
    while (iss2.good())
    {
        iss2 >> f1;
    }
    iss2.clear();
    cout << f1 << " should be 3/8";
    cout << endl;
    
    
    cout << "Three/forths is send to instream for fraction object having 3/8:           ";
    while (iss3.good())
    {
        iss3 >> f1;
    }
    iss3.clear();
    cout << f1 << " should be 0/8";
    cout << endl;
    
    cout << "3fourths is send to instream for fraction object having 0/8:               ";
    while (iss4.good())
    {
        iss4 >> f1;
    }
    iss4.clear();
    cout << f1 << " should be 3/1";
    cout << endl;
    
    cout << "3/forths is send to instream for fraction object having 3/1:               ";
    while (iss5.good())
    {
        iss5 >> f1;
    }
    iss5.clear();
    cout << f1 << " should be 3/1";
    cout << endl;
    
    
    cout << "Three/forths is send to instream for fraction object having 3/1:           ";
    while (iss6.good())
    {
        iss6 >> f1;
    }
    iss6.clear();
    cout << f1 << " should be 0/1";
    cout << endl;
    
    
    cout << "3 forths is send to instream for fraction object having 0/1:               ";
    while (iss7.good())
    {
        iss7 >> f1;
    }
    iss7.clear();
    cout << f1 << " should be 3/1";
    cout << endl;
    
    
    cout << "Three 4 is send to instream for fraction object having 3/1:                ";
    while (iss8.good())
    {
        iss8 >> f1;
    }
    iss8.clear();
    cout << f1 << " should be 0/1";
    cout << endl;
    
    
    
    cout << "3/0 is send to instream for fraction object having 0/1:                    ";
    while (iss9.good())
    {
        iss9 >> f1;
    }
    iss9.clear();
    cout << f1 << " should be 3/1";
    cout << endl;
    
    
    
    cout << "\n\t~Test for overloaded insertion operators~\t\n";
    cout << "f2: should be 1/5...    ";
    f2.write();
    test_insertion_operator (f2, "1/5");
    cout << endl;
    f3 = -f3;
    cout << "f3: should be -3/10...   ";
    f3.write();
    test_insertion_operator (f3, "-3/10");
    cout << endl;
    cout << "f4: should be 0/1...    ";
    f4 = 0 * f4;
    f4.write();
    test_insertion_operator (f4, "0/1");
    cout << endl;
    cout << "f5: should be 3/1...    ";
    f5.write();
    test_insertion_operator (f5, "3/1");
    cout << endl;
    cout << "f6: should be 1/3...    ";
    f6.write();
    test_insertion_operator (f6, "1/3");
    cout << endl;
    cout << "f7: should be 10/1...   ";
    f7.write();
    test_insertion_operator (f7, "10/1");
    cout << endl;
    cout << "f8: should be 5/3...    ";
    f8.write();
    test_insertion_operator (f8, "5/3");
    cout << endl;

    return 0;
}


