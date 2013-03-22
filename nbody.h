#ifndef NBODY_TW_H
#define NBODY_TW_H

#define SCREEN_RES_X 800
#define SCREEN_RES_Y 800
#define TIME 100
#define NUM_BODIES 3
#define TICK_INTERVAL 300

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "SDL.h"
#include "gmp.h"

// display function prototypes
/*
void init_SDL();
void events_SDL();
void render_SDL();
void cleanup_SDL();
*/

// body 
struct body {
    double posX;
    double posY;
    mpf_t velocityX;
    mpf_t velocityY;
    mpf_t mass; // kgs
    mpf_t radius; // m2
    mpf_t force; 
    char *name;
};

void init_body(struct body *mybody);
void print_body(struct body *mybody);
void calc_body_force(struct body *mybody);
void destroy_body(struct body *mybody);

// universe 
struct universe {
    mpf_t g_const; // gravitiational constant
    int num_of_bodies;
    long time;
    struct body *bodies[NUM_BODIES];
};

int init_universe(long num_of_bodies);
void destroy_universe();

// global universe
extern struct universe myuniverse;

//SDL
void run_SDL();
Uint32 timeleft_SDL();
//void DrawBody(SDL_Surface *screen, struct body *mybody);
void DrawPixel(SDL_Surface *screen, int x, int y, Uint8 R, Uint8 G, Uint8 B);

#endif /* NBODY_TW_H */

