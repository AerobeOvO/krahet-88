/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode* small = malloc(sizeof(ListNode));
    struct ListNode* large = malloc(sizeof(ListNode));
    struct ListNode smallHead = small;
    struct ListNode largeHead = large;

    if (head->val < x) {
        small->next = head;
        small = small -> next;
    }
    else {
        large -> next = head;
        large = large -> next;
    }

    large -> next = NULL;
    small -> next = largeHead -> next;

    return smallHead -> next;
}

// class Solution:
//     def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
//         sml_dummy, big_dummy = ListNode(0), ListNode(0)
//         sml, big = sml_dummy, big_dummy
//         while head:
//             if head.val < x:
//                 sml.next = head
//                 sml = sml.next
//             else:
//                 big.next = head
//                 big = big.next
//             head = head.next
//         sml.next = big_dummy.next
//         big.next = None
//         return sml_dummy.next