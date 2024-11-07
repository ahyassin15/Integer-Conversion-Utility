#ifndef MAIN_H
#define MAIN_H

#define MAX_BASE 36
#define MIN_BASE 2


void usage();
void help();
int parse_args(int argc, char *argv[], int *base, long *start, long *finish);


#endif