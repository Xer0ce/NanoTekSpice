/*
** EPITECH PROJECT, 2024
** B-OOP-400-TLS-4-1-tekspice-louis.huguet
** File description:
** False
*/

#ifndef FALSE_HPP_
#define FALSE_HPP_

#include "SpecialComponents.hpp"
#include <iostream>

namespace nts
{
    class FalseCmp : public SpecialComponents {
        public:
            FalseCmp() {
                initMap(2, 1);
                _type = "false";
                getLastPin()->setState(nts::Tristate::False);
            }
            ~FalseCmp() = default;

            void compute() override;
            void initMap(std::size_t numberPin, std::size_t numberImputPin) override;

        protected:
        private:
    };
}

#endif /* !FALSE_HPP_ */
