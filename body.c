#ifndef BODY_TW
#define BODY_TW
#include "nbody.h"

/*
 * Create a random body
 */
void populate_random_body(struct body *mybody)
{
}

double body_distance(struct body *body1, struct body *body2) 
{
    return  sqrt(
            pow(body2->posX - body1->posX, 2.0) +
            pow(body2->posY - body1->posY, 2.0)
            );
    // todo subtrace radius or each??
}

// todo dont return instead sum members of body struct
void body_force(struct body *body1, struct body *body2) 
{
    // G * (m1 * m2)
    double totalmass = myuniverse.g_const * (body1->mass * body2->mass);
    double radius = body_distance(body1, body2);
    double theforce =  totalmass / (radius * radius);

    // what angle is the force
    double deltaY = body1->posY - body2->posY;
    double deltaX = body1->posX - body2->posX;
    // below Y axis is reveresed as Y goes down the page
    double angle = atan2(deltaX, deltaY) * 180 / M_PI;

    printf("angle: %f\n", angle);

    // given angle, calculate force for X and Y 
    body1->forceX += theforce * cos(angle);
    body1->forceY += theforce * sin(angle);
}


// calculates the force on the body
// force = G*mass / (radius * radius)
// force = G*m1*m2/rsqaured
    // force = g_const * mass / pow(radius, 2)
 /*
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
    */

void body_velocity(struct body *body1, struct body *body2) 
{
    // new v = v + (force * time) / mass
}

// force * timesquared / mass = distance
//void calc_body_distance

// move forward

void body_print(struct body *mybody) 
{
    // todo add posx posy?
    printf("%s----\nM: %f\nR: %fPX: %f PY: %f FX: %f FY: %f\n",
            mybody->name,
            mybody->mass,
            mybody->radius,
            mybody->posX,
            mybody->posY,
            mybody->forceX,
            mybody->forceY);
}

#endif /* BODY_TW */

