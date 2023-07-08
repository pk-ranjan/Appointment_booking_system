//
// Created by ranja on 7/7/2023.
//

#ifndef APPOINTMENTBOOKINGSYSTEM_DOCTORSPRACTICE_H
#define APPOINTMENTBOOKINGSYSTEM_DOCTORSPRACTICE_H
#include <iostream>
#include <vector>
#include "Appointment.h"
#include <stdio.h>

using namespace std;

class DoctorsPractice {
public:
    explicit DoctorsPractice(const string &name);

    virtual ~DoctorsPractice();

    const string &getName() const;

    void setName(const string &name);

    const vector<Appointment *> getAppointmentList() const;

    void setAppointmentList(initializer_list<Appointment *> appointmentList);

    void scheduleAppointment();

    void deleteAppointment();

    void showAppointments(const vector<Appointment*> &appointments);

    void loadAppointments();

    void saveAppointments();

private:
    string name;
    vector<Appointment*> appointmentList;

};

#endif //APPOINTMENTBOOKINGSYSTEM_DOCTORSPRACTICE_H
