#include <stdio.h>

#define make_true(x)        x = 1
#define is_newln(c)         (c == '\n')
#define trail_ln(y)         (y == 1) ? putchar('\n') : 0

typedef unsigned int flag;


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


void
one_line (FILE *fp, int starting_line_number)
{
    char character;
    int line_idx = 0;

    while ((character = fgetc(fp)) != EOF)
    {
        if (is_newln(character))
            line_idx++;
        
        if (line_idx == starting_line_number - 1)
        {
            // printf("T")

            putchar(character);
        }
    }
}
