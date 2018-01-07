/*
 *	Implementation of score in project (secondary storage on file)
 */

#include "P_Score.h"
#include "numberslittle.h"
#include <stdio.h>
#include <fat.h>

void writeMaxScore(unsigned int time)
{
	int final_time = time;
	//Open the file in write mode to overwrite
	FILE* file = fopen("/testing.txt","a+");
	if(file != NULL)
	{
		//Print the value in the file
		fprintf(file,"%i \r\n", final_time);
		//Close the file
		fclose(file);
	}
}

