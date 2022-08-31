#include <iostream>

using namespace std;

class node{
public:
  node* prev;
  int data;
  node* next;
  explicit node(int value){
    prev=nullptr;
    data=value;
    next=nullptr;
  }
  node(node* prev1, int value, node* next1){
    prev=prev1;
    data=value;
    next=next1;
  }
  node(node &O1){
    prev = O1.prev;
    data = O1.data;
    next = O1.next;
  }
  ~node()= default;
};

ostream& operator<<(ostream& COUT, node *head){
  node* temp=head;
  while(temp!=nullptr){
    COUT<<temp->data<<" --> ";
    temp=temp->next;
  }
  cout<<"NULL"<<endl;
  return COUT;
}

bool operator==(node& head1, node& head){
  if((head1.next == head.next) && (head1.prev == head.prev) && (head1.data == head.data)){
    return true;
  }
  return false;
}
bool operator!=(node& head1, node& head){
  if((head1.next == head.next) && (head1.prev == head.prev) && (head1.data == head.data)){
    return false;
  }
  return true;
}
bool operator>(node& head1, node& head){
  if(head1.data > head.data){
    return true;
  }
  return false;
}
bool operator>=(node& head1, node& head){
  if(head1.data >= head.data){
    return true;
  }
  return false;
}
bool operator<(node& head1, node& head){
  if(head1.data < head.data){
    return true;
  }
  return false;
}
bool operator<=(node& head1, node& head){
  if(head1.data <= head.data){
    return true;
  }
  return false;
}
void operator+(node& head1, node& head){
  head1.next = &head;
  head.prev = &head1;
}

void operator+=(node& head1, node& head){
  head1.next = &head;
  head.prev = &head1;
}

int front(node* head){
  node* temp = head;
  while(temp->prev != nullptr){
    temp = temp->prev;
  }
  return(temp->data);
}

int back(node* head){
  node* temp= head;
  while(temp->next != nullptr){
    temp = temp->next;
  }
  return(temp->data);
}

node* begin(node* head){
  node* temp = head;
  while(temp->prev != nullptr){
    temp = temp->prev;
  }
  return(temp);
}

node* end(node* head){
  node* temp= head;
  while(temp->next != nullptr){
    temp = temp->next;
  }
  return(temp);
}

int size(node* head){
  node* temp = head;
  int counter = 1;
  while(temp->next != nullptr){
    temp = temp->next;
    counter++;
  }
  return(counter);
}

void push_front(node* &head, int value){
  node* n = new node(value);
  n->next=head;
  if(head!=nullptr){
    head->prev=n;
  }
  head=n;
}

bool empty(node* &head){
  if(head == nullptr){
    return true;
  }
  return false;
}

void push_back(node* &head, int value)
{
  if(head==nullptr){
    push_front(head, value);
    return;
  }
  node* n = new node(value);
  node* temp=head;
  while(temp->next!=nullptr){
    temp=temp->next;
  }
  temp->next=n;
  n->prev=temp;
}

void insert(node* &head, int index, int value){
  if(size(head) < index){
    push_back(head,value);
  }
  else if(index < 0){
    push_front(head, value);
  }
  else{
    node* temp=head;
    int counter = 0;
    while(counter < index){
      counter++;
      temp=temp->next;
    }
    node* n = new node(temp, value, temp->next);
    temp->next = n;
    (temp->next)->prev = n;
  }
}

void emplace(node* &head, int index1, int index2){
  node* tmp = head;
  int value1 = 0;
  int value2 = 0;
  int counter = 0;
  while((tmp->next) != nullptr){
    if(counter == index1){
      value1 = tmp->data;
    }
    else if(counter == index2){
      value2 = tmp->data;
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
      tmp->data = value2;
    }
    else if(counter == index2){
      tmp->data = value1;
    }
    else if(counter > index2 && counter > index1){
      break;
    }
    counter++;
    tmp = tmp->next;
  }
  tmp = begin(tmp);
  head = tmp;
}

int main()
{
  node* head = nullptr;
  node* head1 = new node(head, 2, nullptr);
  push_back(head,1);
  push_back(head,2);
  push_back(head,3);
  push_back(head,4);
  push_back(head,5);
  push_back(head,6);
  emplace(head, 1, 2);
  cout << head << endl;
}
