//
//  Medium.cpp
//  Versuch8
//
//  Created by Julius Wolf on 13.06.23.
//

#include "Medium.hpp"
#include <string>
#include <iostream>

unsigned int Medium::currentID = 0;


Medium::Medium(std::string initTitel)
: titel(initTitel)
, status(false)
{
    ID = currentID++;
}

Medium::~Medium(void)
{
}


void Medium::ausgabe(std::ostream& out) const
{
    out << "ID: " << ID << std::endl;
    out << "Titel: " << titel << std::endl;

    if (status)
    {
        out << "Status: Das Medium ist seit dem " << datumAusgeliehen << " an " << personAusgeliehen.getName() << " ausgeliehen." << std::endl;
    }
    else
    {
        out << "Status: Medium ist zurzeit nicht verliehen." << std::endl;
    }
}

bool Medium::ausleihen(Person person, Datum ausleihdatum)
{
    if (status)
    {
        std::cout << "Das Medium \"" << titel << "\" ist bereits von " << personAusgeliehen.getName() << " ausgeliehen." << std::endl;
        return false;
    }
    else
    {
        status = true;
        personAusgeliehen = person;
        datumAusgeliehen = ausleihdatum;
        std::cout << "Das Medium \"" << titel << "\" wird an " << person.getName() << " verliehen." << std::endl;
        return true;
    }
}

void Medium::zurueckgeben()
{
    if (status)
    {
        status = false;
        std::cout << "Das Medium \"" << titel << "\" wurde zur¸ckgegeben." << std::endl;
    }
    else
    {
        std::cout << "Das Medium \"" << titel << "\" ist nicht verliehen!" << std::endl;
    }
}

unsigned int Medium::getID()
{
    return ID;
}
