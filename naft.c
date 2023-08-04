#include "definitions.h"
#include "usage.h"

#include <getopt.h>


static flag 
		s_switch = 0,
		r_switch = 0,
		a_switch = 0,
		o_switch = 0,
		i_switch = 0,
		n_switch = 0,
		ask_help = 0;
	

struct option longoptions[] = {
	{"starting-line", required_argument, 0, 's'},
	{"required-lines", required_argument, 0, 'r'},
	{"all-after", required_argument, 0, 'a'},
	{"just-one", required_argument, 0, 'o'},
	{"from-stdin", no_argument, 0, 'i'},
	{"no-newline", no_argument, 0, 'n'},
	{"help", no_argument, 0, 'h'},
	{0, 0, 0, 0}
};


int
main (int argc, char **argv)
{
	char optc;

	int optidx,
	    range_starting_line,
		range_required_lines,
		line_start_a_o;

	while ((optc = getopt_long(argc, argv, "s:r:a:o:inh", longoptions, &optidx)) != -1)
	{
		switch (optc)
		{
			case 's':
			    make_true(s_switch);
				range_starting_line = atoi(optarg);
			    break;
			
			case 'r':
			    make_true(r_switch);
				range_required_lines = atoi(optarg);
				break;
			
			case 'a':
			    make_true(a_switch);
				line_start_a_o = atoi(optarg);
			    break;
			
			case 'o':
			    make_true(o_switch);
				line_start_a_o = atoi(optarg);
				break;
			
			case 'i':
			    make_true(i_switch);
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
	    print_usage(0);
}
