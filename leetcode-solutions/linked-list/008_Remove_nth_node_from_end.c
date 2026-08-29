/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {

    if(head == NULL){
        return NULL;
    }

    int length = 0;
    struct ListNode* temp = head;

    // Count the length of the list
    while(temp != NULL){
        temp = temp->next;
        length++;
    }

    // Calculate where to go
    int target = length - n;

    struct ListNode* del = head;
    struct ListNode* ptr = NULL;

    // If deleting the first node
    if(target == 0){
        head = head->next;
        free(del);
        return head;
    }

    // Move to the node to be deleted
    while(target > 0){
        ptr = del;
        del = del->next;
        target--;
    }

    // Deleting
    ptr->next = del->next;
    free(del);

    return head;
}