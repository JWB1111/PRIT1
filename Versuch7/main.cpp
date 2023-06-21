//
//  main.cpp
//  Versuch7
//
//  Created by Julius Wolf on 12.06.23.
//
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm> // for std::sort and std::find
#include <iterator> // for std::ostream_iterator
#include "Student.hpp"

void printMenu() {
    std::cout << "1. Studierende hinzufuegen\n";
    std::cout << "2. Studierende loeschen\n";
    std::cout << "3. Alle Studierende ausgeben\n";
    std::cout << "4. Alle Studierende in umgekehrter Reihenfolge ausgeben\n";
    std::cout << "5. Datenelement vorne loeschen\n";
    std::cout << "6. Daten aus einer Datei einlesen\n";
    std::cout << "7. Daten in eine Datei sichern\n";
    std::cout << "8. Studierende sortieren\n";
    std::cout << "9. Studierende nach Matrikelnummer suchen und loeschen\n";
    std::cout << "0. Beenden\n";
    std::cout << "Ihre Wahl: ";
}

void addStudent(std::vector<Student>& students) {
    std::string name;
    unsigned int matNr;
    std::string geburtstag;
    std::string adresse;
    std::cout << "Name: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    std::cout << "Matrikelnummer: ";
    std::cin >> matNr;
    std::cout << "Geburtstag: ";
    std::cin.ignore();
    std::getline(std::cin, geburtstag);
    std::cout << "Adresse: ";
    std::getline(std::cin, adresse);
    students.push_back(Student(matNr, name, geburtstag, adresse));
    std::cout << "Studierender hinzugefuegt.\n";
}

void deleteStudent(std::vector<Student>& students) {
    if (students.empty()) {
        std::cout << "Die Liste ist leer.\n";
        return;
    }
    unsigned int matNr;
    std::cout << "Matrikelnummer des zu loeschenden Studierenden: ";
    std::cin >> matNr;
    auto it = std::find_if(students.begin(), students.end(), [matNr](const Student& student) {
        return student.getMatNr() == matNr;
    });
    if (it != students.end()) {
        std::cout << "Studierender geloescht: \n";
        std::cout << *it << std::endl;
        students.erase(it);
    } else {
        std::cout << "Studierender nicht gefunden.\n";
    }
}

void printStudents(const std::vector<Student>& students) {
    if (students.empty()) {
        std::cout << "Die Liste ist leer.\n";
        return;
    }
    for (const auto& student : students) {
        std::cout << student << std::endl;
    }
}

void reversePrintStudents(const std::vector<Student>& students) {
    if (students.empty()) {
        std::cout << "Die Liste ist leer.\n";
        return;
    }
    for (auto it = students.rbegin(); it != students.rend(); ++it) {
        std::cout << *it << std::endl;
    }
}

void deleteFirstStudent(std::vector<Student>& students) {
    if (students.empty()) {
        std::cout << "Die Liste ist leer.\n";
        return;
    }
    students.erase(students.begin());
    std::cout << "Erstes Element geloescht.\n";
}

void readDataFromFile(std::vector<Student>& students) {
    std::string filename;
    std::cout << "Geben Sie den Dateinamen ein: ";
    std::cin.ignore();
    std::getline(std::cin, filename);

    std::ifstream file(filename);
    if (!file) {
        std::cout << "Fehler beim Oeffnen der Datei.\n";
        return;
    }

    students.clear(); // Clear the existing data

    std::string name;
    unsigned int matNr;
    std::string geburtstag;
    std::string adresse;
    while (file >> name >> matNr >> geburtstag >> adresse) {
        students.push_back(Student(matNr, name, geburtstag, adresse));
    }

    std::cout << "Daten wurden aus der Datei eingelesen.\n";
}

void saveDataToFile(const std::vector<Student>& students) {
    std::string filename;
    std::cout << "Geben Sie den Dateinamen ein: ";
    std::cin.ignore();
    std::getline(std::cin, filename);

    std::ofstream file(filename);
    if (!file) {
        std::cout << "Fehler beim Oeffnen der Datei.\n";
        return;
    }

    for (const auto& student : students) {
        file << student.getMatNr() << " " << student.getName() << " "
             << student.getGeburtstag() << " " << student.getAdresse() << "\n";
    }

    std::cout << "Daten wurden in die Datei geschrieben.\n";
}

void sortStudents(std::vector<Student>& students) {
    std::sort(students.begin(), students.end());
    std::cout << "Studierende wurden sortiert.\n";
}

void deleteStudentByMatNr(std::vector<Student>& students) {
    if (students.empty()) {
        std::cout << "Die Liste ist leer.\n";
        return;
    }
    unsigned int matNr;
    std::cout << "Matrikelnummer des zu loeschenden Studierenden: ";
    std::cin >> matNr;
    auto it = std::find_if(students.begin(), students.end(), [matNr](const Student& student) {
        return student.getMatNr() == matNr;
    });
    if (it != students.end()) {
        std::cout << "Studierender gefunden und geloescht: \n";
        std::cout << *it << std::endl;
        students.erase(it);
    } else {
        std::cout << "Studierender nicht gefunden.\n";
    }
}

int main() {
    std::vector<Student> students;
    int choice;

    do {
        printMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                deleteStudent(students);
                break;
            case 3:
                printStudents(students);
                break;
            case 4:
                reversePrintStudents(students);
                break;
            case 5:
                deleteFirstStudent(students);
                break;
            case 6:
                readDataFromFile(students);
                break;
            case 7:
                saveDataToFile(students);
                break;
            case 8:
                sortStudents(students);
                break;
            case 9:
                deleteStudentByMatNr(students);
                break;
            case 0:
                std::cout << "Programm wird beendet.\n";
                break;
            default:
                std::cout << "Ungueltige Eingabe.\n";
        }

        std::cout << std::endl;
    } while (choice != 0);

    return 0;
}
