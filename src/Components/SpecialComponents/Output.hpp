/*
** EPITECH PROJECT, 2024
** B-OOP-400-TLS-4-1-tekspice-louis.huguet
** File description:
** Output
*/

#ifndef OUTPUT_HPP_
#define OUTPUT_HPP_

#include "SpecialComponents.hpp"
#include "../../Pins/Pin.hpp"

namespace nts {
    class Output : public SpecialComponents {
        public:
            Output();
            ~Output();

            void initMap(std::size_t numberPin, std::size_t numberImputPin) override;
            void compute() override;

        protected:
        private:
    };
}

#endif /* !OUTPUT_HPP_ */
