Doubly linked list is a template node container.  You need to include List.hpp file to implement your own List type item.  


Constructors 
List()
	Makes List type object, which equal NULL.
List(T value)
	Makes List type object with one T type element in it. 
List(List obj)
	Makes list type object, which equal to obj
List(std::initializer_list)
	Makes list type object, which get values from initializer list.
~List()
	Delete and free memory from all List nodes

Methods
front()
	return first element value
back()
	return last element value
size()
	return list’s size
unique()
	delete List’s all repeated(duplicate) values

empty()
	returns true if List is empty, false if vice versa 
 insert(int index, T value)
	inserts one more T type element in index.
push_back(T value)
	adds one element in the end of the List
push_front(T value)
	adds one element in the front of the List
emplace(int index1, int index2)
	changes List’s index element values 
resize(int size)
	changes List size
	Note: if argument is bigger than List’s size, function add 0 to the end, else,	                                    .                     function delete last elements 
clear()
	delete all List’s items and free the memory
merge(List obj)
	add missing elements from obj to your List.
splice(List obj)
	move all elements from obj to your List
	Note: after this operation obj = NULL
splice(List obj, int index)
	move index element from obj to your List
	Note: after this operation obj = NULL
splice(List obj, int index1, int index2)
	move all elements from index1 to object2 from obj to your List obj
remove_if(iterator start, iterator end, bool (*func)(T))
	remove all elements from List, which return true when the argument function .          is called
back()
	returns an iterator to the begin of the function
end()
	returns an iterator to the end of the function

Operators
==   - return true if all elements are equal
!= - return true if minimum one element is not equal
<< - cout all list elements
>  - return true if the size of List bigger. Note: if size is equal – going to check first element to compare
< - return true if the size of List smaller. Note: if size is equal – going to check first element to compare
>= - return true if the List is bigger or equal
<= - return true if the List is smaller or equal
+ - return a sum of Lists
+= add all elements from second List to first 
= - copy list elements to yours 
