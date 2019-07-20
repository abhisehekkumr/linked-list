#include<iostream>
using namespace std;

struct Stack {
     int data;
     struct Stack *next;
};

void push(struct Stack **top, int data){

     if(!(*top)){
          Stack *node = new Stack;
          node->data = data;
          node->next = NULL;
          (*top) = node;
          return;
     }

     Stack *node = new Stack;
     node->data = data;
     node->next = (*top);
     (*top) = node;
}

void pop(Stack **top){

     if(!(*top))
          return;
     (*top) = (*top)->next;
}

void display(Stack *top){

     if(!top)
          return;
     Stack *ptr = top;
     while(ptr){
          std::cout << ptr->data << ' ';
          ptr = ptr->next;
     }
     std::cout << '\n';
}

int main(){
     Stack *top = NULL;
     for(int i = 0; i < 10; i++)
          push(&top,i);
     display(top);
     pop(&top);
     pop(&top);
     pop(&top);
     display(top);
}
