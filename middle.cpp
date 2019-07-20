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

Node *middleNode(Node *head){

     if(!head)
          return head;

     if(head->next == NULL)
          return head;

     Node *slow = head;
     Node *fast = head->next;

     while(fast){
          fast  = fast->next;

          if(fast){
               fast = fast->next;
               slow = slow->next;
          }
     }
     return slow;
}

Node *middle(Node *head){

     if(head == NULL || head->next == NULL)
          return head;

     Node *slow = head;
     Node *fast = head;

     while(fast && fast->next){
          fast = fast->next->next;
          slow = slow->next;
     }
     return slow;
}

Node *remove(Node *head){

     if(!head)
          return head;

     if(head->next == NULL)
          return head;

     Node *head1 = head;
     Node *ptr = head1;
     head = head->next;
     ptr->next = NULL;

     while(head){

          if(head->data > ptr->data){
               ptr->next = head;
               head = head->next;
               ptr = ptr->next;
               ptr->next = NULL;
          }else
               head = head->next;
     }
     return head1;
}

int main(){

     struct Node *head = NULL;

     for(int i = 10; i >=0; i--)
          head = insert(head, i);
     display(head);
     Node *node = middle(head);

     if(node)
          std::cout << node->data << '\n';
     else
          std::cout << "some problem as occured" << '\n';
}
