/*
 * The Trip
 * UVa id: 10137
 * Accepted
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
        int num_students;
        while (scanf("%d", &num_students) != EOF) {
                /* exit condition */
                if (num_students == 0) {
                        break;
                }

                double *costs;
                costs = (double *) malloc(num_students * sizeof(double));

                int i;
                double total_spent = 0.0;
                for (i = 0; i < num_students; i++) {
                        scanf("%lf", costs + i);
                        total_spent += costs[i];
                }

                double average = (total_spent / num_students * 100) / 100;

                double amount_to_give = 0.0, amount_to_take = 0.0;

                for (i = 0; i < num_students; i++) {
                        if (costs[i] < average) {
                                amount_to_take += floor(average * 100) / 100 - costs[i];
                        } else {
                                amount_to_give += costs[i] - ceil(average * 100) / 100;
                        }
                }

                if (amount_to_take > amount_to_give) {
                        printf("$%.2lf\n", amount_to_take);
                } else {
                        printf("$%.2lf\n", amount_to_give);
                }

                free(costs);
        }

        return 0;
}
