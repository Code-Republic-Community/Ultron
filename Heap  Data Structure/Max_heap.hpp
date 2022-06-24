template <typename T>
MaxHeap<T>::MaxHeap()=default;


template <typename T>
MaxHeap<T>::MaxHeap(const MaxHeap& heap1){
  
  vec_heap = heap1.vec_heap;  //copy constructor
  
}

template <typename T>
MaxHeap<T>::MaxHeap(MaxHeap&& a){
    vec_heap = a.vec_heap;
    a.vec_heap = {};
   //Move constructor
}

template <typename T>
MaxHeap<T>&::MaxHeap<T>::operator=(const MaxHeap<T>& heap_copy){
    if(this == &heap_copy){
        return *this;
    }
    vec_heap = heap_copy.vec_heap;
    
    return *this;
    //copy assignment
}
 template <typename T>
  MaxHeap<T>&::MaxHeap<T>::operator=( MaxHeap<T>&& heap_move){
      if(this == &heap_move){
        return *this;
    }
      vec_heap = heap_move.vec_heap;
      heap_move.vec_heap = {};
      return *this;
  }; // move operator


template <typename T>
MaxHeap<T>::MaxHeap(std::initializer_list<T> obj){
    for(auto it:obj){
        insert(it);
    }
    //initializer_list 
}

template <typename T>
MaxHeap<T>::~MaxHeap()=default;

template <typename T>
int MaxHeap<T>::extract_max_element(){
   
     return vec_heap[0];
}

template <typename T>
void MaxHeap<T>::delete_element(T value_delete){
    for(int i =0; i < (MaxHeap::vec_heap.size());++i){
        if(MaxHeap::vec_heap[i] == value_delete ){
            swap(MaxHeap::vec_heap[i], vec_heap[MaxHeap::vec_heap.size()-1]);
            MaxHeap::vec_heap.pop_back();
            MaxHeapify(i);
            return;
        }
    }
}

template <typename T>
int MaxHeap<T>::linear_search(T value_search){
    for(int i = 0; i < MaxHeap::vec_heap.size();++i){
        if(MaxHeap::vec_heap[i] == value_search){
            return i;
        }
    }
    return -1;
}


template <typename T>
T MaxHeap<T>::parent_heap(){
    return MaxHeap::vec_heap[0];
}



template <typename  T>
void MaxHeap<T>::right_heap(){
    
    for(int i =0; i < (MaxHeap::vec_heap.size()/2);++i){
        std::cout << "right  is "<< vec_heap[(2*i)+2]<<std::endl;
    }
}

template <typename T>
void MaxHeap<T>::left_heap(){
    for(int i = 0; i < (MaxHeap::vec_heap.size()/2);++i){
        std::cout << "left is " << vec_heap[(2*i)+1]<<std::endl;
    }
}

template <typename  T>
int  MaxHeap<T>::height(){
    return (log2(MaxHeap::vec_heap.size()+1)+1);
}

template <typename T>
void MaxHeap<T>::insert(T value){
    vec_heap.push_back(value);
       int index =  (vec_heap.size()-1);
   while(index != 0 && vec_heap[index] > vec_heap[parent(index)]){
        swap(vec_heap[index], vec_heap[parent(index)]);   
        MaxHeapify(parent(index));              
    }
}


template <typename T >
void MaxHeap<T>::print(){
    for(auto element : vec_heap ){
        std::cout << element << " ";
     MaxHeapify(MaxHeap::vec_heap.size()-1);
    }

    std::cout << std::endl;
}

template <typename T>
void MaxHeap<T>::MaxHeapify(int index){
   
	
    if (index != 0 && ((vec_heap[index]) > vec_heap[parent(index)])){
        swap(vec_heap[index], vec_heap[parent(index)]);  
        MaxHeapify(parent(index));               
    }
    
     int largest = index;
    int l = left(index);
	int r = right(index);
    if(left(index) < (vec_heap.size()) && vec_heap[left(index)] > vec_heap[index]){
                largest = l;
    }
    if(right(index) < (vec_heap.size()) && vec_heap[right(index)] > vec_heap[index]){
        largest = r;
        }
    
    if (largest != index){
        swap(vec_heap[index], vec_heap[largest]);      
       MaxHeapify(largest);              
    }
}
template <typename T>
void swap(T &x , T &y){
    T temp =  x;
    x = y;
    y =  temp;
}

