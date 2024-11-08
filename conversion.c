/*
// Ahmed Yassin, 400536694
// The convert utility is an integer conversion utility, designed to read longs from stdin, converts them to a new radix (base), and outputs the result to stdout
*/

//convert_to_base function converts a number to the specified base and prints each digit
void convert_to_base(long num, int base) {

    //Array of characters to represent digits in bases up to 36
    char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int remainder;

    //If number is negative
    if (num < 0) {
        //Print a minus sign
        putchar('-');
        //Make the number positive
        num = -num;
    }

    //Rightmost digit in the specified base
    remainder = num % base;

    //Recursive call convert_to_base function on the quotient to process higher-order digits
    if (num >= base) {
        convert_to_base(num / base, base);
    }

    //Output the current digit after recursive calls
    putchar(digits[remainder]);
}
