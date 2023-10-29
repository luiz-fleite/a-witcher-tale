#include "Date.h"

Date::Date(int d, int m, int a) 
{
    if ( m > 0 && m <= 12 ) // validate the month
        mes = m;
    
    if ( a < 0 )
        ano = 1900;

    else
        ano = a;
   
    dia = VerificaDia(d);

}

void Date::print() const
{
   cout << dia << '/' << mes << '/' << ano;
   
}

int Date::VerificaDia(int diaTeste) const
{
    static const int diasPorMes[ 13 ] = 
       { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    
    if ( diaTeste > 0 && diaTeste <= diasPorMes[ mes ] )
        return diaTeste;
    
    if ( mes == 2 && diaTeste == 29 && ( ano % 400 == 0 ||
            ( ano % 4 == 0 && ano % 100 != 0 ) ) )
        return diaTeste;
    
    cout << "Dia invalido (" << diaTeste << ") configurado para 1.\n";
    return 1; 
}
/*
ostream &operator<< (ostream &out, const Date &date) {
    out << date.dia << "/" << date.mes << "/" << date.ano;
    return out;
}
*/