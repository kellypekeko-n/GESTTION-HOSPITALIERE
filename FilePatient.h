//
// Created by Kelly Pekeko on 2/4/2025.
//

#ifndef FILEPATIENT_H
#define FILEPATIENT_H

#define FILE_SIZE 20
#include "Patient.h"
#include <queue>
class FilePatient {


private:
    std::queue<Patient*> patients;

public:
    void enqueue(Patient* patient);
    Patient* dequeue();
    bool isEmpty() const;
    void display() const;
};



#endif //FILEPATIENT_H
