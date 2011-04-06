#include "evenement.h"
#include <sstream>
#include <cmath>
#include <iomanip>

using namespace std;

//MapSemaine semaine;

void
validerEvenement(const Evenement& e) throw (std::string)
{
    if (e.jour < 1 || e.jour > 7)
        throw string("jourInvalide");
    if (e.heureDebut < 8.0 || e.heureDebut > 19.5)
        throw string("heureDebutIncorrecte");
    if (e.heureFin < 8.5 || e.heureFin > 20.0)
        throw string("heureFinIncorrecte");
    if (heureValide(e.heureDebut))
        throw string("heureDebutIncorrecte");
    if (heureValide(e.heureFin))
        throw string("heureFinIncorrecte");
    if (e.heureFin - e.heureDebut < 0.5)
        throw string("DureeIncorrecte");
}

bool heureValide(const float h)
{
    float h2 = h;
    h2 *= 2;
    if (ceil(h2) > h2)
        return true;
    else
        return false;
}

void
saisirEvenement(Evenement& e) throw (std::string)
{
    int j;
    float hD, hF;
    string a, d;

    cout << "Jour : ";
    cin >> j;
    cout << "Heure de debut : ";
    cin >> hD;
    cout << "Heure de fin : ";
    cin >> hF;
    cout << "Description courte : ";
    cin >> a;
    a.resize(3);

    cin.ignore();
    cout << "Description longue : ";
    getline(cin, d);

    initialiserEvenement(j, hD, hF, a, d, e);
}

void
initialiserEvenement(int j, float hD, float hF, std::string a, std::string d, Evenement& e) throw (std::string)
{
    e.jour       = j;
    e.heureDebut = hD;
    e.heureFin   = hF;
    e.descAbrg   = a;
    e.descLongue = d;

    validerEvenement(e);
}

void
afficherEvenement(const Evenement& e)
{
    string s;

    cout.precision(1);
    cout.setf(ios::fixed, ios::floatfield);

    cout << setw(4) << right << e.heureDebut;
    cout << " - ";
    cout << setw(4) << right << e.heureFin;

    cout << " : " << e.descLongue << endl;
}

bool
estAnterieur(const Evenement& e1, const Evenement& e2)
{
    if (e1.jour < e2.jour)
        return true;
    else if (e1.jour == e2.jour && e1.heureDebut < e2.heureDebut)
        return true;
    else
        return false;
}

void
afficherJourSemaine(int j) throw (std::string)
{
    cout << getSemaine(j) << endl;
}

void
afficherDebutJourSemaine(int j) throw (std::string)
{
    string s = getSemaine(j);
    s.resize(2);
    cout << s << endl;
}

string
getSemaine(int j)
{
    string s;
    switch(j)
    {
        case 1:
            s = "Lundi";
            break;
        case 2:
            s = "Mardi";
            break;

        case 3:
            s = "Mercredi";
            break;

        case 4:
            s = "Jeudi";
            break;

        case 5:
            s = "Vendredi";
            break;

        case 6:
            s = "Samedi";
            break;

        case 7:
            s = "Dimanche";
            break;
    }
    return s;
}

