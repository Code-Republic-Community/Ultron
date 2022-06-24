template<typename T>
bool BST<T>::operator!=(BST& not_equal)
{
    return !(bool_equal(root, not_equal.root));
}
template<typename T>
bool operator==(  BST<T>& equal,BST<T>& equa)
{
    return  equal.bool_equal(equal.root, equa.root);
}
template<typename T>
BST<T> BST<T>::operator+=(BST<T>& plusequal)
{
    std::vector<T> outitem;
    amount(root, plusequal.root, root, outitem);
    for(auto item : outitem) {
        insert(item);
    }
    return *this;
}
template<typename T>
BST<T> operator+(BST<T>& item,T value)
{
    BST<T> new_item;
    item.add_value(item.root, value,new_item.root);
    return new_item;
}
template<typename T>
BST<T> BST<T>::operator+(BST<T>& add)
{
    BST<T> new_obj;
    std::vector<T> outitem;
    amount(root, add.root, new_obj.root, outitem);
    for(auto item : outitem) {
        new_obj.insert(item);
    }
    return new_obj;
}
template<typename T>
BST<T> BST<T>::merge(BST<T> ob)
{
    merge_function(root, ob.root);
    return *this;
}

template<typename T>
BST<T>::~BST()
{
delete_root(root);
}
template<typename T>
BST<T>& BST<T>::operator=(BST<T>&& other)
{
this->root = other.root;
    other.root = nullptr;
    return *this;
}
template<typename T>
BST<T>& BST<T>::operator=(const BST<T>& other)
{
    if(this == &other) {
        return *this;
    }
    copy(root,other.root);
    return *this;
}
template<typename T>
BST<T>::BST( BST<T>&& obj)
{
    root = obj.root;
    obj.root = nullptr;
}
template<typename T>
BST<T>::BST(const BST<T>& cmp)
{
    copy(root, cmp.root);
}
template<typename T>
BST<T>::BST(std::initializer_list<T> list) : root(nullptr)
{
    for(T item : list) {
        insert(item);
    }
}
template<typename T>
std::ostream& operator<<(std::ostream& output, BST<T>& obj)
{
    obj.print_vector.clear();
    obj.print_root(obj.root,1);
    for (auto item : obj.print_vector) {
        output << item << " ";
    }
    output << std::endl;
    return output;
}

template<typename T>
void BST<T>::levelorder()
{
    int height = get__height(root);
    for(int i = 0; i < height; ++i) {
     row(root,i);
    }
}

template<typename T>
void BST<T>::inorder()
{
    print_root(root,1);
    vector_print();
    print_vector.clear();
}

template<typename T>
void BST<T>::preorder()
{
    print_root(root,2);
    vector_print();
    print_vector.clear();
}

template<typename T>
void BST<T>::postorder()
{
    print_root(root,3);
    vector_print();
    print_vector.clear();
}

template<typename T>
void BST<T>::insert(T value)
{
    if(value < 0) {
        return;
    }
    push(root,value);
}

template<typename T>
void BST<T>::clear()
{
    delete_root(root);
    root = nullptr;
}

template<typename T>
void BST<T>::erase(T val)
{
    erase_value(root);
    root = nullptr;
    erase_itr(val,root);
}

template<typename T>
bool BST<T>::find_function(node<T>* root, T value, T*& finD)
{
    if(root == nullptr) {
        return false;
    }
    if(value == root->m_item ) {
        finD = &root->m_item;
        flag = true;
        return true;
    }
    find_function(root->m_left, value, finD);
    find_function(root->m_right, value, finD);
    return flag;
}

template<typename T>
void BST<T>::row(node<T>* root, int value)
{
    bool b = 2;
    if(root == nullptr) {
        return;
    }
    
    if(value == 0) {
        std::cout << root->m_item << " ";
        return;
    }
    if(value > 0) {
        row(root->m_left,value - 1);
        row(root->m_right,value - 1);
    }
}

template<typename T>
bool BST<T>::contains_function(node<T>* obj, T value)
{
    if(obj == nullptr) {
        return false;
    }
    if(obj->m_item == value) {
        flag = true;
    }
    contains_function(obj->m_left, value);
    contains_function(obj->m_right, value);
    return flag;
}

template<typename T>
void BST<T>::merge_function(node<T>* obj1, node<T>* obj2)
{
    if(obj2 == nullptr) {
        return;
    }
    push(obj1,obj2->m_item);
    merge_function(obj1, obj2->m_left);
    merge_function(obj1, obj2->m_right);
}

template<typename T>
void BST<T>::number_of_nodes(node<T>* obj)
{
    if (obj == nullptr) {
        return;
    }
    ++number_nodes;
    number_of_nodes(obj->m_left);
    number_of_nodes(obj->m_right);
}

template<typename T>
int BST<T>::get__height(node<T>* height)
{
    if(height == nullptr) {
        return 0;
    }
    int num = get__height(height->m_left);
    int sum = get__height(height->m_right);
    if(num > sum) {
        return num + 1;
    }
        return sum + 1;
}

template<typename T>
void BST<T>::print_root(node<T>* obj, int value)
{
    if (obj == nullptr) {
        return;
    }
    if(value == 2) {
        print_vector.push_back(obj->m_item);
    }
    print_root(obj->m_left,value);
    if(value == 1) {
        print_vector.push_back(obj->m_item);
    }
    print_root(obj->m_right,value);
    if(value == 3) {
        print_vector.push_back(obj->m_item);
    }
}

template<typename T>
void BST<T>::erase_itr(T value, node<T>* root)
{
    for(auto itr = erase_root.begin(); itr != erase_root.end(); ++itr) {
        if(*itr != value) {
            insert(*itr);
        }
    }
}

template<typename T>
void BST<T>::erase_value(node<T>* obj)
{
   if (obj == nullptr) {
        return;
    }
    erase_root.push_back(obj->m_item);
    erase_value(obj->m_right);
    erase_value(obj->m_left);
    delete obj;
    obj = nullptr;
}

template<typename T>
bool BST<T>::bool_equal(node<T>*& obj1, node<T>*& obj2)
{
    if(obj1 == nullptr && obj2 == nullptr) {
        return true;
    }
    if(obj1 == nullptr) {
        flag = true;
        return false;
    }
    if(obj2 == nullptr) {
        flag = true;
        return false;
    }
    if(obj1->m_item != obj2->m_item) {
        flag = true;
        return false;
    }
    bool_equal(obj1->m_left, obj2->m_left);
    bool_equal(obj1->m_right, obj2->m_right);
    if(flag) {
        return false;
    }
    return true;
}
template<typename T>
void BST<T>::pushvector(const node<T>* add, std::vector<T>& outitem)
{
    if (add == nullptr) {
        return ;
    }
    outitem.push_back(add->m_item);
    pushvector(add->m_left, outitem);
    pushvector(add->m_right, outitem);
}

template<typename T>
void BST<T>::amount(node<T>* add1, node<T>* add2, node<T>*& add, std::vector<T>& outitem)
{
    if(add1 == nullptr && add2 == nullptr) {
        return;
    }
    if(add1 == nullptr) {
        pushvector(add2, outitem);
        return;
    }
    if(add2 == nullptr) {
        pushvector(add1, outitem);
        return;
    }
    add = new node<T>(add1->m_item + add2->m_item);
    amount(add1->m_left, add2->m_left, add->m_left, outitem);
    amount(add1->m_right, add2->m_right, add->m_right, outitem);
}

template<typename T>
void BST<T>::delete_root(node<T>* droot)
{
    if(droot == nullptr) {
        return;
    }
    delete_root(droot->m_left);
    delete_root(droot->m_right);
    delete droot;
    droot = nullptr;
}

template<typename T>
void BST<T>::copy(node<T>*& root, node<T>* croot)
{
    if(croot == nullptr) {
        root = nullptr;
        return;
    }
    root = new node<T>(croot->m_item);
    copy(root->m_left, croot->m_left);
    copy(root->m_right, croot->m_right);
}

template<typename T>
void BST<T>::push(node<T>*& root, T value)
{
    if (root == nullptr) {
        root = new node<T>(value);
        return;
    }
    if(value < root->m_item) {
        push(root->m_left, value);
    }
    if(value > root->m_item) {
        push(root->m_right, value);
    }
}

template<typename T>
void BST<T>::vector_print()
{
    for(auto it = print_vector.begin(); it != print_vector.end(); ++it) {
        std::cout << *it << " " ;
    }
}

template<typename T>
T BST<T>::get_height()
{
    T height_value = get__height(root);
    return height_value;
}

template<typename T>
void BST<T>::get_number_of_nodes()
{
    number_of_nodes(root);
    std::cout << number_nodes <<std::endl;
}

template<typename T>
T BST<T>::get_root_data()
{
    if(root == nullptr) {
        return 0;
    }
    return root->m_item;
}

template<typename T>
bool BST<T>::contains(T value)
{
    if(containS(root, value)) {
        return true;
    }
    return false;
}

template<typename T>
T* BST<T>::find(T value)
{
    T* finD = nullptr;
    if(!find_function(root, value, finD)) {
        std::cout << "There is no such number" << std::endl;
        finD = &non_find;
        return finD;
    }
    return finD;
}

template<typename T>
void BST<T>::add_value(node<T>* item, T value, node<T>*& new_item)
{
    if(item == nullptr) {
        return;
    }
    new_item = new node<T>(item->m_item + value);
    add_value(item->m_left, value, new_item->m_left);
    add_value(item->m_right, value, new_item->m_right);
}

