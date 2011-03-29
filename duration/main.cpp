#include <iostream>
#include <string>
#include "Duration.h"

using namespace std;

int
main(int argc, char **argv)
{
    try
    {
        /*
        Duration d1(12, 21, 17);
        Duration d2(14, 55, 23);

        d1.display("duration1");
        d2.display("duration2");
        cout << (d1 < d2 ? "true":"false") << endl;
        cout << (d1 == d2 ? "true":"false") << endl;
        d1 = d2;
        d1.display("duration1");
        d1.addOneSecond();
        d1.display("duration1");
        */

        cout << "(P1) heures(uneDurée(h, m, s)) = h " << endl;

        cout << (Duration(14, 24, 55).getHours() == 14 ? "true":"false") << endl;


        cout << "(P2) minutes(uneDurée(h, m, s)) = m" << endl;

        cout << (Duration(14, 24, 55).getMinutes() == 24 ? "true":"false") << endl;


        cout << "(P3) secondes(uneDurée(h, m, s)) = s" << endl;

        cout << (Duration(14, 24, 55).getSeconds() == 55 ? "true":"false") << endl;


        cout << "(P4) inf(uneDurée(h1, m1, s1), uneDurée(h2, m2, s2)) =" << endl;
        cout << "\t(h1 < h2) ou (h1=h2 et m1 < m2) ou (h1=h2 et m1=m2 et s1 < s2)" << endl;

        int h1=14, m1=24, s1=55, h2=5, m2=39, s2=27;
        //cout << ((Duration(h1, m1, s1) < Duration(h2, m2, s2) == (h1 < h2) || (h1==h2 && m1 < m2) || (h1==h2 && m1==m2 && s1 < s2)) ? "true":"false") << endl;

        //TODO: finish

        cout << "(P5) égal(uneDurée(h1, m1, s1), uneDurée(h2, m2, s2)) =" << endl;
        cout << "\th1 = h2 et m1 = m2 et s1 = s2" << endl;

        cout << "(P6) plusUneSeconde(uneDurée(h, m, s)) = " << endl;
        cout << "\tsi s < 59 alors uneDurée(h, m, s + 1)" << endl;
        cout << "\tsinon si m < 59 alors uneDurée(h, m + 1, 0)" << endl;
        cout << "\t\tsinon uneDurée(h + 1, 0, 0)" << endl;
    }
    catch (const string &e) {
        cout << "\n" << e << endl;
    }

    return 0;
}

