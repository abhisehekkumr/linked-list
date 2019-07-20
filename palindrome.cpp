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

     while(head){
          std::cout << head->data << ' ';
          head = head->next;
     }
     std::cout << '\n';
}

Node *reverse(Node *head){

     if(!head)
          return head;

     Node *next = NULL;
     Node *prev = NULL;
     Node *current = head;

     while(current){
          next = current->next;
          current->next = prev;
          prev = current;
          current = next;
     }
     return prev;
}

Node *secondPart(Node *head){

     if(!head)
          return head;

     Node *slow = head;
     Node *node = NULL;
     Node *fast = head;

     while(fast && fast->next){
          node = slow;
          fast = fast->next->next;
          slow = slow->next;
     }

     //std::cout << "middle -> " << node->data <<  '\n';
     Node *result = node->next;
     node->next = NULL;
     return result;
}

bool isPalindrome(Node *head){

     if(!head || head->next == NULL)
          return false;

     Node *left = head;
     Node *right = NULL;

     right = secondPart(head);
     right = reverse(right);

     while(left && right){
          if(left->data != right->data)
               return false;
          left = left->next;
          right = right->next;
     }
     return true;
}

int main(){

     Node *head = NULL;

     //for(int i = 0; i < 9; i++)
     //     head = insert(head,i);
     //for(int i = 7; i >= 0; i--)
     //     head = insert(head,i);
     head = insert(head,1);
     head = insert(head,2);
     head = insert(head,1);
     display(head);

     if(isPalindrome(head))
          std::cout << "yes" << '\n';
     else
          std::cout << "no" << '\n';
}
