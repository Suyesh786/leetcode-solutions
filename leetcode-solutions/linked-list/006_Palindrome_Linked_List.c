/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {

    // Find the middle of the linked list
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half
    struct ListNode* prev = NULL;
    struct ListNode* current = slow;

    while(current != NULL){
        struct ListNode* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    // Compare first half with reversed second half
    struct ListNode* first = head;
    struct ListNode* second = prev;

    while(second != NULL){
        if(first->val != second->val){
            return false;
        }

        first = first->next;
        second = second->next;
    }

    return true;
}