#ifndef MAIN_TW
#define MAIN_TW
#include "nbody.h"

int main(int argc, char *argv[]) 
{
    struct body *sun, *earth, *moon;

    mpf_set_default_prec(100);

    init_universe(3);

    // test data
    sun = (struct body*) malloc(sizeof(struct body));
    init_body(sun);
    sun->name = "Sun";
    mpf_set_str(sun->mass, "1.988435e30", 10);
    mpf_set_str(sun->radius, "6.955e8", 10);
    sun->posX = 300;
    sun->posY = 600;
    myuniverse.bodies[0] = sun;

    earth = (struct body*) malloc(sizeof(struct body));
    init_body(earth);
    earth->name = "Earth";
    mpf_set_str(earth->mass, "5.9736e24", 10);
    mpf_set_str(earth->radius, "6.3675e6", 10);
    earth->posX = 400;
    earth->posY = 200;
    myuniverse.bodies[1] = earth;

    moon = (struct body*) malloc(sizeof(struct body));
    init_body(moon);
    moon->name = "Moon";
    mpf_set_str(moon->mass, "7.3459e22", 10);
    mpf_set_str(moon->radius, "1.7375e6", 10);
    moon->posX = 200;
    moon->posY = 600;
    myuniverse.bodies[2] = moon;

    //calc_body_force(sun);
    //calc_body_force(earth);
    //calc_body_force(moon);

    print_body(sun);
    print_body(earth);
    print_body(moon);

    run_SDL(); // this should be in here or something

    // clean up
    for(int i = 0; i < myuniverse.num_of_bodies; i++)
        destroy_body(myuniverse.bodies[i]);
    destroy_universe();

    // need exit finaliser to clear used gmp, sdl, mpi

    return EXIT_SUCCESS;
}

#endif /* MAIN_TW */

