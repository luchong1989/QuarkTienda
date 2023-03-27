// tiendaQuark.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Tienda.h"

int main()
{
    
    Tienda* Tienda1 = new Tienda();
    Tienda1->InicializarVendedor();
    Tienda1->MenuPrincipal();


    return 0;
}


