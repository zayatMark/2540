/*
Lab 1
Mark Zayat
104214103
2023-05-15
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct entry {
  int firstNumber;
  int secondNumber;
  int gcd;
  int count;
  int predicted;
};

int calculateGCD(int m, int n) {
  //Uses Euclid's algorithm to calculate GCD
  while (n != 0) {
    int r = m % n;
    m = n;
    n = r;
  }
  int gcd = m;
  return gcd;
}

int getCount(int m, int n) {
  //This function uses the algorithm explained in the lab to return the number of divisions needed to get the GCD
  // Step 1:
  int u0 = 1, v0 = 0;
  int u = 0, v = 1;
  int m0 = m, n0 = n;
  int count = 1;

  // Step 2:
  while (1) {
    if (m0 % n0 == 0) {
      return count;
      break;
    }

    // Step 3:
    int temp1 = u, temp2 = v;
    if (n0 != 0) {
      u = u0 - (m0 / n0) * u;
      v = v0 - (m0 / n0) * v;
    }
    u0 = temp1;
    v0 = temp2;

    // Step 4:
    int r = m0 % n0;
    m0 = n0;
    n0 = r;
    count++;
  }
}

struct entry makeEntry(int m, int n, int gcd, int count) {
  struct entry entry;
  entry.firstNumber = m;
  entry.secondNumber = n;
  entry.gcd = gcd;
  entry.count = count;
  entry.predicted = (int)ceil(log((double)(m < n ? m : n)) / log(2)) + 1;

  return entry;
}

int main() {
  srand(time(NULL));
  struct entry table[50];
  int i = 0;
  // Generates 50 random pairs of numbers and calculates GCD, count, and predicted value for each pair
  while (i < 50) {
    int m = rand() % 100 + 1;
    int n = rand() % 100 + 1;

    int gcd = calculateGCD(m, n);
    int count = getCount(m, n);

    table[i] = makeEntry(m, n, gcd, count);

    i++;
  }
  // Prints the table
  printf("%-10s %-10s %-10s %-10s %-10s\n", "m", "n", "GCD", "Count", "Predicted");
  for (int i = 0; i < 50; i++) {
  struct entry entry = table[i];
  printf("%-10d %-10d %-10d %-10d %-10d\n", entry.firstNumber, entry.secondNumber, entry.gcd, entry.count, entry.predicted);
}
  return 0;
}
