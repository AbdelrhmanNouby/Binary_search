/*************************************
 * Task	  : Binary_search
 * Created: 12/27/2021 11:35:52 PM
 * Author : Abdelrhman Elsawy
 *************************************/
 
#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "APIs.h"

main()
{ 
	while(1)
	{
		uint32_t arr[255] = {} ;    // empty array to hold input
    	uint8_t u8_size ;	     	// variable to hold size of array with max 255 
    	uint32_t u32_number ;	    // variable to hold number you are searching for 
		printf("Enter the size : ");		// get the size of array
   	 	scanf("%d", &u8_size);
    	printf("Enter the values : \n");	// get values of array 
    	uint8_t u8_index ;
    	for( u8_index = 0; u8_index < u8_size ; u8_index++ )
       		scanf("%d", &arr[u8_index]);
       		
    	printf("Enter the number you are searching for : ");	// get the number you are searching for
    	scanf("%d", &u32_number);
    	uint8_t u8_result = binarySearch( arr, u8_size , u32_number );  // searching for number 
    	if ( u8_result == 255 )    // -1 >> 255 for unsigned    // number not found in array
	 		printf("Element is not present in array\n");
    	else													// numper found and print its index 
 			printf("Element is present at index %d\n",u8_result);
	}
}
