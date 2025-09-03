/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

struct HashTable {
    struct Node *key, *val;
    UT_hash_handle hh;
} * cachedNode;

struct Node* deepCopy(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }
    struct HashTable* tmp;
    HASH_FIND_PTR(cachedNode, &head, tmp);
    if (tmp == NULL) {
        struct Node* headNew = malloc(sizeof(struct Node));
        headNew->val = head->val;
        tmp = malloc(sizeof(struct HashTable));
        tmp->key = head, tmp->val = headNew;
        HASH_ADD_PTR(cachedNode, key, tmp);
        headNew->next = deepCopy(head->next);
        headNew->random = deepCopy(head->random);
    }
    return tmp->val;
}

struct Node* copyRandomList(struct Node* head) {
    cachedNode = NULL;
    return deepCopy(head);
}


// second solution

struct Node* copyRandomList(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }
    for (struct Node* node = head; node != NULL; node = node->next->next) {
        struct Node* nodeNew = malloc(sizeof(struct Node));
        nodeNew->val = node->val;
        nodeNew->next = node->next;
        node->next = nodeNew;
    }
    for (struct Node* node = head; node != NULL; node = node->next->next) {
        struct Node* nodeNew = node->next;
        nodeNew->random = (node->random != NULL) ? node->random->next : NULL;
    }
    struct Node* headNew = head->next;
    for (struct Node* node = head; node != NULL; node = node->next) {
        struct Node* nodeNew = node->next;
        node->next = node->next->next;
        nodeNew->next = (nodeNew->next != NULL) ? nodeNew->next->next : NULL;
    }
    return headNew;
}