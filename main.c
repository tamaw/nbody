#ifndef MAIN_TW
#define MAIN_TW
#include "nbody.h"

// todo seg fault if posx poy are the same on two different points, 
// due to the values being -nan +nan (check divide by zero)

int main(int argc, char *argv[]) 
{
    struct body **bodies;
    int num_of_bodies = 8;

    // argument passed becomes number of bodies
    if(argc == 2)
        num_of_bodies = atoi(argv[1]);

    // set up bodies
    srand(time(NULL));
    bodies = (struct body**) malloc(sizeof(struct body*) * num_of_bodies);
    for(int i = 0; i < num_of_bodies; i++) {
        bodies[i] = make_rand_body();
        body_print(bodies[i]);
    }

    // init SDL and run
    if(SDL_Init(SDL_INIT_VIDEO) == 0 && SDL_SetVideoMode(
                SCREEN_RES_X, SCREEN_RES_Y, 16, SDL_SWSURFACE) != NULL) {
        atexit(SDL_Quit);
        run(bodies, num_of_bodies); 
    }
    else { // on error return
        fprintf(stderr, "Unable to set video: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

#endif /* MAIN_TW */

