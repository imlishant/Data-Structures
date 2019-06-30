SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* head) {
    if(!head)
        return head;
    
    SinglyLinkedListNode* curr = head->next;
    SinglyLinkedListNode* prev = head;
    while(curr){
        cerr << "curr = " << curr->data << "\n";
        if(curr->data == prev->data){
            while(curr->data == prev->data)
            {
                cerr << "in while \n";
                if(curr->next == NULL){
                    prev->next = NULL;
                    //curr = NULL;
                    return head;
                }
                curr = curr->next;
                cerr << "curr = " << curr->data << "\n";
            }
            prev->next = curr; 
            cerr << "prev = " << prev->data << "\n";
        }
        else{
            curr = curr->next;
            prev = prev->next;
        }
    }

    return head;

}
