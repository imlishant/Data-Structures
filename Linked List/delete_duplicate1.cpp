SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* p = head;
    SinglyLinkedListNode* n = head;
    for (p = head; p != NULL; p = p->next) {
        while ((p->next != NULL) && (p->data == p->next->data)) {
            n = p->next->next;
            delete(p->next);
            p->next = n;
        }
    }
    return head;
}
