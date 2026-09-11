/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {

    if(head == NULL){
        return NULL;
    }

    if(head->next == NULL){
        return head;
    }

    struct ListNode* odd = head,* even = head->next,*even1 = head->next;

    struct ListNode* temp = NULL;
    while (even1 != NULL && even1->next != NULL){
        temp = even1->next;
        even1->next = temp->next;
        temp->next = even;
        odd->next = temp;

        odd = odd->next;
        even1 = even1->next;
    }

    return head;


}