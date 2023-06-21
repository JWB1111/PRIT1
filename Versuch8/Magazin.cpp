
//
//  Magazin.cpp
//  Versuch8
//
//  Created by Julius Wolf on 13.06.23.


#include "Medium.hpp"
#include "Magazin.hpp"
#include <string>
#include <iostream>

using namespace std;



Magazin::Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte)
: Medium(initTitel), datumAusgabe(initDatumAusgabe)
, sparte(initSparte)
{
}

Magazin::~Magazin(void)
{
}

void Magazin::ausgabe(std::ostream& out) const {
    Medium::ausgabe(out);  // Call the base class implementation

    if (status) {
        out << "Status: Das Magazin ist seit dem " << datumAusgeliehen << " an " << personAusgeliehen.getName() << " ausgeliehen." << std::endl;
    } else {
        out << "Status: Magazin ist zurzeit nicht verliehen." << std::endl;
    }

    out << "Ausgabe: " << datumAusgabe << std::endl;
    out << "Sparte: " << sparte << std::endl;
}

bool Magazin::ausleihen(Person person, Datum ausleihdatum)
{
    

    int monthsDifference = datumAusgabe - ausleihdatum;
    if (monthsDifference >= 1)
    {
        std::cout << "Das Magazin \"" << titel << "\" ist zu aktuell" << std::endl;
        return false;
    }
    else
    {
        personAusgeliehen = person;
        datumAusgeliehen = ausleihdatum;
        std::cout << "Das Medium \"" << titel << "\" wird an " << person.getName() << " verliehen." << std::endl;
        return true;
    }
}



