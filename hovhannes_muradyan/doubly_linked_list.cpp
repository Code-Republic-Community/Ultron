#include <iostream>

template<typename T>
class doubly_linked_list{
public:
  /////////operators overloading ///////////////////
  friend std::ostream& operator<<(std::ostream& out, doubly_linked_list<T> const &a){
    node* temp=a.head;
    while(temp!=nullptr){
      out<<temp->value<<" --> ";
      temp=temp->next;
    }
    std::cout<<"NULL"<<std::endl;
    return out;
  }
  bool operator!=(doubly_linked_list<T> second);
  bool operator==(doubly_linked_list<T> second);
  /////////constructors/////////////////////
  explicit doubly_linked_list(T value){
    head = new node(value);
    tail = head;
  }
  //TODO
  doubly_linked_list(const doubly_linked_list &O1) {
    head = new node(O1.head->value);
    tail = new node(O1.tail->value);
    node *tmp = O1.head;
    node *tmp1 = head;
    while (tmp->next != nullptr) {
      tmp1->next = tmp->next;
      tmp = tmp->next;
      tmp1 = tmp1->next;
    }
  }
  ~doubly_linked_list() = default;

public:
  int size() const; // return count of elements in list
  T front() const; // return first element value
  T back() const; // return last element value
  void push_front(T value); // add element at front
  void push_back(int value); // append element
  void emplace(int index1, int index2); // emplace element values by index
  void remove(int index); //remove element by index
  void resize(int index); // save first index elements
  void insert(int index, int value); // insert element with value in index
  void clear(); // clear all list
  bool empty(); // check if list is empty or not
private:
  struct node{
    node* prev;
    node* next;
    T value;
    explicit node(T i) {
      value = i;
      prev = nullptr;
      next = nullptr;
    }
  };
  node* head;
  node* tail;
};

template<typename T>
bool doubly_linked_list<T>::operator==(doubly_linked_list<T> second){
  if(this->size() != second.size()){
    return false;
  }
  doubly_linked_list<T>::node *tmp1 = this->head;
  doubly_linked_list<T>::node *tmp2 = second.head;
  while (tmp1->next != nullptr){
    if(tmp1->value != tmp2->value){
      return false;
    }
    tmp1 = tmp1->next;
    tmp2 = tmp2->next;
  }
  return true;

}

template<typename T>
bool doubly_linked_list<T>::operator!=(doubly_linked_list<T> second){
  return !(this == second);
}

template<typename T>
int doubly_linked_list<T>::size() const{
  if(head == nullptr){
    return 0;
  }
<<<<<<< HEAD
  doubly_linked_list<T>::node* temp = head;
  int counter = 1;
  while(temp->next != nullptr){
    temp = temp->next;
    counter++;
  }
  return counter;
}

template<typename T>
T doubly_linked_list<T>::front() const{
  return head->value;
}

template<typename T>
T doubly_linked_list<T>::back() const{
  return tail->value;
}

template<typename T>
void doubly_linked_list<T>::push_front(T value){
  if (head == nullptr) {
    head = new node(value);
    tail = head;
    return;
=======
  //TODO
  explicit doubly_linked_list(T value){
    head->value = value;
    head->prev = nullptr;
    head->next = nullptr;
    tail = head;
  }
  //TODO
  doubly_linked_list(const doubly_linked_list &O1){
    head = O1.head;
    tail = O1.head;
>>>>>>> f9663936c909e21d6b8e47464000ba9c6b52c3d6
  }
  node* n = new node(value);
  n->next = head;
  head->prev = n;
  head=n;
}

template<typename T>
void doubly_linked_list<T>::push_back(int value)
{
  if(head==nullptr){
    push_front(value);
    return;
  }
  node* n = new node(value);
  tail->next = n;
  n->prev = tail;
  tail = n;
}
//TODO (change second while to pointers)
template<typename T>
void doubly_linked_list<T>::emplace(int index1, int index2){
  node* tmp = head;
  int value1 = 0;
  int value2 = 0;
  int counter = 0;
  while((tmp->next) != nullptr){
    if(counter == index1){
      value1 = tmp->value;
    }
    else if(counter == index2){
      value2 = tmp->value;
    }
    else if(counter > index2 && counter > index1){
      break;
    }
    counter++;
    tmp = tmp->next;
  }
  tmp = head;
  counter = 0;
  while((tmp->next) != nullptr){
    if(counter == index1){
      tmp->value = value2;
    }
    else if(counter == index2){
      tmp->value = value1;
    }
    else if(counter > index2 && counter > index1){
      break;
    }
    counter++;
    tmp = tmp->next;
  }
}

//TODO (CHECK INDEX AND LIST SIZE)
template<typename T>
void doubly_linked_list<T>::remove(int index){
  node* tmp = head;
  int counter = 0;
  while(counter != index){
    tmp = tmp->next;
    counter++;
  }
  if(tmp->prev != nullptr && tmp->next != nullptr) {
    (tmp->prev)->next = tmp->next;
    (tmp->next)->prev = tmp->prev;
    delete tmp;
    tmp = nullptr;
  }
  else if(tmp->next != nullptr && tmp->prev == nullptr){
    head = head->next;
    delete tmp;
    tmp = nullptr;
  }
  else {
    tail = tmp->prev;
    delete tmp;
    tmp = nullptr;
  }
}

template<typename T>
void doubly_linked_list<T>::resize(int index){
  node* tmp = head;
  int counter = 0;
  while(counter != index){
    tmp = tmp->next;
    counter++;
  }
  tmp->next = nullptr;
  begin(tmp);
  head = tmp;
}

template<typename T>
void doubly_linked_list<T>::insert(int index, int value){
  if(this->size() <= index){
    push_back(value);
  }
  else if(index == 0){
    push_front(value);
  }
  else{
    node* temp=head;
    int counter = 0;
    while(counter < index){
      counter++;
      temp=temp->next;
    }
    node* n = new node(value);
    n->next = temp;
    n->prev = temp->prev;
    (temp->prev)->next = n;
    temp->prev = n;
  }
}

template<typename T>
void doubly_linked_list<T>::clear() {
  delete head;
  delete tail;
  head = nullptr;
  tail = nullptr;
}

template<typename T>
bool doubly_linked_list<T>::empty(){
  if(head == nullptr){
    return true;
  }
  return false;
}

int main(){
  doubly_linked_list a(1);
  doubly_linked_list b = a;
  b.push_back(5);
  b.push_front(3);
  a.push_front(2);
  a.push_back(3);
  a.push_back(6);
  a.push_front(11);
  a.emplace(1, 2);
  a.insert(16, 27);
  std::cout << a.empty();
  std::cout << b;
}
