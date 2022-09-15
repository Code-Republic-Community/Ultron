#include "HashTable.h"

template<typename T>
HashTable<T>::HashTable() {
  array.resize(10);
  _count = 0;
}

template<typename T>
HashTable<T>::node::node(T init_value)  {
  value = init_value;
  next = nullptr;
}

template<typename T>
HashTable<T>::node::node()= default;

template<typename T>
std::ostream &operator<<(std::ostream &out, const HashTable<T> &obj) {
  for(int i = 0; i < obj.array.size(); i++){
    typename HashTable<T>::node *temp = obj.array[i];
    if(temp != nullptr) {
      while (temp != nullptr) {
        std::cout << temp->value << " ";
        temp = temp->next;
      }
      std::cout << std::endl;
    }
  }

  return out;
}

template<typename T>
int HashTable<T>::HashFunctionHorner(const std::string &s, int table_size, const int key) {
  int hash_result = 0;
  for (int i = 0; s[i] != s.size(); ++i)
    hash_result = (key * hash_result + s[i]) % table_size;
  hash_result = (hash_result * 2 + 1) % table_size;
  return hash_result;
}

template<typename T>
void HashTable<T>::resize() {
  int N = array.size();
  N *= 2;
  std::vector<node*> new_array;
  new_array.resize(N);
  node *tmp;
  for(int i = 0; i < array.size(); i++) {
    tmp = array[i];
    while(tmp != nullptr) {
      new_array[std::hash<T>()(tmp->value) % new_array.size()] = tmp;
      tmp = tmp->next;
    }
  }
  array.swap(new_array);
}

template<typename T>
void HashTable<T>::insert(std::string &value) {
  _count++;
  int index = HashFunctionHorner(value, this->array.size(), this->array.size() - 1);
  node *tmp = array[index];
  if(tmp == nullptr) {
    array[index] = new node(value);
  } else {
    array[index] = new node(value);
    array[index]->next = tmp;
  }
  if(_count * 2 > array.size()) {
    resize();
  }
}

template<typename T>
void HashTable<T>::insert(T value) {
  _count++;
  int index = std::hash<T>()(value) % array.size();
  node *tmp = array[index];
  if(tmp == nullptr) {
    array[index] = new node(value);
  } else {
    array[index] = new node(value);
    array[index]->next = tmp;
  }
  if(_count * 2 > array.size()) {
    resize();
  }
}

template<typename T>
bool HashTable<T>::empty() const {
  if(_count == 0) {
    return true;
  }
  return false;
}

template<typename T>
int HashTable<T>::size() {
  return _count;
}

template<typename T>
bool HashTable<T>::contain(T value) const {
  int index = std::hash<T>()(value) % array.size();
  node *tmp = array[index];
  while(tmp != nullptr) {
    if(tmp->value == value) {
      return true;
    }
    tmp = tmp->next;
  }
  return false;
}

