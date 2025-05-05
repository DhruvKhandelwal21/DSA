# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def removeNodes(self, head):
        def remove_nodes_recursively(head):
            if not head or not head.next:
                return head
            head.next = remove_nodes_recursively(head.next)
            if head.val<head.next.val:
                return head.next
            return head
        return remove_nodes_recursively(head)

        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        