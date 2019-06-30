bool has_cycle(SinglyLinkedListNode* head) {
    SinglyLinkedListNode *fast = head;
    SinglyLinkedListNode *slow = head;
    // Floyd's Cycle Detection Method
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow)
            return true;
    }
    return false;
}
