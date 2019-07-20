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
          node->next = NULL;
          return node;
     }

     Node *ptr = head;
     while(ptr->next)
          ptr = ptr->next;

     Node *node = new Node;
     node->data = data;
     node->next = NULL;
     ptr->next  = node;
     return head;
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

Node *split(Node *head, int k){

     if(!head)
          return head;

     if(head->next == NULL)
          return head;

     Node *first = NULL;
     Node *first_head = NULL;
     Node *second_head = NULL;
     Node *second = NULL;

     while(head){

          // value less than k
          if(head->data  < k){
               Node *ptr = head;
               head = head->next;
               ptr->next = NULL;

               if(!first_head){
                    first_head = ptr;
                    first = first_head;
               }else{

                    first->next = ptr;
                    first = first->next;
               }
          }

          // value grater than k
          else{

               Node *ptr = head;
               head = head->next;
               ptr->next = NULL;

               if(!second_head){
                    second_head = ptr;
                    second = second_head;
               }else{

                    second->next = ptr;
                    second = second->next;
               }
          }
     }

     if(!first_head)
          return second_head;

     if(!second_head)
          return first_head;
     first->next = second_head;
     return first_head;
}

int main(){

     Node *head = NULL;
     head = insert(head,1);
     head = insert(head,4);
     head = insert(head,3);
     head = insert(head,2);
     head = insert(head,5);
     head = insert(head,2);
     display(head);
     head = split(head,0);
     display(head);
}
