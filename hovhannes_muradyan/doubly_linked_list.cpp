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

void print(node* head){
  node* temp=head;
  while(temp!=nullptr){
    cout<<temp->data<<" --> ";
    temp=temp->next;
  }
  cout<<"NULL"<<endl;
}

int main()
{
  node* head1 = new node(1);
  node* head2 = new node(2);  
  node* head = new node(head1, 1, head2);
  push_back(head,1);
  push_back(head,2);
  push_back(head,3);
  push_back(head,4);
  push_back(head,5);
  push_back(head,6);
  print(head);
  cout<< front(head) << endl;
  cout << back(head) << endl;
  cout << size(head) << endl;
}
