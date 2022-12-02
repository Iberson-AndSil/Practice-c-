#include "ejemploDirectiva.hh"

#ifdef MAYOR_NUMERO
template <typename Nm>
Nm NumeroMayor(Nm num1, Nm num2)
{
    if(num1 > num2) return num1;
    else return num1;
}
#else
template <typename Nm>
Nm NumeroMenor(Nm num1, Nm num2)
{
    if(num1 < num2) return num1;
    else return num1;
}

#endif
