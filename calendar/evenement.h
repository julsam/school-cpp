#ifndef _EVENEMENT_H
#define _EVENEMENT_H

#include <iostream>
#include <string>
//#include <map>

//typedef std::map<int, std::string> MapSemaine;

struct StructEvenement
{
    int jour;
    float heureDebut;
    float heureFin;
    std::string descAbrg;
    std::string descLongue;
};
typedef StructEvenement Evenement;


void validerEvenement(const Evenement& e) throw (std::string);
bool heureValide(const float h);
void saisirEvenement(Evenement& e) throw (std::string);
void initialiserEvenement(int j, float hD, float hF, std::string a, std::string d, Evenement& e) throw (std::string);
void afficherEvenement(const Evenement& e);
bool estAnterieur(const Evenement& e1, const Evenement& e2);
void afficherJourSemaine(int j) throw (std::string);
void afficherDebutJourSemaine(int j) throw (std::string);
std::string getSemaine(int j);


#endif // _EVENEMENT_H

