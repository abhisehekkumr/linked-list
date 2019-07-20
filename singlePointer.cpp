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


Node *deleteLocation(Node *head, int location){

     if(!head)
          return head;

     if(location <= 0)
          return head;

     if(location > 1 && head->next == NULL)
          return head;

     if(head->next == NULL && location == 1)
          return NULL;

     if(location == 1)
          return head->next;
     Node *ptr = head;

     while(ptr && (--location) > 1)
          ptr = ptr->next;

     if(!ptr)
          return head;

     if(ptr->next && location == 0){
          ptr->next = NULL;
          return head;
     }

     ptr->next = ptr->next->next;
     return head;
}

Node *ReverseInPair(Node *head,int k){

     if(!head)
          return head;

     Node *next = NULL;
     Node *prev = NULL;
     Node *current = head;
     int count = 0;

     while(current && count < k){
          next = current->next;
          current->next = prev;
          prev = current;
          current = next;
          count++;
     }

     if(next)
          head->next = ReverseInPair(next, k);
     return prev;
}

int main(){

     Node *head = NULL;
     for(int i = 0; i < 10; i++){
          head = insert(head,i);
          //display(head);
     }
     display(head);
     head = deleteLocation(head,1);
     head = deleteLocation(head,5);
     head = deleteLocation(head,8);
     display(head);
     head = ReverseInPair(head,3);
     display(head);
}
