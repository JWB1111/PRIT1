//
//  main.cpp
//  Versuch6
//
//  Created by Julius Wolf on 12.06.23.
//

#include <iostream>
#include <fstream>
#include <vector>
#include "Student.hpp"

void printMenu() {
    std::cout << "1. Studierende hinzufuegen\n";
    std::cout << "2. Studierende loeschen\n";
    std::cout << "3. Alle Studierende ausgeben\n";
    std::cout << "4. Alle Studierende in umgekehrter Reihenfolge ausgeben\n";
    std::cout << "5. Datenelement vorne loeschen\n";
    std::cout << "6. Daten aus einer Datei einlesen\n";
    std::cout << "7. Daten in eine Datei sichern\n";
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
    std::cin.ignore();
    std::getline(std::cin, adresse);
    
    students.push_back(Student(matNr, name, geburtstag, adresse));
}

void deleteStudent(std::vector<Student>& students) {
    if (students.empty()) {
        std::cout << "Die Liste ist leer.\n";
        return;
    }
    int matrikelnummer;
    std::cout << "Matrikelnummer des zu loeschenden Studierenden: ";
    std::cin >> matrikelnummer;
    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->getMatNr() == matrikelnummer) {
            std::cout << "Studierender geloescht: ";
            it->ausgabe();
            students.erase(it);
            return;
        }
    }
    std::cout << "Studierender nicht gefunden.\n";
}

void printStudents(const std::vector<Student>& students) {
    if (students.empty()) {
        std::cout << "Die Liste ist leer.\n";
        return;
    }
    for (const auto& student : students) {
        student.ausgabe();
    }
}

void printStudentsReverse(const std::vector<Student>& students) {
    if (students.empty()) {
        std::cout << "Die Liste ist leer.\n";
        return;
    }
    for (auto it = students.rbegin(); it != students.rend(); ++it) {
        it->ausgabe();
    }
}

void deleteFront(std::vector<Student>& students) {
    if (students.empty()) {
        std::cout << "Die Liste ist leer.\n";
        return;
    }
    std::cout << "Studierender geloescht: ";
    students.front().ausgabe();
    students.erase(students.begin());
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
    std::string matrikelnummerStr; // Store matrikelnummer as string temporarily
    while (file >> name >> matrikelnummerStr) {
        unsigned int matNr;
        try {
            matNr = std::stoi(matrikelnummerStr); // Convert string to unsigned int
        } catch (const std::exception& e) {
            std::cout << "Invalid matrikelnummer: " << matrikelnummerStr << std::endl;
            continue; // Skip this line and proceed to the next one
        }
        students.push_back(Student(matNr, name, "", "")); // Adjust arguments based on Student constructor
    }

    std::cout << "Daten wurden aus der Datei eingelesen.\n";
}


void saveDataToFile(const std::vector<Student>& students) {
    std::string filename;
    std::cout << "Geben Sie den Dateinamen zum Speichern ein: ";
    std::cin.ignore();
    std::getline(std::cin, filename);

    std::ofstream file(filename);
    if (!file) {
        std::cout << "Fehler beim Oeffnen der Datei.\n";
        return;
    }

    for (const auto& student : students) {
        file << student.getName() << " " << student.getMatNr() << "\n";
    }

    std::cout << "Daten wurden in die Datei gesichert.\n";
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
                printStudentsReverse(students);
                break;
            case 5:
                deleteFront(students);
                break;
            case 6:
                readDataFromFile(students);
                break;
            case 7:
                saveDataToFile(students);
                break;
            case 0:
                std::cout << "Programm wird beendet.\n";
                break;
            default:
                std::cout << "Ungueltige Eingabe.\n";
                break;
        }
    } while (choice != 0);

    return 0;
}

