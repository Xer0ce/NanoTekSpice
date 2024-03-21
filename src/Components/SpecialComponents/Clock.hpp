/*
** EPITECH PROJECT, 2024
** B-OOP-400-TLS-4-1-tekspice-louis.huguet
** File description:
** Clock
*/

#ifndef CLOCK_HPP_
#define CLOCK_HPP_

#include "SpecialComponents.hpp"
#include "../../Pins/Pin.hpp"

namespace nts {
    class Clock : public SpecialComponents {
        public:
            Clock();
            ~Clock();

            void initMap(std::size_t numberPin, std::size_t numberImputPin) override;
            void compute() override;
    };
}

#endif /* !CLOCK_HPP_ */
