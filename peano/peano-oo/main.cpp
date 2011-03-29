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

    Peano p, q;
    try
    {
        for(int i = 0; i < in_p; i++)
            p.succ();
        for(int i = 0; i < in_q; i++)
            q.succ();

        cout << "p = ";
        Peano::display(p);

        cout << "q = ";
        Peano::display(q);

        cout << "p == q ? ";
        cout << (p == q ? "true":"false") << endl;

        cout << "p < q ? ";
        cout << (p < q ? "true":"false") << endl;

        cout << "p + q = ";
        Peano::display(p + q);

        cout << "p * q = ";
        Peano::display(p * q);
    }
    catch (const string &e) {
        cout << "\n" << e << endl;
    }


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

