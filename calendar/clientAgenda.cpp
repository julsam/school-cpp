#include "evenement.h"
#include "agenda.h"

using namespace std;

int
main(void)
{
    try
    {
        Evenement e, f, g, h, i, j, k, l;
        Agenda a;

        initialiserAgenda(a);

        initialiserEvenement(1, 9.00, 12.50, "ALG", "Controle Algo 2", e);
        initialiserEvenement(1, 18.00, 19.00, "ECO", "Economie", g);
        initialiserEvenement(2, 15.00, 15.50, "WTF", "What The Fuck", f);
        initialiserEvenement(2, 15.50, 16.50, "FTP", "File Transfert Protocol", h);
        initialiserEvenement(2, 14.50, 17.50, "FTW", "For The Win", i);
        initialiserEvenement(3, 8.00, 17.50, "BLI", "bliblibli", j);
        initialiserEvenement(5, 12.00, 15.50, "WOW", "World of Warcraft", k);
        initialiserEvenement(5, 15.50, 17.50, "LOL", "blagues blagues", l);

        placerEvenement(a, &e);
        placerEvenement(a, &e);
        placerEvenement(a, &g);
        placerEvenement(a, &f);
        placerEvenement(a, &h);
        placerEvenement(a, &i);
        placerEvenement(a, &j);
        placerEvenement(a, &k);
        placerEvenement(a, &l);

        //saisirEvenement(e);

        afficherAgendaDetail(a);
        afficherAgendaGlobal(a);
    }
    catch (string& e)
    {
        cout << e << endl;
    }

    return 0;
}
