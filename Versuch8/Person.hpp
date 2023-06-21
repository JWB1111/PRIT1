//
//  Person.hpp
//  Versuch8
//
//  Created by Julius Wolf on 16.06.23.
//

#ifndef Person_hpp
#define Person_hpp

#include "Datum.hpp"
#include <string>

/*!
 * @brief Klasse Person
 *
 * Die Klasse Person speichert alle relevanten Informationenen einer Person ab,
 * die f¸r die B¸cherei relevant sind, dies beinhaltet:
 *  - Name
 *  - Geburtsdatum
 *
 */
class Person
{
public:
    /*!
     * @brief Konstruktor
     *
     * Konstruktor der Klasse Person
     *
     * \param std::string name: Name der Person, Default-Value ist ein leerer String
     * \param Datum initGeburtsdatum: Geburtsdatum der Person, Default-Value ist das aktuelle Datum
     */
    Person(std::string initName = "", Datum initGeburtsdatum = Datum());

    /*!
     * @brief Destruktor
     */
    ~Person();

    /*!
     * @brief Zugriffsfunktion auf den Namen der Person
     *
     * \return std::string: gibt den Namen der Person zur¸ck
     */
    std::string getName() const;

    /*!
     * @brief Zugriffsfunktion auf das Geburtsdatum der Person
     *
     * \return Datum: gibt das Geburtsdautm der Person zur¸ck
     */
    Datum getGeburtsdatum() const;

private:
    std::string name;
    Datum geburtsdatum;
};


#endif /* Person_h */
