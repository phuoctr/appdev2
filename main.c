//This is main.c
#include<stdio.h>
#include "screen.h" //for defining header, doubel quotes
#include<stdlib.h>
#include<signal.h>
#include<time.h>
#include "sound.h"
int main()
{
	FILE *f;
	short sd[RATE]; // For all samples in 1s
	while(1){
		int ret = system(CMD);
		if(ret == SIGINT) break;
		f=fopen("test.wav","r");
		clearScreen();
		setColors(YELLOW, bg(BLUE));
		if( f == NULL){
			printf("Cannot open the wav file");
			return 1;
		}
		struct WAVHDR h; // instance of wav header
		fread(&h, sizeof(h), 1, f); //read wav file header to f
		displayWAVHDR(h); // show wav header info
		fread(&sd, sizeof(sd), 1, f);
		displayWAVDATA(sd);
		fclose(f); //close the opened file
	}
	resetColors();
	getchar();
}
