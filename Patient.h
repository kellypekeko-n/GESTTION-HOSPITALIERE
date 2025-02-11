//
// Created by Kelly Pekeko on 2/4/2025.
//
#pragma once
#include <iostream>
using namespace std;

#ifndef PATIENT_H
#define PATIENT_H
#include <string>


class Patient {

private:
   std::string name;
    int age;
    std::string condition;
    int turnsRemaining;
    std::string requiredSpecialty;

public:

   Patient(std::string name, int age, std::string condition, int turns, std::string specialty);
;
    string getName() const ;
   int getAge()const ;
    string getCondition()const ;
    int  getTurnsRemaining()const;
    string getRequiredSpecialty()const;
    void decreaseTurnsRemaining();
   void display()const;
};



#endif //PATIENT_H
