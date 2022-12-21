#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>

#include "cambio.h"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        cout << "No se ha introducido ningun argumento" << endl;
    }
    else if (argc == 2)
    {

        float dinero_ = stof(argv[1]);

        Cambio dinero(dinero_);
        dinero.calcular_cambio_decimal();
        dinero.imprimir_cambio_monedas();
    }
    else if (argc == 3)
    {
        if (strcmp(argv[1] , "-b") == 0)
        {
            float dinero_decimal_ = stof(argv[2]);
            int dinero_entero_ = stoi(argv[2]);

            Cambio dinero(dinero_entero_, dinero_decimal_);
            dinero.calcular_cambio();
            dinero.imprimir_cambio();
        }
        else if (strcmp(argv[1] , "-o") == 0)
        {
            float dinero_ = stof(argv[2]);
            dinero_ = round(dinero_ * 100);
            std::cout   <<  std::endl;

            Cambio dinero(dinero_);
            dinero.calcular_cambio_alternativo();
            dinero.imprimir_cambio_alternativo();
        }
        else
        {
            cout << "Argumento no valido" << endl;
        }
    }
    else if (argc == 4)
    {
        if ((strcmp(argv[1] , "-b") == 0 && strcmp(argv[2] , "-o") == 0) || strcmp(argv[2] , "-b") == 0 && strcmp(argv[1] , "-o") == 0)
        {
            float dinero_decimal_ = stof(argv[3]);
            dinero_decimal_ = round(dinero_decimal_ * 100);
            int dinero_entero_ = stoi(argv[3]);
            std::cout << dinero_entero_ << std::endl;
            dinero_entero_ = round(dinero_entero_ * 100);

            Cambio dinero(dinero_entero_, dinero_decimal_);
            dinero.Alternativo();
            dinero.imprimir_cambio_alternativo_2();
        }
        else
        {
            cout << "Argumento no valido" << endl;
        }
    }else
    {
        cout << "Demasiados argumentos" << endl;
    }
}