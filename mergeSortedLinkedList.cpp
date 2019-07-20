class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        ListNode *head = NULL;
        ListNode *ptr = NULL;
        ListNode *ptr1 = l1;
        ListNode *ptr2 = l2;

        if(!l1)
            return l2;

        if(!l2)
            return l1;

        while(ptr1 && ptr2){

            if(ptr1->val < ptr2->val){

                if(!ptr){
                    ptr = ptr1;
                    head = ptr;
                }else{
                    ptr->next = ptr1;
                    ptr = ptr->next;
                }

                ptr1 = ptr1->next;
            }else{

                if(!ptr){
                    ptr = ptr2;
                    head = ptr;
                }else{
                    ptr->next = ptr2;
                    ptr = ptr->next;
                }

                ptr2 = ptr2->next;
            }
        }

        while(ptr1){
            ptr->next = ptr1;
            ptr = ptr->next;
            ptr1 = ptr1->next;
        }

        while(ptr2){
            ptr->next = ptr2;
            ptr = ptr->next;
            ptr2 = ptr2->next;
        }
        return head;
    }
};
