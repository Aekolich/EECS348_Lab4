#include <stdio.h>

/* Lab 4 - Problem 1
 * This program finds all the combinations of scoring plays that can add up to a given NFL score.
 */

int main() {
    int target_score;

    
    while (1) {
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &target_score);

        if (target_score <= 1) {
            break;
        }

        printf("Possible combinations of scoring plays if a team's score is %d:\n", target_score);

        
        int td8; // Touchdown + 2pt
        int td7; // Touchdown + 1pt
        int td6; // Normal Touchdown
        int fg3; // Field Goal
        int s2;  // Safety
        int current_total;

        
        for (td8 = 0; td8 * 8 <= target_score; td8++) {
            for (td7 = 0; td7 * 7 <= target_score; td7++) {
                for (td6 = 0; td6 * 6 <= target_score; td6++) {
                    for (fg3 = 0; fg3 * 3 <= target_score; fg3++) {
                        for (s2 = 0; s2 * 2 <= target_score; s2++) {
                            
                            current_total = 0;
                            current_total = current_total + (td8 * 8);
                            current_total = current_total + (td7 * 7);
                            current_total = current_total + (td6 * 6);
                            current_total = current_total + (fg3 * 3);
                            current_total = current_total + (s2 * 2);

                            if (current_total == target_score) {
                                printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", 
                                       td8, td7, td6, fg3, s2);
                            }
                        }
                    }
                }
            }
        }
        printf("\n"); 
    }

    return 0;
}