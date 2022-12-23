# HashTable is an container which recieves template type key and template type value  
![hash-table](https://user-images.githubusercontent.com/88653435/208425661-2ea84691-b9e0-4abc-a438-4819d80fa112.png)


## How to define
-    HashTable<K, T> name;
-    HashTable<K, T> name(size);
-    HashTable<K, T> name(obj):
  
  ## How to use methods(provided below) on List 
 -    name.method(argument);

## Constructors

HashTable()
-    Make an HashTable type object, which's vector and _count are equal to nullptr.

HashTable(int size)
-	Make an HashTable type object, which's vector size is equal to the argument. 

HashTable(HashTable obj)
-	Make an HashTable type object, which equal to obj

HashTable(std::initializer_list)
-	Make list type object, which get values from initializer list in pair<K, T> format
-	
~HashTable()
-	Delete and free memory from all List nodes

## Methods
get_count()
-	returns count of ellements in a table

empty()
-	returns true if the table is empty, returns false via versa

size()
-	return size of the List

contains(K key)
-	returns true if there is an element with this key and false via versa.

find(K key)
-	return an element value with this key 

insert(K key, T value)
-	inserts an element in this key and value. Changing the old value if exsists.

reformat()
-	Making table twice more and changing the places of old values

remove(K key, T value)
-	deleting the element from the table

emplace(K key, const T &value)
-	inserting the value in the table

print_table()
-	printing the table in a given structure

swap(HashTable<K, T> &obj)
-	changing values and keys in your and argument's table

merge(HashTable obj)
-	add missing elements from obj to your table.


# Hashing algorithms
- String: https://cp-algorithms.com/string/string-hashing.html
- Other types: std::hash<type> ()(key);
- Own classes/structures: you must write own hashing fuction

## Operators
==   - return true if all elements are equal
!= - return true if minimum one element is not equal
<< - cout all list elements
\> return true if the size of table bigger. Note: if size is equal – going to check first element to compare
< - return true if the size of table smaller. Note: if size is equal – going to check first element to compare
\>= - return true if the table is bigger or equal
<= - return true if the table is smaller or equal
= - making your table equal to another one 
= - move constructor
