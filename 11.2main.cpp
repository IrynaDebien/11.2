#include "11.2.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const char* fileName = "file1.txt";

    readFromTextFile(fileName);

    char choice;
    do {
        cout << "\n�������� ��������:\n";
        cout << "1. �������� ����������\n";
        cout << "2. ������� ����������\n";
        cout << "3. �������� ������ ����������\n";
        cout << "4. ����� ���������� �� �������\n";
        cout << "5. ����� ����������� �� ���� ��������\n";
        cout << "6. ����� ����������� �� ��������� ����� �������\n";
        cout << "7. ������� ���� ������ �����������\n";
        cout << "8. �����\n";
        cout << "��� �����: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case '1':
            suggestAddEmployee(fileName);
            break;
        case '2': {
            char lastName[20];
            enterValue("������� ������� ���������� ��� ��������: ", lastName, 20);
            suggestDeleteEmployee(fileName, lastName);
            break;
        }
        case '3': {
            char lastName[20];
            int field;
            Employee newEmployee = {};

            cout << "������� ������� ���������� ��� ��������� ������: ";
            cin.getline(lastName, 20);

            cout << "\n��������, ��� �� ������ ��������:\n";
            cout << "1. �������\n";
            cout << "2. ���\n";
            cout << "3. ��� ��������\n";
            cout << "4. �������\n";
            cout << "5. ����� ����������\n";
            cout << "��� �����: ";
            cin >> field;
            cin.ignore();

            switch (field) {
            case 1:
                enterValue("������� ����� ������� ����������: ", newEmployee.lastName, 20);
                break;
            case 2:
                enterValue("������� ����� ��� ����������: ", newEmployee.firstName, 20);
                break;
            case 3:
                enterValue("������� ����� ���� �������� ����������: ", newEmployee.birthYear, 20);
                break;
            case 4:
                enterValue("������� ����� ����� �������� ����������: ", newEmployee.phone, 20);
                break;
            case 5:
                enterValue("������� ����� ����� ���������� ����������: ", newEmployee.city, 20);
                break;
            default:
                cout << "�������� �����.\n";
                break;
            }
            suggestEditEmployee(fileName, lastName, newEmployee);
            break;
        }
        case '4': {
            char lastName[20];
            enterValue("������� ������� ��� ������: ", lastName, 20);
            findEmployeeByLastName(fileName, lastName);
            break;
        }
        case '5': {
            char birthYear[20];
            enterValue("������� ��� �������� ��� ������: ", birthYear, 20);
            findEmployeesByBirthYear(fileName, birthYear);
            break;
        }
        case '6': {
            char letter;
            cout << "������� ������ ����� ������� ��� ������: ";
            cin >> letter;
            cin.ignore();
            findEmployeesByFirstLetter(fileName, letter);
            break;
        }
        case '7':
            readFromTextFile(fileName);
            break;
        case '8':
            cout << "�����\n";
            break;
        default:
            cout << "�������� �����. ����������, ���������� �����.\n";
        }
    } while (choice != '8');

    return 0;
}
