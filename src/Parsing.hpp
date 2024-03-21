/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Paring
*/

#ifndef PARING_HPP_
#define PARING_HPP_

#include <iostream>
#include <fstream>
#include <map>
#include <memory>
#include "Circuit.hpp"

#include "Components/SpecialComponents/True.hpp"
#include "Components/SpecialComponents/False.hpp"
#include "Components/SpecialComponents/Output.hpp"
#include "Components/SpecialComponents/Input.hpp"
#include "Components/SpecialComponents/Clock.hpp"
#include "Components/ElementaryComponents/AND.hpp"
#include "Components/ElementaryComponents/NOT.hpp"
#include "Components/ElementaryComponents/OR.hpp"
#include "Components/ElementaryComponents/XOR.hpp"
#include "Components/GatesComponents/Components4001.hpp"
#include "Components/GatesComponents/Components4011.hpp"
#include "Components/GatesComponents/Components4030.hpp"
#include "Components/GatesComponents/Components4069.hpp"
#include "Components/GatesComponents/Components4071.hpp"
#include "Components/GatesComponents/Components4081.hpp"

class Parsing {
    public:
        Parsing(std::string provide_file = "None");
        ~Parsing();

        bool checkPart();
        bool initParsing();
        std::string removeComment(std::string line);
        bool containEqual();
        bool makeLink(std::string line, std::string name);
        bool startParsing(std::string line, std::size_t numberLine);
        bool changeComposantValue();
        bool getCommandLine();
        std::string getContent();
        std::unique_ptr <nts::AComponent> createComponent(const std::string &type, std::size_t numberLine);

    private:
        std::string _file;
        std::string _content;

        bool _loopIsRunning;
        std::string _command;
        std::string _component;
        std::string _name_component;
        nts::Circuit _circuit;
};

#endif /* !PARING_HPP_ */
