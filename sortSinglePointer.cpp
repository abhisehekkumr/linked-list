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

void splitList(Node *head, Node **left, Node **right){

     if(head == NULL)
          return;

     Node *slow = head;
     Node *fast = head->next;

     while(fast && fast->next){
          fast = fast->next->next;
          slow = slow->next;
     }

     (*left) = head;
     (*right) = slow->next;
     slow->next = NULL;
}

Node *merge(Node *left, Node *right){

     if(!left)
          return right;

     if(!right)
          return left;

     Node *list = NULL;
     if(left->data < right->data){
          list = left;
          list->next = merge(left->next,right);
     }else{
          list = right;
          list->next = merge(left,right->next);
     }

     return list;
}

Node *mergeSort(Node *source){
     Node *head = source;
     Node *left = NULL;
     Node *right = NULL;

     if(head == NULL || head->next == NULL)
          return head;

     splitList(head, &left, &right);
     left = mergeSort(left);
     right = mergeSort(right);
     return merge(left,right);
}


int main(){

     Node *head = NULL;
     for(int i = 9; i >= 0; i--)
          head = insert(head,i);
     display(head);
     head = mergeSort(head);
     display(head);
}
