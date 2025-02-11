#include <iostream>
#include <vector>
#include "HospitalSystem.h"


Priority categorizeCondition(const std::string& condition) {
 if (condition == "Crise cardiaque") {
  return Priority::HIGH;
 }
 if (condition == "Méralgie") {
  return Priority::MEDIUM;
 }
 return Priority::LOW;
}

int main() {

 // Create a list of doctors
 std::vector<std::string> doctors = {"Cardiologue", "Généraliste",
"Pneumologue", "Orthopédiste"};
 PatientManager manager{};
 HospitalSystem hospital(&manager, doctors);
std::vector<Patient> patients = {
 Patient("Manon Dupont", 19, "Méralgie", 3, "Généraliste"),
 Patient("Jean Lambert", 25, "Crise cardiaque", 1, "Cardiologue"),
 Patient("Julie Marchand", 41, "Hypertension", 2, "Cardiologue"),
 Patient("Lucie Lefevre", 32, "Asthme", 2, "Pneumologue"),
};
 // Add patients to the hospital
 for (const Patient& patient : patients) {
 hospital.addPatient(patient,
categorizeCondition(patient.getCondition()));
 }
 for (int nbTour=1;manager.getNbPatients() > 0;nbTour++) {
 std::cout << "Tour " << nbTour << ":" << std::endl;
 hospital.displayState();
 hospital.processTurn();
 std::cout << "--------------------------------" << std::endl;
 }
 std::cout << "Nombre de patients non traités: " << hospital.getFailureCount()
<< std::endl;
 std::cout << "Pourcentage traité : " << (1 -
(float)hospital.getFailureCount() / patients.size()) * 100 << "%" << std::endl;
 return 0;
}