/*
** EPITECH PROJECT, 2024
** B-OOP-400-TLS-4-1-tekspice-louis.huguet
** File description:
** Components4011
*/

#ifndef COMPONENTS4011_HPP_
#define COMPONENTS4011_HPP_

#include "GatesComponents.hpp"

namespace nts
{
    class Components4011 : public GatesComponents{
        public:
            Components4011() {
                initMap(14, 8);
            }
            ~Components4011() = default;

            void compute() override;
        protected:
        private:
    };
}

#endif /* !COMPONENTS4011_HPP_ */
