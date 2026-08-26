/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {

    // if both are empty
    if(list1 == NULL && list2 == NULL){
        return NULL;
    }

    // if only one is empty
    if(list1 == NULL){
        return list2;
    }

    if(list2 == NULL){
        return list1;
    }

    // Make the list with the smaller first element our main list
    struct ListNode *temp = list1;
    struct ListNode *temp1 = list2;
    struct ListNode *ptr1 = NULL;

    bool b = false;

    if(list1->val > list2->val){
        temp = list2;
        temp1 = list1;
        b = true;
    }

    // temp = main list
    // temp1 = nodes that we need to insert
    while(temp1 != NULL){

        // If temp1 belongs after temp
        if(temp->val <= temp1->val){

            // If temp is the last node
            if(temp->next == NULL){
                temp->next = temp1;
                break;
            }

            // If temp1 belongs between temp and temp->next
            if(temp1->val <= temp->next->val){

                ptr1 = temp1->next;

                temp1->next = temp->next;
                temp->next = temp1;

                temp1 = ptr1;
            }
            else{
                temp = temp->next;
            }
        }
        else{
            temp = temp->next;
        }
    }

    if(b){
        return list2;
    }

    return list1;
}