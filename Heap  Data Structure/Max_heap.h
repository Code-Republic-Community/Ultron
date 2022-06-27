#ifndef Max_heap
#define Max_heap 

template<typename T>
void swap(T &x, T &y);

template<typename T>
class MaxHeap
{
private:
std::vector<T> vec_heap;
public:
               
    MaxHeap(); //default constructor
    MaxHeap(const MaxHeap& ); //Copy constructor
    MaxHeap(MaxHeap&&);//Move constructor
    MaxHeap(std::initializer_list<T> obj); // parameterized constructor
    ~MaxHeap();//destructor
 
    MaxHeap& operator=(const MaxHeap<T>& heap);///copy operator  
    MaxHeap& operator=( MaxHeap<T>&& heap); // move operator

  bool operator==(const MaxHeap<T> equal){
   if(vec_heap.size() != equal.vec_heap.size() ){
    return false;
       }
       
   for(int i = 0;  i < vec_heap.size();++i){
    if(vec_heap[i] != equal.vec_heap[i])
     return false;
       }
       return true;
   }///equal operator
   
  bool operator!=(const MaxHeap<T> no_equal){
     return !(*this == no_equal);
  }//noequal operator

  MaxHeap operator+=(const MaxHeap<T>& sumequal){
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
	
  MaxHeap operator+( const MaxHeap<T>& sum){
   MaxHeap <T> tmp;
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
    
  friend std::ostream& operator<<(std::ostream& out ,const MaxHeap<T> &obj) {
  for(int i = 0;i < obj.size();++i){
      out << obj.vec_heap[i] << "  ";
    }
      return out;
  };//cout  << operator

	void MaxHeapify(int);

	int parent(int child) { return (child-1)/2; }

	int left(int parent) { return (2*parent+ 1); }

	int right(int parent) { return (2*parent + 2); }

	int extract_max_element();
	
	T parent_heap();
	
	int height();
	
	T size(){return vec_heap.size();}
	
	void left_heap();
	
	void right_heap();
	
	void delete_element(T value_delete);
public:
	void insert(T value);
	
	void print();
	
  int linear_search(T value_search);
	
	 
};


#include "Max_heap.hpp"
#endif
