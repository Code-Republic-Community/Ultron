#include "HashTable.h"

template<typename T>
HashTable<T>::HashTable() {
  array.resize(10);
  _count = 0;
}

template<typename T>
HashTable<T>::HashTable(const HashTable<T> &other_list) {
  node *tmp;
  node *tmp1;
  array.resize(other_list.array.size());
  for(int i = 0; i < array.size(); i++) {
    tmp = other_list.array[i];
    if (tmp != nullptr) {
      array[i] = new node(tmp->value);
      tmp1 = array[i];
      while (tmp->next != nullptr) {
        tmp = tmp->next;
        tmp1->next = new node(tmp->value);
        tmp1 = tmp1->next;
      }
    }
  }
}

template<typename T>
HashTable<T>::HashTable(std::initializer_list<T> init_list) {
  array.resize(init_list.size());
  node *tmp;
  for (auto it = init_list.begin(); it != init_list.end(); ++it) {
    _count++;
    int index = std::hash<T>()(*it) % array.size();
    tmp = array[index];
    if (tmp == nullptr) {
      array[index] = new node(*it);
    } else {
      array[index] = new node(*it);
      array[index]->next = tmp;
    }
    if (_count * 2 > array.size()) {
      resize();
    }
  }
}

template<typename T>
HashTable<T>::~HashTable() {
  if(!(this->empty())) {
    node *tmp;
    for (int i = 0; i < array.size(); i++) {
      while (array[i] != nullptr) {
        tmp = array[i];
        array[i] = tmp->next;
        //delete tmp; // conflict in merge time
        tmp = nullptr;
      }
    }
    tmp = nullptr;
    _count = 0;
  }
}


template<typename T>
HashTable<T>::node::node(T init_value)  {
  value = init_value;
  next = nullptr;
}

template<typename T>
HashTable<T>::node::node()= default;


template<typename T>
bool HashTable<T>::operator>(HashTable<T> &obj) {
  if(_count > obj.size()) {
    return true;
  }
  return false;
}

template<typename T>
bool HashTable<T>::operator>=(HashTable<T> &obj) {
  if(_count >= obj.size()) {
    return true;
  }
  return false;
}

template<typename T>
bool HashTable<T>::operator<(HashTable<T> &obj) {
  if(!(this>=obj.size())) {
    return true;
  }
  return false;
}

template<typename T>
bool HashTable<T>::operator<=(HashTable<T> &obj) {
  if(_count < obj.size() || _count == obj.size()) {
    return true;
  }
  return false;
}

template<typename T>
bool HashTable<T>::operator==(HashTable<T> &obj) {
  if(_count == obj.size()) {
    return true;
  }
  return false;
}

template<typename T>
bool HashTable<T>::operator!=(HashTable<T> &obj) {
  if(!(this == obj)) {
    return true;
  }
  return false;
}

template<typename T>
HashTable<T> &HashTable<T>::operator=(HashTable<T> other_list) {
  node *tmp;
  node *tmp1;
  if(!(this->empty())) {
    node *tmp;
    for (int i = 0; i < array.size(); i++) {
      while (array[i] != nullptr) {
        tmp = array[i];
        array[i] = tmp->next;
        delete tmp;
        tmp = nullptr;
      }
    }
    tmp = nullptr;
    _count = 0;
  }
  array.resize(other_list.array.size());
  for(int i = 0; i < array.size(); i++) {
    tmp = other_list.array[i];
    if (tmp != nullptr) {
      array[i] = new node(tmp->value);
      tmp1 = array[i];
      while (tmp->next != nullptr) {
        tmp = tmp->next;
        tmp1->next = new node(tmp->value);
        tmp1 = tmp1->next;
      }
    }
  }
  return *this;
}

template<typename T>
std::ostream &operator<<(std::ostream &out, const HashTable<T> &obj) {
  typename HashTable<T>::node *tmp;
  for(int i = 0; i < obj.array.size(); i++){
    tmp = obj.array[i];
    if(tmp != nullptr) {
      while (tmp != nullptr) {
        std::cout << tmp->value << " ";
        tmp = tmp->next;
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

template<typename T>
void HashTable<T>::clear() {
  if(!(this->empty())) {
    node *tmp;
    for (int i = 0; i < array.size(); i++) {
      while (array[i] != nullptr) {
        tmp = array[i];
        array[i] = tmp->next;
        delete tmp;
        tmp = nullptr;
      }
    }
    tmp = nullptr;
    _count = 0;
    array.resize(10);
  }
}

template<typename T>
double HashTable<T>::load_factor() {
  int counter = 0;
  double average = 0;
  node *tmp;
  for(int i = 0; i < array.size(); i++) {
    tmp = array[i];
    while(tmp != nullptr) {
      counter++;
      tmp = tmp->next;
    }
    average += counter;
    counter = 0;
  }
  average = average / array.size();
  return average;
}

template<typename T>
int HashTable<T>::count(std::string value) {
  int counter = 0;
  if(!(this->empty())) {
    int index = HashFunctionHorner(value, this->array.size(), this->array.size() - 1);
    node *tmp = array[index];
    if(tmp != nullptr) {
      counter++;
    }
    while(tmp != nullptr) {
      counter++;
      tmp = tmp->next;
    }
    return counter;
  }
  return 0;
}


template<typename T>
int HashTable<T>::count(T value) {
  int counter = 0;
  if(!(this->empty())) {
    int index = std::hash<T>()(value) % array.size();
    node *tmp = array[index];
    if(tmp != nullptr) {
      counter++;
    }
    while(tmp != nullptr) {
      counter++;
      tmp = tmp->next;
    }
    return counter;
  }
  return 0;
}

template<typename T>
std::string HashTable<T>::find(std::string value) {
  if(!(this->empty())) {
    int index = HashFunctionHorner(value, this->array.size(), this->array.size() - 1);
    return array[index]->value;
  }
}

template<typename T>
T HashTable<T>::find(T value) {
  if(!(this->empty())) {
    int index = std::hash<T>()(value) % array.size();
    return array[index]->value;
  }
  return 0;
}

template<typename T>
void HashTable<T>::merge(HashTable<T> &another_list) {
  node *tmp;
  for(int i = 0; i < another_list.size(); i++) {
    tmp = another_list.array[i];
    while(tmp != nullptr) {
      if (!(this->contain(tmp->value))) {
        this->insert(tmp->value);
      }
      tmp = tmp->next;
    }
  }
}
