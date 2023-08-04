#include <stdio.h>
#include <stdlib.h>


void
print_usage (int status)
{
    if (! (status == EXIT_SUCCESS) )
    {
        fprintf(stderr, "USAGE: naft OPTION(S) FILE \n"
                        " or    naft OPTION(S) -i\n\n");

        fprintf(stderr, "--starting-line,  -s <number>\t\tWhen specifying range (stating). Used with -r switch.\n"
                        "--required-lines, -r <number>\t\tWhen specifying range (ending). Used with -s switch.\n"
                        "--all-after,      -a <number>\t\tPrint all lines after given line.\n"
                        "--just-one,       -o <number>\t\tPrint one line after the given line.\n"
                        "--from-stdin,     -i\t\t\tGet input from stdin instead of from FILE.\n"
                        "--help, -h\t\t\t\tPrint this help message.");
        exit(status);
    }

    fprintf(stdout, "USAGE: naft OPTION(S) FILE \n"
                    "  or   naft OPTION(S) -i\n\n");

    fprintf(stdout, "--starting-line,  -s <number>\t\tWhen specifying range (stating). Used with -r switch.\n"
                    "--required-lines, -r <number>\t\tWhen specifying range (ending). Used with -s switch.\n"
                    "--all-after,      -a <number>\t\tPrint all lines after given line.\n"
                    "--just-one,       -o <number>\t\tPrint one line after the given line.\n"
                    "--from-stdin,     -i\t\t\tGet input from stdin instead of from FILE.\n"
                    "--help, -h\t\t\t\tPrint this help message.");
    exit(status);
}
