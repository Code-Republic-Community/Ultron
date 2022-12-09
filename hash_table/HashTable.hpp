#include "HashTable.h"

template<typename K, typename T>
HashTable<K, T>::node::node(K init_key, T init_value) {
  next = nullptr;
  key = init_key;
  value = init_value;
}

template<typename K, typename T>
HashTable<K, T>::node::node() {
  next = nullptr;
  key = nullptr;
  value = nullptr;
}

template<typename K, typename T>
HashTable<K, T>::HashTable() {
  array.resize(10);
}

template<typename K, typename T>
HashTable<K, T>::HashTable(int size) {
  array.resize(size);
}

template<typename K, typename T>
HashTable<K, T>::HashTable(const HashTable &object) {
  array.resize(object.array.size());
  this->_count = object.get_count();
  node* tmp;
  for(int i = 0; i < object.array.size(); i++) {
    tmp = object.array[i];
    while(tmp != nullptr) {
      this->append_to_array(i, tmp->key, tmp->value);
      tmp = tmp->next;
    }
  }
}

template<typename K, typename T>
HashTable<K, T>::HashTable(std::initializer_list<std::pair<K, T>> init_list) {
  array.resize(init_list.size());
  for (auto it = init_list.begin(); it != init_list.end(); ++it) {
    this->insert(it->first, it->second);
  }
}

template<typename K, typename T>
HashTable<K, T>::~HashTable() {
  if(_count == 0) {
    return;
  }
  node* tmp, *tmp1;
  for(int i = 0; i < array.size(); i++) {
    tmp = array[i];
    while(tmp != nullptr) {
      tmp1 = tmp;
      tmp = tmp->next;
      delete tmp1;
      tmp1 = nullptr;
    }
  }
}

template<typename K, typename T>
HashTable<K, T> &HashTable<K, T>::operator=(const HashTable<K, T> &obj) {
  node* tmp, *tmp1;
  if(!(this->empty())) {
    for(int i = 0; i < array.size(); i++) {
      tmp = array[i];
      while(tmp != nullptr) {
        tmp1 = tmp;
        tmp = tmp->next;
        delete tmp1;
        tmp1 = nullptr;
      }
    }
  }
  array.resize(obj.array.size());
  for(int i = 0; i < obj.array.size(); i++) {
    array[i] = nullptr;
  }
  for(int i = 0; i < obj.array.size(); i++) {
    tmp = obj.array[i];
    while(tmp != nullptr) {
      int index = std::hash<K>()(tmp->key) % array.size();
      if(array[index] == nullptr) {
        array[index] = new node(tmp->key, tmp->value);
      } else {
        tmp1 = array[index];
        while(tmp1->next != nullptr) {
          tmp1 = tmp1->next;
        }
        tmp1->next = new node(tmp->key, tmp->value);
      }
      tmp = tmp->next;
    }
  }
  return *this;
}

template<typename K, typename T>
bool HashTable<K, T>::operator==(const HashTable<K, T> &obj) const {
  node* tmp;
  if(array.size() != obj.array.size()) {
    return false;
  }
  for(int i = 0; i < obj.array.size(); i++) {
    tmp = array[i];
    while(tmp != nullptr) {
      if (array[i]->value != obj.array[i]->value || array[i]->key != obj.array[i]->key) {
        return false;
      }
      tmp = tmp->next;
    }
  }
  return true;
}

template<typename K, typename T>
bool HashTable<K, T>::operator!=(const HashTable<K, T> &obj) const {
  if(this == obj) {
    return false;
  }
  return true;
}

template<typename K, typename T>
bool HashTable<K, T>::operator>(const HashTable<K, T> &obj) const {
  if(array.size() > obj.array.size()) {
    return true;
  }
  return false;
}

template<typename K, typename T>
bool HashTable<K, T>::operator>=(const HashTable<K, T> &obj) const {
  if(array.size() >= obj.array.size()) {
    return true;
  }
  return false;
}

template<typename K, typename T>
bool HashTable<K, T>::operator<(const HashTable<K, T> &obj) const {
  if(array.size() < obj.array.size()) {
    return true;
  }
  return false;
}

template<typename K, typename T>
bool HashTable<K, T>::operator<=(const HashTable<K, T> &obj) const {
  if(array.size() <= obj.array.size()) {
    return true;
  }
  return false;
}

template<typename K, typename T>
void HashTable<K, T>::append_to_array(int i, K key, T value) {
  node *tmp = array[i];
  if (tmp == nullptr) {
    array[i] = new node(key, value);
  } else {
    while (tmp->next != nullptr) {
      tmp = tmp->next;
    }
    tmp->next = new node(key, value);
  }
}

template<typename K, typename T>
void HashTable<K, T>::insert(K key, T value) {
  int index = std::hash<K>()(key) % array.size();
  node* tmp = array[index];
  if(tmp == nullptr) {
    array[index] = new node(key, value);
  } else {
    while (tmp->key != key || tmp->next != nullptr) {
      tmp = tmp->next;
    }
    if(tmp->key == key) {
      tmp->value = value;
    } else if(tmp->next == nullptr) {
      tmp->next = new node(key, value);
    }
  }
  _count++;
  if(_count * 2> array.size()) {
    this->reformat();
  }
}

template<typename K, typename T>
void HashTable<K, T>::remove(K key, T value) {
  int index = std::hash<K>()(key) % array.size();
  node* tmp = array[index];
  if(tmp == nullptr) {
    return;
  }
  if(tmp->key == key && tmp->value == value) {
    array[index] = tmp->next;
    delete tmp;
    return;
  }
  while (tmp->next->value != value && tmp->next->key == key) {
    tmp = tmp->next;
    if(tmp->next == nullptr) {
      return;
    }
  }
  node* tmp1 = tmp->next;
  tmp->next = tmp->next->next;
  delete tmp1;
  _count--;
}

template<typename K, typename T>
void HashTable<K, T>::print_table() {
  if(_count == 0) {
    std::cout << "Table is empty" << std::endl;
    return;
  }
  node* tmp;
  std::cout << "Table started: " << std::endl;
  for(int i = 0; i < array.size(); i++) {
    std::cout << i << ": ";
    tmp = array[i];
    while(tmp != nullptr) {
      std::cout << tmp->key << ":" << tmp->value << " ";
      tmp = tmp->next;
    }
    std::cout << std::endl;
  }
  std::cout << "End of table." << std::endl;
}

template<typename K, typename T>
bool HashTable<K, T>::empty() const {
  if(_count != 0) {
    return false;
  }
  return true;
}

template<typename K, typename T>
bool HashTable<K, T>::contains(K key) const {
  int index = std::hash<K>()(key) % array.size();
  node* tmp = array[index];
  if(tmp == nullptr) {
    return false;
  }
  return true;
}

template<typename K, typename T>
void HashTable<K, T>::emplace(K key, const T &value) {
  int index = std::hash<K>()(key) % array.size();
  node* tmp = array[index];
  if(tmp == nullptr) {
    array[index] = new node(key, value);
  } else {
    while (tmp->key != key || tmp->next != nullptr) {
      tmp = tmp->next;
    }
    if(tmp->key == key) {
      tmp->value = value;
    } else if(tmp->next == nullptr) {
      tmp->next = new node(key, value);
    }
  }
  _count++;
  if(_count * 2> array.size()) {
    this->reformat();
  }
}

template<typename K, typename T>
void HashTable<K, T>::reformat() {
  std::vector<node *> new_array;
  new_array.resize(array.size()*2);
  node* tmp, *tmp1;
  for(int i = 0; i < array.size(); i++) {
    tmp = array[i];
    while(tmp != nullptr) {
      int index = std::hash<K>()(tmp->key) % new_array.size();
      if(new_array[index] == nullptr) {
        new_array[index] = new node(tmp->key, tmp->value);
      } else {
        tmp1 = new_array[index];
        while(tmp1->next != nullptr) {
          tmp1 = tmp1->next;
        }
        tmp1->next = new node(tmp->key, tmp->value);
      }
      tmp = tmp->next;
    }
  }
  array = new_array;
}

template<typename K, typename T>
int HashTable<K, T>::hash_function(K key) {
  return std::hash<K>()(key) % this->array.size();
}

template<typename K, typename T>
void HashTable<K, T>::find(K key) const {
  int index = std::hash<K>()(key) % this->array.size();
  node* tmp = array[index];
  std::cout << "With key " << key << " I find this: ";
  while(tmp->key != key) {
    tmp = tmp->next;
  }
  std::cout << tmp->value;
}

template<typename U, typename Y>
std::ostream &operator<<(std::ostream &out, const HashTable<U, Y> &obj) {
  typename HashTable<U, Y>::node* tmp;
  if(obj._count == 0) {
    std::cout << "Table is empty" << std::endl;
    return out;
  }
  std::cout << "Table started: " << std::endl;
  for(int i = 0; i < obj.array.size(); i++) {
    std::cout << i << ": ";
    tmp = obj.array[i];
    while(tmp != nullptr) {
      std::cout << tmp->key << ":" << tmp->value << " ";
      tmp = tmp->next;
    }
    std::cout << std::endl;
  }
  std::cout << "End of table." << std::endl;
  return out;
}

template<typename K, typename T>
void HashTable<K, T>::swap(HashTable<K, T> &obj) {
  HashTable<K, T> a = *this;
  *this = obj;
  obj = a;
}

template<typename K, typename T>
void HashTable<K, T>::merge(const HashTable<K, T> &obj) {
  node* tmp, *tmp1;
  bool flag = false;
  for(int i = 0; i < obj.array.size(); i++) {
    tmp = obj.array[i];
    while(tmp != nullptr) {
      int index = std::hash<K>()(tmp->key) % this->array.size();
      tmp1 = array[index];
      while(tmp1 != nullptr) {
        if(tmp1->key == tmp->key) {
          tmp1->value = tmp->value;
          flag = true;
          break;
        }
        tmp1 = tmp->next;
      }
      if(!flag) {
        this->insert(tmp->key, tmp->value);
      }
      flag = false;
      tmp = tmp->next;
    }
  }
}

template<typename K, typename T>
void HashTable<K, T>::erase() {
  node* tmp, *tmp1;
  for(int i = 0; i < array.size(); i++) {
    tmp = array[i];
    while(tmp != nullptr) {
      tmp1 = tmp;
      tmp = tmp->next;
      delete tmp1;
      tmp1 = nullptr;
    }
  }
  _count = 0;
}
