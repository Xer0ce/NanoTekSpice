/*
** EPITECH PROJECT, 2024
** B-OOP-400-TLS-4-1-tekspice-louis.huguet
** File description:
** AComponent
*/

#ifndef ACOMPONENT_HPP_
#define ACOMPONENT_HPP_

#include <cstddef>
#include <map>
#include <iostream>
#include <list>
#include "../Pins/Pin.hpp"


namespace nts
{
    class AComponent : public IComponent {
        public:
            AComponent();
            ~AComponent();

            void simulate( std::size_t tick ) override;
            virtual void compute() = 0;
            void setLink(std::size_t pin, IComponent &other, std::size_t otherPin ) override;
            bool getLinkStatus(std::string name, size_t pin) const;
            virtual void initMap(std::size_t numberPin, std::size_t numberImputPin);
            void printMap() const;
            Pin *getPinAtIndex(std::size_t index);
            Pin *getLastPin();
            std::string getType() const;
            std::list<Pin *> getPins() const;

        protected:
            std::list<Pin *> _pins;
            std::string _type;
            bool _alreadySimulate;
    };
}

#endif /* !ACOMPONENT_HPP_ */
