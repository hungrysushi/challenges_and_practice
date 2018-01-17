/*
 * Title: Graphical Editor
 * UVa id: 10267
 * Accepted
 */

#include <stdio.h>
#include <stdlib.h>

void process_input(char cmd);
void create_table();
void clear_table();
void color_pixel();
void color_vertical();
void color_horizontal();
void color_rectangle();
void color_fill();
void write_picture();
void swap(int* a, int* b);
void fill_neighbors(int x, int y, char color, char orig_color);

char* grid = NULL;  /* keeps things a bit simpler than 2d */
int m;  /* width */
int n;  /* height */

int main()
{
        char cmd;
        while (scanf("%c", &cmd) != EOF) {
                /* terminate session */
                if (cmd == 'X') {
                        break;
                }

                process_input(cmd);
        }

        if (grid != NULL) {
                free(grid);
        }

        return 0;
}

void process_input(char cmd) {
        switch(cmd) {
                case 'I':
                        create_table();
                        break;
                case 'C':
                        clear_table();
                        break;
                case 'L':
                        color_pixel();
                        break;
                case 'V':
                        color_vertical();
                        break;
                case 'H':
                        color_horizontal();
                        break;
                case 'K':
                        color_rectangle();
                        break;
                case 'F':
                        color_fill();
                        break;
                case 'S':
                        write_picture();
                        break;
                default:
                        break;
        }
}

void create_table() {
        scanf(" %d %d", &m, &n);
        /* scanf(" %c", &n); */

        if (grid != NULL) {
                free(grid);
        }

        grid = (char*) malloc(m * n * sizeof(char*));
        clear_table();
}

void clear_table() {
        int i;
        for (i = 0; i < (m * n); i++) {
                grid[i] = 'O'; 
        }
}

void color_pixel() {
        int x, y;
        char color;
        scanf(" %d %d %c", &x, &y, &color);

        /* y * row size + x */
        grid[(y - 1) * m + (x - 1)] = color;
}

void color_vertical() {
        int x, y1, y2;
        char color;
        scanf(" %d %d %d %c", &x, &y1, &y2, &color);

        if (y1 > y2) {
                swap(&y1, &y2);
        }
        
        for(y1 = y1 - 1; y1 < y2; y1++) {
                grid[y1 * m + (x - 1)] = color;
        }
}

void color_horizontal() {
        int x1, x2, y;
        char color;
        scanf(" %d %d %d %c", &x1, &x2, &y, &color);

        if (x1 > x2) {
                swap(&x1, &x2);
        }

        for (x1 = x1 - 1; x1 < x2; x1++) {
                grid[(y - 1) * m + x1] = color;
        }
}

void color_rectangle() {
        int x1, x2, y1, y2;
        char color;
        scanf(" %d %d %d %d %c", &x1, &y1, &x2, &y2, &color);

        if (y1 > y2) {
                swap(&y1, &y2);
        }
        if (x1 > x2) {
                swap(&x1, &x2);
        }

        int i, j;
        for (i = y1 - 1; i < y2; i++) {
                for (j = x1 - 1; j < x2; j++) {
                        grid[i * m + j] = color;
                }
        }
}

void color_fill() {
        int x, y;
        char color;
        scanf(" %d %d %c", &x, &y, &color);

        char orig_color = grid[(y - 1) * m + (x - 1)];

        if (orig_color != color) {
                fill_neighbors((x - 1), (y - 1), color, orig_color);
        }
}

void write_picture() {
        int i, j;
        char filename[13];  /* MSDOS 8.3 format, 12 chars + null */
        scanf(" %s", filename);

        printf("%s\n", filename);
        for (i = 0; i < n; i++) {
                for (j = 0; j < m; j++) {
                        printf("%c", grid[i * m + j]);
                }
                printf("\n");
        }
}

void swap(int* a, int* b) {
        int temp = *a;
        *a = *b;
        *b = temp;
}

void fill_neighbors(int x, int y, char color, char orig_color) {

        grid[y * m + x] = color;

                /* check the four neighbors */
                if (x < (m - 1)) {
                        if (grid[y * m + x + 1] == orig_color) {  /* right side */
                                fill_neighbors(x + 1, y, color, orig_color);
                        }
                }
                if (x > 0) { 
                        if (grid[y * m + x - 1] == orig_color) {  /* left side */
                                fill_neighbors(x - 1, y, color, orig_color);
                        }
                }
                if (y < (n - 1)) {
                        if (grid[(y + 1) * m + x] == orig_color) {  /* below */
                                fill_neighbors(x, y + 1, color, orig_color);
                        }
                }
                if (y > 0) {
                        if (grid[(y - 1) * m + x] == orig_color) {  /* above */
                                fill_neighbors(x, y - 1, color, orig_color);
                        }
                }
}
