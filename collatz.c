#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//  Collatz conjecture
int collatz_steps(int n) {
    int steps = 0;
    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;  // If even, divide by 2
        } else {
            n = 3 * n + 1;  // If odd, multiply by 3 and add 1
        }
        steps++;  
    }
    return steps;
}

int main(int argc, char *argv[]) {
  
    if (argc != 4) {
        printf("Usage: %s <N> <MIN> <MAX>\n", argv[0]);
        return 1;
    }

    // Parse the command-line arguments
    int N = atoi(argv[1]);   // Number of values to test
    int MIN = atoi(argv[2]); // Smallest value to test
    int MAX = atoi(argv[3]); // Largest value to test

 
    if (MIN > MAX) {
        printf("Error: MIN should be less than or equal to MAX.\n");
        return 1;
    }

    
    srand(time(NULL));

    // Loop to generate and test N random numbers between MIN and MAX
    for (int i = 0; i < N; i++) {
        int num = rand() % (MAX - MIN + 1) + MIN;  
        int steps = collatz_steps(num);            
        printf("Number: %d, Steps: %d\n", num, steps);
    }

    return 0;
}

