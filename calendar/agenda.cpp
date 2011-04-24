#include "agenda.h"
#include <string>

using namespace std;

void
initialiserAgenda(Agenda& a)
{
    a.nbEvenements = 0;
}

void
placerEvenement(Agenda& a, Evenement* e) throw (std::string)
{
    if (a.nbEvenements >= NB_EVENEMENTS)
        throw("Debordement du nombre d'évènements.");

    // if this is the first elem we insert in the list
    if (a.nbEvenements == 0)
    {
        a.semaine.push_back(e);
    }
    else // not empty list
    {
        int pos = a.nbEvenements;

        if (estAnterieur(*a.semaine[pos - 1], *e))
        {
            if (insertEvent(a, e, pos) == 1)
                return;
        }
        else
        {
            pos = 0;

            while (pos < a.nbEvenements)
            {
                if (estAnterieur(*e, *a.semaine[pos]))
                {
                    if (insertEvent(a, e, pos) == 1)
                        return;
                    pos = a.nbEvenements; // end loop
                }
                else if (a.semaine[pos] == e) // if elem is already present, we stop
                {
                    cout << e->descAbrg << " : Vous essayer de placer 2 fois le même évènement." << endl;
                    return;
                }
                pos++;
            }
        }
    }

    // elem finally added to our list
    a.nbEvenements++;
}

int
insertEvent(Agenda& a, Evenement* e, int pos)
{
    Semaine::iterator it = a.semaine.begin() + pos;

    if (pos > 0 && chevauchementHoraireInf(e, a.semaine.at(pos - 1)))
    {
        cout << e->descAbrg << " : Chevauchement inférieur." << endl;
        return 1;
    }
    if (pos < a.nbEvenements && chevauchementHoraireSup(e, a.semaine.at(pos)))
    {
        cout << e->descAbrg << " : Chevauchement supérieur." << endl;
        return 1;
    }

    a.semaine.insert(it, e);
    return 0;
}

void
afficherAgendaDetail(const Agenda& a)
{
    int prevDay = 0;

    cout << "\n\n*** AFFICHAGE AGENDA DETAIL ***\n\n";

    for (unsigned int i = 0; i < a.semaine.size(); i++)
    {
        if (a.semaine[i]->jour != prevDay)
        {
            afficherJourSemaine(a.semaine[i]->jour);
            prevDay = a.semaine[i]->jour;
        }

        afficherEvenement(*a.semaine[i]);
    }
}

void
afficherAgendaGlobal(const Agenda& a)
{
    vector<string> lines;

    lines.push_back("08 -  09 -  10 -  11 -  12 -  13 -  14 -  15 -  16 -  17 -  18 -  19");

    for (int i = 0; i < 7; i++)
        lines.push_back(string(68, ' ')); // 68 = num of char per line

    for (unsigned int i = 0; i < a.semaine.size(); i++)
    {
        int day         = a.semaine[i]->jour;
        float duration  = a.semaine[i]->heureFin - a.semaine[i]->heureDebut;
        int pos         = (a.semaine[i]->heureDebut - 8) / 0.5 * 3;
        int ndots       = ((duration / 0.5) - 1) * 3;

        lines[day].replace(pos, 3, a.semaine[i]->descAbrg);
        lines[day].replace(pos + 3, ndots, ndots, '.');
    }

    cout << "\n\n*** AFFICHAGE AGENDA GLOBAL ***\n\n";

    cout << "    " << lines[0] << "\n\n";
    for (unsigned int i = 1; i < lines.size(); i++)
    {
        afficherDebutJourSemaine(i);
        cout << "  " << lines[i] << endl;
    }
}

