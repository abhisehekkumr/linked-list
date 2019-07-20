/*************
 Following is the Node<int> structure already written.

 template <typename T>
 class Node {
	public:
	T data;
	Node* next;

	Node(T data) {
        next = NULL;
        this->data = data;
	}

	~Node() {
        if (next != NULL) {
            delete next;
        }
	}
 };

*************/

Node<int>* func(Node<int> *head,int n) {


    if(!head)
        return head;

    if(head->next == NULL)
        return NULL;

    Node<int> *ptr = head;
    Node<int> *ptr2 = NULL;
    Node<int> *ptr1 = NULL;
    Node<int> *head1 = NULL;
    Node<int> *head2 = NULL;

    while(ptr){

        if(ptr->data == n){

            if(!head1){
                head1 = ptr;
                ptr1 = ptr;
                ptr = ptr->next;
            }else{

                ptr1->next = ptr;
                ptr1 = ptr1->next;
                ptr = ptr->next;
            }

        }else{

            if(!head2){
                head2 = ptr;
                ptr2 = ptr;
                ptr = ptr->next;
            }else{
                ptr2->next = ptr;
                ptr2 = ptr2->next;
                ptr = ptr->next;
            }

        }

    }

    if(!head1)
        return head2;

    if(!head2)
        return head1;

    ptr1->next = NULL;
    ptr2->next = head1;
    return head2;
}
