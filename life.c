#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#define sizex 22 // config
#define sizey 10
#define seed 25
#define dead '.'
#define alive 'o'
#define randomly true
#define colored true
#define get_by(x, y) table[y][x] //functions and fields
#define is_alive(x, y) (table[y][x] == alive)
#define set_alive(x, y) table[y][x] = alive
#define set_dead(x, y) table[y][x] = dead
char table[sizey][sizex];
void print_table(int X,int Y){
	for(int y=0;y<sizey;y++) {
		for(int x=0;x<sizex;x++) {
			if (x != X && y != Y && colored) {
				if (is_alive(x,y)){
					printf("\e[31m%c \e[0m", get_by(x,y));
				} else {
					printf("\e[34m%c \e[0m", get_by(x,y));
				}
			} else {
				printf("%c ", get_by(x,y));
			}
		}
		printf("\n");
	}
}
int alive_nb(int x, int y) {
	int nbs[8][2]={{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1},{-1,0}};
	int	res = 0, nbx, nby;
	for (int k=0;k<8;k++) {
		nbx = x + nbs[k][0]; nby = y + nbs[k][1];
		if(nbx >= 0 && nbx < sizex &&
		   nby >= 0 && nby < sizey &&
			is_alive(nbx,nby)) {
			res++;
		}
	}
	return res;
}
int main() {
	for(int y=0;y<sizey;y++) {
		for(int x=0;x<sizex;x++) {
			if (randomly&&rand()%100+1<=seed) {
				set_alive(x,y);
			} else {
				set_dead(x, y);
			}
		}
	}
	if (!randomly) {}
	while (true) {
		for(int y=0;y<sizey;y++) {
			for(int x=0;x<sizex;x++) {
				printf("(%d,%d); AN:%d\n",x,y,alive_nb(x,y));
				if (alive_nb(x,y) == 3) {
					set_alive(x, y);
				} else if (alive_nb(x,y) != 2 &&
							alive_nb(x,y) !=3 &&
							is_alive(x,y)) {
					set_dead(x, y);
				}
				print_table(x,y);
				usleep(800);
				printf("\e[1;1H\e[2J");
			}
		}
	}
}
