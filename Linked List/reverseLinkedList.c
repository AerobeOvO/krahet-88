/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL || head.next == NULL){
        return head;
    }

    // newHead is used to store the head of the reversed list
    struct ListNode* newHead = reverseList(head->next)

    head->next->next = head;  // reverse the direction of arrow
    head->next = null; // cut off the old arrow, avoid cycle

    return newHead;
}


struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* pre = NULL;
    struct ListNode* cur = head;

    while(cur) {
        struct ListNode* next = cur-> next;

        cur->next = pre;
        pre = cur;
        cur = next; 
    }

    return cur;
}