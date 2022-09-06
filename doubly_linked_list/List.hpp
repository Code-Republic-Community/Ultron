#include <iostream>

#include "List.h"

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
List<T>::List(const List &other_list) {
  if(_head != nullptr) {
    node *tmp = _head;
    while (tmp->next != nullptr) {
      tmp = tmp->next;
      delete tmp->prev;
      tmp->prev= nullptr;
    }
    delete tmp;
    _head = nullptr;
    _tail = nullptr;
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
  }
}

template<typename T>
List<T>::List(std::initializer_list<T> init_list) {
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
  if(_head != nullptr) {
    while (_head->next != nullptr) {
      _head = _head->next;
      delete _head->prev;
      _head->prev = nullptr;
    }
    delete _head;
    _head = nullptr;
  }
}

template<typename T>
std::ostream &operator<<(std::ostream &out, const List<T> &obj) {
  typename List<T>::node *temp = obj._head; // remind asking
  while (temp != nullptr) {
    out << temp->value << " --> ";
    temp = temp->next;
  }
  std::cout << "NULL" << std::endl;
  return out;
}

template<typename T>
void List<T>::operator+=(const List<T> obj) {
  if (obj._head == nullptr) {
    return;
  }
  node *tmp = obj._head;
  while (tmp != nullptr) {
    this->push_back(tmp->value);
    tmp = tmp->next;
  }
  this->_tail = tmp;
}

template<typename T>
List<T> List<T>::operator+(List<T> obj) {
  List<T> nlist = *this;
  nlist += obj;
  return nlist;
}

template<typename T>
bool List<T>::operator==(List<T> &obj) {
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
bool List<T>::operator!=(List<T> &obj) {
  return !(*this == obj);
}

template<typename T>
bool List<T>::operator>(List<T> &obj) {
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
bool List<T>::operator>=(List<T> &obj) {
  if (*this == obj || *this > obj) {
    return true;
  }
  return false;
}

template<typename T>
bool List<T>::operator<(List<T> &obj) {
  if (!(*this >= obj)) {
    return true;
  }
  return false;
}

template<typename T>
bool List<T>::operator<=(List<T> &obj) {
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
    } else if (counter == index2) {
      break;
    } else if (counter > index2 && counter > index1) {
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
  int counter = 0;
  while (counter != index) {
    tmp = tmp->next;
    counter++;
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
  node *tmp = _head;
  node *tmp1 = tmp->next;
  while (tmp->next != nullptr) {
    while (tmp1->next != nullptr) {
      if (tmp->value == tmp1->value) {
        tmp1->prev->next = tmp1->next;
        tmp1->next->prev = tmp1->prev;
      }
      tmp1 = tmp1->next;
    }
    if (tmp->value == _tail->value) {
      _tail = _tail->prev;
      _tail->next = nullptr;
    }
    if (tmp->next != nullptr) {
      tmp = tmp->next;
      tmp1 = tmp->next;
    }
  }
}

template<typename T>
T List<T>::front() const {
  return _head->value;
}

template<typename T>
void List<T>::push_back(int value) {
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
void List<T>::splice(List<T> &second) {
  this->merge(second);
  second._head = nullptr;
  second._tail = nullptr;
}

template<typename T>
void List<T>::splice(List<T> &second, int index) {
  if (index > second.size() || index < 0) {
    return;
  }
  node *tmp = second._head;
  int counter = 0;
  while (counter != index) {
    tmp = tmp->next;
    counter++;
  }
  this->push_back(tmp->value);
  second.remove_by_index(index);
}

template<typename T>
void List<T>::splice(List<T> &second, int index1, int index2) {
  if (index2 < index1) {
    std::swap(index1, index2);
  }
  if (index1 > second.size() || index1 < 0 || index2 > second.size() || index2 < 0) {
    return;
  } else if (second.size() == index2 - index1 + 1) {
    this->splice(second);
    return;
  }
  node *tmp = second._head;
  int counter = 0;
  while (counter != index1) {
    tmp = tmp->next;
    counter++;
  }
  while (counter != index2) {
    this->push_back(tmp->value);
    tmp = tmp->next;
    second.remove_by_index(index1);
    counter++;
  }
  this->push_back(tmp->value);
  second.remove_by_index(index1);
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
void List<T>::insert(int index, int value) {
  if (this->size() <= index) {
    push_back(value);
  } else if (index == 0) {
    push_front(value);
  } else {
    node *temp = _head;
    int counter = 0;
    while (counter < index) {
      counter++;
      temp = temp->next;
    }
    node *new_node = new node(value);
    new_node->next = temp;
    new_node->prev = temp->prev;
    (temp->prev)->next = new_node;
    temp->prev = new_node;
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
  delete _head;
  delete _tail;
  _head = nullptr;
  _tail = nullptr;
}

template<typename T>
T List<T>::back() const {
  return _tail->value;
}

