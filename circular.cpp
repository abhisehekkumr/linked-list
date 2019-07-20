#include<iostream>
using namespace std;

struct Node {
     int data;
     struct Node *next;
};

Node *insert(Node *head, int data){

     if(!head){
          Node *node = new Node;
          node->data = data;
          node->next = node;
          return node;
     }

     Node *ptr = head;
     while(ptr->next != head)
          ptr = ptr->next;

     Node *node = new Node;
     node->data = data;
     node->next = head;
     ptr->next = node;
     return head;
}

void display(Node *head){

     if(!head)
          return;

     Node *ptr = head;
     while(ptr->next != head){
          std::cout << ptr->data << ' ';
          ptr = ptr->next;
     }
     std::cout << ptr->data;
     std::cout << '\n';
}

int main(){

     Node *head = NULL;

     for(int i = 0; i <= 10; i++)
          head = insert(head,i);
     display(head);
}
