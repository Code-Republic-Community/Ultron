<h1><i># Binary-Search-Algorithm</h1><br />
A binary search, is an algorithm used in computer science to locate a specified value within an array. For the search to be binary, the array must be sorted in either ascending or descending order.<br />
How does it work?<br />
As you can see in the diagram, at each step of the algorithm a comparison is made. Then, the procedure branches into one of two directions. Specifically, the key value is compared to the middle element of the array. If the key value is less than or greater than this middle element, the algorithm knows which half of the array to continue searching. The reason is because the array is sorted. This process is repeated on progressively smaller segments of the array until the value is located.<br />
Because each step in the algorithm divides the array size in half, a binary search completes successfully in logarithmic time. That is to say, the worst-case scenario for an array of n elements is guaranteed to be within log(n) operations.

![Screenshot from 2022-06-24 16-27-57](https://user-images.githubusercontent.com/104670251/175536120-3f71121a-a31e-4357-803c-f9123445ed5d.png)</i><br />

