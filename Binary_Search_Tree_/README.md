<i><h1>#Binary Search Tree</h1><br />
Binary Search Tree is a node-based binary tree data structure which has the following properties:<br />
<br />
1.The left subtree of a node contains only nodes with values lesser than the node value.<br />
2.The right subtree of a node contains only nodes with values greater than the node value.<br />
3.The left and right subtree each must also be a binary search tree. <br />
4.There must be no duplicate nodes.<br />
<br />
![Screenshot from 2022-06-24 13-50-24](https://user-images.githubusercontent.com/104670251/175511507-48ad9686-6ac9-4c95-87fa-5597c9d37744.png)
<br />
<br />
Advantages of Binary Search Tree:<br />
1.BST is fast in insertion and deletion when balanced.<br />
2.BST is efficient.<br />
3.BST code is simple as compared to other data structures.<br />
<br />
Disadvantages of Binary Search Tree:<br />
1.The main disadvantage is that we should always implement a balanced binary search tree.Otherwise the cost of operations may not be logarithmic and degenerate into a linear search on an array.<br />
2.Accessing the element in BST is slightly slower than array.<br />
3.A BST can be imbalanced which can increase the complexity.<br />
<br />
![Screenshot from 2022-06-24 14-11-56](https://user-images.githubusercontent.com/104670251/175514722-dbed9e89-3654-4f09-9168-2cd5bc50b782.png)
<br />
Execution times:<br />
1.Search	O(log n):<br />
2.Minimum	O(log n):<br />
3.Maximum	O(log n):<br />
4.Insert	O(log n):<br />
5.Delete	O(log n):<br />
<br />
BST functions:<br />
1.insert() //enters a value.<br />
2.clear() //enters a value.<br />
3.get_height() // returns the height of the tree.<br />
4.erase() //removes a specific item.<br />
5.get_number_of_nodes() // returns the number of roots.<br />
6.preorder()<br />
7.inorder()<br />
8.postorder()<br />
9.levelorder()<br />
10.get_root_data() // returns root.<br />
11.merge() //this function returns two trees connected to each other.<br />
12.contains() // checks if there is such a value.<br />
13.find() // this function returns a pointer to the root of a given value.</i><br />

