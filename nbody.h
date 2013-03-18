#ifndef NBODY_TW_H
#define NBODY_TW_H

#define SCREEN_RES_X 800
#define SCREEN_RES_Y 800

#include <stdio.h>
#include <stdlib.h>
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
    mpf_t velocityX;
    mpf_t velocityY;
    mpf_t mass; // kgs
    mpf_t radius; // m2
    mpf_t force; 
    char *name;
};

void init_body(struct body *);
void print_body(struct body *);
void calc_body_force(struct body *);

// universe 
struct universe {
    mpf_t g_const; // gravitiational constant
    int num_of_bodies;
    long time;
    struct body *bodies;
};

int init_universe(long num_of_bodies);

// global universe
extern struct universe myuniverse;

#endif /* NBODY_TW_H */

