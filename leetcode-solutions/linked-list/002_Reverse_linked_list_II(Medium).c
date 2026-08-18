/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if(head==NULL){
        return NULL;
    }
    // Check if right >= left
    if(left >= right){
        return head;
    }
    struct ListNode*temp = head;
    struct ListNode*temp1 = head;
    // for later use 
    struct ListNode*back = NULL;
    int count=1,count1=1;
    bool found = true, found1 = true;
    while(count != left){
        count++;
        back = temp;
        temp = temp->next;
        if(temp == NULL){
            found = false;
            break;
        }
    }
    while(count1 != right){
        count1++;
        temp1 = temp1->next;
        if(temp1 == NULL){
            found1 = false;
            break;
        }
    }

    // Check if we actually got the left and right 
    if (found == false || found1 == false){
        return head;
    }

    // Actuall Case , we have the left and right , and left < right
    struct ListNode* current = temp->next;
    struct ListNode* ptr = temp->next;
    struct ListNode* prev = temp;
    while(prev != temp1){
        if(ptr != NULL){
            ptr = ptr->next;
        }
        
        current->next = prev;
        prev = current;
        current = ptr;
    }

    temp->next = ptr;
    if (back == NULL) {
        // the reversed section starts at the head
        head = temp1;
    }
    else {
        // there is a node before the reversed section
        back->next = temp1;
    }

    return head;
}