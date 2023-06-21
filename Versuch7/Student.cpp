//
//  Student.cpp
//  Versuch7
//
//  Created by Julius Wolf on 12.06.23.
//

#include "Student.hpp"

Student::Student(unsigned int matNr, std::string name, std::string geburtstag, std::string adresse)
    : matNr(matNr), name(std::move(name)), geburtstag(std::move(geburtstag)), adresse(std::move(adresse))
{
}

Student::Student() : matNr(0)
{
}

unsigned int Student::getMatNr() const
{
    return matNr;
}

std::string Student::getName() const
{
    return name;
}

std::string Student::getGeburtstag() const
{
    return geburtstag;
}

std::string Student::getAdresse() const
{
    return adresse;
}

void Student::ausgabe() const
{
    std::cout << "Matrikelnummer: " << matNr << "\n"
              << "Name: " << name << "\n"
              << "Geburtstag: " << geburtstag << "\n"
              << "Adresse: " << adresse << "\n";
}

bool Student::operator<(const Student& other) const
{
    return matNr < other.matNr;
}

bool Student::operator>(const Student& other) const
{
    return matNr > other.matNr;
}

bool Student::operator==(const Student& other) const
{
    return matNr == other.matNr;
}

std::ostream& operator<<(std::ostream& os, const Student& student)
{
    os << "Matrikelnummer: " << student.getMatNr() << "\n"
       << "Name: " << student.getName() << "\n"
       << "Geburtstag: " << student.getGeburtstag() << "\n"
       << "Adresse: " << student.getAdresse() << "\n";
    return os;
}

