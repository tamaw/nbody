#ifndef MAIN_TW_H
#define MAIN_TW_H
#include "nbody.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "gmp.h"
#include "SDL.h"

// for real plantary data the numbers are too big!
void something() {
    //const long double GRAVITATIONAL_CONSTANT = 0.000000000066726;
    const long double G_CONST = 6.6726 * 10e-11;
    long double mass = 7.36 * 10e22; //kg
    long double radius = 1735771; // meters
    long double force = G_CONST * mass / pow(radius, 2);

    printf("G: %Le\n", G_CONST);
    printf("M: %Le\n", mass);
    printf("R: %Le\n", radius);
    printf("F: %Le\n", force);
}

void something2() 
{
    mpf_t g_const, mass, radius, force;

    mpf_init(g_const);
    mpf_init(mass); // kgs
    mpf_init(radius); // m2
    mpf_init(force);

    mpf_set_str(g_const, "6.6726e-11", 10);
    mpf_set_str(mass, "7.36e22", 10);
    mpf_set_str(radius, "1735771", 10);
    // force = g_const * mass / pow(radius, 2)
    
    mpf_pow_ui(radius, radius, 2); // pow 2 radius
    
    mpf_mul(force, g_const, mass);
    mpf_div(force, force, radius);

    gmp_printf("G: %.Fe\n", g_const);
    gmp_printf("M: %.Fe\n", mass);
    gmp_printf("R: %.Fe\n", radius);
    gmp_printf("F: %.Fe\n", force);

    mpf_clear(g_const);
    mpf_clear(mass);
    mpf_clear(radius);
    mpf_clear(force);
}

int main(int argc, char *argv[]) 
{
    //struct universe *myuniverse;
    //
    mpf_set_default_prec(100);

    something();
    puts("--------");
    something2();

    // start SDL

    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "Unable to init SDL: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    SDL_Surface *screen;

    screen = SDL_SetVideoMode(SCREEN_RES_X, SCREEN_RES_Y,
            16, SDL_SWSURFACE);
    if(screen == NULL) {
        fprintf(stderr, "Unable to set video: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    atexit(SDL_Quit);
    // sdl init done

    DrawPixel(screen, 255, 0 0);

    // wait
    getchar();

    return EXIT_SUCCESS;
}

#endif /* MAIN_TW_H */

