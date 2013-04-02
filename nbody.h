#ifndef NBODY_TW_H
#define NBODY_TW_H

#define SCREEN_RES_X 800
#define SCREEN_RES_Y 800
#define TICK_INTERVAL 5
#define TIME_MAX 200
#define GRAVITATIONAL_CONST 6.6742

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include "SDL.h"
#include "gmp.h"

// body 
struct body {
    double posX;
    double posY;
    double velocityX;
    double velocityY;
    double forceX; 
    double forceY; 
    double mass; // kgs
    double radius; // m2
    char *name;
};


// todo introduce me to body
struct point {
    double x, y;
};
typedef struct point Point;

// body function prototypes
struct body* make_rand_body();
void body_compute_force(struct body *bodya, struct body *bodyb);
double body_compute_distance(struct body *body1, struct body *body2);
void body_compute_velocity(struct body *body1, int time);
void body_compute_position(struct body *mybody);
void body_print(struct body *mybody);
void update_bodies(int time, struct body *bodies[], int num_bodies);
void draw_bodies(SDL_Surface *screen, struct body *bodies[],
        int num_of_bodies);

// display
void run(struct body *bodies[], int num_bodies);
int init_SDL();
void DrawPixel(SDL_Surface *screen, int x, int y, Uint8 R, Uint8 G, Uint8 B);

#endif /* NBODY_TW_H */

