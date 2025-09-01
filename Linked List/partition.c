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