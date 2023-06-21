//
//  Student.hpp
//  Versuch7
//
//  Created by Julius Wolf on 12.06.23.
//

#ifndef Student_hpp
#define Student_hpp

#include <iostream>
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

    // Comparison operators
    bool operator<(const Student& other) const;
    bool operator>(const Student& other) const;
    bool operator==(const Student& other) const;
};

// Overload the output operator for Student objects
std::ostream& operator<<(std::ostream& os, const Student& student);

#endif /* Student_hpp */

