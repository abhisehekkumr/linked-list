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

void createCycle(Node **head, int location){

          if(!(*head))
               return;
          Node *ptr = (*head);
          Node *hd = (*head);

          while(ptr && (--location) > 1){
               hd = ptr;
               ptr = ptr->next;
          }

          if(!ptr){
               hd->next = (*head);
               return;
          }

          while(ptr->next){
               ptr = ptr->next;
          }

          ptr->next = hd;
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

bool isCycleExist(Node *head){

     if(!head)
          return false;

     Node *slow = head;
     Node *fast = head;

     while(fast && fast->next){
          fast = fast->next->next;

          if(fast == slow)
               return true;
          slow = slow->next;
     }

     return false;
}

int main(){
     Node *head = NULL;

     for(int i = 0; i < 10; i++)
          insert(&head,i);
     createCycle(&head,-100);
     //display(head);

     if(isCycleExist(head))
          std::cout << "yes" << '\n';
     else
          std::cout << "no" << '\n';
}
