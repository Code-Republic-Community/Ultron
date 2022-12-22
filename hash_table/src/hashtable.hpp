#include "hashtable.h"

template<typename K, typename T>
HashTable<K, T>::Node::Node(K init_key, T init_value) {
  _next = nullptr;
  _key = init_key;
  _hash = hash(init_key);
  _value = init_value;
}

template<typename K, typename T>
HashTable<K, T>::HashTable() {
  _array.resize(2);
}

template<typename K, typename T>
HashTable<K, T>::HashTable(int size) {
  _array.resize(size);
}

template<typename K, typename T>
HashTable<K, T>::HashTable(const HashTable &object) {
  _array.resize(object._array.size());
  this->_count = object._count;
  Node* tmp;
  for(int i = 0; i < object._array.size(); i++) {
    tmp = object._array[i];
    while(tmp != nullptr) {
      this->append_to_array(i, tmp->_key, tmp->_value);
      tmp = tmp->_next;
    }
  }
}

template<typename K, typename T>
HashTable<K, T>::HashTable(HashTable &&obj) noexcept{
  _array = obj.array;
  _count = obj._count();
  obj._array = nullptr;
  obj._count = nullptr;
  obj = nullptr;
}

template<typename K, typename T>
HashTable<K, T>::HashTable(const std::initializer_list<std::pair<K, T>> &init_list) {
  _array.resize(init_list.size());
  for (auto it = init_list.begin(); it != init_list.end(); ++it) {
    this->insert(it->first, it->second);
  }
}

template<typename K, typename T>
HashTable<K, T>::~HashTable() {
  if(_count == 0) {
    return;
  }
  Node* tmp, *tmp1;
  for(int i = 0; i < _array.size(); i++) {
    tmp = _array[i];
    while(tmp != nullptr) {
      tmp1 = tmp;
      tmp = tmp->_next;
      delete tmp1;
      tmp1 = nullptr;
    }
  }
}

template<typename K, typename T>
HashTable<K, T> &HashTable<K, T>::operator=(const HashTable<K, T> &obj) {
  Node* tmp, *tmp1;
  if(!(this->empty())) {
    for(int i = 0; i < _array.size(); i++) {
      tmp = _array[i];
      while(tmp != nullptr) {
        tmp1 = tmp;
        tmp = tmp->_next;
        delete tmp1;
        tmp1 = nullptr;
      }
    }
  }
  _array.resize(obj._array.size());
  for(int i = 0; i < obj._array.size(); i++) {
    _array[i] = nullptr;
  }
  for(int i = 0; i < obj._array.size(); i++) {
    tmp = obj._array[i];
    while(tmp != nullptr) {
      int index = hash(tmp->_key) % _array.size();
      if(_array[index] == nullptr) {
        _array[index] = new Node(tmp->_key, tmp->_value);
      } else {
        tmp1 = _array[index];
        while(tmp1->_next != nullptr) {
          tmp1 = tmp1->_next;
        }
        tmp1->_next = new Node(tmp->_key, tmp->_value);
      }
      tmp = tmp->_next;
    }
  }
  return *this;
}

template<typename K, typename T>
HashTable<K, T> &HashTable<K, T>::operator=(HashTable<K, T> &&obj)  noexcept {
  Node* tmp, *tmp1;
  if(!(this->empty())) {
    for(int i = 0; i < _array.size(); i++) {
      tmp = _array[i];
      while(tmp != nullptr) {
        tmp1 = tmp;
        tmp = tmp->_next;
        delete tmp1;
        tmp1 = nullptr;
      }
    }
  }
  _array = obj._array;
  _count = obj._count();
  obj._array = nullptr;
  obj._count = nullptr;
  obj = nullptr;
}

template<typename K, typename T>
bool HashTable<K, T>::operator==(const HashTable<K, T> &obj) const {
  Node* tmp;
  if(_array.size() != obj._array.size()) {
    return false;
  }
  for(int i = 0; i < obj._array.size(); i++) {
    tmp = _array[i];
    while(tmp != nullptr) {
      if (_array[i]->_value != obj._array[i]->_value || _array[i]->_key != obj._array[i]->_key) {
        return false;
      }
      tmp = tmp->_next;
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
  if(_array.size() > obj._array.size()) {
    return true;
  }
  return false;
}

template<typename K, typename T>
bool HashTable<K, T>::operator>=(const HashTable<K, T> &obj) const {
  if(_array.size() >= obj._array.size()) {
    return true;
  }
  return false;
}

template<typename K, typename T>
bool HashTable<K, T>::operator<(const HashTable<K, T> &obj) const {
  if(_array.size() < obj._array.size()) {
    return true;
  }
  return false;
}

template<typename K, typename T>
bool HashTable<K, T>::operator<=(const HashTable<K, T> &obj) const {
  if(_array.size() <= obj._array.size()) {
    return true;
  }
  return false;
}

template<typename K, typename T>
void HashTable<K, T>::append_to_array(int i, K key, T value) {
  Node *tmp = _array[i];
  if (tmp == nullptr) {
    _array[i] = new Node(key, value);
  } else {
    while (tmp->_next != nullptr) {
      tmp = tmp->_next;
    }
    tmp->_next = new Node(key, value);
  }
}

template<typename K, typename T>
void HashTable<K, T>::insert(K key, T value) {
  int index = hash(key) % _array.size();
  Node* tmp = _array[index];
  if(tmp == nullptr) {
    _array[index] = new Node(key, value);
  } else {
    while (tmp->_key != key && tmp->_next != nullptr) {
      tmp = tmp->_next;
    }
    if(tmp->_key == key) {
      tmp->_value = value;
    } else if(tmp->_next == nullptr) {
      tmp->_next = new Node(key, value);
    }
  }
  _count++;
  if(_count * 2> _array.size()) {
    this->reformat();
  }
}

template<typename K, typename T>
void HashTable<K, T>::remove(K key, T value) {
  int index = hash(key) % _array.size();
  Node* tmp = _array[index];
  if(tmp == nullptr) {
    return;
  }
  if(tmp->_key == key && tmp->_value == value) {
    _array[index] = tmp->_next;
    delete tmp;
    return;
  }
  while (tmp->_next->_value != value && tmp->_next->_key == key) {
    tmp = tmp->_next;
    if(tmp->_next == nullptr) {
      return;
    }
  }
  Node* tmp1 = tmp->_next;
  tmp->_next = tmp->_next->_next;
  delete tmp1;
  _count--;
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
  int index = hash(key) % _array.size();
  Node* tmp = _array[index];
  if(tmp == nullptr) {
    return false;
  }
  return true;
}

template<typename K, typename T>
void HashTable<K, T>::emplace(K key, const T &value) {
  int index = hash(key) % _array.size();
  Node* tmp = _array[index];
  if(tmp == nullptr) {
    _array[index] = new Node(key, value);
  } else {
    while (tmp->_key != key || tmp->_next != nullptr) {
      tmp = tmp->_next;
    }
    if(tmp->_key == key) {
      tmp->_value = value;
    } else if(tmp->_next == nullptr) {
      tmp->_next = new Node(key, value);
    }
  }
  _count++;
  if(_count * 2> _array.size()) {
    this->reformat();
  }
}

template<typename K, typename T>
void HashTable<K, T>::reformat() {
  std::vector<Node *> new_array;
  new_array.resize(_array.size()*2);
  Node* tmp, *tmp1;
  for(int i = 0; i < _array.size(); i++) {
    tmp = _array[i];
    while(tmp != nullptr) {
      int index = tmp->_hash % new_array.size();
      if(new_array[index] == nullptr) {
        new_array[index] = new Node(tmp->_key, tmp->_value);
      } else {
        tmp1 = new_array[index];
        while(tmp1->_next != nullptr) {
          tmp1 = tmp1->_next;
        }
        tmp1->_next = new Node(tmp->_key, tmp->_value);
      }
      tmp = tmp->_next;
    }
  }
  _array = new_array;
}

template<typename K, typename T>
int HashTable<K, T>::hash_function(K key) {
  return hash(key) % this->_array.size();
}

template<typename K, typename T>
T HashTable<K, T>::find(K key) const {
  int index = hash(key) % this->_array.size();
  Node* tmp = _array[index];
  while(tmp->_key != key) {
    tmp = tmp->_next;
  }
  return tmp->_value;
}

template<typename U, typename Y>
std::ostream &operator<<(std::ostream &out, const HashTable<U, Y> &obj) {
  typename HashTable<U, Y>::Node* tmp;
  if(obj._count == 0) {
    std::cout << "Table is empty" << std::endl;
    return out;
  }
  std::cout << "Table started: " << std::endl;
  for(int i = 0; i < obj._array.size(); i++) {
    std::cout << i << ": ";
    tmp = obj._array[i];
    while(tmp != nullptr) {
      std::cout << tmp->_key << ":" << tmp->_value << " ";
      tmp = tmp->_next;
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
  Node* tmp, *tmp1;
  bool flag = false;
  for(int i = 0; i < obj._array.size(); i++) {
    tmp = obj._array[i];
    while(tmp != nullptr) {
      int index = hash(tmp->_key) % this->_array.size();
      tmp1 = _array[index];
      while(tmp1 != nullptr) {
        if(tmp1->_key == tmp->_key) {
          tmp1->_value = tmp->_value;
          flag = true;
          break;
        }
        tmp1 = tmp->_next;
      }
      if(!flag) {
        this->insert(tmp->_key, tmp->_value);
      }
      flag = false;
      tmp = tmp->_next;
    }
  }
}

template<typename K, typename T>
void HashTable<K, T>::erase() {
  Node* tmp, *tmp1;
  for(int i = 0; i < _array.size(); i++) {
    tmp = _array[i];
    while(tmp != nullptr) {
      tmp1 = tmp;
      tmp = tmp->_next;
      delete tmp1;
      tmp1 = nullptr;
    }
  }
  _count = 0;
}

template<typename K, typename T>
T HashTable<K, T>::operator[](const K &key) const {
  return this->find(key);
}

template<typename K, typename T>
T& HashTable<K, T>::operator[](K &&key){
  int index = hash(key) % this->_array.size();
  Node* tmp = _array[index];
  while(tmp->_key != key) {
    tmp = tmp->_next;
  }
  return tmp->_value;
}

template<typename K, typename T>
unsigned long long HashTable<K, T>::hash(const std::string& key) {
  const int p = 31;
  const int m = 1e9 + 9;
  long long hash_value = 0;
  long long p_pow = 1;
  for (char c : key) {
    hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
    p_pow = (p_pow * p) % m;
  }
  return hash_value;
}

template<typename K, typename T>
unsigned long long HashTable<K, T>::hash(const int &key) {
  return key;
}

template<typename K, typename T>
unsigned long long HashTable<K, T>::hash(const float &key) {
  return key * 100000;
}

template<typename K, typename T>
unsigned long long HashTable<K, T>::hash(const double &key) {
  return std::hash<K>()(key);
}
