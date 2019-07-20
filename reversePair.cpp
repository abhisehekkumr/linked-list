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
     node->next = NULL;
     ptr->next = node;
}

void display(Node *head){

     if(!head)
          return;

     Node *ptr = head;

     while (ptr) {
          std::cout << ptr->data << ' ';
          ptr = ptr->next;
     }
     std::cout << '\n';
}

Node  *ReverseInPair(Node *head, int k){

     if(!(head))
          return head;

     Node *next = NULL;
     Node *prev = NULL;
     Node *current = (head);
     int count = 0;
     while(current && count < k){
          next = current->next;
          current->next = prev;
          prev = current;
          current = next;
          count++;
     }

     if(next != NULL)
          head->next = ReverseInPair(next,k);
     return prev;

}

int main(){

     Node *head = NULL;
     for(int i = 0; i  < 10; i++)
          insert(&head,i);
     display(head);
     head = ReverseInPair(head,2);
     display(head);
}
