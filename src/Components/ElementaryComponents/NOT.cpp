/*
** EPITECH PROJECT, 2024
** B-OOP-400-TLS-4-1-tekspice-louis.huguet
** File description:
** NOT
*/

#include "NOT.hpp"

void nts::NOT::compute()
{
    int stp1 = getPinAtIndex(1)->getState();

    if (stp1 == 0)
        getPinAtIndex(2)->setState(nts::Tristate::True);
    if (stp1 == 1)
        getPinAtIndex(2)->setState(nts::Tristate::False);
    if (stp1 == -1)
        getPinAtIndex(2)->setState(nts::Tristate::Undefined);
    return;
}
