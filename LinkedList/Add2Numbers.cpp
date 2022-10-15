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
        int c = 0, currSum = 0;
        ListNode *ans = new ListNode(), *head = ans;
        while(l1 != nullptr || l2 != nullptr){
            currSum = (l1 ? l1->val : 0) + c + (l2 ? l2->val : 0);
            c = currSum / 10;
            ListNode * curr = new ListNode(currSum % 10);
            ans -> next = curr;
            ans = curr;
            l1 = l1 ? l1-> next : l1;
            l2 = l2 ? l2-> next : l2;
            // l2 = l2 -> next;
        } 
        
        if(c){
            ListNode * curr = new ListNode(c);
            ans -> next = curr; 
        }
        return head -> next;
        
    }
};
