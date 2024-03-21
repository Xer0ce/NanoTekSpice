/*
** EPITECH PROJECT, 2024
** B-OOP-400-TLS-4-1-tekspice-louis.huguet
** File description:
** Components4069
*/

#include "Components4069.hpp"

static bool isOutput(size_t pinNb)
{
    if (pinNb == 2 || pinNb == 4 || pinNb == 6 || pinNb == 12 || pinNb == 10 || pinNb == 8) {
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

void nts::Components4069::initMap(std::size_t numberPin, std::size_t numberImputPin)
{
    for (int i = 1; i != numberPin; i++) {
        if (isOutput(i)) {
            _pins.push_back(new Pin(nts::Tristate::Undefined, i, 1));
        } else if (isNotIgnored(i)) {
            _pins.push_back(new Pin(nts::Tristate::Undefined, i, 0));
        }  else {
            _pins.push_back(new Pin(nts::Tristate::Undefined, i, 2));
        }
    }
}

void nts::Components4069::compute() 
{
    for (size_t i = 1; i < 14; i+=2) {
        if (i == 7 || i == 14) {
            continue;
        }
        int stp1 = getPinAtIndex(i)->getState();

        if (stp1 == 0)
            if (i < 7)
                getPinAtIndex(i + 1)->setState(nts::Tristate::True);
            else
                getPinAtIndex(i - 1)->setState(nts::Tristate::True);
        if (stp1 == 1)
            if (i < 7)    
                getPinAtIndex(i + 1)->setState(nts::Tristate::False);
            else 
                getPinAtIndex(i - 1)->setState(nts::Tristate::False);
        if (stp1 == -1)
            if (i < 7)    
                getPinAtIndex(i + 1)->setState(nts::Tristate::Undefined);
            else 
                getPinAtIndex(i - 1)->setState(nts::Tristate::Undefined);
    }
    return;
}
