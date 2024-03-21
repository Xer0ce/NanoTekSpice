/*
** EPITECH PROJECT, 2024
** B-OOP-400-TLS-4-1-tekspice-louis.huguet
** File description:
** Pin
*/

#ifndef PIN_HPP_
#define PIN_HPP_

#include <iostream>
#include "../Components/IComponent.hpp"

class Pin {
    public:
        Pin(nts::Tristate state, std::size_t pin, std::size_t type);
        ~Pin() = default;

        void setState(nts::Tristate state);
        nts::Tristate getState() const;
        void setPin(std::size_t pin);
        std::size_t getPin() const;
        void setType(std::string type);
        std::string getType() const;
        void setNextState(nts::Tristate state);
        nts::Tristate getNextState() const;
        void setNewState();

    private:
        nts::Tristate _state;
        nts::Tristate _nextState;
        std::size_t _pin;
        std::string _type;
};

#endif /* !PIN_HPP_ */
