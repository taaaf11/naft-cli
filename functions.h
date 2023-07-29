#include <stdio.h>
#include <stdbool.h>

void
print_n_after (FILE *fp, int starting_line_number, int ending_line_number)
{
    int line_idx = 0;
    char character;

    while ((character = fgetc(fp)) != EOF)
    {
        if (character == '\n')
            line_idx++;
        
        if (line_idx >= starting_line_number - 1)
        {
            if (line_idx == ending_line_number)
                break;
            
            putchar (character);
        }
    }
}
