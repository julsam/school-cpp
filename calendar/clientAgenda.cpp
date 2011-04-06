#include "evenement.h"

using namespace std;

int
main(void)
{
    try
    {
        Evenement e;
        initialiserEvenement(7, 9.00, 12.50, "ALG", "Controle Algo 2", e);

        //saisirEvenement(e);
        //afficherEvenement(e);
        afficherJourSemaine(e.jour);
        afficherDebutJourSemaine(e.jour);
    }
    catch (string& e)
    {
        cout << e << endl;
    }

    return 0;
}
