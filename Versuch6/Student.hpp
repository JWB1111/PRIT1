//
//  Student.hpp
//  Versuch6
//
//  Created by Julius Wolf on 12.06.23.
//

#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>

class Student
{
private:
    unsigned int matNr;
    std::string name;
    std::string geburtstag;
    std::string adresse;

public:
    Student(unsigned int matNr, std::string name, std::string geburtstag, std::string adresse);
    Student();
    unsigned int getMatNr() const;
    std::string getName() const;
    std::string getGeburtstag() const;
    std::string getAdresse() const;
    void ausgabe() const;
};

#endif /* STUDENT_HPP */
