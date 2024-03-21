/*
** EPITECH PROJECT, 2024
** B-OOP-400-TLS-4-1-tekspice-louis.huguet
** File description:
** Components4069
*/

#ifndef COMPONENTS4069_HPP_
#define COMPONENTS4069_HPP_

#include "GatesComponents.hpp"

namespace nts
{
    class Components4069 : public GatesComponents{
        public:
            Components4069() {
                initMap(14, 6);
            }
            ~Components4069() = default;;

            void compute() override;
            void initMap(std::size_t numberPin, std::size_t numberImputPin) override;
        protected:
        private:
    };
}

#endif /* !COMPONENTS4069_HPP_ */
