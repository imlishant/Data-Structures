void reversePrint(SinglyLinkedListNode* head) {
    SinglyLinkedListNode *ptr = head;
    vector<int> arr;
    while(ptr != NULL){
        arr.push_back(ptr->data);
        ptr = ptr->next;
    }
    for(int i = arr.size() - 1; i >= 0; i--){
        cout << arr[i] << endl;
    }
}
