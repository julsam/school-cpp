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

