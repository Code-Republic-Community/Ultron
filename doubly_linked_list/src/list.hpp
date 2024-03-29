#include <iostream>
#include <unordered_set>

#include "list.h"

template<typename T>
List<T>::List() {
  _head = nullptr;
  _tail = _head;
}

template<typename T>
List<T>::List(T value) {
  _head = new node(value);
  _tail = _head;
}

template<typename T>
List<T>::List(const List<T> &other_list) {
  if (other_list._head != nullptr) {
    _head = new node(other_list._head->value);
    node *otherNext = other_list._head->next;
    node *temp = _head;
    while (otherNext != nullptr) {
      temp->next = new node(otherNext->value);
      (temp->next)->prev = temp;
      temp = temp->next;
      otherNext = otherNext->next;
    }
    _tail = temp;
  }
}

template<typename T>
List<T>::List(List<T> &&other_list)  noexcept {
  _head = other_list._head;
  _tail = other_list._tail;
  other_list._head = nullptr;
  other_list._tail = nullptr;
}

template<typename T>
List<T>::List(const std::initializer_list<T> &init_list) {
  _head = new node(*init_list.begin());
  node *temp = _head;
  for (auto it = init_list.begin() + 1; it != init_list.end(); ++it) {
    temp->next = new node(*it);
    temp->next->prev = temp;
    temp = temp->next;
    _tail = temp;
  }
}

template<typename T>
List<T>::~List() {
  if (_head != nullptr) {
    node *tmp = _head;
    while (tmp->next != nullptr) {
      tmp = tmp->next;
      delete tmp->prev;
      tmp->prev = nullptr;
    }
    delete tmp;
    tmp = nullptr;
  }
}

template<typename T>
List<T>::node::node(T init_value) {
  value = init_value;
  prev = nullptr;
  next = nullptr;
}

template<typename T>
List<T>::node::node(const List::node &init_node) {
  value = init_node.value;
  prev = init_node.prev;
  next = init_node.prev;
}

template<typename T>
List<T> &List<T>::operator=(const List<T> &other_list) {
  if (_head != nullptr) {
    node *tmp = _head;
    while (tmp->next != nullptr) {
      tmp = tmp->next;
      delete tmp->prev;
      tmp->prev = nullptr;
    }
    delete tmp;
    tmp = nullptr;

  }
  if (other_list._head != nullptr) {
    _head = new node(other_list._head->value);
    node *otherNext = other_list._head->next;
    node *temp = _head;
    while (otherNext != nullptr) {
      temp->next = new node(otherNext->value);
      (temp->next)->prev = temp;
      temp = temp->next;
      otherNext = otherNext->next;
    }
    _tail = temp;
  } else {
    _head = nullptr;
    _tail = nullptr;
  }
  return *this;
}

template<typename T>
List<T> &List<T>::operator=(List<T> &&other_list) noexcept {
  if (_head != nullptr) {
    node *tmp = _head;
    while (tmp->next != nullptr) {
      tmp = tmp->next;
      delete tmp->prev;
      tmp->prev = nullptr;
    }
    delete tmp;
    tmp = nullptr;
  }
  _head = other_list._head;
  _tail = other_list._tail;
  other_list._head = nullptr;
  other_list._tail = nullptr;
}

template<typename T>
std::ostream &operator<<(std::ostream &out, const List<T> &obj) {
  typename List<T>::node *temp = obj._head;
  while (temp != nullptr) {
    out << temp->value << " --> ";
    temp = temp->next;
  }
  std::cout << "NULL" << std::endl;
  return out;
}

template<typename T>
void List<T>::operator+=(const List<T> &obj) {
  if (obj._head == nullptr) {
    return;
  }
  node *tmp = obj._head;
  while (tmp != nullptr) {
    this->push_back(tmp->value);
    tmp = tmp->next;
  }
}

template<typename T>
List<T> List<T>::operator+(const List<T> &obj) const {
  if (this->_head == nullptr) {
    return obj;
  } else if (obj._head == nullptr) {
    return *this;
  }
  List<T> new_list(*this);
  new_list += obj;
  return new_list;
}

template<typename T>
bool List<T>::operator==(const List<T> &obj) const {
  if (this->size() != obj.size()) {
    return false;
  }
  List<T>::node *tmp1 = this->_head;
  List<T>::node *tmp2 = obj._head;
  while (tmp1->next != nullptr) {
    if (tmp1->value != tmp2->value) {
      return false;
    }
    tmp1 = tmp1->next;
    tmp2 = tmp2->next;
  }
  return true;
}

template<typename T>
bool List<T>::operator!=(const List<T> &obj) const {
  return !(*this == obj);
}

template<typename T>
bool List<T>::operator>(const List<T> &obj) const {
  if (this == nullptr || obj._head == nullptr) {
    return false;
  }
  if (this->size() > obj.size()) {
    return true;
  }
  if (this->size() < obj.size()) {
    return false;
  }
  node *tmp = _head;
  node *tmp1 = obj._head;
  while (tmp != nullptr) {
    if (tmp->value > tmp1->value) {
      return true;
    } else if (tmp->value < tmp1->value) {
      return false;
    }
    tmp = tmp->next;
    tmp1 = tmp1->next;
  }
  return false;
}

template<typename T>
bool List<T>::operator>=(const List<T> &obj) const {
  if (*this == obj || *this > obj) {
    return true;
  }
  return false;
}

template<typename T>
bool List<T>::operator<(const List<T> &obj) const {
  if (!(*this >= obj)) {
    return true;
  }
  return false;
}

template<typename T>
bool List<T>::operator<=(const List<T> &obj) const {
  if (*this < obj || *this == obj) {
    return true;
  }
  return false;
}

template<typename T>
void List<T>::emplace(int index1, int index2) {
  if (index1 < 0 || index1 > this->size() || index2 > this->size()) {
    return;
  }
  node *value1;
  node *value2 = _head;
  int counter = 0;
  while ((value2->next) != nullptr) {
    if (counter == index1) {
      value1 = value2;
    } else if ((counter > index2 && counter > index1) || counter == index2) {
      break;
    }
    counter++;
    value2 = value2->next;
  }
  int temp = value1->value;
  value1->value = value2->value;
  value2->value = temp;
}

template<typename T>
void List<T>::remove_by_index(int index) {
  if (index > this->size() || index < 0) {
    return;
  }
  node *tmp = _head;
  while (index != 0) {
    tmp = tmp->next;
    index--;
  }
  if (tmp->prev != nullptr && tmp->next != nullptr) {
    (tmp->prev)->next = tmp->next;
    (tmp->next)->prev = tmp->prev;
    delete tmp;
    tmp = nullptr;
  } else if (tmp->next != nullptr && tmp->prev == nullptr) {
    _head = _head->next;
    _head->prev = nullptr;
    delete tmp;
    tmp = nullptr;
  } else {
    _tail = tmp->prev;
    _tail->next = nullptr;
    delete tmp;
    tmp = nullptr;
  }
}

template<typename T>
void List<T>::unique() {
  if (_head == nullptr) {
    return;
  }
  std::unordered_set<T> used;
  node *tmp = _head;
  node *tmp_next;
  while (tmp != nullptr) {
    if (used.find(tmp->value) != used.end()) {
      tmp_next = tmp->next;
      tmp->prev->next = tmp->next;
      if (tmp->next != nullptr) {
        tmp->next->prev = tmp->prev;
      }
      tmp = tmp_next;
    } else {
      used.insert(tmp->value);
      tmp = tmp->next;
    }
  }
}

template<typename T>
T List<T>::front() const {
  return _head->value;
}

template<typename T>
void List<T>::push_back(T value) {
  if (_head == nullptr) {
    _head = new node(value);
    _tail = _head;
    return;
  }
  node *new_node = new node(value);
  _tail->next = new_node;
  new_node->prev = _tail;
  _tail = new_node;
}

template<typename T>
void List<T>::push_front(T value) {
  if (_head == nullptr) {
    _head = new node(value);
    _tail = _head;
    return;
  }
  node *new_node = new node(value);
  new_node->next = _head;
  _head->prev = new_node;
  _head = new_node;
}

template<typename T>
void List<T>::resize(int index) {
  if (index == this->size()) {
    return;
  }
  if (index < this->size()) {
    node *tmp = _head;
    while (index) {
      tmp = tmp->next;
      index--;
    }
    tmp->next = nullptr;
    _tail = tmp;
    while (tmp->prev != nullptr) {
      tmp = tmp->prev;
    }
    _head = tmp;
  } else {
    for (int i = 0; i < (index - this->size()); i++) {
      this->push_back(0);
    }
  }
}

template<typename T>
void List<T>::splice(List<T> &obj) {
  this->merge(obj);
  obj.clear();
}

template<typename T>
void List<T>::splice(List<T> &obj, int index) {
  if (index > obj.size() || index < 0) {
    return;
  }
  node *tmp = obj._head;
  while (index != 0) {
    tmp = tmp->next;
    index--;
  }
  this->push_back(tmp->value);
  obj.remove_by_index(index);
}

template<typename T>
void List<T>::splice(List<T> &obj, int index1, int index2) {
  if (index2 < index1) {
    std::swap(index1, index2);
  }
  if (index1 > obj.size() || index1 < 0 || index2 > obj.size() || index2 < 0) {
    return;
  } else if (obj.size() == index2 - index1 + 1) {
    this->splice(obj);
    return;
  }
  node *tmp = obj._head;
  int counter = 0;
  while (counter != index1) {
    tmp = tmp->next;
    counter++;
  }
  while (counter != index2) {
    this->push_back(tmp->value);
    tmp = tmp->next;
    obj.remove_by_index(index1);
    counter++;
  }
  this->push_back(tmp->value);
  obj.remove_by_index(index1);
}

template<typename T>
int List<T>::size() const {
  if (_head == nullptr) {
    return 0;
  }
  List<T>::node *temp = _head;
  int counter = 1;
  while (temp->next != nullptr) {
    temp = temp->next;
    counter++;
  }
  return counter;
}

template<typename T>
void List<T>::merge(const List<T> &obj) {
  if (obj._head == nullptr) {
    return;
  }
  node *tmp = obj._head;
  while (tmp->next != nullptr) {
    this->push_back(tmp->value);
    tmp = tmp->next;
  }
  this->push_back(tmp->value);
}

template<typename T>
void List<T>::insert(int index, T value) {
  if (index < 0) {
    return;
  } else if (this->size() <= index) {
    push_back(value);
  } else if (index == 0) {
    push_front(value);
  } else {
    iterator ptr = this->begin();
    for (int i = 0; i < index - 1; i++) {
      ptr++;
    }
    node *tmp = ptr->next->prev;
    ptr->next->prev = new node(value);
    ptr->next->prev->prev = tmp;
    ptr->next->prev->next = ptr->next;
    ptr->next = ptr->next->prev;
  }
}

template<typename T>
bool List<T>::empty() const {
  if (_head == nullptr) {
    return true;
  }
  return false;
}

template<typename T>
void List<T>::clear() {
  if (_head != nullptr) {
    node *tmp = _head;
    while (tmp->next != nullptr) {
      tmp = tmp->next;
      delete tmp->prev;
      tmp->prev = nullptr;
    }
    delete tmp;
    tmp = nullptr;
    _head = nullptr;
  }
}

template<typename T>
T List<T>::back() const {
  return _tail->value;
}

template<typename T>
bool List<T>::iterator::operator!=(const iterator &itr) const {
  return new_node != itr.new_node;
}

template<typename T>
typename List<T>::iterator List<T>::begin() const {
  return iterator(_head);
}

template<typename T>
typename List<T>::iterator List<T>::end() const {
  return iterator(_tail->next);
}

template<typename T>
const typename List<T>::iterator List<T>::iterator::operator++(int) {
  iterator temp = *this;
  new_node = new_node->next;
  return temp;
}

template<typename T>
const typename List<T>::iterator List<T>::iterator::operator--(int) {
  iterator temp = *this;
  new_node = new_node->prev;
  return temp;
}

template<typename T>
typename List<T>::node *List<T>::iterator::operator->() const {
  return new_node;
}

template<typename T>
void List<T>::remove_if(List::iterator start, List::iterator end, bool (*func)(T)) {
  for (auto pos = start; pos != end; pos++) {
    if (func(*pos) == true) {
      if (pos->next != nullptr && pos->prev != nullptr) {
        pos->prev->next = pos->next;
        pos->next->prev = pos->prev;
      } else if (pos->prev == nullptr && pos->next != nullptr) {
        pos->next->prev = nullptr;
        _head = pos->next;
      } else {
        pos->prev->next = nullptr;
        _tail = pos->prev;
      }
    }
  }
}
