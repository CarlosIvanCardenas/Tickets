cmake_minimum_required(VERSION 3.8)
project(Tickets)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Usuario.h Cartelera.h Evento.h Boleto.h)
add_executable(Tickets ${SOURCE_FILES})