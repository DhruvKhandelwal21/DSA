/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        ListNode slow = head, fast = head;
        if(head==null) return null;
        while(fast!=null && fast.next!=null){
            slow = slow.next;
            fast = fast.next.next;
            if(slow==fast){
              break;
            }
        }
        if(fast==null || fast.next==null) return null;
        System.out.println(fast.val);
        slow = head;
        while(true){
            if(fast==slow) return slow;
            slow = slow.next;
            fast = fast.next;
        }
        
    }
}