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
     ptr->next = node;
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

Node *evenOdd(Node *head){

     if(!head)
          return head;

     if(head->next == NULL)
          return head;

     Node *odd = NULL;
     Node *even = NULL;
     Node *odd_end = NULL;
     Node *even_end = NULL;
     Node *ptr = head;
     int count = 1;
     while(ptr){

          if(count & 1){

               if(!odd){
                    odd = ptr;
                    odd_end = ptr;
                    ptr = ptr->next;
                    odd_end->next = NULL;
               }else{
                    odd_end->next = ptr;
                    ptr = ptr->next;
                    odd_end = odd_end->next;
                    odd_end->next = NULL;
               }
          }

          else{

               if(!even_end){
                    even_end = ptr;
                    even = ptr;
                    ptr = ptr->next;
                    even_end->next = NULL;
               }else{
                    even_end->next = ptr;
                    ptr = ptr->next;
                    even_end = even_end->next;
                    even_end->next = NULL;
               }
          }
          count++;
     }

     odd_end->next = even;
     return odd;
}

int main(){

     Node *head = NULL;
     for(int i = 0; i <= 10; i++)
          head = insert(head,i);
     display(head);
     head = evenOdd(head);
     display(head);
}
