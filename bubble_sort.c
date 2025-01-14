#include "stdio.h"

void bubble_sort(int arr[], int size){
    
    for (int i = 0; i < size; i++){
        for (int j = 0; j<size-i-1;j++){
            //check for greater number
            if(arr[j] > arr[j+1]){
                //swap 
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

}

void main ()
{
    int arr[8] = {51,32,64,15,96,7,8};
    int size = sizeof(arr)/sizeof(arr[0]);
    bubble_sort(arr,size);
    for (int i = 0; i<size; i++){
        printf("%d ",arr[i]);
    }
}