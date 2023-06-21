//
//  Buch.hpp
//  Versuch8
//
//  Created by Julius Wolf on 16.06.23.
//

#ifndef BUCH_HPP
#define BUCH_HPP
#include <string>
#include "Medium.hpp"

class Buch : public Medium {
public:
    Buch(std::string initTitel, std::string initAutor);
    virtual ~Buch ();
    virtual void ausgabe(std::ostream& out) const override;
    bool ausleihen(Person person, Datum ausleihdatum);
  
    
private:
    std::string autor;

};

#endif /* BUCH_HPP */
