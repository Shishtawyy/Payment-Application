cmake_minimum_required(VERSION 3.22)
project(Payment_Application C)

set(CMAKE_C_STANDARD 99)

add_executable(Payment_Application main.c App/App.c App/App.h Card/Card.c Card/Card.h Server/Server.c Server/Server.h Terminal/Terminal.c Terminal/Terminal.h)
