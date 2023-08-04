#include "definitions.h"

#include <stdlib.h>
#include <getopt.h>


static flag 
		s_switch = 0,
		r_switch = 0,
		i_switch = 0,
		a_switch = 0,
		o_switch = 0,
		ask_help = 0;
	

struct option longoptions[] = {
	{"starting-line", required_argument, 0, 's'},
	{"required-lines", required_argument, 0, 'r'},
	{"from-stdin", no_argument, 0, 'i'},
	{"all-after", no_argument, 0, 'a'},
	{"just-one", no_argument, 0, 'o'},
	{"help", no_argument, 0, 'h'},
	{0, 0, 0, 0}
};


int
main (int argc, char **argv)
{
	char optc;

	int optidx,
	    range_starting_line,
		range_required_lines;

	while ((optc = getopt_long(argc, argv, "s:r:iaoh", longoptions, &optidx)) != -1)
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
			
			case 'i':
			    make_true(i_switch);
				break;
			
			case 'a':
			    make_true(a_switch);
			    break;
			
			case 'o':
			    make_true(o_switch);
				break;
			
			case 'h':
			    make_true(ask_help);
				break;
		}
	}
}