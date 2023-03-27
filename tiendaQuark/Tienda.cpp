#include "Tienda.h"
#include "Pantalon.h"
#include "Camisa.h"
#include "windows.h"
#include <iostream>

Tienda::Tienda() 
{

    Nombre = "Ropero";
    Direccion = "Calle Fresno #648 col. Valle verde";
}

void Tienda::InicializarVendedor()
{
    vendedor1 = new Vendedor("Lucio", "Martinez", "3344");
}

const std::string& Tienda::getNombre() const
{
    return Nombre;
}

const char* Tienda::getDireccion() const 
{
    return Direccion;
}

void Tienda::MenuPrincipal() 
{
    int opc;
    do {
        system("cls");
        std::cout << "COTIZADOR EXPRESS - MENU PRINCIPAL" << std::endl;
        std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << std::endl;
        std::cout << Nombre << " | " << Direccion << std::endl;
        std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << std::endl;
        std::cout << vendedor1->getNombre() << " " << vendedor1->getApellido() << " | " << vendedor1->getCodigoVendedor() << std::endl;
        std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << std::endl;
        std::cout << "\nSELECCIONE UNA OPCION DEL MENU: \n" << std::endl;
        std::cout << "1) Historial de Cotizaciones\n2) Realizar Cotizacion\n3) Salir" << std::endl;
        std::cin >> opc;

        if (opc == 1)
        {
            MostrarLista();
        }
        if (opc == 2)
        {
            RealizarCotizacion();
        }

    } while (opc != 3);

    exit(0);


}

void Tienda::RealizarCotizacion() 
{
    system("cls");
    int opc;
    std::cout << "COTIZADOR EXPRESS - COTIZAR" << std::endl;
    std::cout << "- - - - - - - - - - - - - - - - - - - - - - - " << std::endl;
    std::cout << "Presiona 3 para volver al menu principal" << std::endl;
    std::cout << "- - - - - - - - - - - - - - - - - - - - - - - " << std::endl;
    std::cout << "Selecciona la prenda a cotizar:" << std::endl;
    std::cout << "- - - - - - - - - - - - - - - - - - - - - - - " << std::endl;
    std::cout << "1) Camisa\n2) Pantalon" << std::endl;
    std::cin >> opc;

    if (opc == 1)
    {
        CamisaCotizacion();
    }
    if (opc == 2)
    {
        PantalonCotizacion();
    }
    if (opc == 3)
    {
        return MenuPrincipal();
    }


}

void Tienda::PantalonCotizacion() 
{
    Cotizacion* NuevaCot = new Cotizacion();
    Pantalon* pantalon = new Pantalon();

    PantalonTipo(pantalon);
    PantalonCalidad(pantalon);
    SetStockPantalon(pantalon, NuevaCot);

}

void Tienda::PantalonTipo(Pantalon* pant) 
{

    system("cls");

    int Opc;
    std::cout << "COTIZADOR EXPRESS - COTIZAR" << std::endl;
    std::cout << "- - - - - - - - - - - - - - - - - - - - - - - " << std::endl;
    std::cout << "Presiona 3 para volver al menu principal" << std::endl;
    std::cout << "- - - - - - - - - - - - - - - - - - - - - - - " << std::endl;
    std::cout << "PASO 2: El pantalon a cotizar es chupin?" << std::endl;
    std::cout << "1) Si\n2) No" << std::endl;
    std::cin >> Opc;
    std::cout << "- - - - - - - - - - - - - - - - - - - - - - - " << std::endl;

    if (Opc == 1)
    {
        pant->setTipo(ETipo::Chupines);

    }
    if (Opc == 2)
    {
        pant->setTipo(ETipo::Comunes);
    }
    if (Opc == 3)
    {
        delete pant;
        return MenuPrincipal();
    }
}

void Tienda::PantalonCalidad(Pantalon* pant) 
{
    system("cls");
    int cal;
    std::cout << "COTIZADOR EXPRESS - COTIZAR" << std::endl;
    std::cout << "- - - - - - - - - - - - - - - - - - - - - - - " << std::endl;
    std::cout << "Presiona 3 para volver al menu principal" << std::endl;
    std::cout << "- - - - - - - - - - - - - - - - - - - - - - - " << std::endl;
    std::cout << "PASO 3: Seleccione la calidad de la prenda" << std::endl;
    std::cout << "1) Standard\n2) Premium" << std::endl;
    std::cin >> cal;
    std::cout << "- - - - - - - - - - - - - - - - - - - - - - - " << std::endl;

    if (cal == 1)
    {
        pant->setCalidadDePrenda(ECalidad::Standard);
    }
    if (cal == 2)
    {
        pant->setCalidadDePrenda(ECalidad::Premium);
    }
    if (cal == 3)
    {
        delete pant;
        return MenuPrincipal();
    }

}

void Tienda::SetStockPantalon(Pantalon* pant, Cotizacion* cot) 
{
    if (pant)
    {
        int Stock = 0;
        std::string clase;
        if (pant->getTipo() == "Chupines" && pant->getCalidad() == "Standard")
        {
            Stock = ChupinesStandard;
            clase = "CS";
        }
        if (pant->getTipo() == "Chupines" && pant->getCalidad() == "Premium")
        {
            Stock = ChupinesPremium;
            clase = "CP";
        }
        if (pant->getTipo() == "Comunes" && pant->getCalidad() == "Standard")
        {
            Stock = ComunesStandard;
            clase = "CST";
        }
        if (pant->getTipo() == "Comunes" && pant->getCalidad() == "Premium")
        {
            Stock = ComunesPremium;
            clase = "CPR";
        }

        if (Stock > 0)
        {
            system("cls");
            float precio;
            std::cout << "COTIZADOR EXPRESS - COTIZAR" << std::endl;
            std::cout << "- - - - - - - - - - - - - - - - - - - - - - - " << std::endl;
            std::cout << "PASO 4: Ingrese el precio unitario de la prenda a cotizar" << std::endl;
            std::cin >> precio;
            std::cout << "- - - - - - - - - - - - - - - - - - - - - - - " << std::endl;

            system("cls");
            int cant;
            std::cout << "COTIZADOR EXPRESS - COTIZAR" << std::endl;
            std::cout << "- - - - - - - - - - - - - - - - - - - - - - - " << std::endl;
            std::cout << "INFORMACION:" << std::endl;
            std::cout << "EXISTE " << Stock << " " << "CANTIDAD DE UNIDADES EN STOCK DE LA PRENDA SELECCIONADA" << std::endl;
            std::cout << "PASO 5: Ingrese la cantidad de unidades a cotizar " << std::endl;
            std::cin >> cant;
            if (cant > Stock)
            {
                system("cls");
                std::cout << "No se puede realizar una cotizacion sobre una cantidad de stock no disponible" << std::endl;
                delete pant;
                delete cot;
                system("pause");
                return MenuPrincipal();
            }
            else
            {
                RestarPantalon(clase, cant);
                PrecioFinalYCotizacionPantalon(cant, precio, cot, pant);
            }
        }
        else
        {
            system("cls");
            std::cout << "Stock: " << Stock << ": No se puede realizar una cotizacion sobre una cantidad de stock no disponible" << std::endl;
            delete pant;
            delete cot;
            system("pause");
            return MenuPrincipal();
        }
    }

}

void Tienda::RestarPantalon(std::string clase, int cant) 
{
    if (clase == "CS")
    {
        ChupinesStandard -= cant;
        if (ChupinesStandard < 0)
        {
            ChupinesStandard = 0;
        }

    }
    if (clase == "CP")
    {
        ChupinesPremium -= cant;
        if (ChupinesPremium < 0)
        {
            ChupinesPremium = 0;
        }
    }
    if (clase == "CST")
    {
        ComunesStandard -= cant;
        if (ComunesStandard < 0)
        {
            ComunesStandard = 0;
        }

    }
    if (clase == "CPR")
    {
        ComunesPremium -= cant;
        if (ComunesPremium < 0)
        {
            ComunesPremium = 0;
        }
    }

}

void Tienda::PrecioFinalYCotizacionPantalon(int cantidad, float precio, Cotizacion* cot, Pantalon* pant)
{
    float preciofinal = 0.0f;
    if (pant->getTipo() == "Chupines" && pant->getCalidad() == "Standard")
    {
        preciofinal = (precio - (precio * 0.12f)) * cantidad;
    }
    else if (pant->getTipo() == "Chupines" && pant->getCalidad() == "Premium")
    {
        float temporal = precio - (precio * 0.12f);
        preciofinal = (temporal + (temporal * 0.30f)) * cantidad;
    }
    else if (pant->getTipo() == "Comunes" && pant->getCalidad() == "Standard")
    {
        preciofinal = precio * cantidad;
    }
    else if (pant->getTipo() == "Comunes" && pant->getCalidad() == "Premium")
    {
        preciofinal = (precio + (precio * 0.30f)) * cantidad;
    }

    cot->SetCantidadDeUnidades(cantidad);
    cot->setPrecioUnitario(precio);
    cot->setPrecioFinal(preciofinal);
    cot->setPrendaCotizada(pant);
    cot->SetNumeroId();
    cot->SetFecha();
    vendedor1->AgregarPrenda(vendedor1->Lista, cot);

    system("cls");
    std::cout << "COTIZADOR EXPRESS - COTIZAR" << std::endl;
    std::cout << "Numero de identificacion: " << cot->getNumeroId()<< std::endl;
    std::cout << "Fecha y hora de la cotizacion: " << cot->GetFechaCotizacion() << std::endl;
    std::cout << "Codigo del vendedor: " << vendedor1->getCodigoVendedor() << std::endl;
    std::cout << "Prenda Cotizada: " << "Pantalon - " << " " << pant->getTipo() << " - " << cot->getPrendaCotizada()->getCalidad() << std::endl;
    std::cout << "Precio Unitario: " << precio << std::endl;
    std::cout << "Cantidad de unidades cotizadas: " << cantidad << std::endl;
    std::cout << "Precio final: " << cot->getPrecioFinal() << std::endl;
    std::cout << "- - - - - - - - - - - - - - - - - - - - - - - " << std::endl;
    std::cout << "Presione enter para finalizar " << std::endl;
    std::cout << "- - - - - - - - - - - - - - - - - - - - - - - " << std::endl;
    system("pause");
    return MenuPrincipal();
}

void Tienda::CamisaCotizacion()
{
    Cotizacion* NuevaCot = new Cotizacion();
    Camisa* camisa = new Camisa();

    CamisaManga(camisa);
    CamisaCuello(camisa);
    CamisaCalidad(camisa);
    SetStockCamisa(camisa, NuevaCot);


}

void Tienda::CamisaManga(Camisa* cam)
{
    system("cls");
    int opc;
    std::cout << "COTIZADOR EXPRESS - COTIZAR" << std::endl;
    std::cout << "- - - - - - - - - - - - - - - - - - - - - - - " << std::endl;
    std::cout << "Presiona 3 para volver al menu principal" << std::endl;
    std::cout << "- - - - - - - - - - - - - - - - - - - - - - - " << std::endl;
    std::cout << "Paso 2. La camisa a cotizar, Es Manga corta?" << std::endl;
    std::cout << "1) Si\n2) No" << std::endl;
    std::cin >> opc;
    if (opc == 1)
    {
        cam->setManga(EManga::Corta);
    }
    if (opc == 2)
    {
        cam->setManga(EManga::Larga);
    }
    if (opc == 3)
    {
        delete cam;
        return MenuPrincipal();
    }

}

void Tienda::CamisaCuello(Camisa* cam)
{
    system("cls");
    int opc;
    std::cout << "COTIZADOR EXPRESS - COTIZAR" << std::endl;
    std::cout << "- - - - - - - - - - - - - - - - - - - - - - - " << std::endl;
    std::cout << "Presiona 3 para volver al menu principal" << std::endl;
    std::cout << "- - - - - - - - - - - - - - - - - - - - - - - " << std::endl;
    std::cout << "Paso 2. La camisa a cotizar, Es cuello Mao?" << std::endl;
    std::cout << "1) Si\n2) No" << std::endl;
    std::cin >> opc;
    if (opc == 1)
    {
        cam->setCuello(ECuello::Mao);
    }
    if (opc == 2)
    {
        cam->setCuello(ECuello::Comun);
    }
    if (opc == 3)
    {
        delete cam;
        return MenuPrincipal();
    }
}

void Tienda::CamisaCalidad(Camisa* cam)
{
    system("cls");
    int opc;
    std::cout << "COTIZADOR EXPRESS - COTIZAR" << std::endl;
    std::cout << "- - - - - - - - - - - - - - - - - - - - - - - " << std::endl;
    std::cout << "Presiona 3 para volver al menu principal" << std::endl;
    std::cout << "- - - - - - - - - - - - - - - - - - - - - - - " << std::endl;
    std::cout << "Seleccione la calidad de la prenda" << std::endl;
    std::cout << "1) Standard\n2) Premium" << std::endl;
    std::cin >> opc;
    if (opc == 1)
    {
        cam->setCalidadDePrenda(ECalidad::Standard);
    }
    if (opc == 2)
    {
        cam->setCalidadDePrenda(ECalidad::Premium);
    }
    if (opc == 3)
    {
        delete cam;
        return MenuPrincipal();
    }
}

void Tienda::SetStockCamisa(Camisa* cam, Cotizacion* cot)
{
    if (cam)
    {
        int Stock = 0;
        std::string clase;
        if (cam->getManga() == "Corta" && cam->getCuello() == "Comun" && cam->getCalidad() == "Standard")
        {
            Stock = CortaComunStandard;
            clase = "CCS";
        }
        if (cam->getManga() == "Corta" && cam->getCuello() == "Comun" && cam->getCalidad() == "Premium")
        {
            Stock = CortaComunStandard;
            clase = "CCP";
        }
        if (cam->getManga() == "Corta" && cam->getCuello() == "Mao" && cam->getCalidad() == "Standard")
        {
            Stock = CortaMaoStandard;
            clase = "CMS";
        }
        if (cam->getManga() == "Corta" && cam->getCuello() == "Mao" && cam->getCalidad() == "Premium")
        {
            Stock = CortaMaoPremium;
            clase = "CMP";
        }
        if (cam->getManga() == "Larga" && cam->getCuello() == "Comun" && cam->getCalidad() == "Standard")
        {
            Stock = LargaComunStandard;
            clase = "LCS";
        }
        if (cam->getManga() == "Larga" && cam->getCuello() == "Comun" && cam->getCalidad() == "Premium")
        {
            Stock = LargaComunPremium;
            clase = "LCP";
        }
        if (cam->getManga() == "Larga" && cam->getCuello() == "Mao" && cam->getCalidad() == "Standard")
        {
            Stock = LargaMaoStandard;
            clase = "LMS";
        }
        if (cam->getManga() == "Larga" && cam->getCuello() == "Mao" && cam->getCalidad() == "Premium")
        {
            Stock = LargaMaoPremium;
            clase = "LMP";
        }
        if (Stock > 0)
        {
            system("cls");
            float precio;
            std::cout << "COTIZADOR EXPRESS - COTIZAR" << std::endl;
            std::cout << "- - - - - - - - - - - - - - - - - - - - - - - " << std::endl;
            std::cout << "PASO 4: Ingrese el precio unitario de la prenda a cotizar" << std::endl;
            std::cin >> precio;
            std::cout << "- - - - - - - - - - - - - - - - - - - - - - - " << std::endl;

            system("cls");
            int cant;
            std::cout << "COTIZADOR EXPRESS - COTIZAR" << std::endl;
            std::cout << "- - - - - - - - - - - - - - - - - - - - - - - " << std::endl;
            std::cout << "INFORMACION:" << std::endl;
            std::cout << "EXISTE " << Stock << " " << "CANTIDAD DE UNIDADES EN STOCK DE LA PRENDA SELECCIONADA" << std::endl;
            std::cout << "PASO 5: Ingrese la cantidad de unidades a cotizar " << std::endl;
            std::cin >> cant;
            if (cant > Stock)
            {
                system("cls");
                std::cout << "No se puede realizar una cotizacion sobre una cantidad de stock no disponible" << std::endl;
                delete cam;
                delete cot;
                system("pause");
                return MenuPrincipal();
            }
            else
            {
                RestarCamisa(clase, cant);
                PrecioFinalYCotizacionCamisa(cant, precio, cot, cam);
            }
        }
        else
        {
            system("cls");
            std::cout << "Stock: " << Stock << ": No se puede realizar una cotizacion sobre una cantidad de stock no disponible" << std::endl;
            delete cam;
            delete cot;
            system("pause");
            return MenuPrincipal();
        }
    }
}

void Tienda::RestarCamisa(std::string clase, int cant)
{
    if (clase == "CCS")
    {
        CortaComunStandard -= cant;
        if (CortaComunStandard < 0)
        {
            CortaComunStandard = 0;
        }
    }
    if (clase == "CCP")
    {
        CortaComunPremium -= cant;
        if (CortaComunPremium < 0)
        {
            CortaComunPremium = 0;
        }
    }
    if (clase == "CMS")
    {
        CortaMaoStandard -= cant;
        if (CortaMaoStandard < 0)
        {
            CortaMaoStandard = 0;
        }
    }
    if (clase == "CMP")
    {
        CortaMaoPremium -= cant;
        if (CortaMaoPremium < 0)
        {
            CortaMaoPremium = 0;
        }

    }
    if (clase == "LCS")
    {
        LargaComunStandard -= cant;
        if (LargaComunStandard < 0)
        {
            LargaComunStandard = 0;
        }
    }
    if (clase == "LCP")
    {
        LargaComunPremium -= cant;
        if (LargaComunPremium < 0)
        {
            LargaComunPremium = 0;
        }
    }
    if (clase == "LMS")
    {
        LargaMaoStandard -= cant;
        if (LargaMaoStandard < 0)
        {
            LargaMaoStandard = 0;
        }
    }
    if (clase == "LMP")
    {
        LargaMaoPremium -= cant;
        if (LargaMaoPremium < 0)
        {
            LargaMaoPremium = 0;
        }
    }
}

void Tienda::PrecioFinalYCotizacionCamisa(int cantidad, float precio, Cotizacion* cot, Camisa* cam)
{
    float preciofinal = 0.0f;
    if (cam->getManga() == "Corta" && cam->getCuello() == "Comun" && cam->getCalidad() == "Standard")
    {
        preciofinal = (precio - (precio * 0.1f)) * cantidad;
    }
    if (cam->getManga() == "Corta" && cam->getCuello() == "Comun" && cam->getCalidad() == "Premium")
    {
        float temporal = precio - (precio * 0.1f);
        preciofinal = (temporal + (temporal * 0.30f)) * cantidad;
    }
    if (cam->getManga() == "Corta" && cam->getCuello() == "Mao" && cam->getCalidad() == "Standard")
    {
        float temporal = precio - (precio * 0.1f);
        preciofinal = (temporal + (temporal * 0.03)) * cantidad;
    }
    if (cam->getManga() == "Corta" && cam->getCuello() == "Mao" && cam->getCalidad() == "Premium")
    {
        float temporal = precio - (precio * 0.1f);
        float temporal2 = temporal + (temporal * 0.03);
        preciofinal = (temporal2 + (temporal2 * 0.30f)) * cantidad;
    }
    if (cam->getManga() == "Larga" && cam->getCuello() == "Comun" && cam->getCalidad() == "Standard")
    {
        preciofinal = precio * cantidad;
    }
    if (cam->getManga() == "Larga" && cam->getCuello() == "Comun" && cam->getCalidad() == "Premium")
    {
        preciofinal = (precio + (precio * 0.30f)) * cantidad;
    }
    if (cam->getManga() == "Larga" && cam->getCuello() == "Mao" && cam->getCalidad() == "Standard")
    {
        preciofinal = (precio + (precio * 0.03f)) * cantidad;
    }
    if (cam->getManga() == "Larga" && cam->getCuello() == "Mao" && cam->getCalidad() == "Premium")
    {
        float temporal = precio + (precio * 0.03f);
        preciofinal = (temporal + (temporal * 0.30f)) * cantidad;
    }

    cot->SetCantidadDeUnidades(cantidad);
    cot->setPrecioUnitario(precio);
    cot->setPrecioFinal(preciofinal);
    cot->setPrendaCotizada(cam);
    cot->SetNumeroId();
    cot->SetFecha();
    vendedor1->AgregarPrenda(vendedor1->Lista, cot);

    system("cls");
    std::cout << "COTIZADOR EXPRESS - COTIZAR" << std::endl;
    std::cout << "Numero de identificacion: " << cot->getNumeroId() << std::endl;
    std::cout << "Fecha y hora de la cotizacion: " << cot->GetFechaCotizacion() << std::endl;
    std::cout << "Codigo del vendedor: " << vendedor1->getCodigoVendedor() << std::endl;
    std::cout << "Prenda Cotizada: " << "Camisa " << "Manga: "<<cam->getManga() << " - " <<"Cuello: "<<cam->getCuello()<<" - "<< cot->getPrendaCotizada()->getCalidad() << std::endl;
    std::cout << "Precio Unitario: " << precio << std::endl;
    std::cout << "Cantidad de unidades cotizadas: " << cantidad << std::endl;
    std::cout << "Precio final: " << cot->getPrecioFinal() << std::endl;
    std::cout << "- - - - - - - - - - - - - - - - - - - - - - - " << std::endl;
    std::cout << "Presione enter para finalizar " << std::endl;
    std::cout << "- - - - - - - - - - - - - - - - - - - - - - - " << std::endl;
    system("pause");
    return MenuPrincipal();
}

void Tienda::MostrarLista()
{
    vendedor1->MostrarLista(vendedor1->getLista());
    std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << std::endl;
    std::cout << "Presione enter para volver al menu principal" << std::endl;
    std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << std::endl;
    system("pause");
    return MenuPrincipal();
}
