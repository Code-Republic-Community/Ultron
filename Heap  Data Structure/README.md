 <h1><b>Heap-Sort-Structure</b></h1> 

<h2>Introduction to Heap in Data Structures</h2>

<strong>A Heap is a special Tree-based data structure in which the tree is a complete binary tree. Generally, Heaps can be of two types:</strong>

<i>Max-Heap: In a Max-Heap the key present at the root node must be greatest among the keys present at all of it’s children. </i>

<i>Min-Heap: In a Min-Heap the key present at the root node must be minimum among the keys present at all of it’s children. </i>

<hr>


![2](https://user-images.githubusercontent.com/58858618/175516059-827fcb47-c64e-4da8-b7b8-7a4d3f46ee68.png)

<hr>


Time complexity in big O notation
<table>
  <tr>
    <th>Algorithm</th>
    <th>Average</th>
    <th>Worst case</th>
  </tr>
  <tr>
    <td>Insert</td>
    <td>O(log n)</td>
    <td>O(log n)</td>
  </tr>
  <tr>
    <td>Delete</td>
    <td>O(log n)</td>
    <td>O(log n)</td>
  </tr>
</table>

<hr>

The elements in the data structure are T type (template).

I have performed these functions։
insert () --- This function enters my values
 
height () --- This function shows the height of my heap

parent () --- This function shows the value of my parent

max_heapify () --- This function sorts Max Heap and Min Heap

delete_element ()  --- I pass a value to this function, if it finds a value, remove it and sort again, if it doesn't find the same value, it returns

extract_max_element () --- Returns the largest value in the case of Max heap and returns the significant value in the case of Min heap

left () --- Returns the left child nodes

right () --- Returns the left child nodes

linear_search () --- Passes the meaning of this function, if it finds the meaning, returns the index, if it does not return, returns -1

void print()  --- Prints Max Heap or Min Heap։

Same functions for min_heap

And a few other helpful functions։


<hr>


I also made these constructors

---Default constructor:

---Constructor with parameters (+std::initializer_list)

---Copy constructor:

---Move constructor:

---Destructor:

<hr>


I also made these operators

---Copy operator assignment =

---Move operator assignment =

---Operator stream out (cout) <<

---Operator is equal to ==

---Operator not equal to !=

---Operator +, +=


<hr>

