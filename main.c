#ifndef MAIN_TW_H
#define MAIN_TW_H
//#include "nbody.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "gmp.h"

/*
void something() {
    //const long double GRAVITATIONAL_CONSTANT = 0.000000000066726;
    const long double G_CONST = 6.6726 * 10e-11;
    long double mass = 5.98 * 10e24; //kg
    long double radius = 6378100; // meters
    long double force = G_CONST * mass / pow(radius, 2);
    long long test = pow(6378100, 2);

    printf("G const: %Le\n", G_CONST);
    printf("mass: %Le\n", mass);
    printf("radius: %Le\n", radius);
    printf("force: %Le\n", force);

}
*/

// for real plantary data the numbers are too big!
void something() {
    //const long double GRAVITATIONAL_CONSTANT = 0.000000000066726;
    const long double G_CONST = 6.6726 * 10e-11;
    long double mass = 7.36 * 10e22; //kg
    long double radius = 1735771; // meters
    long double force = G_CONST * mass / pow(radius, 2);

    printf("G: %Le\n", G_CONST);
    printf("M: %Le\n", mass);
    printf("R: %Le\n", radius);
    printf("F: %Le\n", force);
}

void something2() 
{
    mpf_t g_const, mass, radius, force;

    mpf_init(g_const);
    mpf_init(mass); // kgs
    mpf_init(radius); // m2
    mpf_init(force);

    mpf_set_str(g_const, "6.6726e-11", 10);
    mpf_set_str(mass, "7.36e22", 10);
    mpf_set_str(radius, "1735771", 10);
    // force = g_const * mass / pow(radius, 2)
    
    mpf_pow_ui(radius, radius, 2); // pow 2 radius
    
    mpf_mul(force, g_const, mass);
    mpf_div(force, force, radius);

    gmp_printf("G: %.Fe\n", g_const);
    gmp_printf("M: %.Fe\n", mass);
    gmp_printf("R: %.Fe\n", radius);
    gmp_printf("F: %.Fe\n", force);

    mpf_clear(g_const);
    mpf_clear(mass);
    mpf_clear(radius);
    mpf_clear(force);
}

int main(int argc, char *argv[]) 
{
    //struct universe *myuniverse;
    //
    something();
    puts("--------");
    something2();

    mpf_set_default_prec(100);

    /*

    mpf_t afp;
    mp_exp_t exp;

    mpf_init(afp);
    if(mpf_set_str(afp, "6.6726e-11", 10) < 0)
        puts("error\n");

    //printf("G: %s\n", mpf_get_str(NULL, &exp, 10, 0, afp));
    gmp_printf("G: %.Fe\n", afp);

    mpf_clear(afp);
    */

    return EXIT_SUCCESS;
}

#endif /* MAIN_TW_H */

