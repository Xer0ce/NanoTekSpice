/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Paring
*/

#include <sstream>
#include <string>
#include "Parsing.hpp"

Parsing::Parsing(std::string provide_file) {
    _file = provide_file;
    _loopIsRunning = true;
}

Parsing::~Parsing() {}

bool Parsing::checkPart()
{
    std::ifstream ifs;
    std::string result;

    bool chipsets = false;
    bool links = false;

    ifs.open(_file);
    if (!ifs.is_open()) {
        std::cerr << "Error: Can't open file" << std::endl;
        return false;
    }
    while (std::getline(ifs, result)) {
        result = removeComment(result);
        if (result != "") {
            if (result == ".chipsets:")
                chipsets = true;
            if (result == ".links:")
                links = true;
        }

    }
    ifs.close();
    if (chipsets && links)
        return true;
    else {
        if (!chipsets && !links)
            std::cerr << _file << " : \".chipsets\" and \".links\" not found" << std::endl;
        else if (!chipsets)
            std::cerr << _file << " : \".chipsets\" not found" << std::endl;
        else if (!links)
            std::cerr << _file << " : \".links\" not found" << std::endl;
        return false;
    }
}

bool Parsing::initParsing()
{
    if (!checkPart())
        return false;

    std::ifstream ifs;
    std::string result;
    std::size_t numberLine = 1;

    ifs.open(_file);

    if (!ifs.is_open()) {
        std::cerr << "Error: Can't open file" << std::endl;
        return false;
    }

    while (std::getline(ifs, result)) {
        result = removeComment(result);
        _content += result;
        if (result != "")
            startParsing(result, numberLine);
            _content += "\n";
        numberLine ++;
    }
    ifs.close();
    _circuit.changeValueTrueFalse();
    return true;
}

std::string Parsing::removeComment(std::string line)
{
    std::string result;
    std::string::size_type i = 0;

    while (i < line.size()) {
        if (line[i] == '#') {
            break;
        }
        result += line[i];
        i++;
    }
    return result;
}

bool Parsing::containEqual()
{
    std::string::size_type i = 0;

    while (i < _command.size()) {
        if (_command[i] == '=') {
            return true;
        }
        i++;
    }
    return false;
}

bool checkColon(std::string line)
{
    std::string::size_type i = 0;

    while (i < line.size()) {
        if (line[i] == ':') {
            return true;
        }
        i++;
    }
    return false;
}

bool Parsing::makeLink(std::string part1, std::string part2)
{
    return true;
}

bool Parsing::startParsing(std::string line, std::size_t numberLine)
{
    std::istringstream iss(line);
    std::string part1, part2;

    std::getline(iss, part1, ' ');
    std::getline(iss, part2, ' ');

    if (checkColon(part1)) {
        if (part1 == ".chipsets:")
            return true;
        if (part1 == ".links:")
            return true;
        if (part1 == "")
            return true;
        if(_circuit.insertLink(part1, part2) == false) {
            std::cerr << "(Line " << numberLine << ") \"" << line << "\" : Link Error" << std::endl;
            exit(84);
        }
        return true;
    }
    _circuit.insertComponent(part2, createComponent(part1, numberLine));
    return true;
}

bool Parsing::changeComposantValue()
{
    std::istringstream iss(_command);
    std::string part1, part2;
    std::getline(iss, part1, '=');
    std::getline(iss, part2, '=');

    auto it = _circuit.getComponent(part1);
    if (it == nullptr)
        return false;
    if (it->getType() != "input")
        return false;
    if (part2 == "1") {
        it->getLastPin()->setNextState(nts::Tristate::True);
    } else if (part2 == "0") {
        it->getLastPin()->setNextState(nts::Tristate::False);
    } else if (part2 == "U") {
        it->getLastPin()->setNextState(nts::Tristate::Undefined);
    } else {
        return false;
    }
    return true;
}

bool Parsing::getCommandLine()
{
    while (_loopIsRunning) {
        std::cout << "> ";
        std::getline(std::cin, _command);
        if (std::cin.eof()) {
            _loopIsRunning = false;
            continue;
        } else if (_command == "exit") {
            _loopIsRunning = false;
            continue;
        } else if (_command == "display") {
            _circuit.display();
            continue;
        } else if (containEqual()) {
            if (!changeComposantValue())
                std::cout << "Error: Syntax Error" << std::endl;
            continue;
        } else if (_command == "simulate") {
            _circuit.addTick();
            _circuit.executeSimulation();
            continue;
        } else if (_command == "") {
            continue;
        } else if (_command == "dl") {
            _circuit.displayLink();
            continue;
        } else if (_command == "loop") {
            _circuit.loop();
            continue;
        }
        std::cout << _command << " : Unknown command" << std::endl;
    }
    return true;
}

std::string Parsing::getContent()
{
    return _content;
}

void exitProgramCauseAdvanced(std::string type, std::size_t numberLine)
{
    std::cerr << "(Line " << numberLine << ") : Component \"" << type << "\" does not exist." << std::endl;
    exit(84);
}

std::unique_ptr <nts::AComponent> Parsing::createComponent(const std::string &type, std::size_t numberLine)
{
    if (type == "true") {
        return std::make_unique<nts::TrueCmp>();
    } else if (type == "false") {
        return std::make_unique<nts::FalseCmp>();
    } else if (type == "input") {
         return std::make_unique<nts::Input>();
    } else if (type == "clock") {
         return std::make_unique<nts::Clock>();
    } else if (type == "output") {
        return std::make_unique<nts::Output>();
    } else if (type == "and") {
        return std::make_unique<nts::AND>();
    } else if (type == "not") {
        return std::make_unique<nts::NOT>();
    } else if (type == "or") {
        return std::make_unique<nts::OR>();
    } else if (type == "xor") {
        return std::make_unique<nts::XOR>();
    } else if (type == "4001") {
        return std::make_unique<nts::Components4001>();
    } else if (type == "4011") {
        return std::make_unique<nts::Components4011>();
    } else if (type == "4030") {
        return std::make_unique<nts::Components4030>();
    } else if (type == "4069") {
        return std::make_unique<nts::Components4069>();
    } else if (type == "4071") {
        return std::make_unique<nts::Components4071>();
    } else if (type == "4081") {
        return std::make_unique<nts::Components4081>();
    } else {
        exitProgramCauseAdvanced(type, numberLine);
    }
    return nullptr;
}
