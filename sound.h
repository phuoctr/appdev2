//  Constants definition
#define RATE 16000 // samples per second
// data structures
struct WAVHDR{
	char ChunkID[4]; // it is "RIFF"
	int ChunkSize; //4 bytes num
	char Format[4]; // it is "WAVE"

	char Subchunk1ID[4]; //"fmt"
	int Subchunk1Size; //PCM = 16
	short AudioFormat; // shoud be "1"
	short NumChanels; // Should be 1
	int SampleRate; //16000
	int ByteRate; //16000*NumChannels*BitsPerSample/8
	short BlockAllign; //NumChannels*BitsPerSample
	short BitsSample; // in our app, 16 (-f S16_LE)

	char Subchunk2ID[4]; //"data"
	int Subchunk2size; //

};
// function declarations
