/*
** EPITECH PROJECT, 2024
** *
** File description:
** AComponent
*/

#include "AComponent.hpp"

nts::AComponent::AComponent()
{
    _alreadySimulate = false;
}

nts::AComponent::~AComponent()
{
    for (auto it = _pins.begin(); it != _pins.end(); it++) {
        delete *it;
    }
}

void nts::AComponent::simulate( std::size_t tick )
{
    return;
}

void nts::AComponent::setLink( std::size_t pin, nts::IComponent &other, std::size_t otherPin )
{
    return;
}

bool nts::AComponent::getLinkStatus(std::string name, size_t pin) const
{
    return true;
}

void nts::AComponent::initMap(std::size_t numberPin, std::size_t numberImputPin)
{
    for (int i = 1; i != numberPin + 1; i++) {
        if (i <= numberImputPin)
            _pins.push_back(new Pin(nts::Tristate::Undefined, i, 0));
        else
            _pins.push_back(new Pin(nts::Tristate::Undefined, i, 1));
    }
}

void nts::AComponent::printMap() const
{
    for (auto it = _pins.begin(); it != _pins.end(); it++) {
        std::cout << "Pin: " << (*it)->getPin() << " State: " << (*it)->getState() << " Type: " << (*it)->getType() << std::endl;
    }
}

Pin *nts::AComponent::getPinAtIndex(std::size_t index)
{
    for (auto it = _pins.begin(); it != _pins.end(); it++) {
        if ((*it)->getPin() == index) {
            return *it;
        }
    }
    return nullptr;
}

Pin *nts::AComponent::getLastPin()
{
    return _pins.back();
}

std::string nts::AComponent::getType() const
{
    return _type;
}

std::list<Pin *> nts::AComponent::getPins() const
{
    return _pins;
}
