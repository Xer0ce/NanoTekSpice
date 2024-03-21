/*
** EPITECH PROJECT, 2024
** B-OOP-400-TLS-4-1-tekspice-louis.huguet
** File description:
** IComponent
*/

#include <cstddef>

namespace nts
{
    enum Tristate {
        Undefined = (-true),
        True = true,
        False = false,
    };
    class IComponent
    {
        public:
            virtual ~IComponent() = default;
            virtual void simulate( std::size_t tick ) = 0;
            virtual void compute() = 0;
            virtual void setLink( std::size_t pin, nts::IComponent &other, std::size_t otherPin ) = 0;
    };
}
