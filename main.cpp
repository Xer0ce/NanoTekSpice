/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** main
*/

#include <string.h>
#include <iostream>
#include <memory>
#include "src/Components/AComponent.hpp"
#include "src/Components/SpecialComponents/False.hpp"
#include "src/Components/SpecialComponents/True.hpp"

#include "src/Parsing.hpp"

bool hasEnding(std::string const &fullString, std::string const &ending)
{
    if (fullString.length() - 1 >= ending.length()) {
        return (0 == fullString.compare(fullString.length() - ending.length(), ending.length(), ending));
    } else {
        return false;
    }
}

bool errorGestion(int ac, char **av)
{
    std::string config_file;

    if (ac != 2) {
        std::cerr << "Usage: " << av[0] << " [config_file].nts" << std::endl;
        return false;
    }
    if (strncmp(av[1], "-h", 2) == 0) {
        std::cout << "Usage: " << av[0] << " [config_file].nts" << std::endl;
        return true;
    }
    config_file = av[1];
    if (!hasEnding(config_file, ".nts")) {
        std::cerr << "Error: Invalid file extension" << std::endl;
        return false;
    }
    return true;
}

int main (int ac, char **av)
{
    if (!errorGestion(ac, av))
        return 84;
    Parsing parsing (av[1]);
    if (!parsing.initParsing())
        return 84;
    parsing.getCommandLine();
    return 0;
}
