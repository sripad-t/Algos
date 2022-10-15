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
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        if( a == nullptr ) return b;
        if( b == nullptr ) return a;
        ListNode *ans = new ListNode(-1);
        ListNode *t = ans;
        
        while( a != nullptr || b!= nullptr){
            int aval = a != nullptr ? a->val : INT_MAX;
            int bval = b != nullptr ? b->val : INT_MAX;
            if(aval < bval) {
                t -> next = new ListNode(aval);
                a = a-> next;
            } 
            else{
                t -> next = new ListNode(bval);
                b =  b -> next;
            }
            t = t-> next;
        }
        
        return ans -> next;
    }
};
