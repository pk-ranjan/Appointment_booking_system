//
// Created by ranja on 7/7/2023.
//

#ifndef APPOINTMENTBOOKINGSYSTEM_APPOINTMENT_H
#define APPOINTMENTBOOKINGSYSTEM_APPOINTMENT_H
#include <iostream>
using namespace std;

class Appointment {
public:
    Appointment(const string &date, const string &patient);

    const string &getDate() const;

    void setDate(const string &date);

    const string &getPatient() const;

    void setPatient(const string &patient);

private:
    string date;
    string patient;
};

#endif //APPOINTMENTBOOKINGSYSTEM_APPOINTMENT_H
