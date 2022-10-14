/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        const int tmp = 1e7;
        while(head){
            if(head->val == tmp) return true;
            head->val = tmp;
            head = head->next;
        }
        return false;
    }
};