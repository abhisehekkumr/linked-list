class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {


        if(!head)
            return head;

        if(head->next == NULL && head->val == val)
            return NULL;

        if(head->next == NULL && head->val != val)
            return head;

        bool flag = false;

        if(head->val == val)
            flag = true;

        ListNode *ptr = head;

        while(ptr->next){

            if(ptr->next->val == val){
                ptr->next = ptr->next->next;
            }else
                ptr = ptr->next;
        }

        if(flag)
            return head->next;

        return head;
    }
};
