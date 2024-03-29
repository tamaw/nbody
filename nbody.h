#ifndef NBODY_TW_H
#define NBODY_TW_H

#define SCREEN_RES_X 800
#define SCREEN_RES_Y 800
#define NUM_BODIES 800
#define MAX_BODY_MASS 9
#define TICK_INTERVAL 50
#define TIME_MAX 1000
#define GRAVITATIONAL_CONST 6.6742
#define DISPLAY_ON false
#define MPI_ON true
#define PRINT_ON false


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include "mpi.h"
#include "SDL.h"
#include "gmp.h"

// a colour for the display
struct colour {
    char red, green, blue;
};

// represents a plantary body 
struct body {
    double posX;
    double posY;
    double velocityX;
    double velocityY;
    double forceX; 
    double forceY; 
    double mass; // kgs
    struct colour *colour;
};

// body function prototypes
double body_compute_distance(struct body *body1, struct body *body2);
void body_compute_force(struct body *bodya, struct body *bodyb);
void body_compute_velocity(struct body *body1, int time);
void body_compute_position(struct body *mybody);
struct body* make_rand_body();
void body_print(struct body *mybody);
void update_bodies(int time, struct body *bodies[], int num_bodies);
void mp_update_bodies(int time, struct body *mybodies[], int my_num_bodies,
        struct body *bodies[], int num_bodies);
void bodies_sync(int myid, int num_procs,
        struct body *bodies[], int num_bodies);

// display
void run(struct body *bodies[], int num_bodies, int myid, int num_procs);
void DrawPixel(SDL_Surface *screen, int x, int y, Uint8 R, Uint8 G, Uint8 B);
void draw_bodies(SDL_Surface *screen, struct body *bodies[],
        int num_of_bodies);

#endif /* NBODY_TW_H */

