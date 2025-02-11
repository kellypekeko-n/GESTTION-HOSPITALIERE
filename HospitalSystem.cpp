#include "HospitalSystem.h"
#include <iostream>

HospitalSystem::HospitalSystem(PatientManager* manager, const std::vector<std::string>& doctors)
    : patientManager(manager), doctors(doctors), failureCount(0) {}

void HospitalSystem::addPatient(const Patient& patient, Priority priority) const {
    // Crée une copie dynamique du patient
    Patient* newPatient = new Patient(patient);
    patientManager->addPatient(newPatient, priority);
}


void HospitalSystem::processNextPatient(const std::string& doctor) {
    Patient* patient = patientManager->getNextFor(doctor);

    if (patient) {
        std::cout << "Patient " << patient->getName() << " is being treated by " << doctor << std::endl;
        delete patient; // Supprime le patient après traitement
    }
}


void HospitalSystem::processTurn() {
    for (const std::string& doctor : doctors) {
        processNextPatient(doctor); // Traiter un patient avec chaque médecin
    }

  //  failureCount += patientManager->addTurn(); // Diminuer les tours et compter les échecs
}


void HospitalSystem::displayState() const {
    patientManager->displayPatients();
}

int HospitalSystem::getFailureCount() const {
    return failureCount;
}
