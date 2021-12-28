/*************************************
 * Task	  : Binary_search
 * Created: 12/27/2021 11:35:52 PM
 * Author : Abdelrhman Elsawy
 *************************************/
 
#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "APIs.h"

/**********************************************
function to swap 2 numbers take to pointers 
and swap values in memory positions 
***********************************************/

void swap(uint32_t *first_ptr, uint32_t *second_ptr)
{
    uint32_t u32_temp = *first_ptr;
    *first_ptr = *second_ptr;
    *second_ptr = u32_temp;
}

/*************************************************
function to sorting array by selection  sorting 
take 2 argu the adress of the first elemen and the size 
and sort array in the smae memory area 
*************************************************/

void selectionSort(uint32_t * arr, uint8_t u8_size)
{
    uint8_t u8_outer_counter , u8_inner_counter , u8_min_index;
    
    for ( u8_outer_counter = 0 ; u8_outer_counter < u8_size-1 ; u8_outer_counter++ ) 
    {
        u8_min_index = u8_outer_counter ; // select index to compare with it 
        
        // compare it with every element in the array 
        for ( u8_inner_counter = u8_outer_counter+1; u8_inner_counter < u8_size ; u8_inner_counter++)
          if (arr[u8_inner_counter ] < arr[u8_min_index])
            u8_min_index = u8_inner_counter ;
 		
		 // swap the min number to the index 
        swap(&arr[u8_min_index], &arr[u8_outer_counter]);
    }
}

/**********************************************
function to search for number in array take 3 argu 
the adress of the first elemen and the size 
and the number searching for
in the first check if array sorted or not 
if not , sort it by selection sorting 
return the index if number is found 
return -1 ( 255 ) if number is not found 
**********************************************/

uint8_t binarySearch(uint32_t * arr , uint8_t u8_size , uint32_t u32_number)
{
	uint8_t u8_end = u8_size-1 ;     // assign the end 
	uint8_t u8_start = 0 ;			 // assign the start 
    
	if (arrNotSorted(arr,u8_size))   // check if array sorted or not
    {
		selectionSort(arr,u8_size);		// sort it if not sorted
    	printf("sorted array equal\t");		// print new sorted array
    	printArray(arr,u8_size);
    }
    while ( u8_start <= u8_end ) 
	{	
		uint8_t u8_mid = u8_start + ((u8_end - u8_start) / 2); 	
        if (arr[u8_mid] == u32_number) 
            return u8_mid;
            
        if ( arr[u8_mid] < u32_number )
	     	u8_start = u8_mid + 1 ;   	
        
		else
        	u8_end = u8_mid - 1 ;
    }
    return -1;
}

/**********************************************
function to check if the array sorted or not 
the adress of the first elemen and the size
return 1 if not sorted 
return 0 if sorted 
**********************************************/

uint8_t arrNotSorted(uint32_t* arr, uint8_t u8_size)
{
	uint8_t u8_index ;
	for( u8_index = 1; u8_index < u8_size; u8_index++)
	{
  		 if(arr[u8_index] < arr[u8_index - 1])
       	 	return 1;
	}
    return 0;
}

/******************************************** 
function to print an array take 2 argu 
the adress of the first elemen and the size
********************************************/
void printArray(uint32_t * arr , uint8_t u8_size) 
{
    uint8_t u8_index;
    for ( u8_index = 0 ; u8_index < u8_size ; u8_index++ )
        printf("%d ", arr[u8_index]);
    printf("\n");
}
