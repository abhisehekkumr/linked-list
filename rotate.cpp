#include<iostream>
using namespace std;

struct Node {
     int data;
     struct Node *next;
};

Node *insert(Node *head, int data){

     if(!head){
          Node *node  = new Node;
          node->data = data;
          node->next = NULL;
          return node;
     }

     Node *ptr = head;

     while(ptr->next)
          ptr = ptr->next;

     Node *node =  new Node;
     node->data = data;
     node->next = NULL;
     ptr->next = node;
     return head;
}

int len(Node *head){
     int count = 0;
     Node *ptr = head;
     while(ptr){
          count++;
          ptr = ptr->next;
     }
     return count;
}

Node *lastNode(Node *head, int k){

     if(!head || head->next == NULL)
          return head;

     if(k == 0)
          return head;

     int count = 0;
     Node *ptr = head;

     while(ptr && count < k){
          count++;
          ptr = ptr->next;
     }

     if(!ptr && count == k)
          return head;

     if(!ptr)
          return NULL;

     Node *slow = head;
     while(ptr){
          slow = slow->next;
          ptr = ptr->next;
     }
     return slow;
}

Node *rotate(Node *head, int k){

     int n = len(head);
     if(n == k || k == 0)
          return head;

     k = k%n;
     if(k == 0)
          return head;
     Node *new_head = lastNode(head,k);
     Node *ptr = head;

     while(ptr->next != new_head)
          ptr = ptr->next;
     ptr->next = NULL;

     ptr = new_head;
     while(ptr->next)
          ptr = ptr->next;
     ptr->next = head;
     return new_head;
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

int main(){

     Node *head = NULL;
     //head = insert(head,0);
     head = insert(head,1);
     head = insert(head,2);
     head = insert(head,3);
     head = insert(head,4);
     head = insert(head,5);
     display(head);
     head = rotate(head,10);
     display(head);
}
