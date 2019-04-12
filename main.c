//This is main.c
#include<stdio.h>
#include "screen.h" //for defining header, doubel quotes
#include<stdlib.h>
#include<signal.h>
#include<time.h>
#include "sound.h"
#include "comm.h"

int main(int argc, char **argv)
{
	if(argc == 2){
		int ch;
		printf("How many channels (1:mono, 2:stereo)");
		scanf("%d", &ch);
		float duration;
		printf("How long is the test tone?(1-10s):");
		scanf("%f", &duration);
		testTone(ch, atoi(argv[1]), duration);
		return 0;
	}
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
		sendDATA(sd);
	}
	resetColors();
	getchar();
}
