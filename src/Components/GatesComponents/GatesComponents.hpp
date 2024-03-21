/*
** EPITECH PROJECT, 2024
** B-OOP-400-TLS-4-1-tekspice-louis.huguet
** File description:
** GatesComponents
*/

#ifndef GATESCOMPONENTS_HPP_
#define GATESCOMPONENTS_HPP_

#include "../AComponent.hpp" 

namespace nts
{
    class GatesComponents : public AComponent {
        public:
            GatesComponents() = default;
            ~GatesComponents() = default;

            void initMap(std::size_t numberPin, std::size_t numberImputPin) override;
        protected:
        private:
    };
}

#endif /* !GATESCOMPONENTS_HPP_ */
