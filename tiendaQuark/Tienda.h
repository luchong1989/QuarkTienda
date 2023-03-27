#pragma once
#include <string>
#include "Vendedor.h"

class Cotizacion;
class Pantalon;
class Camisa;

class Tienda 
{

public:
    Tienda();
    Vendedor* vendedor1;
    void InicializarVendedor();
    const std::string& getNombre() const;

    const char* getDireccion() const;

    void MenuPrincipal();
    void RealizarCotizacion();

    void PantalonCotizacion();
    void PantalonTipo(Pantalon* pant);
    void PantalonCalidad(Pantalon* pant);
    void SetStockPantalon(Pantalon* pant, Cotizacion* cot);
    void RestarPantalon(std::string clase, int cant);
    void PrecioFinalYCotizacionPantalon(int cantidad, float precio, Cotizacion* cot, Pantalon* pant);


    void CamisaCotizacion();
    void CamisaManga(Camisa* cam);
    void CamisaCuello(Camisa* cam);
    void CamisaCalidad(Camisa* cam);
    void SetStockCamisa(Camisa* cam, Cotizacion* cot);
    void RestarCamisa(std::string clase, int cant);
    void PrecioFinalYCotizacionCamisa(int cantidad, float precio, Cotizacion* cot, Camisa* cam);


    void MostrarLista();

private:
    std::string Nombre;
    const char* Direccion;

    int ChupinesStandard = 750;
    int ChupinesPremium = 750;
    int ComunesStandard = 250;
    int ComunesPremium = 250;

    int CortaMaoStandard = 100;
    int CortaMaoPremium = 100;
    int CortaComunStandard = 150;
    int CortaComunPremium = 150;
    int LargaMaoStandard = 75;
    int LargaMaoPremium = 75;
    int LargaComunStandard = 175;
    int LargaComunPremium = 175;
};

