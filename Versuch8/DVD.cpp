//
//  DVD.cpp
//  Versuch8
//
//  Created by Julius Wolf on 13.06.23.
//

#include "DVD.hpp"
#include <iostream>
/*
DVD::DVD() {
    // TODO Auto-generated constructor stub

}
*/
DVD::DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre) :
        Medium(initTitel), altersfreigabe(initAltersfreigabe), genre(initGenre)
{

}

void DVD::ausgabe(std::ostream& out) const
{
    Medium::ausgabe(out);
    std::cout << "FSK: " << altersfreigabe << std::endl;
    std::cout << "Genre: " << genre << std::endl;
}

bool DVD::ausleihen(Person person, Datum ausleihdatum)
{
    int personAlter = ausleihdatum - person.getGeburtsdatum();
    //std::cout << "HAAAAAALOOOOOOO: " << personAlter << std::endl;
    if (personAlter >= (altersfreigabe*12))
    {
        Medium::ausleihen(person, ausleihdatum);
        return true;
    }

    else
    {
        std::cout << "DVD darf nicht ausgeliehen werden: Benutzer ist zu jung!" << std::endl;
        return false;
    }
}

DVD::~DVD() {
    // TODO Auto-generated destructor stub
}
