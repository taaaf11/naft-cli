#include <stdio.h>

#define make_true(x)                x = 1
#define is_newln(character)         (character == '\n')
#define trail_ln(yes_or_no)         (yes_or_no == 1) ? putchar('\n') : 0

typedef unsigned int flag;


void
print_range (FILE *fp, int starting_line_number, int required_ending_line_number)
{
    int line_idx = 0,
        is_itr = 0, // used for preventing printing of unexpected newline at start of program,
                    // caused by the <character> variable at the new_line, but there are characters before
                    // the new_line character at that line.
                    // see below
        ending_line_number = starting_line_number + required_ending_line_number - 2;

    char character,
         prev_char;

    while ((character = fgetc(fp)) != EOF)
    {
        if (is_newln(character))
            line_idx++;
        
        if (line_idx >= starting_line_number - 1)
        {
            if (!is_newln(prev_char) && is_newln(character))
            {
                if (is_itr == 0)
                {
                    is_itr++;
                    continue;
                }
            }
            
            if (line_idx == ending_line_number)
                break;
            
            putchar (character);
        }

        prev_char = character;
    }
}


void
print_one_line (FILE *fp, int starting_line_number)
{
    char character,
         prev_char;
    int line_idx = 0;

    while ((character = fgetc(fp)) != EOF)
    {
        if (is_newln(character))
            line_idx++;
        
        if (line_idx == starting_line_number)
        {
            if (!is_newln(prev_char) && is_newln(character))
                continue;
            
            putchar(character);
        }

        prev_char = character;
    }
}


void
print_all_after (FILE *fp, int given_line_number)
{
    char character,
         prev_char;

    int line_idx = 0,
        is_itr = 0; // explanation above

    while ((character = fgetc(fp)) != EOF)
    {   
        if (is_newln(character))
            line_idx++;
        
        if (line_idx > given_line_number - 1)
        {
            if (!is_newln(prev_char) && is_newln(character))
            {
                if (is_itr == 0)
                {
                    is_itr++;
                    continue;
                }
            }

            putchar(character);
        }

        prev_char = character;
    }
}

