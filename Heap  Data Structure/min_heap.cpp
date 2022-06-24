#include<iostream>
#include<cmath>
#include <initializer_list>
#include <vector>

template<typename T>
void swap(T &x, T &y);


template<typename T>
class MinHeap
{

private:
std::vector<T> vec_heap;
public:
               
    MinHeap(); //default constructor
    MinHeap(const MinHeap& ); //Copy constructor
    MinHeap(MinHeap&&);//Move constructor
    MinHeap(std::initializer_list<T> obj); // parameterized constructor
    ~MinHeap();//destructor
 
  MinHeap& operator=(const MinHeap<T>& heap);///copy operator  
  MinHeap& operator=( MinHeap<T>&& heap); // move operator

   bool operator==(const MinHeap<T> equal){
       if(vec_heap.size() != equal.vec_heap.size() ){
           return false;
       }
       for(int i = 0;  i < vec_heap.size();++i){
           if(vec_heap[i] != equal.vec_heap[i])
           return false;
       }
       return true;
   }///equal operator
   
  bool operator!=(const MinHeap<T> no_equal){
     return !(*this == no_equal);
  }//noequal operator

  MinHeap operator+=(const MinHeap<T>  &sumequal){
     
        if(sumequal.vec_heap.size() == vec_heap.size()){
         for(int i = 0; i < vec_heap.size();++i){
        this->vec_heap[i] += sumequal.vec_heap[i];
         
            }
         }
       
      if(sumequal.vec_heap.size() < vec_heap.size())
      for(int i = 0; i < sumequal.vec_heap.size();++i){
      this->vec_heap[i] += sumequal.vec_heap[i];
    
        }
        
        
        if(sumequal.vec_heap.size() > vec_heap.size()){
        for(int i = 0; i < vec_heap.size();++i){
     
      this->vec_heap[i] += sumequal.vec_heap[i];
        }
       for(int i = vec_heap.size();i < sumequal.vec_heap.size();++i) {
          
            insert(sumequal.vec_heap[i]);
        }
        
        }
  
      return *this;
  }; //sumequal operator
    
  MinHeap operator+(const MinHeap<T>  &sum){
     MinHeap <T> tmp;
      if(sum.vec_heap.size() > vec_heap.size()){
          for(int i = 0; i < sum.vec_heap.size();++i){
          tmp.vec_heap.push_back(vec_heap[i] + sum.vec_heap[i]);
         }
      }
         if(sum.vec_heap.size() < vec_heap.size()){
               for(int i = 0; i < sum.vec_heap.size();++i){
          tmp.vec_heap.push_back(vec_heap[i] + sum.vec_heap[i]);
          
         }
         
          for(int i = sum.vec_heap.size();i < vec_heap.size();++i) {
            tmp.vec_heap.push_back(vec_heap[i]);
        }
         }
         if(sum.vec_heap.size() == vec_heap.size()){
         for(int i = 0; i < vec_heap.size();++i){
             tmp.vec_heap.push_back(vec_heap[i] + sum.vec_heap[i]);
            }
         }
      return tmp;
    };
   // sum operator
    
  friend std::ostream& operator<<(std::ostream& out ,MinHeap<T> &obj) {
      for(int i = 0;i < obj.size();++i){
      out << obj.vec_heap[i] << "  ";
      }
      return out;
  };//cout  << operator

	void MinHeapify(int);

	int parent(int child) { return (child-1)/2; }

	int left(int parent) { return (2*parent+ 1); }

	int right(int parent) { return (2*parent + 2); }

	int extract_min_element();
	
	T parent_heap();
	
	int height();
	
	int size(){return vec_heap.size();}
	
	void left_heap();
	
	void right_heap();
	
	void delete_element(T value_delete);
public:
	void insert(T value);
	void print();
int linear_search(T value_search);
	
	 
};

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

int main(){
    MinHeap<int>heap;
    heap.insert(15);
    heap.insert(5);
    heap.insert(5);
    heap.insert(41);
    heap.insert(17);
   
   
     heap.extract_min_element();

 // heap.print();
    MinHeap<int>heap1;
       

     heap1.insert(15);
    heap1.insert(8);
    heap1.insert(5);
    heap1.insert(5);
    heap1.insert(7);

   
   heap1.print();
   heap.print();
// MinHeap<int>heap2= heap + heap1;;
 
  //heap2.print();
  
  //std::cout<<heap.extract_min_element();
 //   heap2.print();
   /* heap1.insert(1);
   
    heap1.insert(7);
    heap1.insert(1);
    heap1.insert(5);
    heap1.insert(55);
    heap1.insert(14);
    heap1.insert(15);
    heap1.insert(85);*/
    //heap1.print();
 heap1 += heap;
  heap1.print(); 
   // heap.print();
  /* if(heap == heap1){
        std::cout << "equal "<<std::endl;
    }else{
        std::cout << "no equal "<<std::endl;
    }
    
    if(heap != heap1){
        std::cout << "true "<<std::endl;
    }else{
        std::cout << "false" <<std::endl;
    }*/
    
  //  MinHeap<int>heap4;
   //  MinHeap<int>heap3;
   
   
  
  // heap = heap + heap1;
 //   heap = std::move(heap1);
 // heap.print();
   //std::cout<< "asZDasZ"<<std::endl;
    //heap1 = heap;
    //heap1.insert(45);
  // heap1.print();
    
   /* std::cout <<std::endl;
    std::cout << heap.height()<<" ";
    std::cout << std::endl;*/
  //  heap.left_heap();
   /* heap.right_heap();
    std::cout << "linear_search is "<< heap.linear_search(95)<<std::endl;
    std::cout << "Parent is  " << heap.parent_heap() << std::endl;
    */
   // heap.print();

//   heap.delete_element(44);
  
 // heap.print();
   /* heap.insert(105);
    heap.insert(35);
    heap.insert(175);
    heap.insert(34);*/
 //  heap.print();
 //heap.print();
   // std::cout <<heap; 
    std::cout<<std::endl;
  // MinHeap<int>hp{1,7,8,9,4,18,11,41};
//   hp.print();
   
}
