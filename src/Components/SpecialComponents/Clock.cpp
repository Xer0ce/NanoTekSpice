/*
** EPITECH PROJECT, 2024
** B-OOP-400-TLS-4-1-tekspice-louis.huguet
** File description:
** Clock
*/

#include "Clock.hpp"

namespace nts {
    Clock::Clock()
    {
        initMap(1, 1);
        _type = "input";
    }

    Clock::~Clock()
    {
    }

    void Clock::initMap(std::size_t numberPin, std::size_t numberImputPin)
    {
        _pins.push_back(new Pin(nts::Tristate::Undefined, numberPin, numberImputPin));
    }

    void Clock::compute()
    {
        if (getPinAtIndex(1)->getState() == nts::Tristate::False) {
            getPinAtIndex(1)->setNextState(nts::Tristate::True);
        } else if (getPinAtIndex(1)->getState() == nts::Tristate::True) {
            getPinAtIndex(1)->setNextState(nts::Tristate::False);
        }
    }
}
