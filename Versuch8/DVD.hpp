
//  DVD.hpp
//  Versuch8
//
//  Created by Julius Wolf on 16.06.23.
//

#ifndef DVD_hpp
#define DVD_hpp

#include <stdio.h>
#include <string>
#include "Medium.hpp"
#include <iostream>


class DVD: public Medium {
public:
    DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre);
    virtual ~DVD();

    virtual void ausgabe(std::ostream& out) const override;
    bool ausleihen(Person person, Datum ausleihdatum);
    
private:
    int altersfreigabe;
    std::string genre;
};

#endif /* DVD_h */
 
