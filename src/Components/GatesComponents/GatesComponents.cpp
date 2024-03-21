/*
** EPITECH PROJECT, 2024
** B-OOP-400-TLS-4-1-tekspice-louis.huguet
** File description:
** GatesComponents
*/

#include "GatesComponents.hpp"

static bool isOutput(size_t pinNb)
{
    if (pinNb == 3 || pinNb == 4 || pinNb == 10 || pinNb == 11) {
        return true;
    }
    return false;
}

static bool isNotIgnored(size_t pinNb)
{
    if (pinNb == 7 || pinNb == 14) {
        return false;
    }
    return true;
}

void nts::GatesComponents::initMap(std::size_t numberPin, std::size_t numberImputPin)
{
    for (int i = 1; i != numberPin; i++) {
        if (isOutput(i)) {
            _pins.push_back(new Pin(nts::Tristate::Undefined, i, 1));
        } else if (isNotIgnored(i)) {
            _pins.push_back(new Pin(nts::Tristate::Undefined, i, 0));
        } else {
            _pins.push_back(new Pin(nts::Tristate::Undefined, i, 2));
        }
    }
}

