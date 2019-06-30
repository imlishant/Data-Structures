SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* ptr = head;
    SinglyLinkedListNode* tmp = head;
    while(ptr){
        tmp = ptr;
        while(tmp != NULL && tmp->data == ptr->data){
            tmp = tmp->next;
        }
        ptr->next = tmp;
        ptr = ptr->next;
    }
    return head;

}
