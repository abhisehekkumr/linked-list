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
     ptr->next  = node;
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

Node *uniqueNumbers(Node *head){

     if(!head)
          return head;

     if(head->next == NULL)
          return head;

          Node* dummy = new Node;

         // dummy node points
         // to the original head
         dummy -> next = head;

         // Node pointing to last
         // node which has no duplicate.
         Node* prev = dummy;

         // Node used to traverse
         // the linked list.
         Node* current = head;

         while(current != NULL)
         {
             // Until the current and
             // previous values are
             // same, keep updating current
             while(current -> next != NULL &&
                   prev -> next -> data == current -> next -> data)
                 current = current -> next;

             // if current has unique value
             // i.e current is not updated,
             // Move the prev pointer to
             // next node
             if (prev -> next == current)
                 prev = prev -> next;

             // when current is updated
             // to the last duplicate
             // value of that segment,
             // make prev the next of current
             else
                 prev -> next = current -> next;

             current = current -> next;
         }

         // update original head to
         // the next of dummy node
         return dummy -> next;
}

int main(){

     Node *head = NULL;
     head = insert(head,1);
     head = insert(head,1);
     head = insert(head,2);
     head = insert(head,2);
     head = insert(head,3);
     head = insert(head,4);
     head = insert(head,5);
     head = insert(head,6);
     display(head);
     head = uniqueNumbers(head);
     display(head);
}
