#include "Camisa.h"

Camisa::Camisa()
{
    Nombre = "Camisa";
	Manga = EManga::Default;
}

const std::string& Camisa::getManga() const
{
    return manga;
}

const std::string& Camisa::getCuello() const
{
    return cuello;
}

void Camisa::setManga(EManga manga)
{
    Manga = manga;
    if (Manga == EManga::Corta)
    {
        this->manga = "Corta";
    }
    if (Manga == EManga::Larga)
    {
        this->manga = "Larga";
    }
}

void Camisa::setCuello(ECuello cuello)
{
    Cuello = cuello;
    if (Cuello == ECuello::Comun)
    {
        this->cuello = "Comun";
    }
    if (Cuello == ECuello::Mao)
    {
        this->cuello = "Mao";
    }
}

