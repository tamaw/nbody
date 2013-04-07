#ifndef MAIN_TW
#define MAIN_TW
#include "nbody.h"

// todo seg fault if posx poy are the same on two different points, 
// due to the values being -nan +nan (check divide by zero)

int main(int argc, char *argv[]) 
{
	int myid = -1, num_procs = 0;
    struct body **bodies;
    int num_of_bodies = NUM_BODIES;

    // set up bodies
    srand(time(NULL));
    bodies = (struct body**)malloc(sizeof(struct body*) * num_of_bodies);
    for(int i = 0; i < num_of_bodies; i++) {
        bodies[i] = make_rand_body();
    }

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);
    if(MPI_ON && myid == 0)
        puts("Using MPI");

    if(myid == 0 && DISPLAY_ON) { // init SDL 
        puts("Using display please wait...");
        if(SDL_Init(SDL_INIT_VIDEO) == 0 && SDL_SetVideoMode(
                    SCREEN_RES_X, SCREEN_RES_Y, 16, SDL_SWSURFACE) != NULL)
            atexit(SDL_Quit);
        else { // on error return
            fprintf(stderr, "Unable to set video: %s\n", SDL_GetError());
            return EXIT_FAILURE;
        }
    } 

    // start!!
    if(myid == 0 && PRINT_ON) {
        printf("Starting with %d ticks\n", TIME_MAX);
        for(int i = 0; i < num_of_bodies; i++)
            body_print(bodies[i]);
    }

    run(bodies, num_of_bodies, myid, num_procs); 

    // finished
    if(myid == 0 && PRINT_ON) {
        puts("\nFinished");
        for(int i = 0; i < num_of_bodies; i++)
            body_print(bodies[i]);
    }

	MPI_Finalize();
    return EXIT_SUCCESS;
}

#endif /* MAIN_TW */

