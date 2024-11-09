/*
// Ahmed Yassin, 400536694
// The convert utility is an integer conversion utility, designed to read longs from stdin, converts them to a new radix (base), and outputs the result to stdout
*/

#include <stdio.h>
#include "input_controller.h"
#include "conversion.h"

//Main function to drive conversion program
int main(int argc, char *argv[]) {

    int base;
    long start, finish;

    //Run handle_args function; if the execution is unsuccessful then return with failure
    if (handle_args(argc, argv, &base, &start, &finish) != 0) {
        return 1;
    }

    //For loop through each number in the range and convert to the base
    for (long i = start; i <= finish; i++) {

        //Display number and base
        printf("%ld in base %d is ", i, base);
        //Convert the number in the specified base and output it
        convert_to_base(i, base);
        printf("\n");
    }
    
    //Return 0 to indicate successful execution
    return 0;
}