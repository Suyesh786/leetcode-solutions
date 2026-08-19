/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* current = head;

    while (current != NULL) {
        struct ListNode* next = current->next;

        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

struct ListNode* removeNodes(struct ListNode* head) {

    if (head == NULL) {
        return NULL;
    }

    // Step 1: Reverse the linked list
    head = reverseList(head);

    // Step 2: Traverse from right to left of the original list
    int maxSeen = head->val;

    struct ListNode* prev = head;
    struct ListNode* current = head->next;

    while (current != NULL) {

        if (current->val < maxSeen) {

            // Remove current node
            prev->next = current->next;

            struct ListNode* waste = current;
            current = current->next;

            free(waste);

        } else {

            // Current node survives
            maxSeen = current->val;

            prev = current;
            current = current->next;
        }
    }

    // Step 3: Reverse again to restore original order
    head = reverseList(head);

    return head;
}