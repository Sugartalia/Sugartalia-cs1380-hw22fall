/* variant.c Natalia R */
#include <stdio.h>
#include "variant.h"

struct BothFields {
    int score;
    float average;
};

void print_stat(const struct Stat *s)
{
    if (s == NULL) {
        return;
    }
    if (s->kind == STAT_SCORE) {
        printf("score: %d\n", s->value.score);
    } else if (s->kind == STAT_AVERAGE) {
        printf("average: %.2f\n", s->value.average);
    } else {
        printf("unknown kind\n");
    }
}

void set_score(struct Stat *s, int score)
{
    if (s == NULL) {
        return;
    }
    s->kind = STAT_SCORE;
    s->value.score = score;
}

void set_average(struct Stat *s, float average)
{
    if (s == NULL) {
        return;
    }
    s->kind = STAT_AVERAGE;
    s->value.average = average;
}

int get_score(const struct Stat *s)
{
    if (s == NULL || s->kind != STAT_SCORE) {
        return 0;
    }
    return s->value.score;
}

float get_average(const struct Stat *s)
{
    if (s == NULL || s->kind != STAT_AVERAGE) {
        return 0.0f;
    }
    return s->value.average;
}

void print_sizes(void)
{
    printf("sizeof union StatValue: %zu\n", sizeof(union StatValue));
    printf("sizeof struct with int+float: %zu\n", sizeof(struct BothFields));
}
