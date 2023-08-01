#include <stdio.h>

#define make_true(x)        x = 1

typedef int flag;

void
print_range (FILE *fp, int starting_line_number, int required_number_of_lines)
{
    int line_idx = 0,
        ending_line_number = starting_line_number + required_number_of_lines - 2;

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
