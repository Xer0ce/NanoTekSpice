/*
** EPITECH PROJECT, 2024
** B-OOP-400-TLS-4-1-tekspice-louis.huguet
** File description:
** True
*/

#include "True.hpp"

namespace nts
{
    void TrueCmp::compute()
    {
        getPinAtIndex(1)->setState(nts::Tristate::True);
        return;
    }

    void TrueCmp::initMap(std::size_t numberPin, std::size_t numberImputPin)
    {
        for (int i = 0; i != numberPin; i++) {
            if (i < numberImputPin)
                _pins.push_back(new Pin(nts::Tristate::Undefined, i, 0));
            else
                _pins.push_back(new Pin(nts::Tristate::True, i, 1));
        }
    }
}
