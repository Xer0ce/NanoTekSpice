/*
** EPITECH PROJECT, 2024
** B-OOP-400-TLS-4-1-tekspice-louis.huguet
** File description:
** Input
*/

#include "Input.hpp"

namespace nts {
    Input::Input()
    {
        initMap(1, 1);
        _type = "input";
    }

    Input::~Input() {}

    void Input::initMap(std::size_t numberPin, std::size_t numberImputPin)
    {
        _pins.push_back(new Pin(nts::Tristate::Undefined, numberPin, numberImputPin));
    }

    void Input::compute() {}
}
