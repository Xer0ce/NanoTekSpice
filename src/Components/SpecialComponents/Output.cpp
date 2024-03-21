/*
** EPITECH PROJECT, 2024
** B-OOP-400-TLS-4-1-tekspice-louis.huguet
** File description:
** Output
*/

#include "Output.hpp"

namespace nts {
    Output::Output()
    {
        initMap(1, 0);
        _type = "output";
    }

    Output::~Output() {}

    void Output::initMap(std::size_t numberPin, std::size_t numberImputPin)
    {
        _pins.push_back(new Pin(nts::Tristate::Undefined, numberPin, numberImputPin));
    }

    void Output::compute() {}
}
