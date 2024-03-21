/*
** EPITECH PROJECT, 2024
** B-OOP-400-TLS-4-1-tekspice-louis.huguet
** File description:
** True
*/

#ifndef TRUE_HPP_
#define TRUE_HPP_

#include "SpecialComponents.hpp"

namespace nts
{
    class TrueCmp : public SpecialComponents {
        public:
            TrueCmp() {
                initMap(2, 1);
                _type = "true";
                getLastPin()->setState(nts::Tristate::True);
            }
            ~TrueCmp() = default;

            void compute() override;
            void initMap(std::size_t numberPin, std::size_t numberImputPin) override;

        protected:
        private:
    };
}

#endif /* !TRUE_HPP_ */
