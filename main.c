#ifndef MAIN_TW
#define MAIN_TW
#include "nbody.h"

// todo throws error if posx poy are the same on two different points

/*
struct body** test_data() 
{
    struct body **bodies;
    struct body *mybody;

    bodies = (struct body**) malloc(sizeof(struct body*) * NUM_BODIES);

    // test data
    mybody = (struct body*) malloc(sizeof(struct body));
    mybody->name = "B1";
    mybody->mass = 1;
    mybody->posX = 1;
    mybody->posY = 800;
    bodies[0] = mybody;

    mybody = (struct body*) malloc(sizeof(struct body));
    mybody->name = "B2";
    mybody->posX = 800;
    mybody->posY = 1;
    mybody->mass = 1;
    bodies[1] = mybody;

    mybody = (struct body*) malloc(sizeof(struct body));
    mybody->name = "B3";
    mybody->mass = 1;
    mybody->posX = 1;
    mybody->posY = 1;
    bodies[2] = mybody;

    mybody = (struct body*) malloc(sizeof(struct body));
    mybody->name = "B4";
    mybody->mass = 1;
    mybody->posX = 800;
    mybody->posY = 800;
    bodies[3] = mybody;

    mybody = (struct body*) malloc(sizeof(struct body));
    mybody->name = "B5";
    mybody->mass = 2;
    mybody->posX = 400;
    mybody->posY = 400;
    bodies[4] = mybody;

    mybody = (struct body*) malloc(sizeof(struct body));
    mybody->name = "B5";
    mybody->mass = 3.33;
    mybody->posX = 600;
    mybody->posY = 700;
    bodies[5] = mybody;

    mybody = (struct body*) malloc(sizeof(struct body));
    mybody->name = "B6";
    mybody->mass = 2.5;
    mybody->posX = 300;
    mybody->posY = 400;
    bodies[6] = mybody;

    mybody = (struct body*) malloc(sizeof(struct body));
    mybody->name = "B7";
    mybody->mass = 1.97;
    mybody->posX = 500;
    mybody->posY = 200;
    bodies[7] = mybody;

    return bodies;
}
*/

int main(int argc, char *argv[]) 
{
    struct body **bodies;
    int num_of_bodies = 8;

    if(argc == 2)
        num_of_bodies = atoi(argv[1]);

    srand(time(NULL));
    bodies = (struct body**) malloc(sizeof(struct body*) * num_of_bodies);

    for(int i = 0; i < num_of_bodies; i++) {
        bodies[i] = make_rand_body();
        body_print(bodies[i]);
    }

    puts("START\n");
    if(init_SDL() == 0)
        run(bodies, num_of_bodies); 

    return EXIT_SUCCESS;
}

#endif /* MAIN_TW */

