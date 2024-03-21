/*
** EPITECH PROJECT, 2024
** B-OOP-400-TLS-4-1-tekspice-louis.huguet
** File description:
** Input
*/

#ifndef INPUT_HPP_
#define INPUT_HPP_

#include "SpecialComponents.hpp"
#include "../../Pins/Pin.hpp"

namespace nts {
    class Input : public SpecialComponents {
        public:
            Input();
            ~Input();

            void initMap(std::size_t numberPin, std::size_t numberImputPin) override;
            void compute() override;

        protected:
        private:
    };
}

#endif /* !INPUT_HPP_ */
