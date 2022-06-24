# Fibonacci-Search-Algorithm
Fibonacci Numbers are recursively defined as F(n) = F(n-1) + F(n-2), F(0) = 0, F(1) = 1.
First few Fibonacci Numbers are 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144,

Fibonacci Search is a comparison-based technique that uses Fibonacci numbers to search an element in a sorted array.

Similarities with Binary Search:

1.Works for sorted arrays

2.A Divide and Conquer Algorithm

3.Has Log n time complexity

Differences with Binary Search: 

1.Fibonacci Search divides given array into unequal parts

2.Binary Search uses a division operator to divide range. Fibonacci Search doesn’t use /, but uses + and -

3.Fibonacci Search examines relatively closer elements in subsequent steps

The idea is to first find the smallest Fibonacci number that is greater than or equal to the length of the given array.

This algorithm is implemented with STL list container and Forward iterators .


