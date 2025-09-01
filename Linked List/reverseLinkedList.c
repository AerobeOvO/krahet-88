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

    struct ListNode* newHead = reverseList(head->next)

    head->next->next = head;
    head->next = null;

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