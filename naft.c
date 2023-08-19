#include "definitions.h"
#include "usage.h"

#include <getopt.h>


static flag
		aflag    = 0, // a switch is present.
		s_switch = 0, // 1 if -s is present; specify starting line number when giving range.
		r_switch = 0, // 1 if -r is present; specify ending line number when giving range.
		a_switch = 0, // 1 if -a is present; print all lines after the line at given line number.
		o_switch = 0, // 1 if -o is present; print one line at given line number.
		f_switch = 0, // 1 if -f is present; get input from specified file instead of from stdin.
		n_switch = 0, // 1 if -n is present; don't print trailing newline at end of output.
		ask_help = 0; // 1 if -h is present; help message.


struct option longoptions[] = {
	{"starting-line", required_argument, 0, 's'},
	{"ending-line",   required_argument, 0, 'r'},
	{"all-after",     required_argument, 0, 'a'},
	{"just-one",      required_argument, 0, 'o'},
	{"from-file",     required_argument, 0, 'f'},
	{"no-trailn",     no_argument,       0, 'n'},
	{"help",          no_argument,       0, 'h'},
	{NULL, 0, NULL, '\0'}
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
				make_true(aflag);
				range_starting_line = atoi(optarg);
				break;

			case 'r':
				make_true(r_switch);
				make_true(aflag);
				range_ending_line = atoi(optarg);
				break;

			case 'a':
				make_true(a_switch);
				make_true(aflag);
				line_start_a_o = atoi(optarg);
				break;

			case 'o':
				make_true(o_switch);
				make_true(aflag);
				line_start_a_o = atoi(optarg);
				break;

			case 'f':
				make_true(f_switch);
				make_true(aflag);
				file_name = optarg;
				break;

			case 'n':
				make_true(n_switch);
				make_true(aflag);
				break;

			case 'h':
				make_true(ask_help);
				make_true(aflag);
				break;
		}
	}

	if (!aflag)
		return 0;

	if (ask_help)
		print_usage(0); // function auto-exits.

	if ((s_switch && !r_switch) || (!s_switch && r_switch))
	{
		fprintf(stderr, "-s and -r switches should be used together.\n");
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
		print_all_after(file, line_start_a_o);

	if (o_switch)
		print_one_line(file, line_start_a_o);

	if (s_switch && r_switch)
		print_range(file, range_starting_line, range_ending_line);

	if (!n_switch)
		trail_ln(1);

	fclose(file);
	return 0;
}

