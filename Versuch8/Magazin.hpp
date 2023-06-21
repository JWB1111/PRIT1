
//
//  Magazin.hpp
//  Versuch8
//
//  Created by Julius Wolf on 16.06.23.
//

#ifndef Magazin_hpp
#define Magazin_hpp
#include <stdio.h>
#include <iostream>
#include "Medium.hpp"



class Magazin: public Medium {
public:
    Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte);
    virtual ~Magazin();
    virtual void ausgabe(std::ostream& out) const override;
    bool ausleihen(Person person,Datum ausleihdatum);
private:
    Datum datumAusgabe;
    std::string sparte;
    
};


#endif /* Magazin_hpp */
