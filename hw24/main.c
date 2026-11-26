/* main.c Natalia R */
#include <stdio.h>
#include "variant.h"

int main(void)
{
    struct Stat a;
    struct Stat b;

    set_score(&a, 18);
    print_stat(&a);
    printf("get_score -> %d\n", get_score(&a));
    printf("wrong kind get_average -> %.2f\n", get_average(&a));

    set_average(&b, 3.5f);
    print_stat(&b);
    printf("get_average -> %.2f\n", get_average(&b));
    printf("wrong kind get_score -> %d\n", get_score(&b));

    print_sizes();

    print_stat(NULL);
    set_score(NULL, 1);
    printf("NULL calls did not crash\n");
    return 0;
}
