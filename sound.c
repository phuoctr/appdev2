#include <stdio.h>
#include <math.h>
#include "sound.h"
#include "screen.h"
//This function takes 1s of samples (16000 in our case) 
// and  calculate 80 pieces of RMS value, then 
// turn these values into decibels, and display them as a bar chart
void displayWAVDATA(short s[]){
	double rms[80]; //We have 16000 samples.
			// Therefore every 200 sample makes one RMS
	int db[80];	//decibel value
	int i, j;	// nested loop counters
	short *ptr = s; //use pointrt to point the beginning of the array
	for(i=0; i<80; i++){ //outer loop repeat 80 times
		double sum=0; // intitalize tje sum
		for(j=0; j<200; j++){
			sum += (*ptr)*(*ptr); // accumlate the sum
			ptr++;	//Pointer increment
		}
		rms[i] = sqrt(sum/200);
		db[i] = 20*log10(rms[i]); //decibel value
#ifdef DEBUG
		printf("RMS[%d] = %f\n", i, rms[i]);
#endif
	}
#ifndef DEBUG
	barChart(db);
#endif	
}


void showID(char *name, char *value){
	printf("%s: ",name);
	for(int i=0;i<4;i++)
		printf("c", value[i]);
	puts(""); 	
}
// Function defination 
void displayWAVHDR(struct WAVHDR h){
#ifdef DEBUG
	showID("Chunk ID", h.ChunkID);
	printf("Chunk size: %d\n", h.ChunkSize);
	showID("Format", h.Format);
	showID("Subchunk ID", h.Subchunk1ID);
	printf("Subchunk1 size: %d\n", h.Subchunk1Size);
	printf("Audio format: %d\n", h.AudioFormat);
	printf("Num of channels: %d",h.SampleRate);
	printf("Byte Rate: %d\n",h.ByteRate);
	printf("Block align: %d\n",h.BlockAlign);
	printf("Bits per second: %d\n",h.BitsSample);
	printf("Subchunk 2 ID: %d\n",h.Subchunk2ID);
	printf("Subchunk 2 size: %d\n", h.Subchunk2Size);
#else
	setColors(RED, bg(BLUE));
	printf("\033[1;1H");
	printf("test.wav		\n");
	setColors(YELLOW, bg(GREEN));
	printf("\033[1;21H");
	printf("Sample rate = %d	\n",h.SampleRate);
	setColors(WHITE, bg(MAGENTA));
	printf("\033[1;61H");
	printf("Duration = %.2f		\n", (float)h.Subchunk2Size/h.ByteRate);


#endif
	// to be continued for other fields
}

