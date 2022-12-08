#ifndef UNTITLED_HASHTABLE_H
#define UNTITLED_HASHTABLE_H

#include <iostream>
#include <vector>

template<typename K, typename T>
class HashTable {
public:
  HashTable();
  explicit HashTable(int size);

private:
  struct node {
    K key;
    T value;
    node *next{};
    node() = default;
    node(K init_key, T init_value);
    T get_value(){return value;}
  };

  int _count = 0;
  std::vector<node *> array;
public:
  void insert(K key, T value);
  void remove(K key, T value);
  void printTable();
};


#include "HashTable.hpp"
#endif
