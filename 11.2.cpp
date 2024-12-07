#include "11.2.h"

void copyString(char* dest, const char* src, int maxLength) {
    int i;
    for (i = 0; i < maxLength - 1 && src[i] != '\0'; ++i) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
}

void addToTextFile(const char* fileName, const Employee& employee) {
    FILE* file;
    fopen_s(&file, fileName, "a");
    if (file != nullptr) {
        fprintf(file, "%s,%s,%s,%s,%s\n", employee.lastName, employee.firstName, employee.birthYear, employee.phone, employee.city);
        fclose(file);
    }
}

void readFromTextFile(const char* fileName) {
    FILE* file;
    fopen_s(&file, fileName, "r");
    if (file != nullptr) {
        char line[256];
        while (fgets(line, sizeof(line), file)) {
            Employee employee;
            sscanf_s(line, "%[^,],%[^,],%[^,],%[^,],%s", employee.lastName, 20, employee.firstName, 20, employee.birthYear, 20, employee.phone, 20, employee.city, 20);
            cout << "Фамилия: " << employee.lastName << ", Имя: " << employee.firstName << ", Год рождения: " << employee.birthYear << ", Телефон: " << employee.phone << ", Город: " << employee.city << endl;
        }
        fclose(file);
    }
}

void enterValue(const char* message, char* field, int size) {
    cout << message;
    cin.getline(field, size);
}

bool checkFileOpenError(FILE*& file, const char* fileName, const char* mode) {
    fopen_s(&file, fileName, mode);
    if (file == nullptr) {
        cerr << "Ошибка при открытии файла " << fileName << " в режиме " << mode << ".\n";
        return false;
    }
    return true;
}

void checkRenameError(const char* oldName, const char* newName) {
    if (rename(oldName, newName) != 0) {
        cerr << "Ошибка при переименовании\n";
    }
}

void enterEmployeeData(Employee& employee) {
    enterValue("Введите фамилию сотрудника: ", employee.lastName, 20);
    enterValue("Введите имя сотрудника: ", employee.firstName, 20);
    enterValue("Введите год рождения сотрудника: ", employee.birthYear, 20);
    enterValue("Введите телефонный номер сотрудника: ", employee.phone, 20);
    enterValue("Введите место жительства сотрудника: ", employee.city, 20);
}

void suggestAddEmployee(const char* fileName) {
    Employee employee;
    enterEmployeeData(employee);
    addToTextFile(fileName, employee);
}

void suggestDeleteEmployee(const char* fileName, const char* lastName) {
    FILE* file;
    FILE* tempFile;
    if (checkFileOpenError(file, fileName, "r") && checkFileOpenError(tempFile, "temp.txt", "w")) {
        char line[256];
        while (fgets(line, sizeof(line), file)) {
            if (strstr(line, lastName) == nullptr) {
                fputs(line, tempFile);
            }
        }
        fclose(file);
        fclose(tempFile);
        remove(fileName);
        checkRenameError("temp.txt", fileName);
    }
}

void suggestEditEmployee(const char* fileName, const char* lastName, Employee& newEmployee) {
    FILE* file;
    FILE* tempFile;
    if (checkFileOpenError(file, fileName, "r") && checkFileOpenError(tempFile, "temp.txt", "w")) {
        char line[256];
        bool found = false;
        while (fgets(line, sizeof(line), file)) {
            if (strstr(line, lastName) != nullptr) {
                found = true;
                Employee employee;
                sscanf_s(line, "%[^,],%[^,],%[^,],%[^,],%s", employee.lastName, 20, employee.firstName, 20, employee.birthYear, 20, employee.phone, 20, employee.city, 20);

                if (newEmployee.lastName[0] == '\0') copyString(newEmployee.lastName, employee.lastName, 20);
                if (newEmployee.firstName[0] == '\0') copyString(newEmployee.firstName, employee.firstName, 20);
                if (newEmployee.birthYear[0] == '\0') copyString(newEmployee.birthYear, employee.birthYear, 20);
                if (newEmployee.phone[0] == '\0') copyString(newEmployee.phone, employee.phone, 20);
                if (newEmployee.city[0] == '\0') copyString(newEmployee.city, employee.city, 20);

                fprintf(tempFile, "%s,%s,%s,%s,%s\n",
                    newEmployee.lastName,
                    newEmployee.firstName,
                    newEmployee.birthYear,
                    newEmployee.phone,
                    newEmployee.city);
            }
            else {
                fputs(line, tempFile);
            }
        }
        fclose(file);
        fclose(tempFile);
        if (!found) {
            cout << "Сотрудник по фамилии " << lastName << " не найден.\n";
        }
        remove(fileName);
        checkRenameError("temp.txt", fileName);
    }
}

void findEmployeeByLastName(const char* fileName, const char* lastName) {
    FILE* file;
    if (checkFileOpenError(file, fileName, "r")) {
        char line[256];
        bool found = false;
        while (fgets(line, sizeof(line), file)) {
            if (strstr(line, lastName) != nullptr) {
                found = true;
                Employee employee;
                sscanf_s(line, "%[^,],%[^,],%[^,],%[^,],%s", employee.lastName, 20, employee.firstName, 20, employee.birthYear, 20, employee.phone, 20, employee.city, 20);
                cout << "Фамилия: " << employee.lastName << ", Имя: " << employee.firstName << ", Год рождения: " << employee.birthYear << ", Телефон: " << employee.phone << ", Город: " << employee.city << endl;
            }
        }
        if (!found) {
            cout << "Сотрудник по фамилии " << lastName << " не найден.\n";
        }
        fclose(file);
    }
}

void findEmployeesByBirthYear(const char* fileName, const char* birthYear) {
    FILE* file;
    if (checkFileOpenError(file, fileName, "r")) {
        char line[256];
        bool found = false;
        while (fgets(line, sizeof(line), file)) {
            if (strstr(line, birthYear) != nullptr) {
                found = true;
                Employee employee;
                sscanf_s(line, "%[^,],%[^,],%[^,],%[^,],%s", employee.lastName, 20, employee.firstName, 20, employee.birthYear, 20, employee.phone, 20, employee.city, 20);
                cout << "Фамилия: " << employee.lastName << ", Имя: " << employee.firstName << ", Год рождения: " << employee.birthYear << ", Телефон: " << employee.phone << ", Город: " << employee.city << endl;
            }
        }
        if (!found) {
            cout << "Сотрудники с годом рождения" << birthYear << " не найдены.\n";
        }
        fclose(file);
    }
}

void findEmployeesByFirstLetter(const char* fileName, char letter) {
    FILE* file;
    if (checkFileOpenError(file, fileName, "r")) {
        char line[256];
        bool found = false;
        while (fgets(line, sizeof(line), file)) {
            if (line[0] == letter) {
                found = true;
                Employee employee;
                sscanf_s(line, "%[^,],%[^,],%[^,],%[^,],%s", employee.lastName, 20, employee.firstName, 20, employee.birthYear, 20, employee.phone, 20, employee.city, 20);
                cout << "Фамилия: " << employee.lastName << ", Имя: " << employee.firstName << ", Год рождения: " << employee.birthYear << ", Телефон: " << employee.phone << ", Город: " << employee.city << endl;
            }
        }
        if (!found) {
            cout << "Сотрудники с фамилией, начинающейся на букву  " << letter << " не найдены.\n";
        }
        fclose(file);
    }
}
