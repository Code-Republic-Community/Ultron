#ifndef UNTITLED_HASHTABLE_H
#define UNTITLED_HASHTABLE_H

#include <iostream>
#include <vector>

template<typename K, typename T>
class HashTable {
public:
  HashTable();
  explicit HashTable(int size);
  HashTable(const HashTable &object);
  HashTable(std::initializer_list<std::pair<K, T>> init_list);
  ~HashTable();

  template<typename U, typename Y>
  friend std::ostream &operator<<(std::ostream &out, const HashTable<U, Y> &obj);
  HashTable<K, T> &operator=(const HashTable<K, T>  &obj);
  bool operator==(const HashTable<K, T> &obj) const;
  bool operator!=(const HashTable<K, T> &obj) const;
  bool operator>(const HashTable<K, T> &obj) const; // Checking by size only
  bool operator>=(const HashTable<K, T> &obj) const; // Checking by size only
  bool operator<(const HashTable<K, T> &obj) const; // Checking by size only
  bool operator<=(const HashTable<K, T> &obj) const; // Checking by size only


  [[nodiscard]] int get_count() const { return _count; }
  [[nodiscard]] bool empty() const;
  [[nodiscard]] bool contains(K key) const;
  void find(K key) const;
  void insert(K key, T value);
  void emplace(K key, const T &value);
  void reformat();
  void remove(K key, T value);
  void print_table();
  int hash_function(K key); // returns index with argument key for current table
  void swap(HashTable<K, T> &obj);
  void merge(const HashTable<K, T> &obj);
  void erase();

private:
  struct node {
    K key;
    T value;
    node *next{};

    node();
    node(K init_key, T init_value);

    T get_value() { return value; }
    K get_key() { return key; }
  };
  int _count = 0;
  std::vector<node *> array;

  void append_to_array(int i, K key, T value);
};


#include "HashTable.hpp"

#endif
