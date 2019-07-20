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

Node *reverse(Node *head){

     if(!head)
          return head;

     if(head->next == NULL)
          return head;

     Node *next = NULL;
     Node *current = head;
     Node *prev = NULL;

     while(current){

          next = current->next;
          current->next = prev;
          prev = current;
          current = next;
     }
     return prev;
}

Node* reverseInParts(Node* head, int m, int n) {

      if(!head)
         return head;

    if(head->next == NULL)
         return head;

    if(n == 0 || m == 0)
         return head;
    if(m == n)
         return head;

       //int l = len(head);

    //if(m == 1 && n == l)
      //  return reverse(head);
    int count = 1;
    Node *ptr = head;
    Node *first_head = head;
    Node *second_head = NULL;
    Node *thirs_head = NULL;
    Node *middle = NULL;
    Node *middle1 = NULL;

   if(m == 1){

       while(ptr && count <= n){

          if(count == n){
               second_head = ptr;
               middle = ptr->next;
               break;
          }
          count++;
          ptr = ptr->next;
       }

       second_head->next = NULL;
       first_head = reverse(first_head);
       ptr = first_head;
       while(ptr->next)
          ptr = ptr->next;
       ptr->next = middle;
       return first_head;
   }

    while(ptr && count <= n){

         if(count == m - 1){
              middle = ptr;
              second_head = ptr->next;
         }

         if(count == n){
              middle1 = ptr;
              thirs_head = ptr->next;
              break;
         }

         count++;
         ptr = ptr->next;
    }

    middle->next = NULL;
    middle1->next = NULL;
    second_head = reverse(second_head);

    ptr = second_head;
    middle->next = second_head;
    while(ptr->next)
         ptr = ptr->next;
    ptr->next = thirs_head;
    return first_head;

   }

int main(){

     Node *head = NULL;
     head = insert(head,1);
     head = insert(head,2);
     head = insert(head,3);
     head = insert(head,4);
     head = insert(head,5);
     display(head);
     head = reverseInParts(head,2,4);
     display(head);
}
