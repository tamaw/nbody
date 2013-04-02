#ifndef BODY_TW
#define BODY_TW
#include "nbody.h"

/*
 * Create a random body
 */
struct body* make_rand_body()
{
    struct body *mybody = (struct body*) malloc(sizeof(struct body));
    mybody->mass = 1;
    mybody->posX = rand() % 800 + 1;
    mybody->posY = rand() % 800 + 1;

    return mybody;
}

// todo function for new body

double body_compute_distance(struct body *body1, struct body *body2) 
{
    double sq =  sqrt(
            pow(body2->posX - body1->posX, 2.0) +
            pow(body2->posY - body1->posY, 2.0)
            );

    //printf("sq: %f\n", sq);
    return sq;
    // todo subtract radius of each body??
}

void body_compute_velocity(struct body *nbody, int time) 
{
    // new v = v + (force * time) / mass

    double velocityX = nbody->velocityX +
        ((time * nbody->forceX) / nbody->mass);
    double velocityY = nbody->velocityY +
        ((time * nbody->forceY) / nbody->mass);

    nbody->velocityX = velocityX;
    nbody->velocityY = velocityY;

    //printf("%s: VX: %f VY: %f\n", body1->name, body1->velocityX, body1->velocityY);
}

void body_compute_position(struct body *mybody) {
    double newposX = mybody->velocityX * TIME_MAX;
    double newposY = mybody->velocityY * TIME_MAX;
    mybody->posX = mybody->posX + newposX;
    mybody->posY = mybody->posY + newposY;

    //printf("%s: %f %f\n", mybody->name, newposX, newposY);
}

void update_bodies(int time, struct body *bodies[], int num_bodies)
{
    for(int n = 0; n < num_bodies; n++) {
        bodies[n]->forceX = 0;
        bodies[n]->forceY = 0;

        // compute total force on body
        for(int j = 0; j < num_bodies; j++) 
            if(j != n)
                body_compute_force(bodies[n], bodies[j]);

        // compute velocity of body
        body_compute_velocity(bodies[n], time);

        // compute new position of body
        body_compute_position(bodies[n]);

        // print table of values
        body_print(bodies[n]);
    }

    puts("\n");
}

void body_compute_force(struct body *bodya, struct body *bodyb)
{
    // (G * (m1 * m2)) * xb - ya
    double totalmass = GRAVITATIONAL_CONST * (bodya->mass * bodyb->mass);
    double radius = body_compute_distance(bodya, bodyb);
    double theforce =  totalmass / (radius * radius);

    bodya->forceX += theforce * ((bodyb->posX - bodya->posX) / radius);
    bodya->forceY += theforce * ((bodyb->posY - bodya->posY) / radius);

    //printf("%s: %f %f\n", bodya->name, bodya->forceX, bodya->forceY);
}

void body_print(struct body *mybody) 
{
    printf("%s M: %f PX: %f PY: %f VX: %f VY: %f\n",
            mybody->name,
            mybody->mass,
            mybody->posX,
            mybody->posY,
            mybody->velocityX,
            mybody->velocityY);
}

#endif /* BODY_TW */

