
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#include"taylorseries.h"

//--------------------------------------------------------
// FUNCTION PROTOTYPES
//--------------------------------------------------------
void print_sines(double from_degrees, double to_degrees, double step);

//--------------------------------------------------------
// FUNCTION main
//--------------------------------------------------------
void main(void)
{
    puts("-------------------------------");
    puts("| codedrome.com               |");
    puts("| Taylor Series Trigonometric |");
    puts("-------------------------------\n");

    print_sines(0.0, 360.0, 30);
}

//--------------------------------------------------------
// FUNCTION print_sines
//--------------------------------------------------------
void print_sines(double from_degrees, double to_degrees, double step)
{
    if(taylor_init(11))
    {
        printf("-----------------------------------------------------------------------------------------\n");
        printf("| Degrees |  C Library |   Taylor 3 |   Taylor 5 |   Taylor 7 |   Taylor 9 |  Taylor 11 |\n");
        printf("-----------------------------------------------------------------------------------------\n");

        for(double degrees = from_degrees; degrees <= to_degrees; degrees += step)
        {
            printf("| %7.0lf | %10.6lf | %10.6lf | %10.6lf | %10.6lf | %10.6lf | %10.6lf |\n",
            degrees,
            sin(degrees / DEGREES_IN_RADIAN),
            taylor_sin_rad(degrees / DEGREES_IN_RADIAN, 3),
            taylor_sin_rad(degrees / DEGREES_IN_RADIAN, 5),
            taylor_sin_rad(degrees / DEGREES_IN_RADIAN, 7),
            taylor_sin_rad(degrees / DEGREES_IN_RADIAN, 9),
            taylor_sin_rad(degrees / DEGREES_IN_RADIAN, 11));
        }

        printf("-----------------------------------------------------------------------------------------\n");

        taylor_free();
    }
}
