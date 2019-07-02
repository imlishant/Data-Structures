DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data) {
    DoublyLinkedListNode *ptr = new DoublyLinkedListNode(data);
    DoublyLinkedListNode *temp = head, *tmp;
    // head is NULL
    if(head == nullptr)
        return ptr;
    // traversing the list: temp = head or NULL or in-between
    while(temp && temp->data < ptr->data){
        tmp = temp;
        temp = temp->next;
    }
    // temp = NULL
    if(!temp){
        tmp->next = ptr;
        ptr->prev = tmp;
        return head;
    }
    // temp is head
    if(temp == head){
        ptr->next = head;
        head->prev = ptr;
        head = ptr;
        return head;
    }
    // else condition
    ptr->next = tmp->next;
    tmp->next->prev = ptr;
    tmp->next = ptr;
    ptr->prev = tmp;
    return head;
}
