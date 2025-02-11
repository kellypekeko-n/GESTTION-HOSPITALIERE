#include "PatientManager.h"
#include <iostream>

void PatientManager::addPatient(Patient* patient, Priority priority) {
    if (priority == Priority::HIGH)
        highPriority.enqueue(patient);
    else if (priority == Priority::MEDIUM)
        mediumPriority.enqueue(patient);
    else
        lowPriority.enqueue(patient);
}

Patient* PatientManager::getNextFor(const std::string& doctor) {
    if (!highPriority.isEmpty()) return highPriority.dequeue();
    if (!mediumPriority.isEmpty()) return mediumPriority.dequeue();
    if (!lowPriority.isEmpty()) return lowPriority.dequeue();

    return nullptr;
}


int PatientManager::addTurn() {
    int failedPatients = 0;

    std::queue<Patient*> tempQueue;

    while (!highPriority.isEmpty()) {
        Patient* p = highPriority.dequeue();
        p->decreaseTurnsRemaining();

        if (p->getTurnsRemaining() > 0) {
            tempQueue.push(p); // Le patient a encore du temps
        } else {
            delete p; // Supprime les patients échoués
            failedPatients++;
        }
    }

    while (!tempQueue.empty()) { // Remet les patients dans la file
        highPriority.enqueue(tempQueue.front());
        tempQueue.pop();
    }

    return failedPatients;
}


void PatientManager::decreaseTurns() {
    std::queue<Patient*> tempQueue;

    while (!highPriority.isEmpty()) {
        Patient* p = highPriority.dequeue();
        p->decreaseTurnsRemaining();

        if (p->getTurnsRemaining() > 0) {
            tempQueue.push(p); // Encore du temps restant
        } else {
            delete p; // Supprimer les patients traités
        }
    }

    while (!tempQueue.empty()) { // Remettre les patients restants
        highPriority.enqueue(tempQueue.front());
        tempQueue.pop();
    }
}


void PatientManager::displayPatients() const {
    std::cout << "High priority patients:\n";
    highPriority.display();
    std::cout << "Medium priority patients:\n";
    mediumPriority.display();
    std::cout << "Low priority patients:\n";
    lowPriority.display();
}

int PatientManager::getNbPatients() const {
    return (highPriority.isEmpty() ? 0 : 1) + 
           (mediumPriority.isEmpty() ? 0 : 1) + 
           (lowPriority.isEmpty() ? 0 : 1);
}
