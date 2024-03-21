/*
** EPITECH PROJECT, 2024
** B-OOP-400-TLS-4-1-tekspice-louis.huguet
** File description:
** Components4030
*/

#ifndef COMPONENTS4030_HPP_
#define COMPONENTS4030_HPP_

#include "GatesComponents.hpp"

namespace nts
{
    class Components4030 : public GatesComponents {
        public:
            Components4030() {
                initMap(14, 8);
            }
            ~Components4030() = default;

            void compute() override;
        protected:
        private:
    };
}

#endif /* !COMPONENTS4030_HPP_ */
