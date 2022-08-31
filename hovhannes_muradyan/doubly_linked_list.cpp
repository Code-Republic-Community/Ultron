#include <iostream>

template<typename T>
class doubly_linked_list{
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
public:
  friend std::ostream& operator<<(std::ostream& out, doubly_linked_list<T> const *a){
    node* temp=a->head;
    while(temp!=nullptr){
      out << temp->value <<" --> ";
      temp = temp->next;
    }
    std::cout <<"NULL" <<std::endl;
    return out;
  }
  friend bool operator==(doubly_linked_list first, doubly_linked_list second){
    if(first.size() != second.size()){
      return false;
    }
    else{
      node* tmp1 = first.head;
      node* tmp2 = second.head;
      while (tmp1->next != nullptr){
        if(tmp1->value != tmp2->value){
          return false;
        }
        tmp1 = tmp1->next;
        tmp2 = tmp2->next;
      }
      return true;
    }
  }
  friend bool operator!=(doubly_linked_list first, doubly_linked_list second){
    return !(first==second);
  }
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
  }
  ~doubly_linked_list() = default;

  int size(){
    node* temp = head;
    int counter = 1;
    if(temp == nullptr){
      return 0;
    }
    while(temp->next != nullptr){
      temp = temp->next;
      counter++;
    }
    return(counter);
  }
  T front(){
    return head->value;
  }

  T back(){
    return tail->value;
  }

  void push_front(T value){
    node* n = new node(value);
    n->next = head;
    if(head != nullptr){
      head->prev = n;
    }
    head = n;
  }

  void push_back(int value)
  {
    if(head == nullptr){
      push_front(value);
      tail = head;
      return;
    }
    node* n = new node(value);
    tail->next = n;
    n->prev = tail;
    tail = n;
  }

  node* head;
  node* tail;
};


int main(){
  doubly_linked_list a(1);
  a.push_front(2);
  a.push_back(3);
  a.push_back(6);
  a.push_front(11);
  std::cout << &a;
}
