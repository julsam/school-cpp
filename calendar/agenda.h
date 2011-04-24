#ifndef _AGENDA_H
#define _AGENDA_H

#include "evenement.h"
#include <deque>
#include <vector>

const int NB_EVENEMENTS = 12 * 2 * 7;
const int NB_EVENT_PER_DAY = 12 * 2;

typedef std::deque<Evenement*> Semaine;

typedef struct
{
    Semaine semaine;
    int nbEvenements;
} Agenda;

void initialiserAgenda(Agenda& a);
void placerEvenement(Agenda& a, Evenement* e) throw (std::string);
void afficherAgendaDetail(const Agenda& a);
void afficherAgendaGlobal(const Agenda& a);

int insertEvent(Agenda& a, Evenement* e, int pos);

#endif // _AGENDA_H

