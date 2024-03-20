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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* start1 = list1;
        ListNode* end1 = list1;
        ListNode* end2 = list2;
        
        while(a>1){
            start1 = start1->next;
            a--;
        }
        while(b>-1){
            end1 = end1->next;
            b--;
        }
        while(end2->next!=NULL){
            end2 = end2->next;
        }
        start1->next = list2;
        end2->next = end1;
        return list1;
        
        
    }
};