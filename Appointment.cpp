//
// Created by ranja on 7/7/2023.
//

#include "Appointment.h"

Appointment::Appointment(const string &date, const string &patient) : date(date), patient(patient) {}

const string &Appointment::getDate() const {
    return date;
}

void Appointment::setDate(const string &date) {
    Appointment::date = date;
}

const string &Appointment::getPatient() const {
    return patient;
}

void Appointment::setPatient(const string &patient) {
    Appointment::patient = patient;
}
