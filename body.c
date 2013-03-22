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
    mpf_inits(mybody->mass, mybody->radius, mybody->force,
            mybody->velocityX, mybody->velocityY, NULL);
}

void destroy_body(struct body *mybody) 
{
    mpf_clears(mybody->mass, mybody->radius, mybody->force,
            mybody->velocityX, mybody->velocityY, NULL);
}



/*
 * Create a random body
 */
void populate_random_body(struct body *mybody)
{
}

double calc_body_distance(struct body *body1, struct body *body2) 
{
    double distance; // todo make gmp?

    distance = sqrt(
}


// calculates the force on the body
// force = G*mass / (radius * radius)
// force = G*m1*m2/rsqaured
void calc_body_force(struct body *mybody) 
{
    // force = g_const * mass / pow(radius, 2)
    mpf_t totalmass, tempforce, tempradius;
    mpf_inits(totalmass, tempforce, tempradius, NULL);

    // force = 0
    mpf_set_si(mybody->force, 0L);

    for(int i = 0; i < myuniverse.num_of_bodies; i++) {
        struct body *otherbody = myuniverse.bodies[i];
        // todo calc distance between bodies

        /// m1 * m2
        mpf_mul(totalmass, mybody->mass, otherbody->mass);
        // r * r !!! radius is distance between two bodies!
        mpf_pow_ui(tempradius, mybody->radius, 2); 
        // G * (m1 * m2)
        mpf_mul(tempforce, myuniverse.g_const, totalmass);
        // (G * (m1 * m2)) / (r * r)
        mpf_div(tempforce, mybody->force, mybody->radius);

        // sum force
        mpf_add(mybody->force, mybody->force, tempforce);
    }

    mpf_clears(totalmass, tempforce, tempradius, NULL);
}

void calc_body_velocity(struct body *mybody) 
{
    // new v = v + (force * time) / mass
}

void calc_body_pos(struct body *mybody) 
{
}


// force * timesquared / mass = distance
//void calc_body_distance

// move forward

void print_body(struct body *mybody) 
{
    printf("%s:\n", mybody->name);
    gmp_printf("G: %.Fe\n", myuniverse.g_const);
    gmp_printf("M: %.Fe\n", mybody->mass);
    gmp_printf("R: %.Fe\n", mybody->radius);
    gmp_printf("F: %.Fe\n", mybody->force);
}

#endif /* BODY_TW */

