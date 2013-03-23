#ifndef MAIN_TW
#define MAIN_TW
#include "nbody.h"

int main(int argc, char *argv[]) 
{
    struct body *mybody;

    //init_universe(3);
    
    myuniverse.g_const = GRAVITATIONAL_CONST;
    myuniverse.time = TIME;
    myuniverse.num_of_bodies = 3; // todo argv me & rand bodies

    mybody = (struct body*) malloc(sizeof(struct body));
    mybody->name = "M1";
    mybody->mass = 5.933;
    mybody->posX = 300;
    mybody->posY = 600;
    myuniverse.bodies[0] = mybody;

    mybody = (struct body*) malloc(sizeof(struct body));
    mybody->name = "M2";
    mybody->mass = 2.2;
    mybody->posX = 200;
    mybody->posY = 600;
    myuniverse.bodies[1] = mybody;

    mybody = (struct body*) malloc(sizeof(struct body));
    mybody->name = "M3";
    mybody->mass = 8.3;
    mybody->posX = 400;
    mybody->posY = 300;
    myuniverse.bodies[2] = mybody;

    body_force(
            myuniverse.bodies[1],
            myuniverse.bodies[2]);
    body_force(
            myuniverse.bodies[1],
            myuniverse.bodies[0]);


    body_print(myuniverse.bodies[0]);
    body_print(myuniverse.bodies[1]);
    body_print(myuniverse.bodies[2]);

    run_SDL(); // this should be in here or something

    // need exit finaliser to clear used gmp, sdl, mpi

    return EXIT_SUCCESS;
}

#endif /* MAIN_TW */

