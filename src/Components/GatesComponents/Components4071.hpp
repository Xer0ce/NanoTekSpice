/*
** EPITECH PROJECT, 2024
** B-OOP-400-TLS-4-1-tekspice-louis.huguet
** File description:
** Components4071
*/

#ifndef COMPONENTS4071_HPP_
#define COMPONENTS4071_HPP_

#include "GatesComponents.hpp"

namespace nts
{
    class Components4071 : public GatesComponents{
        public:
            Components4071() {
                initMap(14, 8);
            }
            ~Components4071() = default;

            void compute() override;
        protected:
        private:
    };
}

#endif /* !COMPONENTS4071_HPP_ */
