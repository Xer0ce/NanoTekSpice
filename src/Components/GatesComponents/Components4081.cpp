/*
** EPITECH PROJECT, 2024
** B-OOP-400-TLS-4-1-tekspice-louis.huguet
** File description:
** Components4081
*/

#include "Components4081.hpp"

void nts::Components4081::compute()
{
    std::size_t index = 0;
    std::size_t iOutput = 0;

    int i = 1;

    while (i <= 14) {
        if (i == 1) {
            index = 1;
            iOutput = 3;
            i+=3;
        } else if (i == 4) {
            iOutput = 4;
            index = 5;
            i+=4;
        } else if (i == 8) {
            iOutput = 10;
            index = 8;
            i+=3;
        } else if (i == 11) {
            iOutput = 11;
            index = 12;
            i+=4;
        } else {
            std::cout << "Error" << std::endl;
        }

        int stp1 = getPinAtIndex(index)->getState();
        int stp2 = getPinAtIndex(index + 1)->getState();

        if (stp1 == 0 && stp2 == 0)
            getPinAtIndex(iOutput)->setState(nts::Tristate::False);
        if (stp1 == 0 && stp2 == 1)
            getPinAtIndex(iOutput)->setState(nts::Tristate::False);
        if (stp1 == 1 && stp2 == 0)
            getPinAtIndex(iOutput)->setState(nts::Tristate::False);
        if (stp1 == 1 && stp2 == 1)
            getPinAtIndex(iOutput)->setState(nts::Tristate::True);
        if (stp1 == 0 && stp2 == -1)
            getPinAtIndex(iOutput)->setState(nts::Tristate::False);
        if (stp1 == 1 && stp2 == -1)
            getPinAtIndex(iOutput)->setState(nts::Tristate::Undefined);
        if (stp1 == -1 && stp2 == 0)
            getPinAtIndex(iOutput)->setState(nts::Tristate::False);
        if (stp1 == -1 && stp2 == 1)
            getPinAtIndex(iOutput)->setState(nts::Tristate::Undefined);
        if (stp1 == -1 && stp2 == -1)
            getPinAtIndex(iOutput)->setState(nts::Tristate::Undefined);
    }
    return;
}
