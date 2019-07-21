```cpp
void decode_huff(node * root, string s) {
    int i = 0;
    node* ptr = root;
    while(i < s.size())
        ptr = root;
        while(ptr->left && ptr->right){
            if(s[i] == '0')
                ptr = ptr->left;
            else ptr = ptr->right;
            i++;
        }
        cout << ptr->data;
    }
}
```

```cpp  
void decode_huff(node * root, string s) {
    int index=0;
    char ch;
    node* ptr=root;
    while(index!=s.size())
    {
        ch=s[index++];
        ptr=((ch=='1')?ptr->right:ptr->left);
        if (ptr->data)
        {
            cout << ptr->data;
            ptr=root;
        }
    }
}
```
