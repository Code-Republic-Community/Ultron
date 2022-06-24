#include  <iostream>

void heapify(int arr_heap[], int number , int i){
    
    int biggest = i;
    int left  = 2*i+1;
    int right = 2*i+2;
	
    if( left < number && arr_heap[left] > arr_heap[biggest]){
        biggest = left;
    }
    if(right < number && arr_heap[right] > arr_heap[biggest]){
        biggest = right;
    }
    if(biggest != i ){
        std::swap(arr_heap[i] , arr_heap[biggest]);
        heapify(arr_heap,number ,biggest);
    }   
}

void print_heap_sort(int arr_heap[], int  number){
    for(int i = 0; i < number; i++){
        std::cout << arr_heap[i] <<  " ";
    }
}
void  heap_sort(int arr_heap[],int number){
    for(int i = number/2-1; i >= 0 ; --i){
        heapify(arr_heap ,  number , i );  
    }
    for(int i = number-1; i >= 0; --i){
        std::swap(arr_heap[i] ,arr_heap[0]);  
        heapify(arr_heap, i , 0);
    }
}

int main(){
    
    int arr_heap[] = {1,8,2,5,2,14,8,299,211,892,41,5,3,852,52};
    int number  =  sizeof(arr_heap) /sizeof(arr_heap[0]);
    heap_sort(arr_heap, number);
    std::cout << "Heap sort element is  " ; 
    print_heap_sort(arr_heap,number);
}
