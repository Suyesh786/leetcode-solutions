/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(head == NULL){
        return head;
    }

    if(head->next == NULL){
        return head;
    }

    bool dead = false,dead2=false;
    //For head Duplications
    if(head->val == head->next->val){
        dead = true;
    }
    //For 2 nums , and head repeats
    if(head->next->next == NULL && dead){
        return NULL;
    }
    //For 2 nums , and head repeats
    if(dead && head->next->next != NULL && head->next->val != head->next->next->val){
        dead2 = true;
    }


    // For all cases except Head duplication
    struct ListNode* temp =head,*move = NULL,*stop = NULL;
    while (temp->next != NULL && temp->next->next != NULL){
        if(temp->next->val == temp->next->next->val){
            stop = temp->next;
            move = stop->next;
            while (stop->next != NULL){
                if(stop->val == stop->next->val){
                    move = move->next;
                    stop = stop->next;
                }else{
                    break;
                }
            }
            temp->next = move;

        }else{
            temp = temp->next;
        }
    }

    if(dead2){
        head=head->next->next;
        return head;
    }
    if(dead){
        head = head->next;
    }

    return head;
}   