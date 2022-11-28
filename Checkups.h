#pragma once

#include "Date.h"
#include "InvalidPasswordExeption.h"
#include "Hash.h"

#include <string>
#include <conio.h>
#include <iostream>
#include <stdexcept>
#include <vector>

using std::string;

const int daysForMonths[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const string letters = "àáâãäå¸æçèéêëìíîïğñòóôõö÷øùúûüışÿÀÁÂÃÄÅ¨ÆÇÈÉÊËÌÍÎÏĞÑÒÓÔÕÖ×ØÙÚÛÜİŞß";

std::string getCorrectStringInput(std::istream& s, const char* message);

std::string getCorrectWordInput(std::istream& s, const char* message);

void checkIfInteger(std::string userInput);

int getCorrectPositiveInteger(std::istream& s, const char* message);

int getCorrectMenuInput(int numberOfMenuItem);

double getCorrectPositiveDouble(std::istream& s, const char* message);

int countAge(int day, int month, int year);

void checkDay(int day, int month, int year);
void checkMonth(int month);
void checkDoctorAge(int day, int month, int year);
void checkPatientAge(int day, int month, int year);

Date getCorrectDateOfBirth(std::istream& s, int role);

int getRole(string login);

int getCorrectFlatNumber(std::istream& s);

string getCorrectEncryptedPassword(std::istream& s);

void endCase();

