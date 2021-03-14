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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode;
        ListNode* cur = ans;
        int l1Val[110], l2Val[110], l1S = 0, l2S = 0;
        while(l1 != nullptr){
            l1Val[l1S++] = l1->val;
            l1 = l1->next;
        }
        while(l2 != nullptr){
            l2Val[l2S++] = l2->val;
            l2 = l2->next;
        }
        for(int i1 = 0, i2 = 0; i1 < l1S || i2 < l2S; i1++, i2++){
            if(i1 < l1S && i2 < l2S){
                cur->val = l1Val[i1] + l2Val[i2];
            }else if(i1 < l1S){
                cur->val = l1Val[i1];
            }else{
                cur->val = l2Val[i2];
            }
            if(i1 + 1 < l1S || i2 + 1 < l2S){
                cur = cur->next = new ListNode;
            }
        }
        cur = ans;
        while(cur != nullptr){
            if(cur->val > 9){
                if(cur->next == nullptr){
                    cur->next = new ListNode;
                }
                cur->next->val += 1;
                cur->val -= 10;
            }
            cur = cur->next;
        }
        return ans;
    }
};