/*
** EPITECH PROJECT, 2024
** B-OOP-400-TLS-4-1-tekspice-louis.huguet
** File description:
** NOT
*/

#ifndef NOT_HPP_
#define NOT_HPP_

#include "ElementaryComponents.hpp"

namespace nts
{ 
    class NOT : public ElementaryComponents {
        public:
            NOT() {
                initMap(2, 1);
            }
            ~NOT() = default;

            void compute() override;

        protected:
        private:
    };
}

#endif /* !NOT_HPP_ */
