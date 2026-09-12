/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* swapPairs(struct ListNode* head) {

    // 0 or 1 node
    if(head == NULL || head->next == NULL){
        return head;
    }

    struct ListNode* one = head;
    struct ListNode* two = head->next;

    // Save the remaining list
    struct ListNode* rest = two->next;

    // Swap the first pair
    two->next = one;

    // Recursively swap the remaining pairs
    one->next = swapPairs(rest);

    // 'two' is now the first node
    return two;
}