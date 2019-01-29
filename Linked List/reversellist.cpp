SinglyLinkedListNode* reverse(SinglyLinkedListNode* head) {
    SinglyLinkedListNode *ptr = head;
    vector<int> ll;
    while(ptr != NULL){
        ll.push_back(ptr->data);
        ptr = ptr->next;
    }
    ptr = head;
    int n = ll.size();
    while(ptr != NULL){
        ptr->data = ll[n-1];
        n--;
        ptr = ptr->next;
    }
    return head;
}
