#ifndef UNIVERSE_TW
#define UNIVERSE_TW
#include "nbody.h"

struct universe myuniverse;

/*
 * Creates a global universe including any constants with gmp
 */
    /*
    mpf_init(myuniverse.g_const);
    mpf_set_str(myuniverse.g_const, "6.6742e-11", 10); 
    myuniverse.time = TIME;
    myuniverse.num_of_bodies = num_of_bodies;
    */

    //myuniverse.bodies

    /*
    for(int i = 0; i < num_of_bodies) {
        struct *body mybody;
        init_body(mybody);
    }
    */
    
//void run_universe() { // for one tick? step universe or somethign?

    /*
    for(int i = 0; i < myuniverse.time; i++) {
        for(int j = 0; j < myuniverse.num_of_bodies; j++) {
            calc_body_force(myunvierse.bodies[j]);
            calc_body_velocity(myuniverse.bodies[j]);
            calc_body_pos(myuniverse.bodies[j]);
        }
    }
    */
    
// for 0 to time
//  foreach body
//      compute force
//      compute velocity
//      compute new position
//
//  foreach body
//      update position


//}

#endif /* UNIVERSE_TW */

