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
     while(ptr){
          std::cout << ptr->data << ' ';
          ptr = ptr->next;
     }
     std::cout << '\n';
}

/*
     intilize:
          current = head
          prev = next = NULL

          as current node is pointed to head for now what we will do is we will
          save the current next into next and update the next with current prev
          pointer and then we will shift by right by current = next and as well
          as we will shift prev to right by prev = current

          first
               mode prev
          then
               current

          in  the new head is need to made by making head = prev
*/

void reverse(Node **head){

     if(!(*head))
          return;

     Node *prev = NULL;
     Node *next = NULL;
     Node *current = (*head);

     while( current != NULL){
          next = current->next;
          current->next = prev;
          prev = current;
          current = next;
     }

     (*head) = prev;
}

int main(){

     Node *head = NULL;
     for(int i = 0; i < 10; i++)
          insert(&head, i);
     reverse(&head);
     display(head);
}
