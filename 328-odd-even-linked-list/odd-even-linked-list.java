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
    public ListNode oddEvenList(ListNode head) {
        ListNode dummy1 = new ListNode(0), dummy2 = new ListNode(0);
        ListNode evenList = dummy1, oddList = dummy2;
        ListNode temp = head;
        int idx = 0;
        while(temp!=null){
           if(idx%2==0){
             evenList.next = temp;
             evenList = evenList.next;
            //  oddList.next = null;
           }else{
            oddList.next = temp;
            oddList = oddList.next;
            // evenList.next = null;
           }
           temp = temp.next;
           idx++;
        }
      oddList.next = null;
      evenList.next = dummy2.next;
      return dummy1.next;
    }
}