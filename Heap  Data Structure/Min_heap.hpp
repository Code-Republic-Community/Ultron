template <typename T>
MinHeap<T>::MinHeap()=default;

template <typename T>
 MinHeap<T>::MinHeap(const MinHeap& heap1){  
  vec_heap = heap1.vec_heap;  //copy constructor
  
}

template <typename T>
 MinHeap<T>::MinHeap(MinHeap&& a){
   vec_heap = a.vec_heap;
     a.vec_heap = {};
   //Move constructor
}

template <typename T>
  MinHeap<T>&::MinHeap<T>::operator=(const MinHeap<T>& heap_copy){
    if(this == &heap_copy){
        return *this;
    }
    vec_heap = heap_copy.vec_heap;  
    return *this;
    //copy assignment
}
template <typename T>
 MinHeap<T>&::MinHeap<T>::operator=( MinHeap<T>&& heap_move){
   if(this == &heap_move){
      return *this;
    }
     vec_heap = heap_move.vec_heap;
     heap_move.vec_heap = {};
     return *this;
  }; // move operator

template <typename T>
 MinHeap<T>::MinHeap(std::initializer_list<T> obj){
   for(auto it : obj)
    insert(it);
    //initializer_list 
}

template <typename T>
 MinHeap<T>::~MinHeap()=default;

template <typename T>
  int MinHeap<T>::extract_min_element(){
    return vec_heap[0];
}

template <typename T>
 void MinHeap<T>::delete_element(T value_delete){
  for(int i =0; i < (MinHeap::vec_heap.size());++i){
   if(MinHeap::vec_heap[i] == value_delete ){
     swap(MinHeap::vec_heap[i], vec_heap[MinHeap::vec_heap.size()-1]);
       MinHeap::vec_heap.pop_back();
        MinHeapify(i);
            return;
        }
    }
}

template <typename T>
 int MinHeap<T>::linear_search(T value_search){
  for(int i = 0; i < MinHeap::vec_heap.size();++i){
    if(MinHeap::vec_heap[i] == value_search){
      return i;
      }
  }
   return -1;
}

template <typename T>
 T MinHeap<T>::parent_heap(){
    return MinHeap::vec_heap[0];
}

template <typename  T>
 void MinHeap<T>::right_heap(){   
    for(int i =0; i < (MinHeap::vec_heap.size()/2);++i){
        std::cout << "right  is "<< vec_heap[(2*i)+2]<<std::endl;
    }
}

template <typename T>
void MinHeap<T>::left_heap(){
    for(int i = 0; i < (MinHeap::vec_heap.size()/2);++i){
        std::cout << "left is " << vec_heap[(2*i)+1]<<std::endl;
    } 
 }
template <typename  T>
  int  MinHeap<T>::height(){
    return (log2(MinHeap::vec_heap.size()+1)+1);
 }

template <typename T>
 void MinHeap<T>::insert(T value){
   vec_heap.push_back(value);
     int index =  (vec_heap.size()-1);
      while(index != 0 && vec_heap[index] < vec_heap[parent(index)]){
       swap(vec_heap[index], vec_heap[parent(index)]);   
        MinHeapify(parent(index));              
    }
}

template <typename T >
 void MinHeap<T>::print(){
  for(auto element : vec_heap ){
   std::cout << element << " ";
     MinHeapify(MinHeap::vec_heap.size()-1);
    }
    std::cout << std::endl;
}

template <typename T>
 void MinHeap<T>::MinHeapify(int index){
  if (index != 0 && ((vec_heap[index]) < vec_heap[parent(index)])){
    swap(vec_heap[index], vec_heap[parent(index)]);  
     MinHeapify(parent(index));               
    }   
 int largest = index;
 int l = left(index);
 int r = right(index);
  if(left(index) < (vec_heap.size()) && vec_heap[left(index)] < vec_heap[index]){
      largest = l;
    }
  if(right(index) < (vec_heap.size()) && vec_heap[right(index)] < vec_heap[index]){
      largest = r;
    }  
  if (largest != index){
       swap(vec_heap[index], vec_heap[largest]);      
        MinHeapify(largest);              
    }
}
template <typename T>
void swap(T &x , T &y){
    T temp =  x;
    x = y;
    y =  temp;
}

