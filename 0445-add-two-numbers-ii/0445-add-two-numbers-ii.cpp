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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;

        while(head) {
            ListNode* nxt = head->next;
            head->next = prev;
            prev = head;
            head = nxt;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* dum = dummy;
        dummy->next = NULL;
        ListNode* ll1 = reverseList(l1);
        ListNode* ll2 = reverseList(l2);
        int carry = 0;
        while(ll1||ll2||carry>0){
            ListNode*temp = new ListNode(0);
            int sum = 0;
            if(ll1){
                sum += ll1->val;
                ll1 = ll1->next;
            }
            if(ll2){
                sum += ll2->val;
                ll2 = ll2->next;
            }
            sum+=carry;
            
            if(sum>=10){
                carry = sum/10;
                sum = sum%10;
            }else{
                carry = 0;
            }
            
            temp->val = sum;
            dum->next = temp;
            dum = dum->next;    
        }
        ListNode* ans = dummy->next;
        return reverseList(ans);
        
    }
};