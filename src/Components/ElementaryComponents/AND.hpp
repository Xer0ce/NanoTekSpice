/*
** EPITECH PROJECT, 2024
** B-OOP-400-TLS-4-1-tekspice-louis.huguet
** File description:
** AND
*/

#ifndef AND_HPP_
#define AND_HPP_

#include "ElementaryComponents.hpp"

namespace nts
{
    class AND : public ElementaryComponents{
        public:
            AND() {
                initMap(3, 2);
                _type = "and";
            }
            ~AND() = default;

            void compute() override;

        protected:
        private:
    };
}

#endif /* !AND_HPP_ */
