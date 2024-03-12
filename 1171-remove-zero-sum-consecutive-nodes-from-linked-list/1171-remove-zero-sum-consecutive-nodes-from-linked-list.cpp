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
      void deleteList(ListNode* head) {
        ListNode *nextptr= nullptr;
        while(head) {
            nextptr = head->next;
            //delete head;
            head = nextptr;
        }
    }
    ListNode* removeZeroSumSublists(ListNode* head) {
          unordered_map<int, ListNode*> sum_pos;
        ListNode *start = nullptr, *end = nullptr, 
                *after_start = nullptr, *after_end = nullptr;
        long long sum = 0;
        
        // dummy head for easier head ops
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        
        // initial sum 0 for position before head
        sum_pos[0] = dummy;
        
        // Store the cumulative sum till each node,
        // for the same cumulative sum we store the latest position
        ListNode *curr = head;
        while(curr) {
            sum += curr->val;
            sum_pos[sum] = curr;
            curr = curr->next;
        }
        
        // We compute the cumulative sum again, this time
        // for each sum we check that farthest position where it is 
        // found again and delete the list till that position
        sum = 0;
        curr = dummy;
        while(curr) {
            sum += curr->val;
            // check the position this sum is last seen
            ListNode *last_seen_pos = sum_pos[sum];
            // delete the sublist to avoid memory leaks
            after_start = curr->next;
            after_end = last_seen_pos->next;
            // when it is not the same node
            // and trhere is somethign to delete
            if(last_seen_pos != curr) {
                last_seen_pos->next = nullptr;
                deleteList(after_start);
            }
            
            curr->next = after_end;
            curr = curr->next;
        }
        
        head = dummy->next;
        delete dummy;
        return head;
    }
};