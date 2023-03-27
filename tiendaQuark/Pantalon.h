#pragma once
#include "Prenda.h"

enum ETipo {
    Comunes,
    Chupines,

    DefaultMax
};
class Pantalon : public Prenda 
{
public:
    Pantalon();

    void setTipo(ETipo tipo);
    const std::string& getTipo() const;

private:
    std::string tipo;
    ETipo Tipo;
};

