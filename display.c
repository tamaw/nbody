#ifndef DISPLAY_TW
#define DISPLAY_TW

#include <math.h>
#include "nbody.h"

Uint32 timeleft();

// todo make old bodies so we can clear previous pos
// todo maybe even store all and timeshift it?

// main loop, updates bodies, draws them and handels events
void run(struct body *bodies[], int num_bodies, int myid, int num_procs)
{ 
    SDL_Surface *screen = SDL_GetVideoSurface();
    SDL_Event event;

    bool running = true;
    int time = 0;

    int my_num_bodies = num_bodies / num_procs;
    struct body *mybodies[my_num_bodies];

    int bodies_low = my_num_bodies * myid; // drop remainer
    int bodies_high = bodies_low + (my_num_bodies);
    for(int n = 0, i = bodies_low; i < bodies_high; i++, n++)
        mybodies[n] = bodies[i];

    while(running) {
        if(time <= TIME_MAX) {
            // todo clone bodies for first and next pos. update easier?
            
            if(MPI_ON) { // multi process update
                mp_update_bodies(time, mybodies, my_num_bodies,
                        bodies, num_bodies);
                bodies_sync(myid, num_procs, bodies, num_bodies);
            } else {// one process updates all bodies
                update_bodies(time, bodies, num_bodies);
            }

            if(myid == 0) {
                if(DISPLAY_ON)
                    draw_bodies(screen, bodies, num_bodies);
                printf(" %d ", time);
                fflush(stdout);
            }

            time++;
        } else if(time > TIME_MAX && !DISPLAY_ON) {
            running = false; // with no display, end on TIME_MAX
        }

        if(myid == 0 && DISPLAY_ON) {
            SDL_Delay(timeleft()); // sleep for framerate

            // process incoming events
            while(SDL_PollEvent(&event))
                if(event.type == SDL_QUIT)
                    running = false;
        }

        // sync is running
        MPI_Bcast(&running, 1, MPI_C_BOOL, 0, MPI_COMM_WORLD);
    }
}

Uint32 timeleft() 
{
    static Uint32 next_time = 0;
    Uint32 now = SDL_GetTicks();

    if(next_time <= now) {
        next_time = now + TICK_INTERVAL;
        return 0;
    }
    return next_time - now;
}

void draw_bodies(SDL_Surface *screen, struct body *bodies[],
        int num_bodies)  
{
    for(int n = 0; n < num_bodies; n++) {
        // todo remove square position of old body
        // todo draw updated body here
        
        if(bodies[n]->posX > SCREEN_RES_X || bodies[n]->posY > SCREEN_RES_Y 
                || bodies[n]->posX < 0 || bodies[n]->posY < 0)
            continue;// outside of drawable screen

        DrawPixel(screen, bodies[n]->posX, bodies[n]->posY,
                bodies[n]->colour->red,
                bodies[n]->colour->green,
                bodies[n]->colour->blue);
    }

    //SDL_Flip(screen); // very expensive, better to remove last bodies
}

// draws a coloured pixel and the x,y coordinates 
void DrawPixel(SDL_Surface *screen,
        int x, int y, Uint8 R, Uint8 G, Uint8 B)
{
    Uint32 colour = SDL_MapRGB(screen->format, R, G, B);
    Uint8 *bufp = (Uint8*) screen->pixels + y * screen->pitch
        + x * screen->format->BytesPerPixel;

    switch (screen->format->BytesPerPixel)
    {
        case 4: // 32-bpp
            bufp[3] = colour >> 24;
        case 3: // 24-bpp 
            bufp[2] = colour >> 16;
        case 2: // 15 or 16-bpp
            bufp[1] = colour >> 8;
        case 1: // 8-bpp
            bufp[0] = colour;
    }

    SDL_UpdateRect(screen, x, y, 1, 1);
}

#endif /* DISPLAY_TW */

