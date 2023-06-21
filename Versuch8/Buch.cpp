//
//  Buch.cpp
//  Versuch8
//
//  Created by Julius Wolf on 20.06.23.
//

#include "Buch.hpp"
#include <string>
#include <iostream>

using namespace std;

Buch::Buch(std::string initTitel, std::string initAutor)
: Medium(initTitel)
, autor(initAutor)
{
}

Buch::~Buch(void)
{
}

void Buch::ausgabe(std::ostream& out) const {
    Medium::ausgabe(out);  // Call the base class implementation

    if (status) {
        out << "Status: Das Buch ist seit dem " << datumAusgeliehen << " an " << personAusgeliehen.getName() << " ausgeliehen." << std::endl;
    } else {
        out << "Status: Buch ist zurzeit nicht verliehen." << std::endl;
    }

    out << "Autor: " << autor << std::endl;
    out << "Titel: " << titel << std::endl;
}

bool Buch::ausleihen(Person person,Datum ausleihdatum)
{
    if (status)
    {
        std::cout << "Das Buch \"" << titel << "\" ist bereits verliehen!" << std::endl;
        return false;
    }
    else
    {
        status = true;
        personAusgeliehen = person;
        datumAusgeliehen = ausleihdatum;
        std::cout << "Das Buch \"" << titel << "\" wird an " << person.getName() << " verliehen." << std::endl;
        return true;
    }
}
