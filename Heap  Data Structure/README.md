 <h1><b>Heap-Sort-Structure</b></h1> 

<h2>Introduction to Heap in Data Structures</h2>

<strong>A Heap is a special Tree-based data structure in which the tree is a complete binary tree. Generally, Heaps can be of two types:</strong>

<i>Max-Heap: In a Max-Heap the key present at the root node must be greatest among the keys present at all of it’s children. </i>

<i>Min-Heap: In a Min-Heap the key present at the root node must be minimum among the keys present at all of it’s children. </i>

<hr>


![2](https://user-images.githubusercontent.com/58858618/175516059-827fcb47-c64e-4da8-b7b8-7a4d3f46ee68.png)

<hr>


<b><i>Time complexity in big O notation</i> </b>
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

<b><i>The elements in the data structure are T type (template).</i> </b>

<h3>I have performed these functions։</h3>

<b>insert ()  </b> --- This function enters my values
 
<b>height ()  </b>--- This function shows the height of my heap

<b>parent ()  </b>--- This function shows the value of my parent

<b>max_heapify ()  </b>--- This function sorts Max Heap and Min Heap

<b>delete_element () </b> --- I pass a value to this function, if it finds a value, remove it and sort again, if it doesn't find the same value, it returns

 
<b>extract_max_element ()  </b> --- Returns the largest value in the case of Max heap and returns the significant value in the case of Min heap

<b>left ()  </b>--- Returns the left child nodes

<b>right ()  </b> --- Returns the left child nodes

<b>linear_search ()  </b> --- Passes the meaning of this function, if it finds the meaning, returns the index, if it does not return, returns -1

<b>void print()  </b> --- Prints Max Heap or Min Heap։

Same functions for min_heap

And a few other helpful functions։


<hr>


<h3>I also made these constructors</h3>

<b>---Default constructor:  </b>

<b>---Constructor with parameters (+std::initializer_list)  </b>

<b>---Copy constructor:  </b>

<b>---Move constructor:  </b>

<b>---Destructor:  </b>

<hr>


<h3>I also made these operators</h3>

<b>---Copy operator assignment =  </b>

<b>---Move operator assignment =  </b>

<b>---Operator stream out (cout) <<  </b>

-<b>--Operator is equal to ==  </b>

<b>---Operator not equal to !=  </b>

 <b>---Operator +, +=  </b>


<hr>

