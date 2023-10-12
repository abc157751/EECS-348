#include <stdio.h>

// Recursive function to find and print all possible combinations of scoring plays
void findCombinations(int score, int td, int fg, int safety, int td_2pt, int td_fg) {
    if(score == 0) {
        printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td_2pt, td_fg, td, fg, safety);
        return;
    }
    
    if(score < 0) {
        return;
    }
    
    findCombinations(score-8, td, fg, safety, td_2pt+1, td_fg);
    findCombinations(score-7, td, fg, safety, td_2pt, td_fg+1);
    findCombinations(score-6, td+1, fg, safety, td_2pt, td_fg);
    findCombinations(score-3, td, fg+1, safety, td_2pt, td_fg);
    findCombinations(score-2, td, fg, safety+1, td_2pt, td_fg);
}

int main() {
    int score;
    
    printf("Enter 0 or 1 to STOP\n");
    
    // Infinite loop to keep prompting the user for input until a termination condition is met
    while(1) {
        printf("Enter the NFL score: ");
        scanf("%d", &score);
        
        // Check for termination condition
        if(score <= 1) {
            printf("Program terminated.\n");
            break;
        }
        
        // Display possible combinations and find them using the recursive function
        printf("Possible combinations of scoring plays:\n");
        findCombinations(score, 0, 0, 0, 0, 0);
    }
    
    return 0;
}
