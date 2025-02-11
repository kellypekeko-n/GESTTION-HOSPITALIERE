#include "Patient.h"
#include <iostream>

Patient::Patient(std::string name, int age, std::string condition, int turns, std::string specialty) {
    this->name = name;
    this->age = age;
    this->condition = condition;
    this->turnsRemaining=turns;
    this->requiredSpecialty=specialty;

}

std::string Patient::getName() const { return name; }
std::string Patient::getCondition() const { return condition; }
int Patient::getTurnsRemaining() const { return turnsRemaining; }
std::string Patient::getRequiredSpecialty() const { return requiredSpecialty; }

void Patient::decreaseTurnsRemaining() {
    if (turnsRemaining > 0) turnsRemaining--;
}

void Patient::display() const {
    std::cout  << name << std::endl;
}
