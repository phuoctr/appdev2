//This is main.c
#include<stdio.h>
#include "screen.h" //for defining header, doubel quotes
#include<stdlib.h>
#include<time.h>
int main()
{
	int arr[80]; //for making a barchart
	srand(time(NULL));
	for(int i=0;i<80;i++){
		arr[i] = rand()%70 + 30;
	}
	clearScreen();
	setColors(YELLOW, bg(BLUE));
//	printf("Printed from main.\n");
	barChart(arr);
	resetColors();
	printf("Another message\n");
	getchar();
}
