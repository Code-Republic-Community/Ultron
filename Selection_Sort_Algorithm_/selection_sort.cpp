#include <iostream>
#include <algorithm>

template <typename iterator>
void selection_sort(iterator begin, iterator end) // with iterators
{
    for (iterator i = begin; i != end; ++i) {
        std::iter_swap(i, std::min_element(i, end));
    }
}
template <typename T>
void selection_sort(T* arr, int size) // implemented for a simple array
{
    int min{};
    for(int i = 0; i < size - 1; ++i) {
        min = i;
        for(int j = i + 1; j < size; ++j) {
            if(arr[j] < arr[min]) {
                min = j;
            }
        }
        T my_swap = arr[min];
        arr[min] = arr[i];
        arr[i] = my_swap;
    }
}

int main()
{
}

