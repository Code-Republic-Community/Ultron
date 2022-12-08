#include "HashTable.h"

template<typename K, typename T>
HashTable<K, T>::HashTable() {
  array.resize(10);
}

template<typename K, typename T>
HashTable<K, T>::HashTable(int size) {
  array.resize(size);
}

template<typename K, typename T>
HashTable<K, T>::node::node(K init_key, T init_value) {
  next = nullptr;
  key = init_key;
  value = init_value;
}

template<typename K, typename T>
void HashTable<K, T>::insert(K key, T value) {
  int index = std::hash<K>()(key) % array.size();
  node* tmp = array[index];
  if(tmp != nullptr) {
    while (tmp->next != nullptr) {
      tmp = tmp->next;
    }
    tmp->next = new node(key, value);
  } else {
    array[index] = new node(key, value);
  }
  _count++;
  if(_count * 2> array.size()) {
    //*this.reformat; // TODO::writeReformatFunction
  }
}

template<typename K, typename T>
void HashTable<K, T>::remove(K key, T value) {
  int index = std::hash<K>()(key) % array.size();
  node* tmp = array[index];
  if(tmp->value == value) {
    array[index] = tmp->next;
    return;
  }
  while (tmp->next->value != value) {
    tmp = tmp->next;
    if(tmp->next == nullptr) {
      return;
    }
  }
  delete tmp->next;
  tmp->next = tmp->next->next;
  _count--;
}

template<typename K, typename T>
void HashTable<K, T>::printTable() {
  node* tmp = array[2];
 // std::cout << tmp->get_value();
}
