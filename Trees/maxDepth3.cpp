class Solution {
public:
    int maxDepth(Node* root) {
        if(root == NULL)
            return 0;
        int n = root->children.size();
        int max = 0;
        vector<int> depth(n);
        for(int i = 0; i < n; i++){
            depth[i] = maxDepth(root->children[i]);
        }
        for(int i = 0; i < n; i++){
            if(max < depth[i]){
                max = depth[i];
            }
        }
        return max+1;
    }
};
