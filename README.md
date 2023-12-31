# Appointment Booking System

This is a console-based application written in C++, designed for the management of appointments in a doctor's practice. The application provides functionality to add, delete, and view appointments.

## Features

- **Add Appointment**: Allows users to add a new appointment by entering the patient's name and the appointment date.
- **Delete Appointment**: Enables users to delete an existing appointment by providing the patient's name and the appointment date.
- **View Appointments**: Allows users to view all the existing appointments in a nicely formatted list.

## Classes Overview

- **Appointment**: This class represents an individual appointment. It stores information such as the appointment date and the name of the patient.
- **DoctorsPractice**: This class represents the doctor's practice. It maintains a list of all the appointments and provides functions to create, delete, and display appointments.
- **CallCenter**: This class handles the user interface and user input, providing an interactive console interface to operate the appointment system.

## Getting Started

To clone this repository, run the following command in your terminal:
```
git clone https://github.com/pk-ranjan/Appointment_booking_system.git
```
Then, navigate to the project directory and build the project:
```
cd AppointmentBookingSystem
mkdir build && cd build
cmake ..
make
```
Now, run the application:
```
./AppointmentBookingSystem
```
Enjoy managing your appointments!
