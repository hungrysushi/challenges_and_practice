/*
 * The 3n + 1 Problem
 * UVa id: 100
 * Accepted
 */

#include <stdio.h>

int max_steps(int start, int end);
int steps(int num);

int main()
{
        int a, b;
        while (scanf("%d %d", &a, &b) != EOF) {
                int max = a > b ? max_steps(b, a) : max_steps(a, b);
                printf("%d %d %d\n", a, b, max);
        }

        return 0;
}

int max_steps(int start, int end) {
        int max = 0;

        do {
                int num_steps = steps(start);
                if (num_steps > max) {
                        max = num_steps;
                }

        } while (start++ != end);

        return max;
}

int steps(int num) {
        int num_steps;
        for (num_steps = 0; num != 1; num_steps++) {
                if (num % 2) {
                        num = 3 * num + 1;
                } else {
                        num = num / 2;
                }
        }

        return ++num_steps;
}
