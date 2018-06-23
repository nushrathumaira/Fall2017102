#include <stdio.h>
#include <string.h>
#include "sorting.h"


int main(int argc, char const *argv[])
{
	FILE* inputFile = fopen(argv[1],"r");
	int data_count_total = 0;
	int num;
	while(fscanf(inputFile, "%d ", &num) == 1)
	{
		data_count_total++;
	}
	// reset file to the beginning of file, second parameter is 0 for text
	//files , for binary file the number for offset
	fseek(inputFile,0, SEEK_SET);
	
        //array to hold the data
	int numbers[data_count_total];
	int i ;	
	for(i=0; i < data_count_total; i ++)
	{	
		fscanf(inputFile, "%d ", &numbers[i]);
		
	}

	if(strcmp(argv[2], "bubble") == 0)
	{
		printf("Bubble Sorting\n");
		bubble_sort(numbers,data_count_total);

	}
	else if(strcmp(argv[2],"comb") == 0)
	{
		printf("Comb Sorting\n");
		comb_sort(numbers,data_count_total);
	}
	else
	{
		printf("No valid sorting function\n");
	}



	// create file name for output using sprintf
	char sname[50];
	sprintf(sname, "%s_%d.dat", argv[2], data_count_total);
	FILE* outputFile = fopen(sname,"w");
	
	for(i =0; i < data_count_total; i++)
	{
		fprintf(outputFile, "%d\n", numbers[i]);
	}
	return 0;


}
