
#include "P_Score.h"
#include "numberslittle.h"
#include <stdio.h>
#include <fat.h>

void writeMaxScore(unsigned int time)
{
	int final_time = time;
	//Open the file in write mode to overwrite
	FILE* file = fopen("/testing.txt","w+");
	if(file != NULL)
	{
		//Print the value in the file
		fprintf(file,"%i\n", final_time);
		//Close the file
		fclose(file);
	}
}


/*
int score = 0;
void displayScore()
{
	int j,i, number;
	//i, digit to display
	for(i = 5; i>0; i--)
	{
		//calculate the power of i-1 in j
		j = i-1; number = 1;
		while(j--)number = number*10;
		//Obtain the number to render
		number = score / number;
		number = number % 10;
		//Render the number
		BG_MAP_RAM_SUB(24)[1+(23-i)*32] = numberslittleMap[(10 - number)*2] | TILE_PALETTE(9);
		BG_MAP_RAM_SUB(24)[1+(23-i)*32+1] = numberslittleMap[(10 - number)*2+1] | TILE_PALETTE(9);
	}
}
*/
