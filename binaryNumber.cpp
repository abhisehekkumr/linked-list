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

long long power(int n){
    long long base = 2;
    long long result = 1;

    while(n){

        if(n & 1)
            result = result*base;
        base = base*base;
        n = n >> 1;
    }
    return result;
}



int calculate(Node<int> *head, long long &ans){

    if(!head)
        return 0;

    if(head->next == NULL){

        if(head->data == 0)
            return 0;
        ans = 1;
        return 0;
    }

    int n = calculate(head->next,ans)+1;

    if(head->data == 0)
        return n;

    ans += power(n);
    return n;
}

int decimal(Node<int> *head) {

    long long ans = 0;
    calculate(head,ans);
     return ans;
}
