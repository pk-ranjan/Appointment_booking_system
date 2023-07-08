cmake_minimum_required(VERSION 3.25)
project(appointmentBookingSystem)

set(CMAKE_CXX_STANDARD 17)

add_executable(appointmentBookingSystem main.cpp CallCenter.h DoctorsPractice.cpp DoctorsPractice.h Appointment.cpp Appointment.h CallCenter.cpp)
