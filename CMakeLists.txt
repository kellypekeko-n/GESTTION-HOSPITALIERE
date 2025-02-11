cmake_minimum_required(VERSION 3.30)
project(Tp1_Hopital)

set(CMAKE_CXX_STANDARD 20)

add_executable(Tp1_Hopital main.cpp
        HospitalSystem.cpp
        HospitalSystem.h
        PatientManager.cpp
        PatientManager.h
        Patient.cpp
        Patient.h
        Priority.cpp
        Priority.h
        FilePatient.cpp
        FilePatient.h)
