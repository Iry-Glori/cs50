/***************************************************************************
 * generate.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 ***************************************************************************/
 
// standard libraries
#define _XOPEN_SOURCE
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// constant
#define LIMIT 65536

int main(int argc, string argv[])
{
    // Checks the number of arguments to give the user usage instructions if 2 or three arguments are not passed (incl. ./generate)
    if (argc != 2 && argc != 3)
    {
        printf("Usage: generate n [s]\n");
        return 1;
    }

    // Converts the first chars passed as an argument into an integer to be used later as the number of numbers to generate
    int n = atoi(argv[1]);

    // srand is an initialization function for drand48

    // In the case where three arguments are passed (2 ints) the second int is used for the srand initialization
    if (argc == 3)
    {
        srand48((long int) atoi(argv[2]));
    }
    // In the case where only 2 arguments are passed, the a call to time(NULL) returns the seconds and is used for the initialization
    // The use of time makes the returned numbers seem random, as repeated calls will use different time values
    else
    {
        srand48((long int) time(NULL));
    }

    // Prints the designated number of random-seeming numbers generated by drand48 and initialized by the srand48 above
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}
