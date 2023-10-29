/* 
 * File:   Data.h
 * Author: Deitel
 *
 * Created on 9 de Junho de 2012, 14:47
 */

#ifndef DATE_H
#define	DATE_H

#include <iostream>

using std::cout;
using std::ostream;

class Date
{
    //friend ostream &operator<< (ostream &out, const Date &date);
public:
    
    Date( int = 1, int = 1, int = 1900 );
    
    inline int getDia() const { return dia; }
    inline int getMes() const { return mes; }
    inline int getAno() const { return ano; }

    void print() const;
    
private:
    
    int mes;
    int dia;
    int ano;
    
    int VerificaDia( int ) const;
};

#endif	/* DATE_H */