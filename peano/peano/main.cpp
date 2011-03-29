#include <stdlib.h>
#include <iostream>
#include <string>
#include "Peano.h"

using namespace std;

extern char *__progname;

void usage(void);

int
main(int argc, char **argv)
{
    int o;
    __progname = argv[0];
    string file;
    int in_p = 2, in_q = 3; // default values

    while((o = getopt(argc, argv, "q:p:h")) != -1)
    {
        switch(o)
        {
            case 'p':
                in_p = atoi(optarg);
                break;
            case 'q':
                in_q = atoi(optarg);
                break;
            case '?':
            case 'h':
                usage();
                break;
        }
    }
/*
    Peano p, q;
    p = zero();
    q = zero();

    // P1
    cout << "P1 " << ( add( zero(), p ) == p ? "true":"false") << endl;
    cout << "add(zero, p) = p" << endl;
    cout << "" << endl;

    // P2
    cout << "P2 " << ( add( succ(p), q ) == succ( add(p, q) ) ? "true":"false" ) << endl;
    cout << "add(succ(p), q) = succ(add(p, q))" << endl;
    cout << "" << endl;

    // P3
    cout << "P3 " << ( mult( zero(), p ) == zero() ? "true":"false" ) << endl;
    cout << "mult(zero, p) = zero" << endl;
    cout << "" << endl;

    // P4
    cout << "P4 " << ( mult( succ(p), q ) == add( mult(p, q), q ) ? "true":"false" ) << endl;
    cout << "mult(succ(p), q) = add(mult(p, q), q)" << endl;
    cout << "" << endl;

    // P5
    cout << "P5 " << ( inf( zero(), zero()) ? "true":"false" ) << endl;
    cout << "inf(zero, zero) = false" << endl;
    cout << "" << endl;

    // P6
    cout << "P6 " << ( inf( zero(), succ(p) ) == true ? "true":"false" ) << endl;
    cout << "inf(succ(p), zero) = true" << endl;
    cout << "" << endl;

    // P7
    cout << "P7 " << ( inf( succ(p), zero() ) ? "true":"false" ) << endl;
    cout << "inf(zero, succ(p)) = false" << endl;
    cout << "" << endl;

    // P8
    cout << "P8 " << ( inf( succ(p), succ(q) ) == inf( p, q ) ? "true":"false" ) << endl;
    cout << "inf(succ(p), succ(q)) = inf(p, q)" << endl;
    cout << "" << endl;

    // P9
    cout << "P9 " << ( zero() == zero() ? "true":"false" ) << endl;
    cout << "egal(zero, zero) = true" << endl;
    cout << "" << endl;

    // P10
    cout << "P10 " << ( zero() == succ(p) ? "true":"false" ) << endl;
    cout << "egal(zero, succ(p)) = false" << endl;
    cout << "" << endl;

    // P11
    cout << "P11 " << ( succ(p) == zero() ? "true":"false" ) << endl;
    cout << "egal(succ(p), zero) = false" << endl;
    cout << "" << endl;

    // P12
    cout << "P12 " << ( (succ(p) == succ(q)) == (p == q) ? "true":"false" ) << endl;
    cout << "egal(succ(p), succ(q)) = egal(p, q)" << endl;
    cout << "" << endl;
    
    
   */

    // p
    Peano p;
    p = zero();

    for(int i = 0; i < in_p; i++)
        p = succ(p);

    cout << "p = ";
    displayPeano(p);

    // q
    Peano q;
    q = zero();

    for(int i = 0; i < in_q; i++)
        q = succ(q);

    cout << "q = ";
    displayPeano(q);

    // p + q
    cout << "p + q = ";
    displayPeano(add(p, q));

    // p * q
    cout << "p * q = ";
    displayPeano(mult(p, q));

    // is p < q ?
    cout << "p < q ? ";
    if(inf(p, q))
        cout << "true" << endl;
    else
        cout << "false" << endl; 

    // is p == q ?
    cout << "p == q ? ";
    if(p == q)
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return EXIT_SUCCESS;
}

void
usage(void)
{
    cout << "usage: " << __progname << " [-pq]\n"
            "\t-h\t\tShow this page\n"
            "\t-p\t\tFirst Peano value\n"
            "\t-q\t\tSecond Peano value" << endl;
    exit(1);
}

