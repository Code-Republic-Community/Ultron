#ifndef BS_H
#define BS_H
template <typename T>
int BinarySearch(T* arr, int size, T value); //for a simple array
template<typename iter>
int size(iter begin, iter end); // This function is for size determination
template<typename iterator>
iterator add(iterator it, int value); // This function is intended for plus operation
template<typename iterator, typename T>
iterator BinarySearch(iterator begin, iterator end, T value, std::forward_iterator_tag); // This function works for list iterators
template<typename iterator, typename T>
iterator BinarySearch(iterator begin, iterator end, T value, std::random_access_iterator_tag); // This function works for vector iterators
template<typename IteratorType, typename T>
IteratorType Binary_Search(IteratorType start, IteratorType end, T value); // This function is designed to determine whether it is a list iterator or a vector iterator
#include "BS.hpp"
#endif
