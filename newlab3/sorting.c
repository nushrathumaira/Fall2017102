#include "sorting.h"



void bubble_sort(int* numbers, int size)
{
	int number_swaps = -1;
	while(number_swaps != 0)
	{
		number_swaps =0;
		for(int i =0 ; i < size -1  ; i++)
		{
			if(numbers[i] > numbers[i+1])
			
			
			{
				swap(&numbers[i],&numbers[i+1]);
				number_swaps++;
			}
		}		
	}



}
void comb_sort(int* numbers, int size)
{

	int gap = size;
	double shrink_factor = 1.3;
	int number_swaps = 0;
	
	do{
		number_swaps = 0;
		gap = gap/shrink_factor;
		gap = (gap == 0) ? 1 : gap;
		int i;
		for(i = 0; i+gap < size-1; i++)
		{
			if(numbers[i] > numbers[i+gap])
			{
				swap(&numbers[i], &numbers[i+gap]);
				number_swaps++;
			}
		}
	}while(number_swaps != 0 && gap > 1);

}
void swap(int* a, int*b)
{
	int t = *a;
	*a = *b;
	*b = t;

}
