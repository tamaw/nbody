#ifndef BODY_TW
#define BODY_TW
#include "nbody.h"
#include "gmp.h"

/*
    const long double G_CONST = 6.6726 * 10e-11;
    long double mass = 7.36 * 10e22; //kg
    long double radius = 1735771; // meters
    long double force = G_CONST * mass / pow(radius, 2);
    */

void init_body(struct body *mybody) 
{
    // todo int rc = response return init fail
    mpf_init(mybody->mass); // kgs
    mpf_init(mybody->radius); // m2
    mpf_init(mybody->force);
    mpf_init(mybody->velocityX);
    mpf_init(mybody->velocityY);
}

void destroy_body(struct body *mybody) 
{
    mpf_clear(mybody->mass);
    mpf_clear(mybody->radius);
    mpf_clear(mybody->force);
    mpf_clear(mybody->velocityX);
    mpf_clear(mybody->velocityY);
}

/*
 * Create a random body
 */
void populate_random(struct body *mybody)
{
}

// calculates the force on the body
// force = G*mass / (radius * radius)
// force = G*m1*m2/rsqaured
void calc_body_force(struct body *mybody) 
{
    // force = g_const * mass / pow(radius, 2)
    mpf_pow_ui(mybody->radius, mybody->radius, 2); // radius squared
    mpf_mul(mybody->force, myuniverse.g_const, mybody->mass);
    mpf_div(mybody->force, mybody->force, mybody->radius);
}

void print_body(struct body *mybody) 
{
    printf("%s:\n", mybody->name);
    gmp_printf("G: %.Fe\n", myuniverse.g_const);
    gmp_printf("M: %.Fe\n", mybody->mass);
    gmp_printf("R: %.Fe\n", mybody->radius);
    gmp_printf("F: %.Fe\n", mybody->force);
}

#endif /* BODY_TW */

