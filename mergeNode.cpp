#include<iostream>
using namespace std;

struct Node{
     int data;
     struct Node *next;
};

struct StackNode {
     struct Node *address;
     struct StackNode *next;
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

void makeMerge(Node **large, Node **small){

     if(!(large))
          return;

     if(!(small))
          return;

     Node *ptr = (*small);
     Node *ptr2 = (*large);
     while(ptr->next){
          ptr = ptr->next;
          ptr2 = ptr2->next;
     }

     ptr->next = ptr2;
}

void push(StackNode **top, Node *node1){

     if(!(*top)){

          StackNode *node = new StackNode;
          node->address = node1;
          node->next = NULL;
          (*top) = node;
          return;
     }

     StackNode *node = new StackNode;
     node->address = node1;
     node->next = (*top);
     (*top) = node;
}

Node *pop( StackNode **top){

     if(!(*top))
          return NULL;

     Node *node = (*top)->address;
     (*top) = (*top)->next;
     return node;
}

void displayStack(StackNode *top){

     StackNode *ptr = top;

     while(ptr){
          cout << ptr->address->data << " ";
          ptr = ptr->next;
     }
     std::cout << '\n';
}

int main(){

     Node *head = NULL;
     Node *head2 = NULL;
     for(int i = 0; i < 10; i++)
          insert(&head, i);

     for(int i = 100; i < 200; i++)
          insert(&head2,i);

     makeMerge(&head2,&head);

     Node *ptr = head;

     StackNode *stack = NULL;
     while(ptr){
          push(&stack, ptr);
          ptr = ptr->next;
     }

     ptr = head2;
     StackNode *stack2 = NULL;
     while(ptr){
          push(&stack2,ptr);
          ptr = ptr->next;
     }

     Node *node = pop(&stack);
     Node *node2 = pop(&stack2);

     while(node && node2 && node->next == node2->next){
          node = pop(&stack);
          node2 = pop(&stack2);
     }

     std::cout << " \n the merge node point is next of " << node->next->data << ' ' << node2->next->data;
}
