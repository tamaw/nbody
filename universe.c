#ifndef UNIVERSE_TW
#define UNIVERSE_TW
#include "nbody.h"

struct universe myuniverse;

/*
 * Creates a global universe including any constants with gmp
 */
int init_universe(long num_of_bodies) 
{
    mpf_init(myuniverse.g_const);
    mpf_set_str(myuniverse.g_const, "6.6742e-11", 10); 
    //myuniverse.time ???

    myuniverse.num_of_bodies = num_of_bodies;
    myuniverse.bodies = (struct body*)malloc(
            sizeof(struct body) * num_of_bodies);

    /*
    for(int i = 0; i < num_of_bodies) {
        struct *body mybody;
        init_body(mybody);
    }
    */
    
    return 0;
}


/*
void UpdateUniverse(struct universe *myuniverse) 
{

};
*/

/*
Universe make_universe(Body* bodies, int num_bodies)
{
    // asser bodies not null


}
*/

#endif /* UNIVERSE_TW */

