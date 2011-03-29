#include <stdlib.h>
#include <iostream>
#include <string>
#include "Duration.h"

using namespace std;

extern char *__progname;

void usage(void);

int
main(int argc, char **argv)
{
    int o;
    __progname = argv[0];
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

    try
    {
        Duration d(12, 21, 17);
        Duration dd(14, 55, 23);
        Duration dd2(14, 55, 23);

        dd.display("dd");
        cout << (d < dd ? "true":"false") << endl;
        cout << (d == dd ? "true":"false") << endl;
        cout << (dd == dd2 ? "true":"false") << endl;
        d.display("d");
        d = dd;
        d.display("d");
        d.addOneSecond();
        d.display("d");

    }
    catch (const string &e) {
        cout << "\n" << e << endl;
    }

    return 0;
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

