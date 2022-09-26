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
  HashTable<T> &operator=(const HashTable<T>  &other_list);
  bool operator!=(const HashTable<T> &obj);
  bool operator==(const HashTable<T> &obj);
  bool operator>(const HashTable<T> &obj);
  bool operator>=(const HashTable<T> &obj);
  bool operator<(const HashTable<T> &obj);
  bool operator<=(const HashTable<T> &obj);

  void resize();
  void insert(T value);
  [[nodiscard]] bool empty() const;
  void clear();
  [[nodiscard]] int size() const;
  int count(T value);
  void erase(const T &value);
  void swap(HashTable<T> &obj) {
    obj.array.swap(array);
    int count_transfer = obj._count;
    obj._count = _count;
    _count = count_transfer;
  };
  T find(const T &value);
  bool contain(const T &value) const;
  double load_factor();
  void merge(HashTable<T> &another_list);

private:
  struct node {
    T value;
    node* next;
    node() = default;
    explicit node(T init_value);
  };
  int _count = 0;
  std::vector<node*> array;
  int hashFunction(T value);
};

template<>
class HashTable <std::string> {
public:
  HashTable();
  HashTable(const HashTable<std::string> &other_list);
  HashTable(std::initializer_list<std::string> init_list);
  ~HashTable();

  friend std::ostream &operator<<(std::ostream &out, const HashTable<std::string> &obj);
  HashTable<std::string> &operator=(const HashTable<std::string>  &other_list);
  bool operator!=(const HashTable<std::string> &obj) const;
  bool operator==(const HashTable<std::string> &obj) const;
  bool operator>(const HashTable<std::string> &obj) const;
  bool operator>=(const HashTable<std::string> &obj) const;
  bool operator<(const HashTable<std::string> &obj);
  bool operator<=(const HashTable<std::string> &obj);

  void resize();
  void insert(std::string value);
  [[nodiscard]] bool empty() const;
  void clear();
  [[nodiscard]] int size() const;
  int count(std::string value);
  void erase(std::string value);
  void swap(HashTable<std::string> &obj) {
    obj.array.swap(array);
    int count_transfer = obj._count;
    obj._count = _count;
    _count = count_transfer;
  };
  std::string find(const std::string &value);
  [[nodiscard]] bool contain(const std::string &value) const;
  double load_factor();
  void merge(HashTable<std::string> &another_list);

private:
  struct node {
    std::string value;
    node* next{};
    node() = default;
    explicit node(std::string init_value);
  };
  int _count = 0;
  std::vector<node*> array;
  [[nodiscard]] int HashFunctionHorner(const std::string &s, int table_size, int key) const;
};

#include "HashTable.hpp"
#endif
