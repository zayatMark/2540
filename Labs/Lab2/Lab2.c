#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SEQUENCE_SIZE 15
#define NUM_SEQUENCES 10

typedef struct {
    int start;
    int end;
    int sum;
} MaxSegment;

void generateSequence(int* sequence) {
    for (int i = 0; i < SEQUENCE_SIZE; i++) {
        sequence[i] = rand() % 201 - 100;
    }
}

MaxSegment findMaxSegment(int* sequence, int sequenceSize) {
    MaxSegment maxSeg;

    // Initialize the maximum segment with the first element of the sequence
    maxSeg.start = 0;
    maxSeg.end = 0;
    maxSeg.sum = sequence[0];

    // Variables to track the current segment
    int currentStartIndex = 0;
    int currentSum = sequence[0];

    // Iterate over the sequence to find the maximum segment
    for (int i = 1; i < sequenceSize; i++) {
        // If adding the current element increases the sum, continue the current segment
        if (currentSum + sequence[i] > sequence[i]) {
            currentSum += sequence[i];
        } else {
            // Otherwise, start a new segment from the current element
            currentSum = sequence[i];
            currentStartIndex = i;
        }

        // If the current sum is greater than the maximum sum, update the maximum segment
        if (currentSum > maxSeg.sum) {
            maxSeg.start = currentStartIndex;
            maxSeg.end = i;
            maxSeg.sum = currentSum;
        }
    }

    return maxSeg;
}

void printMaxSegment(MaxSegment maxSeg) {
    printf("Maximum segment sum: %d\n", maxSeg.sum);
    printf("Start index: %d\n", maxSeg.start);
    printf("End index: %d\n", maxSeg.end);
    printf("\n");
    printf("\n");
}

int main() {
    int sequence[SEQUENCE_SIZE];

    srand(time(NULL));

    for (int i = 1; i <= NUM_SEQUENCES; i++) {
        // Generate a random sequence
        generateSequence(sequence);

        // Find the maximum segment in the sequence
        MaxSegment maxSeg = findMaxSegment(sequence, SEQUENCE_SIZE);

        printf("Sequence %d:\n\n", i);
        printf("Index   Number\n");
        printf("----------------\n");

        // Print the sequence
        for (int j = 0; j < SEQUENCE_SIZE; j++) {
            printf("%-6d  %-6d\n", j, sequence[j]);
        }

        printf("\n");

        // Print the details of the maximum segment
        printMaxSegment(maxSeg);
    }

    return 0;
}
