/*
** EPITECH PROJECT, 2024
** B-OOP-400-TLS-4-1-tekspice-louis.huguet
** File description:
** Components4081
*/

#ifndef COMPONENTS4081_HPP_
#define COMPONENTS4081_HPP_

#include "GatesComponents.hpp"

namespace nts
{
    class Components4081 : public GatesComponents{
        public:
            Components4081() {
                initMap(14, 8);
            }
            ~Components4081() = default;

            void compute() override;
        protected:
        private:
    };
}

#endif /* !COMPONENTS4081_HPP_ */
