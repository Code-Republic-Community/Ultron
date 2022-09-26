template<typename T>
HashTable<T>::HashTable() : _count(0) {
  array.resize(10);
}

template<typename T>
HashTable<T>::HashTable(const HashTable<T> &other_list) {
  node *tmp;
  node *tmp1;
  array.resize(other_list.array.size());
  for (int i = 0; i < array.size(); i++) {
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
  array.resize(10);
  for (auto it = init_list.begin(); it != init_list.end(); ++it) {
    this->insert(*it);
  }
}

template<typename T>
HashTable<T>::~HashTable() {
  if (!(this->empty())) {
    node *tmp;
    for (int i = 0; i < array.size(); i++) {
      while (array[i] != nullptr) {
        tmp = array[i];
        array[i] = tmp->next;
        delete tmp; // conflict in merge time
        tmp = nullptr;
      }
    }
    tmp = nullptr;
    _count = 0;
  }
}


template<typename T>
HashTable<T>::node::node(T init_value) {
  value = init_value;
  next = nullptr;
}

// All operators compare objects by element count
// If first hashtable has more elements, function return true.
// And this principe works on all operators
template<typename T>
bool HashTable<T>::operator>(const HashTable<T> &obj) {
  if (_count > obj.size()) {
    return true;
  }
  return false;
}

template<typename T>
bool HashTable<T>::operator>=(const HashTable<T> &obj) {
  if (_count >= obj.size()) {
    return true;
  }
  return false;
}

template<typename T>
bool HashTable<T>::operator<(const HashTable<T> &obj) {
  if (_count < obj.size()) {
    return true;
  }
  return false;
}

template<typename T>
bool HashTable<T>::operator<=(const HashTable<T> &obj) {
  if (_count <= obj.size()) {
    return true;
  }
  return false;
}

template<typename T>
bool HashTable<T>::operator==(const HashTable<T> &obj) {
  if (_count == obj.size()) {
    return true;
  }
  return false;
}

template<typename T>
bool HashTable<T>::operator!=(const HashTable<T> &obj) {
  if (_count != obj.size()) {
    return true;
  }
  return false;
}

template<typename T>
HashTable<T> &HashTable<T>::operator=(const HashTable<T> &other_list) {
  node *tmp;
  node *tmp1;
  if (!(this->empty())) {
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
  for (int i = 0; i < array.size(); i++) {
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

template<typename U>
std::ostream &operator<<(std::ostream &out, const HashTable<U> &obj) {
  typename HashTable<U>::node *tmp;
  for (int i = 0; i < obj.array.size(); i++) {
    tmp = obj.array[i];
    if (tmp != nullptr) {
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
void HashTable<T>::resize() {
  unsigned int N = array.size();
  N *= 2;
  std::vector<node *> new_array;
  new_array.resize(N);
  node *tmp;
  for (int i = 0; i < array.size(); i++) {
    tmp = array[i];
    while (tmp != nullptr) {
      new_array[std::hash<T>()(tmp->value) % new_array.size()] = tmp;
      tmp = tmp->next;
    }
  }
  array = new_array;
}

template<typename T>
void HashTable<T>::insert(T value) {
  if (!(this->contain(value))) {
    _count++;
    int index = std::hash<T>()(value) % array.size();
    node *tmp = array[index];
    if (tmp == nullptr) {
      array[index] = new node(value);
    } else {
      array[index] = new node(value);
      array[index]->next = tmp;
    }
    if (_count * 2 > array.size()) {
      resize();
    }
  }
}

template<typename T>
bool HashTable<T>::empty() const {
  if (_count == 0) {
    return true;
  }
  return false;
}

template<typename T>
int HashTable<T>::size() const{
  return _count;
}

template<typename T>
bool HashTable<T>::contain(const T &value) const {
  if(array.size() == 0) {
    return false;
  }
  int index = std::hash<T>()(value) % array.size();
  node *tmp = array[index];
  while (tmp != nullptr) {
    if (tmp->value == value) {
      return true;
    }
    tmp = tmp->next;
  }
  return false;
}

template<typename T>
void HashTable<T>::clear() {
  if (!(this->empty())) {
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
  for (int i = 0; i < array.size(); i++) {
    tmp = array[i];
    while (tmp != nullptr) {
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
int HashTable<T>::count(T value) {
  int counter = 0;
  if (!(this->empty())) {
    int index = std::hash<T>()(value) % array.size();
    node *tmp = array[index];
    if (tmp != nullptr) {
      counter++;
    }
    while (tmp != nullptr) {
      counter++;
      tmp = tmp->next;
    }
    return counter;
  }
  return 0;
}

template<typename T>
T HashTable<T>::find(const T &value) {
  if (!(this->empty())) {
    int index = std::hash<T>()(value) % array.size();
    return array[index]->value;
  }
  return 0;
}

template<typename T>
void HashTable<T>::erase(const T &value) {
  int index = std::hash<T>()(value) % array.size();
  node *tmp = array[index];
  if (tmp->next == nullptr && tmp->value == value) {
    tmp = nullptr;
  }
  while (tmp != nullptr) {
    if (tmp->next != nullptr && tmp->next->value == value) {
      tmp->next = tmp->next->next;
      break;
    }
    tmp = tmp->next;
  }
}

//TODO fix the bug
template<typename T>
void HashTable<T>::merge(HashTable<T> &another_list) {
  node *tmp;
  for (int i = 0; i <= another_list.size(); i++) {
    tmp = another_list.array[i];
    while (tmp != nullptr) {
      this->insert(tmp->value);
      tmp = tmp->next;
    }
  }
}

template<typename T>
int HashTable<T>::hashFunction(T value) {
  return 0;
}


HashTable<std::string>::HashTable() : _count(0) {
  array.resize(10);
}

HashTable<std::string>::HashTable(const  HashTable<std::string> &other_list) {
  node *tmp;
  node *tmp1;
  array.resize(other_list.array.size());
  for (int i = 0; i < array.size(); i++) {
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

HashTable<std::string>::HashTable(std::initializer_list<std::string> init_list) {
  array.resize(10);
  for (auto it = init_list.begin(); it != init_list.end(); ++it) {
    this->insert(*it);
  }
}

HashTable<std::string>::~HashTable() {
  if (!(this->empty())) {
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

// All operators compare objects by element count
// If first hashtable has more elements, function return true.
// And this principe works on all operators
bool HashTable<std::string>::operator>(const HashTable<std::string> &obj) const {
  if (_count > obj.size()) {
    return true;
  }
  return false;
}

bool HashTable<std::string>::operator>=(const HashTable<std::string> &obj) const {
  if (_count >= obj.size()) {
    return true;
  }
  return false;
}

bool HashTable<std::string>::operator<(const HashTable<std::string> &obj) {
  if (_count < obj.size()) {
    return true;
  }
  return false;
}

bool HashTable<std::string>::operator<=(const HashTable<std::string> &obj) {
  if (_count <= obj.size()) {
    return true;
  }
  return false;
}

bool HashTable<std::string>::operator==(const HashTable<std::string> &obj) const {
  if (_count == obj.size()) {
    return true;
  }
  return false;
}

bool HashTable<std::string>::operator!=(const HashTable<std::string> &obj) const {
  if (_count != obj.size()) {
    return true;
  }
  return false;
}

std::ostream &operator<<(std::ostream &out, const HashTable<std::string> &obj) {
  typename HashTable<std::string>::node *tmp;
  for (int i = 0; i < obj.array.size(); i++) {
    tmp = obj.array[i];
    if (tmp != nullptr) {
      while (tmp != nullptr) {
        std::cout << tmp->value << " ";
        tmp = tmp->next;
      }
      std::cout << std::endl;
    }
  }
  return out;
}

HashTable<std::string> &HashTable<std::string>::operator=(const HashTable<std::string> &other_list) {
  node *tmp;
  node *tmp1;
  if (!(this->empty())) {
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
  for (int i = 0; i < array.size(); i++) {
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

bool HashTable<std::string>::empty() const {
  if (_count == 0) {
    return true;
  }
  return false;
}

HashTable<std::string>::node::node(std::string init_value) {
  value = init_value;
  next = nullptr;
}

int HashTable<std::string>::size() const{
  return _count;
}

int HashTable<std::string>::HashFunctionHorner(const std::string &s, int table_size, int key) const {
  int hash_result = 0;
  for (int i = 0; s[i] != s.size(); ++i)
    hash_result = (hash_result + s[i]) % table_size;
  hash_result = (hash_result * 2 + 1) % table_size;
  if(hash_result < 0) {
    hash_result = -hash_result;
  }
  return hash_result;
}


void HashTable<std::string>::resize() {
  unsigned int N = array.size();
  N *= 2;
  std::vector<node *> new_array;
  new_array.resize(N);
  node *tmp;
  for (int i = 0; i < array.size(); i++) {
    tmp = array[i];
    while (tmp != nullptr) {
      new_array[HashFunctionHorner(tmp->value, this->array.size(), this->array.size() - 1)] = tmp;
      tmp = tmp->next;
    }
  }
  array = new_array;
}

void HashTable<std::string>::insert(std::string value) {
  if (!(this->contain(value))) {
    _count++;
    int index = HashFunctionHorner(value, this->array.size(), this->array.size() - 1);
    node *tmp = array[index];
    if (tmp == nullptr) {
      array[index] = new node(value);
    } else {
      array[index] = new node(value);
      array[index]->next = tmp;
    }
    if (_count * 2 > array.size()) {
      resize();
    }
  }
}

int HashTable<std::string>::count(std::string value) {
  int counter = 0;
  if (!(this->empty())) {
    int index = HashFunctionHorner(value, this->array.size(), this->array.size() - 1);
    node *tmp = array[index];
    if (tmp != nullptr) {
      counter++;
    }
    while (tmp != nullptr) {
      counter++;
      tmp = tmp->next;
    }
    return counter;
  }
  return 0;
}

std::string HashTable<std::string>::find(const std::string &value) {
  if (!(this->empty())) {
    int index = HashFunctionHorner(value, this->array.size(), this->array.size() - 1);
    return array[index]->value;
  }
  return "";
}

void HashTable<std::string>::erase(std::string value) {
  node *tmp1;
  int index = HashFunctionHorner(value, this->array.size(), this->array.size() - 1);
  node *tmp = array[index];
  while (tmp != nullptr && tmp->next->value != value) {
    if (tmp->next->value == value) {
      tmp1 = tmp->next;
      tmp->next = tmp->next->next;
      delete tmp1;
      tmp1 = nullptr;
    }
  }
}

bool HashTable<std::string>::contain(const std::string &value) const {
  if(array.size() == 0) {
    return false;
  }
  int index = HashFunctionHorner(value, this->array.size(), this->array.size() - 1);
  node *tmp = array[index];
  while (tmp != nullptr) {
    if (tmp->value == value) {
      return true;
    }
    tmp = tmp->next;
  }
  return false;
}