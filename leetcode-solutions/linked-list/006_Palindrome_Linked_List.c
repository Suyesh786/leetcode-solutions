/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {

    // 0 elements
    if(head==NULL){
        return true;
    }

    // 1 element
    if(head->next==NULL){
        return true;
    }

    // 2 elements
    if(head->next->next==NULL){
        if (head->val == head->next->val){
            return true;
        }
        return false;
    }

    // more than 2 
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    struct ListNode* part = slow;
    struct ListNode* ptr = NULL,*curr=NULL,*temp=NULL;

    bool val = true;

    //Moving slow to mid

    while(fast != NULL  && fast->next != NULL){
        part = slow;
        slow = slow->next;
        fast = fast->next->next;
        
    }

    // Diving the list 
    part->next = NULL;

    curr = slow;
    temp = curr->next;
    //Reverse the list
    while(curr != NULL){ 
        curr->next = ptr;   
        ptr = curr; 
          curr = temp; 
        if(temp!=NULL){
            temp = temp->next;
        } 
    }

    slow = ptr;

    // check list 1 is same as list 2
    struct ListNode*t1 = head,*t2 = slow;
    while (t1 != NULL && t2 !=NULL){
        if (t1->val!=t2->val){
            val = false;
            break;
        }
        t1 = t1->next;
        t2 = t2->next;
    }

    return val;
}