/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Cicuit
*/

#include <algorithm>
#include "Circuit.hpp"

volatile sig_atomic_t loopIsRunning = 1;

namespace nts {
    Circuit::Circuit()
    {
        _tick = 0;
    }

    Circuit::~Circuit()
    {
    }

    bool Circuit::insertComponent(std::string name, std::unique_ptr<AComponent> component)
    {
        _components.insert(std::make_pair(name, std::move(component)));
        if (_components.find(name) == _components.end())
            return false;
        return true;
    }

    void Circuit::display()
    {
        std::cout << "tick: " << _tick << std::endl;
        std::cout << "input(s):" << std::endl;
        for (auto it = _components.begin(); it != _components.end(); it++) {
            if (it->second != nullptr) {
                if (it->second->getType() == "input") {
                    std::cout << "  " << it->first << ": ";
                    nts::Tristate state = it->second->getLastPin()->getState();
                    if (state == nts::Tristate::Undefined)
                        std::cout << "U" << std::endl;
                    else
                        std::cout << state << std::endl;
                }
            }
        }
        std::cout << "output(s):" << std::endl;
        for (auto it = _components.begin(); it != _components.end(); it++) {
            if (it->second != nullptr) {
                if (it->second->getType() == "output") {
                    std::cout << "  " << it->first << ": ";
                    nts::Tristate state = it->second->getLastPin()->getState();
                    if (state == nts::Tristate::Undefined)
                        std::cout << "U" << std::endl;
                    else
                        std::cout << state << std::endl;
                }
            }
        }
    }

    AComponent *Circuit::getComponent(std::string name)
    {
        if (_components.find(name) == _components.end())
            return nullptr;
        return _components.at(name).get();
    }

    void Circuit::addTick()
    {
        _tick++;
    }

    bool Circuit::insertLink(std::string firstCmp, std::string secondCmp)
    {
        std::istringstream iss(firstCmp);
        std::string part1, part2;
        std::getline(iss, part1, ':');
        std::getline(iss, part2, ':');

        std::istringstream iss2(secondCmp);
        std::string part3, part4;
        std::getline(iss2, part3, ':');
        std::getline(iss2, part4, ':');

        if (_components.find(part1) == _components.end() || _components.find(part3) == _components.end())
            return false;
        if (std::stoi(part2) > getComponent(part1)->getPins().size())
            return false;
        if (std::stoi(part4) > getComponent(part3)->getPins().size())
            return false;
        _links.push_back({part1, std::stoi(part2), part3, std::stoi(part4)});
        return true;
    }

    void Circuit::displayLink()
    {
        for (auto it = _links.begin(); it != _links.end(); it++) {
            std::cout << it->firstCmp << ":" << it->firstPin << " -> " << it->secondCmp << ":" << it->secondPin << std::endl;
        }
    }

    void Circuit::executeSimulation() {
        std::vector<std::string> prevPath;

        for (auto &component : _components) {
            if (component.second->getType() == "output") {
                std::vector<std::string> path;
                path.push_back(component.first);

                std::vector<Link> originalLinks = _links;

                dfs(component.first, path, prevPath, originalLinks);
            }
        }
    }

    void Circuit::dfs(const std::string &currentComponent, std::vector<std::string> &path, std::vector<std::string> &prevPath, std::vector<Link> &links) {
        std::vector<Link> localLinks = links;

        for (auto it = localLinks.begin(); it != localLinks.end(); ) {
            if (it->secondCmp == currentComponent) {
                if (std::find(path.begin(), path.end(), it->firstCmp) == path.end()) {
                    path.push_back(it->firstCmp);
                    it = localLinks.erase(it);
                    dfs(it->firstCmp, path, prevPath, localLinks);
                    path.pop_back();
                } else {
                    ++it;
                }
            } else if (it->firstCmp == currentComponent) {
                if (std::find(path.begin(), path.end(), it->secondCmp) == path.end()) {
                    path.push_back(it->secondCmp);
                    it = localLinks.erase(it);
                    dfs(it->secondCmp, path, prevPath, localLinks);
                    path.pop_back();
                } else {
                    ++it;
                }
            } else {
                ++it;
            }
        }

        if (path.size() > 1) {
            if (getComponent(path.back())->getType() == "input") {
                getComponent(path.back())->getLastPin()->setNewState();
                getComponent(path.back())->compute();
                std::map<std::string, int> links = getLinks(path.back(), 1);
                getComponent(links.begin()->first)->getPinAtIndex(links.begin()->second)->setState(getComponent(path.back())->getLastPin()->getState());
            } else if (getComponent(path.back())->getType() != "input") {
                getComponent(path.back())->compute();
                std::list <Pin *> pins = getComponent(path.back())->getPins();
                for (auto &pin : pins) {
                    if (pin->getType() == "output") {
                        std::map<std::string, int> links = getLinks(path.back(), (pin->getPin()));
                        getComponent(links.begin()->first)->getPinAtIndex(links.begin()->second)->setState(pin->getState());
                    }
                }
            }
        }
    }

    std::map<std::string, int> Circuit::getLinks(std::string name, int pin)
    {
        std::map<std::string, int> links;
        for (auto it = _links.begin(); it != _links.end(); it++) {
            if (it->firstCmp == name && it->firstPin == pin) {
                links.insert(std::make_pair(it->secondCmp, it->secondPin));
            }
        }
        for (auto it = _links.begin(); it != _links.end(); it++) {
            if (it->secondCmp == name && it->secondPin == pin) {
                links.insert(std::make_pair(it->firstCmp, it->firstPin));
            }
        }
        return links;
    }

    void signalHandler(int signum) {
       loopIsRunning = 0;
    }

    void Circuit::loop()
    {
        signal(SIGINT, signalHandler);
        while (loopIsRunning) {
            addTick();
            executeSimulation();
        }
        loopIsRunning = 1;
    }

    void Circuit::changeValueTrueFalse()
    {
        for (auto it = _components.begin(); it != _components.end(); it++) {
            if (it->second->getType() == "input") {
                std::map<std::string, int> links = getLinks(it->first, 1);
                getComponent(links.begin()->first)->getPinAtIndex(links.begin()->second)->setState(it->second->getLastPin()->getState());
            }
            if (it->second->getType() == "output") {
                std::map<std::string, int> links = getLinks(it->first, 1);
                it->second->getLastPin()->setState(getComponent(links.begin()->first)->getPinAtIndex(links.begin()->second)->getState());
            }
        }
    }
}
