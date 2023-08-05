#include "definitions.h"
#include "usage.h"

#include <getopt.h>


static flag 
		s_switch = 0,
		r_switch = 0,
		a_switch = 0,
		o_switch = 0,
		f_switch = 0,
		n_switch = 0,
		ask_help = 0;
	

struct option longoptions[] = {
	{"starting-line", required_argument, 0, 's'},
	{"required-lines", required_argument, 0, 'r'},
	{"all-after", required_argument, 0, 'a'},
	{"just-one", required_argument, 0, 'o'},
	{"from-file", no_argument, 0, 'f'},
	{"no-newline", no_argument, 0, 'n'},
	{"help", no_argument, 0, 'h'},
	{0, 0, 0, 0}
};


int
main (int argc, char **argv)
{
	char optc,
	     *file_name;

	int optidx,
	    range_starting_line,
		range_ending_line,
		line_start_a_o;

	while ((optc = getopt_long(argc, argv, "s:r:a:o:f:nh", longoptions, &optidx)) != -1)
	{
		switch (optc)
		{
			case 's':
			    make_true(s_switch);
				range_starting_line = atoi(optarg);
			    break;
			
			case 'r':
			    make_true(r_switch);
				range_ending_line = atoi(optarg);
				break;
			
			case 'a':
			    make_true(a_switch);
				line_start_a_o = atoi(optarg);
			    break;
			
			case 'o':
			    make_true(o_switch);
				line_start_a_o = atoi(optarg);
				break;
			
			case 'f':
			    make_true(f_switch);
				file_name = optarg;
				break;
			
			case 'n':
			    make_true(n_switch);
				break;
			
			case 'h':
			    make_true(ask_help);
				break;
		}
	}

	if (ask_help)
	    print_usage(0); // function auto-exits.
	
	if ((s_switch && !r_switch) || (!s_switch && r_switch))
	{
	    fprintf(stderr, "-s and -r switches with their respective long options are to be used together.\n");
		exit(EXIT_FAILURE);
	}
	
	if (!f_switch)
	{
		if (a_switch)
		    print_all_after(stdin, line_start_a_o);
		
		if (o_switch)
		    print_one_line(stdin, line_start_a_o);
		
		if (s_switch && r_switch)
		    print_range(stdin, range_starting_line, range_ending_line);
		
		if (!n_switch)
		    trail_ln(1);
		
		return 0;
	}

	FILE *file = fopen(file_name, "r");

	if (a_switch)
		    print_all_after(stdin, line_start_a_o);
		
	if (o_switch)
	    print_one_line(stdin, line_start_a_o);
		
	if (s_switch && r_switch)
	    print_range(stdin, range_starting_line, range_ending_line);
		
	if (!n_switch)
	    trail_ln(1);

	fclose(file);
	return 0;
}
