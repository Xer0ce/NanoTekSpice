/*
** EPITECH PROJECT, 2024
** B-OOP-400-TLS-4-1-tekspice-louis.huguet
** File description:
** XOR
*/

#include "XOR.hpp"

void nts::XOR::compute()
{
    int stp1 = getPinAtIndex(1)->getState();
    int stp2 = getPinAtIndex(2)->getState();

    if (stp1 == 0 && stp2 == 0) {
        getPinAtIndex(3)->setState(nts::Tristate::False);
    } if (stp1 == 0 && stp2 == 1)
        getPinAtIndex(3)->setState(nts::Tristate::True);
    if (stp1 == 1 && stp2 == 0)
        getPinAtIndex(3)->setState(nts::Tristate::True);
    if (stp1 == 1 && stp2 == 1)
        getPinAtIndex(3)->setState(nts::Tristate::False);
    if (stp1 == 0 && stp2 == -1)
        getPinAtIndex(3)->setState(nts::Tristate::Undefined);
    if (stp1 == 1 && stp2 == -1)
        getPinAtIndex(3)->setState(nts::Tristate::Undefined);
    if (stp1 == -1 && stp2 == 0)
        getPinAtIndex(3)->setState(nts::Tristate::Undefined);
    if (stp1 == -1 && stp2 == 1)
        getPinAtIndex(3)->setState(nts::Tristate::Undefined);
    if (stp1 == -1 && stp2 == -1)
        getPinAtIndex(3)->setState(nts::Tristate::Undefined);
    return;
}
