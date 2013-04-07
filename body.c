#ifndef BODY_TW
#define BODY_TW
#include "nbody.h"

// create a body populated with random values
struct body* make_rand_body()
{
    struct body *mybody = (struct body*) malloc(sizeof(struct body));
    mybody->colour = (struct colour*) malloc(sizeof(struct colour));

    //mybody->mass = (double) (rand() % MAX_BODY_MASS) +
        //((rand() % 100) / 100.0); // 100 for 2 decimal places
    //mybody->mass = .05; // should rand between .05 .9 ?1?
    mybody->mass = (double)(rand() % MAX_BODY_MASS / 100.0) + 0.1;
    mybody->posX = rand() % SCREEN_RES_X + 1;
    mybody->posY = rand() % SCREEN_RES_X + 1;
    mybody->colour->red = rand() % 255;
    mybody->colour->green = rand() % 255;
    mybody->colour->blue = rand() % 255;

    return mybody;
}

// calculate the distance in pixcels between two bodies
double body_compute_distance(struct body *body1, struct body *body2) 
{
    return sqrt(
            pow(body2->posX - body1->posX, 2.0) +
            pow(body2->posY - body1->posY, 2.0)
            );
}

// calculate the current velocity given time 
void body_compute_velocity(struct body *nbody, int time) 
{
    nbody->velocityX = nbody->velocityX +
        ((time * nbody->forceX) / nbody->mass);
    nbody->velocityY = nbody->velocityY +
        ((time * nbody->forceY) / nbody->mass);
}

// calculate the bodys position given a velocity
void body_compute_position(struct body *mybody) 
{
    double newposX = mybody->velocityX * TIME_MAX;
    double newposY = mybody->velocityY * TIME_MAX;
    mybody->posX = mybody->posX + newposX;
    mybody->posY = mybody->posY + newposY;
}

// a subset of the bodies update on all bodies in the universe
void mp_update_bodies(int time,
        struct body *mybodies[], int my_num_bodies,
        struct body *bodies[], int num_bodies)
{

    for(int n = 0; n < my_num_bodies; n++) {
        // compute total force on body
        mybodies[n]->forceX = 0;
        mybodies[n]->forceY = 0;
        for(int j = 0; j < num_bodies; j++) {
            body_compute_force(mybodies[n], bodies[j]);
            //printf("%d against %d\n", n, j);
        }

        // compute velocity of body
        body_compute_velocity(mybodies[n], time);

        // compute new position of body
        body_compute_position(mybodies[n]);

        // print table of values
        //body_print(mybodies[n]);
    }

    //puts("\n");
}

// make an update on all bodies in the universe
void update_bodies(int time, struct body *bodies[], int num_bodies)
{
    for(int n = 0; n < num_bodies; n++) {
        // compute total force on body
        bodies[n]->forceX = 0;
        bodies[n]->forceY = 0;
        for(int j = 0; j < num_bodies; j++) 
            if(j != n)
                body_compute_force(bodies[n], bodies[j]);

        // compute velocity of body
        body_compute_velocity(bodies[n], time);

        // compute new position of body
        body_compute_position(bodies[n]);

        // print table of values
        //body_print(bodies[n]);
    }

    //puts("\n");
}

// add the caculated force on a body from another body
void body_compute_force(struct body *bodya, struct body *bodyb)
{
    double totalmass = GRAVITATIONAL_CONST * (bodya->mass * bodyb->mass);
    double radius = body_compute_distance(bodya, bodyb);
    if(radius == 0) // on top of each other or same point
        return;
    double theforce =  totalmass / (radius * radius);


    bodya->forceX += theforce * ((bodyb->posX - bodya->posX) / radius);
    bodya->forceY += theforce * ((bodyb->posY - bodya->posY) / radius);

    //printf("%s: %f %f\n", bodya->name, bodya->forceX, bodya->forceY);
}


void bodies_sync(int myid, int num_procs,
        struct body *bodies[], int num_bodies) 
{
    int my_num_bodies = num_bodies / num_procs;
    int ownedby = 0, bodies_low, bodies_high;

    //printf("id %d, low %d, high %d\n", myid, bodies_low, bodies_high);
    for(int i = 0; i < num_bodies; i++) {

        // determine what process has what bodies - bit ugly
        if(myid == 0) {
            for(int n = 0; n < num_procs; n++) {
                bodies_low = my_num_bodies * n; //truncate remainder 
                bodies_high = bodies_low + (my_num_bodies);

                // is bodies[i] in the owned range of proc n?
                if(i >= bodies_low && i < bodies_high) {
                    ownedby = n;
                    break;
                }
            }
        }

        // proc n will send data to all other procs
        MPI_Bcast(&ownedby, 1, MPI_INT, 0, MPI_COMM_WORLD);

        // update values of bodie i to other procs
        MPI_Bcast(&bodies[i]->posX, 1, MPI_DOUBLE, ownedby, MPI_COMM_WORLD);
        MPI_Bcast(&bodies[i]->posY, 1, MPI_DOUBLE, ownedby, MPI_COMM_WORLD);
        MPI_Bcast(&bodies[i]->velocityX, 1, MPI_DOUBLE, ownedby,
                MPI_COMM_WORLD);
        MPI_Bcast(&bodies[i]->velocityY, 1, MPI_DOUBLE, ownedby,
                MPI_COMM_WORLD);
    }

}

// print the values of a body
void body_print(struct body *mybody) 
{
    printf("M: %f PX: %f PY: %f VX: %f VY: %f\n",
            mybody->mass,
            mybody->posX,
            mybody->posY,
            mybody->velocityX,
            mybody->velocityY);
}

#endif /* BODY_TW */

