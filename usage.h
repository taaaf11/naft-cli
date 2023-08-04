#include <stdio.h>
#include <stdlib.h>


void
print_usage (int status)
{
    if (! (status == EXIT_SUCCESS) )
    {
        fprintf(stderr, "--starting-line, -s <number>\t\tWhen specifying range (stating). Used with -r switch.\n"
                        "--required-lines, -r <number>\t\tWhen specifying range (ending). Used with -s switch.\n"
                        "--from-stdin, -i\t\tGet input from stdin instead of from FILE.\n"
                        "--all-after, -a");
    }
}
