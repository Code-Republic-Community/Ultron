
template <typename T>
AVL<T>::AVL(const AVL<T>& obj)
{
	root_ptr = help_copy(obj.root_ptr);
}

template <typename T>
typename AVL<T>::Node* AVL<T>::help_copy(const Node* ptr) const
{
	Node* tmp = nullptr;

	if (ptr != nullptr)
	{
		tmp = new Node(ptr->value);
		tmp->left = help_copy(ptr->left);
		tmp->right = help_copy(ptr->right);
	}
	return tmp;
}

template <typename T>
AVL<T>::AVL(AVL<T>&& obj)
{
	root_ptr = obj.root_ptr;
	obj.root_ptr = nullptr;
}

template <typename T>
AVL<T>::AVL(std::initializer_list<T> ob):root_ptr(nullptr)
{
	for (auto i = ob.begin(); i != ob.end(); ++i)
	{
		insert(root_ptr, *i);
		help_rot(root_ptr);
	}
}

template <typename T>
void AVL<T>::help_rot(Node*& root)
{
	if (root != nullptr)
	{
		help_rot(root->left);
		if (get_balance(root) == false)
		{
			balanced(root);
		}
		help_rot(root->right);
	}
}

template <typename T>
AVL<T>::~AVL()
{
	if (root_ptr!= nullptr)
	{
		clear(root_ptr);
	}
}

template <typename T>
AVL<T>& AVL<T>::operator=(const AVL<T>& obj)
{
	if (this == &obj)
	{
		return *this;
	}

	if (root_ptr != nullptr)
	{
		help_delete(root_ptr);
		root_ptr = nullptr;
	}
	root_ptr = help_copy(obj.root_ptr);

	return *this;
}

template <typename T>
AVL<T>& AVL<T>::operator=(AVL<T>&& obj)
{
	if (root_ptr != nullptr)
	{
		help_delete(root_ptr);
		root_ptr = nullptr;
	}
	root_ptr = obj.root_ptr;
	obj.root_ptr = nullptr;
	return *this;
}

template <typename T>
bool AVL<T>::compare(Node* root1,Node* root2) const
{
	if (root1 == nullptr && root2 == nullptr) {
		return true;
	}

	if (root1 != nullptr && root2 != nullptr && root1->value == root2->value)
	{
		return compare(root1->left, root2->left) && compare(root1->right, root2->right);
	}
	return false;
}

template <typename T>
bool AVL<T>::operator==(const AVL<T>& ob) const
{
	if (get_height(root_ptr) != get_height(ob.root_ptr)) {
		return false;
	}
		return compare(root_ptr, ob.root_ptr);
}

template <typename T>
bool AVL<T>::operator!=(const AVL<T>& ob) const
{
	if (get_height(root_ptr) != get_height(ob.root_ptr)) {
		return false;
	}
	return !compare(root_ptr, ob.root_ptr);
}

template <typename T>
void AVL<T>::insert(Node*& root, T val)
{
	if (root == nullptr)
	{
		root = new Node(val);
	}
	else if (val < root->value)
	{
		insert(root->left, val);
		root->left->parent = root;
	}
	else if (val > root->value)
	{
		insert(root->right, val);
		root->right->parent = root;
	}
	else {
		return;
	}
}

template <typename T>
int AVL<T>::help_max(T a, T b) const {
	return (a > b) ? a : b;
}

template <typename T>
int AVL<T>::get_height(Node* root) const
{
	if (root == nullptr){
		return -1;
	}
	else if (root->left == nullptr && root->right == nullptr){
		return 0;
	}
		return 1 + help_max(get_height(root->left), get_height(root->right));
}

template <typename T>
int AVL<T>::help_balance(Node* root)
{
	if (root != nullptr){
		return get_height(root->left) - get_height(root->right);
	}
	return -1;
}

template <typename T>
bool AVL<T>::get_balance(Node*& root) 
{
	int balance = help_balance(root);
	if (balance == 0 || balance == 1 || balance == -1)
	{
		return true;
	}
	return false;
}

template <typename T>
void AVL<T>::balanced(Node*& root)
{
	int balance = help_balance(root);

	if (balance >= 2 && root!=nullptr && help_balance(root->left) > 0)
	{
		ll_rotate(root);
	}
	else
	{
		lr_rotate(root);
	}

	if (balance <= -2 && root!=nullptr && help_balance(root->right) < 0)
	{
		rr_rotate(root);
	}
	else
	{
		rl_rotate(root);
	}
}

template <typename T>
size_t AVL<T>::get_number_of_nodes(Node* root) const
{
	/*static size_t count = 0;
	if (root != nullptr)
	{
		get_number_of_nodes(root->left);
		get_number_of_nodes(root->right);
		return ++count;
	}*/
	if (root == nullptr) {
		return 0;
	}
	return 1 + (get_number_of_nodes(root->left) + get_number_of_nodes(root->right));
}

template <typename T>
void AVL<T>::erase(Node*& root, int val)
{
	if (root!= nullptr)
	{
		erase(root->left, val);
		erase(root->right, val);
		Node* ptr = root_ptr->left;
		if (val == root_ptr->value && root->value > ptr->value)
		{
			if (root->left == nullptr)
			{
				root_ptr->value = root->value;
				root = nullptr;
				if (get_balance(root_ptr) == false) {
					balanced(root_ptr);
				}
			}
			else
			{
				Node* tmp1 = root->left;
				Node* par = root->parent;
				par->right = tmp1;
				tmp1->parent = par;
				root = nullptr;
			}
		}
		else if (val == root->value && root->left == nullptr && root->right == nullptr) {
			root = nullptr;
			if (get_balance(root_ptr) == false) {
				balanced(root_ptr);
			}
		}
		else if (val == root->value && root->left != nullptr && root->right == nullptr)
		{
			Node* tmp = root->left;
			Node* par = root->parent;
			root = tmp;
			root->parent = par;
			if (get_balance(root_ptr) == false) {
				balanced(root_ptr);
			}
		}
		else if (val == root->value && root->left == nullptr && root->right != nullptr)
		{
			Node* tmp = root->right;
			Node* par = root->parent;
			root = tmp;
			root->parent = par;
			if (get_balance(root_ptr) == false) {
				balanced(root_ptr);
			}
		}
		else if (val == root->value && root->left != nullptr && root->right != nullptr)
		{
			if (val > root_ptr->value)
			{
				Node* tmp = root->right;
				Node* par = root->parent;
				root = root->left;
				root->parent = par;
				root->right = tmp;
				tmp->parent = root;
			}
			else
			{
				Node* tmp = root->left;
				Node* par = root->parent;
				root = root->right;
				root->parent = par;
				root->left = tmp;
				tmp->parent = root;
			}

			if (get_balance(root_ptr) == false) {
				balanced(root_ptr);
			}
		}
	}
}

template <typename T>
void AVL<T>::inorder(Node* root)
{
	if (root != nullptr)
	{
		inorder(root->left);
		std::cout << root->value << "  ";
		inorder(root->right);
	}
}

template <typename T>
void AVL<T>::preorder(Node* root)
{
	if (root != nullptr)
	{
		std::cout << root->value << "  ";
		preorder(root->left);
		preorder(root->right);
	}
}

template <typename T>
void AVL<T>::postorder(Node* root)
{
	if (root != nullptr)
	{
		postorder(root->left);
		if (root->left == nullptr || root->right == nullptr)
		{
			std::cout << root->value << "  ";
		}
		postorder(root->right);
		if (root->left != nullptr || root->right != nullptr)
		{
			std::cout << root->value << "  ";
		}
	}
}

template <typename T>
void AVL<T>::levelorder(Node* root)
{
	for (int i = 1;i <= get_number_of_nodes(root)/2; ++i)
	{
		help_levelorder(root, i);
	}
}

template <typename T>
void AVL<T>::help_levelorder(Node* root, int key)
{
	if (root == nullptr) {
		return;
	}
	if (key == 1) {
		std::cout << root->value << "  ";
	}
	else if (key > 1)
	{
		help_levelorder(root->left, key - 1);
		help_levelorder(root->right, key - 1);
	}
}

template <typename T>
AVL<T> AVL<T>::merge(AVL<T>& obj1,AVL<T>& obj2){
	return obj1.help_merge(obj2.root_ptr);
}

template <typename T>
void AVL<T>::help_merge(Node*& tmp)
{
	if (tmp != nullptr)
	{
		help_merge(tmp->left);
		insert(root_ptr, tmp->value);
		help_merge(tmp->right);
	}
}

template <typename T>
typename AVL<T>::Node* AVL<T>::rr_rotate(Node*& root)
{
	if (root != nullptr && root->right != nullptr)
	{
		if (root == root_ptr) {
			root_ptr = root->right;
			root_ptr->parent = nullptr;
		}
		Node* tmp = root->right;
		root->right = tmp->left;
		tmp->left = root;
		tmp->left->parent = tmp;
		return tmp;
	}
	return root;
}

template <typename T>
typename AVL<T>::Node* AVL<T>::ll_rotate(Node*& root)
{
	if (root != nullptr && root->left != nullptr)
	{
		if (root == root_ptr) {
			root_ptr = root->left;
			root_ptr->parent = nullptr;
		}
		Node* tmp = root->left;
		root->left = tmp->right;
		tmp->right = root;
		tmp->right->parent = tmp;
		return tmp;
	}
	return root;
}

template <typename T>
typename AVL<T>::Node* AVL<T>::rl_rotate(Node*& root)
{
	if (root != nullptr && root->right != nullptr)
	{
		Node* tmp = root->right;
		root->right = ll_rotate(tmp);
		return rr_rotate(root);
	}
	return root;
}

template <typename T>
typename AVL<T>::Node* AVL<T>::lr_rotate(Node*& root)
{
	if (root != nullptr && root->left!=nullptr)
	{
		Node* tmp = root->left;
		root->left = rr_rotate(tmp);
		return ll_rotate(root);
	}
	return root;
}

template <typename T>
bool AVL<T>::contains(Node*& root, const T& val)
{
	if (root != nullptr)
	{
		if (val == root->value)
		{
			return true;
		}
		else if (val < root->value)
		{
			return contains(root->left, val);
		}
		else if (val > root->value)
		{
			return contains(root->right, val);
		}
		else
			return false;
	}
	return false;
}

template <typename T>
typename AVL<T>::Node* AVL<T>::find(Node*& root, const T& val)
{
	if (root!= nullptr)
	{
		if (val == root->value)
		{
			return root;
		}
		else if (val < root->value)
		{
			return find(root->left, val);
		}
		else if (val > root->value)
		{
			return find(root->right, val);
		}
		else
			return nullptr;
	}
	return nullptr;
}

template <typename T>
T AVL<T>::get_root_data(Node*& root)
{
	if (root != nullptr)
	{
		return root->value;
	}
}

template <typename T>
void AVL<T>::clear(Node*& ptr)
{
	if (ptr != nullptr)
	{
		clear(ptr->left);
		clear(ptr->right);
		delete ptr;
		ptr = nullptr;
	}
}

template <typename T>
typename AVL<T>::Node* AVL<T>::find_min(Node* root)
{
	if (root != nullptr && root->left != nullptr){
		return find_min(root->left);
	}
		return root;
}

template <typename T>
typename AVL<T>::Iterator AVL<T>::begin() 
{
	if(root_ptr != nullptr)
	{
		Iterator it(find_min(root_ptr),root_ptr);
		return it;
	}
}
///
template <typename T>
typename AVL<T>::Node* AVL<T>::find_max(Node* root)
{
	while (root_ptr != nullptr || root->right != nullptr)
	{
		if (root->right == nullptr) {
			return nullptr;
		}
		root = root->right;
	}
	return root;
}

template <typename T>
typename AVL<T>::Iterator AVL<T>::end() {
	if (root_ptr != nullptr)
	{
		Iterator it(find_max(root_ptr),root_ptr);
		return it;
	}
}

template <typename T>
bool AVL<T>::Iterator::operator==(const Iterator& ob) const {
	return m_it == ob.m_it;
}

template <typename T>
bool AVL<T>::Iterator::operator!=(const Iterator& ob) const{
	return !(*this == ob);
}

template <typename T>
typename AVL<T>::Iterator& AVL<T>::Iterator::operator++()
{
	if (m_it != nullptr) 
	{
		if (m_it->right != nullptr)
		{
			m_it = m_it->right;
			while (m_it->left != nullptr)
			{
				m_it = m_it->left;
			}
			return *this;
		}
		else if(m_it->value < new_root->value)
		{
			Node* tmp = m_it->parent;
			while (tmp != nullptr && m_it == tmp->right)
			{
				m_it = tmp;
				tmp = tmp->parent;
			}
			m_it = tmp;
			return *this;
		} 
		else
		{
			Node* tmp = m_it->parent;
			if (tmp->right == m_it)
			{
				m_it = nullptr;
				return *this;
			}
			else
			{
				m_it = m_it->parent;
				return *this;
			}
		}
	}
	return *this;
}

template <typename T>
typename AVL<T>::Iterator AVL<T>::Iterator::operator++(int)
{
	Iterator tmp(*this);
	++(*this);
	return tmp;
}

template <typename T>
typename AVL<T>::Iterator& AVL<T>::Iterator::operator--()
{
	if (m_it != nullptr)
	{
		if (m_it->left != nullptr)
		{
			m_it = m_it->left;
			while (m_it->right != nullptr)
			{
				m_it = m_it->right;
			}
			return *this;
		}
		else if(m_it->value > new_root->value)
		{
			Node* tmp = m_it->parent;
			while (tmp != nullptr && m_it == tmp->left)
			{
				m_it = tmp;
				tmp = tmp->parent;
			}
			m_it = tmp;
			return *this;
		}
		else
		{
			Node* tmp = m_it->parent;
			if (tmp->left == m_it)
			{
				m_it = nullptr;
				return *this;
			}
			else
			{
				m_it = m_it->parent;
				return *this;
			}
		}
		return *this;
	}
}

template <typename T>
typename AVL<T>::Iterator AVL<T>::Iterator::operator--(int)
{
	Iterator tmp(*this);
	--(*this);
	return tmp;
}

template <typename T>
const T& AVL<T>::Iterator::operator*() const {
	return m_it->value;
}