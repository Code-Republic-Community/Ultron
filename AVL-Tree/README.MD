<h1><b>An Introduction to AVL Tree</b></h1>
<hr>
<h3><i>AVL tree is a self-balanced binary search tree. That means, an AVL tree is a binary search tree but it is a balanced tree. A binary tree is said to be balanced, if the difference between the heights of left and right subtrees of every node in the tree is either -1, 0 or +1. In other words, a binary tree is said to be balanced if for every node, height of its children differ by at most one. In an AVL tree, every node maintains an extra information known as balance factor to take care of the self-balancing nature of the tree.</i></h3>

  ![avl-tree](https://user-images.githubusercontent.com/99535791/175946902-7b87f6a4-aeaa-4f1a-8553-4314265af32a.png)

  
  <h1><b>Why AVL Tree ?</b></h1>
 <h3><i> AVL tree controls the height of the binary search tree by not letting it to be skewed. The time taken for all operations in a binary search tree of height h is O(h). However, it can be extended to O(n) if the BST becomes skewed (i.e. worst case). By limiting this height to log n, AVL tree imposes an upper bound on each operation to be O(log n) where n is the number of nodes..</i></h3>
 
 
<h1><b> AVL Tree Rotations ?</b></h1>
<h3><i>In AVL tree, after performing every operation like insertion and deletion we need to check the balance factor of every node in the tree. If every node satisfies the balance factor condition then we conclude the operation otherwise we must make it balanced. We use rotation operations to make the tree balanced whenever the tree is becoming imbalanced due to any operation.

Rotation is the process of moving the nodes to either left or right to make tree balanced in terms of its height.
To balance itself, an AVL tree may perform the following four kinds of rotations −</b></h1>

<h3><i> 1> Left rotation (Single)</i></h3>
<h3><i> 2> Right rotation (Single)</i></h3>
<h3><i> 3> Left-Right rotation (Double))</i></h3>
<h3><i> 4> Right-Left rotation (Double)?)</i></h3>

  ![maxresdefault](https://user-images.githubusercontent.com/99535791/175948654-6bff70f3-8d45-45c4-aeee-2e8460d105cb.jpg)
  
 <h1><b>Searching</b></h1>

<h2><i>Searching in an AVL Tree is done as in any binary search tree. The Special thing about AVL Tree is that the number of comparison required, i.e. The AVL three’s height, is guaranteed never to exceed log(n).</b></h2>

<h3><i>Step 1: Read the search element from the user.</b></h1>
<h3><i>Step 2: Compare, the search element with the value of root node in the tree.</b></h3>
<h3><i>Step 3: If both are matching, then display “Given node found!!!” and terminate the function.</b></h3>
<h3><i>Step 4: If both are not matching, then check whether search element is smaller or larger than that node value.</b></h3>
<h3><i>Step 5: If search element is smaller, then continue the search process in left subtree.</b></h3>
<h3><i>Step 6: If search element is larger, then continue the search process in right subtree.</b></h3>
<h3><i>Step 7: Repeat the same until we found exact element or we completed with a leaf node.</b></h3>
<h3><i>Step 8: If we reach to the node with search value, then display “Element is found” or "True" and terminate the function.</b></h3>
<h3><i>Step 9: If we reach to a leaf node and it is also not matching, then display “Element not found” or "False" and terminate the function.</b></h3>

![bst4](https://user-images.githubusercontent.com/99535791/175953841-38e28c7a-0fe7-4554-940a-3562ad43b7bc.png)

 <h1><b>Insertion</b></h1>

<h2><i>Insertion in AVL tree is performed in the same way as it is performed in a binary search tree. However, it may lead to violation in the AVL tree property and therefore the tree may need balancing. The tree can be balanced by applying rotations.</b></h2>

<h3><i>Step 1: Insert the new element into the tree using Binary Search Tree insertion logic.</b></h3>
<h3><i>Step 2: After insertion, check the Balance Factor of every node.</b></h3>
<h3><i>Step 3: If the Balance Factor of every node is 0 or 1 or -1 then go for next operation.</b></h3>
<h3><i>Step 4: If the Balance Factor of any node is other than 0 or 1 or -1 then tree is said to be imbalanced. Then perform the suitable Rotation to make it balanced. And go for next operation.</b></h3>

![Insert-into-BST](https://user-images.githubusercontent.com/99535791/175953306-85a0abaf-2feb-495b-8317-7868483cc20a.png)

 <h1><b>Deletion</b></h1>
<h3><i>Deletioncan also be performed in the same way as it is performed in a binary search tree. Deletion may also disturb the balance of the tree therefore; various types of rotations are used to rebalance the tree.</b></h3>

![EFQoQ](https://user-images.githubusercontent.com/99535791/175952460-eb530612-150e-4dbe-8141-8093d3e1d946.png)

 <h1><b>Complexity AVL Tree</b></h1>

![introduction-to-avl-trees-4-1635360791](https://user-images.githubusercontent.com/99535791/175954802-2d48e74b-ec85-4ccf-84c6-79f53d8acaff.png)
