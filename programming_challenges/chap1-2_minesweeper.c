/*
 * minesweeper
 * uva id: 10189
 * Accepted
 */

#include <stdio.h>
#include <stdlib.h>

void print_grid(char* grid, int row, int col);
void update_neighbors(char* grid, int loc, int row_size, int col_size);
void increment_point(char* grid, int index);

int main()
{
        int row, col, i;
        int num_fields = 1;
        while(scanf("%d %d", &row, &col) != EOF) {
                /* exit condition */
                if (row == 0 || col == 0) {
                        return 0;
                }

                /* create and clear a grid by setting it to '0' */
                char *grid;
                grid = (char *) malloc(row * col * sizeof(char));
                for (i = 0; i < (row * col); i++) {
                        grid[i] = '0';
                }

                int count = 0;
                while (count < row * col) {
                        char c;
                        scanf("%c", &c);
                        if (c == '*') {
                                grid[count] = c;
                                update_neighbors(grid, count, row, col);

                                count++;
                        }
                        if (c == '.') {
                                count++;
                        }
                }

                /* sloppy way to handle this, but this is purely to get the
                 * presentation right. It doesn't like the trailing newline */
                if (num_fields > 1) {
                        printf("\n");
                }
                printf("Field #%d:\n", num_fields++);
                print_grid(grid, row, col);

                /* deallocate grid */
                free(grid);
        }
}

void print_grid(char* grid, int row, int col) {
        int i, j;
        for (i = 0; i < row; i++) {
                for (j = 0; j < col; j++) {
                        printf("%c", grid[col * i + j]);
                }
                printf("\n");
        }
}

void update_neighbors(char* grid, int loc, int num_rows, int num_cols) {
        int row = loc / num_cols;
        int col = loc % num_cols;

        int top = row > 0;
        int bottom = row < (num_rows - 1);
        int left = col > 0;
        int right = col < (num_cols - 1);

        if (top) {
                increment_point(grid, loc - num_cols);
        }
        if (bottom) {
                increment_point(grid, loc + num_cols);
        }
        if (left) { 
                increment_point(grid, loc - 1);
        }
        if (right) { 
                increment_point(grid, loc + 1);
        }

        if (top && right) { 
                increment_point(grid, loc - num_cols + 1);
        }
        if (bottom && right) {
                increment_point(grid, loc + num_cols + 1);
        }
        if (bottom && left) {
                increment_point(grid, loc + num_cols - 1);
        }
        if (top && left) {
                increment_point(grid, loc - num_cols - 1);
        }
}

void increment_point(char* grid, int index) {
        if (grid[index] != '*') {
                grid[index]++;
        }
}
