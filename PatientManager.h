//
// Created by Kelly Pekeko on 2/4/2025.
//

#ifndef PATIENTMANAGER_H
#define PATIENTMANAGER_H
#include "FilePatient.h"

#include "Priority.h"


class PatientManager {
private:
    FilePatient lowPriority;
    FilePatient mediumPriority;
    FilePatient highPriority;

public:

  void addPatient(Patient *patient, Priority priority);
    Patient* getNextFor(const std::string& doctor);
    int addTurn();

    void decreaseTurns();

    void displayPatients() const;

    int getNbPatients() const;





};



#endif //PATIENTMANAGER_H
