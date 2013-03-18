#ifndef MAIN_TW
#define MAIN_TW
#include "nbody.h"

int main(int argc, char *argv[]) 
{
    struct body *sun, *earth, *moon;

    mpf_set_default_prec(100);

    init_universe(3);

    // test data
    sun = (struct body*) malloc(sizeof(struct body));
    init_body(sun);
    sun->name = "Sun";
    mpf_set_str(sun->mass, "1.988435e30", 10);
    mpf_set_str(sun->radius, "6.955e8", 10);

    earth = (struct body*) malloc(sizeof(struct body));
    init_body(earth);
    earth->name = "Earth";
    mpf_set_str(earth->mass, "5.9736e24", 10);
    mpf_set_str(earth->radius, "6.3675e6", 10);

    moon = (struct body*) malloc(sizeof(struct body));
    init_body(moon);
    moon->name = "Moon";
    mpf_set_str(moon->mass, "7.3459e22", 10);
    mpf_set_str(moon->radius, "1.7375e6", 10);

    calc_body_force(sun);
    calc_body_force(earth);
    calc_body_force(moon);

    print_body(sun);
    print_body(earth);
    print_body(moon);

    /*
    init_SDL();

    for(;;) {
        events();
        render();
        // loop ??

        // wait
        getchar();
        break;
    }

    cleanup();
    */

    return EXIT_SUCCESS;
}

#endif /* MAIN_TW */

