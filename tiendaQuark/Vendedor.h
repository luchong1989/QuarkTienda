#pragma once

#include <string>
#include "Cotizacion.h"

struct ListaCot 
{
    Cotizacion* cotizacion;
    ListaCot* sig;
};
class Vendedor 
{
public:
    Vendedor(std::string nombre, std::string apellido, std::string codigoVendedor);

    const std::string& getNombre() const;

    const std::string& getApellido() const;

    const std::string& getCodigoVendedor() const;

    ListaCot* Lista = nullptr;

    ListaCot* getLista() const;

    void AgregarPrenda(ListaCot*& lista, Cotizacion* cot);
    void MostrarLista(ListaCot* listacot);


private:
    std::string Nombre;
    std::string Apellido;
    std::string CodigoVendedor;

};

