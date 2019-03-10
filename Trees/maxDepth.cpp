class Solution {
public:
    int maxDepth(Node* root) {
        if(root == NULL)
            return 0;
        int maxdepth = 0;
        for(Node* child : root->children){
            maxdepth = max(maxdepth, maxDepth(child));
        }
        return maxdepth+1;
    }
};
