#include "11.2.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const char* fileName = "file1.txt";

    readFromTextFile(fileName);

    char choice;
    do {
        cout << "\nВыберите действие:\n";
        cout << "1. Добавить сотрудника\n";
        cout << "2. Удалить сотрудника\n";
        cout << "3. Изменить данные сотрудника\n";
        cout << "4. Найти сотрудника по фамилии\n";
        cout << "5. Найти сотрудников по году рождения\n";
        cout << "6. Найти сотрудников по начальной букве фамилии\n";
        cout << "7. Вывести весь список сотрудников\n";
        cout << "8. Выйти\n";
        cout << "Ваш выбор: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case '1':
            suggestAddEmployee(fileName);
            break;
        case '2': {
            char lastName[20];
            enterValue("Введите фамилию сотрудника для удаления: ", lastName, 20);
            suggestDeleteEmployee(fileName, lastName);
            break;
        }
        case '3': {
            char lastName[20];
            int field;
            Employee newEmployee = {};

            cout << "Введите фамилию сотрудника для изменения данных: ";
            cin.getline(lastName, 20);

            cout << "\nВыберите, что вы хотите изменить:\n";
            cout << "1. Фамилия\n";
            cout << "2. Имя\n";
            cout << "3. Год рождения\n";
            cout << "4. Телефон\n";
            cout << "5. Место жительства\n";
            cout << "Ваш выбор: ";
            cin >> field;
            cin.ignore();

            switch (field) {
            case 1:
                enterValue("Введите новую фамилию сотрудника: ", newEmployee.lastName, 20);
                break;
            case 2:
                enterValue("Введите новое имя сотрудника: ", newEmployee.firstName, 20);
                break;
            case 3:
                enterValue("Введите новую дату рождения сотрудника: ", newEmployee.birthYear, 20);
                break;
            case 4:
                enterValue("Введите новый номер телефона сотрудника: ", newEmployee.phone, 20);
                break;
            case 5:
                enterValue("Введите новое место жительства сотрудника: ", newEmployee.city, 20);
                break;
            default:
                cout << "Неверный выбор.\n";
                break;
            }
            suggestEditEmployee(fileName, lastName, newEmployee);
            break;
        }
        case '4': {
            char lastName[20];
            enterValue("Введите фамилию для поиска: ", lastName, 20);
            findEmployeeByLastName(fileName, lastName);
            break;
        }
        case '5': {
            char birthYear[20];
            enterValue("Введите год рождения для поиска: ", birthYear, 20);
            findEmployeesByBirthYear(fileName, birthYear);
            break;
        }
        case '6': {
            char letter;
            cout << "Введите первую букву фамилии для поиска: ";
            cin >> letter;
            cin.ignore();
            findEmployeesByFirstLetter(fileName, letter);
            break;
        }
        case '7':
            readFromTextFile(fileName);
            break;
        case '8':
            cout << "Выход\n";
            break;
        default:
            cout << "Неверный выбор. Пожалуйста, попробуйте снова.\n";
        }
    } while (choice != '8');

    return 0;
}
