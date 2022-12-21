#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>

template<typename K, typename T>
class HashTable {
public:
  HashTable();
  explicit HashTable(int size);
  HashTable(const HashTable &obj);
  HashTable(HashTable &&obj) noexcept ;
  HashTable(const std::initializer_list<std::pair<K, T>> &init_list);
  ~HashTable();

public:
  template<typename U, typename Y>
  friend std::ostream &operator<<(std::ostream &out, const HashTable<U, Y> &obj);
  HashTable<K, T> &operator=(const HashTable<K, T>  &obj);
  HashTable<K, T> &operator=(HashTable<K, T> &&obj) noexcept;
  T operator[](const K &key) const;
  T& operator[](K &&key);

public:
  bool operator==(const HashTable<K, T> &obj) const;
  bool operator!=(const HashTable<K, T> &obj) const;
  bool operator>(const HashTable<K, T> &obj) const; // Checking by size only
  bool operator>=(const HashTable<K, T> &obj) const; // Checking by size only
  bool operator<(const HashTable<K, T> &obj) const; // Checking by size only
  bool operator<=(const HashTable<K, T> &obj) const; // Checking by size only

public:
  [[nodiscard]] int get_count() const { return _count; }
  [[nodiscard]] bool empty() const;
  [[nodiscard]] bool contains(K key) const;
  T find(K key) const;
  void insert(K key, T value);
  void emplace(K key, const T &value);
  void reformat();
  void remove(K key, T value);
  int hash_function(K key); // returns index with argument key for current table
  void swap(HashTable<K, T> &obj);
  void merge(const HashTable<K, T> &obj);
  void erase();

private:
  void append_to_array(int i, K key, T value);

private:
  class Node {
  public:
    K key;
    T value;
    Node *next;
  public:
    Node();
    Node(K init_key, T init_value);
  }; // NODE ENDED HERE

private:
  int _count = 0;
  std::vector<Node *> _array;
};

#include "hashtable.hpp"

#endif // HASHTABLE_H
