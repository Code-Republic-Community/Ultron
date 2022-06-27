#include <iostream>
#include "avl.h"



int main()
{
	AVL<int> obj{20,10,30,12,5,25,13,35,24,6};
	AVL<int> obj1{20,10,30};
	//std::cout<<obj.get_number_of_nodes(obj.root_ptr);
	//AVL<int> obj2 = obj2.merge(obj, obj1);
	/*if (obj != obj1) {
		std::cout << "Yes ";
	}
	else {
		std::cout << "No ";
	}*/
	//std::cout << obj.get_number_of_nodes(obj.root_ptr);
	//std::cout << obj.get_height(obj.root_ptr);
	//obj.preorder(obj.root_ptr);
	//obj.postorder(obj.root_ptr);
	//obj.contains(obj.root_ptr,25);
	//std::cout << obj.find(obj.root_ptr, 31);
	//obj.get_balance(obj.root_ptr);
	//obj.erase(obj.root_ptr, 20);
	//obj.levelorder(obj.root_ptr);
	//obj.inorder(obj.root_ptr);
	//std::cout << obj.get_root_data(obj.root_ptr);
	//obj.levelorder(obj2.root_ptr);
	//AVL<int>::Iterator obj2(obj.root_ptr);

	/*for (auto it = obj.begin();it != obj.end();++it)
	{
		std::cout << *(it) << "  ";
	}*/

	/*auto it = obj.begin();
	++it;
	++it;
	std::cout << *(--it);*/
}

