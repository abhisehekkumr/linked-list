#include<iostream>
using namespace std;

struct Node {
     int data;
     struct Node *next;
};

void insert(Node **head, int data){

     if((*head) == NULL){
          Node *node = new Node;
          node->data = data;
          (*head) = node;
          return;
     }

     Node *ptr = (*head);
     while(ptr->next)
          ptr = ptr->next;

     Node *node =  new Node;
     node->data = data;
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

void deleteNode(Node **head, int data){

     if(!(*head))
          return;

     if((*head)->data == data){
          (*head) = (*head)->next;
          return;
     }

     Node *ptr = (*head);
     while(ptr && ptr->next->next){

          if(ptr->next->data == data)
               break;
          ptr = ptr->next;
     }

     if(ptr->next->next == NULL && data == ptr->next->data){
          ptr->next = NULL;
          return;
     }

     if(data == ptr->next->data){
          ptr->next = ptr->next->next;
          return;
     }
}

void append(Node **head, int data){

     if(!(*head)){
          Node *node = new Node;
          node->data = data;
          (*head) = node;
          return;
     }

     if((*head)->data > data){
          Node *node = new Node;
          node->data = data;
          node->next = (*head);
          (*head) = node;
          return;
     }

     Node *ptr = *head;
     Node *ptr_after = NULL;
     while(ptr){
          ptr_after = ptr;
          ptr = ptr->next;

          if(ptr && ptr->data >= data)
               break;
     }

     if(ptr == NULL){
          Node *node = new Node;
          node->data = data;
          node->next = NULL;
          ptr_after->next = node;
          return;
     }

     Node *node = new Node;
     node->data = data;
     node->next = ptr;
     ptr_after->next = node;

}

void deleteLocation(Node **head, int location){

     if(!(*head))
          return;

     if((*head)->next == NULL){

          if(location == 1)
               (*head) = NULL;
               return;

          return;
     }

     if(location == 1){
          (*head) = (*head)->next;
          return;
     }

     Node *ptr = (*head);

     while(ptr && (--location) > 1){
          ptr = ptr->next;
     }

     if(!ptr)
          return;

     if(ptr->next->next == NULL){
          ptr->next = NULL;
          return;
     }
     ptr->next = ptr->next->next;

}

void deleteList(Node **head){

     if(!(*head))
          return;

     Node *ptr = (*head);

     while(ptr){
          Node *node = (*head);
          (*head) = (*head)->next;
          delete node;
     }
}

int main(){

     Node *head = NULL;
     for(int i = 0; i < 10; i++)
          insert(&head, i);
     display(head);
     //deleteNode(head,1);
     deleteNode(&head,0);
     //deleteNode(head,6);
     //deleteNode(head,9);
     append(&head,-1);
     append(&head,7);
     append(&head,10);
     append(&head,1000);
     append(&head,2);
     display(head);
     deleteLocation(&head,1);
     deleteLocation(&head,5);
     deleteLocation(&head,10);
     deleteLocation(&head,1008787);
     display(head);
     deleteList(&head);
     display(head);
}
