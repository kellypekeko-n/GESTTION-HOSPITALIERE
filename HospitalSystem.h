//
// Created by Kelly Pekeko on 2/4/2025.
//

#ifndef HOSPITALSYSTEM_H
#define HOSPITALSYSTEM_H
#include <vector>
#include <string>
#include "PatientManager.h"


class HospitalSystem {
private:
PatientManager* patientManager;
    std::vector<std::string> doctors;
    int failureCount; // nombre de patient non traite

    public:
    HospitalSystem(PatientManager* manager, const std::vector<std::string>& doctors);

    void addPatient(const Patient& patient, Priority priority) const;

void processNextPatient(const std::string &doctor);


void processNextPaient(const std:: string& doctor);
    void processTurn();
    void displayState()const;
    int getFailureCount()const;// retourne le nombre total de patient
void addPatient(const Patient * patient, Priority priority);
};



#endif //HOSPITALSYSTEM_H
