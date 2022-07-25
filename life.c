#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#ifdef _WIN32
    #include <windows.h>
    #define sleep_ms(ms) Sleep(ms / 1000)
    #define clear_console() system("cls")
#else
    #include <unistd.h>
    #define sleep_ms(ms) usleep(ms)
    #define clear_console() printf("\e[1;1H\e[2J")
#endif
// config
#define size 400
#define seed 21
#define dead '.'
#define alive 'O'
#define randomly false
// functions and fields
#define time_delay (size + 300)
#define get_by(x, y) table[y][x]
#define set_alive(x, y) table[y][x] = alive
#define set_dead(x, y) table[y][x] = dead
#define is_alive(x, y) (table[y][x] == alive)
// main table
char table[size][size];
// prints the table
void print_table() {
    for (int y = 0; y < sqrt(size); y++) {
        for (int x = 0; x < sqrt(size); x++) {
        	printf("%c ", get_by(x, y));
        }
        printf("\n");
    }
}
// counts alive neighbours
int alive_neighbours(int x, int y) {
    int res = 0;
    if (x - 1 >= 0 && y - 1 >= 0 && is_alive(x - 1, y - 1)) res++;
    if (y - 1 >= 0 && is_alive(x, y - 1)) res++;
    if (x + 1 < (int)sqrt(size) && y - 1 >= 0 && is_alive(x + 1, y - 1)) res++;
    if (x + 1 < (int)sqrt(size) && is_alive(x + 1, y)) res++;
    if (x + 1 < (int)sqrt(size) && y + 1 < (int)sqrt(size) && is_alive(x + 1, y + 1)) res++;
    if (y + 1 < (int)sqrt(size) && is_alive(x, y + 1)) res++;
    if (x - 1 >= 0 && y + 1 < (int)sqrt(size) && is_alive(x - 1, y + 1)) res++;
    if (x - 1 >= 0 && is_alive(x - 1, y)) res++;
    return res;
}
// main function
int main() {
    for (int y = 0; y < sqrt(size); y++) {
        for (int x = 0; x < sqrt(size); x++) {
            if (randomly && rand() % 100 + 1 <= seed) {
                set_alive(x, y);
            } else {
                set_dead(x, y);
            }
        }
    }
    if (!randomly) {
    	// custom generation
    	set_alive(10, 10);
    	set_alive(10, 11);
    	set_alive(10, 12);
    }
    while (true) {
        for (int y = 0; y < sqrt(size); y++) {
            for (int x = 0; x < sqrt(size); x++) {
                if (alive_neighbours(x, y) == 3) {
                    set_alive(x, y);
                } else if (alive_neighbours(x, y)!=3 && alive_neighbours(x, y)!=2 && is_alive(x, y)) {
                    set_dead(x, y);
                }
                print_table();
                sleep_ms(time_delay);
                clear_console();
            }
        }
    }
    return 0;
}
