#include <iostream>
#include "Vendedor.h"

Vendedor::Vendedor(std::string nombre, std::string apellido, std::string codigoVendedor) 
{
    Nombre = nombre;
    Apellido = apellido;
    CodigoVendedor = codigoVendedor;

}

const std::string& Vendedor::getNombre() const 
{
    return Nombre;
}

const std::string& Vendedor::getApellido() const 
{
    return Apellido;
}

const std::string& Vendedor::getCodigoVendedor() const 
{
    return CodigoVendedor;
}

void Vendedor::AgregarPrenda(ListaCot*& lista, Cotizacion* cot) 
{

    ListaCot* Nuevacot = new ListaCot();
    Nuevacot->cotizacion = cot;
    Nuevacot->sig = lista;
    lista = Nuevacot;
}

void Vendedor::MostrarLista(ListaCot* listacot)
{
    ListaCot* actual = new ListaCot();
    actual = listacot;
    system("cls");
    std::cout << "COTIZADOR EXPRESS - HISTORIAL DE COTIZACIONES" << std::endl;
    std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << std::endl;
    std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << std::endl;
    while (actual != nullptr)
    {
        
        std::cout << "Numero de identificacion: " << actual->cotizacion->getNumeroId() << std::endl;
        std::cout << "Fecha y hora de la cotizacion " << actual->cotizacion->GetFechaCotizacion() << std::endl;
        std::cout << "Codigo del vendedor: " << CodigoVendedor << std::endl;
        std::cout << "Prenda Cotizada: " << actual->cotizacion->getPrendaCotizada()->getNombre() << " - " << actual->cotizacion->getPrendaCotizada()->getCalidad() << std::endl;
        std::cout << "Precio Unitario: " << actual->cotizacion->getPrecioUnitario() << std::endl;
        std::cout << "Cantidad de unidades cotizadas: " << actual->cotizacion->GetCantidadDeUnidades() << std::endl;
        std::cout << "Precio final: " << actual->cotizacion->getPrecioFinal() << std::endl << std::endl << std::endl;
        actual = actual->sig;
    }

    return;

    
}

ListaCot* Vendedor::getLista() const 
{
    return Lista;
}
