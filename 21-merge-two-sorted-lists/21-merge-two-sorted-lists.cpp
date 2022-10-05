/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr){
            return l2;
        }
        if(l2 == nullptr){
            return l1;
        }
        ListNode* res = NULL, *tmp;
        int flg = 0;
        while(l1 != NULL && l2 != NULL){
           if(flg == 0){
               if(l1->val <= l2->val){
                   res = l1;
                   l1 = l1->next;
               } else {
                   res = l2;
                   l2 = l2->next;
               }
               flg = 1;
               tmp = res;
           } else {
               if(l1->val <= l2->val){
                   res->next = l1;
                   l1 = l1->next;
               } else {
                   res->next = l2;
                   l2 = l2->next;
               }
               res = res->next;
           }
            
        }
        
        if(res == NULL) res = l1;
        while(l1 != NULL){
            res->next = l1;
            res = res->next;
            l1 = l1->next;
        }
        
        if(res == NULL) res = l2;

        while(l2 != NULL){
            res->next = l2;
            res = res->next;
            l2 = l2->next;
        }
        
        return tmp;
    }
};