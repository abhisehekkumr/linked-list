class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

       if(!head)
          return head;

     if(head->next == NULL)
          return head;

     ListNode *head1 = head;
     ListNode *ptr = head1;
     head = head->next;
     ptr->next = NULL;

     while(head){

          if(head->val > ptr->val){
               ptr->next = head;
               head = head->next;
               ptr = ptr->next;
               ptr->next = NULL;
          }else
               head = head->next;
     }
     return head1;
    }

};
