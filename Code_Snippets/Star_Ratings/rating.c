// rating.c
#include <stdio.h>
#include "rating.h"  // Include the header file

void rating_to_stars(float rating) {
    // Ensure rating is between 0 and 5
    if (rating < 0 || rating > 5) {
        printf("Rating should be between 0 and 5\n");
        return;
    }

    int full_stars = (int)rating;   // Number of full stars
    int half_star = (rating - full_stars) >= 0.5 ? 1 : 0;  // Check for a half star
    int empty_stars = 5 - (full_stars + half_star);  // Remaining empty stars

    // Print full stars
    for (int i = 0; i < full_stars; i++) {
        printf("★");
    }

    // Print half star
    if (half_star) {
        printf("✮");
    }

    // Print empty stars
    for (int i = 0; i < empty_stars; i++) {
        printf("☆");
    }

    printf("\n");
}
