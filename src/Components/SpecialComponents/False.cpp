/*
** EPITECH PROJECT, 2024
** B-OOP-400-TLS-4-1-tekspice-louis.huguet
** File description:
** False
*/

#include "False.hpp"

namespace nts
{
    void FalseCmp::compute()
    {
        getPinAtIndex(1)->setState(nts::Tristate::False);
        return;
    }

    void FalseCmp::initMap(std::size_t numberPin, std::size_t numberImputPin)
    {
        for (int i = 0; i != numberPin; i++) {
            if (i < numberImputPin)
                _pins.push_back(new Pin(nts::Tristate::Undefined, i, 0));
            else
                _pins.push_back(new Pin(nts::Tristate::True, i, 1));
        }
    }
}
