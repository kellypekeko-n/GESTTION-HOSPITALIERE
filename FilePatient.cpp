//
// Created by Kelly Pekeko on 2/4/2025.
//

#include "FilePatient.h"
#include<iostream>
using namespace std;


void FilePatient::enqueue(Patient* patient) {
    patients.push(patient);
}

Patient* FilePatient::dequeue() {
    if (!patients.empty()) {
        Patient* frontPatient = patients.front();
        patients.pop();
        return frontPatient;
    }
    throw std::runtime_error("file is empty!");
}

bool FilePatient::isEmpty() const {
    return patients.empty();
}

void FilePatient::display() const {
    std::queue<Patient*> tempQueue = patients;
    while (!tempQueue.empty()) {
        tempQueue.front()->display();
        tempQueue.pop();
    }
}



