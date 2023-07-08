//
// Created by ranja on 7/7/2023.
//

#include <iomanip>
#include <limits>
#include <string>
#include <cctype>
#include <algorithm>
#include <fstream>
#include "DoctorsPractice.h"


const string &DoctorsPractice::getName() const {
    return name;
}

void DoctorsPractice::setName(const string &name) {
    DoctorsPractice::name = name;
}

const vector<Appointment *> DoctorsPractice::getAppointmentList() const {
    return appointmentList;
}

void DoctorsPractice::setAppointmentList(initializer_list<Appointment *> appointmentList) {
    DoctorsPractice::appointmentList = appointmentList;
}

void DoctorsPractice::scheduleAppointment() {

    cin.ignore(); // This will clear the buffer
    string name;
    cout << "Patient = ";
    getline(cin, name);

    string date;
    cout << "Date = ";
    getline(cin, date);
    cout << endl;

    Appointment *appointment = new Appointment(date, name);
    this->appointmentList.push_back(appointment);
    cout << "Appointment added" << endl;
}

std::string toLowerCase(const std::string &str) {
    std::string lowerCaseStr = str;
    std::transform(lowerCaseStr.begin(), lowerCaseStr.end(), lowerCaseStr.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    return lowerCaseStr;
}

void DoctorsPractice::deleteAppointment() {

    cin.ignore();
    string name;
    cout << "Patient = ";
    getline(cin, name);
    name = toLowerCase(name);

    vector<Appointment *> appointments = {};
    for (auto val: this->appointmentList) {
        string lowerCase = toLowerCase(val->getPatient());
        if (lowerCase.find(name) != std::string::npos) {
            appointments.push_back(val);
        }
    }

    if (!appointments.empty()) {
        cout << endl;
        showAppointments(appointments);
        cout << "Which appointment do you want to delete? Please enter the date: ";
        string date;
        cin >> date;
        bool flag = false;
        this->appointmentList.erase(std::remove_if(appointmentList.begin(), appointmentList.end(),
                                                   [&](Appointment *a) {
                                                       if (a->getDate() == date) {
                                                           delete a;
                                                           flag = true;
                                                           return true;
                                                       }
                                                       return false;
                                                   }), appointmentList.end());
        if (flag)
            cout << "Your requested appointment has been successfully deleted\n";
        else
            cout << "Invalid input\n";

    } else
        cout << "*** There are no appointments for you. ***" << endl;
}


void DoctorsPractice::showAppointments(const vector<Appointment *> &appointments) {
    int columnWidth1 = 25;
    int columnWidth2 = 25;

    cout << "\n";
    cout << left << setw(columnWidth1) << "Date"
         << left << setw(columnWidth2) << "Patient"
         << "\n";
    cout << string(columnWidth1 + columnWidth2, '-') << "\n";

    for (auto val: appointments) {
        cout << left << setw(columnWidth1) << val->getDate()
             << left << setw(columnWidth2) << val->getPatient()
             << "\n";
    }

    cout << "\n";
}

DoctorsPractice::~DoctorsPractice() {
    for (auto val: appointmentList)
        delete val;
}

DoctorsPractice::DoctorsPractice(const string &name) : name(name) {
    this->appointmentList = {};
}

void DoctorsPractice::loadAppointments() {

    std::ifstream file("appointments.txt");

    if (file.is_open()) {
        std::string line;
        while (getline(file, line)) {
            std::stringstream ss(line);
            std::string patientName;
            std::string date;
            getline(ss, patientName, ';');
            getline(ss, date, ';');
            appointmentList.push_back(new Appointment(date, patientName));
        }
        file.close();
    } else {
        std::cout << "Failed to open file for reading.\n";
    }
}

void DoctorsPractice::saveAppointments() {
    std::string filename = "appointments.txt";
    std::ofstream file(filename);

    if (file.is_open()) {
        for (auto val: appointmentList) {
            file << val->getPatient() << ';' << val->getDate() << "\n";
        }

        file.close();
    } else {
        std::cout << "Unable to open file for writing\n";
    }

}
