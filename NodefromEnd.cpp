#include<iostream>
using namespace std;

struct Node {
     int data;
     struct Node *next;
};

void insert(Node **head, int data){

     if(!(*head)){
          Node *node = new Node;
          node->data = data;
          node->next = NULL;
          (*head) = node;
          return;
     }

     Node *ptr = (*head);

     while(ptr->next)
          ptr = ptr->next;

     Node *node = new Node;
     node->data = data;
     node->next  = NULL;
     ptr->next = node;
}

void display(Node *head){

     if(!head)
          return;

     Node *ptr = head;
     while(ptr){
          std::cout << ptr->data << ' ';
          ptr = ptr->next;
     }
     std::cout  << '\n';
}

Node *nodeFromeEnd(Node **head, int k){

     if(!(*head))
          return NULL;

     Node *ptr = (*head);

     while(ptr && k--){
          ptr = ptr->next;
     }

     if(ptr == NULL && k == 0)
          return (*head);

     if(!ptr)
          return NULL;

     Node *node = (*head);

     while(ptr){
          ptr = ptr->next;
          node = node->next;
     }

     return node;
}

int main(){

     Node *head = NULL;
     for(int i = 0; i < 10; i++)
          insert(&head,i);
     display(head);
     int numer = 10;
     //cin >> numer;
     Node *node = nodeFromeEnd(&head,numer);

     if(node)
          std::cout << node->data << '\n';
     else
          std::cout << "cannot find" << '\n';
}
