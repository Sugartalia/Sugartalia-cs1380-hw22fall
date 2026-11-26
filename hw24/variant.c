/*
 * variant.c
 * Functions for a stat that is either an int score or a float average.
 * Author: Natalia Robertson
 */

#include <stdio.h>
#include "variant.h"

/* A struct with both fields, only used to compare sizes */
struct BothFields {
    int score;
    float average;
};

/* Print the stat based on its kind */
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

/* Store a score and set the kind */
void set_score(struct Stat *s, int score)
{
    if (s == NULL) {
        return;
    }

    s->kind = STAT_SCORE;
    s->value.score = score;
}

/* Store an average and set the kind */
void set_average(struct Stat *s, float average)
{
    if (s == NULL) {
        return;
    }

    s->kind = STAT_AVERAGE;
    s->value.average = average;
}

/* Return the score, or 0 if it is not a score */
int get_score(const struct Stat *s)
{
    if (s == NULL) {
        return 0;
    }

    if (s->kind != STAT_SCORE) {
        return 0;
    }

    return s->value.score;
}

/* Return the average, or 0.0 if it is not an average */
float get_average(const struct Stat *s)
{
    if (s == NULL) {
        return 0.0f;
    }

    if (s->kind != STAT_AVERAGE) {
        return 0.0f;
    }

    return s->value.average;
}

/* Show that the union is smaller than a struct with both fields */
void print_sizes(void)
{
    printf("sizeof union StatValue: %zu\n", sizeof(union StatValue));
    printf("sizeof struct with int+float: %zu\n", sizeof(struct BothFields));
}
