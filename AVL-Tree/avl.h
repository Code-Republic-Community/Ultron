#ifndef AVL_H
#define AVL_H


template <typename T>
class AVL
{
public:
	AVL():root_ptr(nullptr) {}
	AVL(const AVL&);
	AVL(std::initializer_list<T>);
	AVL(AVL<T>&&);
	~AVL();
public:
	AVL& operator=(const AVL<T>&);
	AVL& operator=(AVL<T>&&);
	bool operator ==(const AVL<T>&) const;
	bool operator !=(const AVL<T>&) const;
private:
	struct Node
	{
	public:
		Node() :left(nullptr), right(nullptr), parent(nullptr), value() {}
		Node(T t) :left(nullptr), right(nullptr), value(t) {}
		Node* left;
		Node* right;
		Node* parent;
		T value;
	};
public:
	class Iterator
	{
	public:
		Iterator() = default;
		Iterator(Node* tmp) :m_it{tmp} {}
		Iterator(Node* ptr, Node* root) :m_it{ptr},new_root(root){}
	public:
		bool operator== (const Iterator&) const;
		bool operator!= (const Iterator&) const;
		Iterator& operator++();
		Iterator operator++(int);
		Iterator& operator--();
		Iterator operator--(int);
		const T& operator*() const;
	private:
		Node* m_it;
		Node* new_root;
	};
public:
	void insert(Node*&,T);
	int get_height(Node*) const;
	bool get_balance(Node*&);
	void erase(Node*&,int);
	size_t get_number_of_nodes(Node*) const;
	void inorder(Node*);
	void preorder(Node*);
	void postorder(Node*);
	void levelorder(Node*);
	T get_root_data(Node*&);
	AVL merge(AVL&,AVL&);
	bool contains(Node*&,const T&);
	Node* find(Node*&,const T&);
	void clear(Node*&);
	Iterator begin();
	Iterator end();
public:
	Node* root_ptr;
private:
	Node* rr_rotate(Node*&);
	Node* ll_rotate(Node*&);
	Node* rl_rotate(Node*&);
	Node* lr_rotate(Node*&);
	void balanced(Node*&);
	void help_merge(Node*&);
	void help_levelorder(Node*, int);
	void help_rot(Node*&);
	bool compare(Node*,Node*) const;
	int help_balance(Node*);
	int help_max(T,T) const;
	Node* help_copy(const Node*) const;
	Node* find_min(Node*);
	Node* find_max(Node*);
};

#include "avl.hpp"
#endif
