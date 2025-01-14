#include "stdio.h"

int partation (int arr[],int low , int high){
   int pivot = arr[high];
   int i = low - 1 ;

   for (int j = low; j  < high; j++){
      if(arr[j] < pivot){
         i++;
         int temp = arr[i];
         arr[i] = arr[j];
         arr[j] = temp;
      }
   }
   i++;
   int temp = arr[i];
   arr[i] = arr[high];
   arr[high] = temp;
   return i;
}

void quick_sort(int arr[],int low,int high){

   if(low < high){
      int pivotindx = partation(arr,low,high);

      quick_sort(arr,low,pivotindx-1);
      quick_sort(arr,pivotindx+1,high);
   }
    
}

void main(){
   int arr[10] = {21,102,43,94,55,76,76,8,29,10};
   int size = sizeof(arr)/sizeof(arr[0]);
   quick_sort(arr,0,size-1);

   for (int i = 0 ; i< size ; i++){
    printf("%d ",arr[i]);
   }

}