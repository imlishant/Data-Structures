bool has_cycle(SinglyLinkedListNode* head) {
    // Hashing
    unordered_set<SinglyLinkedListNode*> s;
    while(head){
        if(s.find(head) != s.end())
            return true;
        s.insert(head);
        head = head->next;
    }
    return false;
}
