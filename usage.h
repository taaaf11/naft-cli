#include <stdio.h>
#include <stdlib.h>


void
print_usage (int status)
{
    if (status != EXIT_SUCCESS)
    {
        fprintf(stderr, "USAGE: naft OPTION(S)\n"
                        "  or   naft OPTION(S) -f FILE \n\n");

        fprintf(stderr, "    --starting-line,  -s <number>\t\tSpecify range (stating). Used with -r switch.\n"
                        "    --ending-line,    -r <number>\t\tSpecify range (ending). Used with -s switch.\n"
                        "    --all-after,      -a <number>\t\tPrint all lines after given line.\n"
                        "    --just-one,       -o <number>\t\tPrint one line after the given line.\n"
                        "    --from-file,      -f\t\t\tGet input from file instead of from stdin.\n"
                        "    --no-trailn,      -n\t\t\tDon't print trailing newline at the end of output (not the newline a file may have).\n"
                        "    --line-n,         -l\t\t\tPrint line numbers along with output.\n"
                        "    --help,           -h\t\t\tPrint this help message.\n\n"
                        "Note: -s and -r switches and their respective long options are to be used together.\n");
        exit(status);
    }

    fprintf(stdout, "USAGE: naft OPTION(S)\n"
                    "  or   naft OPTION(S) -f FILE \n\n");

    fprintf(stdout, "    --starting-line,  -s <number>\t\tSpecify range (stating). Used with -r switch.\n"
                    "    --ending-line,    -r <number>\t\tSpecify range (ending). Used with -s switch.\n"
                    "    --all-after,      -a <number>\t\tPrint all lines after given line.\n"
                    "    --just-one,       -o <number>\t\tPrint one line after the given line.\n"
                    "    --from-file,      -f\t\t\tGet input from file instead of from stdin.\n"
                    "    --no-trailn,      -n\t\t\tDon't print trailing newline at the end of output (not the newline a file may have).\n"
                    "    --line-n,         -l\t\t\tPrint line numbers along with output.\n"
                    "    --help,           -h\t\t\tPrint this help message.\n\n"
                    "Note: -s and -r switches and their respective long options are to be used together.\n");
    exit(status);
}
