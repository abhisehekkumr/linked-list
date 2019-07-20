//head is the head of the linked list
// Following is the node structure
/**************
class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
***************/
node* bubble_sort_LinkedList_itr(node* head)
{
    if(!head)
        return head;

    if(head->next == NULL)
        return head;


    while(true){
        node *current = head;
        node *prev = NULL;
        bool flag = true;

        while(current && current->next){
            node *next = current->next;
            if(current->data > next->data){
                flag = false;

                if(!prev){

                    current->next = next->next;
                    next->next = current;
                    head = next;
                    prev = next;

                }else{

                    prev->next = next;
                    current->next = next->next;
                    next->next = current;
                    prev = next;
                }

            }else{

                prev = current;
                current = next;

            }

        }


        if(flag)
            break;
    }
    return head;
}
