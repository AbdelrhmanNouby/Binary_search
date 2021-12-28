/*************************************
 * Task	  : Binary_search
 * Created: 12/27/2021 11:35:52 PM
 * Author : Abdelrhman Elsawy
 *************************************/

#ifndef __APIS_H__
#define __APIS_H__

uint8_t binarySearch(uint32_t * arr , uint8_t size , uint32_t number); 
void swap(uint32_t *first_ptr, uint32_t *second_ptr);
void selectionSort(uint32_t * arr, uint8_t size);
void printArray(uint32_t * arr , uint8_t size);
uint8_t arrNotSorted(uint32_t* arr, uint8_t size);

#endif /*APIs.h*/
