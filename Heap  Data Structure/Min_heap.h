#ifndef Min_heap
#define Min_heap


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
#include "Min_heap.hpp"
#endif 
