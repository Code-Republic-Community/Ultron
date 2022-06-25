#include <utility>

template <typename iterator>
void bubble_sort(iterator begin, iterator end)
{
    iterator it = --end;
    for(iterator i = begin ; i != end; ++i) {
        bool _true = true;
        for(iterator j = begin; j != it; ++j) {
            iterator tmp = j;
            ++tmp;
            if (*j > *tmp ){
                _true = false;
                std::swap(*j, *tmp);
            }
        }
        if(_true) {return;}
    }
}
template <typename T>
void bubble_sort(T* arr,int size)
{
    for(int i = 0; i < size; ++i) {
    bool _true = true;
        for(int j = 0;j < size - 1; ++j) {
            if(arr[j] > arr[j+1]) {
                std::swap(arr[j],arr[j+1]);
                _true = false;
            }
        }
        if(_true) {
            break;
        }
    }
}
