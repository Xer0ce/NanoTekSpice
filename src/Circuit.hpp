/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Circuit
*/

#ifndef CIRCUIT_HPP_
#define CIRCUIT_HPP_

#include <map>
#include <iostream>
#include <memory>
#include <vector>
#include <sstream>
#include <csignal>
#include "Components/AComponent.hpp"

namespace nts {
    class Circuit {
        public:
            Circuit();
            ~Circuit();
            bool insertComponent(std::string name, std::unique_ptr<AComponent> component);
            void display();
            AComponent *getComponent(std::string name);
            void addTick();
            bool insertLink(std::string firstCmp, std::string secondCmp);
            struct Link {
                std::string firstCmp;
                int firstPin;
                std::string secondCmp;
                int secondPin;
            };
            void displayLink();
            void executeSimulation();
            void dfs(const std::string &currentComponent, std::vector<std::string> &path, std::vector<std::string> &prevPath, std::vector<Link> &links);
            std::map<std::string, int> getLinks(std::string name, int pin);
            void loop();
            void changeValueTrueFalse();

        private:
            std::size_t _tick;
            std::map<std::string, std::unique_ptr<AComponent>> _components;
            std::vector<Link> _links;
    };
}

#endif /* !CIRCUIT_HPP_ */
