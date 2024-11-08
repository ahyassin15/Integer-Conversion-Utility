/*
// Ahmed Yassin, 400536694
// Input controller handles user's arguments they provide and calls usage and help functions when they use the utility incorrectly
*/

//Usage function
void usage() {
    printf("Usage: convert [-b BASE] [-r START FINISH]\n");
    printf("1 < BASE < 37\n");
    printf("START and FINISH are long integers\n");
}

//Help function
void help() {
    
    usage()
    
    printf("Options:\n");
    printf("  -b BASE               Specifies the base for conversion.\n");
    printf("                        BASE must be an integer between 2 and 36.\n");
    printf("  -r START FINISH       Specifies the range of long integers to convert.\n");
    printf("                        START and FINISH are long integers defining the range (inclusive).\n\n");

    printf("Examples:\n");
    printf("  convert -b 16 -r 10 20\n");
    printf("    Converts numbers from 10 to 20 into base 16 and displays the results.\n\n");
    printf("  convert -b 8 -r 5 10\n");
    printf("    Converts numbers from 5 to 10 into base 8 and displays the results.\n\n");

    printf("Notes:\n");
    printf("  - The base must be between 2 and 36 to support numeric and alphabetic characters.\n");
    printf("  - The range START to FINISH must be valid long integers.\n");
    printf("  - If incorrect arguments are provided, the program will show usage instructions.\n\n");
    printf("  - If -b is not used, the conversion base will default to 16 (hexadecimal).\n\n");
    printf("  - If -r is used, convert will output conversions for the given range of integers and then exit.\n\n");
    printf("  - If -r is not used, convert will accept integers from standard input and convert them one at a time until it encounters an EOF character (ctrl-d). Then it will exit.\n\n");
    printf("  - For bases higher than 10, capital letters A through Z should represent digit values 11 through 36.\n\n");

    printf("Use this utility to easily convert a range of long integers to various bases.\n");

}

/*
// handle_args function to handle command-line arguments and set base and range values
// argc: argument count is the number of command-line arguments
// argv[]: argument vector is the array of char* pointers
// base: base value
// start: start value
// finish: finish value
*/

int handle_args(int argc, char *argv[], int *base, long *start, long *finish) {
    
    //Default values for base, start, finish
    *base = 10;
    *start = 0;
    *finish = 0;

    //Flags to track if base and range are set
    int base_set = 0
    int range_set = 0;

    //For loop through each command-line argument
    for (int i = 1; i < argc; i++) {
        
        //Check "-b" flag to specify base
        if (strcmp(argv[i], "-b") == 0 && i + 1 < argc) {
            
            //Convert next argument into integer for base
            *base = atoi(argv[++i]);

            //Check if the base is within the valid range (1 < BASE < 37)
            if (*base < MIN_BASE || *base > MAX_BASE) {
                //If it's not in the range, print error message
                fprintf(stderr, "Error: Base must be between 2 and 36.\n");
                return 1;
            }

            //Set flag to indicate base was specified
            base_set = 1;

        //Check "-r" flag to specify start and finish range
        } else if (strcmp(argv[i], "-r") == 0 && i + 2 < argc) {
            
            //Convert next argument to long for start
            *start = atol(argv[++i]);
            //Convert next argument to long for finish
            *finish = atol(argv[++i]);
            //Set flag to indicate range was specified
            range_set = 1;
        
        //If there is an invalid argument provided
        } else {
            //Display usage and return error
            usage();
            return 1;
        }
    }

    //If base or range was not specified
    if (!base_set || !range_set) {
        //Display usage and return error
        usage();
        return 1;
    }

    //Return 0 to indicate successful execution if all arguments are valid
    return 0;
}