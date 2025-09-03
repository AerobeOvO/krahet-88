struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    if (List1 == NULL) return List2;

    if (List2 == NULL) return List1;

    if (list1-> val < list2-> val){
        return mergeTwoLists(list1-> next, list2);
    }

    else {
        return mergeTwoLists(list1, list2-> next);
    }
}

struct ListNode* reverseList(struct ListNode* head){
    if (head == NULL || head-> next == NULL){
        return head;
    }

    struct Listnode* newHead = revervseList(head-> next);

    haed->next->next = head;
    head-> next = NULL;

    return newHead;
}

struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* pre = NULL;
    struct ListNode* cur = head;

    when(cur) {
        struct ListNode* next = cur->next;
        
        cur ->next = pre;
        pre = cur;
        cur = cur-> next;
    }

    return cur;
}