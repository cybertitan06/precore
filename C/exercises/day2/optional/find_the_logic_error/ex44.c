/**
 * Here some math for you.
 * The goal is to calculate the area of a circle, and then print "Hello World" to the screen!
 * There are varying degrees of 'errors' in this program.
 * There are also many solutions. Feel free to play around.
 * pow() is a 'power' function that raises the first argument
 * to the second argument.
 * @file ex44.c
*/

#include <stdio.h>
#include <math.h>


int main(int argc, char **argv) {
    float pi = 3.141;
    int diameter = 5;
    int radius = diameter / 2;

    // area = 1/2 * pi * r * r
    short area = 1/2 * pi * pow(radius , 2);


    printf("Area of a %d unit diameter circle is: %f\n", diameter, (float)area);
    printf("Expected: %f\n", 3.141*5*5/8);

    if (3.141*5*5/8 == (float)area){
        printf("Hello World!\n");
    }
    return 0;
}
