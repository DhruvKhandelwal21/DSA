/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    private ListNode st;
    boolean solve(ListNode q){
        if(q==null) return true;
        boolean isPal = solve(q.next);
        if(st.val!=q.val) return false;
        st = st.next;
        return isPal;
    }
    public boolean isPalindrome(ListNode head) {
        st = head;
        return solve(head);
    }
}