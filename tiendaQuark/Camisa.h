#pragma once
#include "Prenda.h"

enum EManga 
{
    Corta,
    Larga,

    Default
};

enum ECuello 
{
    Mao,
    Comun,

    Max
};
class Camisa : public Prenda 
{
public:
    Camisa();

    const std::string& getManga() const;

    const std::string& getCuello() const;

    void setManga(EManga manga);

    void setCuello(ECuello cuello);

    

private:
    EManga Manga;
    ECuello Cuello = Max;

    std::string cuello;
    std::string manga;
    std::string Tipo;
};

