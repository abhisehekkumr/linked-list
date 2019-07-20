/**********
 * Following is the Node class that is already written.

class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

*********/

int number(Node *head){

    if(!head)
        return 0;

    if(head->next == NULL){
        int ans = head->data + 1;
        head->data = ans%10;
        return ans/10;
    }

    int ans = number(head->next);

    if((head->data + ans)/10 == 1){
        head->data = (head->data + ans)%10;
        return 1;
    }

    head->data = head->data + ans;
    return 0;
}

Node* NextLargeNumber(Node *head) {

    if(number(head)){
        Node *node = new Node(1);
        node->next = head;
        return node;
    }
    return head;
}
