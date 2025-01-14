#include "stdio.h"


void selection_sort(int arr[],int size){

    for (int i = 0; i < size ; i++){
        int smallest_index = i;
        for (int j = i+1; j < size ; j++){
            if(arr[j]<arr[smallest_index]){
                smallest_index = j;
            }
        }
        //swap 
        if(smallest_index != i){
            int temp = arr[smallest_index];
            arr[smallest_index] = arr[i];
            arr[i] = temp;
        }
        

    }

}



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
    int arr2[8] = {51,32,64,15,96,7,8};
    int size = sizeof(arr)/sizeof(arr[0]);
    bubble_sort(arr,size);
    printf("\n Bubble sort   : ");
    for (int i = 0; i<size; i++){
        printf("%d ",arr[i]);
    }
     selection_sort(arr2,size);
     printf("\nSelection sort : ");
     for (int i = 0; i<size; i++){
        printf("%d ",arr2[i]);
    }
}