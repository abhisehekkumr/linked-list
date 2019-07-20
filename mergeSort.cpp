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

     while (ptr) {
          std::cout << ptr->data << ' ';
          ptr = ptr->next;
     }
     std::cout << '\n';
}

/*
          ------------------------------------------------
                        merge sort code
          ------------------------------------------------
*/

void splitList(Node *head, Node **a, Node **b){

     Node *fast = head->next;
     Node *slow = head;

     while(fast){
          fast = fast->next;

          if(fast){
               slow = slow->next;
               fast = fast->next;
          }
     }

     (*a) = head;
     (*b) = slow->next;
     slow->next = NULL;
}

Node *mergeLists(Node *a, Node *b){

     Node *result = NULL;
     if(!a)
          return b;

     if(!b)
          return a;

     if(a->data < b->data){
          result = a;
          result->next = mergeLists(a->next,b);
     }else{

          result = b;
          result->next = mergeLists(a,b->next);
     }

     return result;
}

void mergeSort(Node **source){
     Node *head = (*source);
     Node *a = NULL;
     Node *b = NULL;

     if(head == NULL || head->next == NULL)
          return;

     splitList(head, &a,&b);
     mergeSort(&a);
     mergeSort(&b);

     (*source) = mergeLists(a,b);
}

int main(){

     Node *head = NULL;
     for(int i = 9; i >= 0; i--)
          head = insert(head,i);
     display(head);
     mergeSort(&head);
     display(head);
}
