/*
** EPITECH PROJECT, 2024
** B-OOP-400-TLS-4-1-tekspice-louis.huguet
** File description:
** Pin
*/

#include "Pin.hpp"

Pin::Pin(nts::Tristate state, std::size_t pin, std::size_t type)
{
    _state = state;
    _pin = pin;
    _nextState = nts::Tristate::Undefined;
    if (type == 0) {
        _type = "input";
    } else if (type == 1) {
        _type = "output";
    } else {
        _type = "ignored";
    }
}

void Pin::setState(nts::Tristate state)
{
    _state = state;
}

nts::Tristate Pin::getState() const
{
    return _state;
}

void Pin::setPin(std::size_t pin)
{
    _pin = pin;
}

std::size_t Pin::getPin() const
{
    return _pin;
}

void Pin::setType(std::string type)
{
    _type = type;
}

std::string Pin::getType() const
{
    return _type;
}

void Pin::setNextState(nts::Tristate state)
{
    _nextState = state;
}

nts::Tristate Pin::getNextState() const
{
    return _nextState;
}

void Pin::setNewState()
{
    _state = _nextState;
}
