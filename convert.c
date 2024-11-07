/*
// Ahmed Yassin, 400536694
// The convert utility is an integer conversion utility, designed to read longs from stdin, converts them to a new radix (base), and outputs the result to stdout
*/

void usage() {
    printf("Usage: convert [-b BASE] [-r START FINISH]\n");
    printf("1 < BASE < 37\n");
    printf("START and FINISH are long integers\n");
}

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

