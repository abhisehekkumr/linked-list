class Solution {
public:
    void deleteNode(ListNode* node) {

        if(node == NULL)
            return;

        if(node->next == NULL)
            return;

        while(node->next && node->next->next){
            node->val = node->next->val;
            node = node->next;
        }

        node->val = node->next->val;
        node->next = NULL;
    }
};
