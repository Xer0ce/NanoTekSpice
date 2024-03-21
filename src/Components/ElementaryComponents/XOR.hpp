/*
** EPITECH PROJECT, 2024
** B-OOP-400-TLS-4-1-tekspice-louis.huguet
** File description:
** XOR
*/

#ifndef XOR_HPP_
#define XOR_HPP_

#include "ElementaryComponents.hpp"

namespace nts
{
    class XOR : public ElementaryComponents {
        public:
            XOR() {
                initMap(3, 2);
            }
            ~XOR() = default;

            void compute() override;

        protected:
        private:
    };
}

#endif /* !XOR_HPP_ */
