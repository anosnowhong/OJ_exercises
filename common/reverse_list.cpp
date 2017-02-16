#include <iostream>
#include <algorithm>
//#include <slist> provide singularly linked list
using namespace std;

struct Node{
  Node(){
  }

  Node(int m){
    data = m;
  }

  int data;
  Node* next;
};

void insert(Node* position, int element){
  Node* n = new Node(element);
  n->next = nullptr;
  position->next = n;
}

void reverse_list(Node*& new_head, Node*& original_head){

  Node* tmp = original_head;
  while(original_head->next != nullptr){
    tmp = original_head->next;
    original_head->next = tmp->next;
    tmp->next = new_head;
  }
  original_head->next = tmp;

}

int main(){

  Node* head = new Node();
  Node* tmp = head;
  //list<int> ll = {0,1,2,3,4,5,6,7,8,9};
  for(int i=0; i<10; i++){
    insert(tmp, i);
    tmp = tmp->next;
  }

  tmp = head;
  tmp = tmp->next;//skip head
  while(tmp!=nullptr){
    cout<<tmp->data<<" ";
    tmp = tmp->next;
  }
  cout<<endl;

  Node* new_head = new Node();

  Node* tmp2 = head;
  while(head->next != nullptr){
    tmp2 = head->next;
    head->next = tmp2->next;
    tmp2->next = new_head;
    new_head = tmp2;
  }
  head->next = tmp2;

  //reverse_list(new_head, head);


  tmp = head;
  tmp = tmp->next;//skip head

  while(tmp!=nullptr){
    cout<<tmp->data<<" ";
    tmp = tmp->next;
  }
  cout<<endl;

  return 0;
}
