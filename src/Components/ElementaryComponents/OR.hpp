/*
** EPITECH PROJECT, 2024
** B-OOP-400-TLS-4-1-tekspice-louis.huguet
** File description:
** OR
*/

#ifndef OR_HPP_
#define OR_HPP_

#include "ElementaryComponents.hpp"

namespace nts
{ 
    class OR : public ElementaryComponents {
        public:
            OR() {
                initMap(3, 2);
            }
            ~OR() = default;

            void compute() override;

        protected:
        private:
    };
}

#endif /* !OR_HPP_ */
