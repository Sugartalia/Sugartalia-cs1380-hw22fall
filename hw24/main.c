/*
 * main.c
 * Demo of the Stat union: score, average, wrong kind, sizes, and NULL.
 * Author: Natalia Robertson
 */

#include <stdio.h>
#include "variant.h"

int main(void)
{
    struct Stat s;

    /* Set a score */
    set_score(&s, 18);
    print_stat(&s);
    printf("get_score -> %d\n", get_score(&s));
    printf("wrong kind get_average -> %.2f\n", get_average(&s));

    /* Set an average */
    set_average(&s, 3.5f);
    print_stat(&s);
    printf("get_average -> %.2f\n", get_average(&s));
    printf("wrong kind get_score -> %d\n", get_score(&s));

    /* Show the sizes */
    print_sizes();

    /* NULL calls should not crash */
    print_stat(NULL);
    set_score(NULL, 1);
    set_average(NULL, 1.0f);
    printf("NULL calls did not crash\n");

    return 0;
}
