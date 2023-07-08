//
// Created by ranja on 7/7/2023.
//

#include "CallCenter.h"


void CallCenter::dialog() {
    char leave = '1';
    DoctorsPractice *doctorsPractice = new DoctorsPractice("Dr. Koch");
    doctorsPractice->loadAppointments();
    while (leave != 'x') {
        cout << "<-----Welcome to the practice of " << doctorsPractice->getName()<< "----->" << endl;
        cout << "1. Schedule an appointment" << endl;
        cout << "2. Delete an appointment" << endl;
        cout << "3. Show all appointments" << endl;
        cout << "x. Exit program" << endl;
        cout<<endl;
        char val;
        cout << "Enter ";
        cin >> val;
        leave = val;

        switch (val) {
            case '1':
                doctorsPractice->scheduleAppointment();
                break;
            case '2':
                doctorsPractice->deleteAppointment();
                break;
            case '3':
                doctorsPractice->showAppointments(doctorsPractice->getAppointmentList());
                break;
            default:
                break;
        }
    }
    doctorsPractice->saveAppointments();
    delete doctorsPractice;

}
