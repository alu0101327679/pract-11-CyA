#include "cambio.h"

Cambio::Cambio()
{
    dinero_decimal_ = 0;
    dinero_entero_ = 0;
}

Cambio::~Cambio()
{
}

Cambio::Cambio(int dinero_entero, float dinero_decimal)
{
    dinero_entero_ = dinero_entero;
    dinero_decimal_ = dinero_decimal;
    calcular_cambio();
    imprimir_cambio();
}

void Cambio::calcular_cambio()
{
    calcular_cambio_decimal_();
    calcular_cambio_entero_();
}

void Cambio::calcular_cambio_entero_()
{
    int dinero = dinero_entero_;
    int counter = 0;
    std::pair<int, int> variable;
    for (int i = 0; i < euros_.size(); i++)
    {
        if (dinero == 0)
        {
        }
        else
        {
            while (dinero >= euros_[i])
            {
                dinero -= euros_[i];
                counter++;
            }
            variable.second = counter;
            variable.first = euros_[i];
            cambio_entero_.push_back(variable);
            variable.first = 0;
            variable.second = 0;
            counter = 0;
        }
    }
}

void Cambio::calcular_cambio_decimal_()
{
    int dinero = 100 * dinero_decimal_;
    int counter = 0;
    std::pair<int, int> variable;
    for (int i = 0; i < euros_.size(); i++)
    {
        if (dinero == 0)
        {
        }
        else
        {
            while (dinero >= centimos_[i])
            {
                dinero -= centimos_[i];
                counter++;
            }
            variable.second = counter;
            variable.first = centimos_[i];
            cambio_entero_.push_back(variable);
            variable.first = 0;
            variable.second = 0;
            counter = 0;
        }
    }
}
void Cambio::imprimir_cambio()
{
    int total;

    std::cout << "Solucion: ";

    for (auto i = 0; i < euros_.size(); i++)
    {
        if (cambio_entero_[i].second == 1)
        {
            std::cout << cambio_entero_[i].first << "€ ";
            total += 1;
        }
        else if (cambio_entero_[i].second != 0)
        {
            std::cout << cambio_entero_[i].second << "x" << cambio_entero_[i].first << "€";
            total += cambio_entero_[i].second;
        }
    }
    std::cout << std::endl;
    std::cout << "Total de monedas: ";
}