#pragma once
#include <string>

enum ECalidad {
    Standard,
    Premium,

    Defa
};
class Prenda {
public:

    Prenda();

    ECalidad getCalidadDePrenda() const;

    void setCalidadDePrenda(ECalidad calidadDePrenda);

    const std::string& getCalidad() const;

    const std::string& getNombre() const;

    


protected:
    std::string Nombre;


private:
    ECalidad CalidadDePrenda;
    std::string Calidad;

};

