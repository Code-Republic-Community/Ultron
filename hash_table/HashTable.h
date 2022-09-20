#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <vector>

template<typename T>
class HashTable {
public:
  HashTable();
  HashTable(const HashTable<T> &other_list);
  HashTable(std::initializer_list<T> init_list);
  ~HashTable();

  template<typename U>
  friend std::ostream &operator<<(std::ostream &out, const HashTable<U> &obj);
  HashTable<T> &operator=(HashTable<T> other_list);
  bool operator!=(HashTable<T> &obj);
  bool operator==(HashTable<T> &obj);
  bool operator>(HashTable<T> &obj);
  bool operator>=(HashTable<T> &obj);
  bool operator<(HashTable<T> &obj);
  bool operator<=(HashTable<T> &obj);
  
  int HashFunctionHorner(const std::string &s, int table_size, int key);
  void resize();
  void insert(std::string &s);
  void insert(T value);
  bool empty() const;
  void clear();
  int size();
  int count(std::string value);
  int count(T value);
  void erase(std::string value);
  void erase(T value);
  void swap(HashTable<T> &obj) {
    obj.array.swap(array);
    int count_transfer = obj._count;
    obj._count = _count;
    _count = count_transfer;
  };
  std::string find(std::string value);
  T find(T value);
  bool contain(T value) const;
  double load_factor();
  void merge(HashTable<T> &another_list);

private:
  struct node {
    T value;
    node* next;
    node();
    explicit node(T init_value);
  };
  int _count = 0;
  std::vector<node*> array;
};

#endif
