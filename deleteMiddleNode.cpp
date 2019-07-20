#include<iostream>
using namespace std;

struct Node{
     int data;
     Node *next;

     Node(int data){
          this->data = data;
          next = NULL;
     }
};


Node *insert(Node *head,int data){
     if(!head)
          return new Node(data);
     Node *ptr = head;
     while(ptr->next)
          ptr = ptr->next;
     ptr->next = new Node(data);
     return head;
}

Node *middle(Node *head){
     if(!head || !head->next)
          return head;

     Node *fast = head->next;
     Node *slow = head;

     while(fast && fast->next){
          slow = slow->next;
          fast = fast->next->next;
     }
     return slow;
}

Node *deleteMiddleNode(Node *head){
     if(!head || !head->next)
          return NULL;
     Node *prev = NULL;
     Node *slow = head;
     Node *fast = head->next;

     while(fast && fast->next){
          prev = slow;
          slow = slow->next;
          fast = fast->next->next;
     }

     if(!prev)
          return slow->next;
     prev->next = slow->next;
     return head;
}

void display(Node *head){
     if(!head)
          return;

     while(head){
          std::cout << head->data << ' ';
          head = head->next;
     }
     std::cout << '\n';
}

int main(){
     int n;
     cin >> n;

     Node *head = NULL;

     for(int i = 0; i < n; i++){
          int element;
          cin >> element;
          head = insert(head,element);
     }
     head = deleteMiddleNode(head);
     display(head);
}
