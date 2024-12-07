#pragma once
#include <iostream>
#include <cstdio>
#include <cstring>
#include <windows.h>

using namespace std;

struct Employee {
    char lastName[20];
    char firstName[20];
    char birthYear[20];
    char phone[20];
    char city[20];
};

void copyString(char* dest, const char* src, int maxLength);
void addToTextFile(const char* fileName, const Employee& employee);
void readFromTextFile(const char* fileName);
void enterValue(const char* message, char* field, int size);
bool checkFileOpenError(FILE*& file, const char* fileName, const char* mode);
void checkRenameError(const char* oldName, const char* newName);
void enterEmployeeData(Employee& employee);
void suggestAddEmployee(const char* fileName);
void suggestDeleteEmployee(const char* fileName, const char* lastName);
void suggestEditEmployee(const char* fileName, const char* lastName, Employee& newEmployee);
void findEmployeeByLastName(const char* fileName, const char* lastName);
void findEmployeesByBirthYear(const char* fileName, const char* birthYear);
void findEmployeesByFirstLetter(const char* fileName, char letter);
