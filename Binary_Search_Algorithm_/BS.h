#ifndef BS_H
#define BS_H
template <typename T>
int BinarySearch(T* arr, int size, T value);
template<typename iter>
int size(iter begin, iter end);
template<typename iterator>
iterator add(iterator it, int value);
template<typename iterator, typename T>
iterator BinarySearch(iterator begin, iterator end, T value, std::forward_iterator_tag);
template<typename iterator, typename T>
iterator BinarySearch(iterator begin, iterator end, T value, std::random_access_iterator_tag);
template<typename IteratorType, typename T>
IteratorType Binary_Search(IteratorType start, IteratorType end, T value);
#include "BS.hpp"
#endif
