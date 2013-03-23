#ifndef NBODY_TW_H
#define NBODY_TW_H

#define SCREEN_RES_X 800
#define SCREEN_RES_Y 800
#define TICK_INTERVAL 300
#define TIME 100
#define GRAVITATIONAL_CONST 6.6742

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "SDL.h"
#include "gmp.h"

// the global universe 
struct universe {
    double g_const; // gravitiational constant
    int num_of_bodies;
    long time;
    struct body *bodies[3];
};

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
/*
typedef struct Point {
    double posX;
    double posY;
};
*/

void body_force(struct body *body1, struct body *body2);
double body_distance(struct body *body1, struct body *body2);
void body_velocity(struct body *body1, struct body *body2);
void body_print(struct body *mybody);

// global universe
extern struct universe myuniverse; // todo typedef me

// display
void run_SDL();
Uint32 timeleft_SDL();
//void DrawBody(SDL_Surface *screen, struct body *mybody);
void DrawPixel(SDL_Surface *screen, int x, int y, Uint8 R, Uint8 G, Uint8 B);

#endif /* NBODY_TW_H */

