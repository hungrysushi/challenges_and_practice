/*
 * Title: LC-Display
 * UVa id: 706
 * Accepted
 */

#include <stdlib.h>
#include <stdio.h>

/* ordered clockwise from the top and middle last */
int SEGMENT_MAP[10][7] = {
        {1, 1, 1, 1, 1, 1, 0},  /* zero */
        {0, 1, 1, 0, 0, 0, 0},  /* one */
        {1, 1, 0, 1, 1, 0, 1},  /* two */
        {1, 1, 1, 1, 0, 0, 1},  /* three */
        {0, 1, 1, 0, 0, 1, 1},  /* four */
        {1, 0, 1, 1, 0, 1, 1},  /* five */
        {1, 0, 1, 1, 1, 1, 1},  /* six */
        {1, 1, 1, 0, 0, 0, 0},  /* seven */
        {1, 1, 1, 1, 1, 1, 1},  /* eight */
        {1, 1, 1, 1, 0, 1, 1},  /* nine */
};

void print_digits(int *digits, int num_digits, int size);
void print_segment_line(int line_num, int *digits, int num_digits, int size);

int main()
{
        int size, i;
        int* digits;
        char* digit_chars;
        while (scanf("%d", &size) != EOF) {
                /* exit */
                if (!size) {
                        return 0;
                }

                digit_chars = (char *) malloc(8 * sizeof(char));  /* from program specs, we'll have at most 8 digits */

                /* read in the numbers as chars first */
                scanf("%s", digit_chars);

                /* get number of actual digits */
                int num_digits = 0;
                for (i = 0; i < 8; i++) {
                        if (digit_chars[i] >= '0' && digit_chars[i] <= '9') {
                                num_digits++;
                        } else {
                                break;  /* reached end of sequence */
                        }
                }

                /* make array of ints from the chars */
                digits = (int *) malloc(num_digits * sizeof(int));
                for (i = 0; i < num_digits; i++) {
                        digits[i] = digit_chars[i] - '0';
                }

                print_digits(digits, num_digits, size);

                free(digit_chars);
                free(digits);
        }

        return 0;
}

void print_digits(int *digits, int num_digits, int size) {
        int i;
        /* for (i = 0; i < num_digits; i++) { */
                print_segment_line(1, digits, num_digits, size);
                print_segment_line(2, digits, num_digits, size);
                print_segment_line(3, digits, num_digits, size);
                print_segment_line(4, digits, num_digits, size);
                print_segment_line(5, digits, num_digits, size);
        /* } */
        printf("\n");
}

void print_segment_line(int line_num, int *digits, int num_digits, int size) {

        int i, j, k;
        switch (line_num) {
                case 1:
                        for (i = 0; i < num_digits; i++) {
                                printf(" ");  /* left corner */
                                for (j = 0; j < size; j++) {
                                        if (SEGMENT_MAP[digits[i]][0]) {
                                                printf("%c", '-');
                                        } else {
                                                printf("%c", ' ');
                                        }
                                }
                                printf(" ");  /* right corner */

                                if (i < (num_digits - 1)) {
                                        printf(" ");  /* one column spacing b/w digits */
                                }
                        }
                        printf("\n");
                        break;
                case 2:
                        for (i = 0; i < size; i++) {
                                for (j = 0; j < num_digits; j++) {
                                        if (SEGMENT_MAP[digits[j]][5]) {
                                                printf("%c", '|');
                                        } else {
                                                printf("%c", ' ');
                                        }

                                        for (k = 0; k < size; k++) {
                                                printf("%c", ' ');
                                        }

                                        if (SEGMENT_MAP[digits[j]][1]) {
                                                printf("%c", '|');
                                        } else {
                                                printf("%c", ' ');
                                        }

                                        if (j < (num_digits - 1)) {
                                                printf(" ");  /* one column spacing b/w digits */
                                        }
                                }
                                printf("%c", '\n');
                        }
                        break;
                case 3:
                        for (i = 0; i < num_digits; i++) {
                                printf(" ");  /* left corner */
                                for (j = 0; j < size; j++) {
                                        if (SEGMENT_MAP[digits[i]][6]) {
                                                printf("%c", '-');
                                        } else {
                                                printf("%c", ' ');
                                        }
                                }
                                printf(" ");  /* right corner */

                                if (i < (num_digits - 1)) {
                                        printf(" ");  /* one column spacing b/w digits */
                                }
                        }
                        printf("\n");

                        break;
                case 4:
                        for (i = 0; i < size; i++) {
                                for (j = 0; j < num_digits; j++) {
                                        if (SEGMENT_MAP[digits[j]][4]) {
                                                printf("%c", '|');
                                        } else {
                                                printf("%c", ' ');
                                        }

                                        for (k = 0; k < size; k++) {
                                                printf("%c", ' ');
                                        }

                                        if (SEGMENT_MAP[digits[j]][2]) {
                                                printf("%c", '|');
                                        } else {
                                                printf("%c", ' ');
                                        }

                                        if (j < (num_digits - 1)) {
                                                printf(" ");  /* one column spacing b/w digits */
                                        }
                                }
                                printf("%c", '\n');
                        }
                        break;
                case 5:
                        for (i = 0; i < num_digits; i++) {
                                printf(" ");  /* left corner */
                                for (j = 0; j < size; j++) {
                                        if (SEGMENT_MAP[digits[i]][3]) {
                                                printf("%c", '-');
                                        } else {
                                                printf("%c", ' ');
                                        }
                                }
                                printf(" ");  /* right corner */

                                if (i < (num_digits - 1)) {
                                        printf(" ");  /* one column spacing b/w digits */
                                }
                        }
                        printf("\n");
                        break;
        }
}
