#ifndef BST_H
#define BST_H
template<typename T>
class BST
{
private:
    template<typename>
    struct node
    {
        T m_item;
        node<T>* m_left;
        node<T>* m_right;
        node(T item = T(), node<T>* left = nullptr, node<T>* right = nullptr) :
        m_item(item),
        m_left(left),
        m_right(right)
        {}
        ~node() {}
    };
    node<T>* root;
public:
    BST() : root(nullptr) {}
    BST(std::initializer_list<T>);
    BST(const BST<T>&);
    BST( BST<T>&&);
    BST& operator=(const BST<T>&);
    BST& operator=(BST<T>&&);
    ~BST();
public:
    template<typename T1>
    friend std::ostream& operator<<(std::ostream&, BST<T1>&);
    template<typename T1>
    friend BST<T1> operator+(BST<T1>&, T);
    template<typename T1>
    friend bool operator==(BST<T1>&, BST<T1>&);
    BST operator+(BST<T>&);
    BST operator+=(BST<T>&);
    bool operator!=(BST&);
public:
    T* find(T); // this function returns a pointer to the root of a given value
    T non_find{}; // the find function returns not_find if it does not find a value
    BST merge(BST<T> ob); //this function returns two trees connected to each other
    std::vector<T> erase_root; // The erase function is performed using this vector
    std::vector<T> print_vector; // this vector helps the ostream operator
    T get_height(); // returns the height of the tree
    T get_root_data(); // returns root
    void get_number_of_nodes(); // returns the number of roots
    void erase(T); //removes a specific item
    void inorder();
    void preorder();
    void postorder();
    void levelorder();
    void insert(T); //enters a value
    void clear(); // cleans the tree
    bool contains(T); // checks if there is such a value
    bool flag = false;
    int number_nodes{}; // this variable keeps the height of the tree
private:
    void add_value(node<T>*, T, node<T>*&); // this function can add value to an object
    bool find_function(node<T>*, T, T*&); // this function looks for whether there is a similar value
    void row(node<T>*, int); // this function calculates the height of the tree
    bool contains_function(node<T>*, T); // this function returns true if it has found the transferred value
    void merge_function(node<T>*, node<T>*); // this function connects two trees
    void number_of_nodes(node<T>*); // returns the number of roots
    int  get__height(node<T>*); //returns the height of the tree
    void print_root(node<T>*, int); // prints the tree
    void erase_itr(T, node<T>*); // removes the specific value of the tree
    void erase_value(node<T>*); // this function helps the erase function
    bool bool_equal(node<T>*&, node<T>*&); // this function compares two trees
    void pushvector(const node<T>*, std::vector<T>&); // If one of the trees has no left or right node,  it must be a  into the vector
    void amount(node<T>*, node<T>*, node<T>*&, std::vector<T>&); // this function adds two trees
    void delete_root(node<T>*); // this function deletes the values of the tree
    void copy(node<T>*&, node<T>*); // this function prints the values of a tree into another
    void push(node<T>*&, T); // this function adds value
    void vector_print(); // this function prints the values of the tree
};
#include "BST.hpp"
#endif
