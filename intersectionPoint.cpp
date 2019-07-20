class Solution {
public:

    int length(ListNode *head){

        int count = 0;

        while(head){
            count++;
            head = head->next;
        }
        return count;
    }

   ListNode *intersectionPoint(ListNode *head1, int l1, ListNode *head2, int l2, int d){

       int count = 0;

       while(head1 && count < d){
           count++;
           head1 = head1->next;
       }

       while(head1 && head2 && head1 != head2){
           head1 = head1->next;
           head2 = head2->next;
       }

       if(head1)
           return head1;
       return NULL;
   }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        if(!headA)
            return NULL;

        if(!headB)
            return NULL;

        int first = length(headA);
        int second = length(headB);
        ListNode *node = NULL;

        if(first > second)
            node = intersectionPoint(headA,first,headB,second,first-second);
        else
            node = intersectionPoint(headB,second,headA,first,second-first);
        return node;
    }
};
