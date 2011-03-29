#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

extern char *__progname;

void
usage()
{
    cout << "usage: " << __progname << " [-hd] [-f file]\n"
            "\t-h\t\tShow this page\n"
            "\t-d\t\tOption not defined yet...\n"
            "\t-f file\t\tLoad file" << endl;
    exit(1);
}

int
main(int argc, char **argv)
{
    int o;
    __progname = argv[0];
    string file;

    while((o = getopt(argc, argv, "df:h")) != -1)
    {
        switch(o)
        {
            case 'd':
                cout << "d = " << optarg << endl;
                break;
            case 'f':
                file = optarg;
                cout << "f = " << file << endl;
                break;
            case '?':
            case 'h':
                usage();
                break;
        }
    }

    return EXIT_SUCCESS;
}
