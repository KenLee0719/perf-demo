#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SWAP(x,y) {int t; t = x; x = y; y = t;}
void bubble_sort(int array[], int n) {
    for (int i=0; i<n-1; i++) {
        for (int j=0; j<n-i-1; j++) {
            if (array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}
void quickSort(int number[], int left, int right) { 
    if(left < right) { 
        int s = number[(left+right)/2]; 
        int i = left - 1; 
        int j = right + 1; 

        while(1) { 
            while(number[++i] < s) ;  // 向右找 
            while(number[--j] > s) ;  // 向左找 
            if(i >= j) 
                break; 
            SWAP(number[i], number[j]); 
        } 

        quickSort(number, left, i-1);   // 對左邊進行遞迴 
        quickSort(number, j+1, right);  // 對右邊進行遞迴 
    } 
}
int main(){
	srand( time(NULL) );
	int data_size = 30000;
	int data[data_size];
	/* 指定亂數範圍 */
	int min = 1;
	int max = 256;

	/* 產生 [min , max] 的整數亂數 */
	for (int i=0; i<data_size; i++)
	{
		data[i] = rand() % (max - min + 1) + min;
	}
	bubble_sort(data, data_size);
	
	int sum = 0;
	for (int i = 0; i < data_size; i++)
	{
		for (int x = 0; x < data_size; x++)
		{
			if (data[i] >= 128) { // 故意選 256 一半  
				sum += data[i];
			}
		}
	}
	printf("Sum = %d \n",sum);
	return 0;
}
