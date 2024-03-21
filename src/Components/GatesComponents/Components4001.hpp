/*
** EPITECH PROJECT, 2024
** B-OOP-400-TLS-4-1-tekspice-louis.huguet
** File description:
** Components4001
*/

#ifndef COMPONENTS4001_HPP_
#define COMPONENTS4001_HPP_

#include "GatesComponents.hpp"

namespace nts
{
    class Components4001 : public GatesComponents {
        public:
            Components4001() {
                initMap(14, 8);
            }
            ~Components4001() = default;

            void compute() override;
        protected:
        private:
    };
}

#endif /* !COMPONENTS4001_HPP_ */
